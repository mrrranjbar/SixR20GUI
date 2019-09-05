#include "codeeditorbackend.h"

CodeEditorBackend::CodeEditorBackend()
{
    controller = Controller::getInstance();
    th = new QThread();
    Am= new BeginInterpreter();
    Am->moveToThread(th);
    connect(this, SIGNAL(AntlrStart()),Am, SLOT(begin()));
    th->start(QThread::LowestPriority);
    connect(controller->beckhoff, SIGNAL(CurrentLineChangedB()),this, SLOT(changedRunningLine()));
}

QString CodeEditorBackend::text() const
{
    return m_text;
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

void CodeEditorBackend::play()
{
    controller->beckhoff->runAll=true;
    controller->beckhoff->currentLine=0;
    Am->load(m_fileUrl.toLocalFile().toUtf8().constData());
    //Am->begin();
    Q_EMIT AntlrStart();
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

bool CodeEditorBackend::save()
{
    QFile file(m_fileUrl.toLocalFile());
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return false;
    }

    file.write(m_text.toUtf8());
    file.close();
    return true;
}

bool CodeEditorBackend::load()
{
    QFile file(m_fileUrl.toLocalFile());
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }
    QByteArray content = file.readAll();
    setText(QString::fromUtf8(content.constData(), content.length()));

    file.close();
    return true;
}
