#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include "teachpointviewmodel.h"
#include <string>
#include <algorithm>

#include <QDebug>
#include <QStringList>
#include <qdom.h>
#include <qfileinfo.h>
#include <qqmlapplicationengine.h>
#include <qxmlstream.h>
teachpointviewmodel::teachpointviewmodel(QObject *parent)
    : QObject(parent)
{
    controller = Controller::getInstance();
}

QString teachpointviewmodel::generateNewPointNumber()
{

    if(controller->dataList.length() == 1)
        return "1";

    points *p = dynamic_cast<points*>(controller->dataList.at(1));
    return QString::number(p->myIndexInList+1);
}

//double* teachpointviewmodel::getActualPositions()
//{
//    return controller->beckhoff->actualPositions;
//}

QString teachpointviewmodel::getTempName()
{
    return _tempName;
}

void teachpointviewmodel::setTempName(QString str)
{
    _tempName = str;
    Q_EMIT tempNameChanged();
}

QList<double> teachpointviewmodel::getTempPoints()
{
    return _tempPoints;
}

void teachpointviewmodel::setTempPoints(QList<double> tempPoints)
{
    _tempPoints = tempPoints;
}

void teachpointviewmodel::editList(int index,QString name)
{
    //    controller->dataList[index];
    points *p = dynamic_cast<points*>(controller->dataList.at(index));
    qDebug() << name << endl;
    p->setName(name);
}

void teachpointviewmodel::saveBtn(int listIndex, bool fromDeleteBtn)
{

    QFile file("pointsList.xml");
    QXmlStreamWriter xmlWriter(&file);

    if(file.exists())
    {
        file.remove();
    }
    file.open(QIODevice::WriteOnly);
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("Points");

    for (int i = 0;i < controller->dataList.length();i++) {
        points *p = dynamic_cast<points*>(controller->dataList.at(i));
        if(fromDeleteBtn == false){

            if(listIndex == i)
            {
                QList<double> result=calc_mainpoints();
                p->setPoints(result);
                //p->setPoints(_tempPoints);
            }
        }
        if(fromDeleteBtn == true){
            if(p->getSaved() == false)
                continue;
        }
        if(!p->getSaved()){
            QString lowerCasePointName = p->getName().toLower().trimmed();

            for (int j=controller->dataList.length()-1; j >=0; j--) {
                if(i == j)
                    continue;

                points *ip = dynamic_cast<points*>(controller->dataList.at(j));;
                QString itratedString = ip->getName().toLower().trimmed();
                if(lowerCasePointName == itratedString){
                    p->setDuplicated(true);
                    continue;
                }
            }
        }
        if(p->getDuplicated())
            continue;

        p->setSaved(true);

        xmlWriter.writeStartElement("point");
        xmlWriter.writeTextElement("name",p->getName());
        xmlWriter.writeTextElement("type",p->getType());

        xmlWriter.writeStartElement("values");
        QList <double> points = p->getPoints();
        xmlWriter.writeTextElement("X",QString::number(points[0]));
        xmlWriter.writeTextElement("Y",QString::number(points[1]));
        xmlWriter.writeTextElement("Z",QString::number(points[2]));
        xmlWriter.writeTextElement("A",QString::number(points[3]));
        xmlWriter.writeTextElement("B",QString::number(points[4]));
        xmlWriter.writeTextElement("C",QString::number(points[5]));
        xmlWriter.writeEndElement();
        xmlWriter.writeTextElement("stringFrameType",p->getStringFrameType());
        xmlWriter.writeTextElement("stringFrameName",p->getStringFrameName());
        xmlWriter.writeTextElement("myIndexInList",QString::number(p->myIndexInList));
        xmlWriter.writeEndElement();

    }
    // end of Points tag
    xmlWriter.writeEndElement();

    file.close();
    controller->ctxt->setContextProperty("TeachPointModel", QVariant::fromValue(controller->dataList));
}

void teachpointviewmodel::createBtn()
{
    QList<double> actualPosition;// =  controller->beckhoff->ActualPositions;
    for(int i=0; i< controller->beckhoff->NumberOfRobotMotors; i++)
    {
        actualPosition.append((double)controller->beckhoff->ActualPositions[i]*controller->robot->PulsToDegFactor1[i]);
    }
    controller->dataList.push_front(new points(false,actualPosition));
    QString newPointNumber = generateNewPointNumber();
    points *p = dynamic_cast<points*>(controller->dataList.at(0));
    p->setName(newPointName+newPointNumber);
    p->setType("cartesian");
    p->myIndexInList = newPointNumber.toInt();
    p->setCreated(true);
    p->setSaved(false);
    p->setUpdated(false);
    controller->ctxt->setContextProperty("TeachPointModel", QVariant::fromValue(controller->dataList));
    this->setTempName(p->getName());
}

void teachpointviewmodel::deleteBtn(int index)
{
    controller->dataList.removeAt(index);
    controller->ctxt->setContextProperty("TeachPointModel", QVariant::fromValue(controller->dataList));
    this->saveBtn(index,true);
}

void teachpointviewmodel::updateBtn(int index)
{
    points *p = dynamic_cast<points*>(controller->dataList.at(index));
    p->setName(_tempName);
    //    QList <double> inputArray;
    //    for (int i =0;i < _tempPoints.length();i++) {
    //        inputArray[i] = _tempPoints[i].toDouble();
    //    }
    p->setPoints(_tempPoints);
    p->setSaved(false);
    p->setUpdated(true);
    controller->ctxt->setContextProperty("TeachPointModel", QVariant::fromValue(controller->dataList));
}

void teachpointviewmodel::goToBtn(int index)
{

    points *p = dynamic_cast<points*>(controller->dataList.at(index));
    QList<double> _positions = p->getPoints();

    //*****************************************
    // joint
//    if(jointCartStat){
//        double TargetPoint[6] = {_positions.at(0),
//                                 _positions.at(1),
//                                 _positions.at(2),
//                                 _positions.at(3),
//                                 _positions.at(4),
//                                 _positions.at(5)};
//        for (int i=0; i< controller->beckhoff->NumberOfRobotMotors; ++i) {
//            controller->beckhoff->setTargetPosition(TargetPoint[i],i);
//        }
//        controller->beckhoff->setTargetPosition(20,6);
//        controller->beckhoff->setTargetPosition(0,7);
//        controller->beckhoff->setGUIManager(8);
//    }
    //*****************************************
    // cartesian
//    else{

        QList<double> tmpValue = controller->robot->currentObjectFrame->mainPoints();


        double SelectedFrame[6] = {tmpValue.at(0),tmpValue.at(1),tmpValue.at(2),
                                   tmpValue.at(3),tmpValue.at(4),tmpValue.at(5)};
        double TargetPoint[6] = {_positions.at(0),
                                 _positions.at(1),
                                 _positions.at(2),
                                 _positions.at(3),
                                 _positions.at(4),
                                 _positions.at(5)};
        double OutPointInRef[6];
        controller->robot->PointInReference(TargetPoint,SelectedFrame,"object",OutPointInRef);
        for (int i=0; i< controller->beckhoff->NumberOfRobotMotors; ++i) {
            controller->beckhoff->setTargetPosition(OutPointInRef[i],i);
        }
        controller->beckhoff->setTargetPosition(20,6);
        controller->beckhoff->setTargetPosition(0,7);
        controller->beckhoff->setGUIManager(10);
    //}


    //***************************************************************
    //***************************************************************
    // pervious code


//    points *p = dynamic_cast<points*>(controller->dataList.at(index));
//    QList<double> points = p->getPoints();
//    for (int i=0; i<controller->beckhoff->NumberOfRobotMotors; i++) {
//        controller->beckhoff->setTargetPosition(points.at(i),i);
//    }
//    controller->beckhoff->setTargetPosition(50,6);
//    controller->beckhoff->setTargetPosition(0,7);
//    controller->beckhoff->setGUIManager(8);
}

void teachpointviewmodel::getSelectedCombo(int listIndex,QString itemName)
{
    qDebug() << "itemName:" << itemName;
    points *p = dynamic_cast<points*>(controller->dataList.at(listIndex));
    p->setStringFrameName(controller->robot->jogTempFrame->name());
    p->setStringFrameType(itemName);
    p->setSaved(false);
    p->setUpdated(true);
    controller->ctxt->setContextProperty("TeachPointModel", QVariant::fromValue(controller->dataList));
}

QString teachpointviewmodel::getPointName(int index)
{
    points *p = dynamic_cast<points*>(controller->dataList.at(index));
    return p->getName();
}

void teachpointviewmodel::cartesianRadioBtnClicked(int index)
{

    points *p = dynamic_cast<points*>(controller->dataList.at(index));
    if(p->getType() == "cartesian")
        return;

    double palsToDegreeRepo[6];
    double degreeToRadian[6];
    double currentPos[8];
    double rpy[3];
    double RadianCartesian[6];
    QList <double> degreeCartesian;

    QList<double> points = p->getPoints();

    for (int i=0;i<6;i++) {
        palsToDegreeRepo[i] = points[i] * controller->robot->PulsToDegFactor1[i];
        degreeToRadian[i] = degreesToRadians(palsToDegreeRepo[i]);
    };

    QList<double> tmpTool = controller->robot->currentToolFrame->mainPoints();
    double q[4];
    //controller->robot->toQuaternion(tmpTool.at(3),tmpTool.at(4),tmpTool.at(5),q);mrr
    double toolParam[8] = {q[0],q[1],q[2],q[3],0,tmpTool[0],tmpTool[1],tmpTool[2]};
    //controller->robot->GetCartPos(degreeToRadian,toolParam,currentPos);mrr
    //controller->robot->toEulerianAngle(currentPos,rpy);mrr

    RadianCartesian[0] = currentPos[5];
    RadianCartesian[1] = currentPos[6];
    RadianCartesian[2] = currentPos[7];
    RadianCartesian[3] = rpy[0];
    RadianCartesian[4] = rpy[1];
    RadianCartesian[5] = rpy[2];

    for (int i=0;i<6;i++) {
        degreeCartesian << radiansToDegrees(RadianCartesian[i]);
    };
    p->setPoints(degreeCartesian);
    this->setTempPoints(degreeCartesian);
    p->setType("cartesian");
    p->setSaved(false);
    p->setUpdated(true);
    controller->ctxt->setContextProperty("TeachPointModel", QVariant::fromValue(controller->dataList));
}

void teachpointviewmodel::jointRadioBtnClicked(int index)
{

}

QString teachpointviewmodel::savedAndUpdatedString(int index)
{
    points *p = dynamic_cast<points*>(controller->dataList.at(index));
    if(p->getDuplicated())
        return " ( Duplicated, Can Not Save! ) ";
    if(p->getUpdated() && !p->getSaved())
        return " ( Updated ) ";
    if(p->getSaved())
        return " ( Saved ) ";
    if(!p->getUpdated() && !p->getSaved())
        return " ( Unsaved ) ";
    if(p->getCreated())
        return " ( Created ) ";
}

void teachpointviewmodel::setPointCoordinate(int index)
{
    points *p = dynamic_cast<points*>(controller->dataList.at(index));
    p->setPoints(_tempPoints);
    p->setUpdated(true);
    //return index;
}

QList<double> teachpointviewmodel::calc_mainpoints()
{
    double p1[6];
    for(int i=0; i< controller->beckhoff->NumberOfRobotMotors; i++)
    {
        p1[i]=(double)controller->beckhoff->ActualPositions[i]*controller->robot->PulsToDegFactor1[i]*M_PI/180.0;

    }

    double tmptool[6] = {controller->robot->currentToolFrame->mainPoints().at(0),
                         controller->robot->currentToolFrame->mainPoints().at(1),
                         controller->robot->currentToolFrame->mainPoints().at(2),
                         controller->robot->currentToolFrame->mainPoints().at(3),
                         controller->robot->currentToolFrame->mainPoints().at(4),
                         controller->robot->currentToolFrame->mainPoints().at(5)};
    double tmpCurrentFrame[8];
    controller->robot->CartesianToDQ(tmptool,tmpCurrentFrame);

    //******************************************************************

    double currentCartesian[8];

    controller->robot->GetCartPos(p1,tmpCurrentFrame,currentCartesian);

    double tmpworld[6] = {controller->robot->currentWorldFrame->mainPoints().at(0),
                         controller->robot->currentWorldFrame->mainPoints().at(1),
                         controller->robot->currentWorldFrame->mainPoints().at(2),
                         controller->robot->currentWorldFrame->mainPoints().at(3),
                         controller->robot->currentWorldFrame->mainPoints().at(4),
                         controller->robot->currentWorldFrame->mainPoints().at(5)};
    double tmpDQWorldFrame[8];
    controller->robot->CartesianToDQ(tmpworld,tmpDQWorldFrame);

    //******************************************************************

    double DQPointInWorld[8];

    controller->robot->DQmultiply(tmpDQWorldFrame,currentCartesian,DQPointInWorld);

    //******************************************************************


    double tmpTask[6] = {controller->robot->currentTaskFrame->mainPoints().at(0),
                         controller->robot->currentTaskFrame->mainPoints().at(1),
                         controller->robot->currentTaskFrame->mainPoints().at(2),
                         controller->robot->currentTaskFrame->mainPoints().at(3),
                         controller->robot->currentTaskFrame->mainPoints().at(4),
                         controller->robot->currentTaskFrame->mainPoints().at(5)};
    double tmpDQTaskFrame[8];
    controller->robot->CartesianToDQ(tmpTask,tmpDQTaskFrame);

    //******************************************************************

    double tmpObject[6] = {controller->robot->currentObjectFrame->mainPoints().at(0),
                         controller->robot->currentObjectFrame->mainPoints().at(1),
                         controller->robot->currentObjectFrame->mainPoints().at(2),
                         controller->robot->currentObjectFrame->mainPoints().at(3),
                         controller->robot->currentObjectFrame->mainPoints().at(4),
                         controller->robot->currentObjectFrame->mainPoints().at(5)};
    double tmpDQObjectFrame[8];
    controller->robot->CartesianToDQ(tmpObject,tmpDQObjectFrame);

    //******************************************************************

    double InvDQTask[8],InvDQObject[8];

    controller->robot->DQinv(tmpDQTaskFrame,InvDQTask);

    controller->robot->DQinv(tmpDQObjectFrame,InvDQObject);

    double DQTemp[8],DQPointInObject[8],CartPointInObject[6];

    controller->robot->DQmultiply(InvDQTask,DQPointInWorld,DQTemp);

    controller->robot->DQmultiply(InvDQObject,DQTemp,DQPointInObject);

    controller->robot->DQToCartesian(DQPointInObject,CartPointInObject);

    QList<double> result = {CartPointInObject[0],CartPointInObject[1],CartPointInObject[2],
                           CartPointInObject[3],CartPointInObject[4],CartPointInObject[5]};

    return result;
}
