#include "velocityaccelerationviewmodel.h"

VelocityAccelerationViewModel::VelocityAccelerationViewModel(QObject *parent) : QObject(parent)
{
    controller = Controller::getInstance();
}

int VelocityAccelerationViewModel::JogMaxVelocity()
{
    //return _jogMaxVelocity;
    return controller->beckhoff->getJogMaxVelocity();
}

int VelocityAccelerationViewModel::JogMaxAcceleration()
{
    //return _jogMaxAcceleration;
    return controller->beckhoff->getJogMaxAcceleration();
}

int VelocityAccelerationViewModel::JogMaxDeceleration()
{
    //return _jogMaxDeceleration;
    return controller->beckhoff->getJogMaxDeceleration();
}

void VelocityAccelerationViewModel::setJogMaxVelocity(int val)
{
    controller->beckhoff->setJogMaxVelocity(val);
    //_jogMaxVelocity = val;
    Q_EMIT JogMaxVelocity();
}

void VelocityAccelerationViewModel::setJogMaxAcceleration(int val)
{
    controller->beckhoff->setJogMaxAcceleration(val);
    //_jogMaxAcceleration = val;
    Q_EMIT JogMaxAcceleration();
}

void VelocityAccelerationViewModel::setJogMaxDeceleration(int val)
{
    controller->beckhoff->setJogMaxDeceleration(val);
    //_jogMaxDeceleration = val;
    Q_EMIT JogMaxDeceleration();
}
