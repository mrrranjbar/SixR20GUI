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

QString teachpointviewmodel::getErrorMessage()
{
    return _errorMessage;
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

void teachpointviewmodel::saveBtn(bool isJoint)
{
    bool is_Duplicate=false;

    for (int i = 0;i < controller->dataList.length();i++) {
        points *p = dynamic_cast<points*>(controller->dataList.at(i));
        if(p->getName()==_tempName)
            is_Duplicate=true;
    }

    if(is_Duplicate)
    {
        _errorMessage="The Chosen Name Is Duplicate . Please Try Another Name";
        emit viewErrorPopup();
    }
    else
    {
        QList<double> actualPosition;
        for(int i=0; i< controller->beckhoff->NumberOfRobotMotors; i++)
        {
            actualPosition.append(controller->beckhoff->ActualPositions[i]*controller->robot->PulsToDegFactor1[i]);
        }
        controller->dataList.push_front(new points(false,actualPosition));
        QString newPointNumber = generateNewPointNumber();
        points *p = dynamic_cast<points*>(controller->dataList.at(0));
        p->setName(_tempName);

        if(isJoint) // joint point
        {
            p->setType("POINTJ");
        }
        else    // cartesian point
        {
            p->setType("POINTP");
            actualPosition=calc_mainpoints();
            p->setPoints(actualPosition);
        }

        p->myIndexInList = newPointNumber.toInt();

        controller->ctxt->setContextProperty("TeachPointModel", QVariant::fromValue(controller->dataList));

        writePointListFile();

    }


}

void teachpointviewmodel::deleteBtn(int index)
{
    controller->dataList.removeAt(index);
    controller->ctxt->setContextProperty("TeachPointModel", QVariant::fromValue(controller->dataList));

    writePointListFile();

    _errorMessage="The Point deleted";
    emit viewErrorPopup();
}

void teachpointviewmodel::updateNameBtn(int index)
{

    qDebug()<<"update name func!!";

    points *current_p = dynamic_cast<points*>(controller->dataList.at(index));

    bool is_Duplicate=false;

    for (int i = 0;i < controller->dataList.length();i++) {
        points *p = dynamic_cast<points*>(controller->dataList.at(i));
        if(p->getName()==_tempName&&current_p->getName()!=_tempName)
            is_Duplicate=true;
    }

    if(is_Duplicate)
    {
        _errorMessage="The Chosen Name Is Duplicate . Please Try Another Name";
        emit viewErrorPopup();
    }
    else
    {
        current_p->setName(_tempName);
        controller->ctxt->setContextProperty("TeachPointModel", QVariant::fromValue(controller->dataList));

        writePointListFile();

        _errorMessage="The Point Name Changed";
        emit viewErrorPopup();
    }
}

void teachpointviewmodel::updatePositionBtn(int index,bool isJoint)
{
    points *p = dynamic_cast<points*>(controller->dataList.at(index));

    QList<double> actualPosition;
    for(int i=0; i< controller->beckhoff->NumberOfRobotMotors; i++)
    {
        actualPosition.append(controller->beckhoff->ActualPositions[i]*controller->robot->PulsToDegFactor1[i]);
    }



    if(isJoint) // joint point
    {
        p->setType("POINTJ");
        p->setPoints(actualPosition);
    }
    else    // cartesian point
    {
        p->setType("POINTP");
        actualPosition=calc_mainpoints();
        p->setPoints(actualPosition);
    }

    controller->ctxt->setContextProperty("TeachPointModel", QVariant::fromValue(controller->dataList));

    writePointListFile();

    _errorMessage="The Point Position Changed";
    emit viewErrorPopup();
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
        controller->beckhoff->setTargetPosition(controller->GotoVelocity,6);
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
        p1[i]=controller->beckhoff->ActualPositions[i]*controller->robot->PulsToDegFactor1[i]*M_PI/180.0;
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


//*******************************************************************
//*******************************************************************
//*******************************************************************

void teachpointviewmodel::writePointListFile()
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
        /*if(fromDeleteBtn == false){

                if(listIndex == i)
                    p->setPoints(_tempPoints) ;
            }
            p->setSaved(true);*/

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
}
