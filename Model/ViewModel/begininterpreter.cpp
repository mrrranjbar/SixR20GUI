#include "begininterpreter.h"
#include <QDebug>
#include <string>
#include <iostream>
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

void BeginInterpreter::load(string addr){//}, InterpreterViewModel parent){
    listener.clearAllDefines();
    addGlobalVariableToListener();
    //    loadToLines(addr);
    //    return;
    std::ifstream stream;
    stream.open(addr);
    //    std::ifstream streamPoints;
    //    streamPoints.open("points.txt");
    //    std::ofstream combined_file( "combined_file.txt" ) ;
    //    combined_file << streamPoints.rdbuf() << stream.rdbuf();
    //    combined_file.close();
    //    stream.open("combined_file.txt");
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
    //add inputs
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
    controller->ctxt->setContextProperty("myTeachPointModel", QVariant::fromValue(teachPoints));
    controller->ctxt->setContextProperty("myTeachFrameModel", QVariant::fromValue(teachFrames));
//    controller->ctxt->setContextProperty("comboModel", &combo);
}

