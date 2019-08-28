#ifndef ANTLRERRORLISTENERM_H
#define ANTLRERRORLISTENERM_H
#pragma once
#include "antlr4-runtime.h"
#include "vector"
using namespace::std;
using namespace antlr4;
//using namespace antlrcpp;
class mSyntaxError{
private:
    antlr4::Recognizer *recognizer;
    antlr4::Token *offendingSymbol;
    size_t line;
    size_t charPositionInLine;
    std::string msg;
    std::exception_ptr e;
public:
    mSyntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
                 size_t charPositionInLine, std::string msg, std::exception_ptr e){
        this->recognizer = recognizer;
        this->offendingSymbol= offendingSymbol;
        this->line = line;
        this->charPositionInLine = charPositionInLine;
        this->msg = msg;
        this-> e = e;
    }
};

class AntlrErrorListenerM : public ANTLRErrorListener
{
private:
    vector<mSyntaxError> syntaxErrors;
public:
    AntlrErrorListenerM();
    void syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
                     size_t charPositionInLine, const std::string &msg, std::exception_ptr e);
    void reportAmbiguity(antlr4::Parser *recognizer, const antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex, bool exact,
                         const antlrcpp::BitSet &ambigAlts, antlr4::atn::ATNConfigSet *configs);
    void reportAttemptingFullContext(antlr4::Parser *recognizer, const antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
                                     const antlrcpp::BitSet &conflictingAlts, antlr4::atn::ATNConfigSet *configs);
    void reportContextSensitivity(antlr4::Parser *recognizer, const antlr4::dfa::DFA &dfa, size_t startIndex, size_t stopIndex,
                                  size_t prediction, antlr4::atn::ATNConfigSet *configs);
    vector<mSyntaxError> getSyntaxErrors(){
        return syntaxErrors;
    }
};

#endif // ANTLRERRORLISTENERM_H
