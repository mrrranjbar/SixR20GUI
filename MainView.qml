import QtQuick 2.9
import QtQuick.Controls 2.2



ApplicationWindow {
    id: window
    visible: true
    width: 1024
    height: 600
    title: qsTr("6R Robot")
    property string _title: "Home Page"


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
                           _text: "Home"
                           _width:parent.width
                           onBtnClick: {
                                stackView.pop()
                               _title = "home page"
                           }
                       }
           MButton {
                           _text: "Jog"
                           _width: parent.width
                           onBtnClick: {
                               stackView.pop()
                               stackView.push("JogViewForm.ui.qml")
                                _title = "jog page"

                           }
                       }
           MButton {
                           _text: "Position"
                           _width: parent.width
                           onBtnClick: {
                               stackView.pop()
                               stackView.push("PositionViewForm.ui.qml")
                                _title = "position page"
                           }
                       }
           MButton {
                           _text: "Teach"
                           _width: parent.width
                           onBtnClick: {
                               stackView.pop()
                               stackView.push("TeachViewForm.ui.qml")
                                _title = "teach page"
                           }
                       }
           MButton {
                           _text: "Interpreter"
                           _width: parent.width
                           onBtnClick: {
                               stackView.pop()
                               stackView.push("InterpreterViewForm.ui.qml")
                                _title = "interpreter page"
                           }
                       }
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
