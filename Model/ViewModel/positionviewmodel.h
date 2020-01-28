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
    Q_PROPERTY(short FeedOverRide READ FeedOverRide WRITE setFeedOverRide NOTIFY FeedOverRideChanged)
    Q_PROPERTY(QString TypeOfFrame READ TypeOfFrame WRITE setTypeOfFrame NOTIFY TypeOfFrameChanged)
//    Q_PROPERTY(QList<QString> tempJontPoints READ getTempCartPoints WRITE setTempCartPoints NOTIFY TempCartPointsChanged)
public:
    explicit PositionViewModel(QObject *parent = nullptr);

Q_SIGNALS:

    void IsJointChanged();
    void TypeOfFrameChanged();
    void FeedOverRideChanged();
//    void PositionChanged();
//    void CartPointsChanged();

public Q_SLOTS:
    //void Move(int index);
    void MoveAll();
    void GoHome();
    bool IsJoint();
    short FeedOverRide();
    void setIsJoint(bool val);

    QList<QString> Positions();
    void setPosition(QString val, int i);
    QList<QString> CartPositions();
    void setCartPositions(QString val, int i);

    void setTypeOfFrame(QString val);
    void setFeedOverRide(short val);
    QString TypeOfFrame();
    void RunMotors();
    void ClearAlarms();

private:
     QList<QString> *_positions;
     QList<QString> *_cartPositions;
    Controller *controller;
    QString _typeOfFrame;
    bool _isJoint;
    short _feedOverRide;
};

#endif // POSITIONVIEWMODEL_H
