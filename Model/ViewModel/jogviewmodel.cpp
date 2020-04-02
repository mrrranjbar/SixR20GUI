#include "jogviewmodel.h"
#include "Model/Controller/controller.h"
JogViewModel::JogViewModel(QObject *parent) : QObject(parent)
{   
    controller = Controller::getInstance();
//    for (int i=0; i < controller->beckhoff->NumberOfRobotMotors; i++) {
//        controller->beckhoff->setMSelect(false,i);
//        controller->beckhoff->setGUIJogDirection(1);
//    }
    _actualPosition = new QList<double>();
    if(controller->IsFirstJogPageLunch)
    {
      setFine(false);
      setFineVelocity(50);
      setFineAcceleration(50);
      setFineDeceleration(50);
      setIsJoint(true);
      controller->IsFirstJogPageLunch = false;
    }
    setIsJoint(controller->IsJoint());
    setFine(controller->JogFine);
    setFineVelocity(controller->JogFineVelocity);
    setFineAcceleration(controller->JogFineAcceleration);
    setFineDeceleration(controller->JogFineDeceleration);
    setVelocity(controller->beckhoff->getJogVelocity());
    setAcceleration(controller->beckhoff->getJogAcceleration());
    setDeceleration(controller->beckhoff->getJogDeceleration());
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

int JogViewModel::Velocity()
{
    return _fine? (_velocity * 100) / _fineVelocity : _velocity;
}

int JogViewModel::Acceleration()
{
    return _fine? (_acceleration * 100) / _fineAcceleration : _acceleration;
}

int JogViewModel::Deceleration()
{
    return _fine? (_deceleration * 100) / _fineDeceleration : _deceleration;
}
int JogViewModel::FineVelocity()
{
    return _fineVelocity;
}

bool JogViewModel::Fine()
{
    return _fine;
}

bool JogViewModel::IsJoint()
{
    return _isJoint;
}

int JogViewModel::FineAcceleration()
{
    return _fineAcceleration;
}

int JogViewModel::FineDeceleration()
{
    return _fineDeceleration;
}

void JogViewModel::setActualPosition(QList<double> value)
{
    _actualPosition = &value;
    Q_EMIT ActualPositionChanged();
}

void JogViewModel::setVelocity(int value)
{
    _velocity = _fine? (value * _fineVelocity) / 100 : value;
    controller->beckhoff->setJogVelocity(_velocity);
    Q_EMIT VelocityChanged();
}

void JogViewModel::setAcceleration(int value)
{
    _acceleration = _fine? (value * _fineAcceleration) / 100 : value;
    controller->beckhoff->setJogAcceleration(_acceleration);
    Q_EMIT AccelerationChanged();
}

void JogViewModel::setDeceleration(int value)
{
    _deceleration = _fine? (value * _fineDeceleration) / 100 : value;
    controller->beckhoff->setJogDeceleration(_deceleration);
    Q_EMIT DecelerationChanged();
}
void JogViewModel::setFineVelocity(int value)
{
    _fineVelocity = value;
    controller->JogFineVelocity = _fineVelocity;
    Q_EMIT FineVelocityChanged();
}

void JogViewModel::setFine(bool value)
{
    _fine = value;
    controller->JogFine = _fine;
    Q_EMIT FineChanged();
}

void JogViewModel::setIsJoint(bool value)
{
    _isJoint = value;
    controller->setIsJoint(value);
    Q_EMIT IsJointChanged();
}

void JogViewModel::setFineAcceleration(int value)
{
    _fineAcceleration = value;
    controller->JogFineAcceleration = _fineAcceleration;
    Q_EMIT FineAccelerationChanged();
}

void JogViewModel::setFineDeceleration(int value)
{
    _fineDeceleration = value;
    controller->JogFineDeceleration = _fineDeceleration;
    Q_EMIT FineDecelerationChanged();
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
