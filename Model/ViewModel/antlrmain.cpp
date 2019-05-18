#include "antlrmain.h"
using namespace std;
using namespace antlr4;

AntlrMain::AntlrMain()
{
    std::ifstream stream;
    string _addresspath="/home/fumrobotics/Documents/QtProjects/SixR20_210298/SixR20_git210298/SixR20_git/Model/Interpreter/text.txt";
    stream.open(_addresspath);
    ANTLRInputStream input(stream);
     SixRGrammerLexer lexer(&input);
     CommonTokenStream token((TokenSource*)&lexer);
     SixRGrammerParser parser(&token);
     mtree = parser.start();
}
void AntlrMain::Start()
{
    MsixRlistener listener;
    tree::ParseTreeWalker::DEFAULT.walk(&listener,mtree);
}

//void AntlrMain::run()
//{
//    std::ifstream stream;
//    string _addresspath="/home/fumrobotics/Documents/QtProjects/SixR20_210298/SixR20_git210298/SixR20_git/Model/Interpreter/text.txt";
//    stream.open(_addresspath);
//    ANTLRInputStream input(stream);
//     SixRGrammerLexer lexer(&input);
//     CommonTokenStream token((TokenSource*)&lexer);
//     SixRGrammerParser parser(&token);
//     tree::ParseTree *mtree = parser.start();
//     MsixRlistener listener;
//     tree::ParseTreeWalker::DEFAULT.walk(&listener,mtree);
//}
