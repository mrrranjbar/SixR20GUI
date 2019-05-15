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
    //bad eyd*********************
    void enterSTATLIN(SixRGrammerParser::STATLINContext *ctx);
    //akhar*************************
    void enterSTATCIR(SixRGrammerParser::STATCIRContext *ctx);
    void enterSTATWAITSEC(SixRGrammerParser::STATWAITSECContext *ctx);
    void enterSTATIF(SixRGrammerParser::STATIFContext *ctx);
    void enterSTATFOR(SixRGrammerParser::STATFORContext *ctx);
    void enterSTATWHILE(SixRGrammerParser::STATWHILEContext *ctx);
    //akhar*************************
    //bad eyd*********************
    //void enterFormalParameters(SixRGrammerParser::FormalParametersContext *ctx);
private:
   vector<Variable> parameter;
   Variable lastPoint_J;
   Variable lastPoint_P;
   vector <double>lp_J;
   vector <double>lp_P;
   //akhar********************
   Variable lastPointCIR_J_walker1;
   Variable lastPointCIR_P_walker1;
   vector<double>lp_JCIR_walker1;
   vector<double>lp_PCIR_walker1;

   Variable lastPointCIR_J_walker2;
   Variable lastPointCIR_P_walker2;
   vector<double>lp_JCIR_walker2;
   vector<double>lp_PCIR_walker2;


   Variable lastPointCIR_J_walker3;
   Variable lastPointCIR_P_walker3;
   vector<double>lp_JCIR_walker3;
   vector<double>lp_PCIR_walker3;

   int flag_walker1;
   int flag_walker2;
   int flag_walker3;

   int waitSec;

   int lastApproximate;
   //akhar********************
   //badeyd_2*****************
   double l_FF;
   double l_CON;
   //badeyd_2*****************
};


#endif // MSIXRPARSER_H

