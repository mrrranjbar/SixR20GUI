#include "jogviewmodel.h"
#include "Model/Controller/controller.h"

JogViewModel::JogViewModel(QObject *parent) : QObject(parent)
{   
    controller = Controller::getInstance();
    for (int i=0; i < controller->beckhoff->NumberOfRobotMotors; i++) {
        controller->beckhoff->setMSelect(false,i);
        controller->beckhoff->setGUIJogDirection(1);
    }
    _actualPosition = new QList<double>();
}
void JogViewModel::jogCart(int sign, int index, int press)
{
    for (int i=0; i < controller->beckhoff->NumberOfRobotMotors; i++) {
        if(i!=index)
        controller->beckhoff->setMSelect(false,i);
    }
    if(press == 1) //press
    {
        controller->beckhoff->setStoppingJog(false);
        controller->beckhoff->setMSelect(true,index);
        if(sign == 0) // -
        {
            controller->beckhoff->setGUIJogDirection(-1);
        }
        else if(sign == 1) // +
        {
            controller->beckhoff->setGUIJogDirection(1);
        }

    } else if(press == 0) // release
    {
        controller->beckhoff->setStoppingJog(true);
        controller->beckhoff->setMSelect(false,index);
    }
    controller->beckhoff->setGUIManager(65);
}

QList<double> JogViewModel::ActualPosition()
{
     return *_actualPosition;
}

void JogViewModel::setActualPosition(QList<double> value)
{
    _actualPosition = &value;
    emit ActualPositionChanged();
}

void JogViewModel::UpdateActualPosition()
{
    QList<double> *tmp = new QList<double>();
    for (int i=0; i<controller->beckhoff->NumberOfRobotMotors; ++i) {
        tmp->append((double)(controller->beckhoff->ActualPositions[i]*controller->robot->PulsToDegFactor1[i]));
    }
    setActualPosition(*tmp);
}

void JogViewModel::jogJoint(int sign, int index, int press)
{
    for (int i=0; i < controller->beckhoff->NumberOfRobotMotors; i++) {
        if(i!=index)
        controller->beckhoff->setMSelect(false,i);
    }
    if(press == 1) //press
    {
        controller->beckhoff->setStoppingJog(false);
        controller->beckhoff->setMSelect(true,index);
        if(sign == 0) // -
        {
            controller->beckhoff->setGUIJogDirection(-1);
        }
        else if(sign == 1) // +
        {
            controller->beckhoff->setGUIJogDirection(1);
        }

    } else if(press == 0) // release
    {
        controller->beckhoff->setStoppingJog(true);
        controller->beckhoff->setMSelect(false,index);
    }
    controller->beckhoff->setGUIManager(64);
}
