#ifndef INTERPRETERVIEWMODEL_H
#define INTERPRETERVIEWMODEL_H

#undef emit
#include "antlrmain.h"
#define emit
#include <QObject>


class InterpreterViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString textEditString READ textEditString WRITE settextEditString NOTIFY textEditStringChanged)
    //ali***************************
    //Q_PROPERTY(QDataStream inputStream READ inputStream WRITE setinputStream)
    //Q_PROPERTY(QANTLRInputStream inputStream READ inputStream WRITE setinputStream NOTIFY inputstreamChanged)
    //ali***************************
public:
    explicit InterpreterViewModel(QObject *parent = nullptr);

signals:
    void textEditStringChanged();

public slots:
    void play();
    void pause();
    QString textEditString();
    void settextEditString(QString str);
    //ali****************
    //QDataStream* inputStream();
    void setinputStream(QString stg);

    QString addressPath();

    //ali****************


private:
    QString _textEditString;
    //ali**************************
    //QDataStream* _inputstream;
    std::string  _addresspath;
    //ali**************************
};


#endif // INTERPRETERVIEWMODEL_H
