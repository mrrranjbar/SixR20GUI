#include "breakviewmodel.h"
#include <QDebug>

breakviewmodel::breakviewmodel(QObject *parent) : QObject(parent)
{

}

void breakviewmodel::setBreakAtIndex(bool value, int index)
{
    QString _action="";
    if(value)
        _action="ON";
    else
        _action="OFF";

    qDebug()<< "SET BREAK OF MOTOR-" +  QString::number(index+1) + " '" + _action + "'";
}
