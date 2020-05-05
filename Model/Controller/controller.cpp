#include "controller.h"
#include "beckhoff.h"
#include "../ViewModel/points.h"
#include "../ViewModel/frame.h"
#include "../ViewModel/bottomviewmodel.h"
#include <QList>
#include <QDomDocument>


Controller::Controller()
{
    robot = new Robot();
    beckhoff = new Beckhoff();
    initializeHashTable();
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


//*************************************************************************
//*************************************************************************

void Controller::Initialize()
{
    InitializeFrames();
}

//*************************************************************************
//*************************************************************************

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

//*************************************************************************
//*************************************************************************

void Controller::InitializeFrames()
{
    //*******************************************************************
    //*******************************************************************
    //                Read From Frames.xml File
    //           And Add Objects Of Frame Class To List
    //*******************************************************************
    //*******************************************************************

    Controller::getInstance()->framesList.clear();

    QString frameName,correspondingFrameName,frameIndex,type,savedStatus,iscurrentStatus,threePointsStatus,frameMethod,
            mainpoints_x,mainpoints_y,mainpoints_z,mainpoints_a,mainpoints_b,mainpoints_c,
            point1_x,point1_y,point1_z,point1_a,point1_b,point1_c,point1_framename,
            point2_x,point2_y,point2_z,point2_a,point2_b,point2_c,point2_framename,
            point3_x,point3_y,point3_z,point3_a,point3_b,point3_c,point3_framename="";
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
        // get frame correspondingFrameName
        firstlevelchildTag=firstlevelchildTag.nextSibling().toElement();
        correspondingFrameName=firstlevelchildTag.firstChild().toText().data();
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



        frame *f=new frame(frameIndex,type,frameName,correspondingFrameName,saved,iscurrent,mainpointsList,threePointsStatus,point1List,point1_framename,point2List,point2_framename,point3List,point3_framename,frameMethod);

        // set Current Frames
        if(iscurrent)
        {
            if(type=="world")
            {
                //**************************************************
                double resultCartesian[6]={ f->mainPoints().at(0),
                                            f->mainPoints().at(1),
                                            f->mainPoints().at(2),
                                            f->mainPoints().at(3),
                                            f->mainPoints().at(4),
                                            f->mainPoints().at(5)};
                double resultDQ[8],baseDQ[8],baseCartesian[6];
                robot->CartesianToDQ(resultCartesian,resultDQ);
                robot->DQinv(resultDQ,baseDQ);
                robot->DQToCartesian(baseDQ,baseCartesian);
                QList<double> exampleList = {baseCartesian[0],baseCartesian[1],baseCartesian[2],
                                             baseCartesian[3],baseCartesian[4],baseCartesian[5]};
                robot->currentBaseFrame->setMainPoints(exampleList);
                //Set base frame in beckhoff / modify in future
                for (int i=0;i<8;i++) {
                    beckhoff->setTargetPosition(baseDQ[i],i);
                }
                beckhoff->setGUIManager(97);
                //**************************************************
                robot->currentWorldFrame->setName(f->name());
                robot->currentWorldFrame->setType(f->type());
                robot->currentWorldFrame->setMethod(f->method());
                robot->currentWorldFrame->setP1Point(f->p1Point());
                robot->currentWorldFrame->setP1frameName(f->p1frameName());
                robot->currentWorldFrame->setP2Point(f->p2Point());
                robot->currentWorldFrame->setP2frameName(f->p2frameName());
                robot->currentWorldFrame->setP3Point(f->p3Point());
                robot->currentWorldFrame->setP3frameName(f->p3frameName());
            }
            else if(type=="object")
            {
                robot->currentObjectFrame=f;
                double tempObject[6] = {f->mainPoints().at(0), f->mainPoints().at(1),f->mainPoints().at(2),
                                      f->mainPoints().at(3),f->mainPoints().at(4),f->mainPoints().at(5)};
                double DQObjecttemp[8];
                robot->CartesianToDQ(tempObject,DQObjecttemp);
                //Set object frame in beckhoff
                for (int i=0;i<8;i++) {
                    beckhoff->setTargetPosition(DQObjecttemp[i],i);
                }
                beckhoff->setGUIManager(94);
            }
            else if(type=="task")
            {
                robot->currentTaskFrame=f;
                double tempTask[6] = {f->mainPoints().at(0), f->mainPoints().at(1),f->mainPoints().at(2),
                                      f->mainPoints().at(3),f->mainPoints().at(4),f->mainPoints().at(5)};
                double DQTasktemp[8];
                robot->CartesianToDQ(tempTask,DQTasktemp);
                //Set task frame in beckhoff
                for (int i=0;i<8;i++) {
                    beckhoff->setTargetPosition(DQTasktemp[i],i);
                }
                beckhoff->setGUIManager(95);
            }
            else if(type=="tool")
            {
                robot->currentToolFrame=f;
                double tempTool[6] = {f->mainPoints().at(0), f->mainPoints().at(1),f->mainPoints().at(2),
                                      f->mainPoints().at(3),f->mainPoints().at(4),f->mainPoints().at(5)};
                double DQTooltemp[8];
                robot->CartesianToDQ(tempTool,DQTooltemp);
                //Set tool frame in beckhoff
                for (int i=0;i<8;i++) {
                    beckhoff->setTargetPosition(DQTooltemp[i],i);
                }
                beckhoff->setGUIManager(96);
            }
        }


        Controller::getInstance()->framesList.push_back(f);
        frameTag = frameTag.nextSibling().toElement();
    }

    ctxt->setContextProperty("SCoordinateModel", QVariant::fromValue( Controller::getInstance()->framesList));

    QList<double> temp1 = {0,0,0,0,0,0};
    robot->currentWorldFrame->setMainPoints(temp1);
    //*******************************************************************
    //*******************************************************************
    //               End of Read From Frames.xml File
    //*******************************************************************
    //*******************************************************************

}

//*****************************************************
//*****************************************************


void Controller::writeListToFile()
{
    //************
    // write to frame.xml file

    QFile file("frames.xml");
    QXmlStreamWriter xmlWriter(&file);


    if(file.exists())
    {
        file.remove();
    }

    file.open(QIODevice::WriteOnly);
    // file.open(QIODevice::WriteOnly);
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("Frames");


    for(int i=0;i<framesList.length();i++)
    {
        frame *f = dynamic_cast<frame *>(framesList.at(i));
        xmlWriter.writeStartElement("frame");
        xmlWriter.writeTextElement("name", f->name());
        xmlWriter.writeTextElement("correspondingFrameName", f->correspondingFrameName());
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

bool Controller::AllowAlarmDetection()
{
    return _allow_alarm_detection;
}

void Controller::setAllowAlarmDetection(bool value)
{
    _allow_alarm_detection = value;
}


void Controller::InitializeAlarm(){

    ctxt->setContextProperty("AlarmModel", QVariant::fromValue( Controller::getInstance()->alarmList));
}

void Controller::AlarmDetection()
{
    uint16_t *t = beckhoff->getErrorCode();
    for (int i = 0; i < beckhoff->NumberOfRobotMotors; i++) {
        char a[16];

        t[i] = (t[i]/16)*10+((t[i]-(t[i]/16)*16)%16);
        snprintf(a, sizeof(a), "%d",t[i]);
        QString code =  (QString)(a);
        bool find = false;
        for (int j = 0 ;j < alarmList.size(); j++) {
            alarm *temp = dynamic_cast<alarm*>(alarmList.at(j));
            if(temp->key().contains(code) && temp->motorNum() == i) {
                find == true;
                break;
            }
        }
        if(!find){
            alarm *temp = getAlarm(code);
            if(temp != nullptr){
                temp->setMotorNum(i);
                alarmList.push_front(temp);
                InitializeAlarm();
            }
        }
    }
    InitializeAlarm();

}

void Controller::initializeHashTable(){
    _alarmTable = new QHash<QString,alarm*>();
    _alarmTable->insert("10",new alarm("IPM Fault","AL-10","Overcurrent (H/W)","Check for incorrect wiring in the drive output and encoder.Check the motor ID, drive ID, and encoder settings. Determine whether there is a conflict or binding in the equipment.",0));
    _alarmTable->insert("11",new alarm("IPM temperature","AL-11","IPM overheat","Check for incorrect wiring in the drive output and encoder. Check the motor ID, drive ID, and encoder settings. Determine whether there is a conflict or binding in the equipment.",0));
    _alarmTable->insert("14",new alarm("Overcurrent","AL-14","Overcurrent (S/W)","Check for incorrect wiring in the drive output and encoder. Check the motor ID, drive ID, and encoder settings. Determine whether there is a conflict or binding in the equipment.",0));
    _alarmTable->insert("15",new alarm("Current offset","AL-15","Abnormal current offset","Check whether the U-phase current offset [0x2614] and V-phase current offset [0x2615] are 5% of the rated current or higher. Replace the drive. ",0));
    _alarmTable->insert("16",new alarm("Overcurrent (/CL) ","AL-16","Overcurrent (H/W)","Check for incorrect wiring in the drive output and encoder. Check the motor ID, drive ID, and encoder settings. Determine whether there is a conflict or binding in the equipment.",0));
    _alarmTable->insert("21",new alarm("Continuous overload","AL-21","Continuous overload ","Determine whether there is a conflict or binding in the equipment. Check the load and the condition of the brake. Check for incorrect wiring in the drive output and encoder. Check the motor ID and encoder settings. ",0));
    _alarmTable->insert("22",new alarm("Room temperature ","AL-22","Drive overheat ","Check the temperature inside the drive [0x2610]. Install a cooling fan and check the load. ",0));
    _alarmTable->insert("23",new alarm("Regen. Overload ","AL-23","Regenerative overload ","Check the input voltage, regenerative braking resistance, and wiring.  Replace the drive. ",0));
    _alarmTable->insert("24",new alarm("Motor cable open","AL-24","Motor disconnection ","Check the wiring of the motor. ",0));
    _alarmTable->insert("30",new alarm("Encoder comm.","AL-30","Serial encoder communication error ","Check for incorrect wiring of the serial encoder. ",0));
    _alarmTable->insert("31",new alarm("Encoder cable open","AL-31","Encoder cable disconnection","Check whether the encoder cable is disconnected. ",0));
    _alarmTable->insert("32",new alarm("Encoder data error ","AL-32","Encoder data error ","Check the encoder settings and wiring. ",0));
    _alarmTable->insert("33",new alarm("Motor setting error ","AL-33","Motor ID setting error ","Replace the encoder. ",0));
    _alarmTable->insert("35",new alarm("Low Battery Error ","AL-35","Low voltage error ","Low voltage of Back Up battery, when Absolute encoder is applied. ※Reset the operation after changing battery. (Applied after S/W Ver 1.3)  ",0));
    _alarmTable->insert("40",new alarm("Under voltage ","AL-40","Low voltage ","Check input voltage and power unit wiring. ",0));
    _alarmTable->insert("41",new alarm("Overvoltage ","AL-41","Overvoltage","Check the input voltage and wiring. Check the braking resistance for damage. Check for excessive regenerative operation. Check the regenerative resistance. ",0));
    _alarmTable->insert("42",new alarm("RST power fail ","AL-42","Main power failure ","Check the power unit wiring and power supply. ",0));
    _alarmTable->insert("43",new alarm("Control power fail ","AL-43","Control power failure ","Check the power unit wiring and power supply. ",0));
    _alarmTable->insert("50",new alarm("Over speed limit","AL-50","Overspeed ","Check the encoder, encoder settings, encoder wiring, gain settings, motor wiring, motor ID, electric gear ratio, and speed command scale. ",0));
    _alarmTable->insert("51",new alarm("Position following ","AL-51","Excessive position error ","Check the Following Error Window [0x6065], wiring and limit contacts, gain setting values, encoder settings, and electric gear ratio settings. Check the load on the equipment and whether there is binding on the equipment. ",0));
    _alarmTable->insert("54",new alarm("Encoder Position Difference","AL-54","Difference between 2 encoders ","Check value of difference between internal and external encoder or external encoder when Full-Closed control ",0));
    _alarmTable->insert("65",new alarm("EtherCAT Comm.Err1","AL-65","EtherCAT communication malfunction ","Check the CN3 and CN4 connectors and the EtherCAT communication cable. Replace the drive. ",0));
    _alarmTable->insert("66",new alarm("EtherCAT Comm.Err2","AL-66","EtherCAT communication malfunction","Check the encoder settings and wiring.",0));
    _alarmTable->insert("67",new alarm("EtherCAT Comm.Err3","AL-67","EtherCAT communication malfunction","Check the encoder settings and wiring.",0));
    _alarmTable->insert("71",new alarm("nvalid factory setting","AL-71","Invalid factory settings ","Restore the default parameters [0x1011]. ",0));
    _alarmTable->insert("72",new alarm("GPIO setting","AL-72","Output contact point setting error","Restore the default parameters [0x1011]. ",0));
}

QString Controller::GeneralRobotStatus()
{
    return _general_robot_status;
}

void Controller::SetGeneralRobotStatus(QString value)
{
    _general_robot_status = value;
}

bool Controller::IsJoint()
{
    return _is_joint;
}

void Controller::setIsJoint(bool val)
{
    _is_joint = val;
}

alarm* Controller::getAlarm(QString key){

    if(_alarmTable->contains(key)){
        alarm* tempAlarm = new alarm(_alarmTable->value(key)->name(),_alarmTable->value(key)->key(),_alarmTable->value(key)->detail(),
                                     _alarmTable->value(key)->check(),_alarmTable->value(key)->type());
        return tempAlarm;
    }
    return nullptr;
}

