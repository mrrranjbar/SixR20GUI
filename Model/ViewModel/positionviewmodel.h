#ifndef POSITIONVIEWMODEL_H
#define POSITIONVIEWMODEL_H

#include "Model/Controller/controller.h"
#include <QObject>

class PositionViewModel : public QObject
{
    Q_OBJECT
    // for showing positions on screen
    Q_PROPERTY(QList<QString> Positions READ Positions)
    Q_PROPERTY(QList<QString> CartPositions READ CartPositions ) /*WRITE setCartPositions NOTIFY CartPointsChanged*/
    //********************
    Q_PROPERTY(bool IsJoint READ IsJoint WRITE setIsJoint NOTIFY IsJointChanged)
    Q_PROPERTY(bool IsPTP READ IsPTP WRITE setIsPTP NOTIFY IsPTPChanged)
    Q_PROPERTY(int Velocity READ Velocity WRITE setVelocity NOTIFY VelocityChanged)
    Q_PROPERTY(QString TypeOfFrame READ TypeOfFrame WRITE setTypeOfFrame NOTIFY TypeOfFrameChanged)
//    Q_PROPERTY(QList<QString> tempJontPoints READ getTempCartPoints WRITE setTempCartPoints NOTIFY TempCartPointsChanged)
public:
    explicit PositionViewModel(QObject *parent = nullptr);

Q_SIGNALS:

    void IsJointChanged();
    void IsPTPChanged();
    void VelocityChanged();
    void TypeOfFrameChanged();
//    void PositionChanged();
//    void CartPointsChanged();

public Q_SLOTS:
    //void Move(int index);
    void MoveAll();
    void GoHome();
    bool IsJoint();
    bool IsPTP();
    int Velocity();
    void setVelocity(int val);
    void setIsPTP(bool val);
    void setIsJoint(bool val);

    QList<QString> Positions();
    void setPosition(QString val, int i);
    QList<QString> CartPositions();
    void setCartPositions(QString val, int i);

    void setTypeOfFrame(QString val);
    QString TypeOfFrame();
    void RunMotors();
    void ClearAlarms();

private:
     QList<QString> *_positions;
     QList<QString> *_cartPositions;
    Controller *controller;
    QString _typeOfFrame;
    bool _isJoint;
    bool _isPTP;
    int _velocity;
};

#endif // POSITIONVIEWMODEL_H
