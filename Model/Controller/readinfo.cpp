#include "readinfo.h"

ReadInfo::ReadInfo(QObject *parent) : QObject(parent)
{
    controller = Controller::getInstance();
}

void ReadInfo::readDataFromController()
{
    while (true) {
         controller->beckhoff->ReadInfoFromRobot();
         std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
