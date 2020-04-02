#ifndef JOGVIEWMODEL_H
#define JOGVIEWMODEL_H

#include <QObject>
#include "Model/Controller/controller.h"

class JogViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<double> ActualPosition READ ActualPosition WRITE setActualPosition NOTIFY ActualPositionChanged)
    Q_PROPERTY(int Velocity READ Velocity WRITE setVelocity NOTIFY VelocityChanged)
    Q_PROPERTY(int Acceleration READ Acceleration WRITE setAcceleration NOTIFY AccelerationChanged)
    Q_PROPERTY(int Deceleration READ Deceleration WRITE setDeceleration NOTIFY DecelerationChanged)
    Q_PROPERTY(int FineVelocity READ FineVelocity WRITE setFineVelocity NOTIFY FineVelocityChanged)
    Q_PROPERTY(int FineAcceleration READ FineAcceleration WRITE setFineAcceleration NOTIFY FineAccelerationChanged)
    Q_PROPERTY(int FineDeceleration READ FineDeceleration WRITE setFineDeceleration NOTIFY FineDecelerationChanged)
    Q_PROPERTY(bool Fine READ Fine WRITE setFine NOTIFY FineChanged)
    Q_PROPERTY(bool IsJoint READ IsJoint WRITE setIsJoint NOTIFY IsJointChanged)

//   Q_PROPERTY(bool StoppingJog READ StoppingJog WRITE setStoppingJog NOTIFY StoppingJogChanged)
//    Q_PROPERTY(QList<bool> MSelect READ MSelect  WRITE setMSelect NOTIFY MSelectChanged)
//    Q_PROPERTY(int JogAcceleration READ JogAcceleration WRITE setJogAcceleration NOTIFY JogAccelerationChanged)
//    Q_PROPERTY(QList<int> JogMaxSpeed READ JogMaxSpeed  WRITE setJogMaxSpeed NOTIFY JogMaxSpeedChanged)
//    Q_PROPERTY(QList<int> JogDirection READ JogDirection  WRITE setJogDirection NOTIFY JogDirectionChanged)

public:
    explicit JogViewModel(QObject *parent = nullptr);

Q_SIGNALS:
    void ActualPositionChanged();
    void VelocityChanged();
    void AccelerationChanged();
    void DecelerationChanged();
    void FineVelocityChanged();
    void FineChanged();
    void IsJointChanged();
    void FineAccelerationChanged();
    void FineDecelerationChanged();


public Q_SLOTS:
    void jogJoint(int sign,int index, int press);
    void jogCart(int sign, int index, int press);
    QList<double> ActualPosition();
    int Velocity();
    int Acceleration();
    int Deceleration();
    int FineVelocity();
    bool Fine();
    bool IsJoint();
    int FineAcceleration();
    int FineDeceleration();
    void setActualPosition(QList<double> value);
     void setVelocity(int value);
     void setAcceleration(int value);
     void setDeceleration(int value);
     void setFineVelocity(int value);
     void setFine(bool value);
     void setIsJoint(bool value);
     void setFineAcceleration(int value);
     void setFineDeceleration(int value);
    void UpdateActualPosition();

private:
Controller *controller;
QList<double> *_actualPosition;
int _velocity;
int _acceleration;
int _deceleration;
int _fineVelocity;
int _fineAcceleration;
int _fineDeceleration;
bool _fine;
bool _isJoint;

};

#endif // JOGVIEWMODEL_H
