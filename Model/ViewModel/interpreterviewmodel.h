#ifndef INTERPRETERVIEWMODEL_H
#define INTERPRETERVIEWMODEL_H
#include "Model/Controller/controller.h"
#undef emit
#include "begininterpreter.h"
#define emit
#include <QObject>
#include<QFile>



class InterpreterViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentLine READ currentLine WRITE setCurrentLine NOTIFY currentLineChanged)
    Q_PROPERTY(QString textEditString READ textEditString WRITE settextEditString NOTIFY textEditStringChanged)
     Q_PROPERTY(QString address READ address WRITE setaddress NOTIFY addressChanged)
    //ali***************************
    //Q_PROPERTY(QDataStream inputStream READ inputStream WRITE setinputStream)
    //Q_PROPERTY(QANTLRInputStream inputStream READ inputStream WRITE setinputStream NOTIFY inputstreamChanged)
    //ali***************************
public:
    QThread *th;
    BeginInterpreter *Am;

    std::ifstream stream;

//    InterpreterViewModel *interpreter;
    explicit InterpreterViewModel(QObject *parent = nullptr);

signals:
    void textEditStringChanged();
    void currentLineChanged();
    void AntlrStart();
    void addressChanged();

public slots:
    void play();
    void pause();
    void stop();
    void newproject();
    void openproject();
    void saveproject();
    QString textEditString();
    void settextEditString(QString str);
    void setCurrentLine(int currentL);
    int currentLine();
    //ali****************
    //QDataStream* inputStream();
    void setinputStream(QString stg);
    QString address();
    void setaddress(QString addr);

    //ali****************


private:
    QString _textEditString;
    int _currentLine;
    //ali**************************
    //QDataStream* _inputstream;
    //ali**************************
     QString _addresspath="/home/fumrobotics/Documents/QtProjects/SixR20_210298/SixR20_git210298/SixR20_git/Model/Interpreter/text.txt";
    Controller *controller;
};


#endif // INTERPRETERVIEWMODEL_H
