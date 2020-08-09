#include "velocityaccelerationviewmodel.h"

VelocityAccelerationViewModel::VelocityAccelerationViewModel(QObject *parent) : QObject(parent)
{
    controller = Controller::getInstance();
//    if(controller->IsFirstGeneralSettingPage)
//    {
//        controller->IsFirstGeneralSettingPage = false;
//        setConfj(false);
//        setConfData(0);
//        setSingulPTP(true);
//        setSingulCP(true);
//        setMaxVelocityPTP(200);
//        setJerkPTP(200);
//        setAccelerationPTP(200);
//        setMaxVelocityCP(200);
//        setJerkCP(200);
//        setAccelerationCP(200);
//        setHomeVelocity(15);
//        setGotoVelocity(10);
//        setMaxVelocityMotor1(10);
//        setMaxVelocityMotor2(10);
//        setMaxVelocityMotor3(10);
//        setMaxVelocityMotor4(10);
//        setMaxVelocityMotor5(10);
//        setMaxVelocityMotor6(10);
//    }
//    else
//    {
//        setConfj(controller->Confj);
//        setConfData(controller->ConfData);
//        setSingulPTP(controller->SingulPTP);
//        setSingulCP(controller->SingulCP);
//        setMaxVelocityPTP(controller->MaxVelocityPTP);
//        setJerkPTP(controller->JerkPTP);
//        setAccelerationPTP(controller->AccelerationPTP);
//        setMaxVelocityCP(controller->MaxVelocityCP);
//        setJerkCP(controller->JerkCP);
//        setAccelerationCP(controller->AccelerationCP);
//        setHomeVelocity(controller->HomeVelocity);
//        setGotoVelocity(controller->GotoVelocity);
//        setMaxVelocityMotor1(controller->MaxVelocityMotor1);
//        setMaxVelocityMotor2(controller->MaxVelocityMotor2);
//        setMaxVelocityMotor3(controller->MaxVelocityMotor3);
//        setMaxVelocityMotor4(controller->MaxVelocityMotor4);
//        setMaxVelocityMotor5(controller->MaxVelocityMotor5);
//        setMaxVelocityMotor6(controller->MaxVelocityMotor6);
//    }
}

bool VelocityAccelerationViewModel::Confj()
{
    _conf_j=controller->Confj;
    return _conf_j;
}

void VelocityAccelerationViewModel::setConfj(bool value)
{
    controller->Confj=value;
    _conf_j=value;
    controller->beckhoff->setConfJ(value);
    Q_EMIT ConfjChanged();
}

int VelocityAccelerationViewModel::ConfData()
{
    _conf_data=controller->ConfData;
    return _conf_data;
}

void VelocityAccelerationViewModel::setConfData(int value)
{
    controller->ConfData=value;
    _conf_data=value;
    controller->beckhoff->setConfData(value);
    Q_EMIT ConfDataChanged();
}

bool VelocityAccelerationViewModel::SingulPTP()
{
    _singul_ptp=controller->SingulPTP;
    return _singul_ptp;
}

void VelocityAccelerationViewModel::setSingulPTP(bool value)
{
    controller->SingulPTP=value;
    _singul_ptp=value;
    controller->beckhoff->setSingulPTP(value);
    Q_EMIT SingulPTPChanged();
}

bool VelocityAccelerationViewModel::SingulCP()
{
    _singul_cp=controller->SingulCP;
    return _singul_cp;
}

void VelocityAccelerationViewModel::setSingulCP(bool value)
{
    controller->SingulCP=value;
    _singul_cp=value;
    controller->beckhoff->setSingulCP(value);
    Q_EMIT SingulCPChanged();
}

double VelocityAccelerationViewModel::MaxVelocityPTP()
{
    _max_velocity_ptp=controller->MaxVelocityPTP;
    return _max_velocity_ptp;
}

double VelocityAccelerationViewModel::JerkPTP()
{
    _jerk_ptp=controller->JerkPTP;
    return _jerk_ptp;
}

double VelocityAccelerationViewModel::AccelerationPTP()
{
    _acceleration_ptp=controller->AccelerationPTP;
    return _acceleration_ptp;
}

double VelocityAccelerationViewModel::MaxVelocityCP()
{
    _max_velocity_cp=controller->MaxVelocityCP;
    return _max_velocity_cp;
}

double VelocityAccelerationViewModel::JerkCP()
{
    _jerk_cp=controller->JerkCP;
    return _jerk_cp;
}

double VelocityAccelerationViewModel::AccelerationCP()
{
    _acceleration_cp=controller->AccelerationCP;
    return _acceleration_cp;
}

double VelocityAccelerationViewModel::HomeVelocity()
{
    _home_velocity=controller->HomeVelocity;
    return _home_velocity;
}

double VelocityAccelerationViewModel::GotoVelocity()
{
    _goto_velocity=controller->GotoVelocity;
    return _goto_velocity;
}

void VelocityAccelerationViewModel::setMaxVelocityPTP(double value)
{
    controller->MaxVelocityPTP=value;
    _max_velocity_ptp=value;
    controller->beckhoff->setMaxVelocityPTP(value);
    Q_EMIT MaxVelocityPTPChanged();
}

void VelocityAccelerationViewModel::setJerkPTP(double value)
{
    controller->JerkPTP=value;
    _jerk_ptp=value;
    controller->beckhoff->setJerkPTP(value);
    Q_EMIT JerkPTPChanged();
}

void VelocityAccelerationViewModel::setAccelerationPTP(double value)
{
    controller->AccelerationPTP=value;
    _acceleration_ptp=value;
    controller->beckhoff->setAccelerationPTP(value);
    Q_EMIT AccelerationPTPChanged();
}

void VelocityAccelerationViewModel::setMaxVelocityCP(double value)
{
    controller->MaxVelocityCP=value;
    _max_velocity_cp=value;
    controller->beckhoff->setMaxVelocityCP(value);
    Q_EMIT MaxVelocityCPChanged();
}

void VelocityAccelerationViewModel::setJerkCP(double value)
{
    controller->JerkCP=value;
    _jerk_cp=value;
    controller->beckhoff->setJerkCP(value);
    Q_EMIT JerkCPChanged();
}

void VelocityAccelerationViewModel::setAccelerationCP(double value)
{
    controller->AccelerationCP=value;
    _acceleration_cp=value;
    controller->beckhoff->setAccelerationCP(value);
    Q_EMIT AccelerationCPChanged();
}

void VelocityAccelerationViewModel::setHomeVelocity(double value)
{
    controller->HomeVelocity=value;
    _home_velocity=value;
    Q_EMIT HomeVelocityChanged();
}

void VelocityAccelerationViewModel::setGotoVelocity(double value)
{
    controller->GotoVelocity=value;
    _goto_velocity=value;
    Q_EMIT GotoVelocityChanged();
}

double VelocityAccelerationViewModel::MaxVelocityMotor1()
{
    _max_velocity_motor1=controller->MaxVelocityMotor1;
    return _max_velocity_motor1;
}

double VelocityAccelerationViewModel::MaxVelocityMotor2()
{
    _max_velocity_motor2=controller->MaxVelocityMotor2;
    return _max_velocity_motor2;
}

double VelocityAccelerationViewModel::MaxVelocityMotor3()
{
    _max_velocity_motor3=controller->MaxVelocityMotor3;
    return _max_velocity_motor3;
}

double VelocityAccelerationViewModel::MaxVelocityMotor4()
{
    _max_velocity_motor4=controller->MaxVelocityMotor4;
    return _max_velocity_motor4;
}

double VelocityAccelerationViewModel::MaxVelocityMotor5()
{
    _max_velocity_motor5=controller->MaxVelocityMotor5;
    return _max_velocity_motor5;
}

double VelocityAccelerationViewModel::MaxVelocityMotor6()
{
    _max_velocity_motor6=controller->MaxVelocityMotor6;
    return _max_velocity_motor6;
}

void VelocityAccelerationViewModel::setMaxVelocityMotor1(double value)
{
    controller->MaxVelocityMotor1=value;
    _max_velocity_motor1=value;
    controller->beckhoff->setMaxVelocityMotor(1,value);
    Q_EMIT MaxVelocityMotor1Changed();
}

void VelocityAccelerationViewModel::setMaxVelocityMotor2(double value)
{
    controller->MaxVelocityMotor2=value;
    _max_velocity_motor2=value;
    controller->beckhoff->setMaxVelocityMotor(2,value);
    Q_EMIT MaxVelocityMotor2Changed();
}

void VelocityAccelerationViewModel::setMaxVelocityMotor3(double value)
{
    controller->MaxVelocityMotor3=value;
    _max_velocity_motor3=value;
    controller->beckhoff->setMaxVelocityMotor(3,value);
    Q_EMIT MaxVelocityMotor3Changed();
}

void VelocityAccelerationViewModel::setMaxVelocityMotor4(double value)
{
    controller->MaxVelocityMotor4=value;
    _max_velocity_motor4=value;
    controller->beckhoff->setMaxVelocityMotor(4,value);
    Q_EMIT MaxVelocityMotor4Changed();
}

void VelocityAccelerationViewModel::setMaxVelocityMotor5(double value)
{
    controller->MaxVelocityMotor5=value;
    _max_velocity_motor5=value;
    controller->beckhoff->setMaxVelocityMotor(5,value);
    Q_EMIT MaxVelocityMotor5Changed();
}

void VelocityAccelerationViewModel::setMaxVelocityMotor6(double value)
{
    controller->MaxVelocityMotor6=value;
    _max_velocity_motor6=value;
    controller->beckhoff->setMaxVelocityMotor(6,value);
    Q_EMIT MaxVelocityMotor6Changed();
}

void VelocityAccelerationViewModel::setHomePosition()
{
    for(int i=0;i<controller->beckhoff->NumberOfRobotMotors;i++)
    {
        controller->homePosition[i]=controller->beckhoff->ActualPositions[i]*controller->robot->PulsToDegFactor1[i];
    }
}

