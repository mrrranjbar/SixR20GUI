import QtQuick 2.7
import QtQuick.Controls 2.2


Item {
    property int _width: 255
    property int _height: 75
    property bool _joint: true

    property var _nameJoint: ["M1", "M2", "M3", "M4", "M5", "M6"]
    property var _valueJoint: ["1234.1234", "1234.1234", "1234.1234", "1234.1234", "1234.1234", "1234.1234"]


    property var _nameCartesian: ["X", "Y", "Z", "Ro", "Pi", "Ya"]
    property var _valueCartesian: ["25", "4544", "789", "12345", "453642", "4563456"]





//    teachpointviewmodel{
//        id:teachpointviewmodel
//    }


   Grid{ // main grid
       width: parent.width
       height: parent.height * 9/10
       columns: 2 // change it to 2
       spacing: 5
       Rectangle{
            width: parent.width /2
            height: parent.height
            color: "#fffff0"
            border.width: 5
            border.color: "#fff5ee"
           ListView {
               model: ListModel {
                   ListElement {
                       name: "Bill Smith"
                       number: "555 3264"
                   }
                   ListElement {
                       name: "John Brown"
                       number: "555 8426"
                   }
                   ListElement {
                       name: "Sam Wise"
                       number: "555 0473"
                   }
               }
               delegate: Text {
                   text: name + ": " + number
               }
           }
       }
   }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
