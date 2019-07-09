#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include "teachpointviewmodel.h"

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

    Controller::getInstance()->dataList.clear();

    QDomDocument xmlBOM;
    QFile f("pointsList.xml");
    if (!f.open(QIODevice::ReadOnly ))
    {
        // Error while loading file
        std::cerr << "File Dose Not Exist" << std::endl;
        return;
    }
    xmlBOM.setContent(&f);
    f.close();

    QDomElement root=xmlBOM.documentElement();

    QDomElement pointTag=root.firstChild().toElement();
    for(int i=0;i<root.childNodes().length();i++)
    {
        //********************
        // get point Name
        //        QString name=pointTag.tagName();
        QDomElement firstlevelchildTag=pointTag.firstChild().toElement();
        QString name=firstlevelchildTag.firstChild().toText().data();
        //********************
        // get point type
        firstlevelchildTag=firstlevelchildTag.nextSibling().toElement();
        QString type=firstlevelchildTag.firstChild().toText().data();
        //********************
        // get point values

        firstlevelchildTag = firstlevelchildTag.nextSibling().toElement();
        //x
        QDomElement secondlevelchildTag=firstlevelchildTag.firstChild().toElement();
        QString x=secondlevelchildTag.firstChild().toText().data();
        //y
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        QString y=secondlevelchildTag.firstChild().toText().data();
        //z
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        QString z=secondlevelchildTag.firstChild().toText().data();
        //a
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        QString a=secondlevelchildTag.firstChild().toText().data();
        //b
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        QString b=secondlevelchildTag.firstChild().toText().data();
        //c
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        QString c=secondlevelchildTag.firstChild().toText().data();

        QList<double> tempPoints = {x.toDouble(), y.toDouble() , z.toDouble(), a.toDouble(), b.toDouble(),c.toDouble()};


        //********************
        // get point stringFrameType
        firstlevelchildTag = firstlevelchildTag.nextSibling().toElement();
        QString stringFrameType=firstlevelchildTag.firstChild().toText().data();
        //********************
        // get point stringFrameName
        firstlevelchildTag = firstlevelchildTag.nextSibling().toElement();
        QString stringFrameName=firstlevelchildTag.firstChild().toText().data();
        //********************
        // get point myIndexInList
        firstlevelchildTag = firstlevelchildTag.nextSibling().toElement();
        QString myIndexInList=firstlevelchildTag.firstChild().toText().data();

        points *p = new points(name,type,tempPoints,stringFrameType,stringFrameName,myIndexInList.toInt());
        p->setSaved(true);
        controller->dataList.push_back(p);
        pointTag = pointTag.nextSibling().toElement();
    }


    controller->ctxt->setContextProperty("TeachPointModel", QVariant::fromValue(controller->dataList));

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
    QList<double> actualPosition =  controller->beckhoff->actualPositions;
    controller->dataList.push_front(new points(false,actualPosition));
    QString newPointNumber = generateNewPointNumber();
    points *p = dynamic_cast<points*>(controller->dataList.at(0));
    p->setName(newPointName+newPointNumber);
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

QString teachpointviewmodel::getPointName(int index)
{
    points *p = dynamic_cast<points*>(controller->dataList.at(index));
    return p->getName();
}

void teachpointviewmodel::radioBtnClicked(int index,QString value)
{
    points *p = dynamic_cast<points*>(controller->dataList.at(index));
    p->setType(value);
    p->setSaved(false);
    p->setUpdated(true);
    controller->ctxt->setContextProperty("TeachPointModel", QVariant::fromValue(controller->dataList));
}

QString teachpointviewmodel::savedAndUpdatedString(int index)
{
    points *p = dynamic_cast<points*>(controller->dataList.at(index));
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
