#include "scoordinatesviewmodel.h"
#include <QFile>
#include <QFileInfo>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QDomDocument>
#include <QtXml>
#include <iostream>
#include "../ViewModel/points.h"
#include "../ViewModel/frame.h"

using namespace std;

scoordinatesviewmodel::scoordinatesviewmodel(QObject *parent) : QObject(parent)
{


    controller = Controller::getInstance();

    controller->Initialize();


}

void scoordinatesviewmodel::saveFrame(QString oldName,QString newName,QString frameType,QString frameMethod,QString teachedFrameType,QString x,QString y,QString z,QString a,QString b,QString c)
{

    //**************************************
    // MainPoints Should Be Calculated With Function
    QList<double> exampleList = {0,0,0,0,0,0};
    //**************************************


    for(int i=0;i<controller->framesList.length();i++)
    {
        frame *temp= dynamic_cast<frame*>(controller->framesList.at(i));

        if(temp->name()==oldName)
        {
            temp->setName(newName);
            temp->setType(frameType);
            temp->setSaved(true);
            temp->setThreePointsStatus("000");
            if(frameMethod=="3-point")
            {
                temp->setMainPoints(exampleList);
            }
            else if(frameMethod=="position")
            {
                QList<double> tempList = {x.toDouble(),y.toDouble(),z.toDouble(),a.toDouble(),b.toDouble(),c.toDouble()};
                temp->setMainPoints(tempList);
            }
            temp->setMethod(frameMethod);
            temp->setFrameType(teachedFrameType);

            //**************************************
            // Get Current Frame Name in Robots
            if(teachedFrameType=="world")
            {
                temp->setFrameName(controller->robot->currentWorldFrame->name());
            }
            else if(teachedFrameType=="object")
            {
                temp->setFrameName(controller->robot->currentObjectFrame->name());
            }
            else if(teachedFrameType=="task")
            {
                temp->setFrameName(controller->robot->currentTaskFrame->name());
            }
            else if(teachedFrameType=="tool")
            {
                temp->setFrameName(controller->robot->currentToolFrame->name());
            }
            else if(teachedFrameType=="base")
            {
                temp->setFrameName(controller->robot->currentBaseFrame->name());
            }
        }
    }

    writeListToFile();

    controller->Initialize();



}



//*****************************************************
//*****************************************************


void scoordinatesviewmodel::createBtn()
{

    QList<double> exampleList = {0,0,0,0,0,0};

    QString type="object",
            tempName="",
            threePointsStatus="100",
            method="3-point",
            TeachedFrameName="TeachedFrameName",
            TeachedFrameType="TeachedFrameType";
    bool savedStatus=false,iscurrentStatus=false;
    int oldIndex=1;


    //**********************************************
    // Create New Name

    if(controller->framesList.length()==0)
    {
        tempName="frame1";
    }
    else
    {
        frame *f = dynamic_cast<frame *>(controller->framesList.at(controller->framesList.length()-1));
        oldIndex=f->frameIndex().toInt();
        oldIndex+=1;

        tempName="frame"+QString::number(oldIndex);
    }
    //**********************************************


    controller->framesList.push_back(new frame(QString::number(oldIndex),type,tempName,savedStatus,iscurrentStatus,exampleList,threePointsStatus,exampleList,"",exampleList,"",exampleList,"",method,TeachedFrameName,TeachedFrameType));
    controller->ctxt->setContextProperty("SCoordinateModel", QVariant::fromValue( controller->framesList));


    writeListToFile();


}

//*****************************************************
//*****************************************************



void scoordinatesviewmodel::removeBtn(QString frameName)
{
    for(int i=0;i<controller->framesList.length();i++)
    {
        frame *f = dynamic_cast<frame *>(controller->framesList.at(i));
        if(f->name()==frameName)
        {
            controller->framesList.removeAt(i);

            //***************************************
            // remove points theached with this frame

            for(int j=0;j<controller->dataList.length();j++)
            {
                points *p = dynamic_cast<points *>(controller->dataList.at(j));
                if(p->getStringFrameName()==frameName)
                {
                    controller->dataList.removeAt(j);
                }
            }

            //***************************************
        }
    }
    controller->ctxt->setContextProperty("SCoordinateModel", QVariant::fromValue( controller->framesList));
    controller->ctxt->setContextProperty("TeachPointModel", QVariant::fromValue( controller->dataList));

    writeListToFile();
    writePointListFile();

}

//*****************************************************
//*****************************************************

void scoordinatesviewmodel::modifyBtn(QString frameName)
{
    for(int i=0;i<controller->framesList.length();i++)
    {
        frame *temp= dynamic_cast<frame*>(controller->framesList.at(i));

        //***************************************************
        // Set saved Frame Status To False
        if(temp->name()==frameName)
        {
            temp->setSaved(false);
            temp->setThreePointsStatus("100");
        }
        //***************************************************
    }

    writeListToFile();

    controller->Initialize();
}


//*****************************************************
//*****************************************************


void scoordinatesviewmodel::writeListToFile()
{
    //************
    // write to file

    QFile file("frames.xml");
    QXmlStreamWriter xmlWriter(&file);


    if(file.exists())
    {
        file.remove();
    }

    bool b=file.open(QIODevice::WriteOnly);
    // file.open(QIODevice::WriteOnly);
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("Frames");


    for(int i=0;i<controller->framesList.length();i++)
    {
        frame *f = dynamic_cast<frame *>(controller->framesList.at(i));
        xmlWriter.writeStartElement("frame");
        xmlWriter.writeTextElement("name", f->name());
        xmlWriter.writeTextElement("index", QString::number(i+1));
        xmlWriter.writeTextElement("type", f->type() );
        xmlWriter.writeTextElement("savedStatus", QString::number(f->saved()));
        xmlWriter.writeTextElement("iscurrentStatus", QString::number(f->iscurrent()));
        //************************
        //mainPoints
        xmlWriter.writeStartElement("mainPoints");
        QList<double> temp = f->mainPoints();
        xmlWriter.writeTextElement("X", QString::number(temp[0]));
        xmlWriter.writeTextElement("Y", QString::number(temp[1]));
        xmlWriter.writeTextElement("Z", QString::number(temp[2]));
        xmlWriter.writeTextElement("A", QString::number(temp[3]));
        xmlWriter.writeTextElement("B", QString::number(temp[4]));
        xmlWriter.writeTextElement("C", QString::number(temp[5]));
        xmlWriter.writeEndElement();
        //************************
        //************************
        // threePointsStatus
        xmlWriter.writeTextElement("threePointsStatus", f->threePointsStatus());
        //************************
        //************************
        // method
        xmlWriter.writeTextElement("method", f->method());
        //************************
        //************************
        // point 1
        xmlWriter.writeStartElement("Point1");
        temp = f->p1Point();
        xmlWriter.writeTextElement("X", QString::number(temp[0]));
        xmlWriter.writeTextElement("Y", QString::number(temp[1]));
        xmlWriter.writeTextElement("Z", QString::number(temp[2]));
        xmlWriter.writeTextElement("A", QString::number(temp[3]));
        xmlWriter.writeTextElement("B", QString::number(temp[4]));
        xmlWriter.writeTextElement("C", QString::number(temp[5]));
        xmlWriter.writeTextElement("frameName",f->p1frameName());
        xmlWriter.writeEndElement();
        //************************
        //************************
        // point 2
        xmlWriter.writeStartElement("Point2");
        temp = f->p2Point();
        xmlWriter.writeTextElement("X", QString::number(temp[0]));
        xmlWriter.writeTextElement("Y", QString::number(temp[1]));
        xmlWriter.writeTextElement("Z", QString::number(temp[2]));
        xmlWriter.writeTextElement("A", QString::number(temp[3]));
        xmlWriter.writeTextElement("B", QString::number(temp[4]));
        xmlWriter.writeTextElement("C", QString::number(temp[5]));
        xmlWriter.writeTextElement("frameName",f->p2frameName());
        xmlWriter.writeEndElement();
        //************************
        //************************
        // point 3
        xmlWriter.writeStartElement("Point3");
        temp = f->p3Point();
        xmlWriter.writeTextElement("X", QString::number(temp[0]));
        xmlWriter.writeTextElement("Y", QString::number(temp[1]));
        xmlWriter.writeTextElement("Z", QString::number(temp[2]));
        xmlWriter.writeTextElement("A", QString::number(temp[3]));
        xmlWriter.writeTextElement("B", QString::number(temp[4]));
        xmlWriter.writeTextElement("C", QString::number(temp[5]));
        xmlWriter.writeTextElement("frameName",f->p3frameName());
        xmlWriter.writeEndElement();
        //************************
        //teachedFrameName
        xmlWriter.writeTextElement("teachedFrameName", f->frameName());
        //************************
        //teachedFrameType
        xmlWriter.writeTextElement("teachedFrameType", f->frameType());


        // end of frame name tag
        xmlWriter.writeEndElement();
    }

    // end of Frames tag
    xmlWriter.writeEndElement();

    file.close();
}

//*****************************************************
//*****************************************************


void scoordinatesviewmodel::writePointListFile()
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


//*****************************************************
//*****************************************************

void scoordinatesviewmodel::setCurrentBtn(QString frameName, QString frameType)
{
    for(int i=0;i<controller->framesList.length();i++)
    {
        frame *temp= dynamic_cast<frame*>(controller->framesList.at(i));

        //***************************************************
        // Set Current Frame Status To False
        if(frameType==temp->type()&&temp->name()!=frameName)
        {
            temp->setIscurrent(false);
        }
        //***************************************************

        if(temp->name()==frameName)
        {
            temp->setIscurrent(true);

            //**************************************
            // Set Current Frame in Robots
            if(frameType=="world")
            {
                controller->robot->currentWorldFrame=temp;
            }
            else if(frameType=="object")
            {
                controller->robot->currentObjectFrame=temp;
            }
            else if(frameType=="task")
            {
                controller->robot->currentTaskFrame=temp;
            }
            else if(frameType=="tool")
            {
                controller->robot->currentToolFrame=temp;
            }
            else if(frameType=="base")
            {
                controller->robot->currentBaseFrame=temp;
            }

        }

    }

    //    qDebug(qPrintable("World:"+controller->robot->currentWorldFrame->name()));
    //    qDebug(qPrintable("object:"+controller->robot->currentObjectFrame->name()));
    //    qDebug(qPrintable("task:"+controller->robot->currentTaskFrame->name()));
    //    qDebug(qPrintable("tool:"+controller->robot->currentToolFrame->name()));
    //    qDebug(qPrintable("base:"+controller->robot->currentBaseFrame->name()));

    writeListToFile();

    controller->Initialize();
}


//*****************************************************
//*****************************************************

void scoordinatesviewmodel::point1Btn(QString frameName)
{
    for(int i=0;i<controller->framesList.length();i++)
    {
        frame *temp= dynamic_cast<frame*>(controller->framesList.at(i));

        //***************************************************
        // Set Current Frame Status To False
        if(temp->name()==frameName)
        {
            temp->setP1Point(controller->beckhoff->actualPositions);
            temp->setP1frameName(controller->robot->jogTempFrame->name());
            temp->setThreePointsStatus("110");
        }
        //***************************************************
    }

    writeListToFile();

    controller->Initialize();
}

//*****************************************************
//*****************************************************

void scoordinatesviewmodel::point2Btn(QString frameName)
{
    for(int i=0;i<controller->framesList.length();i++)
    {
        frame *temp= dynamic_cast<frame*>(controller->framesList.at(i));

        //***************************************************
        // Set Current Frame Status To False
        if(temp->name()==frameName)
        {
            temp->setP2Point(controller->beckhoff->actualPositions);
            temp->setP2frameName(controller->robot->jogTempFrame->name());
            temp->setThreePointsStatus("111");
        }
        //***************************************************
    }

    writeListToFile();

    controller->Initialize();
}

//*****************************************************
//*****************************************************

void scoordinatesviewmodel::point3Btn(QString frameName)
{
    for(int i=0;i<controller->framesList.length();i++)
    {
        frame *temp= dynamic_cast<frame*>(controller->framesList.at(i));

        //***************************************************
        // Set Current Frame Status To False
        if(temp->name()==frameName)
        {
            temp->setP3Point(controller->beckhoff->actualPositions);
            temp->setP3frameName(controller->robot->jogTempFrame->name());


            //*************************
            // calculate mainPoints With 3-Points

            QList<double> p1 = temp->p1Point();
            QList<double> p2 = temp->p2Point();
            QList<double> p3 = temp->p3Point();

            QList<double> Xf = {p2[0]-p1[0],p2[1]-p1[1],p2[2]-p1[2]};
            double normOfXf=pow(Xf[0],2);
            normOfXf=normOfXf + pow(Xf[1],2);
            normOfXf=normOfXf + pow(Xf[2],2);

            Xf[0]=Xf[0] / normOfXf;
            Xf[1]=Xf[1] / normOfXf;
            Xf[1]=Xf[1] / normOfXf;

            QList<double> Yi = {p3[0]-p1[0],p3[1]-p1[1],p3[2]-p1[2]};
            double normOfYi=pow(Yi[0],2);
            normOfYi=normOfYi + pow(Yi[1],2);
            normOfYi=normOfYi + pow(Yi[2],2);

            Yi[0]=Yi[0] / normOfYi;
            Yi[1]=Yi[1] / normOfYi;
            Yi[1]=Yi[1] / normOfYi;

            QList<double> Zf = {(Xf[1]*Yi[2])-(Xf[2]*Yi[1]),(Xf[0]*Yi[2])-(Xf[2]*Yi[0]),(Xf[0]*Yi[1])-(Xf[1]*Yi[0])};

            QList<double> Yf = {(Zf[1]*Xf[2])-(Zf[2]*Xf[1]),(Zf[0]*Xf[2])-(Zf[2]*Xf[0]),(Zf[0]*Xf[1])-(Zf[1]*Xf[0])};

            //*************************


        }
        //***************************************************
    }

    writeListToFile();

    controller->Initialize();
}


//*****************************************************
//*****************************************************
