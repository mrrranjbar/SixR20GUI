
# Hokmabadi
#QT += qml quick core gui printsupport
#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
# Hokmabadi
QT += quick
QT += xml
QT+= widgets
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport
CONFIG += c++11




# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    Model/ViewModel/frame.cpp \
    Model/ViewModel/mainviewmodel.cpp \
    Model/ViewModel/jogviewmodel.cpp \
    Model/ViewModel/positionviewmodel.cpp \
    Model/ViewModel/teachviewmodel.cpp \
    Model/ViewModel/interpreterviewmodel.cpp \
    Model/ViewModel/rightviewmodel.cpp \
    Model/ViewModel/bottomviewmodel.cpp \
    Model/Controller/controller.cpp \
    Model/Robot/robot.cpp \
    Model/Controller/beckhoff.cpp \
    Model/Interpreter/SixRGrammerBaseListener.cpp \
    Model/Interpreter/SixRGrammerLexer.cpp \
    Model/Interpreter/SixRGrammerListener.cpp \
    Model/Interpreter/SixRGrammerParser.cpp \
    Model/ViewModel/antlrmain.cpp \
    Model/Interpreter/msixrlistener.cpp \
    Model/Interpreter/variable.cpp \
    Model/ViewModel/runviewmodel.cpp \
    Model/ViewModel/dryrunviewmodel.cpp \
    Model/ViewModel/teachpointviewmodel.cpp \
    Model/ViewModel/iomonitoringviewmodel.cpp \
    Model/ViewModel/velocityaccelerationviewmodel.cpp \
    Model/ViewModel/scoordinatesviewmodel.cpp \
    Model/ViewModel/iohandlingviewmodel.cpp \
    Model/ViewModel/servoparametersviewmodel.cpp \
    Model/ViewModel/scopeviewmodel.cpp \
    Model/Interpreter/parsetreelinewalker.cpp \
    Model/ViewModel/begininterpreter.cpp \
    Model/ViewModel/points.cpp \
    Model/ViewModel/alarm.cpp \
    Model/ViewModel/qcustomplot.cpp \
    Model/ViewModel/customplotitem.cpp \
    Model/Robot/TrajectoryPoint.cpp \
    Model/Robot/slerp.cpp \
    Model/Interpreter/subroutine.cpp \
    Model/Interpreter/interruptM.cpp


RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Model/ViewModel/frame.h \
    Model/ViewModel/mainviewmodel.h \
    Model/ViewModel/jogviewmodel.h \
    Model/ViewModel/positionviewmodel.h \
    Model/ViewModel/teachviewmodel.h \
    Model/ViewModel/interpreterviewmodel.h \
    Model/ViewModel/rightviewmodel.h \
    Model/ViewModel/bottomviewmodel.h \
    Model/Controller/controller.h \
    Model/Robot/robot.h \
    Model/Controller/beckhoff.h\
    Model/Interpreter/SixRGrammerBaseListener.h \
    Model/Interpreter/SixRGrammerLexer.h \
    Model/Interpreter/SixRGrammerListener.h \
    Model/Interpreter/SixRGrammerParser.h \
    Model/ViewModel/antlrmain.h \
    Model/Interpreter/msixrlistener.h \
    Model/Interpreter/variable.h \
    Model/ViewModel/runviewmodel.h \
    Model/ViewModel/dryrunviewmodel.h \
    Model/ViewModel/teachpointviewmodel.h \
    Model/ViewModel/iomonitoringviewmodel.h \
    Model/ViewModel/velocityaccelerationviewmodel.h \
    Model/ViewModel/scoordinatesviewmodel.h \
    Model/ViewModel/iohandlingviewmodel.h \
    Model/ViewModel/servoparametersviewmodel.h \
    Model/ViewModel/scopeviewmodel.h \
    Model/Interpreter/parsetreelinewalker.h \
    Model/ViewModel/begininterpreter.h \
    Model/ViewModel/points.h \
    Model/ViewModel/alarm.h \
    Model/ViewModel/qcustomplot.h \
    Model/ViewModel/customplotitem.h \
    Model/Robot/TrajectoryPoint.h \
    Model/Robot/slerp.h \
    Model/Interpreter/subroutine.h \
    Model/Interpreter/interruptM.h
    #ali*********************

    #ali*********************




LIBS+=/home/negin/Desktop/qt/SixR20GUI-master/AdsLib-Linux.a\
     /home/negin/Desktop/qt/SixR20GUI-master/Model/Interpreter/libantlr4-runtime.a

DISTFILES += \
    /home/negin/Desktop/qt/SixR20GUI-master/AdsLib-Linux.a \
    /home/negin/Desktop/qt/SixR20GUI-master/Model/Interpreter/libantlr4-runtime.a

#LIBS+=/home/ali/Documents/SixR20/SixR20_git/AdsLib-Linux.a\
#     /home/ali/Documents/SixR20/SixR20_git/Model/Interpreter/libantlr4-runtime.a

#DISTFILES += \
#    /home/ali/Documents/SixR20/SixR20_git/AdsLib-Linux.a \
#    /home/ali/Documents/SixR20/SixR20_git/Model/Interpreter/libantlr4-runtime.a


#LIBS+=/home/hossein/Files/qt_projects/SixR20GUI/AdsLib-Linux.a\
#     /home/hossein/Files/qt_projects/SixR20GUI/Model/Interpreter/libantlr4-runtime.a

#DISTFILES += \
#    /home/hossein/Files/qt_projects/SixR20GUI/AdsLib-Linux.a \
#    /home/hossein/Files/qt_projects/SixR20GUI/Model/Interpreter/libantlr4-runtime.a


#LIBS+=/home/hossein/Files/qt_projects/SixR20GUI/AdsLib-Linux.a\
#     /home/hossein/Files/qt_projects/SixR20GUI/Model/Interpreter/libantlr4-runtime.a

#DISTFILES += \
#    /home/hossein/Files/qt_projects/SixR20GUI/AdsLib-Linux.a \
#    /home/hossein/Files/qt_projects/SixR20GUI/Model/Interpreter/libantlr4-runtime.a



#DISTFILES += \
#    AdsLib-Linux.a \
#    Model/Interpreter/libantlr4-runtime.a

#LIBS+=/home/fumrobotics/Documents/QtProjects/SixR20_210298/SixR20_git210298/SixR20_git/AdsLib-Linux.a\
#     /home/fumrobotics/Documents/QtProjects/SixR20_210298/SixR20_git210298/SixR20_git/Model/Interpreter/libantlr4-runtime.a

#DISTFILES += \
#    /home/fumrobotics/Documents/QtProjects/SixR20_210298/SixR20_git210298/SixR20_git/AdsLib-Linux.a \
#    /home/fumrobotics/Documents/QtProjects/SixR20_210298/SixR20_git210298/SixR20_git/Model/Interpreter/libantlr4-runtime.a

##LIBS+=/home/behrooz/Desktop/SixR20_git150298/SixR20_git/AdsLib-Linux.a\
##     /home/behrooz/Desktop/SixR20_git150298/SixR20_git/Model/Interpreter/libantlr4-runtime.a

##DISTFILES += \
##    /home/behrooz/Desktop/SixR20_git150298/SixR20_git/AdsLib-Linux.a \
##    /home/behrooz/Desktop/SixR20_git150298/SixR20_git/Model/Interpreter/libantlr4-runtime.a
#LIBS+=/home/behrooz/Desktop/SixR20GUI_13980429/SixR20GUI/AdsLib-Linux.a\
#     /home/behrooz/Desktop/SixR20GUI_13980429/SixR20GUI/Model/Interpreter/libantlr4-runtime.a

#DISTFILES += \
#    /home/behrooz/Desktop/SixR20GUI_13980429/SixR20GUI/AdsLib-Linux.a \
#    /home/behrooz/Desktop/SixR20GUI_13980429/SixR20GUI/Model/Interpreter/libantlr4-runtime.a


INCLUDEPATH += Model/Interpreter/include/antlr4-runtime\
                /Model/Interpreter/include/antlr4-runtime/tree\
                #ali*****************
                /Model/Interpreter/include/antlr4-runtime/CommonTokenStream.h\
                /Model/Interpreter/include/antlr4-runtime/ANTLRInputStream.h

                #ali*****************

