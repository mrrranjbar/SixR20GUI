#include <Model/ViewModel/mainviewmodel.h>
#include <Model/ViewModel/jogviewmodel.h>
#include <Model/ViewModel/positionviewmodel.h>
#include <Model/ViewModel/rightviewmodel.h>
#include <Model/ViewModel/interpreterviewmodel.h>
#include <Model/ViewModel/teachpointviewmodel.h>
#include <Model/Controller/controller.h>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <qqmlcontext.h>
#include <qqml.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Controller *ctrl = Controller::getInstance();

    //JogViewModel *jvm = new JogViewModel();

    qmlRegisterType<MainViewModel>("MainViewModel",1,0,"MainViewModel");

    //******************************
    qmlRegisterType<InterpreterViewModel>("InterpreterViewModel",1,0,"InterpreterViewModel");
    //******************************
    qmlRegisterType<JogViewModel>("JogViewModel",1,0,"JogViewModel");
    qmlRegisterType<teachpointviewmodel>("Teachpointviewmodel",1,0,"Teachpointviewmodel");
    qmlRegisterType<PositionViewModel>("PositionViewModel",1,0,"PositionViewModel");
    qmlRegisterType<RightViewModel>("RightViewModel",1,0,"RightViewModel");
    
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/View/MainView.qml")));
    QQmlContext *ctxt = engine.rootContext();
    ctrl->ctxt = ctxt;
    ctrl->Initialize();
    //    teachpointviewmodel::init();
    // ctxt->setContextProperty("TeachPointModel", QVariant::fromValue(ctrl->dataList));

    if (engine.rootObjects().isEmpty())
        return -1;

    return  app.exec();
}
