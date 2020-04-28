#ifndef VELOCITYACCELERATIONVIEWMODEL_H
#define VELOCITYACCELERATIONVIEWMODEL_H

#include <QObject>
#include "Model/Controller/controller.h"

class VelocityAccelerationViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool confj READ Confj WRITE setConfj)
    Q_PROPERTY(int confData READ ConfData WRITE setConfData)
    Q_PROPERTY(bool singulPTP READ SingulPTP WRITE setSingulPTP)
    Q_PROPERTY(bool singulCP READ SingulCP WRITE setSingulCP)

public:
    explicit VelocityAccelerationViewModel(QObject *parent = nullptr);

Q_SIGNALS:


public Q_SLOTS:

    bool Confj();
    void setConfj(bool value);
    int ConfData();
    void setConfData(int value);
    bool SingulPTP();
    void setSingulPTP(bool value);
    bool SingulCP();
    void setSingulCP(bool value);

private:

    int _conf_data;
    bool _conf_j;
    bool _singul_ptp;
    bool _singul_cp;

    Controller *controller;
};

#endif // VELOCITYACCELERATIONVIEWMODEL_H
