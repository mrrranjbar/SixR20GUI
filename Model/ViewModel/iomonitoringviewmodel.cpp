#include "iomonitoringviewmodel.h"
iomonitoringviewmodel::iomonitoringviewmodel(QObject *parent) : QObject(parent)
{
      controller = Controller::getInstance();
      _ioInput = new QList<bool>();
      _ioOutput = new QList<bool>();
      updateIO();

}

//***********************************************************
// Get & Set Input
QList<bool> iomonitoringviewmodel::IoInput()
{
    return *_ioInput;
}

void iomonitoringviewmodel::setIoInput(QList<bool> value)
{
   // _ioInput = &value;
    for(int i=0;i<value.size();i++)
        _ioInput->append(value[i]);
    Q_EMIT IoInputChanged();
}
//***********************************************************
//***********************************************************


//***********************************************************
// Get & Set Output
QList<bool> iomonitoringviewmodel::IoOutput()
{
    return *_ioOutput;
}

void iomonitoringviewmodel::setOutput(QList<bool> value)
{
    for(int i=0;i<value.size();i++)
        _ioOutput->append(value[i]);
    Q_EMIT IoOutputChanged();
}
//***********************************************************
//***********************************************************

void iomonitoringviewmodel::updateIO()
{
    QList<bool> *tmp = new QList<bool>();
    for (int i=0; i<controller->beckhoff->NumberOfInputOutput; ++i) {
        tmp->append(Controller::getInstance()->beckhoff->_input_iomonitoring[i]);
    }
    setIoInput(*tmp);

    QList<bool> *tmp1 = new QList<bool>();
    for (int i=0; i<controller->beckhoff->NumberOfInputOutput; ++i) {
        tmp1->append(Controller::getInstance()->beckhoff->getIoOutput(i));
    }
    setOutput(*tmp1);
}


