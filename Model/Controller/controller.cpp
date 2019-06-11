#include "controller.h"
#include "beckhoff.h"
#include "../ViewModel/points.h"
#include <QList>

Controller::Controller()
{
    robot = new Robot();
    beckhoff = new Beckhoff();
}
Controller* Controller::instance = nullptr;

Controller* Controller::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Controller();
    }

    return instance;
}

void Controller::Initialize()
{
//     QList<double> exampleList = {1.20, 2.2 , 4, 5, 500,300.56};
//     QList<double> exampleList2 = {300, 4000 , 70, 85, 7000,600};

//     Controller::getInstance()->dataList.push_back(new points("Behrooz", true,exampleList));
//     Controller::getInstance()->dataList.push_back(new points("Hossein",false,exampleList2));
//     ctxt->setContextProperty("TeachPointModel", QVariant::fromValue( Controller::getInstance()->dataList));
}

//void Controller::editList(int index)
//{
//    points *p = dynamic_cast<points*>( Controller::getInstance()->dataList.at(index));
//    p->setName("vghugfhjgj");
//}
