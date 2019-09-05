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
    if(_isJoint){
        double TargetPoint[6] = {_positions->at(0).toDouble(),
                                 _positions->at(1).toDouble(),
                                 _positions->at(2).toDouble(),
                                 _positions->at(3).toDouble(),
                                 _positions->at(4).toDouble(),
                                 _positions->at(5).toDouble()};
        for (int i=0; i< controller->beckhoff->NumberOfRobotMotors; ++i) {
            controller->beckhoff->setTargetPosition(TargetPoint[i],i);
        }
        controller->beckhoff->setTargetPosition(20,6);
        controller->beckhoff->setTargetPosition(0,7);
        controller->beckhoff->setGUIManager(8);
    }else{
        QString CurrentFrame = _typeOfFrame;
        QList<double> tmpValue = controller->robot->currentBaseFrame->mainPoints();
        if(CurrentFrame=="world")
        {
            tmpValue = controller->robot->currentWorldFrame->mainPoints();
        }
        else if(CurrentFrame=="object")
        {
            tmpValue = controller->robot->currentObjectFrame->mainPoints();
        }
        else if(CurrentFrame=="task")
        {
            tmpValue = controller->robot->currentTaskFrame->mainPoints();
        }
        else if(CurrentFrame=="tool")
        {
            tmpValue = controller->robot->currentToolFrame->mainPoints();
        }
        else if(CurrentFrame=="base")
        {
            tmpValue = controller->robot->currentBaseFrame->mainPoints();
        }

        double SelectedFrame[6] = {tmpValue.at(0),tmpValue.at(1),tmpValue.at(2),
                                   tmpValue.at(3),tmpValue.at(4),tmpValue.at(5)};
        double TargetPoint[6] = {_positions->at(0).toDouble(),
                                 _positions->at(1).toDouble(),
                                 _positions->at(2).toDouble(),
                                 _positions->at(3).toDouble(),
                                 _positions->at(4).toDouble(),
                                 _positions->at(5).toDouble()};
        double OutPointInRef[6];
        controller->robot->PointInReference(TargetPoint,SelectedFrame,CurrentFrame,OutPointInRef);
        for (int i=0; i< controller->beckhoff->NumberOfRobotMotors; ++i) {
            controller->beckhoff->setTargetPosition(OutPointInRef[i],i);
        }
        controller->beckhoff->setTargetPosition(20,6);
        controller->beckhoff->setTargetPosition(0,7);
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
    _positions->insert(i,val);
}

void PositionViewModel::setTypeOfFrame(QString val)
{
    _typeOfFrame = val;
    emit TypeOfFrameChanged();
}

QString PositionViewModel::TypeOfFrame()
{
    return _typeOfFrame;
}

void PositionViewModel::RunMotors()
{
   controller->beckhoff->setGUIManager(2);
}

void PositionViewModel::ClearAlarms()
{
    controller->beckhoff->setGUIManager(99);
}

