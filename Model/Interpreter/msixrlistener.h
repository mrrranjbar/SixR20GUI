#ifndef MSIXRPARSER_H
#define MSIXRPARSER_H
#include "SixRGrammerParser.h"
#include "SixRGrammerBaseListener.h"
#include "variable.h"

class MsixRlistener: public SixRGrammerBaseListener
{

public:
    MsixRlistener();
    void enterStart(SixRGrammerParser::StartContext * ctx);
    void enterModuleRoutines(SixRGrammerParser::ModuleRoutinesContext * ctx);
    void enterVariableDeclaration(SixRGrammerParser::VariableDeclarationContext *ctx);
    void enterMainRoutine(SixRGrammerParser::MainRoutineContext *ctx);
    void enterStatementList(SixRGrammerParser::StatementListContext *ctx);
    void enterSubRoutine(SixRGrammerParser::SubRoutineContext *ctx);
    void enterRoutineBody(SixRGrammerParser::RoutineBodyContext *ctx);
    void enterSTATPTP(SixRGrammerParser::STATPTPContext *ctx);
    //void enterFormalParameters(SixRGrammerParser::FormalParametersContext *ctx);
private:
   vector<Variable> parameter;
};


#endif // MSIXRPARSER_H

