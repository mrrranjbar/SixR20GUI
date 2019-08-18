#ifndef MSIXRPARSER_H
#define MSIXRPARSER_H
#include "SixRGrammerParser.h"
#include "SixRGrammerBaseListener.h"
#include "variable.h"
#include "Model/Controller/controller.h"
#include <map>
#include "subroutine.h"

class MsixRlistener: public SixRGrammerBaseListener
{
public:
    MsixRlistener();
    int currentLine=0;
    Subroutine global;
    Subroutine main;
    void enterStart(SixRGrammerParser::StartContext * ctx);
    void enterModuleRoutines(SixRGrammerParser::ModuleRoutinesContext * ctx);
    void exitModuleRoutines(SixRGrammerParser::ModuleRoutinesContext * ctx);

    void _checkRobotStat();
    void _sendCommandToRobot(int command, map<string, Variable> parameters);
    //Robot Commands
    enum ControlManager{
        PTP=8,
        LIN=16,
        CIR=32,
        SetFrame=64,
        ClearAlarm=99,
        GoHome=0,
        NOP = 100
    };

private:
    Controller *controller;
    vector<Subroutine*> subroutines;
    //map<string, vector<Variable*>> variables;

    void _enterMainRoutine(SixRGrammerParser::MainRoutineContext *ctx); // OK
    void _enterSubroutineDeclartion(SixRGrammerParser::SubRoutineContext *ctx);
    void _enterVariableDeclaration(SixRGrammerParser::VariableDeclarationContext *ctx,Subroutine *nameSpace);    // OK --> PostControl

    void _enterRoutineBody(SixRGrammerParser::RoutineBodyContext *ctx); // NOT implemented

    int _enterStatementList(SixRGrammerParser::StatementListContext *ctx, Subroutine *nameSpace, string currentScope="");

    //Statements
    void _enterStateFor(SixRGrammerParser::STATFORContext *ctx, Subroutine *nameSpace);  // OK2
    void _enterStateIf(SixRGrammerParser::STATIFContext *ctx, Subroutine *nameSpace);    // OK2
    void _enterStateWaitSecond(SixRGrammerParser::STATWAITSECContext *ctx, Subroutine *nameSpace);   // ?? pause robot and program
    void _enterStateWaitFor(SixRGrammerParser::STATWAITFORContext *ctx, Subroutine *nameSpace);   // OK, but is correct function?!
    void _enterStateWhile(SixRGrammerParser::STATWHILEContext *ctx, Subroutine *nameSpace);  // OK2
    void _enterStateReturn(SixRGrammerParser::STATRETURNContext *ctx, Subroutine *nameSpace);    // OK2?
    void _enterStateAssignExpression(SixRGrammerParser::STATASINEPRContext *ctx, Subroutine *nameSpace); // OK2
    void _enterStateExpression(SixRGrammerParser::STATEXPContext *ctx, Subroutine *nameSpace);   // OK2
    void _enterStatePTP(SixRGrammerParser::STATPTPContext *ctx, Subroutine *nameSpace);  // OK2
    void _enterStateLinear(SixRGrammerParser::STATLINContext *ctx, Subroutine *nameSpace);// OK2
    void _enterStateCirc(SixRGrammerParser::STATCIRContext *ctx, Subroutine *nameSpace);// OK2
    void _enterStateSetFrame(SixRGrammerParser::STATSCFContext *ctx, Subroutine *nameSpace); // ?

    Variable _enterExpression(SixRGrammerParser::ExpressionContext *ctx, Subroutine *nameSpace);
    Variable _enterConditionalOrExpression(SixRGrammerParser::ConditionalOrExpressionContext *ctx, Subroutine *nameSpace);
    Variable _enterExclusiveOrExpression(SixRGrammerParser::ExclusiveOrExpressionContext *ctx, Subroutine *nameSpace);
    Variable _enterConditionalAndExpression(SixRGrammerParser::ConditionalAndExpressionContext *ctx, Subroutine *nameSpace);
    Variable _enterAdditiveExpression(SixRGrammerParser::AdditiveExpressionContext *ctx, Subroutine *nameSpace);
    Variable _enterMultiplicativeExpression(SixRGrammerParser::MultiplicativeExpressionContext *ctx, Subroutine *nameSpace);
    Variable _enterUnaryNotExpression(SixRGrammerParser::UnaryNotExpressionContext *ctx, Subroutine *nameSpace);
    Variable _enterUnaryPlusMinuxExpression(SixRGrammerParser::UnaryPlusMinuxExpressionContext *ctx, Subroutine *nameSpace);
    Variable _enterPrimary(SixRGrammerParser::PrimaryContext *ctx, Subroutine *nameSpace);
    Variable _enterParExpression(SixRGrammerParser::ParExpressionContext *ctx, Subroutine *nameSpace);
    Variable _enterLiteral(SixRGrammerParser::LiteralContext *ctx, Subroutine *nameSpace);

    void _setSixRJPR(SixRGrammerParser::SixRJPRContext *ctx, Variable *variable, bool changeType,Subroutine *nameSpace);
    bool _setSixRJXPoint(SixRGrammerParser::SixRJXPointContext *ctx, Variable *variable, bool changeType,Subroutine *nameSpace);

    bool _isPrimitiveType(string type);
    bool _isSixRPrimitiveType(string type);

    void _setRPPart(vector<SixRGrammerParser::SixRRPPartContext *> ctx, Variable *variable, Subroutine *nameSpace);
    void _setPPart(vector<SixRGrammerParser::SixRPPartContext *> ctx, Variable *variable, Subroutine *nameSpace);
    void _setRPart(vector<SixRGrammerParser::SixRRPartContext *> ctx, Variable *variable, Subroutine *nameSpace);
    void _setJPart(vector<SixRGrammerParser::SixRJPartContext *> ctx, Variable *variable, Subroutine *nameSpace);

    bool _checkSubroutineName(string name);
    void _getVariableByName(string name, Variable *var,Subroutine *nameSpace);
    void _addFormalParametersToSubroutine(Subroutine *sub, SixRGrammerParser::FormalParametersContext *ctx);

    bool _checkVariableName(string varName, Subroutine *nameSpace);
    int _getIndexFromVariableSuffix(SixRGrammerParser::ArrayVariableSuffixContext *ctx, Subroutine *nameSpace);

    void _report(Subroutine *nameSpace, string msg);
};


#endif // MSIXRPARSER_H

