#include "controller.h"
#include "beckhoff.h"
#include "../ViewModel/points.h"
#include "../ViewModel/frame.h"
#include <QList>
#include <QDomDocument>

Controller::Controller()
{
    robot = new Robot();
    beckhoff = new Beckhoff();
}
Controller* Controller::instance = nullptr;

Controller* Controller::getInstance()
{
    if (instance == nullptr)
    {
        instance = new Controller();
    }

    return instance;
}

void Controller::Initialize()
{
//    QList<double> exampleList = {1.20, 2.2 , 4, 5, 500,300.56};
//    QList<double> exampleList2 = {300, 4000 , 70, 85, 7000,600};
//    //points *p = new points(name,type,tempPoints,stringFrameType,stringFrameName,myIndexInList.toInt());


//    Controller::getInstance()->dataList.push_back(new points("Behrooz","cartesian",exampleList,"object","frame1",0));
//    Controller::getInstance()->dataList.push_back(new points("Behrooz","cartesian",exampleList,"object","frame1",0));
//    ctxt->setContextProperty("TeachPointModel", QVariant::fromValue( Controller::getInstance()->dataList));




    //*******************************************************************
    //*******************************************************************
    //                Read From Frames.xml File
    //           And Add Objects Of Frame Class To List
    //*******************************************************************
    //*******************************************************************

    Controller::getInstance()->framesList.clear();

    QString frameName,frameIndex,type,savedStatus,iscurrentStatus,threePointsStatus,frameMethod,
            mainpoints_x,mainpoints_y,mainpoints_z,mainpoints_a,mainpoints_b,mainpoints_c,
            point1_x,point1_y,point1_z,point1_a,point1_b,point1_c,point1_framename,
            point2_x,point2_y,point2_z,point2_a,point2_b,point2_c,point2_framename,
            point3_x,point3_y,point3_z,point3_a,point3_b,point3_c,point3_framename,
            teachedFrameName,teachedFrameType="";
    bool saved,iscurrent=false;
    QDomDocument xmlBOM;


    QFile f("frames.xml");
    if (!f.open(QIODevice::ReadOnly ))
    {
        // Error while loading file
        std::cerr << "File Dose Not Exist" << std::endl;
        return;
    }
    xmlBOM.setContent(&f);
    f.close();

    QDomElement root=xmlBOM.documentElement();

    QDomElement frameTag=root.firstChild().toElement();
    for(int i=0;i<root.childNodes().length();i++)
    {
        //********************
        // get frame Name
        QDomElement firstlevelchildTag=frameTag.firstChild().toElement();
        frameName=firstlevelchildTag.firstChild().toText().data();
        //********************
        // get frame index
        firstlevelchildTag=firstlevelchildTag.nextSibling().toElement();
        frameIndex=firstlevelchildTag.firstChild().toText().data();
        //********************
        // get frame type
        firstlevelchildTag=firstlevelchildTag.nextSibling().toElement();
        type=firstlevelchildTag.firstChild().toText().data();
        //********************
        // get frame savedStatus
        firstlevelchildTag = firstlevelchildTag.nextSibling().toElement();
        savedStatus=firstlevelchildTag.firstChild().toText().data();
        if(savedStatus=="1")
            saved=true;
        else {
            saved=false;
        }
        //********************
        // get frame iscurrentStatus
        firstlevelchildTag = firstlevelchildTag.nextSibling().toElement();
        iscurrentStatus=firstlevelchildTag.firstChild().toText().data();
        if(iscurrentStatus=="1")
            iscurrent=true;
        else {
            iscurrent=false;
        }

        //********************
        // get frame MainPoints
        firstlevelchildTag = firstlevelchildTag.nextSibling().toElement();
        //x
        QDomElement secondlevelchildTag=firstlevelchildTag.firstChild().toElement();
        mainpoints_x=secondlevelchildTag.firstChild().toText().data();
        //y
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        mainpoints_y=secondlevelchildTag.firstChild().toText().data();
        //z
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        mainpoints_z=secondlevelchildTag.firstChild().toText().data();
        //a
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        mainpoints_a=secondlevelchildTag.firstChild().toText().data();
        //b
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        mainpoints_b=secondlevelchildTag.firstChild().toText().data();
        //c
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        mainpoints_c=secondlevelchildTag.firstChild().toText().data();

        QList<double> mainpointsList = {mainpoints_x.toDouble(), mainpoints_y.toDouble() , mainpoints_z.toDouble(), mainpoints_a.toDouble(), mainpoints_b.toDouble(),mainpoints_c.toDouble()};

        //********************
        // get frame threePointsStatus
        firstlevelchildTag=firstlevelchildTag.nextSibling().toElement();
        threePointsStatus=firstlevelchildTag.firstChild().toText().data();
        //********************

        //********************
        // get frame method
        firstlevelchildTag=firstlevelchildTag.nextSibling().toElement();
        frameMethod=firstlevelchildTag.firstChild().toText().data();

        //********************
        // get frame point1
        firstlevelchildTag = firstlevelchildTag.nextSibling().toElement();
        //x
        secondlevelchildTag=firstlevelchildTag.firstChild().toElement();
        point1_x=secondlevelchildTag.firstChild().toText().data();
        //y
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        point1_y=secondlevelchildTag.firstChild().toText().data();
        //z
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        point1_z=secondlevelchildTag.firstChild().toText().data();
        //a
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        point1_a=secondlevelchildTag.firstChild().toText().data();
        //b
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        point1_b=secondlevelchildTag.firstChild().toText().data();
        //c
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        point1_c=secondlevelchildTag.firstChild().toText().data();

        QList<double> point1List = {point1_x.toDouble(), point1_y.toDouble() , point1_z.toDouble(), point1_a.toDouble(), point1_b.toDouble(),point1_c.toDouble()};

        // frameName
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        point1_framename=secondlevelchildTag.firstChild().toText().data();

        //********************
        // get frame point2
        firstlevelchildTag = firstlevelchildTag.nextSibling().toElement();
        //x
        secondlevelchildTag=firstlevelchildTag.firstChild().toElement();
        point2_x=secondlevelchildTag.firstChild().toText().data();
        //y
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        point2_y=secondlevelchildTag.firstChild().toText().data();
        //z
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        point2_z=secondlevelchildTag.firstChild().toText().data();
        //a
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        point2_a=secondlevelchildTag.firstChild().toText().data();
        //b
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        point2_b=secondlevelchildTag.firstChild().toText().data();
        //c
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        point2_c=secondlevelchildTag.firstChild().toText().data();

        QList<double> point2List = {point2_x.toDouble(), point2_y.toDouble() , point2_z.toDouble(), point2_a.toDouble(), point2_b.toDouble(),point2_c.toDouble()};

        // frameName
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        point2_framename=secondlevelchildTag.firstChild().toText().data();

        //********************
        // get frame point3
        firstlevelchildTag = firstlevelchildTag.nextSibling().toElement();
        //x
        secondlevelchildTag=firstlevelchildTag.firstChild().toElement();
        point3_x=secondlevelchildTag.firstChild().toText().data();
        //y
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        point3_y=secondlevelchildTag.firstChild().toText().data();
        //z
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        point3_z=secondlevelchildTag.firstChild().toText().data();
        //a
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        point3_a=secondlevelchildTag.firstChild().toText().data();
        //b
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        point3_b=secondlevelchildTag.firstChild().toText().data();
        //c
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        point3_c=secondlevelchildTag.firstChild().toText().data();

        QList<double> point3List = {point3_x.toDouble(), point3_y.toDouble() , point3_z.toDouble(), point3_a.toDouble(), point3_b.toDouble(),point3_c.toDouble()};

        // frameName
        secondlevelchildTag = secondlevelchildTag.nextSibling().toElement();
        point3_framename=secondlevelchildTag.firstChild().toText().data();

        //********************
        // get frame TeachedFrameName
        firstlevelchildTag = firstlevelchildTag.nextSibling().toElement();
        teachedFrameName=firstlevelchildTag.firstChild().toText().data();
        //********************
        // get frame TeachedFrameType
        firstlevelchildTag = firstlevelchildTag.nextSibling().toElement();
        teachedFrameType=firstlevelchildTag.firstChild().toText().data();



        frame *f=new frame(frameIndex,type,frameName,saved,iscurrent,mainpointsList,threePointsStatus,point1List,point1_framename,point2List,point2_framename,point3List,point3_framename,frameMethod,teachedFrameName,teachedFrameType);
        // set Current Frames
        if(iscurrent)
        {
            if(type=="world")
            {
//                QList<double> temp1 = {0,0,0,0,0,0,0};
//                f->setMainPoints(temp1);
                robot->currentWorldFrame=f;
            }
            else if(type=="object")
            {
                robot->currentObjectFrame=f;
            }
            else if(type=="task")
            {
                robot->currentTaskFrame=f;
            }
            else if(type=="tool")
            {
                robot->currentToolFrame=f;
            }
            else if(type=="base")
            {
                robot->currentBaseFrame=f;
            }
        }


        Controller::getInstance()->framesList.push_back(f);
        frameTag = frameTag.nextSibling().toElement();
    }

    ctxt->setContextProperty("SCoordinateModel", QVariant::fromValue( Controller::getInstance()->framesList));

    QList<double> temp1 = {0,0,0,0,0,0,0};
    robot->currentWorldFrame->setMainPoints(temp1);
    //*******************************************************************
    //*******************************************************************
    //               End of Read From Frames.xml File
    //*******************************************************************
    //*******************************************************************




    /*
    points *p1= new points("p1",true,exampleList);
    points *p2= new points("p2",true,exampleList);
    points *p3= new points("p3",true,exampleList);


    Controller::getInstance()->framesList.push_back(new frame("type1","frame1",true,exampleList,p1,p2,p3,"method","TeachedFrameName","TeachedFrameType"));
    Controller::getInstance()->framesList.push_back(new frame("type2","frame2",true,exampleList2,p1,p2,p3,"method","TeachedFrameName","TeachedFrameType"));
    ctxt->setContextProperty("SCoordinateModel", QVariant::fromValue( Controller::getInstance()->framesList));
*/
    /*while(!root.isNull())
    {
        QDomElement child=root.firstChild().toElement();
        while (!child.isNull()) {
            frameName=child.tagName();
            QDomElement Component=child.firstChild().toElement();
            x=Component.firstChild().toText().data();
            Component = Component.nextSibling().toElement();
            y=Component.firstChild().toText().data();
            Component = Component.nextSibling().toElement();
            z=Component.firstChild().toText().data();
            Component = Component.nextSibling().toElement();
            a=Component.firstChild().toText().data();
            Component = Component.nextSibling().toElement();
            b=Component.firstChild().toText().data();
            Component = Component.nextSibling().toElement();
            c=Component.firstChild().toText().data();
            qDebug(qPrintable(frameName+":"+"X:"+x+"_Y:"+y+"_Z:"+z+"_A:"+a+"_B:"+b+"_C:"+c));
            // Go to next frame
            child = child.nextSibling().toElement();
        }

        root = root.nextSibling().toElement();
    }*/
}

void Controller::InitializePoints()
{
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
        this->dataList.push_back(p);
        pointTag = pointTag.nextSibling().toElement();
    }


    this->ctxt->setContextProperty("TeachPointModel", QVariant::fromValue(this->dataList));

}
//void Controller::editList(int index)
//{
//    points *p = dynamic_cast<points*>( Controller::getInstance()->dataList.at(index));
//    p->setName("vghugfhjgj");
//}
