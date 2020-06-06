#include "mainviewmodel.h"
#include <iostream>
#include "Model/Controller/controller.h"
#include "Model/ViewModel/rightviewmodel.h"
#include "Model/Controller/beckhoff.h";
#include "points.h"
#include <QThread>
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
    connect(controller->beckhoff, SIGNAL(StartedCurrentProject()),this, SLOT(startPrj()));
    connect(controller->beckhoff, SIGNAL(FinishedCurrentProject()),this, SLOT(endPrj()));
    //dataList = new QList<QObject*>();

}
QThread *th1;
ReadInfo *RI;
void MainViewModel::Initialize()
{
    int result =  controller->beckhoff->connectToServer();
    if(result == 1)
    {
        th1 = new QThread();
        RI = new ReadInfo();
        RI->moveToThread(th1);
        connect(this, SIGNAL(readInfoBegin()),RI, SLOT(readDataFromController()));
        th1->start(QThread::LowestPriority);
 //       controller->beckhoff->ActualPositionNotify();
 //       controller->beckhoff->InputIoMonitoringNotify();
//        controller->beckhoff->OutputIoMonitoringNotify();
//        controller->beckhoff->StatusWordNotify();
//        controller->beckhoff->MovementStopNotify();
        controller->setAllowAlarmDetection(true);
        controller->beckhoff->setGUIManager(99);
        while(controller->beckhoff->getGUIManager()!=100);
        QThread::msleep(500);
        setIsPowerOn(Controller::getInstance()->beckhoff->getIoOutput(7));
        controller->beckhoff->setFeedOverRide(1.0);
        controller->beckhoff->setConfJ(false);
        controller->beckhoff->setSingulPTP(true);
        controller->beckhoff->setSingulCP(true);
        //ReadInfoTh.join();
        Q_EMIT readInfoBegin();
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
    if(controller->GeneralRobotStatus()!="RUN")
        controller->beckhoff->setGUIManager(2); // Robot Run
    else {
        controller->beckhoff->setGUIManager(4); // Robot Ready
    }
}

void MainViewModel::PowerOnClicked()
{
    bool tmp = Controller::getInstance()->beckhoff->getIoOutput(7);
    setIsPowerOn(!tmp);
    controller->beckhoff->setIoOutput(!tmp,7);
}

void MainViewModel::HomePositionClicked()
{
    for (int i=0; i<controller->beckhoff->NumberOfRobotMotors; i++)
    {
        controller->beckhoff->setTargetPosition(controller->homePosition[i],i);
        controller->beckhoff->tempJointTargetPoints[i] = QString::number(0);//controller->homePosition[i]);
        controller->beckhoff->tempCartTargetPoints[i] = QString::number(0);//controller->homePosition[i]);
    }
    controller->beckhoff->setTargetPosition(controller->HomeVelocity,6);
    controller->beckhoff->setTargetPosition(0,7);
    controller->beckhoff->setTargetPosition(1,8);
    controller->beckhoff->setGUIManager(8);
    //********************************
    // Disable Left menu
//    controller->beckhoff->StartedCurrentProject();
//    //********************************
//    int next;
//    do{
////        QThread::msleep(100);
//        next = controller->beckhoff->getGUIManager();
//    }while(next!=20);
//    QThread::msleep(3000);
    //********************************
    // Enable Left menu
//    controller->beckhoff->FinishedCurrentProject();
    //********************************
}

void MainViewModel::startPrj()
{
    Q_EMIT startedPrj();
}

void MainViewModel::endPrj()
{
    Q_EMIT endedPrj();
}

void MainViewModel::RunTh()
{
//    while (true) {
//         controller->beckhoff->ReadInfoFromRobot();
//         std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    }
}


