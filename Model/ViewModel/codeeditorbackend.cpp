#include "codeeditorbackend.h"

QString CodeEditorBackend::Errors()
{
    return _errors;
}

CodeEditorBackend::CodeEditorBackend()
{
    controller = Controller::getInstance();
    th = new QThread();
    Am= new BeginInterpreter();
    Am->moveToThread(th);
    connect(this, SIGNAL(AntlrStart()),Am, SLOT(begin()));
    th->start(QThread::LowestPriority);
    connect(controller->beckhoff, SIGNAL(CurrentLineChangedB()),this, SLOT(changedRunningLine()));
    //m_text = "func()\r\nend";
    setErrors(" ");
    emit textChanged(m_text);
}

QString CodeEditorBackend::text() const
{
    return m_text;
}

void CodeEditorBackend::setErrors(QString value)
{
    _errors = value;
    emit ErrorsChanged();
}

QUrl CodeEditorBackend::fileUrl() const
{
    return m_fileUrl;
}

QString CodeEditorBackend::fileName() const
{
    return m_fileName;
}

void CodeEditorBackend::setText(QString text)
{
    if (m_text == text)
        return;

    m_text = text;
    emit textChanged(text);
}

void CodeEditorBackend::setFileUrl(QUrl fileUrl)
{
    if (m_fileUrl == fileUrl)
        return;

    m_fileUrl = fileUrl;
    emit fileUrlChanged(fileUrl);
    setFileName(fileUrl.fileName());
}

void CodeEditorBackend::setFileName(QString fileName)
{
    if (m_fileName == fileName)
        return;

    m_fileName = fileName;
    emit fileNameChanged(fileName);
}

bool CodeEditorBackend::createDirectory(QString path)
{

    const QString& homePath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QDir dir(homePath);
    return dir.mkdir(path);
}

void CodeEditorBackend::play(QString runFromLine)
{
    controller->beckhoff->runFromLineNumber=runFromLine.toInt();
    controller->beckhoff->runAll=true;
    controller->beckhoff->currentLine=0;
    controller->beckhoff->doNextLine=true;
    controller->beckhoff->stopAnltrRun=false;
    controller->IsMovementStop = false;
    controller->IsClearMovementStop = false;
    controller->IsGoToStart = false;

    const QString& homePath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
    QString str=homePath+m_fileUrl.toString().remove(0,9);


    controller->IsFirstMovingCommand = true;

   QString errors = Am->load(str.toUtf8().constData());
   setErrors(errors);
    //->load(m_fileUrl.toUtf8().constData());
    //Am->begin();
    if(errors == "")
        Q_EMIT AntlrStart();
}
void CodeEditorBackend::pause()
{
    controller->beckhoff->doNextLine=!controller->beckhoff->doNextLine;
}

void CodeEditorBackend::stop()
{
    controller->beckhoff->doNextLine=true;
    controller->beckhoff->stopAnltrRun=true;
    controller->IsGoToStart = false;
     controller->beckhoff->FinishCurrentProject();
}
void CodeEditorBackend::changedRunningLine()
{
    int currentL= controller->beckhoff->currentLine;
    int index1=0, index2=0;
    for(int i=0; i<currentL; i++){
        index1 = m_text.indexOf("\n", index1+1);
    }
    index2 = m_text.indexOf("\n", index1+1);

    Q_EMIT lineSelect(index1, index2);
}

QString CodeEditorBackend::addCommandToCurrentLine(int cmd, QString targetP1, QString targetP2, QString targetP3, QString frameType, QString frameTargetPoint, QString moveParam, QString theta, QString exp1, QString exp2, QString id)
{
    string str;
    string moveParam_ = moveParam.toUtf8().constData();
    string theta_ = theta.toUtf8().constData();
    string exp1_ = exp1.toUtf8().constData();
    string exp2_ = exp2.toUtf8().constData();
    string id_ = id.toUtf8().constData();
    string returnVal = id_+"_ret";

    switch (cmd) {
    case LanguageCMD::IF:
        str = "IF DIN["+exp1_+"]=="+exp2_+" THEN\r\n\r\nENDIF";
        break;
    case LanguageCMD::IFELSE:
        str = "IF DIN["+exp1_+"]=="+exp2_+" THEN\r\n\r\nELSE\r\n\r\nENDIF";
        break;
    case LanguageCMD::FOR:
        str = "int forCounter"+exp1_+"=0\nFOR forCounter"+exp1_+"=0 TO "+exp2_+" \r\n\r\nENDFOR";
        break;
    case LanguageCMD::WHILE:
        str = "WHILE DIN["+exp1_+"]=="+exp2_+"\r\n\r\nENDWHILE";
        break;
    case LanguageCMD::SETFRAME:
        str = "SETFRAME "+(string)(frameType.toUtf8().constData())+" "+(string)(frameTargetPoint.toUtf8().constData());
        break;
//    case LanguageCMD::INTERRUPT:
//        str = "int "+id_+"_handler()\n\nEND";
//        str += "int "+returnVal+"\n"+"GLOBAL INTERRUPT DECL "+id_+" ["+exp1_+"] WHEN "+exp2_+" DO "+returnVal+"="+id_+"_handler()";
//        break;
    case LanguageCMD::INTERRUPT:
        str = "interrupt_"+id_+"()\n\nEND\n";
        break;
    case LanguageCMD::SUBROUTINE:
        str = "subroutine_"+id_+"()\n\nEND";
        break;
    case LanguageCMD::WAITFOR:
        str = "WAIT FOR "+exp1_;
        break;
    case LanguageCMD::WAITSEC:
        str = "WAIT SEC "+exp1_;
        break;
    case LanguageCMD::PTP:
        str = "PTP "+(string)(targetP1.toUtf8().constData())+" "+moveParam_;
        break;
    case LanguageCMD::LIN:
        str = "LIN "+(string)(targetP1.toUtf8().constData())+" "+moveParam_;
        break;
    case LanguageCMD::CIRC:
        str = "CIR "+(string)(targetP1.toUtf8().constData())+" "+(string)(targetP2.toUtf8().constData())+" "+theta_+" "+moveParam_;
        break;
    case LanguageCMD::INTERRUPT_MAIN:
        str +="GLOBAL INTERRUPT DECL interrupt_"+id_+" "+theta_+" WHEN DIN["+exp1_+"]=="+exp2_+" DO interrupt_"+id_+"()\n\n";
        break;
    case LanguageCMD::SUBROUTINE_MAIN:
        str = "subroutine_"+id_+"()";
        break;
    case LanguageCMD::GOTOSTART:
        str = "GotoStart";
        break;
    case LanguageCMD::CONFIG:
        str = exp1_+"="+exp2_;
        break;
    case LanguageCMD::SETINPUT:
        str = "DIN["+exp1_+"]";
        break;
    case LanguageCMD::SETOUTPUT:
        str = "DOUT["+exp1_+"]="+exp2_;
        break;
    case LanguageCMD::PTPDIRECT:
        str = "PTP ["+exp1_+"] "+moveParam_;
        break;
    case LanguageCMD::LINDIRECT:
        str = "LIN ["+exp1_+"] "+moveParam_;
        break;
    case LanguageCMD::CIRCDIRECT:
        str = "CIR ["+exp1_+"] ["+exp2_+"] "+theta_+" "+moveParam_;
        break;
    }
    return QString::fromStdString("\r\n"+str);
}

void CodeEditorBackend::setCursorPos(int pos)
{
    cursorPosition = pos;
}

bool CodeEditorBackend::save()
{
    const QString& homePath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);

    QFile file(homePath+m_fileUrl.toString().remove(0,9));
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }
    qDebug() << m_text;
    file.write(m_text.toUtf8());
    file.close();
    return true;
}

bool CodeEditorBackend::load()
{
    const QString& homePath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);

    QFile file(homePath+m_fileUrl.toString().remove(0,9));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }
    QByteArray content = file.readAll();
    setText(QString::fromUtf8(content.constData(), content.length()));

    file.close();
    return true;
}
