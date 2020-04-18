#ifndef VELOCITYACCELERATIONVIEWMODEL_H
#define VELOCITYACCELERATIONVIEWMODEL_H

#include <QObject>
#include "Model/Controller/controller.h"

class VelocityAccelerationViewModel : public QObject
{
    Q_OBJECT
public:
    explicit VelocityAccelerationViewModel(QObject *parent = nullptr);
    Q_PROPERTY(int JogMaxVelocity READ JogMaxVelocity WRITE setJogMaxVelocity NOTIFY JogMaxVelocityChanged)
    Q_PROPERTY(int JogMaxAcceleration READ JogMaxAcceleration WRITE setJogMaxAcceleration NOTIFY JogMaxAccelerationChanged)
    Q_PROPERTY(int JogMaxDeceleration READ JogMaxDeceleration WRITE setJogMaxDeceleration NOTIFY JogMaxDecelerationChanged)

Q_SIGNALS:
    void JogMaxVelocityChanged();
    void JogMaxAccelerationChanged();
    void JogMaxDecelerationChanged();

public Q_SLOTS:
    int JogMaxVelocity();
    int JogMaxAcceleration();
    int JogMaxDeceleration();
    void setJogMaxVelocity(int val);
    void setJogMaxAcceleration(int val);
    void setJogMaxDeceleration(int val);

private:
    int _jogMaxVelocity;
    int _jogMaxAcceleration;
    int _jogMaxDeceleration;
    Controller *controller;
};

#endif // VELOCITYACCELERATIONVIEWMODEL_H
