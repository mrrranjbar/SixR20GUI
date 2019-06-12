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


    // read Frames.xml File Data

    /*QString x,y,z,a,b,c="";
    QString frameName="";
    QFile file("frames.xml");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        exit(0);
    }

    QXmlStreamReader reader(&file);

    qDebug(qPrintable("count:"+reader.lineNumber()));

            while(reader.readNextStartElement()){

                frameName=reader.name().toString();
                //*****************************
                reader.readNextStartElement();
                x = reader.readElementText();
                //*****************************
                reader.readNextStartElement();
                y = reader.readElementText();
                //*****************************
                reader.readNextStartElement();
                z = reader.readElementText();
                //*****************************
                reader.readNextStartElement();
                a = reader.readElementText();
                //*****************************
                reader.readNextStartElement();
                b = reader.readElementText();
                //*****************************
                reader.readNextStartElement();
                c = reader.readElementText();


                qDebug(qPrintable(frameName+":"+"X:"+x+"_Y:"+y+"_Z:"+z+"_A:"+a+"_B:"+b+"_C:"+c));

            }*/



    //******************************************************************
    //******************************************************************


    /*QDomDocument xmlBOM;
    // Load xml file as raw data
    QFile f("simple2.xml");
    if (!f.open(QIODevice::ReadOnly ))
    {
        // Error while loading file
        std::cerr << "Error while loading file" << std::endl;
        //return 1;
    }
    // Set data into the QDomDocument before processing
    xmlBOM.setContent(&f);
    f.close();

    // Extract the root markup
    QDomElement root=xmlBOM.documentElement();

    // Get root names and attributes
    QString Type=root.tagName();
    QString Board=root.attribute("BOARD","No name");
    int Year=root.attribute("YEAR","1900").toInt();

    // Display root data
    std::cout << "Type  = " << Type.toStdString().c_str() << std::endl;
    std::cout << "Board = " << Board.toStdString().c_str() << std::endl;
    std::cout << "Year  = " << Year << std::endl;
    std::cout << std::endl;

    // Get the first child of the root (Markup COMPONENT is expected)
    QDomElement Component=root.firstChild().toElement();

    // Loop while there is a child
    while(!Component.isNull())
    {
        // Check if the child tag name is COMPONENT
        if (Component.tagName()=="COMPONENT")
        {

            // Read and display the component ID
            QString ID=Component.attribute("ID","No ID");

            // Get the first child of the component
            QDomElement Child=Component.firstChild().toElement();

            QString Name;
            double Value;

            // Read each child of the component node
            while (!Child.isNull())
            {
                // Read Name and value
                if (Child.tagName()=="NAME") Name=Child.firstChild().toText().data();
                if (Child.tagName()=="VALUE") Value=Child.firstChild().toText().data().toDouble();

                // Next child
                Child = Child.nextSibling().toElement();
            }

            // Display component data
            std::cout << "Component " << ID.toStdString().c_str() << std::endl;
            std::cout << "   Name  = " << Name.toStdString().c_str() << std::endl;
            std::cout << "   Value = " << Value << std::endl;
            std::cout << std::endl;
        }

        // Next component
        Component = Component.nextSibling().toElement();
    }*/


    /* QString x,y,z,a,b,c="";
    QString frameName="";
    QDomDocument xmlBOM;
    // Load xml file as raw data
    QFile f("frames.xml");
    if (!f.open(QIODevice::ReadOnly ))
    {
        // Error while loading file
        std::cerr << "Error while loading file" << std::endl;
        //return 1;
    }
    // Set data into the QDomDocument before processing
    xmlBOM.setContent(&f);
    f.close();

    // Extract the root markup
    QDomElement root=xmlBOM.documentElement();

    while(!root.isNull())
    {
        frameName=root.tagName();
        QDomElement Component=root.firstChild().toElement();
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
        root = root.nextSibling().toElement();
    }*/




    /*
    QString x,y,z,a,b,c="";
    QString frameName="";
    QDomDocument xmlBOM;
    // Load xml file as raw data
    QFile f("frames2.xml");
    if (!f.open(QIODevice::ReadOnly ))
    {
        // Error while loading file
        std::cerr << "Error while loading file" << std::endl;
        //return 1;
    }
    // Set data into the QDomDocument before processing
    xmlBOM.setContent(&f);
    f.close();

    // Extract the root markup
    QDomElement root=xmlBOM.documentElement();

    while(!root.isNull())
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
    }
*/

}

void scoordinatesviewmodel::saveFrame(QString oldName,QString newName,QString frameType,QString frameMethod,QString teachedFrameType,QString x,QString y,QString z,QString a,QString b,QString c)
{

    //**************************************
    // MainPoints Should Be Calculated With Function
    QList<double> exampleList = {0,0,0,0,0,0};
    //**************************************


    for(int i=0;i<Controller::getInstance()->framesList.length();i++)
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

            controller->framesList.removeAt(i);
            controller->framesList.push_back(temp);
        }
    }

    writeListToFile();

    controller->Initialize();


    /*QString frameName="";
    QDomDocument xmlBOM;
    // Load xml file as raw data
    QFile f("frames2.xml");
    if (!f.open(QIODevice::ReadOnly))
    {
        // Error while loading file
        std::cerr << "Error while loading file" << std::endl;
        //return 1;
    }
    xmlBOM.setContent(&f);
    QDomElement root=xmlBOM.documentElement();

    QDomElement child=xmlBOM.createElement(name);
    QDomElement tag = xmlBOM.createElement("X");
    child.appendChild(tag);
    QDomText txt = xmlBOM.createTextNode(x);
    tag.appendChild(txt);
    tag = xmlBOM.createElement("Y");
    child.appendChild(tag);
    txt=xmlBOM.createTextNode(y);
    tag.appendChild(txt);
    tag = xmlBOM.createElement("Z");
    child.appendChild(tag);
    txt=xmlBOM.createTextNode(z);
    tag.appendChild(txt);
    tag = xmlBOM.createElement("A");
    child.appendChild(tag);
    txt=xmlBOM.createTextNode(a);
    tag.appendChild(txt);
    tag = xmlBOM.createElement("B");
    child.appendChild(tag);
    txt=xmlBOM.createTextNode(b);
    tag.appendChild(txt);
    tag = xmlBOM.createElement("C");
    child.appendChild(tag);
    txt=xmlBOM.createTextNode(c);
    tag.appendChild(txt);

    root.appendChild(child);

    // save to file
    QFile f1("frames3.xml");
    f1.open(QIODevice::WriteOnly | QFile::Text);
    QTextStream output (&f1);
    output << xmlBOM.toString();*/




}

void scoordinatesviewmodel::readFrame()
{

    /*QFile file("simple.xml");
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        //qDebug() << "Cannot read file" << file.errorString();
        exit(0);
    }

    QXmlStreamReader reader(&file);

    if (reader.readNextStartElement()) {
        if (reader.name() == "root"){
            while(reader.readNextStartElement()){
                if(reader.name() == "childA"){
                    QString s = reader.readElementText();
                    qDebug(qPrintable(s));
                }
                else
                    reader.skipCurrentElement();
            }
        }
        else
            reader.raiseError(QObject::tr("Incorrect file"));
    }*/


}



//*****************************************************
//*****************************************************


void scoordinatesviewmodel::createBtn()
{

    QList<double> exampleList = {0,0,0,0,0,0};

    QString type="all",
            tempName="",
            threePointsStatus="100",
            method="3-point",
            TeachedFrameName="TeachedFrameName",
            TeachedFrameType="TeachedFrameType";
    bool savedStatus=false,iscurrentStatus=false;


    //**********************************************
    // Create New Name

    frame *f = dynamic_cast<frame *>(controller->framesList.at(Controller::getInstance()->framesList.length()-1));
    int oldIndex=f->frameIndex().toInt();
    oldIndex+=1;

    tempName="frame"+QString::number(oldIndex);
    //**********************************************


    Controller::getInstance()->framesList.push_back(new frame(QString::number(oldIndex),type,tempName,savedStatus,iscurrentStatus,exampleList,threePointsStatus,exampleList,"",exampleList,"",exampleList,"",method,TeachedFrameName,TeachedFrameType));
    controller->ctxt->setContextProperty("SCoordinateModel", QVariant::fromValue( Controller::getInstance()->framesList));


    writeListToFile();


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
            controller->framesList.removeAt(i);
        }
    }
    controller->ctxt->setContextProperty("SCoordinateModel", QVariant::fromValue( Controller::getInstance()->framesList));


    writeListToFile();
}

//*****************************************************
//*****************************************************

void scoordinatesviewmodel::modifyBtn(QString frameName)
{
    for(int i=0;i<Controller::getInstance()->framesList.length();i++)
    {
        frame *temp= dynamic_cast<frame*>(controller->framesList.at(i));

        //***************************************************
        // Set Current Frame Status To False
        if(temp->name()==frameName)
        {
            temp->setSaved(false);
            temp->setThreePointsStatus("100");
            controller->framesList.removeAt(i);
            controller->framesList.push_back(temp);
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

    file.open(QIODevice::WriteOnly);
    xmlWriter.setAutoFormatting(true);

    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("Frames");


    for(int i=0;i<Controller::getInstance()->framesList.length();i++)
    {
        frame *f = dynamic_cast<frame *>(controller->framesList.at(i));
        xmlWriter.writeStartElement(f->name());
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

void scoordinatesviewmodel::setCurrentBtn(QString frameName, QString frameType)
{
    for(int i=0;i<Controller::getInstance()->framesList.length();i++)
    {
        frame *temp= dynamic_cast<frame*>(controller->framesList.at(i));

        //***************************************************
        // Set Current Frame Status To False
        if(frameType==temp->type()&&temp->name()!=frameName)
        {
            temp->setIscurrent(false);
            controller->framesList.removeAt(i);
            controller->framesList.push_front(temp);
        }
        //***************************************************

        if(temp->name()==frameName)
        {
            temp->setIscurrent(true);
            controller->framesList.removeAt(i);
            controller->framesList.push_front(temp);

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

    qDebug(qPrintable("World:"+controller->robot->currentWorldFrame->name()));
    qDebug(qPrintable("object:"+controller->robot->currentObjectFrame->name()));
    qDebug(qPrintable("task:"+controller->robot->currentTaskFrame->name()));
    qDebug(qPrintable("tool:"+controller->robot->currentToolFrame->name()));
    qDebug(qPrintable("base:"+controller->robot->currentBaseFrame->name()));

    writeListToFile();

    controller->Initialize();
}


//*****************************************************
//*****************************************************

void scoordinatesviewmodel::point1Btn(QString frameName)
{
    for(int i=0;i<Controller::getInstance()->framesList.length();i++)
    {
        frame *temp= dynamic_cast<frame*>(controller->framesList.at(i));

        //***************************************************
        // Set Current Frame Status To False
        if(temp->name()==frameName)
        {
            temp->setP1Point(controller->beckhoff->actualPositions);
            temp->setP1frameName(controller->robot->jogTempFrame->name());
            temp->setThreePointsStatus("110");
            controller->framesList.removeAt(i);
            controller->framesList.push_front(temp);
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
    for(int i=0;i<Controller::getInstance()->framesList.length();i++)
    {
        frame *temp= dynamic_cast<frame*>(controller->framesList.at(i));

        //***************************************************
        // Set Current Frame Status To False
        if(temp->name()==frameName)
        {
            temp->setP2Point(controller->beckhoff->actualPositions);
            temp->setP2frameName(controller->robot->jogTempFrame->name());
            temp->setThreePointsStatus("111");
            controller->framesList.removeAt(i);
            controller->framesList.push_front(temp);
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
    for(int i=0;i<Controller::getInstance()->framesList.length();i++)
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


            controller->framesList.removeAt(i);
            controller->framesList.push_front(temp);
        }
        //***************************************************
    }

    writeListToFile();

    controller->Initialize();
}


//*****************************************************
//*****************************************************

/*void scoordinatesviewmodel::saveBtn()
{
    QFile file("frames.xml");
    QXmlStreamWriter xmlWriter(&file);


    if(file.exists())
    {
        file.open(QIODevice::Append);
        xmlWriter.setAutoFormatting(true);
    }

    file.open(QIODevice::WriteOnly);



    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("Frames");

    xmlWriter.writeStartElement(name);
    xmlWriter.writeTextElement("X", x );
    xmlWriter.writeTextElement("Y", y);
    xmlWriter.writeTextElement("Z", z);
    xmlWriter.writeTextElement("A", a);
    xmlWriter.writeTextElement("B", b);
    xmlWriter.writeTextElement("C", c);

    xmlWriter.writeEndElement();

    xmlWriter.writeEndElement();

    file.close();
}*/
