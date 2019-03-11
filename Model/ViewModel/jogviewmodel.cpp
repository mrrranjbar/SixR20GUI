#include "jogviewmodel.h"
#include "Model/Controller/controller.h"

JogViewModel::JogViewModel(QObject *parent) : QObject(parent)
{   
    controller = Controller::getInstance();
    for (int i=0; i < controller->beckhoff->NumberOfRobotMotors; i++) {
        controller->beckhoff->setMSelect(false,i);
        controller->beckhoff->setJogDirection(0,i);
    }
}

void JogViewModel::jogJoint(int sign, int index, int press)
{
    if(press == 1) //press
    {
        controller->beckhoff->setStoppingJog(false);
        controller->beckhoff->setMSelect(true,index);
        if(sign == 0) // -
        {
            controller->beckhoff->setJogDirection(-1,index);
        }
        else if(sign == 1) // +
        {
            controller->beckhoff->setJogDirection(1,index);
        }

    } else if(press == 0) // release
    {
        controller->beckhoff->setStoppingJog(true);
        controller->beckhoff->setMSelect(false,index);
        controller->beckhoff->setJogDirection(0,index);
    }
}
