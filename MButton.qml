import QtQuick 2.7
import QtQuick.Controls 2.2


Item {
    property string _text: "my button"
    property bool _isActive: false
    property int _width: 100
    property int _height: 50
    property Rectangle _background: _backgroundRect

    signal btnClick()
    signal btnPress()
    signal btnReleased
//    Resource
//    {
//        id:rsc
//    }
    width: _width
    height: _height
    Button {
        id: control

        anchors {
                top: parent.top
                topMargin: -5
        }
        text: qsTr(_text)
        contentItem: Text {
            text: control.text
            font: control.font
            opacity: enabled ? 1.0 : 0.3
            //color: control.down ? "#046380" : "#EFECCA"
            color: _isActive ? "#046380" : "#EFECCA"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }

        background: Rectangle {
            id: _backgroundRect
            implicitWidth: _width
            implicitHeight: _height
            opacity: enabled ? 1 : 0.3
            //border.color: control.down ? "#046380" : "#EFECCA"
            //border.color: control.down ? "#A7A37E" : "#EFECCA"
            //color: _isActive ? "#C5E1A5" : "white"
            color: _isActive ? "#E6E2AF" : "#046380"
            //border.width: 1
            //radius: 2
        }
        onClicked: btnClick()
        onReleased: btnReleased()
        onPressed: btnPress()
    }
}
