#ifndef VELOCITYACCELERATIONVIEWMODEL_H
#define VELOCITYACCELERATIONVIEWMODEL_H

#include <QObject>
#include "Model/Controller/controller.h"

class VelocityAccelerationViewModel : public QObject
{
    Q_OBJECT
public:
    explicit VelocityAccelerationViewModel(QObject *parent = nullptr);

Q_SIGNALS:


public Q_SLOTS:



private:

    Controller *controller;
};

#endif // VELOCITYACCELERATIONVIEWMODEL_H
