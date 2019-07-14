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

    controller->InitializeFrames();


}

void scoordinatesviewmodel::saveFrame(QString oldName,QString newName,QString frameType,QString frameMethod,QString x,QString y,QString z,QString a,QString b,QString c)
{

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
                QList<double> result=calc_mainpoints(temp);
                temp->setMainPoints(result);

                if(frameType=="world")
                {
                    double resultCartesian[6]={result.at(0),result.at(1),result.at(2),
                                               result.at(3),result.at(4),result.at(5)};
                    double resultDQ[8],baseDQ[8],baseCartesian[6];
                    controller->robot->CartesianToDQ(resultCartesian,resultDQ);
                    controller->robot->DQinv(resultDQ,baseDQ);
                    controller->robot->DQToCartesian(baseDQ,baseCartesian);
                    QList<double> exampleList = {baseCartesian[0],baseCartesian[1],baseCartesian[2],
                                                 baseCartesian[3],baseCartesian[4],baseCartesian[5]};

                    QString type="base",
                            tempName="",
                            threePointsStatus="111",
                            method="position";
                    bool savedStatus=true,iscurrentStatus=false;
                    int oldIndex=1;


                    //**********************************************
                    // Create New Name

                    if(Controller::getInstance()->framesList.length()==0)
                    {
                        tempName="frame1";
                    }
                    else
                    {
                        frame *f = dynamic_cast<frame *>(controller->framesList.at(Controller::getInstance()->framesList.length()-1));
                        oldIndex=f->frameIndex().toInt();
                        oldIndex+=1;

                        tempName="frame"+QString::number(oldIndex);
                    }
                    //**********************************************


                    Controller::getInstance()->framesList.push_back(new frame(QString::number(oldIndex),type,tempName,savedStatus,iscurrentStatus,exampleList,threePointsStatus,exampleList,"",exampleList,"",exampleList,"",method));

                }
            }
            //*********************************

            else if(frameMethod=="position")
            {
                QList<double> tempList = {x.toDouble(),y.toDouble(),z.toDouble(),a.toDouble(),b.toDouble(),c.toDouble()};
                temp->setMainPoints(tempList);
                if(frameType=="world")
                {
                    double resultCartesian[6]={tempList.at(0),tempList.at(1),tempList.at(2),
                                               tempList.at(3),tempList.at(4),tempList.at(5)};
                    double resultDQ[8],baseDQ[8],baseCartesian[6];
                    controller->robot->CartesianToDQ(resultCartesian,resultDQ);
                    controller->robot->DQinv(resultDQ,baseDQ);
                    controller->robot->DQToCartesian(baseDQ,baseCartesian);
                    QList<double> exampleList = {baseCartesian[0],baseCartesian[1],baseCartesian[2],
                                                 baseCartesian[3],baseCartesian[4],baseCartesian[5]};

                    QString type="base",
                            tempName="",
                            threePointsStatus="111",
                            method="position";
                    bool savedStatus=false,iscurrentStatus=false;
                    int oldIndex=1;


                    //**********************************************
                    // Create New Name

                    if(Controller::getInstance()->framesList.length()==0)
                    {
                        tempName="frame1";
                    }
                    else
                    {
                        frame *f = dynamic_cast<frame *>(controller->framesList.at(Controller::getInstance()->framesList.length()-1));
                        oldIndex=f->frameIndex().toInt();
                        oldIndex+=1;

                        tempName="frame"+QString::number(oldIndex);
                    }
                    //**********************************************


                    Controller::getInstance()->framesList.push_back(new frame(QString::number(oldIndex),type,tempName,savedStatus,iscurrentStatus,exampleList,threePointsStatus,exampleList,"",exampleList,"",exampleList,"",method));

                }
            }
            temp->setMethod(frameMethod);
        }
    }


    writeListToFile();

    controller->InitializeFrames();
}


//*****************************************************
//*****************************************************


void scoordinatesviewmodel::createBtn(QString frameType)
{

    QList<double> exampleList = {0,0,0,0,0,0};

    QString type=frameType,
            tempName="",
            threePointsStatus="100",
            method="3-point";
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


    controller->framesList.push_back(new frame(QString::number(oldIndex),type,tempName,savedStatus,iscurrentStatus,exampleList,threePointsStatus,exampleList,"",exampleList,"",exampleList,"",method));


    writeListToFile();
    controller->InitializeFrames();


}

//*****************************************************
//*****************************************************



void scoordinatesviewmodel::removeBtn(QString frameName)
{
    for(int i=0;i<Controller::getInstance()->framesList.length();i++)
    {
        frame *f = dynamic_cast<frame *>(controller->framesList.at(i));
        if(f->name()==frameName)
        {
            if(f->iscurrent())
            {
                // message box cant remove current frame
            }
            else
            {
                controller->framesList.removeAt(i);
            }
        }
    }


    writeListToFile();
    controller->InitializeFrames();
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

    controller->InitializeFrames();
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
    for(int i=0;i<Controller::getInstance()->framesList.length();i++)
    {
        frame *temp= dynamic_cast<frame*>(controller->framesList.at(i));

        if(temp->name()==frameName&&temp->iscurrent())
        {
            // message box : you cant set current a current frame
        }

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
            writeListToFile();

            //**************************************
            // Set Current Frame in Robots
            if(frameType=="world")
            {
                double resultCartesian[6]={ temp->mainPoints().at(0),
                                            temp->mainPoints().at(1),
                                            temp->mainPoints().at(2),
                                            temp->mainPoints().at(3),
                                            temp->mainPoints().at(4),
                                            temp->mainPoints().at(5)};
                double resultDQ[8],baseDQ[8],baseCartesian[6];
                controller->robot->CartesianToDQ(resultCartesian,resultDQ);
                controller->robot->DQinv(resultDQ,baseDQ);
                controller->robot->DQToCartesian(baseDQ,baseCartesian);
                QList<double> exampleList = {baseCartesian[0],baseCartesian[1],baseCartesian[2],
                                             baseCartesian[3],baseCartesian[4],baseCartesian[5]};
                controller->robot->currentBaseFrame->setMainPoints(exampleList);

                //Set base frame in beckhoff / modify in future
                for (int i=0;i<8;i++) {
                    controller->beckhoff->setTargetPosition(baseDQ[i],i);
                }
                controller->beckhoff->setGUIManager(97);
                // *******************************************

                QList<double> temp1 = {0,0,0,0,0,0,0};
                controller->robot->currentWorldFrame->setMainPoints(temp1);
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
                double tempTool[6] = {temp->mainPoints().at(0), temp->mainPoints().at(1),temp->mainPoints().at(2),
                                      temp->mainPoints().at(3),temp->mainPoints().at(4),temp->mainPoints().at(5)};
                double DQTooltemp[8];
                controller->robot->CartesianToDQ(tempTool,DQTooltemp);
                //Set tool frame in beckhoff / modify in future
                for (int i=0;i<8;i++) {
                    controller->beckhoff->setTargetPosition(DQTooltemp[i],i);
                }
                controller->beckhoff->setGUIManager(96);
                // *******************************************
            }
            //            else if(frameType=="base")
            //            {
            //                controller->robot->currentBaseFrame=temp;
            //            }

        }
    }


    controller->InitializeFrames();
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
            QList<double> actualPosition;
            double p1[6];
            double out1[6];
            for(int i=0; i< controller->beckhoff->NumberOfRobotMotors; i++)
            {
                p1[i]=(double)controller->beckhoff->ActualPositions[i]*controller->robot->PulsToDegFactor1[i];

            }
            controller->robot->JointToCartesian(p1,out1);

            //***************************************************

            if(temp->type()=="world"||temp->type()=="task")
            {

                for(int i=0; i< controller->beckhoff->NumberOfRobotMotors; i++)
                {
                    actualPosition.append(out1[i]);

                }
            }
            else if(temp->type()=="object")
            {
                double out2[8],out3[6],tempCurrentTaskDQ[8],invCurrentTaskDQ[8],objectToTaskDQ[8];
                controller->robot->CartesianToDQ(out1,out2);
                double tempCurrentTaskCartesian[6]={controller->robot->currentTaskFrame->mainPoints().at(0),
                                                    controller->robot->currentTaskFrame->mainPoints().at(1),
                                                    controller->robot->currentTaskFrame->mainPoints().at(2),
                                                    controller->robot->currentTaskFrame->mainPoints().at(3),
                                                    controller->robot->currentTaskFrame->mainPoints().at(4),
                                                    controller->robot->currentTaskFrame->mainPoints().at(5)};
                controller->robot->CartesianToDQ(tempCurrentTaskCartesian,tempCurrentTaskDQ);
                controller->robot->DQinv(tempCurrentTaskDQ,invCurrentTaskDQ);
                controller->robot->DQmultiply(invCurrentTaskDQ,out2,objectToTaskDQ);
                controller->robot->DQToCartesian(objectToTaskDQ,out3);
                for(int i=0; i< controller->beckhoff->NumberOfRobotMotors; i++)
                {
                    actualPosition.append(out3[i]);

                }

            }
            temp->setP1frameName(controller->robot->jogTempFrame->name());
            temp->setP1Point(actualPosition);
            temp->setThreePointsStatus("110");
        }
        //***************************************************
    }

    writeListToFile();

    controller->InitializeFrames();
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
            QList<double> actualPosition;
            double p1[6];
            double out1[6];
            for(int i=0; i< controller->beckhoff->NumberOfRobotMotors; i++)
            {
                p1[i]=(double)controller->beckhoff->ActualPositions[i]*controller->robot->PulsToDegFactor1[i];

            }
            controller->robot->JointToCartesian(p1,out1);

            //***************************************************

            if(temp->type()=="world"||temp->type()=="task")
            {

                for(int i=0; i< controller->beckhoff->NumberOfRobotMotors; i++)
                {
                    actualPosition.append(out1[i]);

                }

            }
            else if(temp->type()=="object")
            {
                double out2[8],out3[6],tempCurrentTaskDQ[8],invCurrentTaskDQ[8],objectToTaskDQ[8];
                controller->robot->CartesianToDQ(out1,out2);
                double tempCurrentTaskCartesian[6]={controller->robot->currentTaskFrame->mainPoints().at(0),
                                                    controller->robot->currentTaskFrame->mainPoints().at(1),
                                                    controller->robot->currentTaskFrame->mainPoints().at(2),
                                                    controller->robot->currentTaskFrame->mainPoints().at(3),
                                                    controller->robot->currentTaskFrame->mainPoints().at(4),
                                                    controller->robot->currentTaskFrame->mainPoints().at(5)};
                controller->robot->CartesianToDQ(tempCurrentTaskCartesian,tempCurrentTaskDQ);
                controller->robot->DQinv(tempCurrentTaskDQ,invCurrentTaskDQ);
                controller->robot->DQmultiply(invCurrentTaskDQ,out2,objectToTaskDQ);
                controller->robot->DQToCartesian(objectToTaskDQ,out3);
                for(int i=0; i< controller->beckhoff->NumberOfRobotMotors; i++)
                {
                    actualPosition.append(out3[i]);

                }

            }
            temp->setP2Point(actualPosition);
            temp->setP2frameName(controller->robot->jogTempFrame->name());
            temp->setThreePointsStatus("111");
        }
        //***************************************************
    }

    writeListToFile();

    controller->InitializeFrames();
}

//*****************************************************
//*****************************************************

void scoordinatesviewmodel::point3Btn(QString frameName)
{
    for(int i=0;i<Controller::getInstance()->framesList.length();i++)
    {
        frame *temp= dynamic_cast<frame*>(controller->framesList.at(i));

        //***************************************************
        // Set Current Frame Status To False
        if(temp->name()==frameName)
        {
            QList<double> actualPosition;
            double p1[6];
            double out1[6];
            for(int i=0; i< controller->beckhoff->NumberOfRobotMotors; i++)
            {
                p1[i]=(double)controller->beckhoff->ActualPositions[i]*controller->robot->PulsToDegFactor1[i];

            }
            controller->robot->JointToCartesian(p1,out1);

            //***************************************************

            if(temp->type()=="world"||temp->type()=="task")
            {

                for(int i=0; i< controller->beckhoff->NumberOfRobotMotors; i++)
                {
                    actualPosition.append(out1[i]);
                }

            }
            else if(temp->type()=="object")
            {
                double out2[8],out3[6],tempCurrentTaskDQ[8],invCurrentTaskDQ[8],objectToTaskDQ[8];
                controller->robot->CartesianToDQ(out1,out2);
                double tempCurrentTaskCartesian[6]={controller->robot->currentTaskFrame->mainPoints().at(0),
                                                    controller->robot->currentTaskFrame->mainPoints().at(1),
                                                    controller->robot->currentTaskFrame->mainPoints().at(2),
                                                    controller->robot->currentTaskFrame->mainPoints().at(3),
                                                    controller->robot->currentTaskFrame->mainPoints().at(4),
                                                    controller->robot->currentTaskFrame->mainPoints().at(5)};
                controller->robot->CartesianToDQ(tempCurrentTaskCartesian,tempCurrentTaskDQ);
                controller->robot->DQinv(tempCurrentTaskDQ,invCurrentTaskDQ);
                controller->robot->DQmultiply(invCurrentTaskDQ,out2,objectToTaskDQ);
                controller->robot->DQToCartesian(objectToTaskDQ,out3);
                for(int i=0; i< controller->beckhoff->NumberOfRobotMotors; i++)
                {
                    actualPosition.append(out3[i]);

                }

            }
            temp->setP3Point(actualPosition);
            temp->setP3frameName(controller->robot->jogTempFrame->name());

            //***************************************************
        }
    }

    writeListToFile();

    controller->InitializeFrames();
}


//*****************************************************
//*****************************************************

QList<double> scoordinatesviewmodel::calc_mainpoints(frame *frm)
{
    //    for(int i=0;i<Controller::getInstance()->framesList.length();i++)
    //    {
    frame *temp=frm;// dynamic_cast<frame*>(controller->framesList.at(i));

    //*************************
    // calculate mainPoints With 3-Points

    QList<double> p11 = temp->p1Point();
    QList<double> p22 = temp->p2Point();
    QList<double> p33 = temp->p3Point();

    double p1[6] = {p11[0], p11[1], p11[2], p11[3], p11[4], p11[5]};
    double p2[6] = {p22[0], p22[1], p22[2], p22[3], p22[4], p22[5]};
    double p3[6] = {p33[0], p33[1], p33[2], p33[3], p33[4], p33[5]};

    //        double p1[6];
    //        controller->robot->JointToCartesian(out1,p1);
    //        double p2[6];
    //        controller->robot->JointToCartesian(out2,p2);
    //        double p3[6];
    //        controller->robot->JointToCartesian(out3,p3);

    QList<double> Xf = {p2[0]-p1[0],p2[1]-p1[1],p2[2]-p1[2]};
    double normOfXf=pow(Xf[0],2);
    normOfXf= normOfXf + pow(Xf[1],2);
    normOfXf= normOfXf + pow(Xf[2],2);
    normOfXf = sqrt(normOfXf);

    Xf[0]=Xf[0] / normOfXf;
    Xf[1]=Xf[1] / normOfXf;
    Xf[2]=Xf[2] / normOfXf;

    QList<double> Yi = {p3[0]-p1[0],p3[1]-p1[1],p3[2]-p1[2]};
    double normOfYi=pow(Yi[0],2);
    normOfYi=normOfYi + pow(Yi[1],2);
    normOfYi=normOfYi + pow(Yi[2],2);
    normOfYi = sqrt(normOfYi);

    Yi[0]=Yi[0] / normOfYi;
    Yi[1]=Yi[1] / normOfYi;
    Yi[2]=Yi[2] / normOfYi;

    QList<double> Zf = {(Xf[1]*Yi[2])-(Xf[2]*Yi[1]),(Xf[2]*Yi[0])-(Xf[0]*Yi[2]),(Xf[0]*Yi[1])-(Xf[1]*Yi[0])};

    QList<double> Yf = {(Zf[1]*Xf[2])-(Zf[2]*Xf[1]),(Zf[2]*Xf[0])-(Zf[0]*Xf[2]),(Zf[0]*Xf[1])-(Zf[1]*Xf[0])};

    //XF[0] YF[0] ZF[0]
    //XF[1] YF[1] ZF[1]
    //XF[2] YF[2] ZF[2]
    double RotM[3][3]={{Xf[0], Yf[0] ,Zf[0]}, {Xf[1], Yf[1] ,Zf[1]},{Xf[2], Yf[2] ,Zf[2]}};
    double out[3];
    controller->robot->RotMToEuler(RotM,out);
    QList<double> result = {p1[0],p1[1],p1[2], out[0], out[1], out[2]};
    return result;
    //}
}


//*****************************************************
//*****************************************************
