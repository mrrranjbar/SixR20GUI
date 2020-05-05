#include "jogviewmodel.h"
#include "Model/Controller/controller.h"
JogViewModel::JogViewModel(QObject *parent) : QObject(parent)
{   
    controller = Controller::getInstance();
    _actualPosition = new QList<double>();

    if(controller->IsFirstJogPageLunch)
    {
        setFine(false);
        setIsJoint(true);
        setFineVelocity(50);
        setFineAcceleration(50);
        setFineDeceleration(50);
        setVelocity(5);
        setAcceleration(50);
        setDeceleration(50);
        setIsJoint(false); // for cartesian
        setVelocity(30); // for cartesian
        setAcceleration(100); // for cartesian
        setDeceleration(400); // for cartesian
        setFineVelocity(50); // for cartesian
        setFineAcceleration(50); // for cartesian
        setFineDeceleration(50); // for cartesian
        setIsJoint(true);
        setAbcRatio(10);
        controller->IsFirstJogPageLunch = false;
        setCurrentFrame(1);
    }
    else
    {
        setCurrentFrame(controller->JogCartCurrentFrame);
        setIsJoint(controller->IsJoint());
        setFine(controller->JogFine);
        setAbcRatio(controller->JogAbcRatio);
        bool tmp = IsJoint();
        setIsJoint(true);
        setFineVelocity(controller->JogFineVelocity);
        setFineAcceleration(controller->JogFineAcceleration);
        setFineDeceleration(controller->JogFineDeceleration);
        setVelocity(controller->JogVelocity);
        setAcceleration(controller->JogAcceleration);
        setDeceleration(controller->JogDeceleration);
        setIsJoint(false);
        setFineVelocity(controller->JogFineVelocityCart);
        setFineAcceleration(controller->JogFineAccelerationCart);
        setFineDeceleration(controller->JogFineDecelerationCart);
        setVelocity(controller->JogVelocityCart);
        setAcceleration(controller->JogAccelerationCart);
        setDeceleration(controller->JogDecelerationCart);
        setIsJoint(tmp);
    }

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
        //controller->beckhoff->setMSelect(false,index);
    }
    controller->beckhoff->setGUIManager(65);
}

QList<double> JogViewModel::ActualPosition()
{
    return *_actualPosition;
}

int JogViewModel::CurrentFrame()
{
    return _currentFrame;
}

void JogViewModel::setCurrentFrame(int value)
{
    controller->beckhoff->setJogCartCurrentFrame(value);
    _currentFrame = value;
    controller->JogCartCurrentFrame = value;
    Q_EMIT CurrentFrameChanged();
}

double JogViewModel::Velocity()
{
    if(IsJoint())
    {
        return _fine? (_velocity * 100) / _fineVelocity : _velocity;
    }
    else
    {
        return _fine? (_velocityCart * 100) / _fineVelocityCart : _velocityCart;
    }
}

double JogViewModel::AbcRatio()
{
    return  _abcRatio;
}

double JogViewModel::Acceleration()
{
    if(IsJoint())
        return _fine? (_acceleration * 100) / _fineAcceleration : _acceleration;
    else
        return _fine? (_accelerationCart * 100) / _fineAccelerationCart : _accelerationCart;
}

double JogViewModel::Deceleration()
{
    if(IsJoint())
        return _fine? (_deceleration * 100) / _fineDeceleration : _deceleration;
    else
        return _fine? (_decelerationCart * 100) / _fineDecelerationCart : _decelerationCart;
}
int JogViewModel::FineVelocity()
{
    if(IsJoint())
        return _fineVelocity;
    else
        return _fineVelocityCart;
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
    if(IsJoint())
        return _fineAcceleration;
    else
        return _fineAccelerationCart;
}

int JogViewModel::FineDeceleration()
{
    if(IsJoint())
        return _fineDeceleration;
    else
        return _fineDecelerationCart;
}

void JogViewModel::setActualPosition(QList<double> value)
{
    _actualPosition = &value;
    Q_EMIT ActualPositionChanged();
}

void JogViewModel::setVelocity(double value)
{
    if(IsJoint())
    {
        _velocity = _fine? (value * _fineVelocity) / 100 : value;
        controller->beckhoff->setJogVelocity(_velocity);
        controller->JogVelocity = _velocity;
    }
    else
    {
        _velocityCart = _fine? (value * _fineVelocityCart) / 100 : value;
        controller->beckhoff->setJogVelocityCart(_velocityCart);
        controller->JogVelocityCart = _velocityCart;
    }
    Q_EMIT VelocityChanged();
}

void JogViewModel::setAbcRatio(double value)
{
    controller->beckhoff->setJogAbcRatio(value);
    controller->JogAbcRatio = value;
    _abcRatio = value;
    Q_EMIT AbcRatioChanged();
}

void JogViewModel::setAcceleration(double value)
{
    if(IsJoint())
    {
        _acceleration = _fine? (value * _fineAcceleration) / 100 : value;
        controller->beckhoff->setJogAcceleration(_acceleration);
        controller->JogAcceleration = _acceleration;
    }
    else
    {
        _accelerationCart = _fine? (value * _fineAccelerationCart) / 100 : value;
        controller->beckhoff->setJogAccelerationCart(_accelerationCart);
        controller->JogAccelerationCart = _accelerationCart;
    }
    Q_EMIT AccelerationChanged();
}

void JogViewModel::setDeceleration(double value)
{
    if(IsJoint())
    {
        _deceleration = _fine? (value * _fineDeceleration) / 100 : value;
        controller->beckhoff->setJogDeceleration(_deceleration);
        controller->JogDeceleration = _deceleration;
    }
    else
    {
        _decelerationCart = _fine? (value * _fineDecelerationCart) / 100 : value;
        controller->beckhoff->setJogDecelerationCart(_decelerationCart);
        controller->JogDecelerationCart = _decelerationCart;
    }
    Q_EMIT DecelerationChanged();
}
void JogViewModel::setFineVelocity(int value)
{
    if(IsJoint())
    {
        _fineVelocity = value;
        controller->JogFineVelocity = _fineVelocity;
    }
    else
    {
        _fineVelocityCart = value;
        controller->JogFineVelocityCart = _fineVelocityCart;
    }
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
    if(IsJoint())
    {
        _fineAcceleration = value;
        controller->JogFineAcceleration = _fineAcceleration;
    }
    else
    {
        _fineAccelerationCart = value;
        controller->JogFineAccelerationCart = _fineAccelerationCart;
    }
    Q_EMIT FineAccelerationChanged();
}

void JogViewModel::setFineDeceleration(int value)
{
    if(IsJoint())
    {
        _fineDeceleration = value;
        controller->JogFineDeceleration = _fineDeceleration;
    }
    else
    {
        _fineDecelerationCart = value;
        controller->JogFineDecelerationCart = _fineDecelerationCart;
    }
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
        //controller->beckhoff->setMSelect(false,index);
    }
    controller->beckhoff->setGUIManager(64);
}
