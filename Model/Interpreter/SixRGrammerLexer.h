
// Generated from SixRGrammer.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  SixRGrammerLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, FrameType = 19, TOOL = 20, 
    BASE = 21, GOTOSTART = 22, TASK = 23, OBJECT = 24, AND = 25, ANIN = 26, 
    ANOUT = 27, B_AND = 28, B_NOT = 29, B_OR = 30, B_EXOR = 31, BOOL = 32, 
    BREAK = 33, C_DIS = 34, C_ORI = 35, C_PTP = 36, C_VEL = 37, CASE = 38, 
    CAST_FROM = 39, CAST_TO = 40, CHAR = 41, CIR_REL = 42, CIR = 43, CONST = 44, 
    CONTINUE = 45, DELAY = 46, DECL = 47, DEF = 48, DEFAULT = 49, DEFDAT = 50, 
    DEFFCT = 51, DO = 52, ELSE = 53, END = 54, ENDDAT = 55, ENDFCT = 56, 
    ENDFOR = 57, ENDIF = 58, ENDLOOP = 59, ENDSWITCH = 60, ENDWHILE = 61, 
    ENUM = 62, EXIT = 63, EXT = 64, EXTFCT = 65, FALSE = 66, FOR = 67, GLOBAL = 68, 
    GOTO = 69, HALT = 70, IF = 71, IMPORT = 72, INTERRUPT = 73, INT = 74, 
    IS = 75, LIN_REL = 76, LIN = 77, LOOP = 78, MAIN = 79, MAXIMUM = 80, 
    MINIMUM = 81, NOT = 82, OR = 83, PRIO = 84, PTP_REL = 85, PTP = 86, 
    PUBLIC = 87, FLOAT = 88, REPEAT = 89, RETURN = 90, SEC = 91, SETFRAME = 92, 
    SIGNAL = 93, STRUC = 94, SWITCH = 95, THEN = 96, TO = 97, TRIGGER = 98, 
    TRUE = 99, UNTIL = 100, WAIT = 101, WHEN = 102, WHILE = 103, EXOR = 104, 
    STARTPROG = 105, ENDPROG = 106, POINTJ = 107, POINTP = 108, POS = 109, 
    ORIENT = 110, Apprx = 111, THETA = 112, VECTOR = 113, CON = 114, XX = 115, 
    YY = 116, ZZ = 117, AA = 118, BB = 119, CC = 120, FF = 121, TIME = 122, 
    J1 = 123, J2 = 124, J3 = 125, J4 = 126, J5 = 127, J6 = 128, FragINTLITERAL = 129, 
    FragFLOATLITERAL = 130, FragCHARLITERAL = 131, FragSTRINGLITERAL = 132, 
    IDENTIFIER = 133, NEWLINE = 134, WS = 135
  };

  SixRGrammerLexer(antlr4::CharStream *input);
  ~SixRGrammerLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

