#include "alarm.h"
#include <QObject>

alarm::alarm(QString name,QString key,QString detail,QString check,int type,int motorNum): QObject(){
    _name = name;
    _key = key;
    _detail = detail;
    _check = check;
    _type = type;
    _motorNum = motorNum;
}

alarm::alarm(QString name, QString key, QString detail, QString check, int type)
{
    _name = name;
    _key = key;
    _detail = detail;
    _check = check;
    _type = type;
}
alarm::alarm(QObject *parent) : QObject(parent){}

QString alarm::name(){
    return _name;
}
QString alarm::key(){
    return _key;
}
QString alarm::detail(){
    return _detail;
}
QString alarm::check(){
    return _check;
}
int alarm::type(){
    return _type;
}

int alarm::motorNum()
{
    return _motorNum;
}


void alarm::setName(QString name){
    _name = name;
}
void alarm::setKey(QString key){
    _key = key;
}
void alarm::setDetail(QString detail){
    _detail = detail;
}
void alarm::setCheck(QString check){
    _check = check;
}
void alarm::setType(int type){
    _type = type;
}

void alarm::setMotorNum(int motorNum)
{
    _motorNum = motorNum;
}
