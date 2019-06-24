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
    createBtn();
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
    emit tempNameChanged();
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
                p->setPoints(_tempPoints) ;
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
    QList<double> points = p->getPoints();
    for (int i=0; i<controller->beckhoff->NumberOfRobotMotors; i++) {
        controller->beckhoff->setTargetPosition(points.at(i),i);
    }
    controller->beckhoff->setTargetPosition(50,6);
    controller->beckhoff->setTargetPosition(0,7);
    controller->beckhoff->setGUIManager(8);
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
        palsToDegreeRepo[i] = points[i] * PulsToDegFactor1[i];
        degreeToRadian[i] = degreesToRadians(palsToDegreeRepo[i]);
    };

    GetCartPos(degreeToRadian,toolParam,currentPos);
    toEulerianAngle(currentPos,rpy);

    RadianCartesian[0] = currentPos[5] + 100;
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

QString teachpointviewmodel::savedAndUpdatedString(int index)
{
    points *p = dynamic_cast<points*>(controller->dataList.at(index));
    if(p->getDuplicated())
        return " ( Duplicated ) ";
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

void teachpointviewmodel::GetCartPos(double theta[], double ToolParams[], double out[])
{
    double temp[] = { theta[0] , theta[1], theta[2],theta[3],theta[4],theta[5],theta[6] };
    double Q1[] = { (double)(cos((double)theta[0] / 2.0)), 0, 0,(double)(sin((double)theta[0] / 2.0)), 0, 0, 0, L[0] };
    double Q2[] = { (double)(cos((double)theta[1] / 2.0)), 0,  (double)(sin((double)theta[1] / 2.0)), 0, 0, 0, 0, 0 };
    double Q3[] = { (double)(cos((double)theta[2] / 2.0)), 0, (double)(sin((double)theta[2] / 2.0)), 0, 0, 0, 0, L[2] };
    double Q4[] = { (double)(cos((double)theta[3] / 2.0)), (double)(sin((double)theta[3] / 2.0)), 0, 0, 0, L[4], 0, L[3] };
    double Q5[] = { (double)(cos((double)theta[4] / 2.0)), 0, (double)(sin((double)theta[4] / 2.0)), 0, 0, 0, 0, 0 };
    double Q6[] = { (double)(cos((double)theta[5] / 2.0)), (double)(sin((double)theta[5] / 2.0)), 0, 0, 0, 0, 0, 0 };


    double M7[8];
    DQmultiply(QEndEffector, ToolParams, M7);
    double M6[8];
    DQmultiply(Q6, M7, M6);
    double M5[8];
    DQmultiply(Q5, M6, M5);
    double M4[8];
    DQmultiply(Q4, M5, M4);
    double M3[8];
    DQmultiply(Q3, M4, M3);
    double M2[8];
    DQmultiply(Q2, M3, M2);
    DQmultiply(Q1, M2, out);
}

void teachpointviewmodel::DQmultiply(double Q1[], double Q2[], double out[])
{
    out[0] = Q1[0] * Q2[0] - Q1[1] * Q2[1] - Q1[2] * Q2[2] - Q1[3] * Q2[3];
    out[1] = Q1[0] * Q2[1] + Q1[1] * Q2[0] + Q1[2] * Q2[3] - Q1[3] * Q2[2];
    out[2] = Q1[0] * Q2[2] + Q1[2] * Q2[0] - Q1[1] * Q2[3] + Q1[3] * Q2[1];
    out[3] = Q1[0] * Q2[3] + Q1[1] * Q2[2] - Q1[2] * Q2[1] + Q1[3] * Q2[0];
    out[4] = 0;
    out[5] = Q1[5] + Q2[5] + Q1[2] * (Q1[1] * Q2[6] - Q1[2] * Q2[5]) * 2 + Q1[0] * (Q1[2] * Q2[7] - Q1[3] * Q2[6]) * 2 + Q1[3] * (Q1[1] * Q2[7] - Q1[3] * Q2[5]) * 2;
    out[6] = Q1[6] + Q2[6] - Q1[1] * (Q1[1] * Q2[6] - Q1[2] * Q2[5]) * 2 - Q1[0] * (Q1[1] * Q2[7] - Q1[3] * Q2[5]) * 2 + Q1[3] * (Q1[2] * Q2[7] - Q1[3] * Q2[6]) * 2;
    out[7] = Q1[7] + Q2[7] + Q1[0] * (Q1[1] * Q2[6] - Q1[2] * Q2[5]) * 2 - Q1[1] * (Q1[1] * Q2[7] - Q1[3] * Q2[5]) * 2 - Q1[2] * (Q1[2] * Q2[7] - Q1[3] * Q2[6]) * 2;

    //return Q;

}

void teachpointviewmodel::toEulerianAngle(double quar[], double output[])
{
    double quar0 = quar[0];
    double quar1 = quar[1];
    double quar2 = quar[2];
    double quar3 = quar[3];
    //quar = quar.Normalize(2).ToArray();
    //double output[3];// = new decimal[3];
    double ysqr = quar2 * quar2;

    // roll (x-axis rotation)
    double t0 = +2.0 * (quar0 * quar1 + quar2 * quar3);
    double t1 = +1.0 - 2.0 * (quar1 * quar1 + ysqr);
    output[0] = (atan2(t0, t1) * 180) / (double)(M_PI);

    // pitch (y-axis rotation)
    double t2 = +2.0 * (quar0 * quar2 - quar3 * quar1);
    t2 = t2 > 1.0 ? 1.0 : t2;
    t2 = t2 < -1.0 ? -1.0 : t2;
    output[1] = (double)((asin((double)t2) * 180) / M_PI);

    // yaw (z-axis rotation)
    double t3 = +2.0 * (quar0 * quar3 + quar1 * quar2);
    double t4 = +1.0 - 2.0 * (ysqr + quar3 * quar3);
    output[2] = (atan2(t3, t4) * 180) / (double)(M_PI);

    //return output;
}

