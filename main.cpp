#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <Model/ViewModel/mainviewmodel.h>
#include <Model/ViewModel/jogviewmodel.h>
#include <Model/ViewModel/positionviewmodel.h>
#include <Model/ViewModel/rightviewmodel.h>
#include <Model/ViewModel/interpreterviewmodel.h>
#include <QtQml>


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    MainViewModel *mvm = new MainViewModel();
    mvm->Initialize();
    //JogViewModel *jvm = new JogViewModel();

    qmlRegisterType<MainViewModel>("MainViewModel",1,0,"MainViewModel");

    //******************************
    qmlRegisterType<InterpreterViewModel>("InterpreterViewModel",1,0,"InterpreterViewModel");
    //******************************
    qmlRegisterType<JogViewModel>("JogViewModel",1,0,"JogViewModel");
    qmlRegisterType<PositionViewModel>("PositionViewModel",1,0,"PositionViewModel");
    qmlRegisterType<RightViewModel>("RightViewModel",1,0,"RightViewModel");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/View/MainView.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
