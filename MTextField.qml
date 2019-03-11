import QtQuick 2.7
import QtQuick.Controls 2.2

Item {
    property string _placeholderText: "e.g. 25320"
    property int _width: 100
    property int _height: 50
    property string _text: "0"
    signal textChanged()
    width: _width
    height: _height

    TextField {
        id: control
        placeholderText: qsTr(_placeholderText)

        background: Rectangle {
            implicitWidth: _width
            implicitHeight: _height
            color: control.enabled ? "transparent" : "#353637"
            //border.color: control.enabled ? "#21be2b" : "transparent"
            //radius: 2
        }
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: _text
        onTextChanged: textChanged()
    }

}
