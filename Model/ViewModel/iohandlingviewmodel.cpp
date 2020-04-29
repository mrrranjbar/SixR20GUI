#include "iohandlingviewmodel.h"
iohandlingviewmodel::iohandlingviewmodel(QObject *parent) : QObject(parent)
{

    controller = Controller::getInstance();
    _ioOutput = new QList<bool>();
    /*for(int i=0;i<controller->beckhoff->NumberOfInputOutput;i++)
        _ioOutput->append(false);*/
    updateIO();
}

QList<bool> iohandlingviewmodel::IoOutput()
{
    return *_ioOutput;
}

void iohandlingviewmodel::setOutput(QList<bool> value)
{
    for(int i=0;i<value.size();i++)
        _ioOutput->append(value[i]);
    Q_EMIT IoChanged();
}

void iohandlingviewmodel::setOutputAtIndex(bool value, int index)
{
//    controller->beckhoff->setIoOutput(value,index);
}

void iohandlingviewmodel::updateIO()
{
    /*bool tmp = false;
    for (int i=0; i<controller->beckhoff->NumberOfInputOutput; i++) {
        tmp=Controller::getInstance()->beckhoff->getIoOutput(i);
        set_Output(tmp,i);
    }*/

    QList<bool> *tmp1 = new QList<bool>();
    for (int i=0; i<controller->beckhoff->NumberOfInputOutput; ++i) {
        tmp1->append(Controller::getInstance()->beckhoff->getIoOutput(i));
    }
    setOutput(*tmp1);

}
