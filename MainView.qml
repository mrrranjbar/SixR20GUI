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
                           _text: "Auto Mode"
                           _width:parent.width
                           //horizontalCenter: parent.horizontalCenter
                           onBtnClick: {
//                                stackView.pop()
//                               _title = "Auto Mode"
                               _autoMode = !_autoMode
                           }
                       }
           MButton {
                           _text: "Run"
                            visible: _autoMode
                            //anchors.horizontalCenter: parent.horizontalCenter
                           _width:parent.width * 2/3
                           onBtnClick: {
                                stackView.pop()
                               stackView.push("InterpreterViewForm.ui.qml")

                               _title = "Run Page"
                           }
                       }
           MButton {
                           _text: "Dry Run"
                           visible: _autoMode
                           //anchors.horizontalCenter : parent.horizontalCenter
                           _width:parent.width * 2/3
                           onBtnClick: {
                                stackView.pop()
                               stackView.push("Web2Form.ui.qml")
                               _title = "Dry Run Page "
                           }
                       }
           MButton {
                           _text: "Programming Mode"
                           _width: parent.width
                           onBtnClick: {
                               stackView.pop()
                               stackView.push("IOMonitoringViewForm.ui.qml")
                                _title = "IO Monitoring"



                           }
                       }
           MButton {
                           _text: "Setting"
                           _width: parent.width
                           onBtnClick: {
                               stackView.pop()
                               stackView.push("TeachViewForm.ui.qml")
                                _title = "Setting"
                           }
                       }
           MButton {
                           _text: "Maintenance"
                           _width: parent.width//IOHandlingViewForm.ui.qml
                           onBtnClick: {
                               stackView.pop()
                               stackView.push("IOHandlingViewForm.ui.qml")
                                _title = "IO Handling"
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
