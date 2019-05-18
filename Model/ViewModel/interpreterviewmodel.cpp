#include "interpreterviewmodel.h"
#include <QThread>
#include <iostream>


using namespace std;



InterpreterViewModel::InterpreterViewModel(QObject *parent) : QObject(parent)
{
    controller = Controller::getInstance();
    th = new QThread();
//    this->moveToThread(th);
}

void InterpreterViewModel::play()
{


    AntlrMain Am;
    //Am.Start();
    Am.Start();


//    QString _temp=_textEditString;
//    qInfo("qt play");
}

void InterpreterViewModel::pause()
{
//    controller->beckhoff->setGUIManager(99);
//    controller->beckhoff->setGUIManager(2);
    qInfo("qt pause");

}
QString InterpreterViewModel:: textEditString()
{
    return _textEditString;
}

void InterpreterViewModel::settextEditString(QString str)
{
    _textEditString=str;
    emit textEditStringChanged();
    setinputStream(_textEditString);
}

//QDataStream* InterpreterViewModel::inputStream()
//{
//    return _inputstream;
//}

void InterpreterViewModel::setinputStream(QString stg)
{
   // _inputstream=QDataStream(stg);
}

QString InterpreterViewModel::addressPath()
{



   /*
     SixRGrammerParser::FileContext* tree = parser.file();

     ImageVisitor visitor;
     Scene scene = visitor.visitFile(tree);
     scene.draw();


     tree::ParseTree *tree = parser.start();
     SixRGrammerListener listener;
     tree::ParseTreeWalker::DEFAULT->walk(&listener, tree);

*/

    return "hch";// _addresspath;
}


