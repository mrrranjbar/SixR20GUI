#ifndef ANTLRMAIN_H
#define ANTLRMAIN_H

#include "Model/Interpreter/antlr4-runtime.h"
#include "Model/Interpreter/SixRGrammerLexer.h"
#include "Model/Interpreter/SixRGrammerParser.h"
#include "Model/Interpreter/SixRGrammerBaseListener.h"
#include "Model/Interpreter/include/antlr4-runtime/ANTLRInputStream.h"
#include "Model/Interpreter/include/antlr4-runtime/CommonTokenStream.h"
#include "Model/Interpreter/include/antlr4-runtime/tree/ParseTree.h"
#include "Model/Interpreter/msixrlistener.h"
using namespace std;
using namespace antlr4;
#include <QThread>


class AntlrMain/*: public QThread*/
{

public:
    std::ifstream stream;
    string _addresspath="/home/fumrobotics/Documents/QtProjects/SixR20_210298/SixR20_git210298/SixR20_git/Model/Interpreter/text.txt";
    //stream.open(_addresspath);
    ANTLRInputStream input;
     SixRGrammerLexer* lexer;
     CommonTokenStream* token;
     SixRGrammerParser* parser;
     tree::ParseTree *mtree;
    AntlrMain();
    void Start();
    //void run();
};

#endif // ANTLRMAIN_H
