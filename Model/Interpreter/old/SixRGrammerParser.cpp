
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
    setState(94);
    moduleRoutines();
    setState(95);
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
    setState(103);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SixRGrammerParser::BOOL

    || _la == SixRGrammerParser::CHAR || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & ((1ULL << (SixRGrammerParser::INT - 68))
      | (1ULL << (SixRGrammerParser::MAIN - 68))
      | (1ULL << (SixRGrammerParser::FLOAT - 68))
      | (1ULL << (SixRGrammerParser::POINTJ - 68))
      | (1ULL << (SixRGrammerParser::POINTP - 68))
      | (1ULL << (SixRGrammerParser::POS - 68))
      | (1ULL << (SixRGrammerParser::ORIENT - 68))
      | (1ULL << (SixRGrammerParser::IDENTIFIER - 68))
      | (1ULL << (SixRGrammerParser::NEWLINE - 68)))) != 0)) {
      setState(101);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
      case 1: {
        setState(97);
        mainRoutine();
        break;
      }

      case 2: {
        setState(98);
        subRoutine();
        break;
      }

      case 3: {
        setState(99);
        variableDeclaration();
        break;
      }

      case 4: {
        setState(100);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      setState(105);
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
    setState(107);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SixRGrammerParser::INT) {
      setState(106);
      match(SixRGrammerParser::INT);
    }
    setState(109);
    match(SixRGrammerParser::MAIN);
    setState(110);
    match(SixRGrammerParser::T__0);
    setState(111);
    match(SixRGrammerParser::T__1);
    setState(112);
    match(SixRGrammerParser::NEWLINE);
    setState(113);
    routineBody();
    setState(114);
    match(SixRGrammerParser::END);
    setState(116);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      setState(115);
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
    setState(119);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SixRGrammerParser::BOOL

    || _la == SixRGrammerParser::CHAR || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & ((1ULL << (SixRGrammerParser::INT - 68))
      | (1ULL << (SixRGrammerParser::FLOAT - 68))
      | (1ULL << (SixRGrammerParser::POINTJ - 68))
      | (1ULL << (SixRGrammerParser::POINTP - 68))
      | (1ULL << (SixRGrammerParser::POS - 68))
      | (1ULL << (SixRGrammerParser::ORIENT - 68)))) != 0)) {
      setState(118);
      type();
    }
    setState(121);
    procedureName();
    setState(122);
    match(SixRGrammerParser::T__0);
    setState(123);
    formalParameters();
    setState(124);
    match(SixRGrammerParser::T__1);
    setState(125);
    match(SixRGrammerParser::NEWLINE);
    setState(126);
    routineBody();
    setState(127);
    match(SixRGrammerParser::END);
    setState(129);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      setState(128);
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
    setState(131);
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
    setState(141);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SixRGrammerParser::BOOL

    || _la == SixRGrammerParser::CHAR || ((((_la - 68) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 68)) & ((1ULL << (SixRGrammerParser::INT - 68))
      | (1ULL << (SixRGrammerParser::FLOAT - 68))
      | (1ULL << (SixRGrammerParser::POINTJ - 68))
      | (1ULL << (SixRGrammerParser::POINTP - 68))
      | (1ULL << (SixRGrammerParser::POS - 68))
      | (1ULL << (SixRGrammerParser::ORIENT - 68)))) != 0)) {
      setState(133);
      parameter();
      setState(138);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SixRGrammerParser::T__2) {
        setState(134);
        match(SixRGrammerParser::T__2);
        setState(135);
        parameter();
        setState(140);
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
    setState(143);
    type();
    setState(144);
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
    setState(146);
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
    setState(151);
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
      | (1ULL << SixRGrammerParser::CONTINUE)
      | (1ULL << SixRGrammerParser::FALSE)
      | (1ULL << SixRGrammerParser::FOR))) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & ((1ULL << (SixRGrammerParser::IF - 65))
      | (1ULL << (SixRGrammerParser::INT - 65))
      | (1ULL << (SixRGrammerParser::LIN - 65))
      | (1ULL << (SixRGrammerParser::NOT - 65))
      | (1ULL << (SixRGrammerParser::PTP - 65))
      | (1ULL << (SixRGrammerParser::FLOAT - 65))
      | (1ULL << (SixRGrammerParser::RETURN - 65))
      | (1ULL << (SixRGrammerParser::TRUE - 65))
      | (1ULL << (SixRGrammerParser::WAIT - 65))
      | (1ULL << (SixRGrammerParser::WHILE - 65))
      | (1ULL << (SixRGrammerParser::POINTJ - 65))
      | (1ULL << (SixRGrammerParser::POINTP - 65))
      | (1ULL << (SixRGrammerParser::POS - 65))
      | (1ULL << (SixRGrammerParser::ORIENT - 65))
      | (1ULL << (SixRGrammerParser::FragINTLITERAL - 65))
      | (1ULL << (SixRGrammerParser::FragFLOATLITERAL - 65))
      | (1ULL << (SixRGrammerParser::FragCHARLITERAL - 65))
      | (1ULL << (SixRGrammerParser::FragSTRINGLITERAL - 65))
      | (1ULL << (SixRGrammerParser::IDENTIFIER - 65))
      | (1ULL << (SixRGrammerParser::NEWLINE - 65)))) != 0)) {
      setState(148);
      statement();
      setState(153);
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

SixRGrammerParser::SixRJXPointContext* SixRGrammerParser::STATLINContext::sixRJXPoint() {
  return getRuleContext<SixRGrammerParser::SixRJXPointContext>(0);
}

SixRGrammerParser::VariableNameContext* SixRGrammerParser::STATLINContext::variableName() {
  return getRuleContext<SixRGrammerParser::VariableNameContext>(0);
}

tree::TerminalNode* SixRGrammerParser::STATLINContext::FF() {
  return getToken(SixRGrammerParser::FF, 0);
}

std::vector<SixRGrammerParser::ExpressionContext *> SixRGrammerParser::STATLINContext::expression() {
  return getRuleContexts<SixRGrammerParser::ExpressionContext>();
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::STATLINContext::expression(size_t i) {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(i);
}

tree::TerminalNode* SixRGrammerParser::STATLINContext::CON() {
  return getToken(SixRGrammerParser::CON, 0);
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

SixRGrammerParser::SixRJXPointContext* SixRGrammerParser::STATPTPContext::sixRJXPoint() {
  return getRuleContext<SixRGrammerParser::SixRJXPointContext>(0);
}

SixRGrammerParser::VariableNameContext* SixRGrammerParser::STATPTPContext::variableName() {
  return getRuleContext<SixRGrammerParser::VariableNameContext>(0);
}

tree::TerminalNode* SixRGrammerParser::STATPTPContext::FF() {
  return getToken(SixRGrammerParser::FF, 0);
}

std::vector<SixRGrammerParser::ExpressionContext *> SixRGrammerParser::STATPTPContext::expression() {
  return getRuleContexts<SixRGrammerParser::ExpressionContext>();
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::STATPTPContext::expression(size_t i) {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(i);
}

tree::TerminalNode* SixRGrammerParser::STATPTPContext::CON() {
  return getToken(SixRGrammerParser::CON, 0);
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

std::vector<SixRGrammerParser::SixRJXPointContext *> SixRGrammerParser::STATCIRContext::sixRJXPoint() {
  return getRuleContexts<SixRGrammerParser::SixRJXPointContext>();
}

SixRGrammerParser::SixRJXPointContext* SixRGrammerParser::STATCIRContext::sixRJXPoint(size_t i) {
  return getRuleContext<SixRGrammerParser::SixRJXPointContext>(i);
}

std::vector<SixRGrammerParser::VariableNameContext *> SixRGrammerParser::STATCIRContext::variableName() {
  return getRuleContexts<SixRGrammerParser::VariableNameContext>();
}

SixRGrammerParser::VariableNameContext* SixRGrammerParser::STATCIRContext::variableName(size_t i) {
  return getRuleContext<SixRGrammerParser::VariableNameContext>(i);
}

std::vector<SixRGrammerParser::ExpressionContext *> SixRGrammerParser::STATCIRContext::expression() {
  return getRuleContexts<SixRGrammerParser::ExpressionContext>();
}

SixRGrammerParser::ExpressionContext* SixRGrammerParser::STATCIRContext::expression(size_t i) {
  return getRuleContext<SixRGrammerParser::ExpressionContext>(i);
}

tree::TerminalNode* SixRGrammerParser::STATCIRContext::FF() {
  return getToken(SixRGrammerParser::FF, 0);
}

tree::TerminalNode* SixRGrammerParser::STATCIRContext::CON() {
  return getToken(SixRGrammerParser::CON, 0);
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

tree::TerminalNode* SixRGrammerParser::STATVARDECContext::NEWLINE() {
  return getToken(SixRGrammerParser::NEWLINE, 0);
}

SixRGrammerParser::VariableDeclarationContext* SixRGrammerParser::STATVARDECContext::variableDeclaration() {
  return getRuleContext<SixRGrammerParser::VariableDeclarationContext>(0);
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
    setState(276);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATCONTINUEContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(154);
      match(SixRGrammerParser::CONTINUE);
      setState(155);
      match(SixRGrammerParser::NEWLINE);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATFORContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(156);
      match(SixRGrammerParser::FOR);
      setState(157);
      match(SixRGrammerParser::IDENTIFIER);
      setState(158);
      match(SixRGrammerParser::T__3);
      setState(159);
      expression();
      setState(160);
      match(SixRGrammerParser::TO);
      setState(161);
      expression();
      setState(162);
      match(SixRGrammerParser::NEWLINE);
      setState(163);
      statementList();
      setState(164);
      match(SixRGrammerParser::ENDFOR);
      setState(166);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
      case 1: {
        setState(165);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATIFContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(168);
      match(SixRGrammerParser::IF);
      setState(169);
      expression();
      setState(170);
      match(SixRGrammerParser::THEN);
      setState(171);
      match(SixRGrammerParser::NEWLINE);
      setState(172);
      statementList();
      setState(176);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SixRGrammerParser::ELSE) {
        setState(173);
        match(SixRGrammerParser::ELSE);
        setState(174);
        match(SixRGrammerParser::NEWLINE);
        setState(175);
        statementList();
      }
      setState(178);
      match(SixRGrammerParser::ENDIF);
      setState(180);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
      case 1: {
        setState(179);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 4: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATWAITFORContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(182);
      match(SixRGrammerParser::WAIT);
      setState(183);
      match(SixRGrammerParser::FOR);
      setState(184);
      expression();
      setState(186);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
      case 1: {
        setState(185);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 5: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATWAITSECContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(188);
      match(SixRGrammerParser::WAIT);
      setState(189);
      match(SixRGrammerParser::SEC);
      setState(190);
      expression();
      setState(192);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
      case 1: {
        setState(191);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 6: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATWHILEContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(194);
      match(SixRGrammerParser::WHILE);
      setState(195);
      expression();
      setState(196);
      match(SixRGrammerParser::NEWLINE);
      setState(197);
      statementList();
      setState(198);
      match(SixRGrammerParser::ENDWHILE);
      setState(200);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
      case 1: {
        setState(199);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 7: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATRETURNContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(202);
      match(SixRGrammerParser::RETURN);
      setState(204);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SixRGrammerParser::T__0)
        | (1ULL << SixRGrammerParser::T__13)
        | (1ULL << SixRGrammerParser::T__14)
        | (1ULL << SixRGrammerParser::T__17)
        | (1ULL << SixRGrammerParser::FALSE))) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 76)) & ((1ULL << (SixRGrammerParser::NOT - 76))
        | (1ULL << (SixRGrammerParser::TRUE - 76))
        | (1ULL << (SixRGrammerParser::FragINTLITERAL - 76))
        | (1ULL << (SixRGrammerParser::FragFLOATLITERAL - 76))
        | (1ULL << (SixRGrammerParser::FragCHARLITERAL - 76))
        | (1ULL << (SixRGrammerParser::FragSTRINGLITERAL - 76))
        | (1ULL << (SixRGrammerParser::IDENTIFIER - 76)))) != 0)) {
        setState(203);
        expression();
      }
      setState(206);
      match(SixRGrammerParser::NEWLINE);
      break;
    }

    case 8: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATASINEPRContext>(_localctx));
      enterOuterAlt(_localctx, 8);
      setState(207);
      assignmentExpression();
      setState(209);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
      case 1: {
        setState(208);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 9: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATEXPContext>(_localctx));
      enterOuterAlt(_localctx, 9);
      setState(211);
      expression();
      setState(213);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
      case 1: {
        setState(212);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 10: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATBRAKEContext>(_localctx));
      enterOuterAlt(_localctx, 10);
      setState(215);
      match(SixRGrammerParser::BREAK);
      setState(216);
      match(SixRGrammerParser::NEWLINE);
      break;
    }

    case 11: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATNEWLINEContext>(_localctx));
      enterOuterAlt(_localctx, 11);
      setState(217);
      match(SixRGrammerParser::NEWLINE);
      break;
    }

    case 12: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATPTPContext>(_localctx));
      enterOuterAlt(_localctx, 12);
      setState(218);
      match(SixRGrammerParser::PTP);
      setState(221);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SixRGrammerParser::T__4: {
          setState(219);
          sixRJXPoint();
          break;
        }

        case SixRGrammerParser::IDENTIFIER: {
          setState(220);
          variableName();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(225);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SixRGrammerParser::FF) {
        setState(223);
        match(SixRGrammerParser::FF);
        setState(224);
        expression();
      }
      setState(229);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SixRGrammerParser::CON) {
        setState(227);
        match(SixRGrammerParser::CON);
        setState(228);
        expression();
      }
      setState(232);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
      case 1: {
        setState(231);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 13: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATLINContext>(_localctx));
      enterOuterAlt(_localctx, 13);
      setState(234);
      match(SixRGrammerParser::LIN);
      setState(237);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SixRGrammerParser::T__4: {
          setState(235);
          sixRJXPoint();
          break;
        }

        case SixRGrammerParser::IDENTIFIER: {
          setState(236);
          variableName();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(241);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SixRGrammerParser::FF) {
        setState(239);
        match(SixRGrammerParser::FF);
        setState(240);
        expression();
      }
      setState(245);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SixRGrammerParser::CON) {
        setState(243);
        match(SixRGrammerParser::CON);
        setState(244);
        expression();
      }
      setState(248);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
      case 1: {
        setState(247);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 14: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATCIRContext>(_localctx));
      enterOuterAlt(_localctx, 14);
      setState(250);
      match(SixRGrammerParser::CIR);
      setState(253);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SixRGrammerParser::T__4: {
          setState(251);
          sixRJXPoint();
          break;
        }

        case SixRGrammerParser::IDENTIFIER: {
          setState(252);
          variableName();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(257);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SixRGrammerParser::T__4: {
          setState(255);
          sixRJXPoint();
          break;
        }

        case SixRGrammerParser::IDENTIFIER: {
          setState(256);
          variableName();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(260);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
      case 1: {
        setState(259);
        expression();
        break;
      }

      }
      setState(264);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SixRGrammerParser::FF) {
        setState(262);
        match(SixRGrammerParser::FF);
        setState(263);
        expression();
      }
      setState(268);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SixRGrammerParser::CON) {
        setState(266);
        match(SixRGrammerParser::CON);
        setState(267);
        expression();
      }
      setState(271);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
      case 1: {
        setState(270);
        match(SixRGrammerParser::NEWLINE);
        break;
      }

      }
      break;
    }

    case 15: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<SixRGrammerParser::STATVARDECContext>(_localctx));
      enterOuterAlt(_localctx, 15);
      setState(273);
      variableDeclaration();
      setState(274);
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
  enterRule(_localctx, 20, SixRGrammerParser::RuleVariableDeclaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(278);
    type();
    setState(279);
    variableName();
    setState(282);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SixRGrammerParser::EOF:
      case SixRGrammerParser::T__2:
      case SixRGrammerParser::BOOL:
      case SixRGrammerParser::CHAR:
      case SixRGrammerParser::INT:
      case SixRGrammerParser::MAIN:
      case SixRGrammerParser::FLOAT:
      case SixRGrammerParser::POINTJ:
      case SixRGrammerParser::POINTP:
      case SixRGrammerParser::POS:
      case SixRGrammerParser::ORIENT:
      case SixRGrammerParser::IDENTIFIER:
      case SixRGrammerParser::NEWLINE: {
        setState(280);
        variableListRest();
        break;
      }

      case SixRGrammerParser::T__3: {
        setState(281);
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
  enterRule(_localctx, 22, SixRGrammerParser::RuleVariableInitialisation);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(284);
    match(SixRGrammerParser::T__3);
    setState(287);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      setState(285);
      expression();
      break;
    }

    case 2: {
      setState(286);
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
  enterRule(_localctx, 24, SixRGrammerParser::RuleVariableListRest);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(293);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SixRGrammerParser::T__2) {
      setState(289);
      match(SixRGrammerParser::T__2);
      setState(290);
      variableName();
      setState(295);
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
  enterRule(_localctx, 26, SixRGrammerParser::RuleAssignmentExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(296);
    variableName();
    setState(297);
    match(SixRGrammerParser::T__3);
    setState(300);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(298);
      expression();
      break;
    }

    case 2: {
      setState(299);
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
  enterRule(_localctx, 28, SixRGrammerParser::RuleSixRJPR);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(305);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 37, _ctx)) {
    case 1: {
      setState(302);
      sixRJXPoint();
      break;
    }

    case 2: {
      setState(303);
      sixRPosition();
      break;
    }

    case 3: {
      setState(304);
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
  enterRule(_localctx, 30, SixRGrammerParser::RuleSixRJXPoint);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(309);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 38, _ctx)) {
    case 1: {
      setState(307);
      sixRPPoint();
      break;
    }

    case 2: {
      setState(308);
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
  enterRule(_localctx, 32, SixRGrammerParser::RuleSixRPPoint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(329);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 41, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(311);
      match(SixRGrammerParser::T__4);
      setState(320);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 106) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 106)) & ((1ULL << (SixRGrammerParser::XX - 106))
        | (1ULL << (SixRGrammerParser::YY - 106))
        | (1ULL << (SixRGrammerParser::ZZ - 106))
        | (1ULL << (SixRGrammerParser::AA - 106))
        | (1ULL << (SixRGrammerParser::BB - 106))
        | (1ULL << (SixRGrammerParser::CC - 106)))) != 0)) {
        setState(312);
        sixRRPPart();
        setState(317);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SixRGrammerParser::T__2) {
          setState(313);
          match(SixRGrammerParser::T__2);
          setState(314);
          sixRRPPart();
          setState(319);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(322);
      match(SixRGrammerParser::T__5);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(323);
      match(SixRGrammerParser::T__4);
      setState(324);
      variableName();
      setState(325);
      match(SixRGrammerParser::T__2);
      setState(326);
      variableName();
      setState(327);
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
  enterRule(_localctx, 34, SixRGrammerParser::RuleSixRPosition);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(331);
    match(SixRGrammerParser::T__0);
    setState(340);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 106) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 106)) & ((1ULL << (SixRGrammerParser::XX - 106))
      | (1ULL << (SixRGrammerParser::YY - 106))
      | (1ULL << (SixRGrammerParser::ZZ - 106)))) != 0)) {
      setState(332);
      sixRPPart();
      setState(337);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SixRGrammerParser::T__2) {
        setState(333);
        match(SixRGrammerParser::T__2);
        setState(334);
        sixRPPart();
        setState(339);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(342);
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
  enterRule(_localctx, 36, SixRGrammerParser::RuleSixROrientation);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(344);
    match(SixRGrammerParser::T__0);
    setState(353);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 109) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 109)) & ((1ULL << (SixRGrammerParser::AA - 109))
      | (1ULL << (SixRGrammerParser::BB - 109))
      | (1ULL << (SixRGrammerParser::CC - 109)))) != 0)) {
      setState(345);
      sixRRPart();
      setState(350);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SixRGrammerParser::T__2) {
        setState(346);
        match(SixRGrammerParser::T__2);
        setState(347);
        sixRRPart();
        setState(352);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(355);
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
  enterRule(_localctx, 38, SixRGrammerParser::RuleSixRJPoint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    match(SixRGrammerParser::T__4);
    setState(366);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 113) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 113)) & ((1ULL << (SixRGrammerParser::J1 - 113))
      | (1ULL << (SixRGrammerParser::J2 - 113))
      | (1ULL << (SixRGrammerParser::J3 - 113))
      | (1ULL << (SixRGrammerParser::J4 - 113))
      | (1ULL << (SixRGrammerParser::J5 - 113))
      | (1ULL << (SixRGrammerParser::J6 - 113)))) != 0)) {
      setState(358);
      sixRJPart();
      setState(363);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == SixRGrammerParser::T__2) {
        setState(359);
        match(SixRGrammerParser::T__2);
        setState(360);
        sixRJPart();
        setState(365);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(368);
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
  enterRule(_localctx, 40, SixRGrammerParser::RuleSixRJPart);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(370);
    _la = _input->LA(1);
    if (!(((((_la - 113) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 113)) & ((1ULL << (SixRGrammerParser::J1 - 113))
      | (1ULL << (SixRGrammerParser::J2 - 113))
      | (1ULL << (SixRGrammerParser::J3 - 113))
      | (1ULL << (SixRGrammerParser::J4 - 113))
      | (1ULL << (SixRGrammerParser::J5 - 113))
      | (1ULL << (SixRGrammerParser::J6 - 113)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(371);
    match(SixRGrammerParser::T__6);
    setState(372);
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
  enterRule(_localctx, 42, SixRGrammerParser::RuleSixRRPPart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(376);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SixRGrammerParser::AA:
      case SixRGrammerParser::BB:
      case SixRGrammerParser::CC: {
        enterOuterAlt(_localctx, 1);
        setState(374);
        sixRRPart();
        break;
      }

      case SixRGrammerParser::XX:
      case SixRGrammerParser::YY:
      case SixRGrammerParser::ZZ: {
        enterOuterAlt(_localctx, 2);
        setState(375);
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
  enterRule(_localctx, 44, SixRGrammerParser::RuleSixRPPart);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(378);
    _la = _input->LA(1);
    if (!(((((_la - 106) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 106)) & ((1ULL << (SixRGrammerParser::XX - 106))
      | (1ULL << (SixRGrammerParser::YY - 106))
      | (1ULL << (SixRGrammerParser::ZZ - 106)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(379);
    match(SixRGrammerParser::T__6);
    setState(380);
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
  enterRule(_localctx, 46, SixRGrammerParser::RuleSixRRPart);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(382);
    _la = _input->LA(1);
    if (!(((((_la - 109) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 109)) & ((1ULL << (SixRGrammerParser::AA - 109))
      | (1ULL << (SixRGrammerParser::BB - 109))
      | (1ULL << (SixRGrammerParser::CC - 109)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(383);
    match(SixRGrammerParser::T__6);
    setState(384);
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
  enterRule(_localctx, 48, SixRGrammerParser::RuleVariableName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(386);
    match(SixRGrammerParser::IDENTIFIER);
    setState(388);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      setState(387);
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
  enterRule(_localctx, 50, SixRGrammerParser::RuleArrayVariableSuffix);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(390);
    match(SixRGrammerParser::T__4);

    setState(391);
    expression();
    setState(396);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SixRGrammerParser::T__2) {
      setState(392);
      match(SixRGrammerParser::T__2);
      setState(393);
      expression();
      setState(398);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(399);
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
  enterRule(_localctx, 52, SixRGrammerParser::RuleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(424);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 54, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(401);
      procedureName();
      setState(402);
      match(SixRGrammerParser::T__0);
      setState(411);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SixRGrammerParser::T__0)
        | (1ULL << SixRGrammerParser::T__13)
        | (1ULL << SixRGrammerParser::T__14)
        | (1ULL << SixRGrammerParser::T__17)
        | (1ULL << SixRGrammerParser::FALSE))) != 0) || ((((_la - 76) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 76)) & ((1ULL << (SixRGrammerParser::NOT - 76))
        | (1ULL << (SixRGrammerParser::TRUE - 76))
        | (1ULL << (SixRGrammerParser::FragINTLITERAL - 76))
        | (1ULL << (SixRGrammerParser::FragFLOATLITERAL - 76))
        | (1ULL << (SixRGrammerParser::FragCHARLITERAL - 76))
        | (1ULL << (SixRGrammerParser::FragSTRINGLITERAL - 76))
        | (1ULL << (SixRGrammerParser::IDENTIFIER - 76)))) != 0)) {
        setState(403);
        expression();
        setState(408);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SixRGrammerParser::T__2) {
          setState(404);
          match(SixRGrammerParser::T__2);
          setState(405);
          expression();
          setState(410);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(413);
      match(SixRGrammerParser::T__1);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(415);
      conditionalOrExpression();
      setState(421);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << SixRGrammerParser::T__7)
        | (1ULL << SixRGrammerParser::T__8)
        | (1ULL << SixRGrammerParser::T__9)
        | (1ULL << SixRGrammerParser::T__10)
        | (1ULL << SixRGrammerParser::T__11)
        | (1ULL << SixRGrammerParser::T__12))) != 0)) {
        setState(416);
        relationalOp();
        setState(417);
        conditionalOrExpression();
        setState(423);
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
  enterRule(_localctx, 54, SixRGrammerParser::RuleRelationalOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(426);
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
  enterRule(_localctx, 56, SixRGrammerParser::RuleConditionalOrExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(428);
    exclusiveOrExpression();
    setState(433);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SixRGrammerParser::OR) {
      setState(429);
      match(SixRGrammerParser::OR);
      setState(430);
      exclusiveOrExpression();
      setState(435);
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
  enterRule(_localctx, 58, SixRGrammerParser::RuleExclusiveOrExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(436);
    conditionalAndExpression();
    setState(441);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SixRGrammerParser::EXOR) {
      setState(437);
      match(SixRGrammerParser::EXOR);
      setState(438);
      conditionalAndExpression();
      setState(443);
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
  enterRule(_localctx, 60, SixRGrammerParser::RuleConditionalAndExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(444);
    additiveExpression();
    setState(449);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SixRGrammerParser::AND) {
      setState(445);
      match(SixRGrammerParser::AND);
      setState(446);
      additiveExpression();
      setState(451);
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
  enterRule(_localctx, 62, SixRGrammerParser::RuleAdditiveExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(452);
    multiplicativeExpression();
    setState(457);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(453);
        _la = _input->LA(1);
        if (!(_la == SixRGrammerParser::T__13

        || _la == SixRGrammerParser::T__14)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(454);
        multiplicativeExpression(); 
      }
      setState(459);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 58, _ctx);
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
  enterRule(_localctx, 64, SixRGrammerParser::RuleMultiplicativeExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(460);
    unaryNotExpression();
    setState(465);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SixRGrammerParser::T__15

    || _la == SixRGrammerParser::T__16) {
      setState(461);
      _la = _input->LA(1);
      if (!(_la == SixRGrammerParser::T__15

      || _la == SixRGrammerParser::T__16)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(462);
      unaryNotExpression();
      setState(467);
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
  enterRule(_localctx, 66, SixRGrammerParser::RuleUnaryNotExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(473);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SixRGrammerParser::NOT: {
        enterOuterAlt(_localctx, 1);
        setState(468);
        match(SixRGrammerParser::NOT);
        setState(469);
        unaryNotExpression();
        break;
      }

      case SixRGrammerParser::T__17: {
        enterOuterAlt(_localctx, 2);
        setState(470);
        match(SixRGrammerParser::T__17);
        setState(471);
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
        setState(472);
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
  enterRule(_localctx, 68, SixRGrammerParser::RuleUnaryPlusMinuxExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(480);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SixRGrammerParser::T__13: {
        enterOuterAlt(_localctx, 1);
        setState(475);
        match(SixRGrammerParser::T__13);
        setState(476);
        unaryPlusMinuxExpression();
        break;
      }

      case SixRGrammerParser::T__14: {
        enterOuterAlt(_localctx, 2);
        setState(477);
        match(SixRGrammerParser::T__14);
        setState(478);
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
        setState(479);
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
  enterRule(_localctx, 70, SixRGrammerParser::RulePrimary);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(485);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SixRGrammerParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(482);
        parExpression();
        break;
      }

      case SixRGrammerParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 2);
        setState(483);
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
        setState(484);
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
  enterRule(_localctx, 72, SixRGrammerParser::RuleLiteral);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(491);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SixRGrammerParser::FragINTLITERAL:
      case SixRGrammerParser::FragFLOATLITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(487);
        numberLITERAL();
        break;
      }

      case SixRGrammerParser::FragCHARLITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(488);
        charLITERAL();
        break;
      }

      case SixRGrammerParser::FragSTRINGLITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(489);
        stringLITERAL();
        break;
      }

      case SixRGrammerParser::FALSE:
      case SixRGrammerParser::TRUE: {
        enterOuterAlt(_localctx, 4);
        setState(490);
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
  enterRule(_localctx, 74, SixRGrammerParser::RuleIntLITERAL);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(493);
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
  enterRule(_localctx, 76, SixRGrammerParser::RuleFloatLITERAL);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(495);
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
  enterRule(_localctx, 78, SixRGrammerParser::RuleCharLITERAL);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(497);
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
  enterRule(_localctx, 80, SixRGrammerParser::RuleStringLITERAL);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(499);
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
  enterRule(_localctx, 82, SixRGrammerParser::RuleNumberLITERAL);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(503);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SixRGrammerParser::FragINTLITERAL: {
        enterOuterAlt(_localctx, 1);
        setState(501);
        intLITERAL();
        break;
      }

      case SixRGrammerParser::FragFLOATLITERAL: {
        enterOuterAlt(_localctx, 2);
        setState(502);
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
  enterRule(_localctx, 84, SixRGrammerParser::RuleBooleanLiteral);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(505);
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
  enterRule(_localctx, 86, SixRGrammerParser::RuleParExpression);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(507);
    match(SixRGrammerParser::T__0);
    setState(508);
    expression();
    setState(509);
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
  enterRule(_localctx, 88, SixRGrammerParser::RuleType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(513);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SixRGrammerParser::BOOL:
      case SixRGrammerParser::CHAR:
      case SixRGrammerParser::INT:
      case SixRGrammerParser::FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(511);
        primitiveType();
        break;
      }

      case SixRGrammerParser::POINTJ:
      case SixRGrammerParser::POINTP:
      case SixRGrammerParser::POS:
      case SixRGrammerParser::ORIENT: {
        enterOuterAlt(_localctx, 2);
        setState(512);
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
  enterRule(_localctx, 90, SixRGrammerParser::RuleSixRPrimitiveType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(515);
    _la = _input->LA(1);
    if (!(((((_la - 100) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 100)) & ((1ULL << (SixRGrammerParser::POINTJ - 100))
      | (1ULL << (SixRGrammerParser::POINTP - 100))
      | (1ULL << (SixRGrammerParser::POS - 100))
      | (1ULL << (SixRGrammerParser::ORIENT - 100)))) != 0))) {
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
  enterRule(_localctx, 92, SixRGrammerParser::RulePrimitiveType);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(517);
    _la = _input->LA(1);
    if (!(((((_la - 26) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 26)) & ((1ULL << (SixRGrammerParser::BOOL - 26))
      | (1ULL << (SixRGrammerParser::CHAR - 26))
      | (1ULL << (SixRGrammerParser::INT - 26))
      | (1ULL << (SixRGrammerParser::FLOAT - 26)))) != 0))) {
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
  "variableDeclaration", "variableInitialisation", "variableListRest", "assignmentExpression", 
  "sixRJPR", "sixRJXPoint", "sixRPPoint", "sixRPosition", "sixROrientation", 
  "sixRJPoint", "sixRJPart", "sixRRPPart", "sixRPPart", "sixRRPart", "variableName", 
  "arrayVariableSuffix", "expression", "relationalOp", "conditionalOrExpression", 
  "exclusiveOrExpression", "conditionalAndExpression", "additiveExpression", 
  "multiplicativeExpression", "unaryNotExpression", "unaryPlusMinuxExpression", 
  "primary", "literal", "intLITERAL", "floatLITERAL", "charLITERAL", "stringLITERAL", 
  "numberLITERAL", "booleanLiteral", "parExpression", "type", "sixRPrimitiveType", 
  "primitiveType"
};

std::vector<std::string> SixRGrammerParser::_literalNames = {
  "", "'('", "')'", "','", "'='", "'['", "']'", "':'", "'=='", "'!='", "'<='", 
  "'>='", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'!'"
};

std::vector<std::string> SixRGrammerParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "AND", "ANIN", "ANOUT", "B_AND", "B_NOT", "B_OR", "B_EXOR", "BOOL", 
  "BREAK", "C_DIS", "C_ORI", "C_PTP", "C_VEL", "CASE", "CAST_FROM", "CAST_TO", 
  "CHAR", "CIR_REL", "CIR", "CONST", "CONTINUE", "DELAY", "DECL", "DEF", 
  "DEFAULT", "DEFDAT", "DEFFCT", "DO", "ELSE", "END", "ENDDAT", "ENDFCT", 
  "ENDFOR", "ENDIF", "ENDLOOP", "ENDSWITCH", "ENDWHILE", "ENUM", "EXIT", 
  "EXT", "EXTFCT", "FALSE", "FOR", "GLOBAL", "GOTO", "HALT", "IF", "IMPORT", 
  "INTERRUPT", "INT", "IS", "LIN_REL", "LIN", "LOOP", "MAIN", "MAXIMUM", 
  "MINIMUM", "NOT", "OR", "PRIO", "PTP_REL", "PTP", "PUBLIC", "FLOAT", "REPEAT", 
  "RETURN", "SEC", "SIGNAL", "STRUC", "SWITCH", "THEN", "TO", "TRIGGER", 
  "TRUE", "UNTIL", "WAIT", "WHEN", "WHILE", "EXOR", "STARTPROG", "ENDPROG", 
  "POINTJ", "POINTP", "POS", "ORIENT", "VECTOR", "CON", "XX", "YY", "ZZ", 
  "AA", "BB", "CC", "FF", "J1", "J2", "J3", "J4", "J5", "J6", "FragINTLITERAL", 
  "FragFLOATLITERAL", "FragCHARLITERAL", "FragSTRINGLITERAL", "IDENTIFIER", 
  "NEWLINE", "WS"
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
    0x3, 0x7f, 0x20a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
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
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x68, 0xa, 0x3, 0xc, 0x3, 
    0xe, 0x3, 0x6b, 0xb, 0x3, 0x3, 0x4, 0x5, 0x4, 0x6e, 0xa, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0x77, 0xa, 0x4, 0x3, 0x5, 0x5, 0x5, 0x7a, 0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 
    0x84, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 
    0x7, 0x8b, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x8e, 0xb, 0x7, 0x5, 0x7, 0x90, 
    0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 
    0x7, 0xa, 0x98, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x9b, 0xb, 0xa, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xa9, 0xa, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x5, 0xb, 0xb3, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xb7, 0xa, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xbd, 0xa, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xc3, 0xa, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xcb, 
    0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xcf, 0xa, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x5, 0xb, 0xd4, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 
    0xd8, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x5, 0xb, 0xe0, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xe4, 0xa, 
    0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xe8, 0xa, 0xb, 0x3, 0xb, 0x5, 0xb, 
    0xeb, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xf0, 0xa, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xf4, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 
    0xb, 0xf8, 0xa, 0xb, 0x3, 0xb, 0x5, 0xb, 0xfb, 0xa, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x5, 0xb, 0x100, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 
    0x104, 0xa, 0xb, 0x3, 0xb, 0x5, 0xb, 0x107, 0xa, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x5, 0xb, 0x10b, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0x10f, 
    0xa, 0xb, 0x3, 0xb, 0x5, 0xb, 0x112, 0xa, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x5, 0xb, 0x117, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x5, 0xc, 0x11d, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x122, 
    0xa, 0xd, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x126, 0xa, 0xe, 0xc, 0xe, 0xe, 
    0xe, 0x129, 0xb, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 
    0x12f, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x5, 0x10, 0x134, 
    0xa, 0x10, 0x3, 0x11, 0x3, 0x11, 0x5, 0x11, 0x138, 0xa, 0x11, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x7, 0x12, 0x13e, 0xa, 0x12, 0xc, 0x12, 
    0xe, 0x12, 0x141, 0xb, 0x12, 0x5, 0x12, 0x143, 0xa, 0x12, 0x3, 0x12, 
    0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 
    0x12, 0x14c, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 
    0x7, 0x13, 0x152, 0xa, 0x13, 0xc, 0x13, 0xe, 0x13, 0x155, 0xb, 0x13, 
    0x5, 0x13, 0x157, 0xa, 0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0x15f, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 
    0x162, 0xb, 0x14, 0x5, 0x14, 0x164, 0xa, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x7, 0x15, 0x16c, 0xa, 0x15, 
    0xc, 0x15, 0xe, 0x15, 0x16f, 0xb, 0x15, 0x5, 0x15, 0x171, 0xa, 0x15, 
    0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
    0x17, 0x3, 0x17, 0x5, 0x17, 0x17b, 0xa, 0x17, 0x3, 0x18, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 0x3, 
    0x1a, 0x3, 0x1a, 0x5, 0x1a, 0x187, 0xa, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 
    0x3, 0x1b, 0x3, 0x1b, 0x7, 0x1b, 0x18d, 0xa, 0x1b, 0xc, 0x1b, 0xe, 0x1b, 
    0x190, 0xb, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x199, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 
    0x19c, 0xb, 0x1c, 0x5, 0x1c, 0x19e, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x7, 0x1c, 0x1a6, 0xa, 0x1c, 
    0xc, 0x1c, 0xe, 0x1c, 0x1a9, 0xb, 0x1c, 0x5, 0x1c, 0x1ab, 0xa, 0x1c, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1e, 0x7, 0x1e, 0x1b2, 
    0xa, 0x1e, 0xc, 0x1e, 0xe, 0x1e, 0x1b5, 0xb, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 
    0x3, 0x1f, 0x7, 0x1f, 0x1ba, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x1bd, 
    0xb, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 0x1c2, 0xa, 0x20, 
    0xc, 0x20, 0xe, 0x20, 0x1c5, 0xb, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 
    0x7, 0x21, 0x1ca, 0xa, 0x21, 0xc, 0x21, 0xe, 0x21, 0x1cd, 0xb, 0x21, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x7, 0x22, 0x1d2, 0xa, 0x22, 0xc, 0x22, 
    0xe, 0x22, 0x1d5, 0xb, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
    0x3, 0x23, 0x5, 0x23, 0x1dc, 0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x5, 0x24, 0x1e3, 0xa, 0x24, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x5, 0x25, 0x1e8, 0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x26, 0x5, 0x26, 0x1ee, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 
    0x2b, 0x5, 0x2b, 0x1fa, 0xa, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x204, 
    0xa, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x2, 
    0x2, 0x31, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 
    0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 
    0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 
    0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 
    0x2, 0xb, 0x3, 0x2, 0x73, 0x78, 0x3, 0x2, 0x6c, 0x6e, 0x3, 0x2, 0x6f, 
    0x71, 0x3, 0x2, 0xa, 0xf, 0x3, 0x2, 0x10, 0x11, 0x3, 0x2, 0x12, 0x13, 
    0x4, 0x2, 0x3e, 0x3e, 0x5e, 0x5e, 0x3, 0x2, 0x66, 0x69, 0x6, 0x2, 0x1c, 
    0x1c, 0x25, 0x25, 0x46, 0x46, 0x54, 0x54, 0x2, 0x231, 0x2, 0x60, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6, 0x6d, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x79, 0x3, 0x2, 0x2, 0x2, 0xa, 0x85, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x8f, 0x3, 0x2, 0x2, 0x2, 0xe, 0x91, 0x3, 0x2, 0x2, 0x2, 0x10, 0x94, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0x99, 0x3, 0x2, 0x2, 0x2, 0x14, 0x116, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0x118, 0x3, 0x2, 0x2, 0x2, 0x18, 0x11e, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x127, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x12a, 0x3, 0x2, 0x2, 
    0x2, 0x1e, 0x133, 0x3, 0x2, 0x2, 0x2, 0x20, 0x137, 0x3, 0x2, 0x2, 0x2, 
    0x22, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x24, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x26, 
    0x15a, 0x3, 0x2, 0x2, 0x2, 0x28, 0x167, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x174, 
    0x3, 0x2, 0x2, 0x2, 0x2c, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x17c, 0x3, 
    0x2, 0x2, 0x2, 0x30, 0x180, 0x3, 0x2, 0x2, 0x2, 0x32, 0x184, 0x3, 0x2, 
    0x2, 0x2, 0x34, 0x188, 0x3, 0x2, 0x2, 0x2, 0x36, 0x1aa, 0x3, 0x2, 0x2, 
    0x2, 0x38, 0x1ac, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x1ae, 0x3, 0x2, 0x2, 0x2, 
    0x3c, 0x1b6, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x1be, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x1c6, 0x3, 0x2, 0x2, 0x2, 0x42, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x44, 0x1db, 
    0x3, 0x2, 0x2, 0x2, 0x46, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x48, 0x1e7, 0x3, 
    0x2, 0x2, 0x2, 0x4a, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x1ef, 0x3, 0x2, 
    0x2, 0x2, 0x4e, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x50, 0x1f3, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x1f5, 0x3, 0x2, 0x2, 0x2, 0x54, 0x1f9, 0x3, 0x2, 0x2, 0x2, 
    0x56, 0x1fb, 0x3, 0x2, 0x2, 0x2, 0x58, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x5a, 
    0x203, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x205, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x207, 
    0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x5, 0x4, 0x3, 0x2, 0x61, 0x62, 0x7, 
    0x2, 0x2, 0x3, 0x62, 0x3, 0x3, 0x2, 0x2, 0x2, 0x63, 0x68, 0x5, 0x6, 
    0x4, 0x2, 0x64, 0x68, 0x5, 0x8, 0x5, 0x2, 0x65, 0x68, 0x5, 0x16, 0xc, 
    0x2, 0x66, 0x68, 0x7, 0x7e, 0x2, 0x2, 0x67, 0x63, 0x3, 0x2, 0x2, 0x2, 
    0x67, 0x64, 0x3, 0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x67, 
    0x66, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x69, 0x67, 
    0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6e, 0x7, 0x46, 
    0x2, 0x2, 0x6d, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 0x2, 0x2, 
    0x2, 0x6e, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x7, 0x4b, 0x2, 0x2, 
    0x70, 0x71, 0x7, 0x3, 0x2, 0x2, 0x71, 0x72, 0x7, 0x4, 0x2, 0x2, 0x72, 
    0x73, 0x7, 0x7e, 0x2, 0x2, 0x73, 0x74, 0x5, 0x10, 0x9, 0x2, 0x74, 0x76, 
    0x7, 0x32, 0x2, 0x2, 0x75, 0x77, 0x7, 0x7e, 0x2, 0x2, 0x76, 0x75, 0x3, 
    0x2, 0x2, 0x2, 0x76, 0x77, 0x3, 0x2, 0x2, 0x2, 0x77, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x78, 0x7a, 0x5, 0x5a, 0x2e, 0x2, 0x79, 0x78, 0x3, 0x2, 0x2, 
    0x2, 0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x7b, 0x3, 0x2, 0x2, 0x2, 
    0x7b, 0x7c, 0x5, 0xa, 0x6, 0x2, 0x7c, 0x7d, 0x7, 0x3, 0x2, 0x2, 0x7d, 
    0x7e, 0x5, 0xc, 0x7, 0x2, 0x7e, 0x7f, 0x7, 0x4, 0x2, 0x2, 0x7f, 0x80, 
    0x7, 0x7e, 0x2, 0x2, 0x80, 0x81, 0x5, 0x10, 0x9, 0x2, 0x81, 0x83, 0x7, 
    0x32, 0x2, 0x2, 0x82, 0x84, 0x7, 0x7e, 0x2, 0x2, 0x83, 0x82, 0x3, 0x2, 
    0x2, 0x2, 0x83, 0x84, 0x3, 0x2, 0x2, 0x2, 0x84, 0x9, 0x3, 0x2, 0x2, 
    0x2, 0x85, 0x86, 0x7, 0x7d, 0x2, 0x2, 0x86, 0xb, 0x3, 0x2, 0x2, 0x2, 
    0x87, 0x8c, 0x5, 0xe, 0x8, 0x2, 0x88, 0x89, 0x7, 0x5, 0x2, 0x2, 0x89, 
    0x8b, 0x5, 0xe, 0x8, 0x2, 0x8a, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8e, 
    0x3, 0x2, 0x2, 0x2, 0x8c, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x3, 
    0x2, 0x2, 0x2, 0x8d, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8c, 0x3, 0x2, 
    0x2, 0x2, 0x8f, 0x87, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x3, 0x2, 0x2, 
    0x2, 0x90, 0xd, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x5, 0x5a, 0x2e, 0x2, 
    0x92, 0x93, 0x5, 0x32, 0x1a, 0x2, 0x93, 0xf, 0x3, 0x2, 0x2, 0x2, 0x94, 
    0x95, 0x5, 0x12, 0xa, 0x2, 0x95, 0x11, 0x3, 0x2, 0x2, 0x2, 0x96, 0x98, 
    0x5, 0x14, 0xb, 0x2, 0x97, 0x96, 0x3, 0x2, 0x2, 0x2, 0x98, 0x9b, 0x3, 
    0x2, 0x2, 0x2, 0x99, 0x97, 0x3, 0x2, 0x2, 0x2, 0x99, 0x9a, 0x3, 0x2, 
    0x2, 0x2, 0x9a, 0x13, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x99, 0x3, 0x2, 0x2, 
    0x2, 0x9c, 0x9d, 0x7, 0x29, 0x2, 0x2, 0x9d, 0x117, 0x7, 0x7e, 0x2, 0x2, 
    0x9e, 0x9f, 0x7, 0x3f, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0x7d, 0x2, 0x2, 0xa0, 
    0xa1, 0x7, 0x6, 0x2, 0x2, 0xa1, 0xa2, 0x5, 0x36, 0x1c, 0x2, 0xa2, 0xa3, 
    0x7, 0x5c, 0x2, 0x2, 0xa3, 0xa4, 0x5, 0x36, 0x1c, 0x2, 0xa4, 0xa5, 0x7, 
    0x7e, 0x2, 0x2, 0xa5, 0xa6, 0x5, 0x12, 0xa, 0x2, 0xa6, 0xa8, 0x7, 0x35, 
    0x2, 0x2, 0xa7, 0xa9, 0x7, 0x7e, 0x2, 0x2, 0xa8, 0xa7, 0x3, 0x2, 0x2, 
    0x2, 0xa8, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa9, 0x117, 0x3, 0x2, 0x2, 0x2, 
    0xaa, 0xab, 0x7, 0x43, 0x2, 0x2, 0xab, 0xac, 0x5, 0x36, 0x1c, 0x2, 0xac, 
    0xad, 0x7, 0x5b, 0x2, 0x2, 0xad, 0xae, 0x7, 0x7e, 0x2, 0x2, 0xae, 0xb2, 
    0x5, 0x12, 0xa, 0x2, 0xaf, 0xb0, 0x7, 0x31, 0x2, 0x2, 0xb0, 0xb1, 0x7, 
    0x7e, 0x2, 0x2, 0xb1, 0xb3, 0x5, 0x12, 0xa, 0x2, 0xb2, 0xaf, 0x3, 0x2, 
    0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb4, 0x3, 0x2, 0x2, 
    0x2, 0xb4, 0xb6, 0x7, 0x36, 0x2, 0x2, 0xb5, 0xb7, 0x7, 0x7e, 0x2, 0x2, 
    0xb6, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb7, 
    0x117, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x7, 0x60, 0x2, 0x2, 0xb9, 0xba, 
    0x7, 0x3f, 0x2, 0x2, 0xba, 0xbc, 0x5, 0x36, 0x1c, 0x2, 0xbb, 0xbd, 0x7, 
    0x7e, 0x2, 0x2, 0xbc, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x3, 0x2, 
    0x2, 0x2, 0xbd, 0x117, 0x3, 0x2, 0x2, 0x2, 0xbe, 0xbf, 0x7, 0x60, 0x2, 
    0x2, 0xbf, 0xc0, 0x7, 0x57, 0x2, 0x2, 0xc0, 0xc2, 0x5, 0x36, 0x1c, 0x2, 
    0xc1, 0xc3, 0x7, 0x7e, 0x2, 0x2, 0xc2, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xc2, 
    0xc3, 0x3, 0x2, 0x2, 0x2, 0xc3, 0x117, 0x3, 0x2, 0x2, 0x2, 0xc4, 0xc5, 
    0x7, 0x62, 0x2, 0x2, 0xc5, 0xc6, 0x5, 0x36, 0x1c, 0x2, 0xc6, 0xc7, 0x7, 
    0x7e, 0x2, 0x2, 0xc7, 0xc8, 0x5, 0x12, 0xa, 0x2, 0xc8, 0xca, 0x7, 0x39, 
    0x2, 0x2, 0xc9, 0xcb, 0x7, 0x7e, 0x2, 0x2, 0xca, 0xc9, 0x3, 0x2, 0x2, 
    0x2, 0xca, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcb, 0x117, 0x3, 0x2, 0x2, 0x2, 
    0xcc, 0xce, 0x7, 0x56, 0x2, 0x2, 0xcd, 0xcf, 0x5, 0x36, 0x1c, 0x2, 0xce, 
    0xcd, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 
    0x3, 0x2, 0x2, 0x2, 0xd0, 0x117, 0x7, 0x7e, 0x2, 0x2, 0xd1, 0xd3, 0x5, 
    0x1c, 0xf, 0x2, 0xd2, 0xd4, 0x7, 0x7e, 0x2, 0x2, 0xd3, 0xd2, 0x3, 0x2, 
    0x2, 0x2, 0xd3, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd4, 0x117, 0x3, 0x2, 0x2, 
    0x2, 0xd5, 0xd7, 0x5, 0x36, 0x1c, 0x2, 0xd6, 0xd8, 0x7, 0x7e, 0x2, 0x2, 
    0xd7, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd7, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xd8, 
    0x117, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0x7, 0x1d, 0x2, 0x2, 0xda, 0x117, 
    0x7, 0x7e, 0x2, 0x2, 0xdb, 0x117, 0x7, 0x7e, 0x2, 0x2, 0xdc, 0xdf, 0x7, 
    0x52, 0x2, 0x2, 0xdd, 0xe0, 0x5, 0x20, 0x11, 0x2, 0xde, 0xe0, 0x5, 0x32, 
    0x1a, 0x2, 0xdf, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xde, 0x3, 0x2, 0x2, 
    0x2, 0xe0, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe1, 0xe2, 0x7, 0x72, 0x2, 0x2, 
    0xe2, 0xe4, 0x5, 0x36, 0x1c, 0x2, 0xe3, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe3, 
    0xe4, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe6, 
    0x7, 0x6b, 0x2, 0x2, 0xe6, 0xe8, 0x5, 0x36, 0x1c, 0x2, 0xe7, 0xe5, 0x3, 
    0x2, 0x2, 0x2, 0xe7, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xea, 0x3, 0x2, 
    0x2, 0x2, 0xe9, 0xeb, 0x7, 0x7e, 0x2, 0x2, 0xea, 0xe9, 0x3, 0x2, 0x2, 
    0x2, 0xea, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xeb, 0x117, 0x3, 0x2, 0x2, 0x2, 
    0xec, 0xef, 0x7, 0x49, 0x2, 0x2, 0xed, 0xf0, 0x5, 0x20, 0x11, 0x2, 0xee, 
    0xf0, 0x5, 0x32, 0x1a, 0x2, 0xef, 0xed, 0x3, 0x2, 0x2, 0x2, 0xef, 0xee, 
    0x3, 0x2, 0x2, 0x2, 0xf0, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xf2, 0x7, 
    0x72, 0x2, 0x2, 0xf2, 0xf4, 0x5, 0x36, 0x1c, 0x2, 0xf3, 0xf1, 0x3, 0x2, 
    0x2, 0x2, 0xf3, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf7, 0x3, 0x2, 0x2, 
    0x2, 0xf5, 0xf6, 0x7, 0x6b, 0x2, 0x2, 0xf6, 0xf8, 0x5, 0x36, 0x1c, 0x2, 
    0xf7, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xf8, 
    0xfa, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfb, 0x7, 0x7e, 0x2, 0x2, 0xfa, 0xf9, 
    0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x3, 0x2, 0x2, 0x2, 0xfb, 0x117, 0x3, 
    0x2, 0x2, 0x2, 0xfc, 0xff, 0x7, 0x27, 0x2, 0x2, 0xfd, 0x100, 0x5, 0x20, 
    0x11, 0x2, 0xfe, 0x100, 0x5, 0x32, 0x1a, 0x2, 0xff, 0xfd, 0x3, 0x2, 
    0x2, 0x2, 0xff, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x100, 0x103, 0x3, 0x2, 0x2, 
    0x2, 0x101, 0x104, 0x5, 0x20, 0x11, 0x2, 0x102, 0x104, 0x5, 0x32, 0x1a, 
    0x2, 0x103, 0x101, 0x3, 0x2, 0x2, 0x2, 0x103, 0x102, 0x3, 0x2, 0x2, 
    0x2, 0x104, 0x106, 0x3, 0x2, 0x2, 0x2, 0x105, 0x107, 0x5, 0x36, 0x1c, 
    0x2, 0x106, 0x105, 0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 0x3, 0x2, 0x2, 
    0x2, 0x107, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x108, 0x109, 0x7, 0x72, 0x2, 
    0x2, 0x109, 0x10b, 0x5, 0x36, 0x1c, 0x2, 0x10a, 0x108, 0x3, 0x2, 0x2, 
    0x2, 0x10a, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10e, 0x3, 0x2, 0x2, 
    0x2, 0x10c, 0x10d, 0x7, 0x6b, 0x2, 0x2, 0x10d, 0x10f, 0x5, 0x36, 0x1c, 
    0x2, 0x10e, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10f, 0x3, 0x2, 0x2, 
    0x2, 0x10f, 0x111, 0x3, 0x2, 0x2, 0x2, 0x110, 0x112, 0x7, 0x7e, 0x2, 
    0x2, 0x111, 0x110, 0x3, 0x2, 0x2, 0x2, 0x111, 0x112, 0x3, 0x2, 0x2, 
    0x2, 0x112, 0x117, 0x3, 0x2, 0x2, 0x2, 0x113, 0x114, 0x5, 0x16, 0xc, 
    0x2, 0x114, 0x115, 0x7, 0x7e, 0x2, 0x2, 0x115, 0x117, 0x3, 0x2, 0x2, 
    0x2, 0x116, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x116, 0x9e, 0x3, 0x2, 0x2, 0x2, 
    0x116, 0xaa, 0x3, 0x2, 0x2, 0x2, 0x116, 0xb8, 0x3, 0x2, 0x2, 0x2, 0x116, 
    0xbe, 0x3, 0x2, 0x2, 0x2, 0x116, 0xc4, 0x3, 0x2, 0x2, 0x2, 0x116, 0xcc, 
    0x3, 0x2, 0x2, 0x2, 0x116, 0xd1, 0x3, 0x2, 0x2, 0x2, 0x116, 0xd5, 0x3, 
    0x2, 0x2, 0x2, 0x116, 0xd9, 0x3, 0x2, 0x2, 0x2, 0x116, 0xdb, 0x3, 0x2, 
    0x2, 0x2, 0x116, 0xdc, 0x3, 0x2, 0x2, 0x2, 0x116, 0xec, 0x3, 0x2, 0x2, 
    0x2, 0x116, 0xfc, 0x3, 0x2, 0x2, 0x2, 0x116, 0x113, 0x3, 0x2, 0x2, 0x2, 
    0x117, 0x15, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x5, 0x5a, 0x2e, 0x2, 
    0x119, 0x11c, 0x5, 0x32, 0x1a, 0x2, 0x11a, 0x11d, 0x5, 0x1a, 0xe, 0x2, 
    0x11b, 0x11d, 0x5, 0x18, 0xd, 0x2, 0x11c, 0x11a, 0x3, 0x2, 0x2, 0x2, 
    0x11c, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x11d, 0x17, 0x3, 0x2, 0x2, 0x2, 0x11e, 
    0x121, 0x7, 0x6, 0x2, 0x2, 0x11f, 0x122, 0x5, 0x36, 0x1c, 0x2, 0x120, 
    0x122, 0x5, 0x1e, 0x10, 0x2, 0x121, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x121, 
    0x120, 0x3, 0x2, 0x2, 0x2, 0x122, 0x19, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 
    0x7, 0x5, 0x2, 0x2, 0x124, 0x126, 0x5, 0x32, 0x1a, 0x2, 0x125, 0x123, 
    0x3, 0x2, 0x2, 0x2, 0x126, 0x129, 0x3, 0x2, 0x2, 0x2, 0x127, 0x125, 
    0x3, 0x2, 0x2, 0x2, 0x127, 0x128, 0x3, 0x2, 0x2, 0x2, 0x128, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0x129, 0x127, 0x3, 0x2, 0x2, 0x2, 0x12a, 0x12b, 0x5, 
    0x32, 0x1a, 0x2, 0x12b, 0x12e, 0x7, 0x6, 0x2, 0x2, 0x12c, 0x12f, 0x5, 
    0x36, 0x1c, 0x2, 0x12d, 0x12f, 0x5, 0x1e, 0x10, 0x2, 0x12e, 0x12c, 0x3, 
    0x2, 0x2, 0x2, 0x12e, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x1d, 0x3, 0x2, 
    0x2, 0x2, 0x130, 0x134, 0x5, 0x20, 0x11, 0x2, 0x131, 0x134, 0x5, 0x24, 
    0x13, 0x2, 0x132, 0x134, 0x5, 0x26, 0x14, 0x2, 0x133, 0x130, 0x3, 0x2, 
    0x2, 0x2, 0x133, 0x131, 0x3, 0x2, 0x2, 0x2, 0x133, 0x132, 0x3, 0x2, 
    0x2, 0x2, 0x134, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x135, 0x138, 0x5, 0x22, 
    0x12, 0x2, 0x136, 0x138, 0x5, 0x28, 0x15, 0x2, 0x137, 0x135, 0x3, 0x2, 
    0x2, 0x2, 0x137, 0x136, 0x3, 0x2, 0x2, 0x2, 0x138, 0x21, 0x3, 0x2, 0x2, 
    0x2, 0x139, 0x142, 0x7, 0x7, 0x2, 0x2, 0x13a, 0x13f, 0x5, 0x2c, 0x17, 
    0x2, 0x13b, 0x13c, 0x7, 0x5, 0x2, 0x2, 0x13c, 0x13e, 0x5, 0x2c, 0x17, 
    0x2, 0x13d, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x141, 0x3, 0x2, 0x2, 
    0x2, 0x13f, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x13f, 0x140, 0x3, 0x2, 0x2, 
    0x2, 0x140, 0x143, 0x3, 0x2, 0x2, 0x2, 0x141, 0x13f, 0x3, 0x2, 0x2, 
    0x2, 0x142, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 0x3, 0x2, 0x2, 
    0x2, 0x143, 0x144, 0x3, 0x2, 0x2, 0x2, 0x144, 0x14c, 0x7, 0x8, 0x2, 
    0x2, 0x145, 0x146, 0x7, 0x7, 0x2, 0x2, 0x146, 0x147, 0x5, 0x32, 0x1a, 
    0x2, 0x147, 0x148, 0x7, 0x5, 0x2, 0x2, 0x148, 0x149, 0x5, 0x32, 0x1a, 
    0x2, 0x149, 0x14a, 0x7, 0x8, 0x2, 0x2, 0x14a, 0x14c, 0x3, 0x2, 0x2, 
    0x2, 0x14b, 0x139, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x145, 0x3, 0x2, 0x2, 
    0x2, 0x14c, 0x23, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x156, 0x7, 0x3, 0x2, 0x2, 
    0x14e, 0x153, 0x5, 0x2e, 0x18, 0x2, 0x14f, 0x150, 0x7, 0x5, 0x2, 0x2, 
    0x150, 0x152, 0x5, 0x2e, 0x18, 0x2, 0x151, 0x14f, 0x3, 0x2, 0x2, 0x2, 
    0x152, 0x155, 0x3, 0x2, 0x2, 0x2, 0x153, 0x151, 0x3, 0x2, 0x2, 0x2, 
    0x153, 0x154, 0x3, 0x2, 0x2, 0x2, 0x154, 0x157, 0x3, 0x2, 0x2, 0x2, 
    0x155, 0x153, 0x3, 0x2, 0x2, 0x2, 0x156, 0x14e, 0x3, 0x2, 0x2, 0x2, 
    0x156, 0x157, 0x3, 0x2, 0x2, 0x2, 0x157, 0x158, 0x3, 0x2, 0x2, 0x2, 
    0x158, 0x159, 0x7, 0x4, 0x2, 0x2, 0x159, 0x25, 0x3, 0x2, 0x2, 0x2, 0x15a, 
    0x163, 0x7, 0x3, 0x2, 0x2, 0x15b, 0x160, 0x5, 0x30, 0x19, 0x2, 0x15c, 
    0x15d, 0x7, 0x5, 0x2, 0x2, 0x15d, 0x15f, 0x5, 0x30, 0x19, 0x2, 0x15e, 
    0x15c, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x162, 0x3, 0x2, 0x2, 0x2, 0x160, 
    0x15e, 0x3, 0x2, 0x2, 0x2, 0x160, 0x161, 0x3, 0x2, 0x2, 0x2, 0x161, 
    0x164, 0x3, 0x2, 0x2, 0x2, 0x162, 0x160, 0x3, 0x2, 0x2, 0x2, 0x163, 
    0x15b, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x3, 0x2, 0x2, 0x2, 0x164, 
    0x165, 0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x7, 0x4, 0x2, 0x2, 0x166, 
    0x27, 0x3, 0x2, 0x2, 0x2, 0x167, 0x170, 0x7, 0x7, 0x2, 0x2, 0x168, 0x16d, 
    0x5, 0x2a, 0x16, 0x2, 0x169, 0x16a, 0x7, 0x5, 0x2, 0x2, 0x16a, 0x16c, 
    0x5, 0x2a, 0x16, 0x2, 0x16b, 0x169, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16f, 
    0x3, 0x2, 0x2, 0x2, 0x16d, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16e, 
    0x3, 0x2, 0x2, 0x2, 0x16e, 0x171, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x16d, 
    0x3, 0x2, 0x2, 0x2, 0x170, 0x168, 0x3, 0x2, 0x2, 0x2, 0x170, 0x171, 
    0x3, 0x2, 0x2, 0x2, 0x171, 0x172, 0x3, 0x2, 0x2, 0x2, 0x172, 0x173, 
    0x7, 0x8, 0x2, 0x2, 0x173, 0x29, 0x3, 0x2, 0x2, 0x2, 0x174, 0x175, 0x9, 
    0x2, 0x2, 0x2, 0x175, 0x176, 0x7, 0x9, 0x2, 0x2, 0x176, 0x177, 0x5, 
    0x36, 0x1c, 0x2, 0x177, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x178, 0x17b, 0x5, 
    0x30, 0x19, 0x2, 0x179, 0x17b, 0x5, 0x2e, 0x18, 0x2, 0x17a, 0x178, 0x3, 
    0x2, 0x2, 0x2, 0x17a, 0x179, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x2d, 0x3, 0x2, 
    0x2, 0x2, 0x17c, 0x17d, 0x9, 0x3, 0x2, 0x2, 0x17d, 0x17e, 0x7, 0x9, 
    0x2, 0x2, 0x17e, 0x17f, 0x5, 0x36, 0x1c, 0x2, 0x17f, 0x2f, 0x3, 0x2, 
    0x2, 0x2, 0x180, 0x181, 0x9, 0x4, 0x2, 0x2, 0x181, 0x182, 0x7, 0x9, 
    0x2, 0x2, 0x182, 0x183, 0x5, 0x36, 0x1c, 0x2, 0x183, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0x184, 0x186, 0x7, 0x7d, 0x2, 0x2, 0x185, 0x187, 0x5, 0x34, 
    0x1b, 0x2, 0x186, 0x185, 0x3, 0x2, 0x2, 0x2, 0x186, 0x187, 0x3, 0x2, 
    0x2, 0x2, 0x187, 0x33, 0x3, 0x2, 0x2, 0x2, 0x188, 0x189, 0x7, 0x7, 0x2, 
    0x2, 0x189, 0x18e, 0x5, 0x36, 0x1c, 0x2, 0x18a, 0x18b, 0x7, 0x5, 0x2, 
    0x2, 0x18b, 0x18d, 0x5, 0x36, 0x1c, 0x2, 0x18c, 0x18a, 0x3, 0x2, 0x2, 
    0x2, 0x18d, 0x190, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x18c, 0x3, 0x2, 0x2, 
    0x2, 0x18e, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x191, 0x3, 0x2, 0x2, 
    0x2, 0x190, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 0x7, 0x8, 0x2, 
    0x2, 0x192, 0x35, 0x3, 0x2, 0x2, 0x2, 0x193, 0x194, 0x5, 0xa, 0x6, 0x2, 
    0x194, 0x19d, 0x7, 0x3, 0x2, 0x2, 0x195, 0x19a, 0x5, 0x36, 0x1c, 0x2, 
    0x196, 0x197, 0x7, 0x5, 0x2, 0x2, 0x197, 0x199, 0x5, 0x36, 0x1c, 0x2, 
    0x198, 0x196, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19c, 0x3, 0x2, 0x2, 0x2, 
    0x19a, 0x198, 0x3, 0x2, 0x2, 0x2, 0x19a, 0x19b, 0x3, 0x2, 0x2, 0x2, 
    0x19b, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x19c, 0x19a, 0x3, 0x2, 0x2, 0x2, 
    0x19d, 0x195, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19e, 0x3, 0x2, 0x2, 0x2, 
    0x19e, 0x19f, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x7, 0x4, 0x2, 0x2, 
    0x1a0, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x1a7, 0x5, 0x3a, 0x1e, 0x2, 
    0x1a2, 0x1a3, 0x5, 0x38, 0x1d, 0x2, 0x1a3, 0x1a4, 0x5, 0x3a, 0x1e, 0x2, 
    0x1a4, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1a5, 0x1a2, 0x3, 0x2, 0x2, 0x2, 
    0x1a6, 0x1a9, 0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a5, 0x3, 0x2, 0x2, 0x2, 
    0x1a7, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1ab, 0x3, 0x2, 0x2, 0x2, 
    0x1a9, 0x1a7, 0x3, 0x2, 0x2, 0x2, 0x1aa, 0x193, 0x3, 0x2, 0x2, 0x2, 
    0x1aa, 0x1a1, 0x3, 0x2, 0x2, 0x2, 0x1ab, 0x37, 0x3, 0x2, 0x2, 0x2, 0x1ac, 
    0x1ad, 0x9, 0x5, 0x2, 0x2, 0x1ad, 0x39, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1b3, 
    0x5, 0x3c, 0x1f, 0x2, 0x1af, 0x1b0, 0x7, 0x4f, 0x2, 0x2, 0x1b0, 0x1b2, 
    0x5, 0x3c, 0x1f, 0x2, 0x1b1, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b5, 
    0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b4, 
    0x3, 0x2, 0x2, 0x2, 0x1b4, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x1b3, 0x3, 
    0x2, 0x2, 0x2, 0x1b6, 0x1bb, 0x5, 0x3e, 0x20, 0x2, 0x1b7, 0x1b8, 0x7, 
    0x63, 0x2, 0x2, 0x1b8, 0x1ba, 0x5, 0x3e, 0x20, 0x2, 0x1b9, 0x1b7, 0x3, 
    0x2, 0x2, 0x2, 0x1ba, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1b9, 0x3, 
    0x2, 0x2, 0x2, 0x1bb, 0x1bc, 0x3, 0x2, 0x2, 0x2, 0x1bc, 0x3d, 0x3, 0x2, 
    0x2, 0x2, 0x1bd, 0x1bb, 0x3, 0x2, 0x2, 0x2, 0x1be, 0x1c3, 0x5, 0x40, 
    0x21, 0x2, 0x1bf, 0x1c0, 0x7, 0x15, 0x2, 0x2, 0x1c0, 0x1c2, 0x5, 0x40, 
    0x21, 0x2, 0x1c1, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c5, 0x3, 0x2, 
    0x2, 0x2, 0x1c3, 0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1c3, 0x1c4, 0x3, 0x2, 
    0x2, 0x2, 0x1c4, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c3, 0x3, 0x2, 0x2, 
    0x2, 0x1c6, 0x1cb, 0x5, 0x42, 0x22, 0x2, 0x1c7, 0x1c8, 0x9, 0x6, 0x2, 
    0x2, 0x1c8, 0x1ca, 0x5, 0x42, 0x22, 0x2, 0x1c9, 0x1c7, 0x3, 0x2, 0x2, 
    0x2, 0x1ca, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1cb, 0x1c9, 0x3, 0x2, 0x2, 
    0x2, 0x1cb, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0x1cd, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1ce, 0x1d3, 0x5, 0x44, 0x23, 0x2, 
    0x1cf, 0x1d0, 0x9, 0x7, 0x2, 0x2, 0x1d0, 0x1d2, 0x5, 0x44, 0x23, 0x2, 
    0x1d1, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d5, 0x3, 0x2, 0x2, 0x2, 
    0x1d3, 0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d4, 0x3, 0x2, 0x2, 0x2, 
    0x1d4, 0x43, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d6, 
    0x1d7, 0x7, 0x4e, 0x2, 0x2, 0x1d7, 0x1dc, 0x5, 0x44, 0x23, 0x2, 0x1d8, 
    0x1d9, 0x7, 0x14, 0x2, 0x2, 0x1d9, 0x1dc, 0x5, 0x44, 0x23, 0x2, 0x1da, 
    0x1dc, 0x5, 0x46, 0x24, 0x2, 0x1db, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1db, 
    0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1dc, 
    0x45, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1de, 0x7, 0x10, 0x2, 0x2, 0x1de, 
    0x1e3, 0x5, 0x46, 0x24, 0x2, 0x1df, 0x1e0, 0x7, 0x11, 0x2, 0x2, 0x1e0, 
    0x1e3, 0x5, 0x46, 0x24, 0x2, 0x1e1, 0x1e3, 0x5, 0x48, 0x25, 0x2, 0x1e2, 
    0x1dd, 0x3, 0x2, 0x2, 0x2, 0x1e2, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x1e2, 
    0x1e1, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x47, 0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1e8, 
    0x5, 0x58, 0x2d, 0x2, 0x1e5, 0x1e8, 0x5, 0x32, 0x1a, 0x2, 0x1e6, 0x1e8, 
    0x5, 0x4a, 0x26, 0x2, 0x1e7, 0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e5, 
    0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x49, 0x3, 
    0x2, 0x2, 0x2, 0x1e9, 0x1ee, 0x5, 0x54, 0x2b, 0x2, 0x1ea, 0x1ee, 0x5, 
    0x50, 0x29, 0x2, 0x1eb, 0x1ee, 0x5, 0x52, 0x2a, 0x2, 0x1ec, 0x1ee, 0x5, 
    0x56, 0x2c, 0x2, 0x1ed, 0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1ea, 0x3, 
    0x2, 0x2, 0x2, 0x1ed, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1ec, 0x3, 
    0x2, 0x2, 0x2, 0x1ee, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x1f0, 0x7, 0x79, 
    0x2, 0x2, 0x1f0, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1f2, 0x7, 0x7a, 
    0x2, 0x2, 0x1f2, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f4, 0x7, 0x7b, 
    0x2, 0x2, 0x1f4, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f6, 0x7, 0x7c, 
    0x2, 0x2, 0x1f6, 0x53, 0x3, 0x2, 0x2, 0x2, 0x1f7, 0x1fa, 0x5, 0x4c, 
    0x27, 0x2, 0x1f8, 0x1fa, 0x5, 0x4e, 0x28, 0x2, 0x1f9, 0x1f7, 0x3, 0x2, 
    0x2, 0x2, 0x1f9, 0x1f8, 0x3, 0x2, 0x2, 0x2, 0x1fa, 0x55, 0x3, 0x2, 0x2, 
    0x2, 0x1fb, 0x1fc, 0x9, 0x8, 0x2, 0x2, 0x1fc, 0x57, 0x3, 0x2, 0x2, 0x2, 
    0x1fd, 0x1fe, 0x7, 0x3, 0x2, 0x2, 0x1fe, 0x1ff, 0x5, 0x36, 0x1c, 0x2, 
    0x1ff, 0x200, 0x7, 0x4, 0x2, 0x2, 0x200, 0x59, 0x3, 0x2, 0x2, 0x2, 0x201, 
    0x204, 0x5, 0x5e, 0x30, 0x2, 0x202, 0x204, 0x5, 0x5c, 0x2f, 0x2, 0x203, 
    0x201, 0x3, 0x2, 0x2, 0x2, 0x203, 0x202, 0x3, 0x2, 0x2, 0x2, 0x204, 
    0x5b, 0x3, 0x2, 0x2, 0x2, 0x205, 0x206, 0x9, 0x9, 0x2, 0x2, 0x206, 0x5d, 
    0x3, 0x2, 0x2, 0x2, 0x207, 0x208, 0x9, 0xa, 0x2, 0x2, 0x208, 0x5f, 0x3, 
    0x2, 0x2, 0x2, 0x44, 0x67, 0x69, 0x6d, 0x76, 0x79, 0x83, 0x8c, 0x8f, 
    0x99, 0xa8, 0xb2, 0xb6, 0xbc, 0xc2, 0xca, 0xce, 0xd3, 0xd7, 0xdf, 0xe3, 
    0xe7, 0xea, 0xef, 0xf3, 0xf7, 0xfa, 0xff, 0x103, 0x106, 0x10a, 0x10e, 
    0x111, 0x116, 0x11c, 0x121, 0x127, 0x12e, 0x133, 0x137, 0x13f, 0x142, 
    0x14b, 0x153, 0x156, 0x160, 0x163, 0x16d, 0x170, 0x17a, 0x186, 0x18e, 
    0x19a, 0x19d, 0x1a7, 0x1aa, 0x1b3, 0x1bb, 0x1c3, 0x1cb, 0x1d3, 0x1db, 
    0x1e2, 0x1e7, 0x1ed, 0x1f9, 0x203, 
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
