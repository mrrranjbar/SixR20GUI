
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
    PUBLIC = 86, FLOAT = 87, REPEAT = 88, RETURN = 89, SEC = 90, SETFRAME = 91, 
    SIGNAL = 92, STRUC = 93, SWITCH = 94, THEN = 95, TO = 96, TRIGGER = 97, 
    TRUE = 98, UNTIL = 99, WAIT = 100, WHEN = 101, WHILE = 102, EXOR = 103, 
    STARTPROG = 104, ENDPROG = 105, POINTJ = 106, POINTP = 107, POS = 108, 
    ORIENT = 109, RADIUS = 110, VECTOR = 111, CON = 112, XX = 113, YY = 114, 
    ZZ = 115, AA = 116, BB = 117, CC = 118, FF = 119, J1 = 120, J2 = 121, 
    J3 = 122, J4 = 123, J5 = 124, J6 = 125, FragINTLITERAL = 126, FragFLOATLITERAL = 127, 
    FragCHARLITERAL = 128, FragSTRINGLITERAL = 129, IDENTIFIER = 130, NEWLINE = 131, 
    WS = 132
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

