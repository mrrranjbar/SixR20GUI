import QtQuick 2.4
import QtQuick.Controls 2.2
import MainViewModel 1.0
import RightViewModel 1.0

Item {
    property bool _joint: true
    //ffff
    property var _nameJoint: ["M1", "M2", "M3", "M4", "M5", "M6"]
    property var _nameCart: ["X", "Y", "Z", "Roll", "Pitch", "Yaw"]
    property color _firstC: "#17a81a" //"#00802b"
    property color _defaultTextC: "#bcf6bd" //"#00ff55"
    property var _colors: ["#004d00", "#17a81a", "#66ff66", "#E70000", "#FF8C00", "#FFEF00", "#00811F", "#0044FF", "#760089"]
    property var _nColors: ["#17a81a", "#bcf6bd"]
    //    property color secondC: "#24db33"
    Timer {
        id: _timer
        interval: 20
        running: true
        repeat: false
        onTriggered: {
            rightviewmodel.UpdatePosition(_joint)
            rightviewmodel.UpdateStatusWord()
        }
    }
    Grid // main grid
    {
        width: parent.width * 0.98
        height: parent.height
        rows: 4
        spacing: 5
        Switch {

            id: control
            text: control.checked ? qsTr("Cartesian") : qsTr("Joint")
            width: parent.width * 0.5
            height: parent.height * 0.1
            onClicked: _joint = !_joint
            indicator: Rectangle {
                implicitWidth: 48
                implicitHeight: 26
                x: control.leftPadding
                y: parent.height / 2 - height / 2
                radius: 13
                color: control.checked ? "#17a81a" : "#ffffff"
                border.color: control.checked ? "#17a81a" : "#cccccc"

                Rectangle {
                    x: control.checked ? parent.width - width : 0
                    width: 26
                    height: 26
                    radius: 13
                    color: control.down ? "#cccccc" : "#ffffff"
                    border.color: control.checked ? (control.down ? "#17a81a" : "#21be2b") : "#999999"
                }
            }

            contentItem: Text {
                text: control.text
                font: control.font
                opacity: enabled ? 1.0 : 0.3
                color: control.down ? "#17a81a" : "#21be2b"
                verticalAlignment: Text.AlignVCenter
                leftPadding: control.indicator.width + control.spacing
            }
        }

        Grid {
            //joint
            rows: 7
            width: parent.width * 0.98
            height: parent.height * 0.5
            spacing: 5
            visible: _joint
            Repeater {
                model: 6
                MFrame {
                    width: parent.width
                    height: (parent.height - 25) / 6.0
                    Grid {
                        anchors.horizontalCenter: parent.horizontalCenter
                        columns: 3
                        spacing: 0
                        height: parent.height
                        width: parent.width
                        Label {
                            width: parent.width / 2.0
                            height: parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            text: "<b>" + _nameJoint[index] + "</b>"
                            color: "#21be2b"
                        }
                        Label {
                            width: parent.width / 2.0
                            height: parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            text: "<b>" + rightviewmodel.ActualPosition[index].toFixed(
                                3) + "</b>"
                            color: "#21be2b"
                        }
                    }
                }
            }
        }

        Grid {
            //carthesian
            rows: 7
            width: parent.width * 0.98
            height: parent.height * 0.5
            spacing: 5
            visible: !_joint
            Repeater {
                model: 6
                MFrame {
                    width: parent.width
                    height: (parent.height - 25) / 6.0
                    Grid {
                        anchors.horizontalCenter: parent.horizontalCenter
                        columns: 3
                        spacing: 0
                        height: parent.height
                        width: parent.width
                        Label {
                            width: parent.width / 2.0
                            height: parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            text: "<b>" + _nameCart[index] + "</b>"
                            color: "#21be2b"
                        }
                        Label {
                            width: parent.width / 2.0
                            height: parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            text: "<b>" + rightviewmodel.ActualPosition[index].toFixed(
                                3) + "</b>"
                            color: "#21be2b"
                        }
                    }
                }
            }
        }

        MFrame {
            //Status
            width: parent.width
            height: parent.height * 0.1
            Grid {
                rows: 3
                spacing: 5
                width: parent.width * 0.98
                height: parent.height
                Label {
                    width: parent.width
                    height: parent.height / 2
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "<b>" + "Status" + "</b>"
                    color: "#21be2b"
                }
                Label {
                    width: parent.width
                    height: parent.height / 2
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "<b>" + "AXA" + "</b>"
                    color: "#21be2b"
                }
            }
        }
    }

    RightViewModel {
        id: rightviewmodel
    }
}




/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/

