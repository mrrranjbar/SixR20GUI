
// Generated from SixRGrammer.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "SixRGrammerParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by SixRGrammerParser.
 */
class  SixRGrammerListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart(SixRGrammerParser::StartContext *ctx) = 0;
  virtual void exitStart(SixRGrammerParser::StartContext *ctx) = 0;

  virtual void enterModuleRoutines(SixRGrammerParser::ModuleRoutinesContext *ctx) = 0;
  virtual void exitModuleRoutines(SixRGrammerParser::ModuleRoutinesContext *ctx) = 0;

  virtual void enterMainRoutine(SixRGrammerParser::MainRoutineContext *ctx) = 0;
  virtual void exitMainRoutine(SixRGrammerParser::MainRoutineContext *ctx) = 0;

  virtual void enterSubRoutine(SixRGrammerParser::SubRoutineContext *ctx) = 0;
  virtual void exitSubRoutine(SixRGrammerParser::SubRoutineContext *ctx) = 0;

  virtual void enterProcedureName(SixRGrammerParser::ProcedureNameContext *ctx) = 0;
  virtual void exitProcedureName(SixRGrammerParser::ProcedureNameContext *ctx) = 0;

  virtual void enterFormalParameters(SixRGrammerParser::FormalParametersContext *ctx) = 0;
  virtual void exitFormalParameters(SixRGrammerParser::FormalParametersContext *ctx) = 0;

  virtual void enterParameter(SixRGrammerParser::ParameterContext *ctx) = 0;
  virtual void exitParameter(SixRGrammerParser::ParameterContext *ctx) = 0;

  virtual void enterRoutineBody(SixRGrammerParser::RoutineBodyContext *ctx) = 0;
  virtual void exitRoutineBody(SixRGrammerParser::RoutineBodyContext *ctx) = 0;

  virtual void enterStatementList(SixRGrammerParser::StatementListContext *ctx) = 0;
  virtual void exitStatementList(SixRGrammerParser::StatementListContext *ctx) = 0;

  virtual void enterSTATCONTINUE(SixRGrammerParser::STATCONTINUEContext *ctx) = 0;
  virtual void exitSTATCONTINUE(SixRGrammerParser::STATCONTINUEContext *ctx) = 0;

  virtual void enterSTATFOR(SixRGrammerParser::STATFORContext *ctx) = 0;
  virtual void exitSTATFOR(SixRGrammerParser::STATFORContext *ctx) = 0;

  virtual void enterSTATIF(SixRGrammerParser::STATIFContext *ctx) = 0;
  virtual void exitSTATIF(SixRGrammerParser::STATIFContext *ctx) = 0;

  virtual void enterSTATWAITFOR(SixRGrammerParser::STATWAITFORContext *ctx) = 0;
  virtual void exitSTATWAITFOR(SixRGrammerParser::STATWAITFORContext *ctx) = 0;

  virtual void enterSTATWAITSEC(SixRGrammerParser::STATWAITSECContext *ctx) = 0;
  virtual void exitSTATWAITSEC(SixRGrammerParser::STATWAITSECContext *ctx) = 0;

  virtual void enterSTATWHILE(SixRGrammerParser::STATWHILEContext *ctx) = 0;
  virtual void exitSTATWHILE(SixRGrammerParser::STATWHILEContext *ctx) = 0;

  virtual void enterSTATRETURN(SixRGrammerParser::STATRETURNContext *ctx) = 0;
  virtual void exitSTATRETURN(SixRGrammerParser::STATRETURNContext *ctx) = 0;

  virtual void enterSTATASINEPR(SixRGrammerParser::STATASINEPRContext *ctx) = 0;
  virtual void exitSTATASINEPR(SixRGrammerParser::STATASINEPRContext *ctx) = 0;

  virtual void enterSTATEXP(SixRGrammerParser::STATEXPContext *ctx) = 0;
  virtual void exitSTATEXP(SixRGrammerParser::STATEXPContext *ctx) = 0;

  virtual void enterSTATBRAKE(SixRGrammerParser::STATBRAKEContext *ctx) = 0;
  virtual void exitSTATBRAKE(SixRGrammerParser::STATBRAKEContext *ctx) = 0;

  virtual void enterSTATPTP(SixRGrammerParser::STATPTPContext *ctx) = 0;
  virtual void exitSTATPTP(SixRGrammerParser::STATPTPContext *ctx) = 0;

  virtual void enterSTATLIN(SixRGrammerParser::STATLINContext *ctx) = 0;
  virtual void exitSTATLIN(SixRGrammerParser::STATLINContext *ctx) = 0;

  virtual void enterSTATCIR(SixRGrammerParser::STATCIRContext *ctx) = 0;
  virtual void exitSTATCIR(SixRGrammerParser::STATCIRContext *ctx) = 0;

  virtual void enterSTATVARDEC(SixRGrammerParser::STATVARDECContext *ctx) = 0;
  virtual void exitSTATVARDEC(SixRGrammerParser::STATVARDECContext *ctx) = 0;

  virtual void enterSTATSCF(SixRGrammerParser::STATSCFContext *ctx) = 0;
  virtual void exitSTATSCF(SixRGrammerParser::STATSCFContext *ctx) = 0;

  virtual void enterSTATNEWLINE(SixRGrammerParser::STATNEWLINEContext *ctx) = 0;
  virtual void exitSTATNEWLINE(SixRGrammerParser::STATNEWLINEContext *ctx) = 0;

  virtual void enterSTATINTERRUPTDEC(SixRGrammerParser::STATINTERRUPTDECContext *ctx) = 0;
  virtual void exitSTATINTERRUPTDEC(SixRGrammerParser::STATINTERRUPTDECContext *ctx) = 0;

  virtual void enterSTATINTERRUPT(SixRGrammerParser::STATINTERRUPTContext *ctx) = 0;
  virtual void exitSTATINTERRUPT(SixRGrammerParser::STATINTERRUPTContext *ctx) = 0;

  virtual void enterSTATGOTOSTART(SixRGrammerParser::STATGOTOSTARTContext *ctx) = 0;
  virtual void exitSTATGOTOSTART(SixRGrammerParser::STATGOTOSTARTContext *ctx) = 0;

  virtual void enterTargetPoint(SixRGrammerParser::TargetPointContext *ctx) = 0;
  virtual void exitTargetPoint(SixRGrammerParser::TargetPointContext *ctx) = 0;

  virtual void enterApprxExpr(SixRGrammerParser::ApprxExprContext *ctx) = 0;
  virtual void exitApprxExpr(SixRGrammerParser::ApprxExprContext *ctx) = 0;

  virtual void enterFfExpr(SixRGrammerParser::FfExprContext *ctx) = 0;
  virtual void exitFfExpr(SixRGrammerParser::FfExprContext *ctx) = 0;

  virtual void enterTimeExpr(SixRGrammerParser::TimeExprContext *ctx) = 0;
  virtual void exitTimeExpr(SixRGrammerParser::TimeExprContext *ctx) = 0;

  virtual void enterConExpr(SixRGrammerParser::ConExprContext *ctx) = 0;
  virtual void exitConExpr(SixRGrammerParser::ConExprContext *ctx) = 0;

  virtual void enterThetaExpr(SixRGrammerParser::ThetaExprContext *ctx) = 0;
  virtual void exitThetaExpr(SixRGrammerParser::ThetaExprContext *ctx) = 0;

  virtual void enterInterruptDeclaration(SixRGrammerParser::InterruptDeclarationContext *ctx) = 0;
  virtual void exitInterruptDeclaration(SixRGrammerParser::InterruptDeclarationContext *ctx) = 0;

  virtual void enterInterruptPriority(SixRGrammerParser::InterruptPriorityContext *ctx) = 0;
  virtual void exitInterruptPriority(SixRGrammerParser::InterruptPriorityContext *ctx) = 0;

  virtual void enterVariableDeclaration(SixRGrammerParser::VariableDeclarationContext *ctx) = 0;
  virtual void exitVariableDeclaration(SixRGrammerParser::VariableDeclarationContext *ctx) = 0;

  virtual void enterVariableInitialisation(SixRGrammerParser::VariableInitialisationContext *ctx) = 0;
  virtual void exitVariableInitialisation(SixRGrammerParser::VariableInitialisationContext *ctx) = 0;

  virtual void enterVariableListRest(SixRGrammerParser::VariableListRestContext *ctx) = 0;
  virtual void exitVariableListRest(SixRGrammerParser::VariableListRestContext *ctx) = 0;

  virtual void enterAssignmentExpression(SixRGrammerParser::AssignmentExpressionContext *ctx) = 0;
  virtual void exitAssignmentExpression(SixRGrammerParser::AssignmentExpressionContext *ctx) = 0;

  virtual void enterSixRJPR(SixRGrammerParser::SixRJPRContext *ctx) = 0;
  virtual void exitSixRJPR(SixRGrammerParser::SixRJPRContext *ctx) = 0;

  virtual void enterSixRJXPoint(SixRGrammerParser::SixRJXPointContext *ctx) = 0;
  virtual void exitSixRJXPoint(SixRGrammerParser::SixRJXPointContext *ctx) = 0;

  virtual void enterSixRPPoint(SixRGrammerParser::SixRPPointContext *ctx) = 0;
  virtual void exitSixRPPoint(SixRGrammerParser::SixRPPointContext *ctx) = 0;

  virtual void enterSixRPosition(SixRGrammerParser::SixRPositionContext *ctx) = 0;
  virtual void exitSixRPosition(SixRGrammerParser::SixRPositionContext *ctx) = 0;

  virtual void enterSixROrientation(SixRGrammerParser::SixROrientationContext *ctx) = 0;
  virtual void exitSixROrientation(SixRGrammerParser::SixROrientationContext *ctx) = 0;

  virtual void enterSixRJPoint(SixRGrammerParser::SixRJPointContext *ctx) = 0;
  virtual void exitSixRJPoint(SixRGrammerParser::SixRJPointContext *ctx) = 0;

  virtual void enterSixRJPart(SixRGrammerParser::SixRJPartContext *ctx) = 0;
  virtual void exitSixRJPart(SixRGrammerParser::SixRJPartContext *ctx) = 0;

  virtual void enterSixRRPPart(SixRGrammerParser::SixRRPPartContext *ctx) = 0;
  virtual void exitSixRRPPart(SixRGrammerParser::SixRRPPartContext *ctx) = 0;

  virtual void enterSixRPPart(SixRGrammerParser::SixRPPartContext *ctx) = 0;
  virtual void exitSixRPPart(SixRGrammerParser::SixRPPartContext *ctx) = 0;

  virtual void enterSixRRPart(SixRGrammerParser::SixRRPartContext *ctx) = 0;
  virtual void exitSixRRPart(SixRGrammerParser::SixRRPartContext *ctx) = 0;

  virtual void enterVariableName(SixRGrammerParser::VariableNameContext *ctx) = 0;
  virtual void exitVariableName(SixRGrammerParser::VariableNameContext *ctx) = 0;

  virtual void enterArrayVariableSuffix(SixRGrammerParser::ArrayVariableSuffixContext *ctx) = 0;
  virtual void exitArrayVariableSuffix(SixRGrammerParser::ArrayVariableSuffixContext *ctx) = 0;

  virtual void enterExpression(SixRGrammerParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(SixRGrammerParser::ExpressionContext *ctx) = 0;

  virtual void enterRelationalOp(SixRGrammerParser::RelationalOpContext *ctx) = 0;
  virtual void exitRelationalOp(SixRGrammerParser::RelationalOpContext *ctx) = 0;

  virtual void enterConditionalOrExpression(SixRGrammerParser::ConditionalOrExpressionContext *ctx) = 0;
  virtual void exitConditionalOrExpression(SixRGrammerParser::ConditionalOrExpressionContext *ctx) = 0;

  virtual void enterExclusiveOrExpression(SixRGrammerParser::ExclusiveOrExpressionContext *ctx) = 0;
  virtual void exitExclusiveOrExpression(SixRGrammerParser::ExclusiveOrExpressionContext *ctx) = 0;

  virtual void enterConditionalAndExpression(SixRGrammerParser::ConditionalAndExpressionContext *ctx) = 0;
  virtual void exitConditionalAndExpression(SixRGrammerParser::ConditionalAndExpressionContext *ctx) = 0;

  virtual void enterAdditiveExpression(SixRGrammerParser::AdditiveExpressionContext *ctx) = 0;
  virtual void exitAdditiveExpression(SixRGrammerParser::AdditiveExpressionContext *ctx) = 0;

  virtual void enterMultiplicativeExpression(SixRGrammerParser::MultiplicativeExpressionContext *ctx) = 0;
  virtual void exitMultiplicativeExpression(SixRGrammerParser::MultiplicativeExpressionContext *ctx) = 0;

  virtual void enterUnaryNotExpression(SixRGrammerParser::UnaryNotExpressionContext *ctx) = 0;
  virtual void exitUnaryNotExpression(SixRGrammerParser::UnaryNotExpressionContext *ctx) = 0;

  virtual void enterUnaryPlusMinuxExpression(SixRGrammerParser::UnaryPlusMinuxExpressionContext *ctx) = 0;
  virtual void exitUnaryPlusMinuxExpression(SixRGrammerParser::UnaryPlusMinuxExpressionContext *ctx) = 0;

  virtual void enterPrimary(SixRGrammerParser::PrimaryContext *ctx) = 0;
  virtual void exitPrimary(SixRGrammerParser::PrimaryContext *ctx) = 0;

  virtual void enterLiteral(SixRGrammerParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(SixRGrammerParser::LiteralContext *ctx) = 0;

  virtual void enterIntLITERAL(SixRGrammerParser::IntLITERALContext *ctx) = 0;
  virtual void exitIntLITERAL(SixRGrammerParser::IntLITERALContext *ctx) = 0;

  virtual void enterFloatLITERAL(SixRGrammerParser::FloatLITERALContext *ctx) = 0;
  virtual void exitFloatLITERAL(SixRGrammerParser::FloatLITERALContext *ctx) = 0;

  virtual void enterCharLITERAL(SixRGrammerParser::CharLITERALContext *ctx) = 0;
  virtual void exitCharLITERAL(SixRGrammerParser::CharLITERALContext *ctx) = 0;

  virtual void enterStringLITERAL(SixRGrammerParser::StringLITERALContext *ctx) = 0;
  virtual void exitStringLITERAL(SixRGrammerParser::StringLITERALContext *ctx) = 0;

  virtual void enterNumberLITERAL(SixRGrammerParser::NumberLITERALContext *ctx) = 0;
  virtual void exitNumberLITERAL(SixRGrammerParser::NumberLITERALContext *ctx) = 0;

  virtual void enterBooleanLiteral(SixRGrammerParser::BooleanLiteralContext *ctx) = 0;
  virtual void exitBooleanLiteral(SixRGrammerParser::BooleanLiteralContext *ctx) = 0;

  virtual void enterParExpression(SixRGrammerParser::ParExpressionContext *ctx) = 0;
  virtual void exitParExpression(SixRGrammerParser::ParExpressionContext *ctx) = 0;

  virtual void enterType(SixRGrammerParser::TypeContext *ctx) = 0;
  virtual void exitType(SixRGrammerParser::TypeContext *ctx) = 0;

  virtual void enterSixRPrimitiveType(SixRGrammerParser::SixRPrimitiveTypeContext *ctx) = 0;
  virtual void exitSixRPrimitiveType(SixRGrammerParser::SixRPrimitiveTypeContext *ctx) = 0;

  virtual void enterPrimitiveType(SixRGrammerParser::PrimitiveTypeContext *ctx) = 0;
  virtual void exitPrimitiveType(SixRGrammerParser::PrimitiveTypeContext *ctx) = 0;


};

