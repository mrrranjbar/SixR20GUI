#include "mainviewmodel.h"
#include <iostream>
#include "Model/Controller/controller.h"
#include "Model/ViewModel/interpreterviewmodel.h"
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
        controller->beckhoff->setGUIManager(99);
        while(controller->beckhoff->getGUIManager()!=100);
        controller->beckhoff->setGUIManager(2);
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

void MainViewModel::setCount(int count)
{
    _count = count;
    Q_EMIT CountChanged();
}


