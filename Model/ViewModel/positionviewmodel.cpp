#include "positionviewmodel.h"

PositionViewModel::PositionViewModel(QObject *parent) : QObject(parent)
{
    controller = Controller::getInstance();
}

void PositionViewModel::Move(int index)
{
    controller->beckhoff->setGUIManager(1);
    switch (index) {
        case 0:// move motor 1
        {
            controller->beckhoff->setTargetPosition(_positions->takeAt(0).toInt(),0);
            uint16_t h[6] = {31,15,15,15,15,15};
            controller->beckhoff->setControlWord(h);
            break;
        }
        case 1:// move motor 2
        {
            controller->beckhoff->setTargetPosition(_positions->takeAt(1).toInt(),1);
            uint16_t h[6] = {15,31,15,15,15,15};
            controller->beckhoff->setControlWord(h);
            break;
        }
        case 2:// move motor 3
        {
            controller->beckhoff->setTargetPosition(_positions->takeAt(2).toInt(),2);
            uint16_t h[6] = {15,15,31,15,15,15};
            controller->beckhoff->setControlWord(h);
            break;
        }
        case 3:// move motor 4
        {
            controller->beckhoff->setTargetPosition(_positions->takeAt(3).toInt(),3);
            uint16_t h[6] = {15,15,15,31,15,15};
            controller->beckhoff->setControlWord(h);
            break;
        }
        case 4:// move motor 5
        {
            controller->beckhoff->setTargetPosition(_positions->takeAt(4).toInt(),4);
            uint16_t h[6] = {15,15,15,15,31,15};
            controller->beckhoff->setControlWord(h);
            break;
        }
        case 5:// move motor 6
        {
            controller->beckhoff->setTargetPosition(_positions->takeAt(5).toInt(),5);
            uint16_t h[6] = {15,15,15,15,15,31};
            controller->beckhoff->setControlWord(h);
            break;
        }
    }
}

void PositionViewModel::MoveAll()
{
     controller->beckhoff->setGUIManager(1);
     for (int i=0; i< controller->beckhoff->NumberOfRobotMotors; ++i) {
        controller->beckhoff->setTargetPosition(_positions->takeAt(i).toInt(),i);
     }
     uint16_t h[6] = {31,31,31,31,31,31};
     controller->beckhoff->setControlWord(h);
}

void PositionViewModel::GoHome()
{
    controller->beckhoff->setGUIManager(1);
    for (int i=0; i< controller->beckhoff->NumberOfRobotMotors; ++i) {
        controller->beckhoff->setTargetPosition(0,i);
    }
    uint16_t h[6] = {31,31,31,31,31,31};
    controller->beckhoff->setControlWord(h);
}

QList<QString> PositionViewModel::Positions()
{
    return *_positions;
}

