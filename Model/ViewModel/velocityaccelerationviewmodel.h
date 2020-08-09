#ifndef VELOCITYACCELERATIONVIEWMODEL_H
#define VELOCITYACCELERATIONVIEWMODEL_H

#include <QObject>
#include "Model/Controller/controller.h"

class VelocityAccelerationViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool confj READ Confj WRITE setConfj NOTIFY ConfjChanged)
    Q_PROPERTY(int confData READ ConfData WRITE setConfData NOTIFY ConfDataChanged)
    Q_PROPERTY(bool singulPTP READ SingulPTP WRITE setSingulPTP NOTIFY SingulPTPChanged)
    Q_PROPERTY(bool singulCP READ SingulCP WRITE setSingulCP NOTIFY SingulCPChanged)
    Q_PROPERTY(double maxVelocityPTP READ MaxVelocityPTP WRITE setMaxVelocityPTP NOTIFY MaxVelocityPTPChanged)
    Q_PROPERTY(double jerkPTP READ JerkPTP WRITE setJerkPTP NOTIFY JerkPTPChanged)
    Q_PROPERTY(double accelerationPTP READ AccelerationPTP WRITE setAccelerationPTP NOTIFY AccelerationPTPChanged)
    Q_PROPERTY(double maxVelocityCP READ MaxVelocityCP WRITE setMaxVelocityCP NOTIFY MaxVelocityCPChanged)
    Q_PROPERTY(double jerkCP READ JerkCP WRITE setJerkCP NOTIFY JerkCPChanged)
    Q_PROPERTY(double accelerationCP READ AccelerationCP WRITE setAccelerationCP NOTIFY AccelerationCPChanged)
    Q_PROPERTY(double homeVelocity READ HomeVelocity WRITE setHomeVelocity NOTIFY HomeVelocityChanged)
    Q_PROPERTY(double gotoVelocity READ GotoVelocity WRITE setGotoVelocity NOTIFY GotoVelocityChanged)
    Q_PROPERTY(double maxVelocityMotor1 READ MaxVelocityMotor1 WRITE setMaxVelocityMotor1 NOTIFY MaxVelocityMotor1Changed)
    Q_PROPERTY(double maxVelocityMotor2 READ MaxVelocityMotor2 WRITE setMaxVelocityMotor2 NOTIFY MaxVelocityMotor2Changed)
    Q_PROPERTY(double maxVelocityMotor3 READ MaxVelocityMotor3 WRITE setMaxVelocityMotor3 NOTIFY MaxVelocityMotor3Changed)
    Q_PROPERTY(double maxVelocityMotor4 READ MaxVelocityMotor4 WRITE setMaxVelocityMotor4 NOTIFY MaxVelocityMotor4Changed)
    Q_PROPERTY(double maxVelocityMotor5 READ MaxVelocityMotor5 WRITE setMaxVelocityMotor5 NOTIFY MaxVelocityMotor5Changed)
    Q_PROPERTY(double maxVelocityMotor6 READ MaxVelocityMotor6 WRITE setMaxVelocityMotor6 NOTIFY MaxVelocityMotor6Changed)

public:
    explicit VelocityAccelerationViewModel(QObject *parent = nullptr);

Q_SIGNALS:
    void ConfjChanged();
    void ConfDataChanged();
    void SingulPTPChanged();
    void SingulCPChanged();
    void MaxVelocityPTPChanged();
    void JerkPTPChanged();
    void AccelerationPTPChanged();
    void MaxVelocityCPChanged();
    void JerkCPChanged();
    void AccelerationCPChanged();
    void HomeVelocityChanged();
    void GotoVelocityChanged();
    void MaxVelocityMotor1Changed();
    void MaxVelocityMotor2Changed();
    void MaxVelocityMotor3Changed();
    void MaxVelocityMotor4Changed();
    void MaxVelocityMotor5Changed();
    void MaxVelocityMotor6Changed();


public Q_SLOTS:

    bool Confj();
    void setConfj(bool value);
    int ConfData();
    void setConfData(int value);
    bool SingulPTP();
    void setSingulPTP(bool value);
    bool SingulCP();
    void setSingulCP(bool value);
    double MaxVelocityPTP();
    double JerkPTP();
    double AccelerationPTP();
    double MaxVelocityCP();
    double JerkCP();
    double AccelerationCP();
    double HomeVelocity();
    double GotoVelocity();
    void setMaxVelocityPTP(double value);
    void setJerkPTP(double value);
    void setAccelerationPTP(double value);
    void setMaxVelocityCP(double value);
    void setJerkCP(double value);
    void setAccelerationCP(double value);
    void setHomeVelocity(double value);
    void setGotoVelocity(double value);
    double MaxVelocityMotor1();
    double MaxVelocityMotor2();
    double MaxVelocityMotor3();
    double MaxVelocityMotor4();
    double MaxVelocityMotor5();
    double MaxVelocityMotor6();
    void setMaxVelocityMotor1(double value);
    void setMaxVelocityMotor2(double value);
    void setMaxVelocityMotor3(double value);
    void setMaxVelocityMotor4(double value);
    void setMaxVelocityMotor5(double value);
    void setMaxVelocityMotor6(double value);

    void setHomePosition();


private:

    int _conf_data;
    bool _conf_j;
    bool _singul_ptp;
    bool _singul_cp;
    double _max_velocity_ptp;
    double _jerk_ptp;
    double _acceleration_ptp;
    double _max_velocity_cp;
    double _jerk_cp;
    double _acceleration_cp;
    double _home_velocity;
    double _goto_velocity;
    double _max_velocity_motor1;
    double _max_velocity_motor2;
    double _max_velocity_motor3;
    double _max_velocity_motor4;
    double _max_velocity_motor5;
    double _max_velocity_motor6;

    Controller *controller;
};

#endif // VELOCITYACCELERATIONVIEWMODEL_H
