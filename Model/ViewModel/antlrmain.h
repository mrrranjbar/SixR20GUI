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


class AntlrMain
{
public:
    AntlrMain();
    void Start();
};

#endif // ANTLRMAIN_H
