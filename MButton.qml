import QtQuick 2.7
import QtQuick.Controls 2.2


Item {
    property string _text: "my button"
    property int _width: 100
    property int _height: 50

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
            color: control.down ? "#17a81a" : "#21be2b"
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            elide: Text.ElideRight
        }

        background: Rectangle {
            implicitWidth: _width
            implicitHeight: _height
            opacity: enabled ? 1 : 0.3
            border.color: control.down ? "#17a81a" : "#21be2b"
            border.width: 1
            radius: 2
        }
        onClicked: btnClick()
        onReleased: btnReleased()
        onPressed: btnPress()
    }
}
