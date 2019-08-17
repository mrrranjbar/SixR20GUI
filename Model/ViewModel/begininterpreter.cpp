#include "begininterpreter.h"
//#include <iostream>
//#include <iomanip>


//#include <QThread>
BeginInterpreter::BeginInterpreter(QObject *parent) : QObject(parent)
{
    controller = Controller::getInstance();
}

void BeginInterpreter::loadToLines(string addr){
    std::ifstream stream;
    stream.open(addr);
    string s;
    while (getline(stream, s))
    {
        lines.push_back(s);
    }
}

void BeginInterpreter::parseLine(int lineNumber){
    stringstream  ss;
    ss<<lines.at(lineNumber);
    input = ANTLRInputStream(ss);
    lexer = new SixRGrammerLexer(&input);
    token = new CommonTokenStream((TokenSource*)lexer);
    parser = new SixRGrammerParser(token);
    mtree = parser->start();
    tree::ParseTreeWalker::DEFAULT.walk(&listener,mtree);
}

void BeginInterpreter::load(string addr){//}, InterpreterViewModel parent){
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
    input = ANTLRInputStream(stream);
    lexer = new SixRGrammerLexer(&input);
    token = new CommonTokenStream((TokenSource*)lexer);
    parser = new SixRGrammerParser(token);
    mtree = parser->start();
}
string BeginInterpreter::getTeachPoints(){
    string pointss="";
//    for (int i = 0;i < controller->dataList.length();i++) {
//        points *p = dynamic_cast<points*>(controller->dataList.at(i));
//        QList<double> lis = p->getPoints();
//        pointss<<"[";
//        for(int i=0; i<lis.count()-1; i++){
//            pointss <<"j"<<i<<":"<<lis[i]<<",";
//        }
//         pointss <<"j"<<i<<":"<<lis[lis.count()-1];
//        pointss<<"]";
//    }
    return pointss;
}
void BeginInterpreter::begin()
{
    //    while(1){
    //        QThread::msleep(10);
    //    }

    listener.currentLine=0;
    tree::ParseTreeWalker::DEFAULT.walk(&listener,mtree);
}

int BeginInterpreter::getCurrentLine()
{
    return listener.currentLine;
}

