#ifndef BEGININTERPRETER_H
#define BEGININTERPRETER_H

#include "Model/Interpreter/antlr4-runtime.h"
#include "Model/Interpreter/SixRGrammerLexer.h"
#include "Model/Interpreter/SixRGrammerParser.h"
#include "Model/Interpreter/SixRGrammerBaseListener.h"
#include "Model/Interpreter/include/antlr4-runtime/ANTLRInputStream.h"
#include "Model/Interpreter/include/antlr4-runtime/CommonTokenStream.h"
#include "Model/Interpreter/include/antlr4-runtime/tree/ParseTree.h"
#include "Model/Interpreter/msixrlistener.h"
#include "Model/ViewModel/points.h"
#include "Model/Interpreter/antlrerrorlistenerm.h"
#include <QObject>
//#include <boost/signal.hpp>
//#include <boost/bind.hpp>
//#include <iostream>

//using namespace boost;
using namespace std;


using namespace antlr4;

class BeginInterpreter : public QObject
{
    Q_OBJECT
public:
    explicit BeginInterpreter(QObject *parent = nullptr);
    ANTLRInputStream input;
    SixRGrammerLexer* lexer;
    CommonTokenStream* token;
    SixRGrammerParser* parser;
    tree::ParseTree *mtree;
    MsixRlistener listener;
    Controller *controller;
    int getCurrentLine();
    vector<string> lines;

    void addGlobalVariableToListener();
    QString load(string addr);//, InterpreterViewModel parent);//std::ifstream stream);
    void parseLine(int lineNumber);
    void loadToLines(string addr);
    string getTeachPoints();
private:
    int _lastLineNumner=-1;
    void newLine(int newLine);

Q_SIGNALS:
    void newLineGUI(int newLine);

public Q_SLOTS:
    void begin();
    //void newLine(int newLine);
};

#endif // BEGININTERPRETER_H
