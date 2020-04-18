import QtQuick 2.7
import QtQuick.Controls 2.2

Item {

    property string _text: qsTr("CheckBox")
    property int _width: parent.width
    property int _height: parent.height
    property int _implicitWidth: 26
    property int _implicitHeight: 26
    property int _recWidth: 14
    property int _recHeight: 14
    property int _recX: 6
    property int _recY: 6

    CheckBox {
        id: control
        text: _text
        checked: true
        width: _width
        height: _height


        indicator: Rectangle {
            implicitWidth: _implicitWidth
            implicitHeight: _implicitHeight
            x: control.leftPadding
            y: parent.height / 2 - height / 2
            radius: 3
            border.color: control.down ? "#046380" : "#EFECCA"

            Rectangle {
                width: _recWidth
                height: _recHeight
                x: _recX
                y: _recY
                radius: 2
                color: control.down ? "#046380" : "#EFECCA"
                visible: control.checked
            }
        }

        contentItem: Text {
            text: control.text
            font: control.font
            opacity: enabled ? 1.0 : 0.3
            color: control.down ? "#046380" : "#EFECCA"
            verticalAlignment: Text.AlignVCenter
            leftPadding: control.indicator.width + control.spacing
        }
    }
}
