#ifndef ANTLRERRORLISTENERM_H
#define ANTLRERRORLISTENERM_H
#pragma once
#include "antlr4-runtime.h"
#include "vector"
using namespace::std;
using namespace antlr4;
//using namespace antlrcpp;
class mSyntaxAmbiguity{
private:
    Parser *recognizer;
    //dfa::DFA &dfa;
    size_t startIndex;
    size_t stopIndex;
    bool exact;
    //antlrcpp::BitSet &ambigAlts;
    atn::ATNConfigSet *configs;
public:
    mSyntaxAmbiguity(antlr4::Parser *recognizer, size_t startIndex, size_t stopIndex, bool exact,
                     antlr4::atn::ATNConfigSet *configs){
        this->recognizer = recognizer;
        this->startIndex = startIndex;
        this->stopIndex = stopIndex;
        this->exact = exact;
        this->configs = configs;
    }
//    mSyntaxAmbiguity(antlr4::Parser *recognizer, const antlr4::dfa::DFA &_dfa, size_t startIndex, size_t stopIndex, bool exact,
//                     const antlrcpp::BitSet &_ambigAlts, antlr4::atn::ATNConfigSet *configs):dfa(_dfa),ambigAlts(_ambigAlts){
//        this->recognizer = recognizer;
//        //this->dfa1=new dfa::DFA(dfa);
//        this->startIndex = startIndex;
//        this->stopIndex = stopIndex;
//        this->exact = exact;
//        //this->ambigAlts = ambigAlts;
//        this->configs = configs;
//    }
};

class mSyntaxError{
private:
    antlr4::Recognizer *recognizer;
    antlr4::Token *offendingSymbol;
    std::string msg;
    //const std::string &msg;
    std::exception_ptr e;
public:
    mSyntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
                 size_t charPositionInLine, const std::string &_msg, std::exception_ptr e){
        this->recognizer = recognizer;
        this->offendingSymbol= offendingSymbol;
        this->line = line;
        this->charPositionInLine = charPositionInLine;
        this->msg = msg.data();
        this-> e = e;
    }
    size_t line;
    size_t charPositionInLine;
//    mSyntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line,
//                 size_t charPositionInLine, const std::string &_msg, std::exception_ptr e):msg(_msg){
//        this->recognizer = recognizer;
//        this->offendingSymbol= offendingSymbol;
//        this->line = line;
//        this->charPositionInLine = charPositionInLine;
//        //this->msg = msg;
//        this-> e = e;
//    }
};

class AntlrErrorListenerM : public ANTLRErrorListener
{
private:
    vector<mSyntaxError> syntaxErrors;
    vector<mSyntaxAmbiguity> syntaxAmbiguity;
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
    vector<mSyntaxError> getSyntaxErrors();
};

#endif // ANTLRERRORLISTENERM_H
