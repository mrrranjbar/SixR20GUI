#include "rightviewmodel.h"

RightViewModel::RightViewModel(QObject *parent) : QObject(parent)
{
    controller = Controller::getInstance();
    _statusWord = new QList<QString>();
    _actualPosition = new QList<double>();
    _feedOverRide = 1.0;
}

QList<QString> RightViewModel::StatusWord()
{
    return *_statusWord;
}

QString RightViewModel::StatusWordStr()
{
    return _statusWordStr;
}

QList<double> RightViewModel::ActualPosition()
{
    return *_actualPosition;
}
void RightViewModel::setFeedOverRide(double val)
{
    controller->beckhoff->setFeedOverRide(val);
    _feedOverRide = val;
    Q_EMIT FeedOverRideChanged();
}
double RightViewModel::FeedOverRide()
{
    return  _feedOverRide;
}

void RightViewModel::setStatusWord(QList<QString> value)
{
    _statusWord = &value;
    Q_EMIT StatusWordChanged();
}

void RightViewModel::UpdateStatusWord()
{
    QList<QString> *tmp = new QList<QString>();
    for (int i=0; i<controller->beckhoff->NumberOfRobotMotors; ++i) {
        uint16_t st = Controller::getInstance()->beckhoff->StatusWord[i];
        if((st & 79) == 0)
        {
            tmp->append("NOT READY TO SWITCH ON");
        }
        else if((st & 79) == 64)
        {
            tmp->append("SWITCH ON DISABLE");
        }
        else if((st & 111) == 33)
        {
            tmp->append("READY TO SWITCH ON");
        }
        else if((st & 111) == 35)
        {
            tmp->append("SWITCHED ON");
        }
        else if((st & 111) == 39)
        {
            tmp->append("OPERATION ENABLE");
        }
        else if((st & 111) == 7)
        {
            tmp->append("QUICK STOP ACTIVE");
        }
        else if((st & 79) == 15)
        {
            tmp->append("FAULT REACTION ACTIVE");
        }
        else if((st & 79) == 8)
        {
            tmp->append("FAULT");
            if(controller->AllowAlarmDetection())
            {
                controller->AlarmDetection();
                emit controller->beckhoff->AlarmDetected();
                controller->setAllowAlarmDetection(false);
            }
        }
        else if((st & 16) == 16)
        {
            tmp->append("MAIN POWER ON");
        }
        else if((st & 128) == 128)
        {
            tmp->append("WARNNING IS OCCURRED");
        }
        else {
            tmp->append("UNKNOWN");
        }
    }

    // for General Robot's status
    QString GeneralStatus;
    if(tmp->at(0) == "FAULT"
            || tmp->at(1) == "FAULT"
            || tmp->at(2) == "FAULT"
            || tmp->at(3) == "FAULT"
            || tmp->at(4) == "FAULT"
            || tmp->at(5) == "FAULT")
    {
        GeneralStatus = "ALARM";
    }
    else if(!controller->beckhoff->getIoOutput(7)){
        GeneralStatus = "NOT READY";
    }
    else if(tmp->at(0) == "SWITCHED ON"
            && tmp->at(1) == "SWITCHED ON"
            && tmp->at(2) == "SWITCHED ON"
            && tmp->at(3) == "SWITCHED ON"
            && tmp->at(4) == "SWITCHED ON"
            && tmp->at(5) == "SWITCHED ON")
    {
        GeneralStatus = "READY";
        controller->setAllowAlarmDetection(true);
    }
    else if(tmp->at(0) == "READY TO SWITCH ON"
            && tmp->at(1) == "READY TO SWITCH ON"
            && tmp->at(2) == "READY TO SWITCH ON"
            && tmp->at(3) == "READY TO SWITCH ON"
            && tmp->at(4) == "READY TO SWITCH ON"
            && tmp->at(5) == "READY TO SWITCH ON")
    {
        GeneralStatus = "READY";
        controller->setAllowAlarmDetection(true);
    }
    else if(tmp->at(0) == "OPERATION ENABLE"
            && tmp->at(1) == "OPERATION ENABLE"
            && tmp->at(2) == "OPERATION ENABLE"
            && tmp->at(3) == "OPERATION ENABLE"
            && tmp->at(4) == "OPERATION ENABLE"
            && tmp->at(5) == "OPERATION ENABLE")
    {
        GeneralStatus = "RUN";
        controller->setAllowAlarmDetection(true);
    }
    else {
        GeneralStatus = "UNKNOWN";
        controller->setAllowAlarmDetection(true);
    }
    setStatusWordStr(GeneralStatus);
    controller->SetGeneralRobotStatus(GeneralStatus);
    setStatusWord(*tmp);
    emit controller->beckhoff->AlarmDetected();
    if(Controller::getInstance()->beckhoff->MovementStop == 1)
    {
        emit Controller::getInstance()->beckhoff->MovementStopDetected();
    }
}

void RightViewModel::setActualPosition(QList<double> value)
{
    _actualPosition = &value;
    Q_EMIT ActualPositionChanged();
}

void RightViewModel::setStatusWordStr(QString value)
{
    _statusWordStr = value;
    emit StatusWordStrChanged();
}

void RightViewModel::UpdateActualPosition(bool _joint, int cmb_frame_currentIndex)
{
    if(_joint) // Joint
    {
        QList<double> *tmp = new QList<double>();
        for (int i=0; i<controller->beckhoff->NumberOfRobotMotors; ++i) {
            tmp->append((double)(controller->beckhoff->ActualPositions[i]*controller->robot->PulsToDegFactor1[i]));
        }
        setActualPosition(*tmp);
    }
    else { // Cartesian

    }
}
