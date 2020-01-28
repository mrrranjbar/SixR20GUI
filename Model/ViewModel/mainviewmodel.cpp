#include "mainviewmodel.h"
#include <iostream>
#include "Model/Controller/controller.h"
#include "Model/ViewModel/interpreterviewmodel.h"
#include "Model/ViewModel/rightviewmodel.h"
#include "points.h"
MainViewModel* MainViewModel::instance = nullptr;
MainViewModel *MainViewModel::getInstance()
{
    if (instance == nullptr)
    {
        instance = new MainViewModel();
    }

    return instance;
}

MainViewModel::MainViewModel(QObject *parent) : QObject(parent)
{
    _count = 1;
    controller = Controller::getInstance();
    Initialize();
    //dataList = new QList<QObject*>();

}

void MainViewModel::Initialize()
{

    int result =  controller->beckhoff->connectToServer();
    if(result == 1)
    {
        controller->beckhoff->ActualPositionNotify();
        controller->beckhoff->InputIoMonitoringNotify();
        controller->beckhoff->StatusWordNotify();
        controller->setAllowAlarmDetection(true);
        controller->beckhoff->setGUIManager(99);
        while(controller->beckhoff->getGUIManager()!=100);
        controller->beckhoff->setGUIManager(4);
        setIsPowerOn(Controller::getInstance()->beckhoff->getIoOutput(7));
    }

}


void MainViewModel::TestSlot()
{
    _count = 3;
    std::clog<<"test slot"<<std::endl;
}

int MainViewModel::Count()
{
    return _count;
}

bool MainViewModel::IsPowerOn()
{
    return _isPowerOn;
}

void MainViewModel::setIsPowerOn(bool value)
{
    _isPowerOn = value;
    Q_EMIT IsPowerOnChanged();
}

void MainViewModel::setCount(int count)
{
    _count = count;
    Q_EMIT CountChanged();
}

void MainViewModel::RunClicked()
{
    controller->beckhoff->setGUIManager(2);
}

void MainViewModel::PowerOnClicked()
{
    bool tmp = Controller::getInstance()->beckhoff->getIoOutput(7);
    setIsPowerOn(!tmp);
    controller->beckhoff->setIoOutput(!tmp,7);
}

void MainViewModel::HomePositionClicked()
{
    for (int i=0; i<controller->beckhoff->NumberOfRobotMotors; i++) {
        controller->beckhoff->setTargetPosition(0,i);
        controller->beckhoff->tempJointTargetPoints[i] = "0";
        controller->beckhoff->tempCartTargetPoints[i] = "0";
    }
    controller->beckhoff->setTargetPosition(30,6);
    controller->beckhoff->setTargetPosition(0,7);
    controller->beckhoff->setGUIManager(8);
}


