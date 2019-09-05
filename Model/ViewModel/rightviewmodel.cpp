#include "rightviewmodel.h"

RightViewModel::RightViewModel(QObject *parent) : QObject(parent)
{
    controller = Controller::getInstance();
    _statusWord = new QList<int>();
    _actualPosition = new QList<double>();
}

QList<int> RightViewModel::StatusWord()
{
    return *_statusWord;
}

QList<double> RightViewModel::ActualPosition()
{
    return *_actualPosition;
}

void RightViewModel::setStatusWord(QList<int> value)
{
    _statusWord = &value;
    emit StatusWordChanged();
}

void RightViewModel::UpdateStatusWord()
{
    QList<int> *tmp = new QList<int>();
    for (int i=0; i<controller->beckhoff->NumberOfRobotMotors; ++i) {
        tmp->append(Controller::getInstance()->beckhoff->StatusWord[i]);
    }
    // check status word
    setStatusWord(*tmp);
    controller->AlarmDetection();
    emit controller->beckhoff->AlarmDetected();
}

void RightViewModel::setActualPosition(QList<double> value)
{
    _actualPosition = &value;
    emit ActualPositionChanged();
}

void RightViewModel::UpdateActualPosition()
{
    QList<double> *tmp = new QList<double>();
    for (int i=0; i<controller->beckhoff->NumberOfRobotMotors; ++i) {
        tmp->append((double)(controller->beckhoff->ActualPositions[i]*controller->robot->PulsToDegFactor1[i]));
    }
    setActualPosition(*tmp);
}
