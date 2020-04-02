import QtQuick 2.9
import QtQuick.Controls 2.2
//import InterpreterViewModel 1.0
ApplicationWindow {
    id: window
    visible: true
    flags: Qt.FramelessWindowHint
//    width: 1024
//    height: 600
    width: splash.width
    height: splash.height
    title: qsTr("6R Robot")
    property string _title: "Home"
    property bool _autoMode: false
    property bool _programmingMode: false
    property bool _setting: false
    property bool _maintenance: false

    //    InterpreterViewModel {
    //        id: interpreterviewmodel
    //        onLineSelect: {
    //            textarea.select(start, end)
    //            //console.log("You chose: ", start, end)
    //            textarea.update()
    //        }
    //    }
    Resource
    {
        id:rsc
    }

    header: ToolBar
    {
        id: header
        visible:false
        background: Rectangle {
            implicitHeight: 40
            color: "#eeeeee"

            Rectangle {
                width: parent.width
                height: 1
                anchors.bottom: parent.bottom
                color: "transparent"
                border.color: "#21be2b"

            }
        }
        Label{
            anchors.fill: parent
            text: " <b>" +_title+"</b>"
            color: "#21be2b"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }


    }
    Component.onCompleted: {
        automode._isActive = true
    }

    Grid{
        anchors.fill: parent
        columns: 2
        spacing: 5
        leftPadding: 5
        topPadding: 5
        Grid // left side
        {
            columns: 1
            spacing: 2
            id:leftside
            width: parent.width * 3/20
            height: parent.height

            MButton {
                id : automode
                _text: "Home"
                _width:parent.width
                //horizontalCenter: parent.horizontalCenter
                onBtnClick: {
                    stackView.pop()
                    stackView.push("MainViewForm.ui.qml")
                    _title = "Home"
                    automode._isActive=true
                    programmingmode._isActive = false
                    teach._isActive = false
                    interpreter._isActive = false
                    setting._isActive = false
                    iOMonitoring._isActive = false
                    velocityAcceleration._isActive = false
                    maintenance._isActive = false
                    ioHandling._isActive = false
                    servoParameters._isActive = false
                    scope._isActive = false
                    breaks._isActive=false
                }

            }
            MButton {
                id : programmingmode
                _text: "Program"
                anchors.top : (_autoMode) ? dryrun.bottom : automode.bottom
                anchors.margins: 2
                _width: parent.width
                onBtnClick: {
                    _programmingMode = !_programmingMode
                    _autoMode = false
                    _setting = false
                    _maintenance = false
                    //                               stackView.pop()
                    //                               stackView.push("JogViewForm.ui.qml")
                    _title = "Programming Mode"
                    automode._isActive=false
                    programmingmode._isActive = true
                    teach._isActive = false
                    interpreter._isActive = false
                    setting._isActive = false
                    iOMonitoring._isActive = false
                    velocityAcceleration._isActive = false
                    maintenance._isActive = false
                    ioHandling._isActive = false
                    servoParameters._isActive = false
                    scope._isActive = false
                    breaks._isActive=false
                }
            }
            MButton {
                id : teach
                _text: "Teach"
                _width:parent.width * 2/3
                anchors.top : programmingmode.bottom
                visible: _programmingMode
                anchors.margins: 2
                anchors.horizontalCenter: parent.horizontalCenter
                onBtnClick: {
                    _programmingMode != _programmingMode
                    _autoMode = false
                    stackView.pop()
                    stackView.push("TeachViewForm.ui.qml")
                    //stackView.push(InterpreterViewModel)
                    _title = "Teach"
                    automode._isActive=false
                    programmingmode._isActive = false
                    teach._isActive = true
                    interpreter._isActive = false
                    setting._isActive = false
                    iOMonitoring._isActive = false
                    velocityAcceleration._isActive = false
                    maintenance._isActive = false
                    ioHandling._isActive = false
                    servoParameters._isActive = false
                    scope._isActive = false
                    breaks._isActive=false
                }
            }
            MButton {
                id : interpreter
                _text: "Editor"
                _width:parent.width * 2/3
                visible: _programmingMode
                anchors.top : teach.bottom
                anchors.margins: 2
                anchors.horizontalCenter: parent.horizontalCenter
                onBtnClick: {
                    _programmingMode != _programmingMode
                    _autoMode = false
                    stackView.pop()
                    stackView.push("CodeEditorWindow.qml")
                    //stackView.push("InterpreterViewForm.ui.qml")
                    _title = "Programming Mode"
                    automode._isActive=false
                    programmingmode._isActive = false
                    teach._isActive = false
                    interpreter._isActive = true
                    setting._isActive = false
                    iOMonitoring._isActive = false
                    velocityAcceleration._isActive = false
                    maintenance._isActive = false
                    ioHandling._isActive = false
                    servoParameters._isActive = false
                    scope._isActive = false
                    breaks._isActive=false
                }
            }
            //*************************************
            // setting group buttons
            MButton {
                id : setting
                _text: "Setting"
                anchors.top : (_programmingMode) ? interpreter.bottom : programmingmode.bottom
                anchors.margins: 2
                _width: parent.width
                onBtnClick: {
                    _setting = !_setting
                    _autoMode = false
                    _programmingMode = false
                    _maintenance = false
                    //                               stackView.pop()
                    //                               stackView.push("TeachViewForm.ui.qml")
                    //                               //stackView.push("TeachPointViewForm.ui.qml")
                    _title = "Setting"
                    automode._isActive=false
                    programmingmode._isActive = false
                    teach._isActive = false
                    interpreter._isActive = false
                    setting._isActive = true
                    iOMonitoring._isActive = false
                    velocityAcceleration._isActive = false
                    maintenance._isActive = false
                    ioHandling._isActive = false
                    servoParameters._isActive = false
                    scope._isActive = false
                    breaks._isActive=false
                }
            }
            // setting sub buttons
            MButton {
                id : iOMonitoring
                _text: "IO/M"
                _width:parent.width * 2/3
                visible: _setting
                anchors.top : setting.bottom
                anchors.margins: 2
                anchors.horizontalCenter: parent.horizontalCenter
                onBtnClick: {
                    stackView.pop()
                    stackView.push("IOMonitoringViewForm.ui.qml")
                    _title = "IO Monitoring Mode"
                    automode._isActive=false
                    programmingmode._isActive = false
                    teach._isActive = false
                    interpreter._isActive = false
                    setting._isActive = false
                    iOMonitoring._isActive = true
                    velocityAcceleration._isActive = false
                    maintenance._isActive = false
                    ioHandling._isActive = false
                    servoParameters._isActive = false
                    scope._isActive = false
                    breaks._isActive=false
                }
            }
            MButton {
                id : velocityAcceleration
                _text: "Vel/Acc"
                _width:parent.width * 2/3
                visible: _setting
                anchors.top : iOMonitoring.bottom
                anchors.margins: 2
                anchors.horizontalCenter: parent.horizontalCenter
                onBtnClick: {
                    stackView.pop()
                    stackView.push("VelocityAccelerationViewForm.ui.qml")
                    _title = "Velocity Acceleration Mode"
                    automode._isActive=false
                    programmingmode._isActive = false
                    teach._isActive = false
                    interpreter._isActive = false
                    setting._isActive = false
                    iOMonitoring._isActive = false
                    velocityAcceleration._isActive = true
                    maintenance._isActive = false
                    ioHandling._isActive = false
                    servoParameters._isActive = false
                    scope._isActive = false
                    breaks._isActive=false
                }
            }
            // end of setting group button

            //*******************************************
            // maintenance GroupBox
            MButton {
                id  :maintenance
                anchors.top : (_setting) ? velocityAcceleration.bottom : setting.bottom
                _text: "Maintenance"
                _width: parent.width
                anchors.margins: 2
                //                           anchors.top : setting.bottom
                onBtnClick: {
                    _maintenance = !_maintenance
                    _autoMode = false
                    _programmingMode = false
                    _setting = false
                    //                               stackView.pop()
                    //                               stackView.push("ScoordinatesViewForm.ui.qml")
                    _title = "Maintenance"
                    automode._isActive=false
                    programmingmode._isActive = false
                    teach._isActive = false
                    interpreter._isActive = false
                    setting._isActive = false
                    iOMonitoring._isActive = false
                    velocityAcceleration._isActive = false
                    maintenance._isActive = true
                    ioHandling._isActive = false
                    servoParameters._isActive = false
                    scope._isActive = false
                    breaks._isActive=false

                }
            }
            MButton {
                id : ioHandling
                _text: "IO/H"
                _width:parent.width * 2/3
                visible: _maintenance
                anchors.top : maintenance.bottom
                anchors.margins: 2
                anchors.horizontalCenter: parent.horizontalCenter
                onBtnClick: {
                    stackView.pop()
                    stackView.push("IOHandlingViewForm.ui.qml")
                    _title = "IOHandling Mode"
                    automode._isActive=false
                    programmingmode._isActive = false
                    teach._isActive = false
                    interpreter._isActive = false
                    setting._isActive = false
                    iOMonitoring._isActive = false
                    velocityAcceleration._isActive = false
                    maintenance._isActive = false
                    ioHandling._isActive = true
                    servoParameters._isActive = false
                    scope._isActive = false
                    breaks._isActive=false
                }
            }
            MButton {
                id : servoParameters
                _text: "Servo Prm"
                _width:parent.width * 2/3
                visible: _maintenance
                anchors.top : ioHandling.bottom
                anchors.margins: 2
                anchors.horizontalCenter: parent.horizontalCenter
                onBtnClick: {
                    stackView.pop()
                    stackView.push("ServoParametersViewForm.ui.qml")
                    _title = "Servo Parameters Mode"
                    automode._isActive=false
                    programmingmode._isActive = false
                    teach._isActive = false
                    interpreter._isActive = false
                    setting._isActive = false
                    iOMonitoring._isActive = false
                    velocityAcceleration._isActive = false
                    maintenance._isActive = false
                    ioHandling._isActive = false
                    servoParameters._isActive = true
                    scope._isActive = false
                    breaks._isActive=false
                }
            }
            MButton {
                id : scope
                _text: "Scope"
                _width:parent.width * 2/3
                visible: _maintenance
                anchors.top : servoParameters.bottom
                anchors.margins: 2
                anchors.horizontalCenter: parent.horizontalCenter
                onBtnClick: {
                    stackView.pop()
                    stackView.push("ScopeViewForm.ui.qml")
                    _title = "Servo Parameters Mode"
                    automode._isActive=false
                    programmingmode._isActive = false
                    teach._isActive = false
                    interpreter._isActive = false
                    setting._isActive = false
                    iOMonitoring._isActive = false
                    velocityAcceleration._isActive = false
                    maintenance._isActive = false
                    ioHandling._isActive = false
                    servoParameters._isActive = false
                    scope._isActive = true
                    breaks._isActive=false
                }
            }
            MButton {
                id : breaks
                _text: "Break"
                _width:parent.width * 2/3
                visible: _maintenance
                anchors.top : scope.bottom
                anchors.margins: 2
                anchors.horizontalCenter: parent.horizontalCenter
                onBtnClick: {
                    stackView.pop()
                    stackView.push("BreakViewForm.ui.qml")
                    _title = "Breaks Mode"
                    automode._isActive=false
                    programmingmode._isActive = false
                    teach._isActive = false
                    interpreter._isActive = false
                    setting._isActive = false
                    iOMonitoring._isActive = false
                    velocityAcceleration._isActive = false
                    maintenance._isActive = false
                    ioHandling._isActive = false
                    servoParameters._isActive = false
                    scope._isActive = false
                    breaks._isActive=true
                }
            }
            Rectangle
            {
                width: parent.width * 2/3
                height: 100
                //anchors.bottom: leftside.bottom
                y:440
                anchors.left: scope.left
                Image{
                    anchors.fill: parent
                    fillMode: Image.PreserveAspectFit
                    source: "qrc:/icons/sixr_icon.png"
                }
            }

        }
        Grid  // right side
        {
            id :  right_side
            width: parent.width * 17/20
            height: parent.height
            columns: 1
            spacing: 5
            Grid{
                width: parent.width - 20
                height: parent.height * 0.85
                columns: 2
                spacing: 5
                StackView {
                    width: parent.width * 17/20
                    height: parent.height
                    id: stackView
                    initialItem: "MainViewForm.ui.qml"
                }
                StackView {
                    width: parent.width * 3/20
                    height: parent.height
                    initialItem: "RightViewForm.ui.qml"
                }
            }
            StackView {
                width: parent.width - 15
                height: parent.height * 0.15 - 20
                initialItem: "BottomViewForm.ui.qml"
            }
        }

    }

    Splash
    {
        id:splash
        x:0
        y:0
        onTimeout: {
            window.flags=Qt.Window
//            window.width=1024
//            window.height=600
//            setX(Screen.width / 2 - window.width / 2);
//            setY(Screen.height / 2 - window.height / 2);
//            window.visibility= "Maximized"
            window.visible=true
            header.visible=true
        }

    }


}
