#include "rightviewmodel.h"

RightViewModel::RightViewModel(QObject *parent) : QObject(parent)
{
    controller = Controller::getInstance();
    _statusWord = new QList<int>();
}

QList<int> RightViewModel::StatusWord()
{
    return *_statusWord;
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
    setStatusWord(*tmp);
}
