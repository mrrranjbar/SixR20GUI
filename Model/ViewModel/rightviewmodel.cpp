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
    Q_EMIT StatusWordChanged();
}

void RightViewModel::UpdateStatusWord()
{
    QList<int> *tmp = new QList<int>();
    for (int i=0; i<controller->beckhoff->NumberOfRobotMotors; ++i) {
        tmp->append(Controller::getInstance()->beckhoff->StatusWord[i]);
    }
    setStatusWord(*tmp);
}

void RightViewModel::setActualPosition(QList<double> value)
{
    _actualPosition = &value;
    Q_EMIT ActualPositionChanged();
}

void RightViewModel::UpdateActualPosition()
{
    QList<double> *tmp = new QList<double>();
    for (int i=0; i<controller->beckhoff->NumberOfRobotMotors; ++i) {
        tmp->append((double)(controller->beckhoff->ActualPositions[i]*controller->robot->PulsToDegFactor1[i]));
    }
    setActualPosition(*tmp);
}
