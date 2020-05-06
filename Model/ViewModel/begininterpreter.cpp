#include "begininterpreter.h"
#include <QDebug>
#include <string>
#include <iostream>
#include <fstream>
#include <streambuf>
#include "Model/Interpreter/antlrerrorlistenerm.h"
//#include <iostream>
//#include <iomanip>

//#include <QThread>

//#include <QApplication>
#include <QQmlApplicationEngine>
//#include <qqmlengine.h>
//#include <qqmlcontext.h>
//#include <qqml.h>
#include <QStringList>

#include "comboboxmodel.h"
BeginInterpreter::BeginInterpreter(QObject *parent) : QObject(parent)
{
    controller = Controller::getInstance();
    listener.clearAllDefines();
    addGlobalVariableToListener();
    //listener.newLineEvent.connect(bind(&BeginInterpreter::newLine, this));
    //connect(&listener, SIGNAL(newLine(int)),SLOT(newLine(int)));
    //connect(&listener, SIGNAL(newLine(int)),this, SLOT(newLine(int)));
    //connect(&listener,&MsixRlistener::newLine,this, &BeginInterpreter::newLine);
    //connect(&listener,SIGNAL( newLine(int)), this, SLOT(newLine(int)));
}

//void BeginInterpreter::loadToLines(string addr){
//    std::ifstream stream;
//    stream.open(addr);
//    string s;
//    while (getline(stream, s))
//    {
//        lines.push_back(s);
//    }
//}

//void BeginInterpreter::parseLine(int lineNumber){
//    stringstream  ss;
//    ss<<lines.at(lineNumber);
//    input = ANTLRInputStream(ss);
//    lexer = new SixRGrammerLexer(&input);
//    token = new CommonTokenStream((TokenSource*)lexer);
//    parser = new SixRGrammerParser(token);
//    mtree = parser->start();
//    tree::ParseTreeWalker::DEFAULT.walk(&listener,mtree);
//}

QString BeginInterpreter::load(string addr){//}, InterpreterViewModel parent){
    listener.clearAllDefines();
    addGlobalVariableToListener();
    //    loadToLines(addr);
    //    return;
    std::ifstream stream;
    stream.open(addr);
    AntlrErrorListenerM syntaxErrorListener;
    AntlrErrorListenerM lexerErrorListener;

    input = ANTLRInputStream(stream);
    lexer = new SixRGrammerLexer(&input);
    token = new CommonTokenStream((TokenSource*)lexer);
    parser = new SixRGrammerParser(token);
    lexer->addErrorListener(&syntaxErrorListener);
    parser->addErrorListener(&syntaxErrorListener);
    mtree = parser->start();
    auto lexerErrorList = lexerErrorListener.getSyntaxErrors();
    auto syntaxErrorList = syntaxErrorListener.getSyntaxErrors();
    QString errors;
    for(int i=0; i< syntaxErrorList.size();i++)
    {
        errors+=(QString::fromStdString("Syntax Error: Line " + to_string(syntaxErrorList.at(i).line) +" ,Character "+ to_string(syntaxErrorList.at(i).charPositionInLine) +" has error!\n" ));
    }
    return errors;
}
//string BeginInterpreter::getTeachPoints(){
//    string pointss="";
//    //    for (int i = 0;i < controller->dataList.length();i++) {
//    //        points *p = dynamic_cast<points*>(controller->dataList.at(i));
//    //        QList<double> lis = p->getPoints();
//    //        pointss<<"[";
//    //        for(int i=0; i<lis.count()-1; i++){
//    //            pointss <<"j"<<i<<":"<<lis[i]<<",";
//    //        }
//    //         pointss <<"j"<<i<<":"<<lis[lis.count()-1];
//    //        pointss<<"]";
//    //    }
//    return pointss;
//}
void BeginInterpreter::begin()
{
    //    while(1){
    //        QThread::msleep(10);
    //    }

    listener.currentLine=0;
    try {
        tree::ParseTreeWalker::DEFAULT.walk(&listener,mtree); // start of msixrlistener.cpp => constructor => enterModuleRoutines

    } catch (const std::exception& ex) {
        cout<<"Error: "<<ex.what()<<endl;
    } catch (const std::string& ex) {
        cout<<"Error: "<<ex.c_str()<<endl;
    } catch (...) {
        cout<<"Unknown Error"<<endl;
    }
}

void BeginInterpreter::newLine(int newLine)
{
    if(newLine != _lastLineNumner){
        _lastLineNumner = newLine;
        newLineGUI(_lastLineNumner);
    }
}

int BeginInterpreter::getCurrentLine()
{
    return listener.currentLine;
}

void BeginInterpreter::addGlobalVariableToListener()
{
    //add io
    Variable DIO;
    DIO.name = listener.output;
    DIO.type = "BOOL";
    vector<double> init;
    for(int i=0; i<16; i++)
        init.push_back(0);
    DIO.setData(init);
    listener.addPointToGlobal(DIO);
    DIO.name = listener.input;
    listener.addPointToGlobal(DIO);

    //add ConfJ
    Variable ConfJ;
    ConfJ.name = listener.confJ;
    ConfJ.type = "BOOL";
    vector<double> init1;
    init1.push_back(0);
    ConfJ.setData(init1);
    listener.addPointToGlobal(ConfJ);

    //add ConfData
    Variable ConfData;
    ConfData.name = listener.confData;
    ConfData.type = "INT";
    vector<double> init2;
    init2.push_back(0);
    ConfData.setData(init2);
    ConfData.setData(init2);
    listener.addPointToGlobal(ConfData);

    //add SingulPTP
    Variable SingulPTP;
    SingulPTP.name = listener.singulPTP;
    SingulPTP.type = "BOOL";
    vector<double> init3;
    init3.push_back(0);
    SingulPTP.setData(init3);
    SingulPTP.setData(init3);
    listener.addPointToGlobal(SingulPTP);


    //add SingulCP
    Variable SingulCP;
    SingulCP.name = listener.singulCP;
    SingulCP.type = "BOOL";
    vector<double> init4;
    init4.push_back(0);
    SingulCP.setData(init4);
    SingulCP.setData(init4);
    listener.addPointToGlobal(SingulCP);

    //add teach point
    QStringList teachPoints;
    for(int i=0; i<controller->dataList.size(); i++){
        points *p = dynamic_cast<points*>(controller->dataList.at(i));
        Variable variable;
        variable.name = p->getName().toUtf8().constData();
        variable.type = p->getType().toUtf8().constData();
        variable.setData(p->getPoints().toVector().toStdVector());
        listener.addPointToGlobal(variable);
        teachPoints.append(p->getName());
    }
    //add teach frame
    QStringList teachFrames;
    for(int i=0; i<controller->framesList.size(); i++){
        frame *p = dynamic_cast<frame*>(controller->framesList.at(i));
        Variable variable;
        variable.name = p->name().toUtf8().constData();
        variable.type = "POINTP";
        variable.setData(p->mainPoints().toVector().toStdVector());
        listener.addPointToGlobal(variable);
        teachFrames.append(p->name());
    }
    QQmlApplicationEngine engine;
    ComboBoxModel comboPoint;
    comboPoint.setComboList(teachPoints);
    //MNR??!
//    controller->ctxt->setContextProperty("myTeachPointModel", QVariant::fromValue(teachPoints));
//    controller->ctxt->setContextProperty("myTeachFrameModel", QVariant::fromValue(teachFrames));
////    controller->ctxt->setContextProperty("comboModel", &combo);
}

