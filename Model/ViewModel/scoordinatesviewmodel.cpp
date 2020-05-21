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

//    controller->InitializeFrames();


}

void scoordinatesviewmodel::saveFrame(QString newName,QString frameType,QString frameMethod,QString x,QString y,QString z,QString a,QString b,QString c)
{
    bool is_Duplicate=false;
    frame *f;

    for (int i = 0;i < controller->framesList.length();i++) {
        f = dynamic_cast<frame *>(controller->framesList.at(i));
        if(f->name()==newName)
            is_Duplicate=true;
    }

    if(is_Duplicate)
    {
        _errorMessage="The Chosen Name Is Duplicate . Please Try Another Name";
        emit viewErrorPopup();
    }
    else
    {

        QString type=frameType,
                tempName,correspondingFrameName="",threePointsStatus="000";
        bool savedStatus=true,iscurrentStatus=false;

        QList<double> zeroList = {0,0,0,0,0,0};

        int newIndex=1;
        if(Controller::getInstance()->framesList.length()!=0)
        {
            f = dynamic_cast<frame *>(controller->framesList.at(Controller::getInstance()->framesList.length()-1));
            newIndex=f->frameIndex().toInt();
            newIndex+=1;
        }

        //*************************************************************
        // 3-point mood
        //*************************************************************

        if(frameMethod=="3-point")
        {
            QList<double> result=calc_mainpoints(controller->robot->createFrameTemp);

            controller->framesList.push_back(new frame(QString::number(newIndex),frameType,newName,correspondingFrameName,savedStatus,iscurrentStatus,result,threePointsStatus,controller->robot->createFrameTemp->p1Point(),"",controller->robot->createFrameTemp->p2Point(),"",controller->robot->createFrameTemp->p3Point(),"",frameMethod));

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


                //****************************************************************
                // create case
                //****************************************************************

                QString type="base",
                        tempName="",
                        threePointsStatus="000",
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
                    f = dynamic_cast<frame *>(controller->framesList.at(Controller::getInstance()->framesList.length()-1));
                    oldIndex=f->frameIndex().toInt();
                    oldIndex+=1;

                    tempName="frame"+QString::number(oldIndex);
                }
                //**********************************************


                Controller::getInstance()->framesList.push_back(new frame(QString::number(oldIndex),type,tempName,"",savedStatus,iscurrentStatus,exampleList,threePointsStatus,exampleList,"",exampleList,"",exampleList,"",method));

                f->setCorrespondingFrameName(tempName);
            }


        }

        //*************************************************************
        // Position mood
        //*************************************************************

        else if(frameMethod=="position")
        {
            QList<double> tempList = {x.toDouble(),y.toDouble(),z.toDouble(),a.toDouble(),b.toDouble(),c.toDouble()};
            controller->framesList.push_back(new frame(QString::number(newIndex),frameType,newName,correspondingFrameName,savedStatus,iscurrentStatus,tempList,threePointsStatus,controller->robot->createFrameTemp->p1Point(),"",controller->robot->createFrameTemp->p2Point(),"",controller->robot->createFrameTemp->p3Point(),"",frameMethod));
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

                //****************************************************************
                // create case
                //****************************************************************

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
                    f = dynamic_cast<frame *>(controller->framesList.at(Controller::getInstance()->framesList.length()-1));
                    oldIndex=f->frameIndex().toInt();
                    oldIndex+=1;

                    tempName="frame"+QString::number(oldIndex);
                }
                //**********************************************


                Controller::getInstance()->framesList.push_back(new frame(QString::number(oldIndex),type,tempName,"",savedStatus,iscurrentStatus,exampleList,threePointsStatus,exampleList,"",exampleList,"",exampleList,"",method));

                f->setCorrespondingFrameName(tempName);
            }

        }

        //*************************************************************
        // 3-config mood
        //*************************************************************

        else if(frameMethod=="3-config")
        {
            qDebug() << "************************** 3-config";
        }

        //*************************************************************
        // 4-config mood
        //*************************************************************

        else if(frameMethod=="4-config")
        {
            qDebug() << "************************** 4-config";
        }

        controller->robot->createFrameTemp->setName("");
        controller->robot->createFrameTemp->setThreePointsStatus("000");
        controller->writeListToFile();

        controller->InitializeFrames();
    }
}

void scoordinatesviewmodel::updateFrame(bool isUpdateNameChecked,bool isUpdatePositionChecked,QString oldName,QString newName,QString frameType, QString frameMethod, QString x, QString y, QString z, QString a, QString b, QString c)
{
    bool is_Duplicate=false;
    frame *f,*currentF;
    QList<double> zeroList = {0,0,0,0,0,0};

    for (int i = 0;i < controller->framesList.length();i++) {
        f = dynamic_cast<frame *>(controller->framesList.at(i));
        if(f->name()==newName&&f->name()!=oldName)
            is_Duplicate=true;
        if(f->name()==oldName)
            currentF=f;
    }


    if(is_Duplicate)
    {
        _errorMessage="The Chosen Name Is Duplicate . Please Try Another Name";
        emit viewErrorPopup();
    }
    else
    {
        //*************************************************************
        // 3-point mood
        //*************************************************************

        if(frameMethod=="3-point")
        {
            if(isUpdatePositionChecked)
            {
                QList<double> result=calc_mainpoints(currentF);

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

                    for(int k=0;k<controller->framesList.length();k++)
                    {
                        f= dynamic_cast<frame*>(controller->framesList.at(k));
                        if(f->name()==currentF->correspondingFrameName()&&f->type()=="base")
                        {
                            f->setMainPoints(exampleList);
                        }
                    }

                    //**************************************
                    // if this world frame is current change mainPoints of currentBaseFrame

                    if(currentF->iscurrent())
                    {
                        controller->robot->currentWorldFrame = currentF;
                        controller->robot->currentWorldFrame->setMainPoints(zeroList);
                        controller->robot->currentBaseFrame->setMainPoints(exampleList);
                    }

                    //*************************************************
                }
                currentF->setMethod(frameMethod);
                currentF->setMainPoints(result);
            }
            if(isUpdateNameChecked)
                currentF->setName(newName);

        }

        //*************************************************************
        // Position mood
        //*************************************************************

        else if(frameMethod=="position")
        {
            if(isUpdatePositionChecked)
            {
                QList<double> tempList = {x.toDouble(),y.toDouble(),z.toDouble(),a.toDouble(),b.toDouble(),c.toDouble()};

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

                    for(int k=0;k<controller->framesList.length();k++)
                    {
                        f= dynamic_cast<frame*>(controller->framesList.at(k));
                        if(f->name()==currentF->correspondingFrameName()&&f->type()=="base")
                        {
                            f->setMainPoints(exampleList);
                        }
                    }

                    //**************************************
                    // if this world frame is current change mainPoints of currentBaseFrame

                    if(currentF->iscurrent())
                    {
                        controller->robot->currentWorldFrame = currentF;
                        controller->robot->currentWorldFrame->setMainPoints(zeroList);
                        controller->robot->currentBaseFrame->setMainPoints(exampleList);
                    }

                    //*************************************************
                }
                currentF->setMethod(frameMethod);
                currentF->setMainPoints(tempList);
            }
            if(isUpdateNameChecked)
                currentF->setName(newName);
        }


        //*********************************
        // if frame is current

        if(currentF->iscurrent()&&isUpdatePositionChecked)
        {
            if(frameType=="task")
            {
                controller->robot->currentTaskFrame=currentF;
            }
            else if(frameType=="tool")
            {
                controller->robot->currentToolFrame=currentF;
            }
            else if(frameType=="object")
            {
                controller->robot->currentObjectFrame = currentF;
            }
        }
        //***********************************

        currentF->setThreePointsStatus("000");
        controller->writeListToFile();
        controller->InitializeFrames();
        emit updateFrameDone();

    }

}


//*****************************************************
//*****************************************************

void scoordinatesviewmodel::setUpdateOptionsStatus(bool value)
{
    controller->IsUpdateButtonClickedFramePage=value;
}

//*****************************************************
//*****************************************************

void scoordinatesviewmodel::setUpdatePositionChkboxStatus(bool value)
{
    controller->IsUpdatePositionCheckedFramePage=value;
}

//*****************************************************
//*****************************************************

bool scoordinatesviewmodel::removeBtn(QString frameName)
{
    for(int i=0;i<Controller::getInstance()->framesList.length();i++)
    {
        frame *f = dynamic_cast<frame *>(controller->framesList.at(i));
        if(f->name()==frameName)
        {
            if(f->iscurrent())
            {
                return false;
            }
            else
            {
                //***************************************************
                // if it is world frame --> remove related base frame
                if(f->type()=="world")
                {
                    //*************************************************
                    // find base frame that related to this world frame

                    //                    double tempFrameCartesian[6]={f->mainPoints().at(0),
                    //                                                 f->mainPoints().at(1),
                    //                                                 f->mainPoints().at(2),
                    //                                                 f->mainPoints().at(3),
                    //                                                 f->mainPoints().at(4),
                    //                                                 f->mainPoints().at(5)};
                    //                    double tempFrameDQ[8],tempbaseDQ[8],tempbaseCartesian[6];
                    //                    controller->robot->CartesianToDQ(tempFrameCartesian,tempFrameDQ);
                    //                    controller->robot->DQinv(tempFrameDQ,tempbaseDQ);
                    //                    controller->robot->DQToCartesian(tempbaseDQ,tempbaseCartesian);
                    //                    QList<double> tempBaseMainPoints = {tempbaseCartesian[0],tempbaseCartesian[1],tempbaseCartesian[2],
                    //                                                 tempbaseCartesian[3],tempbaseCartesian[4],tempbaseCartesian[5]};

                    //************************************
                    controller->framesList.removeAt(i);
                    //************************************

                    for(int k=0;k<controller->framesList.length();k++)
                    {
                        frame *tempBase= dynamic_cast<frame*>(controller->framesList.at(k));
                        QString t=tempBase->name();
                        if(tempBase->name()==f->correspondingFrameName()&&tempBase->type()=="base")
                        {
                            controller->framesList.removeAt(k);
                            break; // jump from for(k) loop
                        }
                    }
                }
                else
                {
                    controller->framesList.removeAt(i);
                }
                //***************************************************
            }
            break; // jump from for(i) loop
        }
    }


    controller->writeListToFile();
    controller->InitializeFrames();
    return true;
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
                controller->robot->currentWorldFrame=temp;
            }
            else if(frameType=="object")
            {
                controller->robot->currentObjectFrame=temp;
                double tempObject[6] = {temp->mainPoints().at(0), temp->mainPoints().at(1),temp->mainPoints().at(2),
                                        temp->mainPoints().at(3),temp->mainPoints().at(4),temp->mainPoints().at(5)};
                double DQObjecttemp[8];
                controller->robot->CartesianToDQ(tempObject,DQObjecttemp);
                //Set object frame in beckhoff
                for (int i=0;i<8;i++) {
                    controller->beckhoff->setTargetPosition(DQObjecttemp[i],i);
                }
                controller->beckhoff->setGUIManager(94);
            }
            else if(frameType=="task")
            {
                controller->robot->currentTaskFrame=temp;
                double tempTask[6] = {temp->mainPoints().at(0), temp->mainPoints().at(1),temp->mainPoints().at(2),
                                      temp->mainPoints().at(3),temp->mainPoints().at(4),temp->mainPoints().at(5)};
                double DQTasktemp[8];
                controller->robot->CartesianToDQ(tempTask,DQTasktemp);
                //Set task frame in beckhoff
                for (int i=0;i<8;i++) {
                    controller->beckhoff->setTargetPosition(DQTasktemp[i],i);
                }
                controller->beckhoff->setGUIManager(95);
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

        }
    }

    controller->writeListToFile();
    controller->InitializeFrames();
    QList<double> temp1 = {0,0,0,0,0,0};
    controller->robot->currentWorldFrame->setMainPoints(temp1);
}


//*****************************************************
//*****************************************************

void scoordinatesviewmodel::point1Btn(QString frameName,QString frameType)
{

    controller->robot->createFrameTemp->setType(frameType);

    QList<double> actualPosition;
    double p1[6];
    double out1[6];
    for(int i=0; i< controller->beckhoff->NumberOfRobotMotors; i++)
    {
        p1[i]=(double)controller->beckhoff->ActualPositions[i]*controller->robot->PulsToDegFactor1[i];

    }
    controller->robot->JointToCartesian(p1,out1);


    //***************************************************

    if(controller->robot->createFrameTemp->type()=="world"||controller->robot->createFrameTemp->type()=="task"||controller->robot->createFrameTemp->type()=="tool")
    {

        for(int i=0; i< controller->beckhoff->NumberOfRobotMotors; i++)
        {
            actualPosition.append(out1[i]);

        }
    }
    else if(controller->robot->createFrameTemp->type()=="object")
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
    controller->robot->createFrameTemp->setName(frameName);
    controller->robot->createFrameTemp->setMethod("3-point");
    controller->robot->createFrameTemp->setP1frameName(controller->robot->jogTempFrame->name());
    controller->robot->createFrameTemp->setP1Point(actualPosition);
    controller->robot->createFrameTemp->setThreePointsStatus("100");

}

//*****************************************************
//*****************************************************

void scoordinatesviewmodel::point2Btn()
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

    if(controller->robot->createFrameTemp->type()=="world"||controller->robot->createFrameTemp->type()=="task"||controller->robot->createFrameTemp->type()=="tool")
    {

        for(int i=0; i< controller->beckhoff->NumberOfRobotMotors; i++)
        {
            actualPosition.append(out1[i]);

        }

    }
    else if(controller->robot->createFrameTemp->type()=="object")
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
    controller->robot->createFrameTemp->setP2Point(actualPosition);
    controller->robot->createFrameTemp->setP2frameName(controller->robot->jogTempFrame->name());
    controller->robot->createFrameTemp->setThreePointsStatus("110");
}

//*****************************************************
//*****************************************************

void scoordinatesviewmodel::point3Btn()
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

    if(controller->robot->createFrameTemp->type()=="world"||controller->robot->createFrameTemp->type()=="task"||controller->robot->createFrameTemp->type()=="tool")
    {

        for(int i=0; i< controller->beckhoff->NumberOfRobotMotors; i++)
        {
            actualPosition.append(out1[i]);

        }

    }
    else if(controller->robot->createFrameTemp->type()=="object")
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
    controller->robot->createFrameTemp->setP3Point(actualPosition);
    controller->robot->createFrameTemp->setP3frameName(controller->robot->jogTempFrame->name());
    controller->robot->createFrameTemp->setThreePointsStatus("111");

}

void scoordinatesviewmodel::point1BtnUpdate(QString frameName)
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
            temp->setThreePointsStatus("100");
        }
        //***************************************************
    }

    controller->writeListToFile();

    controller->InitializeFrames();
}

void scoordinatesviewmodel::point2BtnUpdate(QString frameName)
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
            temp->setThreePointsStatus("110");
        }
        //***************************************************
    }

    controller->writeListToFile();

    controller->InitializeFrames();
}

void scoordinatesviewmodel::point3BtnUpdate(QString frameName)
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
            temp->setThreePointsStatus("111");

            //***************************************************
        }
    }

    controller->writeListToFile();

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

//*******************************************************************
//*******************************************************************

int scoordinatesviewmodel::getCurrentListIndex()
{
    return controller->robot->currentFrameListIndex;
}

//*******************************************************************
//*******************************************************************

void scoordinatesviewmodel::setCurrentListIndex(int val)
{
    controller->robot->currentFrameListIndex=val;
}

//*******************************************************************
//*******************************************************************

int scoordinatesviewmodel::getSizeOfFrameList()
{
    return controller->framesList.length();
}

//*******************************************************************
//*******************************************************************

void scoordinatesviewmodel::setLastFrameType(QString val)
{
    controller->robot->lastFrameType=val;
}

//*******************************************************************
//*******************************************************************

QString scoordinatesviewmodel::getLastFrameType()
{
    return controller->robot->lastFrameType;
}

QString scoordinatesviewmodel::getTempCreateFrameName()
{
    return controller->robot->createFrameTemp->name();
}

QString scoordinatesviewmodel::getTempCreateFrameType()
{
    return controller->robot->createFrameTemp->type();
}

QString scoordinatesviewmodel::getTempCreateFrameThreePointsStatus()
{
    return controller->robot->createFrameTemp->threePointsStatus();
}

QString scoordinatesviewmodel::getErrorMessage()
{
    return _errorMessage;
}

bool scoordinatesviewmodel::isUpdateBtnClicked()
{
    return controller->IsUpdateButtonClickedFramePage;
}

bool scoordinatesviewmodel::isUpdatePositionChecked()
{
    return controller->IsUpdatePositionCheckedFramePage;
}


//*****************************************************
//*****************************************************
