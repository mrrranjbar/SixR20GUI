#ifndef POSITIONVIEWMODEL_H
#define POSITIONVIEWMODEL_H

#include "Model/Controller/controller.h"
#include <QObject>

class PositionViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QString> Positions READ Positions)
public:
    explicit PositionViewModel(QObject *parent = nullptr);

signals:
    //void PositionChanged();

public slots:
    //void Move(int index);
    void MoveAll();
    void GoHome();
    QList<QString> Positions();
    void setPosition(QString val, int i);

private:
     QList<QString> *_positions;
    Controller *controller;
};

#endif // POSITIONVIEWMODEL_H
