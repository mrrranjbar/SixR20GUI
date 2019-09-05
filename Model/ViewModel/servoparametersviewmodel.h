#ifndef SERVOPARAMETERSVIEWMODEL_H
#define SERVOPARAMETERSVIEWMODEL_H

#include <QObject>

class servoparametersviewmodel : public QObject
{
    Q_OBJECT
public:
    explicit servoparametersviewmodel(QObject *parent = nullptr);

Q_SIGNALS:

public Q_SLOTS:
};

#endif // SERVOPARAMETERSVIEWMODEL_H