#include "scoordinatesviewmodel.h"
#include <QFile>
#include <QFileInfo>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QDomDocument>
#include <QtXml>
#include <iostream>

using namespace std;


scoordinatesviewmodel::scoordinatesviewmodel(QObject *parent) : QObject(parent)
{

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


}

void scoordinatesviewmodel::saveFrame(int id, QString name, QString x, QString y, QString z, QString a, QString b, QString c)
{


    /*QFile file("frames2.xml");
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

    file.close();*/

    QString frameName="";
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
    output << xmlBOM.toString();



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
