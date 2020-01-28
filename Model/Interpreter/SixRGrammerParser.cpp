
// Generated from SixRGrammer.g4 by ANTLR 4.7.2


#include "SixRGrammerListener.h"

#include "SixRGrammerParser.h"


using namespace antlrcpp;
using namespace antlr4;

SixRGrammerParser::SixRGrammerParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SixRGrammerParser::~SixRGrammerParser() {
  delete _interpreter;
}

std::string SixRGrammerParser::getGrammarFileName() const {
  return "SixRGrammer.g4";
}

const std::vector<std::string>& SixRGrammerParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SixRGrammerParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StartContext ------------------------------------------------------------------

SixRGrammerParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::ModuleRoutinesContext* SixRGrammerParser::StartContext::moduleRoutines() {
  return getRuleContext<SixRGrammerParser::ModuleRoutinesContext>(0);
}

tree::TerminalNode* SixRGrammerParser::StartContext::EOF() {
  return getToken(SixRGrammerParser::EOF, 0);
}


size_t SixRGrammerParser::StartContext::getRuleIndex() const {
  return SixRGrammerParser::RuleStart;
}

void SixRGrammerParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void SixRGrammerParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

SixRGrammerParser::StartContext* SixRGrammerParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, SixRGrammerParser::RuleStart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    moduleRoutines();
    setState(109);
    match(SixRGrammerParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModuleRoutinesContext ------------------------------------------------------------------

SixRGrammerParser::ModuleRoutinesContext::ModuleRoutinesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SixRGrammerParser::MainRoutineContext *> SixRGrammerParser::ModuleRoutinesContext::mainRoutine() {
  return getRuleContexts<SixRGrammerParser::MainRoutineContext>();
}

SixRGrammerParser::MainRoutineContext* SixRGrammerParser::ModuleRoutinesContext::mainRoutine(size_t i) {
  return getRuleContext<SixRGrammerParser::MainRoutineContext>(i);
}

std::vector<SixRGrammerParser::SubRoutineContext *> SixRGrammerParser::ModuleRoutinesContext::subRoutine() {
  return getRuleContexts<SixRGrammerParser::SubRoutineContext>();
}

SixRGrammerParser::SubRoutineContext* SixRGrammerParser::ModuleRoutinesContext::subRoutine(size_t i) {
  return getRuleContext<SixRGrammerParser::SubRoutineContext>(i);
}

std::vector<SixRGrammerParser::VariableDeclarationContext *> SixRGrammerParser::ModuleRoutinesContext::variableDeclaration() {
  return getRuleContexts<SixRGrammerParser::VariableDeclarationContext>();
}

SixRGrammerParser::VariableDeclarationContext* SixRGrammerParser::ModuleRoutinesContext::variableDeclaration(size_t i) {
  return getRuleContext<SixRGrammerParser::VariableDeclarationContext>(i);
}

std::vector<SixRGrammerParser::InterruptDeclarationContext *> SixRGrammerParser::ModuleRoutinesContext::interruptDeclaration() {
  return getRuleContexts<SixRGrammerParser::InterruptDeclarationContext>();
}

SixRGrammerParser::InterruptDeclarationContext* SixRGrammerParser::ModuleRoutinesContext::interruptDeclaration(size_t i) {
  return getRuleContext<SixRGrammerParser::InterruptDeclarationContext>(i);
}

std::vector<tree::TerminalNode *> SixRGrammerParser::ModuleRoutinesContext::NEWLINE() {
  return getTokens(SixRGrammerParser::NEWLINE);
}

tree::TerminalNode* SixRGrammerParser::ModuleRoutinesContext::NEWLINE(size_t i) {
  return getToken(SixRGrammerParser::NEWLINE, i);
}


size_t SixRGrammerParser::ModuleRoutinesContext::getRuleIndex() const {
  return SixRGrammerParser::RuleModuleRoutines;
}

void SixRGrammerParser::ModuleRoutinesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModuleRoutines(this);
}

void SixRGrammerParser::ModuleRoutinesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModuleRoutines(this);
}

SixRGrammerParser::ModuleRoutinesContext* SixRGrammerParser::moduleRoutines() {
  ModuleRoutinesContext *_localctx = _tracker.createInstance<ModuleRoutinesContext>(_ctx, getState());
  enterRule(_localctx, 2, SixRGrammerParser::RuleModuleRoutines);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(118);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 31) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 31)) & ((1ULL << (SixRGrammerParser::BOOL - 31))
      | (1ULL << (SixRGrammerParser::CHAR - 31))
      | (1ULL << (SixRGrammerParser::GLOBAL - 31))
      | (1ULL << (SixRGrammerParser::INTERRUPT - 31))
      | (1ULL << (SixRGrammerParser::INT - 31))
      | (1ULL << (SixRGrammerParser::MAIN - 31))
      | (1ULL << (SixRGrammerParser::FLOAT - 31)))) != 0) || ((((_la - 106) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 106)) & ((1ULL << (SixRGrammerParser::POINTJ - 106))
      | (1ULL << (SixRGrammerParser::POINTP - 106))
      | (1ULL << (SixRGrammerParser::POS - 106))
      | (1ULL << (SixRGrammerParser::ORIENT - 106))
      | (1ULL << (SixRGrammerParser::IDENTIFIER - 106))
      | (1ULL << (SixRGrammerParser::NEWLINE - 106)))) != 0)) {
      setState(116);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(111);
        mainRoutine();
        break;
      }

      case 2: {
        setState(112);
        subRoutine();
        break;
      }

      case 3: {
        setState(113);
        variableDeclaration();
        break;
      }

      case 4: {
        setState(114);
        interruptDeclaration();
        break;
      }

      case 5: {
        setState(115);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      setState(120);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MainRoutineContext ------------------------------------------------------------------

SixRGrammerParser::MainRoutineContext::MainRoutineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SixRGrammerParser::MainRoutineContext::MAIN() {
  return getToken(SixRGrammerParser::MAIN, 0);
}

std::vector<tree::TerminalNode *> SixRGrammerParser::MainRoutineContext::NEWLINE() {
  return getTokens(SixRGrammerParser::NEWLINE);
}

tree::TerminalNode* SixRGrammerParser::MainRoutineContext::NEWLINE(size_t i) {
  return getToken(SixRGrammerParser::NEWLINE, i);
}

SixRGrammerParser::RoutineBodyContext* SixRGrammerParser::MainRoutineContext::routineBody() {
  return getRuleContext<SixRGrammerParser::RoutineBodyContext>(0);
}

tree::TerminalNode* SixRGrammerParser::MainRoutineContext::END() {
  return getToken(SixRGrammerParser::END, 0);
}

tree::TerminalNode* SixRGrammerParser::MainRoutineContext::INT() {
  return getToken(SixRGrammerParser::INT, 0);
}


size_t SixRGrammerParser::MainRoutineContext::getRuleIndex() const {
  return SixRGrammerParser::RuleMainRoutine;
}

void SixRGrammerParser::MainRoutineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMainRoutine(this);
}

void SixRGrammerParser::MainRoutineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMainRoutine(this);
}

SixRGrammerParser::MainRoutineContext* SixRGrammerParser::mainRoutine() {
  MainRoutineContext *_localctx = _tracker.createInstance<MainRoutineContext>(_ctx, getState());
  enterRule(_localctx, 4, SixRGrammerParser::RuleMainRoutine);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SixRGrammerParser::INT) {
      setState(121);
      match(SixRGrammerParser::INT);
    }
    setState(124);
    match(SixRGrammerParser::MAIN);
    setState(125);
    match(SixRGrammerParser::T__0);
    setState(126);
    match(SixRGrammerParser::T__1);
    setState(127);
    match(SixRGrammerParser::NEWLINE);
    setState(128);
    routineBody();
    setState(129);
    match(SixRGrammerParser::END);
    setState(131);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(130);
      match(SixRGrammerParser::NEWLINE);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubRoutineContext ------------------------------------------------------------------

SixRGrammerParser::SubRoutineContext::SubRoutineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::ProcedureNameContext* SixRGrammerParser::SubRoutineContext::procedureName() {
  return getRuleContext<SixRGrammerParser::ProcedureNameContext>(0);
}

SixRGrammerParser::FormalParametersContext* SixRGrammerParser::SubRoutineContext::formalParameters() {
  return getRuleContext<SixRGrammerParser::FormalParametersContext>(0);
}

std::vector<tree::TerminalNode *> SixRGrammerParser::SubRoutineContext::NEWLINE() {
  return getTokens(SixRGrammerParser::NEWLINE);
}

tree::TerminalNode* SixRGrammerParser::SubRoutineContext::NEWLINE(size_t i) {
  return getToken(SixRGrammerParser::NEWLINE, i);
}

SixRGrammerParser::RoutineBodyContext* SixRGrammerParser::SubRoutineContext::routineBody() {
  return getRuleContext<SixRGrammerParser::RoutineBodyContext>(0);
}

tree::TerminalNode* SixRGrammerParser::SubRoutineContext::END() {
  return getToken(SixRGrammerParser::END, 0);
}

SixRGrammerParser::TypeContext* SixRGrammerParser::SubRoutineContext::type() {
  return getRuleContext<SixRGrammerParser::TypeContext>(0);
}


size_t SixRGrammerParser::SubRoutineContext::getRuleIndex() const {
  return SixRGrammerParser::RuleSubRoutine;
}

void SixRGrammerParser::SubRoutineContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSubRoutine(this);
}

void SixRGrammerParser::SubRoutineContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSubRoutine(this);
}

SixRGrammerParser::SubRoutineContext* SixRGrammerParser::subRoutine() {
  SubRoutineContext *_localctx = _tracker.createInstance<SubRoutineContext>(_ctx, getState());
  enterRule(_localctx, 6, SixRGrammerParser::RuleSubRoutine);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(134);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SixRGrammerParser::BOOL

    || _la == SixRGrammerParser::CHAR || ((((_la - 73) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 73)) & ((1ULL << (SixRGrammerParser::INT - 73))
      | (1ULL << (SixRGrammerParser::FLOAT - 73))
      | (1ULL << (SixRGrammerParser::POINTJ - 73))
      | (1ULL << (SixRGrammerParser::POINTP - 73))
      | (1ULL << (SixRGrammerParser::POS - 73))
      | (1ULL << (SixRGrammerParser::ORIENT - 73)))) != 0)) {
      setState(133);
      type();
    }
    setState(136);
    procedureName();
    setState(137);
    match(SixRGrammerParser::T__0);
    setState(138);
    formalParameters();
    setState(139);
    match(SixRGrammerParser::T__1);
    setState(140);
    match(SixRGrammerParser::NEWLINE);
    setState(141);
    routineBody();
    setState(142);
    match(SixRGrammerParser::END);
    setState(144);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(143);
      match(SixRGrammerParser::NEWLINE);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureNameContext ------------------------------------------------------------------

SixRGrammerParser::ProcedureNameContext::ProcedureNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SixRGrammerParser::ProcedureNameContext::IDENTIFIER() {
  return getToken(SixRGrammerParser::IDENTIFIER, 0);
}


size_t SixRGrammerParser::ProcedureNameContext::getRuleIndex() const {
  return SixRGrammerParser::RuleProcedureName;
}

void SixRGrammerParser::ProcedureNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProcedureName(this);
}

void SixRGrammerParser::ProcedureNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProcedureName(this);
}

SixRGrammerParser::ProcedureNameContext* SixRGrammerParser::procedureName() {
  ProcedureNameContext *_localctx = _tracker.createInstance<ProcedureNameContext>(_ctx, getState());
  enterRule(_localctx, 8, SixRGrammerParser::RuleProcedureName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(146);
    match(SixRGrammerParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FormalParametersContext ------------------------------------------------------------------

SixRGrammerParser::FormalParametersContext::FormalParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SixRGrammerParser::ParameterContext *> SixRGrammerParser::FormalParametersContext::parameter() {
  return getRuleContexts<SixRGrammerParser::ParameterContext>();
}

SixRGrammerParser::ParameterContext* SixRGrammerParser::FormalParametersContext::parameter(size_t i) {
  return getRuleContext<SixRGrammerParser::ParameterContext>(i);
}


size_t SixRGrammerParser::FormalParametersContext::getRuleIndex() const {
  return SixRGrammerParser::RuleFormalParameters;
}

void SixRGrammerParser::FormalParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFormalParameters(this);
}

void SixRGrammerParser::FormalParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFormalParameters(this);
}

SixRGrammerParser::FormalParametersContext* SixRGrammerParser::formalParameters() {
  FormalParametersContext *_localctx = _tracker.createInstance<FormalParametersContext>(_ctx, getState());
  enterRule(_localctx, 10, SixRGrammerParser::RuleFormalParameters);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SixRGrammerParser::BOOL

    || _la == SixRGrammerParser::CHAR || ((((_la - 73) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 73)) & ((1ULL << (SixRGrammerParser::INT - 73))
      | (1ULL << (SixRGrammerParser::FLOAT - 73))
      | (1ULL << (SixRGrammerParser::POINTJ - 73))
      | (1ULL << (SixRGrammerParser::POINTP - 73))
      | (1ULL << (SixRGrammerParser::POS - 73))
      | (1ULL << (SixRGrammerParser::ORIENT - 73)))) != 0)) {
      setState(148);
      parameter();
      setState(153);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SixRGrammerParser::T__2) {
        setState(149);
        match(SixRGrammerParser::T__2);
        setState(150);
        parameter();
        setState(155);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

SixRGrammerParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::TypeContext* SixRGrammerParser::ParameterContext::type() {
  return getRuleContext<SixRGrammerParser::TypeContext>(0);
}

SixRGrammerParser::VariableNameContext* SixRGrammerParser::ParameterContext::variableName() {
  return getRuleContext<SixRGrammerParser::VariableNameContext>(0);
}


size_t SixRGrammerParser::ParameterContext::getRuleIndex() const {
  return SixRGrammerParser::RuleParameter;
}

void SixRGrammerParser::ParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter(this);
}

void SixRGrammerParser::ParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter(this);
}

SixRGrammerParser::ParameterContext* SixRGrammerParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 12, SixRGrammerParser::RuleParameter);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(158);
    type();
    setState(159);
    variableName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RoutineBodyContext ------------------------------------------------------------------

SixRGrammerParser::RoutineBodyContext::RoutineBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::StatementListContext* SixRGrammerParser::RoutineBodyContext::statementList() {
  return getRuleContext<SixRGrammerParser::StatementListContext>(0);
}


size_t SixRGrammerParser::RoutineBodyContext::getRuleIndex() const {
  return SixRGrammerParser::RuleRoutineBody;
}

void SixRGrammerParser::RoutineBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRoutineBody(this);
}

void SixRGrammerParser::RoutineBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRoutineBody(this);
}

SixRGrammerParser::RoutineBodyContext* SixRGrammerParser::routineBody() {
  RoutineBodyContext *_localctx = _tracker.createInstance<RoutineBodyContext>(_ctx, getState());
  enterRule(_localctx, 14, SixRGrammerParser::RuleRoutineBody);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(161);
    statementList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementListContext ------------------------------------------------------------------

SixRGrammerParser::StatementListContext::StatementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SixRGrammerParser::StatementContext *> SixRGrammerParser::StatementListContext::statement() {
  return getRuleContexts<SixRGrammerParser::StatementContext>();
}

SixRGrammerParser::StatementContext* SixRGrammerParser::StatementListContext::statement(size_t i) {
  return getRuleContext<SixRGrammerParser::StatementContext>(i);
}


size_t SixRGrammerParser::StatementListContext::getRuleIndex() const {
  return SixRGrammerParser::RuleStatementList;
}

void SixRGrammerParser::StatementListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementList(this);
}

void SixRGrammerParser::StatementListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementList(this);
}

SixRGrammerParser::StatementListContext* SixRGrammerParser::statementList() {
  StatementListContext *_localctx = _tracker.createInstance<StatementListContext>(_ctx, getState());
  enterRule(_localctx, 16, SixRGrammerParser::RuleStatementList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SixRGrammerParser::T__0)
      | (1ULL << SixRGrammerParser::T__13)
      | (1ULL << SixRGrammerParser::T__14)
      | (1ULL << SixRGrammerParser::T__17)
      | (1ULL << SixRGrammerParser::BOOL)
      | (1ULL << SixRGrammerParser::BREAK)
      | (1ULL << SixRGrammerParser::CHAR)
      | (1ULL << SixRGrammerParser::CIR)
      | (1ULL << SixRGrammerParser::CONTINUE))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (SixRGrammerParser::FALSE - 65))
      | (1ULL << (SixRGrammerParser::FOR - 65))
      | (1ULL << (SixRGrammerParser::GLOBAL - 65))
      | (1ULL << (SixRGrammerParser::IF - 65))
      | (1ULL << (SixRGrammerParser::INTERRUPT - 65))
      | (1ULL << (SixRGrammerParser::INT - 65))
      | (1ULL << (SixRGrammerParser::LIN - 65))
      | (1ULL << (SixRGrammerParser::NOT - 65))
      | (1ULL << (SixRGrammerParser::PTP - 65))
      | (1ULL << (SixRGrammerParser::FLOAT - 65))
      | (1ULL << (SixRGrammerParser::RETURN - 65))
      | (1ULL << (SixRGrammerParser::SETFRAME - 65))
      | (1ULL << (SixRGrammerParser::TRUE - 65))
      | (1ULL << (SixRGrammerParser::WAIT - 65))
      | (1ULL << (SixRGrammerParser::WHILE - 65))
      | (1ULL << (SixRGrammerParser::POINTJ - 65))
      | (1ULL << (SixRGrammerParser::POINTP - 65))
      | (1ULL << (SixRGrammerParser::POS - 65))
      | (1ULL << (SixRGrammerParser::ORIENT - 65))
      | (1ULL << (SixRGrammerParser::FragINTLITERAL - 65))
      | (1ULL << (SixRGrammerParser::FragFLOATLITERAL - 65)))) != 0) || ((((_la - 129) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 129)) & ((1ULL << (SixRGrammerParser::FragCHARLITERAL - 129))
      | (1ULL << (SixRGrammerParser::FragSTRINGLITERAL - 129))
      | (1ULL << (SixRGrammerParser::IDENTIFIER - 129))
      | (1ULL << (SixRGrammerParser::NEWLINE - 129)))) != 0)) {
      setState(163);
      statement();
      setState(168);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

SixRGrammerParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SixRGrammerParser::StatementContext::getRuleIndex() const {
  return SixRGrammerParser::RuleStatement;
}

void SixRGrammerParser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- STATINTERRUPTDECContext ------------------------------------------------------------------

SixRGrammerParser::InterruptDeclarationContext* SixRGrammerParser::STATINTERRUPTDECContext::interruptDeclaration() {
  return getRuleContext<SixRGrammerParser::InterruptDeclarationContext>(0);
}

tree::TerminalNode* SixRGrammerParser::STATINTERRUPTDECContext::NEWLINE() {
  return getToken(SixRGrammerParser::NEWLINE, 0);
}

SixRGrammerParser::STATINTERRUPTDECContext::STATINTERRUPTDECContext(StatementContext *ctx) { copyFrom(ctx); }

void SixRGrammerParser::STATINTERRUPTDECContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSTATINTERRUPTDEC(this);
}
void SixRGrammerParser::STATINTERRUPTDECContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSTATINTERRUPTDEC(this);
}
//----------------- STATFORContext ------------------------------------------------------------------

tree::TerminalNode* SixRGrammerParser::STATFORContext::FOR() {
  return getToken(SixRGrammerParser::FOR, 0);
}

tree::TerminalNode* SixRGrammerParser::STATFORContext::IDENTIFIER() {
  return getToken(SixRGrammerParser::IDENTIFIER, 0);
}

std::vector<SixRGrammerParser::ExpressionContext *> SixRGrammerParser::STATFORContext::expression() {
  return getRuleContexts<SixRGrammerParser::ExpressionContext>();
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::STATFORContext::expression(size_t i) {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(i);
}

tree::TerminalNode* SixRGrammerParser::STATFORContext::TO() {
  return getToken(SixRGrammerParser::TO, 0);
}

std::vector<tree::TerminalNode *> SixRGrammerParser::STATFORContext::NEWLINE() {
  return getTokens(SixRGrammerParser::NEWLINE);
}

tree::TerminalNode* SixRGrammerParser::STATFORContext::NEWLINE(size_t i) {
  return getToken(SixRGrammerParser::NEWLINE, i);
}

SixRGrammerParser::StatementListContext* SixRGrammerParser::STATFORContext::statementList() {
  return getRuleContext<SixRGrammerParser::StatementListContext>(0);
}

tree::TerminalNode* SixRGrammerParser::STATFORContext::ENDFOR() {
  return getToken(SixRGrammerParser::ENDFOR, 0);
}

SixRGrammerParser::STATFORContext::STATFORContext(StatementContext *ctx) { copyFrom(ctx); }

void SixRGrammerParser::STATFORContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSTATFOR(this);
}
void SixRGrammerParser::STATFORContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSTATFOR(this);
}
//----------------- STATLINContext ------------------------------------------------------------------

tree::TerminalNode* SixRGrammerParser::STATLINContext::LIN() {
  return getToken(SixRGrammerParser::LIN, 0);
}

SixRGrammerParser::TargetPointContext* SixRGrammerParser::STATLINContext::targetPoint() {
  return getRuleContext<SixRGrammerParser::TargetPointContext>(0);
}

SixRGrammerParser::FfExprContext* SixRGrammerParser::STATLINContext::ffExpr() {
  return getRuleContext<SixRGrammerParser::FfExprContext>(0);
}

SixRGrammerParser::ConExprContext* SixRGrammerParser::STATLINContext::conExpr() {
  return getRuleContext<SixRGrammerParser::ConExprContext>(0);
}

SixRGrammerParser::ApprxExprContext* SixRGrammerParser::STATLINContext::apprxExpr() {
  return getRuleContext<SixRGrammerParser::ApprxExprContext>(0);
}

tree::TerminalNode* SixRGrammerParser::STATLINContext::NEWLINE() {
  return getToken(SixRGrammerParser::NEWLINE, 0);
}

SixRGrammerParser::STATLINContext::STATLINContext(StatementContext *ctx) { copyFrom(ctx); }

void SixRGrammerParser::STATLINContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSTATLIN(this);
}
void SixRGrammerParser::STATLINContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSTATLIN(this);
}
//----------------- STATINTERRUPTContext ------------------------------------------------------------------

SixRGrammerParser::InterruptPriorityContext* SixRGrammerParser::STATINTERRUPTContext::interruptPriority() {
  return getRuleContext<SixRGrammerParser::InterruptPriorityContext>(0);
}

tree::TerminalNode* SixRGrammerParser::STATINTERRUPTContext::NEWLINE() {
  return getToken(SixRGrammerParser::NEWLINE, 0);
}

SixRGrammerParser::STATINTERRUPTContext::STATINTERRUPTContext(StatementContext *ctx) { copyFrom(ctx); }

void SixRGrammerParser::STATINTERRUPTContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSTATINTERRUPT(this);
}
void SixRGrammerParser::STATINTERRUPTContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSTATINTERRUPT(this);
}
//----------------- STATCONTINUEContext ------------------------------------------------------------------

tree::TerminalNode* SixRGrammerParser::STATCONTINUEContext::CONTINUE() {
  return getToken(SixRGrammerParser::CONTINUE, 0);
}

tree::TerminalNode* SixRGrammerParser::STATCONTINUEContext::NEWLINE() {
  return getToken(SixRGrammerParser::NEWLINE, 0);
}

SixRGrammerParser::STATCONTINUEContext::STATCONTINUEContext(StatementContext *ctx) { copyFrom(ctx); }

void SixRGrammerParser::STATCONTINUEContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSTATCONTINUE(this);
}
void SixRGrammerParser::STATCONTINUEContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSTATCONTINUE(this);
}
//----------------- STATPTPContext ------------------------------------------------------------------

tree::TerminalNode* SixRGrammerParser::STATPTPContext::PTP() {
  return getToken(SixRGrammerParser::PTP, 0);
}

SixRGrammerParser::TargetPointContext* SixRGrammerParser::STATPTPContext::targetPoint() {
  return getRuleContext<SixRGrammerParser::TargetPointContext>(0);
}

SixRGrammerParser::FfExprContext* SixRGrammerParser::STATPTPContext::ffExpr() {
  return getRuleContext<SixRGrammerParser::FfExprContext>(0);
}

SixRGrammerParser::ConExprContext* SixRGrammerParser::STATPTPContext::conExpr() {
  return getRuleContext<SixRGrammerParser::ConExprContext>(0);
}

SixRGrammerParser::ApprxExprContext* SixRGrammerParser::STATPTPContext::apprxExpr() {
  return getRuleContext<SixRGrammerParser::ApprxExprContext>(0);
}

tree::TerminalNode* SixRGrammerParser::STATPTPContext::NEWLINE() {
  return getToken(SixRGrammerParser::NEWLINE, 0);
}

SixRGrammerParser::STATPTPContext::STATPTPContext(StatementContext *ctx) { copyFrom(ctx); }

void SixRGrammerParser::STATPTPContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSTATPTP(this);
}
void SixRGrammerParser::STATPTPContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSTATPTP(this);
}
//----------------- STATCIRContext ------------------------------------------------------------------

tree::TerminalNode* SixRGrammerParser::STATCIRContext::CIR() {
  return getToken(SixRGrammerParser::CIR, 0);
}

std::vector<SixRGrammerParser::TargetPointContext *> SixRGrammerParser::STATCIRContext::targetPoint() {
  return getRuleContexts<SixRGrammerParser::TargetPointContext>();
}

SixRGrammerParser::TargetPointContext* SixRGrammerParser::STATCIRContext::targetPoint(size_t i) {
  return getRuleContext<SixRGrammerParser::TargetPointContext>(i);
}

SixRGrammerParser::ThetaExprContext* SixRGrammerParser::STATCIRContext::thetaExpr() {
  return getRuleContext<SixRGrammerParser::ThetaExprContext>(0);
}

SixRGrammerParser::FfExprContext* SixRGrammerParser::STATCIRContext::ffExpr() {
  return getRuleContext<SixRGrammerParser::FfExprContext>(0);
}

SixRGrammerParser::ConExprContext* SixRGrammerParser::STATCIRContext::conExpr() {
  return getRuleContext<SixRGrammerParser::ConExprContext>(0);
}

SixRGrammerParser::ApprxExprContext* SixRGrammerParser::STATCIRContext::apprxExpr() {
  return getRuleContext<SixRGrammerParser::ApprxExprContext>(0);
}

tree::TerminalNode* SixRGrammerParser::STATCIRContext::NEWLINE() {
  return getToken(SixRGrammerParser::NEWLINE, 0);
}

SixRGrammerParser::STATCIRContext::STATCIRContext(StatementContext *ctx) { copyFrom(ctx); }

void SixRGrammerParser::STATCIRContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSTATCIR(this);
}
void SixRGrammerParser::STATCIRContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSTATCIR(this);
}
//----------------- STATBRAKEContext ------------------------------------------------------------------

tree::TerminalNode* SixRGrammerParser::STATBRAKEContext::BREAK() {
  return getToken(SixRGrammerParser::BREAK, 0);
}

tree::TerminalNode* SixRGrammerParser::STATBRAKEContext::NEWLINE() {
  return getToken(SixRGrammerParser::NEWLINE, 0);
}

SixRGrammerParser::STATBRAKEContext::STATBRAKEContext(StatementContext *ctx) { copyFrom(ctx); }

void SixRGrammerParser::STATBRAKEContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSTATBRAKE(this);
}
void SixRGrammerParser::STATBRAKEContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSTATBRAKE(this);
}
//----------------- STATIFContext ------------------------------------------------------------------

tree::TerminalNode* SixRGrammerParser::STATIFContext::IF() {
  return getToken(SixRGrammerParser::IF, 0);
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::STATIFContext::expression() {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(0);
}

tree::TerminalNode* SixRGrammerParser::STATIFContext::THEN() {
  return getToken(SixRGrammerParser::THEN, 0);
}

std::vector<tree::TerminalNode *> SixRGrammerParser::STATIFContext::NEWLINE() {
  return getTokens(SixRGrammerParser::NEWLINE);
}

tree::TerminalNode* SixRGrammerParser::STATIFContext::NEWLINE(size_t i) {
  return getToken(SixRGrammerParser::NEWLINE, i);
}

std::vector<SixRGrammerParser::StatementListContext *> SixRGrammerParser::STATIFContext::statementList() {
  return getRuleContexts<SixRGrammerParser::StatementListContext>();
}

SixRGrammerParser::StatementListContext* SixRGrammerParser::STATIFContext::statementList(size_t i) {
  return getRuleContext<SixRGrammerParser::StatementListContext>(i);
}

tree::TerminalNode* SixRGrammerParser::STATIFContext::ENDIF() {
  return getToken(SixRGrammerParser::ENDIF, 0);
}

tree::TerminalNode* SixRGrammerParser::STATIFContext::ELSE() {
  return getToken(SixRGrammerParser::ELSE, 0);
}

SixRGrammerParser::STATIFContext::STATIFContext(StatementContext *ctx) { copyFrom(ctx); }

void SixRGrammerParser::STATIFContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSTATIF(this);
}
void SixRGrammerParser::STATIFContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSTATIF(this);
}
//----------------- STATNEWLINEContext ------------------------------------------------------------------

tree::TerminalNode* SixRGrammerParser::STATNEWLINEContext::NEWLINE() {
  return getToken(SixRGrammerParser::NEWLINE, 0);
}

SixRGrammerParser::STATNEWLINEContext::STATNEWLINEContext(StatementContext *ctx) { copyFrom(ctx); }

void SixRGrammerParser::STATNEWLINEContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSTATNEWLINE(this);
}
void SixRGrammerParser::STATNEWLINEContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSTATNEWLINE(this);
}
//----------------- STATSCFContext ------------------------------------------------------------------

tree::TerminalNode* SixRGrammerParser::STATSCFContext::SETFRAME() {
  return getToken(SixRGrammerParser::SETFRAME, 0);
}

tree::TerminalNode* SixRGrammerParser::STATSCFContext::FrameType() {
  return getToken(SixRGrammerParser::FrameType, 0);
}

SixRGrammerParser::VariableNameContext* SixRGrammerParser::STATSCFContext::variableName() {
  return getRuleContext<SixRGrammerParser::VariableNameContext>(0);
}

tree::TerminalNode* SixRGrammerParser::STATSCFContext::NEWLINE() {
  return getToken(SixRGrammerParser::NEWLINE, 0);
}

SixRGrammerParser::STATSCFContext::STATSCFContext(StatementContext *ctx) { copyFrom(ctx); }

void SixRGrammerParser::STATSCFContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSTATSCF(this);
}
void SixRGrammerParser::STATSCFContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSTATSCF(this);
}
//----------------- STATWAITFORContext ------------------------------------------------------------------

tree::TerminalNode* SixRGrammerParser::STATWAITFORContext::WAIT() {
  return getToken(SixRGrammerParser::WAIT, 0);
}

tree::TerminalNode* SixRGrammerParser::STATWAITFORContext::FOR() {
  return getToken(SixRGrammerParser::FOR, 0);
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::STATWAITFORContext::expression() {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(0);
}

tree::TerminalNode* SixRGrammerParser::STATWAITFORContext::NEWLINE() {
  return getToken(SixRGrammerParser::NEWLINE, 0);
}

SixRGrammerParser::STATWAITFORContext::STATWAITFORContext(StatementContext *ctx) { copyFrom(ctx); }

void SixRGrammerParser::STATWAITFORContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSTATWAITFOR(this);
}
void SixRGrammerParser::STATWAITFORContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSTATWAITFOR(this);
}
//----------------- STATWHILEContext ------------------------------------------------------------------

tree::TerminalNode* SixRGrammerParser::STATWHILEContext::WHILE() {
  return getToken(SixRGrammerParser::WHILE, 0);
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::STATWHILEContext::expression() {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(0);
}

std::vector<tree::TerminalNode *> SixRGrammerParser::STATWHILEContext::NEWLINE() {
  return getTokens(SixRGrammerParser::NEWLINE);
}

tree::TerminalNode* SixRGrammerParser::STATWHILEContext::NEWLINE(size_t i) {
  return getToken(SixRGrammerParser::NEWLINE, i);
}

SixRGrammerParser::StatementListContext* SixRGrammerParser::STATWHILEContext::statementList() {
  return getRuleContext<SixRGrammerParser::StatementListContext>(0);
}

tree::TerminalNode* SixRGrammerParser::STATWHILEContext::ENDWHILE() {
  return getToken(SixRGrammerParser::ENDWHILE, 0);
}

SixRGrammerParser::STATWHILEContext::STATWHILEContext(StatementContext *ctx) { copyFrom(ctx); }

void SixRGrammerParser::STATWHILEContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSTATWHILE(this);
}
void SixRGrammerParser::STATWHILEContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSTATWHILE(this);
}
//----------------- STATRETURNContext ------------------------------------------------------------------

tree::TerminalNode* SixRGrammerParser::STATRETURNContext::RETURN() {
  return getToken(SixRGrammerParser::RETURN, 0);
}

tree::TerminalNode* SixRGrammerParser::STATRETURNContext::NEWLINE() {
  return getToken(SixRGrammerParser::NEWLINE, 0);
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::STATRETURNContext::expression() {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(0);
}

SixRGrammerParser::STATRETURNContext::STATRETURNContext(StatementContext *ctx) { copyFrom(ctx); }

void SixRGrammerParser::STATRETURNContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSTATRETURN(this);
}
void SixRGrammerParser::STATRETURNContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSTATRETURN(this);
}
//----------------- STATVARDECContext ------------------------------------------------------------------

SixRGrammerParser::VariableDeclarationContext* SixRGrammerParser::STATVARDECContext::variableDeclaration() {
  return getRuleContext<SixRGrammerParser::VariableDeclarationContext>(0);
}

tree::TerminalNode* SixRGrammerParser::STATVARDECContext::NEWLINE() {
  return getToken(SixRGrammerParser::NEWLINE, 0);
}

SixRGrammerParser::STATVARDECContext::STATVARDECContext(StatementContext *ctx) { copyFrom(ctx); }

void SixRGrammerParser::STATVARDECContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSTATVARDEC(this);
}
void SixRGrammerParser::STATVARDECContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSTATVARDEC(this);
}
//----------------- STATASINEPRContext ------------------------------------------------------------------

SixRGrammerParser::AssignmentExpressionContext* SixRGrammerParser::STATASINEPRContext::assignmentExpression() {
  return getRuleContext<SixRGrammerParser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* SixRGrammerParser::STATASINEPRContext::NEWLINE() {
  return getToken(SixRGrammerParser::NEWLINE, 0);
}

SixRGrammerParser::STATASINEPRContext::STATASINEPRContext(StatementContext *ctx) { copyFrom(ctx); }

void SixRGrammerParser::STATASINEPRContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSTATASINEPR(this);
}
void SixRGrammerParser::STATASINEPRContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSTATASINEPR(this);
}
//----------------- STATEXPContext ------------------------------------------------------------------

SixRGrammerParser::ExpressionContext* SixRGrammerParser::STATEXPContext::expression() {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(0);
}

tree::TerminalNode* SixRGrammerParser::STATEXPContext::NEWLINE() {
  return getToken(SixRGrammerParser::NEWLINE, 0);
}

SixRGrammerParser::STATEXPContext::STATEXPContext(StatementContext *ctx) { copyFrom(ctx); }

void SixRGrammerParser::STATEXPContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSTATEXP(this);
}
void SixRGrammerParser::STATEXPContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSTATEXP(this);
}
//----------------- STATWAITSECContext ------------------------------------------------------------------

tree::TerminalNode* SixRGrammerParser::STATWAITSECContext::WAIT() {
  return getToken(SixRGrammerParser::WAIT, 0);
}

tree::TerminalNode* SixRGrammerParser::STATWAITSECContext::SEC() {
  return getToken(SixRGrammerParser::SEC, 0);
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::STATWAITSECContext::expression() {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(0);
}

tree::TerminalNode* SixRGrammerParser::STATWAITSECContext::NEWLINE() {
  return getToken(SixRGrammerParser::NEWLINE, 0);
}

SixRGrammerParser::STATWAITSECContext::STATWAITSECContext(StatementContext *ctx) { copyFrom(ctx); }

void SixRGrammerParser::STATWAITSECContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSTATWAITSEC(this);
}
void SixRGrammerParser::STATWAITSECContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSTATWAITSEC(this);
}
SixRGrammerParser::StatementContext* SixRGrammerParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 18, SixRGrammerParser::RuleStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(300);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATCONTINUEContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(169);
      match(SixRGrammerParser::CONTINUE);
      setState(170);
      match(SixRGrammerParser::NEWLINE);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATFORContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(171);
      match(SixRGrammerParser::FOR);
      setState(172);
      match(SixRGrammerParser::IDENTIFIER);
      setState(173);
      match(SixRGrammerParser::T__3);
      setState(174);
      expression();
      setState(175);
      match(SixRGrammerParser::TO);
      setState(176);
      expression();
      setState(177);
      match(SixRGrammerParser::NEWLINE);
      setState(178);
      statementList();
      setState(179);
      match(SixRGrammerParser::ENDFOR);
      setState(181);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
      case 1: {
        setState(180);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATIFContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(183);
      match(SixRGrammerParser::IF);
      setState(184);
      expression();
      setState(185);
      match(SixRGrammerParser::THEN);
      setState(186);
      match(SixRGrammerParser::NEWLINE);
      setState(187);
      statementList();
      setState(191);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SixRGrammerParser::ELSE) {
        setState(188);
        match(SixRGrammerParser::ELSE);
        setState(189);
        match(SixRGrammerParser::NEWLINE);
        setState(190);
        statementList();
      }
      setState(193);
      match(SixRGrammerParser::ENDIF);
      setState(195);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
      case 1: {
        setState(194);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATWAITFORContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(197);
      match(SixRGrammerParser::WAIT);
      setState(198);
      match(SixRGrammerParser::FOR);
      setState(199);
      expression();
      setState(201);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
      case 1: {
        setState(200);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATWAITSECContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(203);
      match(SixRGrammerParser::WAIT);
      setState(204);
      match(SixRGrammerParser::SEC);
      setState(205);
      expression();
      setState(207);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
      case 1: {
        setState(206);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATWHILEContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(209);
      match(SixRGrammerParser::WHILE);
      setState(210);
      expression();
      setState(211);
      match(SixRGrammerParser::NEWLINE);
      setState(212);
      statementList();
      setState(213);
      match(SixRGrammerParser::ENDWHILE);
      setState(215);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
      case 1: {
        setState(214);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATRETURNContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(217);
      match(SixRGrammerParser::RETURN);
      setState(219);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SixRGrammerParser::T__0)
        | (1ULL << SixRGrammerParser::T__13)
        | (1ULL << SixRGrammerParser::T__14)
        | (1ULL << SixRGrammerParser::T__17))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 65)) & ((1ULL << (SixRGrammerParser::FALSE - 65))
        | (1ULL << (SixRGrammerParser::NOT - 65))
        | (1ULL << (SixRGrammerParser::TRUE - 65))
        | (1ULL << (SixRGrammerParser::FragINTLITERAL - 65))
        | (1ULL << (SixRGrammerParser::FragFLOATLITERAL - 65)))) != 0) || ((((_la - 129) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 129)) & ((1ULL << (SixRGrammerParser::FragCHARLITERAL - 129))
        | (1ULL << (SixRGrammerParser::FragSTRINGLITERAL - 129))
        | (1ULL << (SixRGrammerParser::IDENTIFIER - 129)))) != 0)) {
        setState(218);
        expression();
      }
      setState(221);
      match(SixRGrammerParser::NEWLINE);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATASINEPRContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(222);
      assignmentExpression();
      setState(224);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
      case 1: {
        setState(223);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 9: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATEXPContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(226);
      expression();
      setState(228);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
      case 1: {
        setState(227);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 10: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATBRAKEContext>(_localctx));
      enterOuterAlt(_localctx, 10);
      setState(230);
      match(SixRGrammerParser::BREAK);
      setState(231);
      match(SixRGrammerParser::NEWLINE);
      break;
    }

    case 11: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATPTPContext>(_localctx));
      enterOuterAlt(_localctx, 11);
      setState(232);
      match(SixRGrammerParser::PTP);
      setState(233);
      targetPoint();
      setState(235);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SixRGrammerParser::FF) {
        setState(234);
        ffExpr();
      }
      setState(238);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SixRGrammerParser::CON) {
        setState(237);
        conExpr();
      }
      setState(241);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SixRGrammerParser::Apprx) {
        setState(240);
        apprxExpr();
      }
      setState(244);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
      case 1: {
        setState(243);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 12: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATLINContext>(_localctx));
      enterOuterAlt(_localctx, 12);
      setState(246);
      match(SixRGrammerParser::LIN);
      setState(247);
      targetPoint();
      setState(249);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SixRGrammerParser::FF) {
        setState(248);
        ffExpr();
      }
      setState(252);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SixRGrammerParser::CON) {
        setState(251);
        conExpr();
      }
      setState(255);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SixRGrammerParser::Apprx) {
        setState(254);
        apprxExpr();
      }
      setState(258);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
      case 1: {
        setState(257);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 13: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATCIRContext>(_localctx));
      enterOuterAlt(_localctx, 13);
      setState(260);
      match(SixRGrammerParser::CIR);
      setState(261);
      targetPoint();
      setState(262);
      targetPoint();
      setState(264);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
      case 1: {
        setState(263);
        targetPoint();
        break;
      }

      }
      setState(267);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SixRGrammerParser::THETA) {
        setState(266);
        thetaExpr();
      }
      setState(270);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SixRGrammerParser::FF) {
        setState(269);
        ffExpr();
      }
      setState(273);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SixRGrammerParser::CON) {
        setState(272);
        conExpr();
      }
      setState(276);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SixRGrammerParser::Apprx) {
        setState(275);
        apprxExpr();
      }
      setState(279);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
      case 1: {
        setState(278);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 14: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATVARDECContext>(_localctx));
      enterOuterAlt(_localctx, 14);
      setState(281);
      variableDeclaration();
      setState(283);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
      case 1: {
        setState(282);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 15: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATSCFContext>(_localctx));
      enterOuterAlt(_localctx, 15);
      setState(285);
      match(SixRGrammerParser::SETFRAME);
      setState(286);
      match(SixRGrammerParser::FrameType);
      setState(287);
      variableName();
      setState(289);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx)) {
      case 1: {
        setState(288);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 16: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATNEWLINEContext>(_localctx));
      enterOuterAlt(_localctx, 16);
      setState(291);
      match(SixRGrammerParser::NEWLINE);
      break;
    }

    case 17: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATINTERRUPTDECContext>(_localctx));
      enterOuterAlt(_localctx, 17);
      setState(292);
      interruptDeclaration();
      setState(294);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
      case 1: {
        setState(293);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 18: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATINTERRUPTContext>(_localctx));
      enterOuterAlt(_localctx, 18);
      setState(296);
      interruptPriority();
      setState(298);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 35, _ctx)) {
      case 1: {
        setState(297);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TargetPointContext ------------------------------------------------------------------

SixRGrammerParser::TargetPointContext::TargetPointContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::SixRJXPointContext* SixRGrammerParser::TargetPointContext::sixRJXPoint() {
  return getRuleContext<SixRGrammerParser::SixRJXPointContext>(0);
}

SixRGrammerParser::VariableNameContext* SixRGrammerParser::TargetPointContext::variableName() {
  return getRuleContext<SixRGrammerParser::VariableNameContext>(0);
}


size_t SixRGrammerParser::TargetPointContext::getRuleIndex() const {
  return SixRGrammerParser::RuleTargetPoint;
}

void SixRGrammerParser::TargetPointContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTargetPoint(this);
}

void SixRGrammerParser::TargetPointContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTargetPoint(this);
}

SixRGrammerParser::TargetPointContext* SixRGrammerParser::targetPoint() {
  TargetPointContext *_localctx = _tracker.createInstance<TargetPointContext>(_ctx, getState());
  enterRule(_localctx, 20, SixRGrammerParser::RuleTargetPoint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(304);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SixRGrammerParser::T__4: {
        setState(302);
        sixRJXPoint();
        break;
      }

      case SixRGrammerParser::IDENTIFIER: {
        setState(303);
        variableName();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ApprxExprContext ------------------------------------------------------------------

SixRGrammerParser::ApprxExprContext::ApprxExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SixRGrammerParser::ApprxExprContext::Apprx() {
  return getToken(SixRGrammerParser::Apprx, 0);
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::ApprxExprContext::expression() {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(0);
}


size_t SixRGrammerParser::ApprxExprContext::getRuleIndex() const {
  return SixRGrammerParser::RuleApprxExpr;
}

void SixRGrammerParser::ApprxExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterApprxExpr(this);
}

void SixRGrammerParser::ApprxExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitApprxExpr(this);
}

SixRGrammerParser::ApprxExprContext* SixRGrammerParser::apprxExpr() {
  ApprxExprContext *_localctx = _tracker.createInstance<ApprxExprContext>(_ctx, getState());
  enterRule(_localctx, 22, SixRGrammerParser::RuleApprxExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(306);
    match(SixRGrammerParser::Apprx);
    setState(307);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FfExprContext ------------------------------------------------------------------

SixRGrammerParser::FfExprContext::FfExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SixRGrammerParser::FfExprContext::FF() {
  return getToken(SixRGrammerParser::FF, 0);
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::FfExprContext::expression() {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(0);
}


size_t SixRGrammerParser::FfExprContext::getRuleIndex() const {
  return SixRGrammerParser::RuleFfExpr;
}

void SixRGrammerParser::FfExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFfExpr(this);
}

void SixRGrammerParser::FfExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFfExpr(this);
}

SixRGrammerParser::FfExprContext* SixRGrammerParser::ffExpr() {
  FfExprContext *_localctx = _tracker.createInstance<FfExprContext>(_ctx, getState());
  enterRule(_localctx, 24, SixRGrammerParser::RuleFfExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(309);
    match(SixRGrammerParser::FF);
    setState(310);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConExprContext ------------------------------------------------------------------

SixRGrammerParser::ConExprContext::ConExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SixRGrammerParser::ConExprContext::CON() {
  return getToken(SixRGrammerParser::CON, 0);
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::ConExprContext::expression() {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(0);
}


size_t SixRGrammerParser::ConExprContext::getRuleIndex() const {
  return SixRGrammerParser::RuleConExpr;
}

void SixRGrammerParser::ConExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConExpr(this);
}

void SixRGrammerParser::ConExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConExpr(this);
}

SixRGrammerParser::ConExprContext* SixRGrammerParser::conExpr() {
  ConExprContext *_localctx = _tracker.createInstance<ConExprContext>(_ctx, getState());
  enterRule(_localctx, 26, SixRGrammerParser::RuleConExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(312);
    match(SixRGrammerParser::CON);
    setState(313);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThetaExprContext ------------------------------------------------------------------

SixRGrammerParser::ThetaExprContext::ThetaExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SixRGrammerParser::ThetaExprContext::THETA() {
  return getToken(SixRGrammerParser::THETA, 0);
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::ThetaExprContext::expression() {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(0);
}


size_t SixRGrammerParser::ThetaExprContext::getRuleIndex() const {
  return SixRGrammerParser::RuleThetaExpr;
}

void SixRGrammerParser::ThetaExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThetaExpr(this);
}

void SixRGrammerParser::ThetaExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThetaExpr(this);
}

SixRGrammerParser::ThetaExprContext* SixRGrammerParser::thetaExpr() {
  ThetaExprContext *_localctx = _tracker.createInstance<ThetaExprContext>(_ctx, getState());
  enterRule(_localctx, 28, SixRGrammerParser::RuleThetaExpr);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(315);
    match(SixRGrammerParser::THETA);
    setState(316);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InterruptDeclarationContext ------------------------------------------------------------------

SixRGrammerParser::InterruptDeclarationContext::InterruptDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SixRGrammerParser::InterruptDeclarationContext::INTERRUPT() {
  return getToken(SixRGrammerParser::INTERRUPT, 0);
}

tree::TerminalNode* SixRGrammerParser::InterruptDeclarationContext::DECL() {
  return getToken(SixRGrammerParser::DECL, 0);
}

tree::TerminalNode* SixRGrammerParser::InterruptDeclarationContext::IDENTIFIER() {
  return getToken(SixRGrammerParser::IDENTIFIER, 0);
}

SixRGrammerParser::PrimaryContext* SixRGrammerParser::InterruptDeclarationContext::primary() {
  return getRuleContext<SixRGrammerParser::PrimaryContext>(0);
}

tree::TerminalNode* SixRGrammerParser::InterruptDeclarationContext::WHEN() {
  return getToken(SixRGrammerParser::WHEN, 0);
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::InterruptDeclarationContext::expression() {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(0);
}

tree::TerminalNode* SixRGrammerParser::InterruptDeclarationContext::DO() {
  return getToken(SixRGrammerParser::DO, 0);
}

SixRGrammerParser::AssignmentExpressionContext* SixRGrammerParser::InterruptDeclarationContext::assignmentExpression() {
  return getRuleContext<SixRGrammerParser::AssignmentExpressionContext>(0);
}

tree::TerminalNode* SixRGrammerParser::InterruptDeclarationContext::GLOBAL() {
  return getToken(SixRGrammerParser::GLOBAL, 0);
}


size_t SixRGrammerParser::InterruptDeclarationContext::getRuleIndex() const {
  return SixRGrammerParser::RuleInterruptDeclaration;
}

void SixRGrammerParser::InterruptDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterruptDeclaration(this);
}

void SixRGrammerParser::InterruptDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterruptDeclaration(this);
}

SixRGrammerParser::InterruptDeclarationContext* SixRGrammerParser::interruptDeclaration() {
  InterruptDeclarationContext *_localctx = _tracker.createInstance<InterruptDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 30, SixRGrammerParser::RuleInterruptDeclaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SixRGrammerParser::GLOBAL) {
      setState(318);
      match(SixRGrammerParser::GLOBAL);
    }
    setState(321);
    match(SixRGrammerParser::INTERRUPT);
    setState(322);
    match(SixRGrammerParser::DECL);
    setState(323);
    match(SixRGrammerParser::IDENTIFIER);
    setState(324);
    primary();
    setState(325);
    match(SixRGrammerParser::WHEN);
    setState(326);
    expression();
    setState(327);
    match(SixRGrammerParser::DO);
    setState(328);
    assignmentExpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InterruptPriorityContext ------------------------------------------------------------------

SixRGrammerParser::InterruptPriorityContext::InterruptPriorityContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SixRGrammerParser::InterruptPriorityContext::INTERRUPT() {
  return getToken(SixRGrammerParser::INTERRUPT, 0);
}

tree::TerminalNode* SixRGrammerParser::InterruptPriorityContext::IDENTIFIER() {
  return getToken(SixRGrammerParser::IDENTIFIER, 0);
}

SixRGrammerParser::PrimaryContext* SixRGrammerParser::InterruptPriorityContext::primary() {
  return getRuleContext<SixRGrammerParser::PrimaryContext>(0);
}


size_t SixRGrammerParser::InterruptPriorityContext::getRuleIndex() const {
  return SixRGrammerParser::RuleInterruptPriority;
}

void SixRGrammerParser::InterruptPriorityContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterruptPriority(this);
}

void SixRGrammerParser::InterruptPriorityContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterruptPriority(this);
}

SixRGrammerParser::InterruptPriorityContext* SixRGrammerParser::interruptPriority() {
  InterruptPriorityContext *_localctx = _tracker.createInstance<InterruptPriorityContext>(_ctx, getState());
  enterRule(_localctx, 32, SixRGrammerParser::RuleInterruptPriority);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(330);
    match(SixRGrammerParser::INTERRUPT);
    setState(331);
    match(SixRGrammerParser::IDENTIFIER);
    setState(333);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      setState(332);
      primary();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationContext ------------------------------------------------------------------

SixRGrammerParser::VariableDeclarationContext::VariableDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::TypeContext* SixRGrammerParser::VariableDeclarationContext::type() {
  return getRuleContext<SixRGrammerParser::TypeContext>(0);
}

SixRGrammerParser::VariableNameContext* SixRGrammerParser::VariableDeclarationContext::variableName() {
  return getRuleContext<SixRGrammerParser::VariableNameContext>(0);
}

SixRGrammerParser::VariableListRestContext* SixRGrammerParser::VariableDeclarationContext::variableListRest() {
  return getRuleContext<SixRGrammerParser::VariableListRestContext>(0);
}

SixRGrammerParser::VariableInitialisationContext* SixRGrammerParser::VariableDeclarationContext::variableInitialisation() {
  return getRuleContext<SixRGrammerParser::VariableInitialisationContext>(0);
}


size_t SixRGrammerParser::VariableDeclarationContext::getRuleIndex() const {
  return SixRGrammerParser::RuleVariableDeclaration;
}

void SixRGrammerParser::VariableDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableDeclaration(this);
}

void SixRGrammerParser::VariableDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableDeclaration(this);
}

SixRGrammerParser::VariableDeclarationContext* SixRGrammerParser::variableDeclaration() {
  VariableDeclarationContext *_localctx = _tracker.createInstance<VariableDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 34, SixRGrammerParser::RuleVariableDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(335);
    type();
    setState(336);
    variableName();
    setState(339);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SixRGrammerParser::EOF:
      case SixRGrammerParser::T__0:
      case SixRGrammerParser::T__2:
      case SixRGrammerParser::T__13:
      case SixRGrammerParser::T__14:
      case SixRGrammerParser::T__17:
      case SixRGrammerParser::BOOL:
      case SixRGrammerParser::BREAK:
      case SixRGrammerParser::CHAR:
      case SixRGrammerParser::CIR:
      case SixRGrammerParser::CONTINUE:
      case SixRGrammerParser::ELSE:
      case SixRGrammerParser::END:
      case SixRGrammerParser::ENDFOR:
      case SixRGrammerParser::ENDIF:
      case SixRGrammerParser::ENDWHILE:
      case SixRGrammerParser::FALSE:
      case SixRGrammerParser::FOR:
      case SixRGrammerParser::GLOBAL:
      case SixRGrammerParser::IF:
      case SixRGrammerParser::INTERRUPT:
      case SixRGrammerParser::INT:
      case SixRGrammerParser::LIN:
      case SixRGrammerParser::MAIN:
      case SixRGrammerParser::NOT:
      case SixRGrammerParser::PTP:
      case SixRGrammerParser::FLOAT:
      case SixRGrammerParser::RETURN:
      case SixRGrammerParser::SETFRAME:
      case SixRGrammerParser::TRUE:
      case SixRGrammerParser::WAIT:
      case SixRGrammerParser::WHILE:
      case SixRGrammerParser::POINTJ:
      case SixRGrammerParser::POINTP:
      case SixRGrammerParser::POS:
      case SixRGrammerParser::ORIENT:
      case SixRGrammerParser::FragINTLITERAL:
      case SixRGrammerParser::FragFLOATLITERAL:
      case SixRGrammerParser::FragCHARLITERAL:
      case SixRGrammerParser::FragSTRINGLITERAL:
      case SixRGrammerParser::IDENTIFIER:
      case SixRGrammerParser::NEWLINE: {
        setState(337);
        variableListRest();
        break;
      }

      case SixRGrammerParser::T__3: {
        setState(338);
        variableInitialisation();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableInitialisationContext ------------------------------------------------------------------

SixRGrammerParser::VariableInitialisationContext::VariableInitialisationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::VariableInitialisationContext::expression() {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(0);
}

SixRGrammerParser::SixRJPRContext* SixRGrammerParser::VariableInitialisationContext::sixRJPR() {
  return getRuleContext<SixRGrammerParser::SixRJPRContext>(0);
}


size_t SixRGrammerParser::VariableInitialisationContext::getRuleIndex() const {
  return SixRGrammerParser::RuleVariableInitialisation;
}

void SixRGrammerParser::VariableInitialisationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableInitialisation(this);
}

void SixRGrammerParser::VariableInitialisationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableInitialisation(this);
}

SixRGrammerParser::VariableInitialisationContext* SixRGrammerParser::variableInitialisation() {
  VariableInitialisationContext *_localctx = _tracker.createInstance<VariableInitialisationContext>(_ctx, getState());
  enterRule(_localctx, 36, SixRGrammerParser::RuleVariableInitialisation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(341);
    match(SixRGrammerParser::T__3);
    setState(344);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      setState(342);
      expression();
      break;
    }

    case 2: {
      setState(343);
      sixRJPR();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableListRestContext ------------------------------------------------------------------

SixRGrammerParser::VariableListRestContext::VariableListRestContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SixRGrammerParser::VariableNameContext *> SixRGrammerParser::VariableListRestContext::variableName() {
  return getRuleContexts<SixRGrammerParser::VariableNameContext>();
}

SixRGrammerParser::VariableNameContext* SixRGrammerParser::VariableListRestContext::variableName(size_t i) {
  return getRuleContext<SixRGrammerParser::VariableNameContext>(i);
}


size_t SixRGrammerParser::VariableListRestContext::getRuleIndex() const {
  return SixRGrammerParser::RuleVariableListRest;
}

void SixRGrammerParser::VariableListRestContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableListRest(this);
}

void SixRGrammerParser::VariableListRestContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableListRest(this);
}

SixRGrammerParser::VariableListRestContext* SixRGrammerParser::variableListRest() {
  VariableListRestContext *_localctx = _tracker.createInstance<VariableListRestContext>(_ctx, getState());
  enterRule(_localctx, 38, SixRGrammerParser::RuleVariableListRest);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(350);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SixRGrammerParser::T__2) {
      setState(346);
      match(SixRGrammerParser::T__2);
      setState(347);
      variableName();
      setState(352);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentExpressionContext ------------------------------------------------------------------

SixRGrammerParser::AssignmentExpressionContext::AssignmentExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::VariableNameContext* SixRGrammerParser::AssignmentExpressionContext::variableName() {
  return getRuleContext<SixRGrammerParser::VariableNameContext>(0);
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::AssignmentExpressionContext::expression() {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(0);
}

SixRGrammerParser::SixRJPRContext* SixRGrammerParser::AssignmentExpressionContext::sixRJPR() {
  return getRuleContext<SixRGrammerParser::SixRJPRContext>(0);
}


size_t SixRGrammerParser::AssignmentExpressionContext::getRuleIndex() const {
  return SixRGrammerParser::RuleAssignmentExpression;
}

void SixRGrammerParser::AssignmentExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentExpression(this);
}

void SixRGrammerParser::AssignmentExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentExpression(this);
}

SixRGrammerParser::AssignmentExpressionContext* SixRGrammerParser::assignmentExpression() {
  AssignmentExpressionContext *_localctx = _tracker.createInstance<AssignmentExpressionContext>(_ctx, getState());
  enterRule(_localctx, 40, SixRGrammerParser::RuleAssignmentExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(353);
    variableName();
    setState(354);
    match(SixRGrammerParser::T__3);
    setState(357);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      setState(355);
      expression();
      break;
    }

    case 2: {
      setState(356);
      sixRJPR();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SixRJPRContext ------------------------------------------------------------------

SixRGrammerParser::SixRJPRContext::SixRJPRContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::SixRJXPointContext* SixRGrammerParser::SixRJPRContext::sixRJXPoint() {
  return getRuleContext<SixRGrammerParser::SixRJXPointContext>(0);
}

SixRGrammerParser::SixRPositionContext* SixRGrammerParser::SixRJPRContext::sixRPosition() {
  return getRuleContext<SixRGrammerParser::SixRPositionContext>(0);
}

SixRGrammerParser::SixROrientationContext* SixRGrammerParser::SixRJPRContext::sixROrientation() {
  return getRuleContext<SixRGrammerParser::SixROrientationContext>(0);
}


size_t SixRGrammerParser::SixRJPRContext::getRuleIndex() const {
  return SixRGrammerParser::RuleSixRJPR;
}

void SixRGrammerParser::SixRJPRContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSixRJPR(this);
}

void SixRGrammerParser::SixRJPRContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSixRJPR(this);
}

SixRGrammerParser::SixRJPRContext* SixRGrammerParser::sixRJPR() {
  SixRJPRContext *_localctx = _tracker.createInstance<SixRJPRContext>(_ctx, getState());
  enterRule(_localctx, 42, SixRGrammerParser::RuleSixRJPR);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(362);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      setState(359);
      sixRJXPoint();
      break;
    }

    case 2: {
      setState(360);
      sixRPosition();
      break;
    }

    case 3: {
      setState(361);
      sixROrientation();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SixRJXPointContext ------------------------------------------------------------------

SixRGrammerParser::SixRJXPointContext::SixRJXPointContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::SixRPPointContext* SixRGrammerParser::SixRJXPointContext::sixRPPoint() {
  return getRuleContext<SixRGrammerParser::SixRPPointContext>(0);
}

SixRGrammerParser::SixRJPointContext* SixRGrammerParser::SixRJXPointContext::sixRJPoint() {
  return getRuleContext<SixRGrammerParser::SixRJPointContext>(0);
}


size_t SixRGrammerParser::SixRJXPointContext::getRuleIndex() const {
  return SixRGrammerParser::RuleSixRJXPoint;
}

void SixRGrammerParser::SixRJXPointContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSixRJXPoint(this);
}

void SixRGrammerParser::SixRJXPointContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSixRJXPoint(this);
}

SixRGrammerParser::SixRJXPointContext* SixRGrammerParser::sixRJXPoint() {
  SixRJXPointContext *_localctx = _tracker.createInstance<SixRJXPointContext>(_ctx, getState());
  enterRule(_localctx, 44, SixRGrammerParser::RuleSixRJXPoint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(366);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      setState(364);
      sixRPPoint();
      break;
    }

    case 2: {
      setState(365);
      sixRJPoint();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SixRPPointContext ------------------------------------------------------------------

SixRGrammerParser::SixRPPointContext::SixRPPointContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SixRGrammerParser::SixRRPPartContext *> SixRGrammerParser::SixRPPointContext::sixRRPPart() {
  return getRuleContexts<SixRGrammerParser::SixRRPPartContext>();
}

SixRGrammerParser::SixRRPPartContext* SixRGrammerParser::SixRPPointContext::sixRRPPart(size_t i) {
  return getRuleContext<SixRGrammerParser::SixRRPPartContext>(i);
}

std::vector<SixRGrammerParser::VariableNameContext *> SixRGrammerParser::SixRPPointContext::variableName() {
  return getRuleContexts<SixRGrammerParser::VariableNameContext>();
}

SixRGrammerParser::VariableNameContext* SixRGrammerParser::SixRPPointContext::variableName(size_t i) {
  return getRuleContext<SixRGrammerParser::VariableNameContext>(i);
}


size_t SixRGrammerParser::SixRPPointContext::getRuleIndex() const {
  return SixRGrammerParser::RuleSixRPPoint;
}

void SixRGrammerParser::SixRPPointContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSixRPPoint(this);
}

void SixRGrammerParser::SixRPPointContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSixRPPoint(this);
}

SixRGrammerParser::SixRPPointContext* SixRGrammerParser::sixRPPoint() {
  SixRPPointContext *_localctx = _tracker.createInstance<SixRPPointContext>(_ctx, getState());
  enterRule(_localctx, 46, SixRGrammerParser::RuleSixRPPoint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(386);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 48, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(368);
      match(SixRGrammerParser::T__4);
      setState(377);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 114) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 114)) & ((1ULL << (SixRGrammerParser::XX - 114))
        | (1ULL << (SixRGrammerParser::YY - 114))
        | (1ULL << (SixRGrammerParser::ZZ - 114))
        | (1ULL << (SixRGrammerParser::AA - 114))
        | (1ULL << (SixRGrammerParser::BB - 114))
        | (1ULL << (SixRGrammerParser::CC - 114)))) != 0)) {
        setState(369);
        sixRRPPart();
        setState(374);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SixRGrammerParser::T__2) {
          setState(370);
          match(SixRGrammerParser::T__2);
          setState(371);
          sixRRPPart();
          setState(376);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(379);
      match(SixRGrammerParser::T__5);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(380);
      match(SixRGrammerParser::T__4);
      setState(381);
      variableName();
      setState(382);
      match(SixRGrammerParser::T__2);
      setState(383);
      variableName();
      setState(384);
      match(SixRGrammerParser::T__5);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SixRPositionContext ------------------------------------------------------------------

SixRGrammerParser::SixRPositionContext::SixRPositionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SixRGrammerParser::SixRPPartContext *> SixRGrammerParser::SixRPositionContext::sixRPPart() {
  return getRuleContexts<SixRGrammerParser::SixRPPartContext>();
}

SixRGrammerParser::SixRPPartContext* SixRGrammerParser::SixRPositionContext::sixRPPart(size_t i) {
  return getRuleContext<SixRGrammerParser::SixRPPartContext>(i);
}


size_t SixRGrammerParser::SixRPositionContext::getRuleIndex() const {
  return SixRGrammerParser::RuleSixRPosition;
}

void SixRGrammerParser::SixRPositionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSixRPosition(this);
}

void SixRGrammerParser::SixRPositionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSixRPosition(this);
}

SixRGrammerParser::SixRPositionContext* SixRGrammerParser::sixRPosition() {
  SixRPositionContext *_localctx = _tracker.createInstance<SixRPositionContext>(_ctx, getState());
  enterRule(_localctx, 48, SixRGrammerParser::RuleSixRPosition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(388);
    match(SixRGrammerParser::T__0);
    setState(397);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 114) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 114)) & ((1ULL << (SixRGrammerParser::XX - 114))
      | (1ULL << (SixRGrammerParser::YY - 114))
      | (1ULL << (SixRGrammerParser::ZZ - 114)))) != 0)) {
      setState(389);
      sixRPPart();
      setState(394);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SixRGrammerParser::T__2) {
        setState(390);
        match(SixRGrammerParser::T__2);
        setState(391);
        sixRPPart();
        setState(396);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(399);
    match(SixRGrammerParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SixROrientationContext ------------------------------------------------------------------

SixRGrammerParser::SixROrientationContext::SixROrientationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SixRGrammerParser::SixRRPartContext *> SixRGrammerParser::SixROrientationContext::sixRRPart() {
  return getRuleContexts<SixRGrammerParser::SixRRPartContext>();
}

SixRGrammerParser::SixRRPartContext* SixRGrammerParser::SixROrientationContext::sixRRPart(size_t i) {
  return getRuleContext<SixRGrammerParser::SixRRPartContext>(i);
}


size_t SixRGrammerParser::SixROrientationContext::getRuleIndex() const {
  return SixRGrammerParser::RuleSixROrientation;
}

void SixRGrammerParser::SixROrientationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSixROrientation(this);
}

void SixRGrammerParser::SixROrientationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSixROrientation(this);
}

SixRGrammerParser::SixROrientationContext* SixRGrammerParser::sixROrientation() {
  SixROrientationContext *_localctx = _tracker.createInstance<SixROrientationContext>(_ctx, getState());
  enterRule(_localctx, 50, SixRGrammerParser::RuleSixROrientation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(401);
    match(SixRGrammerParser::T__0);
    setState(410);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 117) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 117)) & ((1ULL << (SixRGrammerParser::AA - 117))
      | (1ULL << (SixRGrammerParser::BB - 117))
      | (1ULL << (SixRGrammerParser::CC - 117)))) != 0)) {
      setState(402);
      sixRRPart();
      setState(407);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SixRGrammerParser::T__2) {
        setState(403);
        match(SixRGrammerParser::T__2);
        setState(404);
        sixRRPart();
        setState(409);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(412);
    match(SixRGrammerParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SixRJPointContext ------------------------------------------------------------------

SixRGrammerParser::SixRJPointContext::SixRJPointContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SixRGrammerParser::SixRJPartContext *> SixRGrammerParser::SixRJPointContext::sixRJPart() {
  return getRuleContexts<SixRGrammerParser::SixRJPartContext>();
}

SixRGrammerParser::SixRJPartContext* SixRGrammerParser::SixRJPointContext::sixRJPart(size_t i) {
  return getRuleContext<SixRGrammerParser::SixRJPartContext>(i);
}


size_t SixRGrammerParser::SixRJPointContext::getRuleIndex() const {
  return SixRGrammerParser::RuleSixRJPoint;
}

void SixRGrammerParser::SixRJPointContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSixRJPoint(this);
}

void SixRGrammerParser::SixRJPointContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSixRJPoint(this);
}

SixRGrammerParser::SixRJPointContext* SixRGrammerParser::sixRJPoint() {
  SixRJPointContext *_localctx = _tracker.createInstance<SixRJPointContext>(_ctx, getState());
  enterRule(_localctx, 52, SixRGrammerParser::RuleSixRJPoint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(414);
    match(SixRGrammerParser::T__4);
    setState(423);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 121) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 121)) & ((1ULL << (SixRGrammerParser::J1 - 121))
      | (1ULL << (SixRGrammerParser::J2 - 121))
      | (1ULL << (SixRGrammerParser::J3 - 121))
      | (1ULL << (SixRGrammerParser::J4 - 121))
      | (1ULL << (SixRGrammerParser::J5 - 121))
      | (1ULL << (SixRGrammerParser::J6 - 121)))) != 0)) {
      setState(415);
      sixRJPart();
      setState(420);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SixRGrammerParser::T__2) {
        setState(416);
        match(SixRGrammerParser::T__2);
        setState(417);
        sixRJPart();
        setState(422);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(425);
    match(SixRGrammerParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SixRJPartContext ------------------------------------------------------------------

SixRGrammerParser::SixRJPartContext::SixRJPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::SixRJPartContext::expression() {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(0);
}

tree::TerminalNode* SixRGrammerParser::SixRJPartContext::J1() {
  return getToken(SixRGrammerParser::J1, 0);
}

tree::TerminalNode* SixRGrammerParser::SixRJPartContext::J2() {
  return getToken(SixRGrammerParser::J2, 0);
}

tree::TerminalNode* SixRGrammerParser::SixRJPartContext::J3() {
  return getToken(SixRGrammerParser::J3, 0);
}

tree::TerminalNode* SixRGrammerParser::SixRJPartContext::J4() {
  return getToken(SixRGrammerParser::J4, 0);
}

tree::TerminalNode* SixRGrammerParser::SixRJPartContext::J5() {
  return getToken(SixRGrammerParser::J5, 0);
}

tree::TerminalNode* SixRGrammerParser::SixRJPartContext::J6() {
  return getToken(SixRGrammerParser::J6, 0);
}


size_t SixRGrammerParser::SixRJPartContext::getRuleIndex() const {
  return SixRGrammerParser::RuleSixRJPart;
}

void SixRGrammerParser::SixRJPartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSixRJPart(this);
}

void SixRGrammerParser::SixRJPartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSixRJPart(this);
}

SixRGrammerParser::SixRJPartContext* SixRGrammerParser::sixRJPart() {
  SixRJPartContext *_localctx = _tracker.createInstance<SixRJPartContext>(_ctx, getState());
  enterRule(_localctx, 54, SixRGrammerParser::RuleSixRJPart);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(427);
    _la = _input->LA(1);
    if (!(((((_la - 121) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 121)) & ((1ULL << (SixRGrammerParser::J1 - 121))
      | (1ULL << (SixRGrammerParser::J2 - 121))
      | (1ULL << (SixRGrammerParser::J3 - 121))
      | (1ULL << (SixRGrammerParser::J4 - 121))
      | (1ULL << (SixRGrammerParser::J5 - 121))
      | (1ULL << (SixRGrammerParser::J6 - 121)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(428);
    match(SixRGrammerParser::T__6);
    setState(429);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SixRRPPartContext ------------------------------------------------------------------

SixRGrammerParser::SixRRPPartContext::SixRRPPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::SixRRPartContext* SixRGrammerParser::SixRRPPartContext::sixRRPart() {
  return getRuleContext<SixRGrammerParser::SixRRPartContext>(0);
}

SixRGrammerParser::SixRPPartContext* SixRGrammerParser::SixRRPPartContext::sixRPPart() {
  return getRuleContext<SixRGrammerParser::SixRPPartContext>(0);
}


size_t SixRGrammerParser::SixRRPPartContext::getRuleIndex() const {
  return SixRGrammerParser::RuleSixRRPPart;
}

void SixRGrammerParser::SixRRPPartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSixRRPPart(this);
}

void SixRGrammerParser::SixRRPPartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSixRRPPart(this);
}

SixRGrammerParser::SixRRPPartContext* SixRGrammerParser::sixRRPPart() {
  SixRRPPartContext *_localctx = _tracker.createInstance<SixRRPPartContext>(_ctx, getState());
  enterRule(_localctx, 56, SixRGrammerParser::RuleSixRRPPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(433);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SixRGrammerParser::AA:
      case SixRGrammerParser::BB:
      case SixRGrammerParser::CC: {
        enterOuterAlt(_localctx, 1);
        setState(431);
        sixRRPart();
        break;
      }

      case SixRGrammerParser::XX:
      case SixRGrammerParser::YY:
      case SixRGrammerParser::ZZ: {
        enterOuterAlt(_localctx, 2);
        setState(432);
        sixRPPart();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SixRPPartContext ------------------------------------------------------------------

SixRGrammerParser::SixRPPartContext::SixRPPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::SixRPPartContext::expression() {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(0);
}

tree::TerminalNode* SixRGrammerParser::SixRPPartContext::XX() {
  return getToken(SixRGrammerParser::XX, 0);
}

tree::TerminalNode* SixRGrammerParser::SixRPPartContext::YY() {
  return getToken(SixRGrammerParser::YY, 0);
}

tree::TerminalNode* SixRGrammerParser::SixRPPartContext::ZZ() {
  return getToken(SixRGrammerParser::ZZ, 0);
}


size_t SixRGrammerParser::SixRPPartContext::getRuleIndex() const {
  return SixRGrammerParser::RuleSixRPPart;
}

void SixRGrammerParser::SixRPPartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSixRPPart(this);
}

void SixRGrammerParser::SixRPPartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSixRPPart(this);
}

SixRGrammerParser::SixRPPartContext* SixRGrammerParser::sixRPPart() {
  SixRPPartContext *_localctx = _tracker.createInstance<SixRPPartContext>(_ctx, getState());
  enterRule(_localctx, 58, SixRGrammerParser::RuleSixRPPart);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(435);
    _la = _input->LA(1);
    if (!(((((_la - 114) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 114)) & ((1ULL << (SixRGrammerParser::XX - 114))
      | (1ULL << (SixRGrammerParser::YY - 114))
      | (1ULL << (SixRGrammerParser::ZZ - 114)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(436);
    match(SixRGrammerParser::T__6);
    setState(437);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SixRRPartContext ------------------------------------------------------------------

SixRGrammerParser::SixRRPartContext::SixRRPartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::SixRRPartContext::expression() {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(0);
}

tree::TerminalNode* SixRGrammerParser::SixRRPartContext::AA() {
  return getToken(SixRGrammerParser::AA, 0);
}

tree::TerminalNode* SixRGrammerParser::SixRRPartContext::BB() {
  return getToken(SixRGrammerParser::BB, 0);
}

tree::TerminalNode* SixRGrammerParser::SixRRPartContext::CC() {
  return getToken(SixRGrammerParser::CC, 0);
}


size_t SixRGrammerParser::SixRRPartContext::getRuleIndex() const {
  return SixRGrammerParser::RuleSixRRPart;
}

void SixRGrammerParser::SixRRPartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSixRRPart(this);
}

void SixRGrammerParser::SixRRPartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSixRRPart(this);
}

SixRGrammerParser::SixRRPartContext* SixRGrammerParser::sixRRPart() {
  SixRRPartContext *_localctx = _tracker.createInstance<SixRRPartContext>(_ctx, getState());
  enterRule(_localctx, 60, SixRGrammerParser::RuleSixRRPart);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(439);
    _la = _input->LA(1);
    if (!(((((_la - 117) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 117)) & ((1ULL << (SixRGrammerParser::AA - 117))
      | (1ULL << (SixRGrammerParser::BB - 117))
      | (1ULL << (SixRGrammerParser::CC - 117)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(440);
    match(SixRGrammerParser::T__6);
    setState(441);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableNameContext ------------------------------------------------------------------

SixRGrammerParser::VariableNameContext::VariableNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SixRGrammerParser::VariableNameContext::IDENTIFIER() {
  return getToken(SixRGrammerParser::IDENTIFIER, 0);
}

SixRGrammerParser::ArrayVariableSuffixContext* SixRGrammerParser::VariableNameContext::arrayVariableSuffix() {
  return getRuleContext<SixRGrammerParser::ArrayVariableSuffixContext>(0);
}


size_t SixRGrammerParser::VariableNameContext::getRuleIndex() const {
  return SixRGrammerParser::RuleVariableName;
}

void SixRGrammerParser::VariableNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariableName(this);
}

void SixRGrammerParser::VariableNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariableName(this);
}

SixRGrammerParser::VariableNameContext* SixRGrammerParser::variableName() {
  VariableNameContext *_localctx = _tracker.createInstance<VariableNameContext>(_ctx, getState());
  enterRule(_localctx, 62, SixRGrammerParser::RuleVariableName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(443);
    match(SixRGrammerParser::IDENTIFIER);
    setState(445);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 56, _ctx)) {
    case 1: {
      setState(444);
      arrayVariableSuffix();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayVariableSuffixContext ------------------------------------------------------------------

SixRGrammerParser::ArrayVariableSuffixContext::ArrayVariableSuffixContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SixRGrammerParser::ExpressionContext *> SixRGrammerParser::ArrayVariableSuffixContext::expression() {
  return getRuleContexts<SixRGrammerParser::ExpressionContext>();
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::ArrayVariableSuffixContext::expression(size_t i) {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(i);
}


size_t SixRGrammerParser::ArrayVariableSuffixContext::getRuleIndex() const {
  return SixRGrammerParser::RuleArrayVariableSuffix;
}

void SixRGrammerParser::ArrayVariableSuffixContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayVariableSuffix(this);
}

void SixRGrammerParser::ArrayVariableSuffixContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayVariableSuffix(this);
}

SixRGrammerParser::ArrayVariableSuffixContext* SixRGrammerParser::arrayVariableSuffix() {
  ArrayVariableSuffixContext *_localctx = _tracker.createInstance<ArrayVariableSuffixContext>(_ctx, getState());
  enterRule(_localctx, 64, SixRGrammerParser::RuleArrayVariableSuffix);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(447);
    match(SixRGrammerParser::T__4);

    setState(448);
    expression();
    setState(453);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SixRGrammerParser::T__2) {
      setState(449);
      match(SixRGrammerParser::T__2);
      setState(450);
      expression();
      setState(455);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(456);
    match(SixRGrammerParser::T__5);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

SixRGrammerParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::ProcedureNameContext* SixRGrammerParser::ExpressionContext::procedureName() {
  return getRuleContext<SixRGrammerParser::ProcedureNameContext>(0);
}

std::vector<SixRGrammerParser::ExpressionContext *> SixRGrammerParser::ExpressionContext::expression() {
  return getRuleContexts<SixRGrammerParser::ExpressionContext>();
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::ExpressionContext::expression(size_t i) {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(i);
}

std::vector<SixRGrammerParser::ConditionalOrExpressionContext *> SixRGrammerParser::ExpressionContext::conditionalOrExpression() {
  return getRuleContexts<SixRGrammerParser::ConditionalOrExpressionContext>();
}

SixRGrammerParser::ConditionalOrExpressionContext* SixRGrammerParser::ExpressionContext::conditionalOrExpression(size_t i) {
  return getRuleContext<SixRGrammerParser::ConditionalOrExpressionContext>(i);
}

std::vector<SixRGrammerParser::RelationalOpContext *> SixRGrammerParser::ExpressionContext::relationalOp() {
  return getRuleContexts<SixRGrammerParser::RelationalOpContext>();
}

SixRGrammerParser::RelationalOpContext* SixRGrammerParser::ExpressionContext::relationalOp(size_t i) {
  return getRuleContext<SixRGrammerParser::RelationalOpContext>(i);
}


size_t SixRGrammerParser::ExpressionContext::getRuleIndex() const {
  return SixRGrammerParser::RuleExpression;
}

void SixRGrammerParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void SixRGrammerParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 66, SixRGrammerParser::RuleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(481);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(458);
      procedureName();
      setState(459);
      match(SixRGrammerParser::T__0);
      setState(468);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SixRGrammerParser::T__0)
        | (1ULL << SixRGrammerParser::T__13)
        | (1ULL << SixRGrammerParser::T__14)
        | (1ULL << SixRGrammerParser::T__17))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 65)) & ((1ULL << (SixRGrammerParser::FALSE - 65))
        | (1ULL << (SixRGrammerParser::NOT - 65))
        | (1ULL << (SixRGrammerParser::TRUE - 65))
        | (1ULL << (SixRGrammerParser::FragINTLITERAL - 65))
        | (1ULL << (SixRGrammerParser::FragFLOATLITERAL - 65)))) != 0) || ((((_la - 129) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 129)) & ((1ULL << (SixRGrammerParser::FragCHARLITERAL - 129))
        | (1ULL << (SixRGrammerParser::FragSTRINGLITERAL - 129))
        | (1ULL << (SixRGrammerParser::IDENTIFIER - 129)))) != 0)) {
        setState(460);
        expression();
        setState(465);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SixRGrammerParser::T__2) {
          setState(461);
          match(SixRGrammerParser::T__2);
          setState(462);
          expression();
          setState(467);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(470);
      match(SixRGrammerParser::T__1);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(472);
      conditionalOrExpression();
      setState(478);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SixRGrammerParser::T__7)
        | (1ULL << SixRGrammerParser::T__8)
        | (1ULL << SixRGrammerParser::T__9)
        | (1ULL << SixRGrammerParser::T__10)
        | (1ULL << SixRGrammerParser::T__11)
        | (1ULL << SixRGrammerParser::T__12))) != 0)) {
        setState(473);
        relationalOp();
        setState(474);
        conditionalOrExpression();
        setState(480);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationalOpContext ------------------------------------------------------------------

SixRGrammerParser::RelationalOpContext::RelationalOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SixRGrammerParser::RelationalOpContext::getRuleIndex() const {
  return SixRGrammerParser::RuleRelationalOp;
}

void SixRGrammerParser::RelationalOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationalOp(this);
}

void SixRGrammerParser::RelationalOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationalOp(this);
}

SixRGrammerParser::RelationalOpContext* SixRGrammerParser::relationalOp() {
  RelationalOpContext *_localctx = _tracker.createInstance<RelationalOpContext>(_ctx, getState());
  enterRule(_localctx, 68, SixRGrammerParser::RuleRelationalOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(483);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SixRGrammerParser::T__7)
      | (1ULL << SixRGrammerParser::T__8)
      | (1ULL << SixRGrammerParser::T__9)
      | (1ULL << SixRGrammerParser::T__10)
      | (1ULL << SixRGrammerParser::T__11)
      | (1ULL << SixRGrammerParser::T__12))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionalOrExpressionContext ------------------------------------------------------------------

SixRGrammerParser::ConditionalOrExpressionContext::ConditionalOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SixRGrammerParser::ExclusiveOrExpressionContext *> SixRGrammerParser::ConditionalOrExpressionContext::exclusiveOrExpression() {
  return getRuleContexts<SixRGrammerParser::ExclusiveOrExpressionContext>();
}

SixRGrammerParser::ExclusiveOrExpressionContext* SixRGrammerParser::ConditionalOrExpressionContext::exclusiveOrExpression(size_t i) {
  return getRuleContext<SixRGrammerParser::ExclusiveOrExpressionContext>(i);
}

std::vector<tree::TerminalNode *> SixRGrammerParser::ConditionalOrExpressionContext::OR() {
  return getTokens(SixRGrammerParser::OR);
}

tree::TerminalNode* SixRGrammerParser::ConditionalOrExpressionContext::OR(size_t i) {
  return getToken(SixRGrammerParser::OR, i);
}


size_t SixRGrammerParser::ConditionalOrExpressionContext::getRuleIndex() const {
  return SixRGrammerParser::RuleConditionalOrExpression;
}

void SixRGrammerParser::ConditionalOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalOrExpression(this);
}

void SixRGrammerParser::ConditionalOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalOrExpression(this);
}

SixRGrammerParser::ConditionalOrExpressionContext* SixRGrammerParser::conditionalOrExpression() {
  ConditionalOrExpressionContext *_localctx = _tracker.createInstance<ConditionalOrExpressionContext>(_ctx, getState());
  enterRule(_localctx, 70, SixRGrammerParser::RuleConditionalOrExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(485);
    exclusiveOrExpression();
    setState(490);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SixRGrammerParser::OR) {
      setState(486);
      match(SixRGrammerParser::OR);
      setState(487);
      exclusiveOrExpression();
      setState(492);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExclusiveOrExpressionContext ------------------------------------------------------------------

SixRGrammerParser::ExclusiveOrExpressionContext::ExclusiveOrExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SixRGrammerParser::ConditionalAndExpressionContext *> SixRGrammerParser::ExclusiveOrExpressionContext::conditionalAndExpression() {
  return getRuleContexts<SixRGrammerParser::ConditionalAndExpressionContext>();
}

SixRGrammerParser::ConditionalAndExpressionContext* SixRGrammerParser::ExclusiveOrExpressionContext::conditionalAndExpression(size_t i) {
  return getRuleContext<SixRGrammerParser::ConditionalAndExpressionContext>(i);
}

std::vector<tree::TerminalNode *> SixRGrammerParser::ExclusiveOrExpressionContext::EXOR() {
  return getTokens(SixRGrammerParser::EXOR);
}

tree::TerminalNode* SixRGrammerParser::ExclusiveOrExpressionContext::EXOR(size_t i) {
  return getToken(SixRGrammerParser::EXOR, i);
}


size_t SixRGrammerParser::ExclusiveOrExpressionContext::getRuleIndex() const {
  return SixRGrammerParser::RuleExclusiveOrExpression;
}

void SixRGrammerParser::ExclusiveOrExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExclusiveOrExpression(this);
}

void SixRGrammerParser::ExclusiveOrExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExclusiveOrExpression(this);
}

SixRGrammerParser::ExclusiveOrExpressionContext* SixRGrammerParser::exclusiveOrExpression() {
  ExclusiveOrExpressionContext *_localctx = _tracker.createInstance<ExclusiveOrExpressionContext>(_ctx, getState());
  enterRule(_localctx, 72, SixRGrammerParser::RuleExclusiveOrExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(493);
    conditionalAndExpression();
    setState(498);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SixRGrammerParser::EXOR) {
      setState(494);
      match(SixRGrammerParser::EXOR);
      setState(495);
      conditionalAndExpression();
      setState(500);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionalAndExpressionContext ------------------------------------------------------------------

SixRGrammerParser::ConditionalAndExpressionContext::ConditionalAndExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SixRGrammerParser::AdditiveExpressionContext *> SixRGrammerParser::ConditionalAndExpressionContext::additiveExpression() {
  return getRuleContexts<SixRGrammerParser::AdditiveExpressionContext>();
}

SixRGrammerParser::AdditiveExpressionContext* SixRGrammerParser::ConditionalAndExpressionContext::additiveExpression(size_t i) {
  return getRuleContext<SixRGrammerParser::AdditiveExpressionContext>(i);
}

std::vector<tree::TerminalNode *> SixRGrammerParser::ConditionalAndExpressionContext::AND() {
  return getTokens(SixRGrammerParser::AND);
}

tree::TerminalNode* SixRGrammerParser::ConditionalAndExpressionContext::AND(size_t i) {
  return getToken(SixRGrammerParser::AND, i);
}


size_t SixRGrammerParser::ConditionalAndExpressionContext::getRuleIndex() const {
  return SixRGrammerParser::RuleConditionalAndExpression;
}

void SixRGrammerParser::ConditionalAndExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConditionalAndExpression(this);
}

void SixRGrammerParser::ConditionalAndExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConditionalAndExpression(this);
}

SixRGrammerParser::ConditionalAndExpressionContext* SixRGrammerParser::conditionalAndExpression() {
  ConditionalAndExpressionContext *_localctx = _tracker.createInstance<ConditionalAndExpressionContext>(_ctx, getState());
  enterRule(_localctx, 74, SixRGrammerParser::RuleConditionalAndExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(501);
    additiveExpression();
    setState(506);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SixRGrammerParser::AND) {
      setState(502);
      match(SixRGrammerParser::AND);
      setState(503);
      additiveExpression();
      setState(508);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AdditiveExpressionContext ------------------------------------------------------------------

SixRGrammerParser::AdditiveExpressionContext::AdditiveExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SixRGrammerParser::MultiplicativeExpressionContext *> SixRGrammerParser::AdditiveExpressionContext::multiplicativeExpression() {
  return getRuleContexts<SixRGrammerParser::MultiplicativeExpressionContext>();
}

SixRGrammerParser::MultiplicativeExpressionContext* SixRGrammerParser::AdditiveExpressionContext::multiplicativeExpression(size_t i) {
  return getRuleContext<SixRGrammerParser::MultiplicativeExpressionContext>(i);
}


size_t SixRGrammerParser::AdditiveExpressionContext::getRuleIndex() const {
  return SixRGrammerParser::RuleAdditiveExpression;
}

void SixRGrammerParser::AdditiveExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditiveExpression(this);
}

void SixRGrammerParser::AdditiveExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditiveExpression(this);
}

SixRGrammerParser::AdditiveExpressionContext* SixRGrammerParser::additiveExpression() {
  AdditiveExpressionContext *_localctx = _tracker.createInstance<AdditiveExpressionContext>(_ctx, getState());
  enterRule(_localctx, 76, SixRGrammerParser::RuleAdditiveExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(509);
    multiplicativeExpression();
    setState(514);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(510);
        _la = _input->LA(1);
        if (!(_la == SixRGrammerParser::T__13

        || _la == SixRGrammerParser::T__14)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(511);
        multiplicativeExpression(); 
      }
      setState(516);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

SixRGrammerParser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SixRGrammerParser::UnaryNotExpressionContext *> SixRGrammerParser::MultiplicativeExpressionContext::unaryNotExpression() {
  return getRuleContexts<SixRGrammerParser::UnaryNotExpressionContext>();
}

SixRGrammerParser::UnaryNotExpressionContext* SixRGrammerParser::MultiplicativeExpressionContext::unaryNotExpression(size_t i) {
  return getRuleContext<SixRGrammerParser::UnaryNotExpressionContext>(i);
}


size_t SixRGrammerParser::MultiplicativeExpressionContext::getRuleIndex() const {
  return SixRGrammerParser::RuleMultiplicativeExpression;
}

void SixRGrammerParser::MultiplicativeExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplicativeExpression(this);
}

void SixRGrammerParser::MultiplicativeExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplicativeExpression(this);
}

SixRGrammerParser::MultiplicativeExpressionContext* SixRGrammerParser::multiplicativeExpression() {
  MultiplicativeExpressionContext *_localctx = _tracker.createInstance<MultiplicativeExpressionContext>(_ctx, getState());
  enterRule(_localctx, 78, SixRGrammerParser::RuleMultiplicativeExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(517);
    unaryNotExpression();
    setState(522);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SixRGrammerParser::T__15

    || _la == SixRGrammerParser::T__16) {
      setState(518);
      _la = _input->LA(1);
      if (!(_la == SixRGrammerParser::T__15

      || _la == SixRGrammerParser::T__16)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(519);
      unaryNotExpression();
      setState(524);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryNotExpressionContext ------------------------------------------------------------------

SixRGrammerParser::UnaryNotExpressionContext::UnaryNotExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SixRGrammerParser::UnaryNotExpressionContext::NOT() {
  return getToken(SixRGrammerParser::NOT, 0);
}

SixRGrammerParser::UnaryNotExpressionContext* SixRGrammerParser::UnaryNotExpressionContext::unaryNotExpression() {
  return getRuleContext<SixRGrammerParser::UnaryNotExpressionContext>(0);
}

SixRGrammerParser::UnaryPlusMinuxExpressionContext* SixRGrammerParser::UnaryNotExpressionContext::unaryPlusMinuxExpression() {
  return getRuleContext<SixRGrammerParser::UnaryPlusMinuxExpressionContext>(0);
}


size_t SixRGrammerParser::UnaryNotExpressionContext::getRuleIndex() const {
  return SixRGrammerParser::RuleUnaryNotExpression;
}

void SixRGrammerParser::UnaryNotExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryNotExpression(this);
}

void SixRGrammerParser::UnaryNotExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryNotExpression(this);
}

SixRGrammerParser::UnaryNotExpressionContext* SixRGrammerParser::unaryNotExpression() {
  UnaryNotExpressionContext *_localctx = _tracker.createInstance<UnaryNotExpressionContext>(_ctx, getState());
  enterRule(_localctx, 80, SixRGrammerParser::RuleUnaryNotExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(530);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SixRGrammerParser::NOT: {
        enterOuterAlt(_localctx, 1);
        setState(525);
        match(SixRGrammerParser::NOT);
        setState(526);
        unaryNotExpression();
        break;
      }

      case SixRGrammerParser::T__17: {
        enterOuterAlt(_localctx, 2);
        setState(527);
        match(SixRGrammerParser::T__17);
        setState(528);
        unaryNotExpression();
        break;
      }

      case SixRGrammerParser::T__0:
      case SixRGrammerParser::T__13:
      case SixRGrammerParser::T__14:
      case SixRGrammerParser::FALSE:
      case SixRGrammerParser::TRUE:
      case SixRGrammerParser::FragINTLITERAL:
      case SixRGrammerParser::FragFLOATLITERAL:
      case SixRGrammerParser::FragCHARLITERAL:
      case SixRGrammerParser::FragSTRINGLITERAL:
      case SixRGrammerParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 3);
        setState(529);
        unaryPlusMinuxExpression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryPlusMinuxExpressionContext ------------------------------------------------------------------

SixRGrammerParser::UnaryPlusMinuxExpressionContext::UnaryPlusMinuxExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::UnaryPlusMinuxExpressionContext* SixRGrammerParser::UnaryPlusMinuxExpressionContext::unaryPlusMinuxExpression() {
  return getRuleContext<SixRGrammerParser::UnaryPlusMinuxExpressionContext>(0);
}

SixRGrammerParser::PrimaryContext* SixRGrammerParser::UnaryPlusMinuxExpressionContext::primary() {
  return getRuleContext<SixRGrammerParser::PrimaryContext>(0);
}


size_t SixRGrammerParser::UnaryPlusMinuxExpressionContext::getRuleIndex() const {
  return SixRGrammerParser::RuleUnaryPlusMinuxExpression;
}

void SixRGrammerParser::UnaryPlusMinuxExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryPlusMinuxExpression(this);
}

void SixRGrammerParser::UnaryPlusMinuxExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryPlusMinuxExpression(this);
}

SixRGrammerParser::UnaryPlusMinuxExpressionContext* SixRGrammerParser::unaryPlusMinuxExpression() {
  UnaryPlusMinuxExpressionContext *_localctx = _tracker.createInstance<UnaryPlusMinuxExpressionContext>(_ctx, getState());
  enterRule(_localctx, 82, SixRGrammerParser::RuleUnaryPlusMinuxExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(537);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SixRGrammerParser::T__13: {
        enterOuterAlt(_localctx, 1);
        setState(532);
        match(SixRGrammerParser::T__13);
        setState(533);
        unaryPlusMinuxExpression();
        break;
      }

      case SixRGrammerParser::T__14: {
        enterOuterAlt(_localctx, 2);
        setState(534);
        match(SixRGrammerParser::T__14);
        setState(535);
        unaryPlusMinuxExpression();
        break;
      }

      case SixRGrammerParser::T__0:
      case SixRGrammerParser::FALSE:
      case SixRGrammerParser::TRUE:
      case SixRGrammerParser::FragINTLITERAL:
      case SixRGrammerParser::FragFLOATLITERAL:
      case SixRGrammerParser::FragCHARLITERAL:
      case SixRGrammerParser::FragSTRINGLITERAL:
      case SixRGrammerParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 3);
        setState(536);
        primary();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimaryContext ------------------------------------------------------------------

SixRGrammerParser::PrimaryContext::PrimaryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::ParExpressionContext* SixRGrammerParser::PrimaryContext::parExpression() {
  return getRuleContext<SixRGrammerParser::ParExpressionContext>(0);
}

SixRGrammerParser::VariableNameContext* SixRGrammerParser::PrimaryContext::variableName() {
  return getRuleContext<SixRGrammerParser::VariableNameContext>(0);
}

SixRGrammerParser::LiteralContext* SixRGrammerParser::PrimaryContext::literal() {
  return getRuleContext<SixRGrammerParser::LiteralContext>(0);
}


size_t SixRGrammerParser::PrimaryContext::getRuleIndex() const {
  return SixRGrammerParser::RulePrimary;
}

void SixRGrammerParser::PrimaryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimary(this);
}

void SixRGrammerParser::PrimaryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimary(this);
}

SixRGrammerParser::PrimaryContext* SixRGrammerParser::primary() {
  PrimaryContext *_localctx = _tracker.createInstance<PrimaryContext>(_ctx, getState());
  enterRule(_localctx, 84, SixRGrammerParser::RulePrimary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(542);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SixRGrammerParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(539);
        parExpression();
        break;
      }

      case SixRGrammerParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(540);
        variableName();
        break;
      }

      case SixRGrammerParser::FALSE:
      case SixRGrammerParser::TRUE:
      case SixRGrammerParser::FragINTLITERAL:
      case SixRGrammerParser::FragFLOATLITERAL:
      case SixRGrammerParser::FragCHARLITERAL:
      case SixRGrammerParser::FragSTRINGLITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(541);
        literal();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

SixRGrammerParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::NumberLITERALContext* SixRGrammerParser::LiteralContext::numberLITERAL() {
  return getRuleContext<SixRGrammerParser::NumberLITERALContext>(0);
}

SixRGrammerParser::CharLITERALContext* SixRGrammerParser::LiteralContext::charLITERAL() {
  return getRuleContext<SixRGrammerParser::CharLITERALContext>(0);
}

SixRGrammerParser::StringLITERALContext* SixRGrammerParser::LiteralContext::stringLITERAL() {
  return getRuleContext<SixRGrammerParser::StringLITERALContext>(0);
}

SixRGrammerParser::BooleanLiteralContext* SixRGrammerParser::LiteralContext::booleanLiteral() {
  return getRuleContext<SixRGrammerParser::BooleanLiteralContext>(0);
}


size_t SixRGrammerParser::LiteralContext::getRuleIndex() const {
  return SixRGrammerParser::RuleLiteral;
}

void SixRGrammerParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void SixRGrammerParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}

SixRGrammerParser::LiteralContext* SixRGrammerParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 86, SixRGrammerParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(548);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SixRGrammerParser::FragINTLITERAL:
      case SixRGrammerParser::FragFLOATLITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(544);
        numberLITERAL();
        break;
      }

      case SixRGrammerParser::FragCHARLITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(545);
        charLITERAL();
        break;
      }

      case SixRGrammerParser::FragSTRINGLITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(546);
        stringLITERAL();
        break;
      }

      case SixRGrammerParser::FALSE:
      case SixRGrammerParser::TRUE: {
        enterOuterAlt(_localctx, 4);
        setState(547);
        booleanLiteral();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntLITERALContext ------------------------------------------------------------------

SixRGrammerParser::IntLITERALContext::IntLITERALContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SixRGrammerParser::IntLITERALContext::FragINTLITERAL() {
  return getToken(SixRGrammerParser::FragINTLITERAL, 0);
}


size_t SixRGrammerParser::IntLITERALContext::getRuleIndex() const {
  return SixRGrammerParser::RuleIntLITERAL;
}

void SixRGrammerParser::IntLITERALContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIntLITERAL(this);
}

void SixRGrammerParser::IntLITERALContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIntLITERAL(this);
}

SixRGrammerParser::IntLITERALContext* SixRGrammerParser::intLITERAL() {
  IntLITERALContext *_localctx = _tracker.createInstance<IntLITERALContext>(_ctx, getState());
  enterRule(_localctx, 88, SixRGrammerParser::RuleIntLITERAL);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(550);
    match(SixRGrammerParser::FragINTLITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FloatLITERALContext ------------------------------------------------------------------

SixRGrammerParser::FloatLITERALContext::FloatLITERALContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SixRGrammerParser::FloatLITERALContext::FragFLOATLITERAL() {
  return getToken(SixRGrammerParser::FragFLOATLITERAL, 0);
}


size_t SixRGrammerParser::FloatLITERALContext::getRuleIndex() const {
  return SixRGrammerParser::RuleFloatLITERAL;
}

void SixRGrammerParser::FloatLITERALContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFloatLITERAL(this);
}

void SixRGrammerParser::FloatLITERALContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFloatLITERAL(this);
}

SixRGrammerParser::FloatLITERALContext* SixRGrammerParser::floatLITERAL() {
  FloatLITERALContext *_localctx = _tracker.createInstance<FloatLITERALContext>(_ctx, getState());
  enterRule(_localctx, 90, SixRGrammerParser::RuleFloatLITERAL);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(552);
    match(SixRGrammerParser::FragFLOATLITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CharLITERALContext ------------------------------------------------------------------

SixRGrammerParser::CharLITERALContext::CharLITERALContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SixRGrammerParser::CharLITERALContext::FragCHARLITERAL() {
  return getToken(SixRGrammerParser::FragCHARLITERAL, 0);
}


size_t SixRGrammerParser::CharLITERALContext::getRuleIndex() const {
  return SixRGrammerParser::RuleCharLITERAL;
}

void SixRGrammerParser::CharLITERALContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCharLITERAL(this);
}

void SixRGrammerParser::CharLITERALContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCharLITERAL(this);
}

SixRGrammerParser::CharLITERALContext* SixRGrammerParser::charLITERAL() {
  CharLITERALContext *_localctx = _tracker.createInstance<CharLITERALContext>(_ctx, getState());
  enterRule(_localctx, 92, SixRGrammerParser::RuleCharLITERAL);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(554);
    match(SixRGrammerParser::FragCHARLITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringLITERALContext ------------------------------------------------------------------

SixRGrammerParser::StringLITERALContext::StringLITERALContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SixRGrammerParser::StringLITERALContext::FragSTRINGLITERAL() {
  return getToken(SixRGrammerParser::FragSTRINGLITERAL, 0);
}


size_t SixRGrammerParser::StringLITERALContext::getRuleIndex() const {
  return SixRGrammerParser::RuleStringLITERAL;
}

void SixRGrammerParser::StringLITERALContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStringLITERAL(this);
}

void SixRGrammerParser::StringLITERALContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStringLITERAL(this);
}

SixRGrammerParser::StringLITERALContext* SixRGrammerParser::stringLITERAL() {
  StringLITERALContext *_localctx = _tracker.createInstance<StringLITERALContext>(_ctx, getState());
  enterRule(_localctx, 94, SixRGrammerParser::RuleStringLITERAL);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(556);
    match(SixRGrammerParser::FragSTRINGLITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberLITERALContext ------------------------------------------------------------------

SixRGrammerParser::NumberLITERALContext::NumberLITERALContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::IntLITERALContext* SixRGrammerParser::NumberLITERALContext::intLITERAL() {
  return getRuleContext<SixRGrammerParser::IntLITERALContext>(0);
}

SixRGrammerParser::FloatLITERALContext* SixRGrammerParser::NumberLITERALContext::floatLITERAL() {
  return getRuleContext<SixRGrammerParser::FloatLITERALContext>(0);
}


size_t SixRGrammerParser::NumberLITERALContext::getRuleIndex() const {
  return SixRGrammerParser::RuleNumberLITERAL;
}

void SixRGrammerParser::NumberLITERALContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumberLITERAL(this);
}

void SixRGrammerParser::NumberLITERALContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumberLITERAL(this);
}

SixRGrammerParser::NumberLITERALContext* SixRGrammerParser::numberLITERAL() {
  NumberLITERALContext *_localctx = _tracker.createInstance<NumberLITERALContext>(_ctx, getState());
  enterRule(_localctx, 96, SixRGrammerParser::RuleNumberLITERAL);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(560);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SixRGrammerParser::FragINTLITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(558);
        intLITERAL();
        break;
      }

      case SixRGrammerParser::FragFLOATLITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(559);
        floatLITERAL();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BooleanLiteralContext ------------------------------------------------------------------

SixRGrammerParser::BooleanLiteralContext::BooleanLiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SixRGrammerParser::BooleanLiteralContext::TRUE() {
  return getToken(SixRGrammerParser::TRUE, 0);
}

tree::TerminalNode* SixRGrammerParser::BooleanLiteralContext::FALSE() {
  return getToken(SixRGrammerParser::FALSE, 0);
}


size_t SixRGrammerParser::BooleanLiteralContext::getRuleIndex() const {
  return SixRGrammerParser::RuleBooleanLiteral;
}

void SixRGrammerParser::BooleanLiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBooleanLiteral(this);
}

void SixRGrammerParser::BooleanLiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBooleanLiteral(this);
}

SixRGrammerParser::BooleanLiteralContext* SixRGrammerParser::booleanLiteral() {
  BooleanLiteralContext *_localctx = _tracker.createInstance<BooleanLiteralContext>(_ctx, getState());
  enterRule(_localctx, 98, SixRGrammerParser::RuleBooleanLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(562);
    _la = _input->LA(1);
    if (!(_la == SixRGrammerParser::FALSE

    || _la == SixRGrammerParser::TRUE)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParExpressionContext ------------------------------------------------------------------

SixRGrammerParser::ParExpressionContext::ParExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::ParExpressionContext::expression() {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(0);
}


size_t SixRGrammerParser::ParExpressionContext::getRuleIndex() const {
  return SixRGrammerParser::RuleParExpression;
}

void SixRGrammerParser::ParExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParExpression(this);
}

void SixRGrammerParser::ParExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParExpression(this);
}

SixRGrammerParser::ParExpressionContext* SixRGrammerParser::parExpression() {
  ParExpressionContext *_localctx = _tracker.createInstance<ParExpressionContext>(_ctx, getState());
  enterRule(_localctx, 100, SixRGrammerParser::RuleParExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(564);
    match(SixRGrammerParser::T__0);
    setState(565);
    expression();
    setState(566);
    match(SixRGrammerParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

SixRGrammerParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SixRGrammerParser::PrimitiveTypeContext* SixRGrammerParser::TypeContext::primitiveType() {
  return getRuleContext<SixRGrammerParser::PrimitiveTypeContext>(0);
}

SixRGrammerParser::SixRPrimitiveTypeContext* SixRGrammerParser::TypeContext::sixRPrimitiveType() {
  return getRuleContext<SixRGrammerParser::SixRPrimitiveTypeContext>(0);
}


size_t SixRGrammerParser::TypeContext::getRuleIndex() const {
  return SixRGrammerParser::RuleType;
}

void SixRGrammerParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void SixRGrammerParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

SixRGrammerParser::TypeContext* SixRGrammerParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 102, SixRGrammerParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(570);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SixRGrammerParser::BOOL:
      case SixRGrammerParser::CHAR:
      case SixRGrammerParser::INT:
      case SixRGrammerParser::FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(568);
        primitiveType();
        break;
      }

      case SixRGrammerParser::POINTJ:
      case SixRGrammerParser::POINTP:
      case SixRGrammerParser::POS:
      case SixRGrammerParser::ORIENT: {
        enterOuterAlt(_localctx, 2);
        setState(569);
        sixRPrimitiveType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SixRPrimitiveTypeContext ------------------------------------------------------------------

SixRGrammerParser::SixRPrimitiveTypeContext::SixRPrimitiveTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SixRGrammerParser::SixRPrimitiveTypeContext::POS() {
  return getToken(SixRGrammerParser::POS, 0);
}

tree::TerminalNode* SixRGrammerParser::SixRPrimitiveTypeContext::ORIENT() {
  return getToken(SixRGrammerParser::ORIENT, 0);
}

tree::TerminalNode* SixRGrammerParser::SixRPrimitiveTypeContext::POINTJ() {
  return getToken(SixRGrammerParser::POINTJ, 0);
}

tree::TerminalNode* SixRGrammerParser::SixRPrimitiveTypeContext::POINTP() {
  return getToken(SixRGrammerParser::POINTP, 0);
}


size_t SixRGrammerParser::SixRPrimitiveTypeContext::getRuleIndex() const {
  return SixRGrammerParser::RuleSixRPrimitiveType;
}

void SixRGrammerParser::SixRPrimitiveTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSixRPrimitiveType(this);
}

void SixRGrammerParser::SixRPrimitiveTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSixRPrimitiveType(this);
}

SixRGrammerParser::SixRPrimitiveTypeContext* SixRGrammerParser::sixRPrimitiveType() {
  SixRPrimitiveTypeContext *_localctx = _tracker.createInstance<SixRPrimitiveTypeContext>(_ctx, getState());
  enterRule(_localctx, 104, SixRGrammerParser::RuleSixRPrimitiveType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(572);
    _la = _input->LA(1);
    if (!(((((_la - 106) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 106)) & ((1ULL << (SixRGrammerParser::POINTJ - 106))
      | (1ULL << (SixRGrammerParser::POINTP - 106))
      | (1ULL << (SixRGrammerParser::POS - 106))
      | (1ULL << (SixRGrammerParser::ORIENT - 106)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrimitiveTypeContext ------------------------------------------------------------------

SixRGrammerParser::PrimitiveTypeContext::PrimitiveTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SixRGrammerParser::PrimitiveTypeContext::BOOL() {
  return getToken(SixRGrammerParser::BOOL, 0);
}

tree::TerminalNode* SixRGrammerParser::PrimitiveTypeContext::CHAR() {
  return getToken(SixRGrammerParser::CHAR, 0);
}

tree::TerminalNode* SixRGrammerParser::PrimitiveTypeContext::INT() {
  return getToken(SixRGrammerParser::INT, 0);
}

tree::TerminalNode* SixRGrammerParser::PrimitiveTypeContext::FLOAT() {
  return getToken(SixRGrammerParser::FLOAT, 0);
}


size_t SixRGrammerParser::PrimitiveTypeContext::getRuleIndex() const {
  return SixRGrammerParser::RulePrimitiveType;
}

void SixRGrammerParser::PrimitiveTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimitiveType(this);
}

void SixRGrammerParser::PrimitiveTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SixRGrammerListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimitiveType(this);
}

SixRGrammerParser::PrimitiveTypeContext* SixRGrammerParser::primitiveType() {
  PrimitiveTypeContext *_localctx = _tracker.createInstance<PrimitiveTypeContext>(_ctx, getState());
  enterRule(_localctx, 106, SixRGrammerParser::RulePrimitiveType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(574);
    _la = _input->LA(1);
    if (!(((((_la - 31) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 31)) & ((1ULL << (SixRGrammerParser::BOOL - 31))
      | (1ULL << (SixRGrammerParser::CHAR - 31))
      | (1ULL << (SixRGrammerParser::INT - 31))
      | (1ULL << (SixRGrammerParser::FLOAT - 31)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> SixRGrammerParser::_decisionToDFA;
atn::PredictionContextCache SixRGrammerParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SixRGrammerParser::_atn;
std::vector<uint16_t> SixRGrammerParser::_serializedATN;

std::vector<std::string> SixRGrammerParser::_ruleNames = {
  "start", "moduleRoutines", "mainRoutine", "subRoutine", "procedureName", 
  "formalParameters", "parameter", "routineBody", "statementList", "statement", 
  "targetPoint", "apprxExpr", "ffExpr", "conExpr", "thetaExpr", "interruptDeclaration", 
  "interruptPriority", "variableDeclaration", "variableInitialisation", 
  "variableListRest", "assignmentExpression", "sixRJPR", "sixRJXPoint", 
  "sixRPPoint", "sixRPosition", "sixROrientation", "sixRJPoint", "sixRJPart", 
  "sixRRPPart", "sixRPPart", "sixRRPart", "variableName", "arrayVariableSuffix", 
  "expression", "relationalOp", "conditionalOrExpression", "exclusiveOrExpression", 
  "conditionalAndExpression", "additiveExpression", "multiplicativeExpression", 
  "unaryNotExpression", "unaryPlusMinuxExpression", "primary", "literal", 
  "intLITERAL", "floatLITERAL", "charLITERAL", "stringLITERAL", "numberLITERAL", 
  "booleanLiteral", "parExpression", "type", "sixRPrimitiveType", "primitiveType"
};

std::vector<std::string> SixRGrammerParser::_literalNames = {
  "", "'('", "')'", "','", "'='", "'['", "']'", "':'", "'=='", "'!='", "'<='", 
  "'>='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'!'"
};

std::vector<std::string> SixRGrammerParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "FrameType", "TOOL", "BASE", "TASK", "OBJECT", "AND", "ANIN", "ANOUT", 
  "B_AND", "B_NOT", "B_OR", "B_EXOR", "BOOL", "BREAK", "C_DIS", "C_ORI", 
  "C_PTP", "C_VEL", "CASE", "CAST_FROM", "CAST_TO", "CHAR", "CIR_REL", "CIR", 
  "CONST", "CONTINUE", "DELAY", "DECL", "DEF", "DEFAULT", "DEFDAT", "DEFFCT", 
  "DO", "ELSE", "END", "ENDDAT", "ENDFCT", "ENDFOR", "ENDIF", "ENDLOOP", 
  "ENDSWITCH", "ENDWHILE", "ENUM", "EXIT", "EXT", "EXTFCT", "FALSE", "FOR", 
  "GLOBAL", "GOTO", "HALT", "IF", "IMPORT", "INTERRUPT", "INT", "IS", "LIN_REL", 
  "LIN", "LOOP", "MAIN", "MAXIMUM", "MINIMUM", "NOT", "OR", "PRIO", "PTP_REL", 
  "PTP", "PUBLIC", "FLOAT", "REPEAT", "RETURN", "SEC", "SETFRAME", "SIGNAL", 
  "STRUC", "SWITCH", "THEN", "TO", "TRIGGER", "TRUE", "UNTIL", "WAIT", "WHEN", 
  "WHILE", "EXOR", "STARTPROG", "ENDPROG", "POINTJ", "POINTP", "POS", "ORIENT", 
  "Apprx", "THETA", "VECTOR", "CON", "XX", "YY", "ZZ", "AA", "BB", "CC", 
  "FF", "J1", "J2", "J3", "J4", "J5", "J6", "FragINTLITERAL", "FragFLOATLITERAL", 
  "FragCHARLITERAL", "FragSTRINGLITERAL", "IDENTIFIER", "NEWLINE", "WS"
};

dfa::Vocabulary SixRGrammerParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SixRGrammerParser::_tokenNames;

SixRGrammerParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x87, 0x243, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x77, 
    0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x7a, 0xb, 0x3, 0x3, 0x4, 0x5, 0x4, 0x7d, 
    0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x5, 0x4, 0x86, 0xa, 0x4, 0x3, 0x5, 0x5, 0x5, 0x89, 0xa, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0x93, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x7, 0x7, 0x9a, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x9d, 0xb, 
    0x7, 0x5, 0x7, 0x9f, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0xa, 0x7, 0xa, 0xa7, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xaa, 
    0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 
    0xb8, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xc2, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x5, 0xb, 0xc6, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 
    0xb, 0xcc, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 
    0xd2, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x5, 0xb, 0xda, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xde, 0xa, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xe3, 0xa, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x5, 0xb, 0xe7, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x5, 0xb, 0xee, 0xa, 0xb, 0x3, 0xb, 0x5, 0xb, 0xf1, 0xa, 
    0xb, 0x3, 0xb, 0x5, 0xb, 0xf4, 0xa, 0xb, 0x3, 0xb, 0x5, 0xb, 0xf7, 0xa, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xfc, 0xa, 0xb, 0x3, 0xb, 
    0x5, 0xb, 0xff, 0xa, 0xb, 0x3, 0xb, 0x5, 0xb, 0x102, 0xa, 0xb, 0x3, 
    0xb, 0x5, 0xb, 0x105, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x5, 0xb, 0x10b, 0xa, 0xb, 0x3, 0xb, 0x5, 0xb, 0x10e, 0xa, 0xb, 0x3, 
    0xb, 0x5, 0xb, 0x111, 0xa, 0xb, 0x3, 0xb, 0x5, 0xb, 0x114, 0xa, 0xb, 
    0x3, 0xb, 0x5, 0xb, 0x117, 0xa, 0xb, 0x3, 0xb, 0x5, 0xb, 0x11a, 0xa, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x11e, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x124, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x5, 0xb, 0x129, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x12d, 
    0xa, 0xb, 0x5, 0xb, 0x12f, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0x133, 
    0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 
    0x11, 0x5, 0x11, 0x142, 0xa, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 
    0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x150, 0xa, 0x12, 0x3, 0x13, 
    0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x5, 0x13, 0x156, 0xa, 0x13, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x5, 0x14, 0x15b, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 
    0x7, 0x15, 0x15f, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x162, 0xb, 0x15, 
    0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x5, 0x16, 0x168, 0xa, 0x16, 
    0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x5, 0x17, 0x16d, 0xa, 0x17, 0x3, 0x18, 
    0x3, 0x18, 0x5, 0x18, 0x171, 0xa, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x7, 0x19, 0x177, 0xa, 0x19, 0xc, 0x19, 0xe, 0x19, 0x17a, 
    0xb, 0x19, 0x5, 0x19, 0x17c, 0xa, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
    0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x185, 0xa, 0x19, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x18b, 0xa, 0x1a, 
    0xc, 0x1a, 0xe, 0x1a, 0x18e, 0xb, 0x1a, 0x5, 0x1a, 0x190, 0xa, 0x1a, 
    0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x7, 
    0x1b, 0x198, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 0x19b, 0xb, 0x1b, 0x5, 
    0x1b, 0x19d, 0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x1a5, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 
    0x1a8, 0xb, 0x1c, 0x5, 0x1c, 0x1aa, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x5, 
    0x1e, 0x1b4, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x21, 0x3, 0x21, 0x5, 
    0x21, 0x1c0, 0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 
    0x7, 0x22, 0x1c6, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 0x1c9, 0xb, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 
    0x23, 0x7, 0x23, 0x1d2, 0xa, 0x23, 0xc, 0x23, 0xe, 0x23, 0x1d5, 0xb, 
    0x23, 0x5, 0x23, 0x1d7, 0xa, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x7, 0x23, 0x1df, 0xa, 0x23, 0xc, 0x23, 
    0xe, 0x23, 0x1e2, 0xb, 0x23, 0x5, 0x23, 0x1e4, 0xa, 0x23, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x7, 0x25, 0x1eb, 0xa, 0x25, 
    0xc, 0x25, 0xe, 0x25, 0x1ee, 0xb, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x7, 0x26, 0x1f3, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 0x1f6, 0xb, 0x26, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x7, 0x27, 0x1fb, 0xa, 0x27, 0xc, 0x27, 
    0xe, 0x27, 0x1fe, 0xb, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x7, 0x28, 
    0x203, 0xa, 0x28, 0xc, 0x28, 0xe, 0x28, 0x206, 0xb, 0x28, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x7, 0x29, 0x20b, 0xa, 0x29, 0xc, 0x29, 0xe, 0x29, 
    0x20e, 0xb, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
    0x5, 0x2a, 0x215, 0xa, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 
    0x3, 0x2b, 0x5, 0x2b, 0x21c, 0xa, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x5, 0x2c, 0x221, 0xa, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
    0x5, 0x2d, 0x227, 0xa, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 0x5, 
    0x32, 0x233, 0xa, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x23d, 0xa, 0x35, 
    0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x2, 0x2, 0x38, 
    0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 
    0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 
    0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 
    0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 
    0x64, 0x66, 0x68, 0x6a, 0x6c, 0x2, 0xb, 0x3, 0x2, 0x7b, 0x80, 0x3, 0x2, 
    0x74, 0x76, 0x3, 0x2, 0x77, 0x79, 0x3, 0x2, 0xa, 0xf, 0x3, 0x2, 0x10, 
    0x11, 0x3, 0x2, 0x12, 0x13, 0x4, 0x2, 0x43, 0x43, 0x64, 0x64, 0x3, 0x2, 
    0x6c, 0x6f, 0x6, 0x2, 0x21, 0x21, 0x2a, 0x2a, 0x4b, 0x4b, 0x59, 0x59, 
    0x2, 0x26e, 0x2, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x4, 0x78, 0x3, 0x2, 0x2, 
    0x2, 0x6, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x8, 0x88, 0x3, 0x2, 0x2, 0x2, 0xa, 
    0x94, 0x3, 0x2, 0x2, 0x2, 0xc, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xe, 0xa0, 
    0x3, 0x2, 0x2, 0x2, 0x10, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x12, 0xa8, 0x3, 
    0x2, 0x2, 0x2, 0x14, 0x12e, 0x3, 0x2, 0x2, 0x2, 0x16, 0x132, 0x3, 0x2, 
    0x2, 0x2, 0x18, 0x134, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x137, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x13d, 0x3, 0x2, 0x2, 0x2, 
    0x20, 0x141, 0x3, 0x2, 0x2, 0x2, 0x22, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x151, 0x3, 0x2, 0x2, 0x2, 0x26, 0x157, 0x3, 0x2, 0x2, 0x2, 0x28, 0x160, 
    0x3, 0x2, 0x2, 0x2, 0x2a, 0x163, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x16c, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x170, 0x3, 0x2, 0x2, 0x2, 0x30, 0x184, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x186, 0x3, 0x2, 0x2, 0x2, 0x34, 0x193, 0x3, 0x2, 0x2, 
    0x2, 0x36, 0x1a0, 0x3, 0x2, 0x2, 0x2, 0x38, 0x1ad, 0x3, 0x2, 0x2, 0x2, 
    0x3a, 0x1b3, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x3e, 
    0x1b9, 0x3, 0x2, 0x2, 0x2, 0x40, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x42, 0x1c1, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x46, 0x1e5, 0x3, 
    0x2, 0x2, 0x2, 0x48, 0x1e7, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x1ef, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x1ff, 0x3, 0x2, 0x2, 
    0x2, 0x50, 0x207, 0x3, 0x2, 0x2, 0x2, 0x52, 0x214, 0x3, 0x2, 0x2, 0x2, 
    0x54, 0x21b, 0x3, 0x2, 0x2, 0x2, 0x56, 0x220, 0x3, 0x2, 0x2, 0x2, 0x58, 
    0x226, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x228, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x22a, 
    0x3, 0x2, 0x2, 0x2, 0x5e, 0x22c, 0x3, 0x2, 0x2, 0x2, 0x60, 0x22e, 0x3, 
    0x2, 0x2, 0x2, 0x62, 0x232, 0x3, 0x2, 0x2, 0x2, 0x64, 0x234, 0x3, 0x2, 
    0x2, 0x2, 0x66, 0x236, 0x3, 0x2, 0x2, 0x2, 0x68, 0x23c, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x23e, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x240, 0x3, 0x2, 0x2, 0x2, 
    0x6e, 0x6f, 0x5, 0x4, 0x3, 0x2, 0x6f, 0x70, 0x7, 0x2, 0x2, 0x3, 0x70, 
    0x3, 0x3, 0x2, 0x2, 0x2, 0x71, 0x77, 0x5, 0x6, 0x4, 0x2, 0x72, 0x77, 
    0x5, 0x8, 0x5, 0x2, 0x73, 0x77, 0x5, 0x24, 0x13, 0x2, 0x74, 0x77, 0x5, 
    0x20, 0x11, 0x2, 0x75, 0x77, 0x7, 0x86, 0x2, 0x2, 0x76, 0x71, 0x3, 0x2, 
    0x2, 0x2, 0x76, 0x72, 0x3, 0x2, 0x2, 0x2, 0x76, 0x73, 0x3, 0x2, 0x2, 
    0x2, 0x76, 0x74, 0x3, 0x2, 0x2, 0x2, 0x76, 0x75, 0x3, 0x2, 0x2, 0x2, 
    0x77, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x78, 0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 
    0x79, 0x3, 0x2, 0x2, 0x2, 0x79, 0x5, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x78, 
    0x3, 0x2, 0x2, 0x2, 0x7b, 0x7d, 0x7, 0x4b, 0x2, 0x2, 0x7c, 0x7b, 0x3, 
    0x2, 0x2, 0x2, 0x7c, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x7e, 0x3, 0x2, 
    0x2, 0x2, 0x7e, 0x7f, 0x7, 0x50, 0x2, 0x2, 0x7f, 0x80, 0x7, 0x3, 0x2, 
    0x2, 0x80, 0x81, 0x7, 0x4, 0x2, 0x2, 0x81, 0x82, 0x7, 0x86, 0x2, 0x2, 
    0x82, 0x83, 0x5, 0x10, 0x9, 0x2, 0x83, 0x85, 0x7, 0x37, 0x2, 0x2, 0x84, 
    0x86, 0x7, 0x86, 0x2, 0x2, 0x85, 0x84, 0x3, 0x2, 0x2, 0x2, 0x85, 0x86, 
    0x3, 0x2, 0x2, 0x2, 0x86, 0x7, 0x3, 0x2, 0x2, 0x2, 0x87, 0x89, 0x5, 
    0x68, 0x35, 0x2, 0x88, 0x87, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x3, 0x2, 
    0x2, 0x2, 0x89, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x5, 0xa, 0x6, 
    0x2, 0x8b, 0x8c, 0x7, 0x3, 0x2, 0x2, 0x8c, 0x8d, 0x5, 0xc, 0x7, 0x2, 
    0x8d, 0x8e, 0x7, 0x4, 0x2, 0x2, 0x8e, 0x8f, 0x7, 0x86, 0x2, 0x2, 0x8f, 
    0x90, 0x5, 0x10, 0x9, 0x2, 0x90, 0x92, 0x7, 0x37, 0x2, 0x2, 0x91, 0x93, 
    0x7, 0x86, 0x2, 0x2, 0x92, 0x91, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x3, 
    0x2, 0x2, 0x2, 0x93, 0x9, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x7, 0x85, 
    0x2, 0x2, 0x95, 0xb, 0x3, 0x2, 0x2, 0x2, 0x96, 0x9b, 0x5, 0xe, 0x8, 
    0x2, 0x97, 0x98, 0x7, 0x5, 0x2, 0x2, 0x98, 0x9a, 0x5, 0xe, 0x8, 0x2, 
    0x99, 0x97, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9b, 
    0x99, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9f, 
    0x3, 0x2, 0x2, 0x2, 0x9d, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x96, 0x3, 
    0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xd, 0x3, 0x2, 
    0x2, 0x2, 0xa0, 0xa1, 0x5, 0x68, 0x35, 0x2, 0xa1, 0xa2, 0x5, 0x40, 0x21, 
    0x2, 0xa2, 0xf, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x5, 0x12, 0xa, 0x2, 
    0xa4, 0x11, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa7, 0x5, 0x14, 0xb, 0x2, 0xa6, 
    0xa5, 0x3, 0x2, 0x2, 0x2, 0xa7, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa6, 
    0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa9, 0x13, 0x3, 
    0x2, 0x2, 0x2, 0xaa, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x7, 0x2e, 
    0x2, 0x2, 0xac, 0x12f, 0x7, 0x86, 0x2, 0x2, 0xad, 0xae, 0x7, 0x44, 0x2, 
    0x2, 0xae, 0xaf, 0x7, 0x85, 0x2, 0x2, 0xaf, 0xb0, 0x7, 0x6, 0x2, 0x2, 
    0xb0, 0xb1, 0x5, 0x44, 0x23, 0x2, 0xb1, 0xb2, 0x7, 0x62, 0x2, 0x2, 0xb2, 
    0xb3, 0x5, 0x44, 0x23, 0x2, 0xb3, 0xb4, 0x7, 0x86, 0x2, 0x2, 0xb4, 0xb5, 
    0x5, 0x12, 0xa, 0x2, 0xb5, 0xb7, 0x7, 0x3a, 0x2, 0x2, 0xb6, 0xb8, 0x7, 
    0x86, 0x2, 0x2, 0xb7, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb7, 0xb8, 0x3, 0x2, 
    0x2, 0x2, 0xb8, 0x12f, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 0x7, 0x48, 0x2, 
    0x2, 0xba, 0xbb, 0x5, 0x44, 0x23, 0x2, 0xbb, 0xbc, 0x7, 0x61, 0x2, 0x2, 
    0xbc, 0xbd, 0x7, 0x86, 0x2, 0x2, 0xbd, 0xc1, 0x5, 0x12, 0xa, 0x2, 0xbe, 
    0xbf, 0x7, 0x36, 0x2, 0x2, 0xbf, 0xc0, 0x7, 0x86, 0x2, 0x2, 0xc0, 0xc2, 
    0x5, 0x12, 0xa, 0x2, 0xc1, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x3, 
    0x2, 0x2, 0x2, 0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc5, 0x7, 0x3b, 
    0x2, 0x2, 0xc4, 0xc6, 0x7, 0x86, 0x2, 0x2, 0xc5, 0xc4, 0x3, 0x2, 0x2, 
    0x2, 0xc5, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc6, 0x12f, 0x3, 0x2, 0x2, 0x2, 
    0xc7, 0xc8, 0x7, 0x66, 0x2, 0x2, 0xc8, 0xc9, 0x7, 0x44, 0x2, 0x2, 0xc9, 
    0xcb, 0x5, 0x44, 0x23, 0x2, 0xca, 0xcc, 0x7, 0x86, 0x2, 0x2, 0xcb, 0xca, 
    0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcc, 0x12f, 0x3, 
    0x2, 0x2, 0x2, 0xcd, 0xce, 0x7, 0x66, 0x2, 0x2, 0xce, 0xcf, 0x7, 0x5c, 
    0x2, 0x2, 0xcf, 0xd1, 0x5, 0x44, 0x23, 0x2, 0xd0, 0xd2, 0x7, 0x86, 0x2, 
    0x2, 0xd1, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd1, 0xd2, 0x3, 0x2, 0x2, 0x2, 
    0xd2, 0x12f, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x7, 0x68, 0x2, 0x2, 0xd4, 
    0xd5, 0x5, 0x44, 0x23, 0x2, 0xd5, 0xd6, 0x7, 0x86, 0x2, 0x2, 0xd6, 0xd7, 
    0x5, 0x12, 0xa, 0x2, 0xd7, 0xd9, 0x7, 0x3e, 0x2, 0x2, 0xd8, 0xda, 0x7, 
    0x86, 0x2, 0x2, 0xd9, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x3, 0x2, 
    0x2, 0x2, 0xda, 0x12f, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdd, 0x7, 0x5b, 0x2, 
    0x2, 0xdc, 0xde, 0x5, 0x44, 0x23, 0x2, 0xdd, 0xdc, 0x3, 0x2, 0x2, 0x2, 
    0xdd, 0xde, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xdf, 
    0x12f, 0x7, 0x86, 0x2, 0x2, 0xe0, 0xe2, 0x5, 0x2a, 0x16, 0x2, 0xe1, 
    0xe3, 0x7, 0x86, 0x2, 0x2, 0xe2, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 
    0x3, 0x2, 0x2, 0x2, 0xe3, 0x12f, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe6, 0x5, 
    0x44, 0x23, 0x2, 0xe5, 0xe7, 0x7, 0x86, 0x2, 0x2, 0xe6, 0xe5, 0x3, 0x2, 
    0x2, 0x2, 0xe6, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe7, 0x12f, 0x3, 0x2, 0x2, 
    0x2, 0xe8, 0xe9, 0x7, 0x22, 0x2, 0x2, 0xe9, 0x12f, 0x7, 0x86, 0x2, 0x2, 
    0xea, 0xeb, 0x7, 0x57, 0x2, 0x2, 0xeb, 0xed, 0x5, 0x16, 0xc, 0x2, 0xec, 
    0xee, 0x5, 0x1a, 0xe, 0x2, 0xed, 0xec, 0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 
    0x3, 0x2, 0x2, 0x2, 0xee, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf1, 0x5, 
    0x1c, 0xf, 0x2, 0xf0, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x3, 0x2, 
    0x2, 0x2, 0xf1, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf4, 0x5, 0x18, 0xd, 
    0x2, 0xf3, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf4, 0x3, 0x2, 0x2, 0x2, 
    0xf4, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf7, 0x7, 0x86, 0x2, 0x2, 0xf6, 
    0xf5, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x3, 0x2, 0x2, 0x2, 0xf7, 0x12f, 
    0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x7, 0x4e, 0x2, 0x2, 0xf9, 0xfb, 0x5, 
    0x16, 0xc, 0x2, 0xfa, 0xfc, 0x5, 0x1a, 0xe, 0x2, 0xfb, 0xfa, 0x3, 0x2, 
    0x2, 0x2, 0xfb, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfe, 0x3, 0x2, 0x2, 
    0x2, 0xfd, 0xff, 0x5, 0x1c, 0xf, 0x2, 0xfe, 0xfd, 0x3, 0x2, 0x2, 0x2, 
    0xfe, 0xff, 0x3, 0x2, 0x2, 0x2, 0xff, 0x101, 0x3, 0x2, 0x2, 0x2, 0x100, 
    0x102, 0x5, 0x18, 0xd, 0x2, 0x101, 0x100, 0x3, 0x2, 0x2, 0x2, 0x101, 
    0x102, 0x3, 0x2, 0x2, 0x2, 0x102, 0x104, 0x3, 0x2, 0x2, 0x2, 0x103, 
    0x105, 0x7, 0x86, 0x2, 0x2, 0x104, 0x103, 0x3, 0x2, 0x2, 0x2, 0x104, 
    0x105, 0x3, 0x2, 0x2, 0x2, 0x105, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x106, 
    0x107, 0x7, 0x2c, 0x2, 0x2, 0x107, 0x108, 0x5, 0x16, 0xc, 0x2, 0x108, 
    0x10a, 0x5, 0x16, 0xc, 0x2, 0x109, 0x10b, 0x5, 0x16, 0xc, 0x2, 0x10a, 
    0x109, 0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10b, 
    0x10d, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10e, 0x5, 0x1e, 0x10, 0x2, 0x10d, 
    0x10c, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x10e, 0x3, 0x2, 0x2, 0x2, 0x10e, 
    0x110, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x111, 0x5, 0x1a, 0xe, 0x2, 0x110, 
    0x10f, 0x3, 0x2, 0x2, 0x2, 0x110, 0x111, 0x3, 0x2, 0x2, 0x2, 0x111, 
    0x113, 0x3, 0x2, 0x2, 0x2, 0x112, 0x114, 0x5, 0x1c, 0xf, 0x2, 0x113, 
    0x112, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x3, 0x2, 0x2, 0x2, 0x114, 
    0x116, 0x3, 0x2, 0x2, 0x2, 0x115, 0x117, 0x5, 0x18, 0xd, 0x2, 0x116, 
    0x115, 0x3, 0x2, 0x2, 0x2, 0x116, 0x117, 0x3, 0x2, 0x2, 0x2, 0x117, 
    0x119, 0x3, 0x2, 0x2, 0x2, 0x118, 0x11a, 0x7, 0x86, 0x2, 0x2, 0x119, 
    0x118, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11a, 
    0x12f, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11d, 0x5, 0x24, 0x13, 0x2, 0x11c, 
    0x11e, 0x7, 0x86, 0x2, 0x2, 0x11d, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11d, 
    0x11e, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x11f, 
    0x120, 0x7, 0x5d, 0x2, 0x2, 0x120, 0x121, 0x7, 0x15, 0x2, 0x2, 0x121, 
    0x123, 0x5, 0x40, 0x21, 0x2, 0x122, 0x124, 0x7, 0x86, 0x2, 0x2, 0x123, 
    0x122, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0x3, 0x2, 0x2, 0x2, 0x124, 
    0x12f, 0x3, 0x2, 0x2, 0x2, 0x125, 0x12f, 0x7, 0x86, 0x2, 0x2, 0x126, 
    0x128, 0x5, 0x20, 0x11, 0x2, 0x127, 0x129, 0x7, 0x86, 0x2, 0x2, 0x128, 
    0x127, 0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 0x3, 0x2, 0x2, 0x2, 0x129, 
    0x12f, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12c, 0x5, 0x22, 0x12, 0x2, 0x12b, 
    0x12d, 0x7, 0x86, 0x2, 0x2, 0x12c, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12c, 
    0x12d, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x12e, 
    0xab, 0x3, 0x2, 0x2, 0x2, 0x12e, 0xad, 0x3, 0x2, 0x2, 0x2, 0x12e, 0xb9, 
    0x3, 0x2, 0x2, 0x2, 0x12e, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x12e, 0xcd, 0x3, 
    0x2, 0x2, 0x2, 0x12e, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x12e, 0xdb, 0x3, 0x2, 
    0x2, 0x2, 0x12e, 0xe0, 0x3, 0x2, 0x2, 0x2, 0x12e, 0xe4, 0x3, 0x2, 0x2, 
    0x2, 0x12e, 0xe8, 0x3, 0x2, 0x2, 0x2, 0x12e, 0xea, 0x3, 0x2, 0x2, 0x2, 
    0x12e, 0xf8, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x106, 0x3, 0x2, 0x2, 0x2, 0x12e, 
    0x11b, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x12e, 
    0x125, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x126, 0x3, 0x2, 0x2, 0x2, 0x12e, 
    0x12a, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x15, 0x3, 0x2, 0x2, 0x2, 0x130, 0x133, 
    0x5, 0x2e, 0x18, 0x2, 0x131, 0x133, 0x5, 0x40, 0x21, 0x2, 0x132, 0x130, 
    0x3, 0x2, 0x2, 0x2, 0x132, 0x131, 0x3, 0x2, 0x2, 0x2, 0x133, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0x134, 0x135, 0x7, 0x70, 0x2, 0x2, 0x135, 0x136, 0x5, 
    0x44, 0x23, 0x2, 0x136, 0x19, 0x3, 0x2, 0x2, 0x2, 0x137, 0x138, 0x7, 
    0x7a, 0x2, 0x2, 0x138, 0x139, 0x5, 0x44, 0x23, 0x2, 0x139, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0x13a, 0x13b, 0x7, 0x73, 0x2, 0x2, 0x13b, 0x13c, 0x5, 
    0x44, 0x23, 0x2, 0x13c, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x13e, 0x7, 
    0x71, 0x2, 0x2, 0x13e, 0x13f, 0x5, 0x44, 0x23, 0x2, 0x13f, 0x1f, 0x3, 
    0x2, 0x2, 0x2, 0x140, 0x142, 0x7, 0x45, 0x2, 0x2, 0x141, 0x140, 0x3, 
    0x2, 0x2, 0x2, 0x141, 0x142, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0x3, 
    0x2, 0x2, 0x2, 0x143, 0x144, 0x7, 0x4a, 0x2, 0x2, 0x144, 0x145, 0x7, 
    0x30, 0x2, 0x2, 0x145, 0x146, 0x7, 0x85, 0x2, 0x2, 0x146, 0x147, 0x5, 
    0x56, 0x2c, 0x2, 0x147, 0x148, 0x7, 0x67, 0x2, 0x2, 0x148, 0x149, 0x5, 
    0x44, 0x23, 0x2, 0x149, 0x14a, 0x7, 0x35, 0x2, 0x2, 0x14a, 0x14b, 0x5, 
    0x2a, 0x16, 0x2, 0x14b, 0x21, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14d, 0x7, 
    0x4a, 0x2, 0x2, 0x14d, 0x14f, 0x7, 0x85, 0x2, 0x2, 0x14e, 0x150, 0x5, 
    0x56, 0x2c, 0x2, 0x14f, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x3, 
    0x2, 0x2, 0x2, 0x150, 0x23, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 0x5, 0x68, 
    0x35, 0x2, 0x152, 0x155, 0x5, 0x40, 0x21, 0x2, 0x153, 0x156, 0x5, 0x28, 
    0x15, 0x2, 0x154, 0x156, 0x5, 0x26, 0x14, 0x2, 0x155, 0x153, 0x3, 0x2, 
    0x2, 0x2, 0x155, 0x154, 0x3, 0x2, 0x2, 0x2, 0x156, 0x25, 0x3, 0x2, 0x2, 
    0x2, 0x157, 0x15a, 0x7, 0x6, 0x2, 0x2, 0x158, 0x15b, 0x5, 0x44, 0x23, 
    0x2, 0x159, 0x15b, 0x5, 0x2c, 0x17, 0x2, 0x15a, 0x158, 0x3, 0x2, 0x2, 
    0x2, 0x15a, 0x159, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x27, 0x3, 0x2, 0x2, 0x2, 
    0x15c, 0x15d, 0x7, 0x5, 0x2, 0x2, 0x15d, 0x15f, 0x5, 0x40, 0x21, 0x2, 
    0x15e, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x162, 0x3, 0x2, 0x2, 0x2, 
    0x160, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x3, 0x2, 0x2, 0x2, 
    0x161, 0x29, 0x3, 0x2, 0x2, 0x2, 0x162, 0x160, 0x3, 0x2, 0x2, 0x2, 0x163, 
    0x164, 0x5, 0x40, 0x21, 0x2, 0x164, 0x167, 0x7, 0x6, 0x2, 0x2, 0x165, 
    0x168, 0x5, 0x44, 0x23, 0x2, 0x166, 0x168, 0x5, 0x2c, 0x17, 0x2, 0x167, 
    0x165, 0x3, 0x2, 0x2, 0x2, 0x167, 0x166, 0x3, 0x2, 0x2, 0x2, 0x168, 
    0x2b, 0x3, 0x2, 0x2, 0x2, 0x169, 0x16d, 0x5, 0x2e, 0x18, 0x2, 0x16a, 
    0x16d, 0x5, 0x32, 0x1a, 0x2, 0x16b, 0x16d, 0x5, 0x34, 0x1b, 0x2, 0x16c, 
    0x169, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x16c, 
    0x16b, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x171, 
    0x5, 0x30, 0x19, 0x2, 0x16f, 0x171, 0x5, 0x36, 0x1c, 0x2, 0x170, 0x16e, 
    0x3, 0x2, 0x2, 0x2, 0x170, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x171, 0x2f, 0x3, 
    0x2, 0x2, 0x2, 0x172, 0x17b, 0x7, 0x7, 0x2, 0x2, 0x173, 0x178, 0x5, 
    0x3a, 0x1e, 0x2, 0x174, 0x175, 0x7, 0x5, 0x2, 0x2, 0x175, 0x177, 0x5, 
    0x3a, 0x1e, 0x2, 0x176, 0x174, 0x3, 0x2, 0x2, 0x2, 0x177, 0x17a, 0x3, 
    0x2, 0x2, 0x2, 0x178, 0x176, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 0x3, 
    0x2, 0x2, 0x2, 0x179, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x178, 0x3, 
    0x2, 0x2, 0x2, 0x17b, 0x173, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17c, 0x3, 
    0x2, 0x2, 0x2, 0x17c, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x185, 0x7, 
    0x8, 0x2, 0x2, 0x17e, 0x17f, 0x7, 0x7, 0x2, 0x2, 0x17f, 0x180, 0x5, 
    0x40, 0x21, 0x2, 0x180, 0x181, 0x7, 0x5, 0x2, 0x2, 0x181, 0x182, 0x5, 
    0x40, 0x21, 0x2, 0x182, 0x183, 0x7, 0x8, 0x2, 0x2, 0x183, 0x185, 0x3, 
    0x2, 0x2, 0x2, 0x184, 0x172, 0x3, 0x2, 0x2, 0x2, 0x184, 0x17e, 0x3, 
    0x2, 0x2, 0x2, 0x185, 0x31, 0x3, 0x2, 0x2, 0x2, 0x186, 0x18f, 0x7, 0x3, 
    0x2, 0x2, 0x187, 0x18c, 0x5, 0x3c, 0x1f, 0x2, 0x188, 0x189, 0x7, 0x5, 
    0x2, 0x2, 0x189, 0x18b, 0x5, 0x3c, 0x1f, 0x2, 0x18a, 0x188, 0x3, 0x2, 
    0x2, 0x2, 0x18b, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18a, 0x3, 0x2, 
    0x2, 0x2, 0x18c, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x190, 0x3, 0x2, 
    0x2, 0x2, 0x18e, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x187, 0x3, 0x2, 
    0x2, 0x2, 0x18f, 0x190, 0x3, 0x2, 0x2, 0x2, 0x190, 0x191, 0x3, 0x2, 
    0x2, 0x2, 0x191, 0x192, 0x7, 0x4, 0x2, 0x2, 0x192, 0x33, 0x3, 0x2, 0x2, 
    0x2, 0x193, 0x19c, 0x7, 0x3, 0x2, 0x2, 0x194, 0x199, 0x5, 0x3e, 0x20, 
    0x2, 0x195, 0x196, 0x7, 0x5, 0x2, 0x2, 0x196, 0x198, 0x5, 0x3e, 0x20, 
    0x2, 0x197, 0x195, 0x3, 0x2, 0x2, 0x2, 0x198, 0x19b, 0x3, 0x2, 0x2, 
    0x2, 0x199, 0x197, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19a, 0x3, 0x2, 0x2, 
    0x2, 0x19a, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x199, 0x3, 0x2, 0x2, 
    0x2, 0x19c, 0x194, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19d, 0x3, 0x2, 0x2, 
    0x2, 0x19d, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 0x7, 0x4, 0x2, 
    0x2, 0x19f, 0x35, 0x3, 0x2, 0x2, 0x2, 0x1a0, 0x1a9, 0x7, 0x7, 0x2, 0x2, 
    0x1a1, 0x1a6, 0x5, 0x38, 0x1d, 0x2, 0x1a2, 0x1a3, 0x7, 0x5, 0x2, 0x2, 
    0x1a3, 0x1a5, 0x5, 0x38, 0x1d, 0x2, 0x1a4, 0x1a2, 0x3, 0x2, 0x2, 0x2, 
    0x1a5, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a4, 0x3, 0x2, 0x2, 0x2, 
    0x1a6, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1aa, 0x3, 0x2, 0x2, 0x2, 
    0x1a8, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1a1, 0x3, 0x2, 0x2, 0x2, 
    0x1a9, 0x1aa, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x1ab, 0x3, 0x2, 0x2, 0x2, 
    0x1ab, 0x1ac, 0x7, 0x8, 0x2, 0x2, 0x1ac, 0x37, 0x3, 0x2, 0x2, 0x2, 0x1ad, 
    0x1ae, 0x9, 0x2, 0x2, 0x2, 0x1ae, 0x1af, 0x7, 0x9, 0x2, 0x2, 0x1af, 
    0x1b0, 0x5, 0x44, 0x23, 0x2, 0x1b0, 0x39, 0x3, 0x2, 0x2, 0x2, 0x1b1, 
    0x1b4, 0x5, 0x3e, 0x20, 0x2, 0x1b2, 0x1b4, 0x5, 0x3c, 0x1f, 0x2, 0x1b3, 
    0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b4, 
    0x3b, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b6, 0x9, 0x3, 0x2, 0x2, 0x1b6, 0x1b7, 
    0x7, 0x9, 0x2, 0x2, 0x1b7, 0x1b8, 0x5, 0x44, 0x23, 0x2, 0x1b8, 0x3d, 
    0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1ba, 0x9, 0x4, 0x2, 0x2, 0x1ba, 0x1bb, 
    0x7, 0x9, 0x2, 0x2, 0x1bb, 0x1bc, 0x5, 0x44, 0x23, 0x2, 0x1bc, 0x3f, 
    0x3, 0x2, 0x2, 0x2, 0x1bd, 0x1bf, 0x7, 0x85, 0x2, 0x2, 0x1be, 0x1c0, 
    0x5, 0x42, 0x22, 0x2, 0x1bf, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c0, 
    0x3, 0x2, 0x2, 0x2, 0x1c0, 0x41, 0x3, 0x2, 0x2, 0x2, 0x1c1, 0x1c2, 0x7, 
    0x7, 0x2, 0x2, 0x1c2, 0x1c7, 0x5, 0x44, 0x23, 0x2, 0x1c3, 0x1c4, 0x7, 
    0x5, 0x2, 0x2, 0x1c4, 0x1c6, 0x5, 0x44, 0x23, 0x2, 0x1c5, 0x1c3, 0x3, 
    0x2, 0x2, 0x2, 0x1c6, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c5, 0x3, 
    0x2, 0x2, 0x2, 0x1c7, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1ca, 0x3, 
    0x2, 0x2, 0x2, 0x1c9, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1cb, 0x7, 
    0x8, 0x2, 0x2, 0x1cb, 0x43, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cd, 0x5, 0xa, 
    0x6, 0x2, 0x1cd, 0x1d6, 0x7, 0x3, 0x2, 0x2, 0x1ce, 0x1d3, 0x5, 0x44, 
    0x23, 0x2, 0x1cf, 0x1d0, 0x7, 0x5, 0x2, 0x2, 0x1d0, 0x1d2, 0x5, 0x44, 
    0x23, 0x2, 0x1d1, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d5, 0x3, 0x2, 
    0x2, 0x2, 0x1d3, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d4, 0x3, 0x2, 
    0x2, 0x2, 0x1d4, 0x1d7, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d3, 0x3, 0x2, 
    0x2, 0x2, 0x1d6, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1d6, 0x1d7, 0x3, 0x2, 
    0x2, 0x2, 0x1d7, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1d9, 0x7, 0x4, 
    0x2, 0x2, 0x1d9, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1e0, 0x5, 0x48, 
    0x25, 0x2, 0x1db, 0x1dc, 0x5, 0x46, 0x24, 0x2, 0x1dc, 0x1dd, 0x5, 0x48, 
    0x25, 0x2, 0x1dd, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1de, 0x1db, 0x3, 0x2, 
    0x2, 0x2, 0x1df, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x1de, 0x3, 0x2, 
    0x2, 0x2, 0x1e0, 0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1e1, 0x1e4, 0x3, 0x2, 
    0x2, 0x2, 0x1e2, 0x1e0, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1cc, 0x3, 0x2, 
    0x2, 0x2, 0x1e3, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x45, 0x3, 0x2, 0x2, 
    0x2, 0x1e5, 0x1e6, 0x9, 0x5, 0x2, 0x2, 0x1e6, 0x47, 0x3, 0x2, 0x2, 0x2, 
    0x1e7, 0x1ec, 0x5, 0x4a, 0x26, 0x2, 0x1e8, 0x1e9, 0x7, 0x54, 0x2, 0x2, 
    0x1e9, 0x1eb, 0x5, 0x4a, 0x26, 0x2, 0x1ea, 0x1e8, 0x3, 0x2, 0x2, 0x2, 
    0x1eb, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1ea, 0x3, 0x2, 0x2, 0x2, 
    0x1ec, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x49, 0x3, 0x2, 0x2, 0x2, 0x1ee, 
    0x1ec, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x1f4, 0x5, 0x4c, 0x27, 0x2, 0x1f0, 
    0x1f1, 0x7, 0x69, 0x2, 0x2, 0x1f1, 0x1f3, 0x5, 0x4c, 0x27, 0x2, 0x1f2, 
    0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f4, 
    0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f5, 
    0x4b, 0x3, 0x2, 0x2, 0x2, 0x1f6, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1fc, 
    0x5, 0x4e, 0x28, 0x2, 0x1f8, 0x1f9, 0x7, 0x1a, 0x2, 0x2, 0x1f9, 0x1fb, 
    0x5, 0x4e, 0x28, 0x2, 0x1fa, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x1fe, 
    0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1fd, 
    0x3, 0x2, 0x2, 0x2, 0x1fd, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1fc, 0x3, 
    0x2, 0x2, 0x2, 0x1ff, 0x204, 0x5, 0x50, 0x29, 0x2, 0x200, 0x201, 0x9, 
    0x6, 0x2, 0x2, 0x201, 0x203, 0x5, 0x50, 0x29, 0x2, 0x202, 0x200, 0x3, 
    0x2, 0x2, 0x2, 0x203, 0x206, 0x3, 0x2, 0x2, 0x2, 0x204, 0x202, 0x3, 
    0x2, 0x2, 0x2, 0x204, 0x205, 0x3, 0x2, 0x2, 0x2, 0x205, 0x4f, 0x3, 0x2, 
    0x2, 0x2, 0x206, 0x204, 0x3, 0x2, 0x2, 0x2, 0x207, 0x20c, 0x5, 0x52, 
    0x2a, 0x2, 0x208, 0x209, 0x9, 0x7, 0x2, 0x2, 0x209, 0x20b, 0x5, 0x52, 
    0x2a, 0x2, 0x20a, 0x208, 0x3, 0x2, 0x2, 0x2, 0x20b, 0x20e, 0x3, 0x2, 
    0x2, 0x2, 0x20c, 0x20a, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x20d, 0x3, 0x2, 
    0x2, 0x2, 0x20d, 0x51, 0x3, 0x2, 0x2, 0x2, 0x20e, 0x20c, 0x3, 0x2, 0x2, 
    0x2, 0x20f, 0x210, 0x7, 0x53, 0x2, 0x2, 0x210, 0x215, 0x5, 0x52, 0x2a, 
    0x2, 0x211, 0x212, 0x7, 0x14, 0x2, 0x2, 0x212, 0x215, 0x5, 0x52, 0x2a, 
    0x2, 0x213, 0x215, 0x5, 0x54, 0x2b, 0x2, 0x214, 0x20f, 0x3, 0x2, 0x2, 
    0x2, 0x214, 0x211, 0x3, 0x2, 0x2, 0x2, 0x214, 0x213, 0x3, 0x2, 0x2, 
    0x2, 0x215, 0x53, 0x3, 0x2, 0x2, 0x2, 0x216, 0x217, 0x7, 0x10, 0x2, 
    0x2, 0x217, 0x21c, 0x5, 0x54, 0x2b, 0x2, 0x218, 0x219, 0x7, 0x11, 0x2, 
    0x2, 0x219, 0x21c, 0x5, 0x54, 0x2b, 0x2, 0x21a, 0x21c, 0x5, 0x56, 0x2c, 
    0x2, 0x21b, 0x216, 0x3, 0x2, 0x2, 0x2, 0x21b, 0x218, 0x3, 0x2, 0x2, 
    0x2, 0x21b, 0x21a, 0x3, 0x2, 0x2, 0x2, 0x21c, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x21d, 0x221, 0x5, 0x66, 0x34, 0x2, 0x21e, 0x221, 0x5, 0x40, 0x21, 0x2, 
    0x21f, 0x221, 0x5, 0x58, 0x2d, 0x2, 0x220, 0x21d, 0x3, 0x2, 0x2, 0x2, 
    0x220, 0x21e, 0x3, 0x2, 0x2, 0x2, 0x220, 0x21f, 0x3, 0x2, 0x2, 0x2, 
    0x221, 0x57, 0x3, 0x2, 0x2, 0x2, 0x222, 0x227, 0x5, 0x62, 0x32, 0x2, 
    0x223, 0x227, 0x5, 0x5e, 0x30, 0x2, 0x224, 0x227, 0x5, 0x60, 0x31, 0x2, 
    0x225, 0x227, 0x5, 0x64, 0x33, 0x2, 0x226, 0x222, 0x3, 0x2, 0x2, 0x2, 
    0x226, 0x223, 0x3, 0x2, 0x2, 0x2, 0x226, 0x224, 0x3, 0x2, 0x2, 0x2, 
    0x226, 0x225, 0x3, 0x2, 0x2, 0x2, 0x227, 0x59, 0x3, 0x2, 0x2, 0x2, 0x228, 
    0x229, 0x7, 0x81, 0x2, 0x2, 0x229, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x22a, 
    0x22b, 0x7, 0x82, 0x2, 0x2, 0x22b, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x22c, 
    0x22d, 0x7, 0x83, 0x2, 0x2, 0x22d, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x22e, 
    0x22f, 0x7, 0x84, 0x2, 0x2, 0x22f, 0x61, 0x3, 0x2, 0x2, 0x2, 0x230, 
    0x233, 0x5, 0x5a, 0x2e, 0x2, 0x231, 0x233, 0x5, 0x5c, 0x2f, 0x2, 0x232, 
    0x230, 0x3, 0x2, 0x2, 0x2, 0x232, 0x231, 0x3, 0x2, 0x2, 0x2, 0x233, 
    0x63, 0x3, 0x2, 0x2, 0x2, 0x234, 0x235, 0x9, 0x8, 0x2, 0x2, 0x235, 0x65, 
    0x3, 0x2, 0x2, 0x2, 0x236, 0x237, 0x7, 0x3, 0x2, 0x2, 0x237, 0x238, 
    0x5, 0x44, 0x23, 0x2, 0x238, 0x239, 0x7, 0x4, 0x2, 0x2, 0x239, 0x67, 
    0x3, 0x2, 0x2, 0x2, 0x23a, 0x23d, 0x5, 0x6c, 0x37, 0x2, 0x23b, 0x23d, 
    0x5, 0x6a, 0x36, 0x2, 0x23c, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x23b, 
    0x3, 0x2, 0x2, 0x2, 0x23d, 0x69, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x23f, 0x9, 
    0x9, 0x2, 0x2, 0x23f, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x240, 0x241, 0x9, 0xa, 
    0x2, 0x2, 0x241, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x76, 0x78, 0x7c, 0x85, 
    0x88, 0x92, 0x9b, 0x9e, 0xa8, 0xb7, 0xc1, 0xc5, 0xcb, 0xd1, 0xd9, 0xdd, 
    0xe2, 0xe6, 0xed, 0xf0, 0xf3, 0xf6, 0xfb, 0xfe, 0x101, 0x104, 0x10a, 
    0x10d, 0x110, 0x113, 0x116, 0x119, 0x11d, 0x123, 0x128, 0x12c, 0x12e, 
    0x132, 0x141, 0x14f, 0x155, 0x15a, 0x160, 0x167, 0x16c, 0x170, 0x178, 
    0x17b, 0x184, 0x18c, 0x18f, 0x199, 0x19c, 0x1a6, 0x1a9, 0x1b3, 0x1bf, 
    0x1c7, 0x1d3, 0x1d6, 0x1e0, 0x1e3, 0x1ec, 0x1f4, 0x1fc, 0x204, 0x20c, 
    0x214, 0x21b, 0x220, 0x226, 0x232, 0x23c, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SixRGrammerParser::Initializer SixRGrammerParser::_init;
