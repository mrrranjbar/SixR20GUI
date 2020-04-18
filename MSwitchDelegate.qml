import QtQuick 2.9
import QtQuick.Controls 2.2

Item {
     property string _label: "Joint"
    property int _width: 100
    property int _height: 50
    width: _width
    height: _height
    Switch {
        id: control
        text: qsTr("Switch")

        indicator: Rectangle {
            implicitWidth: 48
            implicitHeight: 26
            x: control.leftPadding
            y: parent.height / 2 - height / 2
            radius: 13
            color: control.checked ? "#046380" : "#ffffff"
            border.color: control.checked ? "#046380" : "#cccccc"

            Rectangle {
                x: control.checked ? parent.width - width : 0
                width: 26
                height: 26
                radius: 13
                color: control.down ? "#cccccc" : "#ffffff"
                border.color: control.checked ? (control.down ? "#046380" : "#EFECCA") : "#999999"
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
