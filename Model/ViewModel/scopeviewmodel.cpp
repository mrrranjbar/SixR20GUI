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
    points *pt= dynamic_cast<points*>(controller->dataList.at(teachpoint));
    for (int i = 0; i < 6; i++) {
        actualPos[i] = ((static_cast<double>( controller->beckhoff->ActualPositions[i])) *
                controller->robot->PulsToDegFactor1[i]) * M_PI / 180.0;
        targetPos[i] = pt->getPoints().at(i);
     }
    targetPos[6] = 30;
    targetPos[7] = 0;

//    if(mode == "PTP Joint")
//    {
//            for (int i=0; i< controller->beckhoff->NumberOfRobotMotors; ++i) {
//                    controller->beckhoff->setTargetPosition(targetPos[i],i);
//                }
//            controller->beckhoff->setTargetPosition(targetPos[6],6);  // FF
//            controller->beckhoff->setTargetPosition(targetPos[7],7);  // CON
//           controller->beckhoff->setGUIManager(8);
//    }
    if(mode == "PTP Cartesian" )
    {
            QList<double> tmpValue = controller->robot->currentObjectFrame->mainPoints();
            double SelectedFrame[6] = {tmpValue.at(0),tmpValue.at(1),tmpValue.at(2),
                                           tmpValue.at(3),tmpValue.at(4),tmpValue.at(5)};
            double TargetPoint[6] = {targetPos[0],
                                     targetPos[1],
                                     targetPos[2],
                                     targetPos[3],
                                     targetPos[4],
                                     targetPos[5]};
            double OutPointInRef[6];
            controller->robot->PointInReference(TargetPoint,SelectedFrame,"object",OutPointInRef);
            for (int i=0; i< controller->beckhoff->NumberOfRobotMotors; ++i) {
                    controller->beckhoff->setTargetPosition(OutPointInRef[i],i);
                    targetPos[i] = OutPointInRef[i];
                }
            controller->beckhoff->setTargetPosition(targetPos[6],6);  // FF
            controller->beckhoff->setTargetPosition(targetPos[7],7);  // CON
            controller->beckhoff->setGUIManager(10);
            controller->robot->PTPCartesian(actualPos,targetPos,out);
    }
    else if(mode == "Linear")
     {
        QList<double> tmpValue = controller->robot->currentObjectFrame->mainPoints();
        double SelectedFrame[6] = {tmpValue.at(0),tmpValue.at(1),tmpValue.at(2),
                                       tmpValue.at(3),tmpValue.at(4),tmpValue.at(5)};
        double TargetPoint[6] = {targetPos[0],
                                 targetPos[1],
                                 targetPos[2],
                                 targetPos[3],
                                 targetPos[4],
                                 targetPos[5]};
        double OutPointInRef[6];
        controller->robot->PointInReference(TargetPoint,SelectedFrame,"object",OutPointInRef);
        for (int i=0; i< controller->beckhoff->NumberOfRobotMotors; ++i) {
                controller->beckhoff->setTargetPosition(OutPointInRef[i],i);
                targetPos[i] = OutPointInRef[i];
            }
        controller->beckhoff->setTargetPosition(targetPos[6],6);  // FF
        controller->beckhoff->setTargetPosition(targetPos[7],7);  // CON
        controller->beckhoff->setGUIManager(16);
        controller->robot->LIN(actualPos,targetPos,out);
    }
    QCustomPlot::Desired = out;
//     if(mode == "Circle")
//     {
//        //p2
//        vector<double> _positions2 = parameters["p2"].getData();
//        //p3
//        vector<double> _positions3 = parameters["p3"].getData();

//        //Frame
//        QList<double> tmpValue = controller->robot->currentObjectFrame->mainPoints();
//        double SelectedFrame[6] = {tmpValue.at(0),tmpValue.at(1),tmpValue.at(2),
//                                       tmpValue.at(3),tmpValue.at(4),tmpValue.at(5)};

//        double TargetPoint2[6] = {_positions2.at(0),
//                                 _positions2.at(1),
//                                 _positions2.at(2),
//                                 _positions2.at(3),
//                                 _positions2.at(4),
//                                 _positions2.at(5)};
//        double TargetPoint3[6] = {_positions3.at(0),
//                                 _positions3.at(1),
//                                 _positions3.at(2),
//                                 0,
//                                 0,
//                                 0};
//        double OutPointInRef2[6];
//        double OutPointInRef3[6];
//        controller->robot->PointInReference(TargetPoint2,SelectedFrame,"object",OutPointInRef2);
//        controller->robot->PointInReference(TargetPoint3,SelectedFrame,"object",OutPointInRef3);

//        for (int i=0; i< controller->beckhoff->NumberOfRobotMotors; ++i) {
//                controller->beckhoff->setTargetPosition(OutPointInRef2[i],i);
//            }
//        controller->beckhoff->setTargetPosition(parameters["FF"].getDataAt(0),6);  // FF
//        controller->beckhoff->setTargetPosition(parameters["CON"].getDataAt(0),7);  // CON
//       controller->beckhoff->setGUIManager(21);
//       while(controller->beckhoff->getGUIManager() != 23)
//       {
//           QThread::msleep(20);
//       }
//       for (int i=0; i< controller->beckhoff->NumberOfRobotMotors - 3; ++i) {
//               controller->beckhoff->setTargetPosition(OutPointInRef3[i],i);
//           }
//       controller->beckhoff->setTargetPosition(parameters["Radius"].getDataAt(0) * (M_PI / 180.0),3);  // Radius
//      // controller->beckhoff->setTargetPosition(-1,3);  // Radius
//       controller->beckhoff->setGUIManager(22);
//       while(controller->beckhoff->getGUIManager() != 23)
//       {
//           QThread::msleep(20);
//       }
//       controller->beckhoff->setGUIManager(12);
//     }









//    if(mode == "Circle"){

//    }else if(mode == "Line"){
//        for (int i = 0; i < 6; i++) {
//                        actualPos[i] = (actualPos[i] * M_PI) / 180.0; //to radian
//                    }
//        controller->robot->LIN(actualPos,targetPos,out);
//    }else if(mode == "PTP Cartesian"){
//        controller->robot->PTPCartesian(actualPos,targetPos,out);
//    }else if (mode == "PTP Joint") {
//        controller->robot->PTPList(actualPos, targetPos, out);
//    }
//    QCustomPlot::Desired = out;


}
int scopeviewmodel::motorNum()
{
    return _motorNum;
}

void scopeviewmodel::setMotorNum(int motorNum)
{
    _motorNum = motorNum;
}

