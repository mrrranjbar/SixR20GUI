#include "interpreterviewmodel.h"
#include <QThread>
#include <iostream>

using namespace std;



InterpreterViewModel::InterpreterViewModel(QObject *parent) : QObject(parent)
{
    controller = Controller::getInstance();
    th = new QThread();
    Am= new BeginInterpreter();
    Am->moveToThread(th);
    connect(this, SIGNAL(AntlrStart()),Am, SLOT(begin()));
    th->start(QThread::LowestPriority);
}

void InterpreterViewModel::play()
{

    //Am->getCurrentLine();
    //    Am->begin();
    Am->load(_addresspath.toUtf8().constData());
    emit AntlrStart();
}
void InterpreterViewModel::pause()
{

}

void InterpreterViewModel::stop()
{

}

void InterpreterViewModel::newproject()
{
    //    _addresspath = QFileDialog::getOpenFileName(this,
    //        tr("Open Image"), "/home/jana", tr("Image Files (*.png *.jpg *.bmp)"));



    //    QFile file(QString::fromStdString(_addresspath));
    //    file.write(str.toUtf8());
    //    stream.open(_addresspath);
}

void InterpreterViewModel::openproject()
{
    stream.open(_addresspath.toUtf8().constData());
    string str((std::istreambuf_iterator<char>(stream)),
               std::istreambuf_iterator<char>());
    settextEditString(QString::fromStdString(str));
}

void InterpreterViewModel::saveproject()
{
    QFile file(_addresspath);
    file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
    //    QObject *object = component.create();
    //    QObject *whot = object->findChild<QObject*>("whot");
    //    if (whot)
    //        file.write(whot->property("text"));
    file.write(_textEditString.toUtf8());
}
QString InterpreterViewModel:: textEditString()
{
    return _textEditString;
}

void InterpreterViewModel::settextEditString(QString str)
{
    _textEditString=str;
    emit textEditStringChanged();
}

void InterpreterViewModel::setCurrentLine(int currentL)
{
    _currentLine=currentL;
    emit currentLineChanged();
}

int InterpreterViewModel::currentLine()
{
    return _currentLine;
}


void InterpreterViewModel::setinputStream(QString stg)
{

}



QString InterpreterViewModel::address()
{
    return _addresspath;
}

void InterpreterViewModel::setaddress(QString addr)
{
    _addresspath = addr.remove(0,7);
    emit addressChanged();
}


