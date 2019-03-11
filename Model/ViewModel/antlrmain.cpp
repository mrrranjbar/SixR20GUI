#include "antlrmain.h"
using namespace std;
using namespace antlr4;

AntlrMain::AntlrMain()
{

}

void AntlrMain::Start()
{
        std::ifstream stream;
        string _addresspath="/home/ali/Documents/myQtproject/SixR20/Model/Interpreter/text.txt";
        stream.open(_addresspath);
        ANTLRInputStream input(stream);
         SixRGrammerLexer lexer(&input);
         CommonTokenStream token((TokenSource*)&lexer);
         SixRGrammerParser parser(&token);
         tree::ParseTree *mtree = parser.start();
         MsixRlistener listener;
         tree::ParseTreeWalker::DEFAULT.walk(&listener,mtree);

}
