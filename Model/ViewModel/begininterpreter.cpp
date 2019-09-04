#include "begininterpreter.h"



//#include <QThread>
BeginInterpreter::BeginInterpreter(QObject *parent) : QObject(parent)
{
//    stream.open(_addresspath);
//    input = ANTLRInputStream(stream);
//    lexer = new SixRGrammerLexer(&input);
//    token = new CommonTokenStream((TokenSource*)lexer);
//    parser = new SixRGrammerParser(token);
//    mtree = parser->start();
}
void BeginInterpreter::load(string addr){//}, InterpreterViewModel parent){
    std::ifstream stream;
    stream.open(addr);
    input = ANTLRInputStream(stream);
    lexer = new SixRGrammerLexer(&input);
    token = new CommonTokenStream((TokenSource*)lexer);
    parser = new SixRGrammerParser(token);    
    mtree = parser->start();
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

