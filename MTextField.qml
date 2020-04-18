import QtQuick 2.7
import QtQuick.Controls 2.2

Item {
    property string _placeholderText: "e.g. 25320"
    property int _width: 100
    property int _height: 50
    property string _text: "0"
    property  TextInput textInput: mTextField1
   // signal textChanged()
    width: _width
    height: _height

//    TextInput {
//        id: control
////        placeholderText: qsTr(_placeholderText)

////        background: Rectangle {
////            implicitWidth: _width
////            implicitHeight: _height
////            color: control.enabled ? "transparent" : "#353637"
////            //border.color: control.enabled ? "#EFECCA" : "transparent"
////            //radius: 2
////        }
////        horizontalAlignment: Text.AlignHCenter
////        verticalAlignment: Text.AlignVCenter

//        //onTextChanged: textChanged()
////        onReleased: {
////            text: _text
////        }
//    }
    TextInput {
         id: mTextField1
         width: _width
         height:_height
         horizontalAlignment: Text.AlignHCenter
         verticalAlignment: Text.AlignVCenter
         color: "#EFECCA"
         text: _text
         onTextChanged: _text = mTextField1.text

     }

}
