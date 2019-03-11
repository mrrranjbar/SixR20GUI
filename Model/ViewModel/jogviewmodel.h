#ifndef JOGVIEWMODEL_H
#define JOGVIEWMODEL_H

#include <QObject>
#include "Model/Controller/controller.h"

class JogViewModel : public QObject
{
    Q_OBJECT
//   Q_PROPERTY(bool StoppingJog READ StoppingJog WRITE setStoppingJog NOTIFY StoppingJogChanged)
//    Q_PROPERTY(QList<bool> MSelect READ MSelect  WRITE setMSelect NOTIFY MSelectChanged)
//    Q_PROPERTY(int JogAcceleration READ JogAcceleration WRITE setJogAcceleration NOTIFY JogAccelerationChanged)
//    Q_PROPERTY(QList<int> JogMaxSpeed READ JogMaxSpeed  WRITE setJogMaxSpeed NOTIFY JogMaxSpeedChanged)
//    Q_PROPERTY(QList<int> JogDirection READ JogDirection  WRITE setJogDirection NOTIFY JogDirectionChanged)

public:
    explicit JogViewModel(QObject *parent = nullptr);

signals:


public slots:
    void jogJoint(int sign,int index, int press);

private:
Controller *controller;

};

#endif // JOGVIEWMODEL_H
