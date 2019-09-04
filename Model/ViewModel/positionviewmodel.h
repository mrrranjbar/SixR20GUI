#ifndef POSITIONVIEWMODEL_H
#define POSITIONVIEWMODEL_H

#include "Model/Controller/controller.h"
#include <QObject>

class PositionViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QString> Positions READ Positions)
    Q_PROPERTY(bool IsJoint READ IsJoint WRITE setIsJoint NOTIFY IsJointChanged)
    Q_PROPERTY(QString TypeOfFrame READ TypeOfFrame WRITE setTypeOfFrame NOTIFY TypeOfFrameChanged)
public:
    explicit PositionViewModel(QObject *parent = nullptr);

signals:

    void IsJointChanged();
    void TypeOfFrameChanged();
    //void PositionChanged();

public slots:
    //void Move(int index);
    void MoveAll();
    void GoHome();
    bool IsJoint();
    void setIsJoint(bool val);
    QList<QString> Positions();
    void setPosition(QString val, int i);
    void setTypeOfFrame(QString val);
    QString TypeOfFrame();

private:
     QList<QString> *_positions;
    Controller *controller;
    QString _typeOfFrame;
    bool _isJoint;
};

#endif // POSITIONVIEWMODEL_H
