#include "velocityaccelerationviewmodel.h"

VelocityAccelerationViewModel::VelocityAccelerationViewModel(QObject *parent) : QObject(parent)
{
    controller = Controller::getInstance();
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
//    controller->beckhoff->setConfJ(value);
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
    //    controller->beckhoff->setConfData(value);
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
//    controller->beckhoff->setSingulPTP(value);
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
//    controller->beckhoff->setSingulCP(value);
}

