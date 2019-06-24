import QtQuick 2.9
import QtQuick.Controls 2.2


ApplicationWindow {
    id: window
    visible: true
    width: 1024
    height: 600
    title: qsTr("6R Robot")
    property string _title: "Home Page"
    property bool _autoMode: false
    property bool _programmingMode: false
    property bool _setting: false
    property bool _maintenance: false

    Resource
    {
        id:rsc
    }

    header: ToolBar
    {
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
           width: parent.width * 3/20
           height: parent.height
           MButton {        
                           id : automode
                           _text: "Auto Mode"
                           _width:parent.width
                           //horizontalCenter: parent.horizontalCenter
                           onBtnClick: {
//                                stackView.pop()
//                               _title = "Auto Mode"
                               _autoMode = !_autoMode
                               _programmingMode = false
                               _setting = false
                               _maintenance = false
                           }
                       Component.onCompleted: {
                           }

           }
           MButton {
                           id : run
                           _text: "Run"
                           visible: _autoMode
                           _width:parent.width * 2/3
                           anchors.top : automode.bottom
                           anchors.margins: 2
                           anchors.horizontalCenter: parent.horizontalCenter
                           onBtnClick: {
                                stackView.pop()
                                stackView.push("RunViewForm.ui.qml")
                               _title = "Run Page"
                           }
                       }
           MButton {
                            id : dryrun
                           _text: "Dry Run"
                           visible: _autoMode
                           _width:parent.width * 2/3
                            anchors.top : run.bottom
                           anchors.margins: 2
                           anchors.horizontalCenter: parent.horizontalCenter
                           onBtnClick: {
                                stackView.pop()
                                stackView.push("DryRunViewForm.ui.qml")

                               _title = "Dry Run Page "
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
                                _title = "Teach"
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
                               stackView.push("InterpreterViewForm.ui.qml")
                                _title = "Programming Mode"
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
                           }
                       }
//           MButton {
//                           _text: "Interpreter"
//                           _width: parent.width
//                           onBtnClick: {
//                               stackView.pop()
//                               stackView.push("InterpreterViewForm.ui.qml")
//                                _title = "interpreter page"
//                           }
//                       }
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


}
