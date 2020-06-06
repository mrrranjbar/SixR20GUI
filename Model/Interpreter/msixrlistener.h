#ifndef MSIXRPARSER_H
#define MSIXRPARSER_H
#include "SixRGrammerParser.h"
#include "SixRGrammerBaseListener.h"
#include "variable.h"
#include "Model/Controller/controller.h"
#include <map>
//#include <iostream>
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <mutex>          // std::mutex, std::unique_lock, std::defer_lock
#include <chrono>         // std::chrono::seconds
#include <queue>
#include "subroutine.h"
#include "interruptM.h"

using namespace std;

class MsixRlistener:public SixRGrammerBaseListener
{
public:    
    MsixRlistener();
    Subroutine global;
    Subroutine main;

    int currentLine=0;
    //queue<int> robotCurrentLine;
    void signalFromRobot();

    void enterStart(SixRGrammerParser::StartContext * ctx);
    void enterModuleRoutines(SixRGrammerParser::ModuleRoutinesContext * ctx);
    void exitModuleRoutines(SixRGrammerParser::ModuleRoutinesContext * ctx);
    void addPointToGlobal(Variable point);
    void clearAllDefines();

    void _checkRobotStat();
    void _sendCommandToRobot(int command, map<string, Variable> parameters);
    void _sendOutputToRobot(int portNum, int value);
    void _sendConfJToRobot(bool value);
    void _sendConfDataToRobot(int value);
    void _sendSingulPTPToRobot(bool value);
    void _sendSingulCPToRobot(bool value);
    void _updateInputFromRobot();

    void _checkInterruptsThread();
    void _runIntrupt(Subroutine *nameSpace);



    //Robot Commands
    string output= "DOUT";
    string input = "DIN";
    string confJ = "ConfJ";
    string confData = "ConfData";
    string singulPTP = "SingulPTP";
    string singulCP = "SingulCP";
    enum ControlManager{
        PTP=8,
        PTP_CART=10,
        LIN=16,
        CIR=12,
        SetFrame=64,
        ClearAlarm=99,
        GoHome=98,
        NOP = 100
    };

private:
    Controller *controller;
    vector<Subroutine*> subroutines;
    std::mutex mtx;           // mutex for critical section
    bool _readyToRun=false;

    Variable _F_Default;
    Variable _CON_Default;
    Variable _APPROX_Default;
    Variable _THETA_Default;




    void exitProgram();

    void _enterMainRoutine(SixRGrammerParser::MainRoutineContext *ctx); // OK
    void _enterSubroutineDeclartion(SixRGrammerParser::SubRoutineContext *ctx);
    void _enterVariableDeclaration(SixRGrammerParser::VariableDeclarationContext *ctx,Subroutine *nameSpace);    // OK --> PostControl

    void _enterInterruptDeclartion(SixRGrammerParser::InterruptDeclarationContext *ctx, Subroutine *nameSpace); //OK
    void _enterInterruptPriority(SixRGrammerParser::InterruptPriorityContext *ctx, Subroutine *nameSpace);  //OK

    //void _enterRoutineBody(SixRGrammerParser::RoutineBodyContext *ctx); // NOT implemented

    int _enterStatementList(SixRGrammerParser::StatementListContext *ctx, Subroutine *nameSpace, string currentScope="");

    //Statements
    void _enterStateFor(SixRGrammerParser::STATFORContext *ctx, Subroutine *nameSpace);  // OK2
    void _enterStateIf(SixRGrammerParser::STATIFContext *ctx, Subroutine *nameSpace);    // OK2
    void _enterStateWaitSecond(SixRGrammerParser::STATWAITSECContext *ctx, Subroutine *nameSpace);  // OK sleep interpreter // ?? pause robot and program
    void _enterStateWaitFor(SixRGrammerParser::STATWAITFORContext *ctx, Subroutine *nameSpace);   // OK, but is correct function?!
    void _enterStateWhile(SixRGrammerParser::STATWHILEContext *ctx, Subroutine *nameSpace);  // OK2
    void _enterStateReturn(SixRGrammerParser::STATRETURNContext *ctx, Subroutine *nameSpace);    // OK2?
    void _enterStateAssignExpression(SixRGrammerParser::STATASINEPRContext *ctx, Subroutine *nameSpace); // OK2
    void _enterStateExpression(SixRGrammerParser::STATEXPContext *ctx, Subroutine *nameSpace);   // OK2 .. post control
    void _enterStatePTP(SixRGrammerParser::STATPTPContext *ctx, Subroutine *nameSpace);  // OK2
    void _enterStateLinear(SixRGrammerParser::STATLINContext *ctx, Subroutine *nameSpace);// OK2
    void _enterStateCirc(SixRGrammerParser::STATCIRContext *ctx, Subroutine *nameSpace);// OK2
    void _enterStateGotoStart(SixRGrammerParser::STATGOTOSTARTContext *ctx, Subroutine *nameSpace);// ?
    void _enterStateSetFrame(SixRGrammerParser::STATSCFContext *ctx, Subroutine *nameSpace); // ?
    void _enterStateInterruptDeclaration(SixRGrammerParser::STATINTERRUPTDECContext *ctx,Subroutine *nameSpace);    //
    void _enterStateInterruptSetPriority(SixRGrammerParser::STATINTERRUPTContext *ctx,Subroutine *nameSpace);    //


    void _enterAssignExpression(SixRGrammerParser::AssignmentExpressionContext *ctx, Subroutine *nameSpace);
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

    void _setCurrentFrame(string frameName, string frameType);

    bool _checkSubroutineName(string name);
    Subroutine* _getVariableByName(string name, Variable *var,Subroutine *nameSpace);
    void _addFormalParametersToSubroutine(Subroutine *sub, SixRGrammerParser::FormalParametersContext *ctx);

    bool _checkVariableName(string varName, Subroutine *nameSpace);
    int _getIndexFromVariableSuffix(SixRGrammerParser::ArrayVariableSuffixContext *ctx, Subroutine *nameSpace);

    int _checkInterrupts(Subroutine *nameSpace);

    void _updateParsingLine(antlr4::tree::TerminalNode* node);

    void _report(Subroutine *nameSpace, string msg);
};


#endif // MSIXRPARSER_H

