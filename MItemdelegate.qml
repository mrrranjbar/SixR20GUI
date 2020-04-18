import QtQuick 2.7
import QtQuick.Controls 2.2

Item {
    property string _text: "ItemDelegate"
    property int _width: 100
    property int _height: 40
    signal mClick()
    width: _width
    height: _height
    ItemDelegate {
        id: control
        text: qsTr(_text)
        height: _height
        width: _width
        contentItem: Text {
            rightPadding: control.spacing
            text: control.text
            font: control.font
            color: control.enabled ? (control.down ? "#046380" : "#EFECCA") : "#bdbebf"
            elide: Text.ElideRight
            verticalAlignment: Text.AlignVCenter
        }

        background: Rectangle {
            implicitWidth: _width
            implicitHeight: _height
            opacity: enabled ? 1 : 0.3
            color: control.down ? "#dddedf" : "#eeeeee"

            Rectangle {
                width: parent.width
                height: 1
                color: control.down ? "#046380" : "#EFECCA"
                anchors.bottom: parent.bottom
            }
        }
        onClicked: mClick()
    }

}
