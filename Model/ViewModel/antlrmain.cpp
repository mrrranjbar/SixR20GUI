//#include "antlrmain.h"


//AntlrMain2::AntlrMain2(QObject *parent) : QObject(parent)
//{
////    stream.open(_addresspath);
////    input = ANTLRInputStream(stream);
////    lexer = new SixRGrammerLexer(&input);
////    token = new CommonTokenStream((TokenSource*)lexer);
////    parser = new SixRGrammerParser(token);
////    mtree = parser->start();
//}

////int AntlrMain::getCurrentLine()
////{
////    return listener.currentLine;
////}
////void AntlrMain::begin()
////{
////    listener.currentLine =0;
////    tree::ParseTreeWalker::DEFAULT.walk(&listener,mtree);
////}

////void AntlrMain::run()
////{
////    MsixRlistener listener;
////    tree::ParseTreeWalker::DEFAULT.walk(&listener,mtree);
//////    std::ifstream stream;
//////    string _addresspath="/home/fumrobotics/Documents/QtProjects/SixR20_210298/SixR20_git210298/SixR20_git/Model/Interpreter/text.txt";
//////    stream.open(_addresspath);
//////    ANTLRInputStream input(stream);
//////     SixRGrammerLexer lexer(&input);
//////     CommonTokenStream token((TokenSource*)&lexer);
//////     SixRGrammerParser parser(&token);
//////     tree::ParseTree *mtree = parser.start();
//////     MsixRlistener listener;
//////     tree::ParseTreeWalker::DEFAULT.walk(&listener,mtree);
////}
