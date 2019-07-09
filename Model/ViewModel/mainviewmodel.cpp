#include "mainviewmodel.h"
#include <iostream>
#include "Model/Controller/controller.h"
#include "Model/ViewModel/interpreterviewmodel.h"

MainViewModel::MainViewModel(QObject *parent) : QObject(parent)
{
    _count = 1;
    controller = Controller::getInstance();


}

void MainViewModel::Initialize()
{
    // controller setting e.g. controlword = 6
//    controller->beckhoff->setControlWord(6);
//    controller->beckhoff->setControlWord(7);
//    controller->beckhoff->setControlWord(15);
   int result =  controller->beckhoff->connectToServer();
 //  int error =0;
   //uint16_t* ctrl = new uint16_t[6];
   if(result == 1)
   {
//       uint16_t h[6] = {128,128,128,128,128,128};
//       controller->beckhoff->setControlWord(h);

//       uint16_t h1[6] = {15,15,15,15,15,15};
//       controller->beckhoff->setControlWord(h1);

//       controller->beckhoff->StatusWordNotify();
       //controller->beckhoff->setGUIManager(99);

       //controller->beckhoff->setGUIManager(2);
   //}

       /*controller->beckhoff->setGUIManager(99);
       while(controller->beckhoff->getGUIManager()!=100);
<<<<<<< HEAD
       controller->beckhoff->setGUIManager(2);*/
   //}
       controller->beckhoff->setGUIManager(2);
       controller->beckhoff->InputIoMonitoringNotify();


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
    emit CountChanged();
}


