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
#include <Model/ViewModel/iohandlingviewmodel.h>
#include <Model/ViewModel/scopeviewmodel.h>
#include <Model/ViewModel/iomonitoringviewmodel.h>
#include <Model/ViewModel/teachpointviewmodel.h>
#include <Model/Controller/controller.h>
#include <Model/ViewModel/scoordinatesviewmodel.h>
#include <Model/ViewModel/bottomviewmodel.h>
#include <Model/ViewModel/servoparametersviewmodel.h>
#include <Model/ViewModel/velocityaccelerationviewmodel.h>
#include <Model/ViewModel/breakviewmodel.h>
#include <Model/ViewModel/customplotitem.h>
#include <Model/ViewModel/qcustomplot.h>
#include <QtQml>
#include <QtCharts>
#include <qqmlcontext.h>
#include "Model/ViewModel/linenumbers.h"
#include "Model/ViewModel/codeeditorbackend.h"

#include <QQmlApplicationEngine>
#include "Model/ViewModel/comboboxmodel.h"
#include "Model/ViewModel/fileio.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);


    Controller *ctrl = Controller::getInstance();

    QQmlApplicationEngine engine;
    ComboBoxModel combo;

    QStringList tmp;
    tmp << "1wer" << "jjuy2ju" << "mm3mm" << "4" << "5" << "6" << "7";
    combo.setComboList(tmp);

    QQmlContext *ownContext = engine.rootContext();
    ownContext->setContextProperty("myTeachPointModel", QVariant::fromValue(combo.comboList()));
    ownContext->setContextProperty("myTeachFrameModel", QVariant::fromValue(combo.comboList()));


//    QQmlContext *classContext = engine.rootContext();
//    classContext->setContextProperty("comboModel", &combo);
    qmlRegisterType<LineNumbers>("CodeEditor", 1, 0, "LineNumbers");
    qmlRegisterType<CodeEditorBackend>("CodeEditor", 1, 0, "CodeEditorBackend");
    qmlRegisterType<FileIO>("CodeEditorWindow", 1, 0, "FileIO");
    qmlRegisterType<FileIO>("CodeWindow", 1, 0, "FileIO");
    qmlRegisterType<MainViewModel>("MainViewModel",1,0,"MainViewModel");


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
    qmlRegisterType<VelocityAccelerationViewModel>("VelocityAccelerationViewModel",1,0,"VelocityAccelerationViewModel");
    qmlRegisterType<ServoPRMViewModel>("ServoPRMViewModel",1,0,"ServoPRMViewModel");
    qmlRegisterType<breakviewmodel>("BreakViewModel",1,0,"BreakViewModel");
    qmlRegisterType<CustomPlotItem>("CustomPlot", 1, 0, "CustomPlotItem");
    qmlRegisterType<QCustomPlot>("QCustomPlot", 1, 0, "QCustomPlot");
    //*******************************
    teachpointviewmodel techpoint;

    QObject *topLevel = engine.rootObjects().value(0);
    QQuickWindow *Item = qobject_cast<QQuickWindow *>(topLevel);

    QObject::connect(&techpoint, SIGNAL(openPopUp(QVariant)),
                     Item, SLOT(openPopUp(QVariant)));

    //QQmlApplicationEngine engine;
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
