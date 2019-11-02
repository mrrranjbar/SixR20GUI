#include "interpreterviewmodel.h"
#include <QQmlComponent>
#include <QQmlEngine>
#include <QQuickView>
#include <QThread>
#include <iostream>
#include <QCoreApplication>
#include <QFileInfo>




using namespace std;



InterpreterViewModel::InterpreterViewModel(QObject *parent) : QObject(parent)
{
    controller = Controller::getInstance();
    th = new QThread();
    Am= new BeginInterpreter();
    Am->moveToThread(th);
    connect(this, SIGNAL(AntlrStart()),Am, SLOT(begin()));
    th->start(QThread::LowestPriority);
    connect(controller->beckhoff, SIGNAL(CurrentLineChangedB()),this, SLOT(CurrentLineEvent()));
}
void InterpreterViewModel::play()
{
    isStarted=true;
    controller->beckhoff->runAll=true;
    controller->beckhoff->currentLine=0;
    saveFile();
    Am->load(_addresspath.toUtf8().constData());
    Am->begin();

    //emit AntlrStart();
}

void InterpreterViewModel::nextLine()
{
    controller->beckhoff->runAll=false;
    controller->beckhoff->doNextLine = true;
    selectLine(controller->beckhoff->currentLine);
    if(!isStarted){
        isStarted=true;
        Am->load(_addresspath.toUtf8().constData());
        emit AntlrStart();
    }
}
void InterpreterViewModel::pause()
{
    controller->beckhoff->runAll=false;
    controller->beckhoff->doNextLine = false;
    selectLine(controller->beckhoff->currentLine);
}

void InterpreterViewModel::stop()
{
}

void InterpreterViewModel::newFile()
{

}

void InterpreterViewModel::openFile()
{
    stream.open(_addresspath.toUtf8().constData());
    string str((std::istreambuf_iterator<char>(stream)),
               std::istreambuf_iterator<char>());
    settextEditString(QString::fromStdString(str));
}

void InterpreterViewModel::saveFile()
{
    QFile file(_addresspath);
    file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text);
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

void InterpreterViewModel::selectLine(int currentL)
{
    _currentLine=currentL;
    int index1=0, index2=0;
    for(int i=0; i<currentL; i++){
        index1 = _textEditString.indexOf("\n", index1+1);
    }
    index2 = _textEditString.indexOf("\n", index1+1);
    emit lineSelect(index1, index2);
//    QThread::msleep(10);
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

void InterpreterViewModel::CurrentLineEvent()
{
    selectLine(controller->beckhoff->currentLine);
}

void InterpreterViewModel::setaddress(QString addr)
{
    _addresspath = addr.remove(0,7);
    emit addressChanged();
}


