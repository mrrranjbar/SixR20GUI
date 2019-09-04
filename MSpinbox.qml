import QtQuick 2.7
import QtQuick.Controls 2.2


Item {
    property int _width: 40
    property int _backwidth: 200
    property int _height: 40
    property real _value: 123.123

    width: _backwidth
    height: _height
    SpinBox {
        id: control
        value: _value
        editable: true

        contentItem: TextInput {
            z: 2
            text: control.textFromValue(control.value, control.locale)

            font: control.font
            color: "#21be2b"
            selectionColor: "#21be2b"
            selectedTextColor: "#ffffff"
            horizontalAlignment: Qt.AlignHCenter
            verticalAlignment: Qt.AlignVCenter

            readOnly: !control.editable
           // validator: control.validator
            validator : RegExpValidator { regExp : /[0-9]+\.[0-9]+/ }
            inputMethodHints: Qt.ImhFormattedNumbersOnly
        }

        up.indicator: Rectangle {
            x: control.mirrored ? 0 : parent.width - width
            height: parent.height
            implicitWidth: _width
            implicitHeight: _height
            color: control.up.pressed ? "#e4e4e4" : "#f6f6f6"
            border.color: enabled ? "#21be2b" : "#bdbebf"

            Text {
                text: "+"
                font.pixelSize: control.font.pixelSize * 2
                color: "#21be2b"
                anchors.fill: parent
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        down.indicator: Rectangle {
            x: control.mirrored ? parent.width - width : 0
            height: parent.height
            implicitWidth: _width
            implicitHeight: _height
            color: control.down.pressed ? "#e4e4e4" : "#f6f6f6"
            border.color: enabled ? "#21be2b" : "#bdbebf"

            Text {
                text: "-"
                font.pixelSize: control.font.pixelSize * 2
                color: "#21be2b"
                anchors.fill: parent
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }

        background: Rectangle {
            implicitWidth: _backwidth
            border.color: "#bdbebf"
        }
    }
}
