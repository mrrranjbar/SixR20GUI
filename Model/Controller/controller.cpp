#include "controller.h"
#include "beckhoff.h"

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


//int main()
//{
//    //new Singleton(); // Won't work
//    Singleton* s = Singleton::getInstance(); // Ok
//    Singleton* r = Singleton::getInstance();

//}
