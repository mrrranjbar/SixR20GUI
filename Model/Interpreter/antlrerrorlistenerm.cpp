#include "antlrerrorlistenerm.h"

AntlrErrorListenerM::AntlrErrorListenerM()
{

}

void AntlrErrorListenerM::syntaxError(antlr4::Recognizer *recognizer, antlr4::Token *offendingSymbol, size_t line, size_t charPositionInLine, const string &msg, __exception_ptr::exception_ptr e)
{
    syntaxErrors.push_back(*new mSyntaxError(recognizer, offendingSymbol, line, charPositionInLine, msg, e));
}

void AntlrErrorListenerM::reportAmbiguity(Parser *recognizer, const dfa::DFA &dfa, size_t startIndex, size_t stopIndex, bool exact, const antlrcpp::BitSet &ambigAlts, atn::ATNConfigSet *configs)
{
    syntaxAmbiguity.push_back(*new mSyntaxAmbiguity(recognizer, startIndex, stopIndex, exact, configs));
}

void AntlrErrorListenerM::reportAttemptingFullContext(Parser *recognizer, const dfa::DFA &dfa, size_t startIndex, size_t stopIndex, const antlrcpp::BitSet &conflictingAlts, atn::ATNConfigSet *configs)
{

}

void AntlrErrorListenerM::reportContextSensitivity(Parser *recognizer, const dfa::DFA &dfa, size_t startIndex, size_t stopIndex, size_t prediction, atn::ATNConfigSet *configs)
{

}

vector<mSyntaxError> AntlrErrorListenerM::getSyntaxErrors()
{
    return syntaxErrors;
}
