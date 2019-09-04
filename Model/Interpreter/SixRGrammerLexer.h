
// Generated from SixRGrammer.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  SixRGrammerLexer : public antlr4::Lexer {
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
    FragSTRINGLITERAL = 127, IDENTIFIER = 128, NEWLINE = 129, WS = 130
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

