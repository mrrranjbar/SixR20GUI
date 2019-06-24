
// Generated from SixRGrammer.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  SixRGrammerParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, FrameType = 19, TOOL = 20, 
    BASE = 21, TASK = 22, OBJECT = 23, AND = 24, ANIN = 25, ANOUT = 26, 
    B_AND = 27, B_NOT = 28, B_OR = 29, B_EXOR = 30, BOOL = 31, BREAK = 32, 
    C_DIS = 33, C_ORI = 34, C_PTP = 35, C_VEL = 36, CASE = 37, CAST_FROM = 38, 
    CAST_TO = 39, CHAR = 40, CIR_REL = 41, CIR = 42, CONST = 43, CONTINUE = 44, 
    DELAY = 45, DECL = 46, DEF = 47, DEFAULT = 48, DEFDAT = 49, DEFFCT = 50, 
    DO = 51, ELSE = 52, END = 53, ENDDAT = 54, ENDFCT = 55, ENDFOR = 56, 
    ENDIF = 57, ENDLOOP = 58, ENDSWITCH = 59, ENDWHILE = 60, ENUM = 61, 
    EXIT = 62, EXT = 63, EXTFCT = 64, FALSE = 65, FOR = 66, GLOBAL = 67, 
    GOTO = 68, HALT = 69, IF = 70, IMPORT = 71, INTERRUPT = 72, INT = 73, 
    IS = 74, LIN_REL = 75, LIN = 76, LOOP = 77, MAIN = 78, MAXIMUM = 79, 
    MINIMUM = 80, NOT = 81, OR = 82, PRIO = 83, PTP_REL = 84, PTP = 85, 
    PUBLIC = 86, FLOAT = 87, REPEAT = 88, RETURN = 89, SEC = 90, SIGNAL = 91, 
    STRUC = 92, SWITCH = 93, THEN = 94, TO = 95, TRIGGER = 96, TRUE = 97, 
    UNTIL = 98, WAIT = 99, WHEN = 100, WHILE = 101, EXOR = 102, STARTPROG = 103, 
    ENDPROG = 104, POINTJ = 105, POINTP = 106, POS = 107, ORIENT = 108, 
    VECTOR = 109, CON = 110, XX = 111, YY = 112, ZZ = 113, AA = 114, BB = 115, 
    CC = 116, FF = 117, J1 = 118, J2 = 119, J3 = 120, J4 = 121, J5 = 122, 
    J6 = 123, FragINTLITERAL = 124, FragFLOATLITERAL = 125, FragCHARLITERAL = 126, 
    FragSTRINGLITERAL = 127, IDENTIFIER = 128, NEWLINE = 129, WS = 130, 
    SETFRAME = 131
  };

  enum {
    RuleStart = 0, RuleModuleRoutines = 1, RuleMainRoutine = 2, RuleSubRoutine = 3, 
    RuleProcedureName = 4, RuleFormalParameters = 5, RuleParameter = 6, 
    RuleRoutineBody = 7, RuleStatementList = 8, RuleStatement = 9, RuleVariableDeclaration = 10, 
    RuleVariableInitialisation = 11, RuleVariableListRest = 12, RuleAssignmentExpression = 13, 
    RuleSixRJPR = 14, RuleSixRJXPoint = 15, RuleSixRPPoint = 16, RuleSixRPosition = 17, 
    RuleSixROrientation = 18, RuleSixRJPoint = 19, RuleSixRJPart = 20, RuleSixRRPPart = 21, 
    RuleSixRPPart = 22, RuleSixRRPart = 23, RuleVariableName = 24, RuleArrayVariableSuffix = 25, 
    RuleExpression = 26, RuleRelationalOp = 27, RuleConditionalOrExpression = 28, 
    RuleExclusiveOrExpression = 29, RuleConditionalAndExpression = 30, RuleAdditiveExpression = 31, 
    RuleMultiplicativeExpression = 32, RuleUnaryNotExpression = 33, RuleUnaryPlusMinuxExpression = 34, 
    RulePrimary = 35, RuleLiteral = 36, RuleIntLITERAL = 37, RuleFloatLITERAL = 38, 
    RuleCharLITERAL = 39, RuleStringLITERAL = 40, RuleNumberLITERAL = 41, 
    RuleBooleanLiteral = 42, RuleParExpression = 43, RuleType = 44, RuleSixRPrimitiveType = 45, 
    RulePrimitiveType = 46
  };

  SixRGrammerParser(antlr4::TokenStream *input);
  ~SixRGrammerParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class StartContext;
  class ModuleRoutinesContext;
  class MainRoutineContext;
  class SubRoutineContext;
  class ProcedureNameContext;
  class FormalParametersContext;
  class ParameterContext;
  class RoutineBodyContext;
  class StatementListContext;
  class StatementContext;
  class VariableDeclarationContext;
  class VariableInitialisationContext;
  class VariableListRestContext;
  class AssignmentExpressionContext;
  class SixRJPRContext;
  class SixRJXPointContext;
  class SixRPPointContext;
  class SixRPositionContext;
  class SixROrientationContext;
  class SixRJPointContext;
  class SixRJPartContext;
  class SixRRPPartContext;
  class SixRPPartContext;
  class SixRRPartContext;
  class VariableNameContext;
  class ArrayVariableSuffixContext;
  class ExpressionContext;
  class RelationalOpContext;
  class ConditionalOrExpressionContext;
  class ExclusiveOrExpressionContext;
  class ConditionalAndExpressionContext;
  class AdditiveExpressionContext;
  class MultiplicativeExpressionContext;
  class UnaryNotExpressionContext;
  class UnaryPlusMinuxExpressionContext;
  class PrimaryContext;
  class LiteralContext;
  class IntLITERALContext;
  class FloatLITERALContext;
  class CharLITERALContext;
  class StringLITERALContext;
  class NumberLITERALContext;
  class BooleanLiteralContext;
  class ParExpressionContext;
  class TypeContext;
  class SixRPrimitiveTypeContext;
  class PrimitiveTypeContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ModuleRoutinesContext *moduleRoutines();
    antlr4::tree::TerminalNode *EOF();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StartContext* start();

  class  ModuleRoutinesContext : public antlr4::ParserRuleContext {
  public:
    ModuleRoutinesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<MainRoutineContext *> mainRoutine();
    MainRoutineContext* mainRoutine(size_t i);
    std::vector<SubRoutineContext *> subRoutine();
    SubRoutineContext* subRoutine(size_t i);
    std::vector<VariableDeclarationContext *> variableDeclaration();
    VariableDeclarationContext* variableDeclaration(size_t i);
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ModuleRoutinesContext* moduleRoutines();

  class  MainRoutineContext : public antlr4::ParserRuleContext {
  public:
    MainRoutineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *MAIN();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    RoutineBodyContext *routineBody();
    antlr4::tree::TerminalNode *END();
    antlr4::tree::TerminalNode *INT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MainRoutineContext* mainRoutine();

  class  SubRoutineContext : public antlr4::ParserRuleContext {
  public:
    SubRoutineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProcedureNameContext *procedureName();
    FormalParametersContext *formalParameters();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    RoutineBodyContext *routineBody();
    antlr4::tree::TerminalNode *END();
    TypeContext *type();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SubRoutineContext* subRoutine();

  class  ProcedureNameContext : public antlr4::ParserRuleContext {
  public:
    ProcedureNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProcedureNameContext* procedureName();

  class  FormalParametersContext : public antlr4::ParserRuleContext {
  public:
    FormalParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParameterContext *> parameter();
    ParameterContext* parameter(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FormalParametersContext* formalParameters();

  class  ParameterContext : public antlr4::ParserRuleContext {
  public:
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    VariableNameContext *variableName();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParameterContext* parameter();

  class  RoutineBodyContext : public antlr4::ParserRuleContext {
  public:
    RoutineBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementListContext *statementList();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RoutineBodyContext* routineBody();

  class  StatementListContext : public antlr4::ParserRuleContext {
  public:
    StatementListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementListContext* statementList();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatementContext() = default;
    void copyFrom(StatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  STATFORContext : public StatementContext {
  public:
    STATFORContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *TO();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    StatementListContext *statementList();
    antlr4::tree::TerminalNode *ENDFOR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  STATLINContext : public StatementContext {
  public:
    STATLINContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *LIN();
    SixRJXPointContext *sixRJXPoint();
    VariableNameContext *variableName();
    antlr4::tree::TerminalNode *FF();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *CON();
    antlr4::tree::TerminalNode *NEWLINE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  STATCONTINUEContext : public StatementContext {
  public:
    STATCONTINUEContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *CONTINUE();
    antlr4::tree::TerminalNode *NEWLINE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  STATPTPContext : public StatementContext {
  public:
    STATPTPContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *PTP();
    SixRJXPointContext *sixRJXPoint();
    VariableNameContext *variableName();
    antlr4::tree::TerminalNode *FF();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *CON();
    antlr4::tree::TerminalNode *NEWLINE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  STATCIRContext : public StatementContext {
  public:
    STATCIRContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *CIR();
    std::vector<SixRJXPointContext *> sixRJXPoint();
    SixRJXPointContext* sixRJXPoint(size_t i);
    std::vector<VariableNameContext *> variableName();
    VariableNameContext* variableName(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *FF();
    antlr4::tree::TerminalNode *CON();
    antlr4::tree::TerminalNode *NEWLINE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  STATBRAKEContext : public StatementContext {
  public:
    STATBRAKEContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *BREAK();
    antlr4::tree::TerminalNode *NEWLINE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  STATIFContext : public StatementContext {
  public:
    STATIFContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *IF();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *THEN();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<StatementListContext *> statementList();
    StatementListContext* statementList(size_t i);
    antlr4::tree::TerminalNode *ENDIF();
    antlr4::tree::TerminalNode *ELSE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  STATNEWLINEContext : public StatementContext {
  public:
    STATNEWLINEContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *NEWLINE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  STATSCFContext : public StatementContext {
  public:
    STATSCFContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *SETFRAME();
    antlr4::tree::TerminalNode *FrameType();
    VariableNameContext *variableName();
    antlr4::tree::TerminalNode *NEWLINE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  STATWAITFORContext : public StatementContext {
  public:
    STATWAITFORContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *WAIT();
    antlr4::tree::TerminalNode *FOR();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *NEWLINE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  STATWHILEContext : public StatementContext {
  public:
    STATWHILEContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *WHILE();
    ExpressionContext *expression();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    StatementListContext *statementList();
    antlr4::tree::TerminalNode *ENDWHILE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  STATRETURNContext : public StatementContext {
  public:
    STATRETURNContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *RETURN();
    antlr4::tree::TerminalNode *NEWLINE();
    ExpressionContext *expression();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  STATVARDECContext : public StatementContext {
  public:
    STATVARDECContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *NEWLINE();
    VariableDeclarationContext *variableDeclaration();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  STATASINEPRContext : public StatementContext {
  public:
    STATASINEPRContext(StatementContext *ctx);

    AssignmentExpressionContext *assignmentExpression();
    antlr4::tree::TerminalNode *NEWLINE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  STATEXPContext : public StatementContext {
  public:
    STATEXPContext(StatementContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *NEWLINE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  class  STATWAITSECContext : public StatementContext {
  public:
    STATWAITSECContext(StatementContext *ctx);

    antlr4::tree::TerminalNode *WAIT();
    antlr4::tree::TerminalNode *SEC();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *NEWLINE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
  };

  StatementContext* statement();

  class  VariableDeclarationContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypeContext *type();
    VariableNameContext *variableName();
    VariableListRestContext *variableListRest();
    VariableInitialisationContext *variableInitialisation();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableDeclarationContext* variableDeclaration();

  class  VariableInitialisationContext : public antlr4::ParserRuleContext {
  public:
    VariableInitialisationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    SixRJPRContext *sixRJPR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableInitialisationContext* variableInitialisation();

  class  VariableListRestContext : public antlr4::ParserRuleContext {
  public:
    VariableListRestContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VariableNameContext *> variableName();
    VariableNameContext* variableName(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableListRestContext* variableListRest();

  class  AssignmentExpressionContext : public antlr4::ParserRuleContext {
  public:
    AssignmentExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableNameContext *variableName();
    ExpressionContext *expression();
    SixRJPRContext *sixRJPR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AssignmentExpressionContext* assignmentExpression();

  class  SixRJPRContext : public antlr4::ParserRuleContext {
  public:
    SixRJPRContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SixRJXPointContext *sixRJXPoint();
    SixRPositionContext *sixRPosition();
    SixROrientationContext *sixROrientation();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SixRJPRContext* sixRJPR();

  class  SixRJXPointContext : public antlr4::ParserRuleContext {
  public:
    SixRJXPointContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SixRPPointContext *sixRPPoint();
    SixRJPointContext *sixRJPoint();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SixRJXPointContext* sixRJXPoint();

  class  SixRPPointContext : public antlr4::ParserRuleContext {
  public:
    SixRPPointContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SixRRPPartContext *> sixRRPPart();
    SixRRPPartContext* sixRRPPart(size_t i);
    std::vector<VariableNameContext *> variableName();
    VariableNameContext* variableName(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SixRPPointContext* sixRPPoint();

  class  SixRPositionContext : public antlr4::ParserRuleContext {
  public:
    SixRPositionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SixRPPartContext *> sixRPPart();
    SixRPPartContext* sixRPPart(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SixRPositionContext* sixRPosition();

  class  SixROrientationContext : public antlr4::ParserRuleContext {
  public:
    SixROrientationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SixRRPartContext *> sixRRPart();
    SixRRPartContext* sixRRPart(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SixROrientationContext* sixROrientation();

  class  SixRJPointContext : public antlr4::ParserRuleContext {
  public:
    SixRJPointContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SixRJPartContext *> sixRJPart();
    SixRJPartContext* sixRJPart(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SixRJPointContext* sixRJPoint();

  class  SixRJPartContext : public antlr4::ParserRuleContext {
  public:
    SixRJPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *J1();
    antlr4::tree::TerminalNode *J2();
    antlr4::tree::TerminalNode *J3();
    antlr4::tree::TerminalNode *J4();
    antlr4::tree::TerminalNode *J5();
    antlr4::tree::TerminalNode *J6();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SixRJPartContext* sixRJPart();

  class  SixRRPPartContext : public antlr4::ParserRuleContext {
  public:
    SixRRPPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SixRRPartContext *sixRRPart();
    SixRPPartContext *sixRPPart();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SixRRPPartContext* sixRRPPart();

  class  SixRPPartContext : public antlr4::ParserRuleContext {
  public:
    SixRPPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *XX();
    antlr4::tree::TerminalNode *YY();
    antlr4::tree::TerminalNode *ZZ();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SixRPPartContext* sixRPPart();

  class  SixRRPartContext : public antlr4::ParserRuleContext {
  public:
    SixRRPartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *AA();
    antlr4::tree::TerminalNode *BB();
    antlr4::tree::TerminalNode *CC();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SixRRPartContext* sixRRPart();

  class  VariableNameContext : public antlr4::ParserRuleContext {
  public:
    VariableNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    ArrayVariableSuffixContext *arrayVariableSuffix();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableNameContext* variableName();

  class  ArrayVariableSuffixContext : public antlr4::ParserRuleContext {
  public:
    ArrayVariableSuffixContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArrayVariableSuffixContext* arrayVariableSuffix();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProcedureNameContext *procedureName();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<ConditionalOrExpressionContext *> conditionalOrExpression();
    ConditionalOrExpressionContext* conditionalOrExpression(size_t i);
    std::vector<RelationalOpContext *> relationalOp();
    RelationalOpContext* relationalOp(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();

  class  RelationalOpContext : public antlr4::ParserRuleContext {
  public:
    RelationalOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  RelationalOpContext* relationalOp();

  class  ConditionalOrExpressionContext : public antlr4::ParserRuleContext {
  public:
    ConditionalOrExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ExclusiveOrExpressionContext *> exclusiveOrExpression();
    ExclusiveOrExpressionContext* exclusiveOrExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> OR();
    antlr4::tree::TerminalNode* OR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConditionalOrExpressionContext* conditionalOrExpression();

  class  ExclusiveOrExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExclusiveOrExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ConditionalAndExpressionContext *> conditionalAndExpression();
    ConditionalAndExpressionContext* conditionalAndExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> EXOR();
    antlr4::tree::TerminalNode* EXOR(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExclusiveOrExpressionContext* exclusiveOrExpression();

  class  ConditionalAndExpressionContext : public antlr4::ParserRuleContext {
  public:
    ConditionalAndExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<AdditiveExpressionContext *> additiveExpression();
    AdditiveExpressionContext* additiveExpression(size_t i);
    std::vector<antlr4::tree::TerminalNode *> AND();
    antlr4::tree::TerminalNode* AND(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ConditionalAndExpressionContext* conditionalAndExpression();

  class  AdditiveExpressionContext : public antlr4::ParserRuleContext {
  public:
    AdditiveExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<MultiplicativeExpressionContext *> multiplicativeExpression();
    MultiplicativeExpressionContext* multiplicativeExpression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  AdditiveExpressionContext* additiveExpression();

  class  MultiplicativeExpressionContext : public antlr4::ParserRuleContext {
  public:
    MultiplicativeExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<UnaryNotExpressionContext *> unaryNotExpression();
    UnaryNotExpressionContext* unaryNotExpression(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  MultiplicativeExpressionContext* multiplicativeExpression();

  class  UnaryNotExpressionContext : public antlr4::ParserRuleContext {
  public:
    UnaryNotExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NOT();
    UnaryNotExpressionContext *unaryNotExpression();
    UnaryPlusMinuxExpressionContext *unaryPlusMinuxExpression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnaryNotExpressionContext* unaryNotExpression();

  class  UnaryPlusMinuxExpressionContext : public antlr4::ParserRuleContext {
  public:
    UnaryPlusMinuxExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnaryPlusMinuxExpressionContext *unaryPlusMinuxExpression();
    PrimaryContext *primary();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnaryPlusMinuxExpressionContext* unaryPlusMinuxExpression();

  class  PrimaryContext : public antlr4::ParserRuleContext {
  public:
    PrimaryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParExpressionContext *parExpression();
    VariableNameContext *variableName();
    LiteralContext *literal();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PrimaryContext* primary();

  class  LiteralContext : public antlr4::ParserRuleContext {
  public:
    LiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    NumberLITERALContext *numberLITERAL();
    CharLITERALContext *charLITERAL();
    StringLITERALContext *stringLITERAL();
    BooleanLiteralContext *booleanLiteral();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LiteralContext* literal();

  class  IntLITERALContext : public antlr4::ParserRuleContext {
  public:
    IntLITERALContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FragINTLITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IntLITERALContext* intLITERAL();

  class  FloatLITERALContext : public antlr4::ParserRuleContext {
  public:
    FloatLITERALContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FragFLOATLITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FloatLITERALContext* floatLITERAL();

  class  CharLITERALContext : public antlr4::ParserRuleContext {
  public:
    CharLITERALContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FragCHARLITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  CharLITERALContext* charLITERAL();

  class  StringLITERALContext : public antlr4::ParserRuleContext {
  public:
    StringLITERALContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FragSTRINGLITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StringLITERALContext* stringLITERAL();

  class  NumberLITERALContext : public antlr4::ParserRuleContext {
  public:
    NumberLITERALContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    IntLITERALContext *intLITERAL();
    FloatLITERALContext *floatLITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  NumberLITERALContext* numberLITERAL();

  class  BooleanLiteralContext : public antlr4::ParserRuleContext {
  public:
    BooleanLiteralContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  BooleanLiteralContext* booleanLiteral();

  class  ParExpressionContext : public antlr4::ParserRuleContext {
  public:
    ParExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ParExpressionContext* parExpression();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    PrimitiveTypeContext *primitiveType();
    SixRPrimitiveTypeContext *sixRPrimitiveType();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TypeContext* type();

  class  SixRPrimitiveTypeContext : public antlr4::ParserRuleContext {
  public:
    SixRPrimitiveTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *POS();
    antlr4::tree::TerminalNode *ORIENT();
    antlr4::tree::TerminalNode *POINTJ();
    antlr4::tree::TerminalNode *POINTP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  SixRPrimitiveTypeContext* sixRPrimitiveType();

  class  PrimitiveTypeContext : public antlr4::ParserRuleContext {
  public:
    PrimitiveTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BOOL();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  PrimitiveTypeContext* primitiveType();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

