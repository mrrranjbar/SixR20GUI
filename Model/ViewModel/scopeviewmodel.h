#ifndef SCOPEVIEWMODEL_H
#define SCOPEVIEWMODEL_H

#include <QObject>
#include <QtCharts>

#include "../Controller/controller.h"
#include "customplotitem.h"
#include "Model/Robot/TrajectoryPoint.h"

using namespace QtCharts;

class scopeviewmodel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(int motorNum READ motorNum WRITE setMotorNum)
public:
    explicit scopeviewmodel(QObject *parent = nullptr);


signals:

public slots:

    void run(QString mode,int teachpoint);
    void setMotorNum(int type);
    int motorNum();

private:
    Controller * controller;
    int _motorNum = 0;
};

#endif // SCOPEVIEWMODEL_H
