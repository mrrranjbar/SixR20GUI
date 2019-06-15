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
            text: "6R Robot"
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
           width: parent.width * 1/4
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
                           _text: "Programming Mode"
                           anchors.top : (_autoMode) ? dryrun.bottom : automode.bottom
                           anchors.margins: 2
                           _width: parent.width
                           onBtnClick: {
                               _programmingMode = !_programmingMode
                               _autoMode = false
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
                               stackView.push("TeachPointViewForm.ui.qml")
                                _title = "Teach Point"
                           }
                       }
           MButton {
                           id : interpreter
                           _text: "Interpreter"
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

           MButton {
                           id : setting
                           _text: "Setting"
                          anchors.top : (_programmingMode) ? interpreter.bottom : programmingmode.bottom
                          anchors.margins: 2
                          _width: parent.width
                           onBtnClick: {
                               stackView.pop()

                               stackView.push("TeachViewForm.ui.qml")
                               //stackView.push("TeachPointViewForm.ui.qml")
                               _title = "Setting"
                           }
                       }
           MButton {
                           id  :maintenance
                           _text: "Maintenance"
                           _width: parent.width
                         anchors.margins: 2
                           anchors.top : setting.bottom
                           onBtnClick: {
                               stackView.pop()


                               stackView.push("ScoordinatesViewForm.ui.qml")
                                _title = "ScoordinatesViewForm"

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
               width: parent.width * 3/4
               height: parent.height
               columns: 1
               spacing: 5
               MFrame{
                   width: parent.width - 15
                   height: parent.height * 0.1
                   Label{
                       width: parent.width
                       height: parent.height
                       text: " <b>" +_title+"</b>"
                       font.capitalization: Font.AllUppercase
                       color: "#21be2b"
                      verticalAlignment: Text.AlignVCenter
                      horizontalAlignment: Text.AlignHCenter
                   }
               }
                   Grid{
                       width: parent.width - 20
                       height: parent.height * 0.6
                       columns: 2
                       spacing: 5
                       StackView {
                           width: parent.width * 0.7
                           height: parent.height
                           id: stackView
                           initialItem: "MainViewForm.ui.qml"
                       }
                       StackView {
                           width: parent.width * 0.3
                           height: parent.height
                           initialItem: "RightViewForm.ui.qml"
                       }
                   }
               StackView {
                   width: parent.width - 15
                   height: parent.height * 0.3 - 20
                   initialItem: "BottomViewForm.ui.qml"
               }
           }

   }


}
