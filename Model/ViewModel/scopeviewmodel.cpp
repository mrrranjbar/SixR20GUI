#include "scopeviewmodel.h"
scopeviewmodel::scopeviewmodel(QObject *parent) : QObject(parent)
{

//    controller->InitializePoints();
    controller = Controller::getInstance();

}

void scopeviewmodel::run(QString mode, int teachpoint)
{
    TrajectoryPointList<double>* out;
    out = new TrajectoryPointList<double>[6];
    double actualPos[6],targetPos[8];
//    for (int i = 0; i < 10001; ++i)
//    {
//        out->AddPoint(5*sin(5*3.1415926535898*i/100),0,0);              // x goes from -1 to 1
////        y[i] = ;               // let's plot a quadratic function
//    }
    for (int i = 0; i < 6; i++) {
//        actualPos[i] = (static_cast<double>( controller->beckhoff->ActualPositions[5])) *controller->robot->PulsToDegFactor1[5];
        actualPos[i] = 0;
        points *pt= dynamic_cast<points*>(controller->dataList.at(teachpoint));
        targetPos[i] = pt->getPoints().at(i);
     }
    targetPos[6] = 50;
    targetPos[7] = 0;
    if(mode == "Circle"){

    }else if(mode == "Line"){
        for (int i = 0; i < 6; i++) {
                        actualPos[i] = (actualPos[i] * M_PI) / 180.0; //to radian
                    }
        controller->robot->LIN(actualPos,targetPos,out);
    }else if(mode == "PTP Cartesian"){
        controller->robot->PTPCartesian(actualPos,targetPos,out);
    }else if (mode == "PTP Joint") {
        controller->robot->PTPList(actualPos, targetPos, out);
    }
    QCustomPlot::Desired = out;
//    plot->setMotorNum(_motorNum);
}
int scopeviewmodel::motorNum()
{
    return _motorNum;
}

void scopeviewmodel::setMotorNum(int motorNum)
{
    _motorNum = motorNum;
}

