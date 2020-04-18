import QtQuick 2.7
import QtQuick.Controls 2.2

Item {
    property string _text: "label"
    Label {
        text: qsTr(_text)
        color: "#EFECCA"
    }

}
