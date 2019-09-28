#ifndef ALARM_H
#define ALARM_H

#include <QObject>

class alarm : public QObject
{

    Q_OBJECT

    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString key READ key WRITE setKey)
    Q_PROPERTY(QString detail READ detail WRITE setDetail)
    Q_PROPERTY(QString check READ check WRITE setCheck)
    Q_PROPERTY(int type READ type WRITE setType)
    Q_PROPERTY(int motorNum READ motorNum WRITE setMotorNum)

public:
    alarm(QString name,QString key,QString detail,QString check,int type,int motorNum);
    alarm(QString name,QString key,QString detail,QString check,int type);
    alarm(QObject *parent);


public slots:
    QString name();
    QString key();
    QString detail();
    QString check();
    int type();
    int motorNum();

    void setName(QString name);
    void setKey(QString key);
    void setDetail(QString detail);
    void setCheck(QString check);
    void setType(int type);
    void setMotorNum(int type);

private:
    QString _name;
    QString _key;
    QString _detail;
    QString _check;
    int _motorNum;
    int _type;

};

#endif // ALARM_H
