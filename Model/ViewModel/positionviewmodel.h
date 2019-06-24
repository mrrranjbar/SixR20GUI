#ifndef POSITIONVIEWMODEL_H
#define POSITIONVIEWMODEL_H

#include "Model/Controller/controller.h"
#include <QObject>

class PositionViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QString> Positions READ Positions)
    Q_PROPERTY(bool IsJoint READ IsJoint WRITE setIsJoint NOTIFY IsJointChanged)
public:
    explicit PositionViewModel(QObject *parent = nullptr);

signals:
    void IsJointChanged();
    //void PositionChanged();

public slots:
    //void Move(int index);
    void MoveAll();
    void GoHome();
    bool IsJoint();
    void setIsJoint(bool val);
    QList<QString> Positions();
    void setPosition(QString val, int i);

private:
     QList<QString> *_positions;
    Controller *controller;
    bool _isJoint;
};

#endif // POSITIONVIEWMODEL_H
