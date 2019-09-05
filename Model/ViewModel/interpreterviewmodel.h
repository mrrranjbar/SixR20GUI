#ifndef INTERPRETERVIEWMODEL_H
#define INTERPRETERVIEWMODEL_H
#include "Model/Controller/controller.h"
#undef emit
#include "begininterpreter.h"
#define emit
#include <QObject>
#include<QFile>
#include <QtCore/qobject.h>
#include <QtGui/qtextobject.h>
#include <QTextEdit>
#include <QQuickTextDocument>



class InterpreterViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString textEditString READ textEditString WRITE settextEditString NOTIFY textEditStringChanged)
    Q_PROPERTY(QString address READ address WRITE setaddress NOTIFY addressChanged)

public:
    QObject *textEdit;
    QThread *th;
    BeginInterpreter *Am;
    bool isStarted=false;

    std::ifstream stream;

//    InterpreterViewModel *interpreter;
    explicit InterpreterViewModel(QObject *parent = nullptr);

Q_SIGNALS:
    void textEditStringChanged();
    void AntlrStart();
    void addressChanged();
    void lineSelect(int start, int end);

public Q_SLOTS:
    void play();
    void nextLine();
    void pause();
    void stop();
    void newFile();
    void openFile();
    void saveFile();
    QString textEditString();
    void settextEditString(QString str);
    void setaddress(QString str);
    void selectLine(int currentL);
    int currentLine();
    void setinputStream(QString stg);
    QString address();
    void CurrentLineEvent();


private:
    QString _textEditString;
    int _currentLine;
     QString _addresspath="/home/fumrobotics/Documents/QtProjects/SixR20_210298/SixR20_git210298/SixR20_git/Model/Interpreter/text.txt";

    Controller *controller;
};


#endif // INTERPRETERVIEWMODEL_H
