#include <QGuiApplication>
//***************************
//#include <QApplication>
//***************************
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QtQuick/qquickitem.h>
#include <qqmlcontext.h>
#include <qqml.h>

#include <Model/ViewModel/mainviewmodel.h>
#include <Model/ViewModel/jogviewmodel.h>
#include <Model/ViewModel/positionviewmodel.h>
#include <Model/ViewModel/rightviewmodel.h>
#include <Model/ViewModel/interpreterviewmodel.h>
#include <Model/ViewModel/iohandlingviewmodel.h>
#include <Model/ViewModel/scopeviewmodel.h>
#include <Model/ViewModel/iomonitoringviewmodel.h>
#include <Model/ViewModel/teachpointviewmodel.h>
#include <Model/Controller/controller.h>
#include <Model/ViewModel/scoordinatesviewmodel.h>
#include <Model/ViewModel/bottomviewmodel.h>
#include <Model/ViewModel/customplotitem.h>
#include <Model/ViewModel/qcustomplot.h>
#include <QtQml>
#include <QtCharts>
#include <qqmlcontext.h>



int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

//  QtWebView::initialize();

    Controller *ctrl = Controller::getInstance();
    // Hokmabadi
    //QApplication app(argc, argv);
    // Hokmabadi

    //JogViewModel *jvm = new JogViewModel();
    //PositionViewModel *pm = new PositionViewModel();


    qmlRegisterType<MainViewModel>("MainViewModel",1,0,"MainViewModel");

    //******************************
    qmlRegisterType<InterpreterViewModel>("InterpreterViewModel",1,0,"InterpreterViewModel");
    //******************************
    qmlRegisterType<JogViewModel>("JogViewModel",1,0,"JogViewModel");
    qmlRegisterType<teachpointviewmodel>("Teachpointviewmodel",1,0,"Teachpointviewmodel");
    qmlRegisterType<PositionViewModel>("PositionViewModel",1,0,"PositionViewModel");
    qmlRegisterType<RightViewModel>("RightViewModel",1,0,"RightViewModel");

    //*******************************
    qmlRegisterType<iohandlingviewmodel>("IOHandlingViewModel",1,0,"IOHandlingViewModel");
    qmlRegisterType<iomonitoringviewmodel>("IOMonitoringViewModel",1,0,"IOMonitoringViewModel");
    qmlRegisterType<teachpointviewmodel>("TeachPointViewModel",1,0,"TeachPointViewModel");
    qmlRegisterType<scoordinatesviewmodel>("ScoordinatesViewModel",1,0,"ScoordinatesViewModel");
    qmlRegisterType<scopeviewmodel>("ScopeViewModel",1,0,"ScopeViewModel");
    qmlRegisterType<BottomViewModel>("BottomViewModel",1,0,"BottomViewModel");
    qmlRegisterType<CustomPlotItem>("CustomPlot", 1, 0, "CustomPlotItem");
    qmlRegisterType<QCustomPlot>("QCustomPlot", 1, 0, "QCustomPlot");
    //*******************************

//    QQmlEngine engine1;
//    QQmlComponent component(&engine1,
//                            QUrl::fromLocalFile("InterpreterViewForm.ui.qml"));
//    QObject *object = component.create();
//    QObject *textArea = object->findChild<QObject*>("textName");


    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/View/MainView.qml")));

    QQmlContext *ctxt = engine.rootContext();
    ctrl->ctxt = ctxt;
    ctrl->Initialize();
    ctrl->InitializePoints();
    ctrl->InitializeAlarm();
//    ctrl->InitializeChartPoints();
    //    teachpointviewmodel::init();
    // ctxt->setContextProperty("TeachPointModel", QVariant::fromValue(ctrl->dataList));


    if (engine.rootObjects().isEmpty())
        return -1;




    return app.exec();

}
