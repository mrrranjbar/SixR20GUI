#include "positionviewmodel.h"

PositionViewModel::PositionViewModel(QObject *parent) : QObject(parent)
{
    controller = Controller::getInstance();
    _positions = new QList<QString>();
    _positions->push_back("0");
    _positions->push_back("0");
    _positions->push_back("0");
    _positions->push_back("0");
    _positions->push_back("0");
    _positions->push_back("0");
    _isJoint = true;
}

//void PositionViewModel::Move(int index)
//{
//    for (int i=0; i<controller->beckhoff->NumberOfRobotMotors; i++) {
//     controller->beckhoff->setTargetPosition(0,i);
//    }
//    controller->beckhoff->setTargetPosition(_positions->at(index).toInt(),index);
//    controller->beckhoff->setTargetPosition(50,6); // should change
//    controller->beckhoff->setGUIManager(8);
//}

void PositionViewModel::MoveAll()
{
    for (int i=0; i< controller->beckhoff->NumberOfRobotMotors; ++i) {
       controller->beckhoff->setTargetPosition(_positions->at(i).toInt(),i);
    }
    controller->beckhoff->setTargetPosition(30,6);
    controller->beckhoff->setTargetPosition(0,7);
    if(_isJoint){
     controller->beckhoff->setGUIManager(8);
    }else{
        controller->beckhoff->setGUIManager(10);
    }
}

void PositionViewModel::GoHome()
{
    for (int i=0; i<controller->beckhoff->NumberOfRobotMotors; i++) {
     controller->beckhoff->setTargetPosition(0,i);
    }
    controller->beckhoff->setTargetPosition(50,6);
    controller->beckhoff->setTargetPosition(0,7);
    controller->beckhoff->setGUIManager(8);
}

bool PositionViewModel::IsJoint()
{
    return _isJoint;
}

void PositionViewModel::setIsJoint(bool val)
{
    _isJoint = val;
    IsJointChanged();
}

QList<QString> PositionViewModel::Positions()
{
    return *_positions;
}

void PositionViewModel::setPosition(QString val, int i)
{
   _positions->replace(i,val);
}

