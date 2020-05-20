#include "positionviewmodel.h"
PositionViewModel::PositionViewModel(QObject *parent) : QObject(parent)
{
    controller = Controller::getInstance();
    _positions = new QList<QString>();
    _cartPositions = new QList<QString>();


    controller->beckhoff->tempJointTargetPoints[0] != "0" ?_positions->push_back(controller->beckhoff->tempJointTargetPoints[0]) : _positions->push_back("0");
    controller->beckhoff->tempJointTargetPoints[1] != "0" ?_positions->push_back(controller->beckhoff->tempJointTargetPoints[1]) : _positions->push_back("0");
    controller->beckhoff->tempJointTargetPoints[2] != "0" ?_positions->push_back(controller->beckhoff->tempJointTargetPoints[2]) : _positions->push_back("0");
    controller->beckhoff->tempJointTargetPoints[3] != "0" ?_positions->push_back(controller->beckhoff->tempJointTargetPoints[3]) : _positions->push_back("0");
    controller->beckhoff->tempJointTargetPoints[4] != "0" ?_positions->push_back(controller->beckhoff->tempJointTargetPoints[4]) : _positions->push_back("0");
    controller->beckhoff->tempJointTargetPoints[5] != "0" ?_positions->push_back(controller->beckhoff->tempJointTargetPoints[5]) : _positions->push_back("0");

    controller->beckhoff->tempCartTargetPoints[0] != "0" ?_cartPositions->push_back(controller->beckhoff->tempCartTargetPoints[0]) : _cartPositions->push_back("0");
    controller->beckhoff->tempCartTargetPoints[1] != "0" ?_cartPositions->push_back(controller->beckhoff->tempCartTargetPoints[1]) : _cartPositions->push_back("0");
    controller->beckhoff->tempCartTargetPoints[2] != "0" ?_cartPositions->push_back(controller->beckhoff->tempCartTargetPoints[2]) : _cartPositions->push_back("0");
    controller->beckhoff->tempCartTargetPoints[3] != "0" ?_cartPositions->push_back(controller->beckhoff->tempCartTargetPoints[3]) : _cartPositions->push_back("0");
    controller->beckhoff->tempCartTargetPoints[4] != "0" ?_cartPositions->push_back(controller->beckhoff->tempCartTargetPoints[4]) : _cartPositions->push_back("0");
    controller->beckhoff->tempCartTargetPoints[5] != "0" ?_cartPositions->push_back(controller->beckhoff->tempCartTargetPoints[5]) : _cartPositions->push_back("0");

    if(controller->IsFirstPositionPageLunch)
    {
        setIsJoint(true);
        setVelocity(20);
        setIsPTP(false);
        controller->IsFirstPositionPageLunch = false;
    }
    setVelocity(controller->PositionVelocity);
    setIsPTP(controller->PositionPTP);
    setIsJoint(controller->IsJogInPositionPage);
}

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
            controller->beckhoff->tempJointTargetPoints[i] =_positions->at(i);
        }
        // changed 20 to 200
        //template
        controller->beckhoff->setTargetPosition(Velocity(),6);
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
            for(int i=0; i<controller->beckhoff->NumberOfRobotMotors; i++)
            {
                controller->robot->ActualPositionRadian[i] = controller->beckhoff->ActualPositions[i]*controller->robot->PulsToDegFactor1[i] * M_PI / 180.0;
            }
        }
        else if(CurrentFrame=="base")
        {
            tmpValue = controller->robot->currentBaseFrame->mainPoints();
        }

        double SelectedFrame[6] = {tmpValue.at(0),tmpValue.at(1),tmpValue.at(2),
                                   tmpValue.at(3),tmpValue.at(4),tmpValue.at(5)};
        double TargetPoint[6] = {_cartPositions->at(0).toDouble(),
                                 _cartPositions->at(1).toDouble(),
                                 _cartPositions->at(2).toDouble(),
                                 _cartPositions->at(3).toDouble(),
                                 _cartPositions->at(4).toDouble(),
                                 _cartPositions->at(5).toDouble()};
        double OutPointInRef[6];
        controller->robot->PointInReference(TargetPoint,SelectedFrame,CurrentFrame,OutPointInRef);
        for (int i=0; i< controller->beckhoff->NumberOfRobotMotors; ++i) {
            controller->beckhoff->setTargetPosition(OutPointInRef[i],i);
            controller->beckhoff->tempCartTargetPoints[i] = _cartPositions->at(i);
        }
        controller->beckhoff->setTargetPosition(Velocity(),6);
        controller->beckhoff->setTargetPosition(0,7);
        controller->beckhoff->setTargetPosition(1,8); //time
        if(IsPTP())
            controller->beckhoff->setGUIManager(10); //PTP Cartesian
        else
            controller->beckhoff->setGUIManager(12); // LIN
    }
    controller->IsMovementStop = false;
    controller->IsClearMovementStop = false;
}

void PositionViewModel::GoHome()
{
    for (int i=0; i<controller->beckhoff->NumberOfRobotMotors; i++) {
        controller->beckhoff->setTargetPosition(0,i);
        controller->beckhoff->tempJointTargetPoints[i] = "0";
        controller->beckhoff->tempCartTargetPoints[i] = "0";
    }
    controller->beckhoff->setTargetPosition(30,6);
    controller->beckhoff->setTargetPosition(0,7);
    controller->beckhoff->setGUIManager(8);
}

bool PositionViewModel::IsJoint()
{
    return _isJoint;
}

bool PositionViewModel::IsPTP()
{
    return _isPTP;
}

int PositionViewModel::Velocity()
{
    return _velocity;
}

void PositionViewModel::setVelocity(int val)
{
    controller->PositionVelocity = val;
    _velocity = val;
    Q_EMIT VelocityChanged();
}

void PositionViewModel::setIsPTP(bool val)
{
    controller->PositionPTP = val;
    _isPTP = val;
    Q_EMIT IsPTPChanged();
}



void PositionViewModel::setIsJoint(bool val)
{
    _isJoint = val;
    controller->IsJogInPositionPage=val;
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

QList<QString> PositionViewModel::CartPositions()
{
    return *_cartPositions;
}

void PositionViewModel::setCartPositions(QString val, int i)
{
    _cartPositions->insert(i,val);
    //    CartPointsChanged();
}

void PositionViewModel::setTypeOfFrame(QString val)
{
    _typeOfFrame = val;
    Q_EMIT TypeOfFrameChanged();
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
//    controller->beckhoff->setGUIManager(99);
//    while(controller->beckhoff->getGUIManager()!=100);
//    controller->beckhoff->setGUIManager(4);
//    controller->alarmList.clear();
//    controller->AlarmDetection();
}

