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
    //dataList = new QList<QObject*>();

}

void MainViewModel::Initialize()
{
    //    //dataList = new QList<QObject*>();
//          dataList->append(new points("MMr"));
//          dataList->append(new points("Mbb"));
    // controller setting e.g. controlword = 6
//    controller->beckhoff->setControlWord(6);
//    controller->beckhoff->setControlWord(7);
//    controller->beckhoff->setControlWord(15);
//   int result =  controller->beckhoff->connectToServer();
 //  int error =0;
   //uint16_t* ctrl = new uint16_t[6];
//   if(result == 1)
//   {
//       uint16_t h[6] = {128,128,128,128,128,128};
//       controller->beckhoff->setControlWord(h);

//       uint16_t h1[6] = {15,15,15,15,15,15};
//       controller->beckhoff->setControlWord(h1);

//       controller->beckhoff->StatusWordNotify();
//       controller->beckhoff->setGUIManager(4);
//       controller->beckhoff->setTargetPosition(40,0);
//       controller->beckhoff->setTargetPosition(40,1);
//       controller->beckhoff->setTargetPosition(20,6);
          //   }
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
    emit CountChanged();
}


