import QtQuick 2.9
import QtQuick.Controls 2.2
import MainViewModel 1.0
import RightViewModel 1.0

Item {
    id: rightview
    property bool _joint: true
    property int _frame: 0
    property var _nameJoint: ["M1", "M2", "M3", "M4", "M5", "M6"]
    property var _nameCart: ["X", "Y", "Z", "Roll", "Pitch", "Yaw"]
    property color _firstC: "#17a81a" //"#00802b"
    property color _defaultTextC: "#bcf6bd" //"#00ff55"
    property var _colors: ["#004d00", "#17a81a", "#66ff66", "#E70000", "#FF8C00", "#FFEF00", "#00811F", "#0044FF", "#760089"]
    property var _nColors: ["#17a81a", "#bcf6bd"]
    //    property color secondC: "#24db33"
    Timer {
        interval: 20
        running: true
        repeat: true
        onTriggered: {
           // rightviewmodel.UpdatePosition(_joint, cmb_frame.currentIndex)
            rightviewmodel.UpdateActualPosition(_joint, cmb_frame.currentIndex)
            rightviewmodel.UpdateStatusWord()
        }
    }
    Grid // main grid
    {
        id: maingrid
        width: parent.width * 0.98
        height: parent.height
        rows: 5
        spacing: 5

        Switch {
            id: control
            text: control.checked ? qsTr("Cartesian") : qsTr("Joint")
            width: parent.width * 0.5
            height: parent.height * 0.07
            onClicked: _joint = !_joint
            indicator: Rectangle {
                implicitWidth: 48
                implicitHeight: 26
                x: control.leftPadding
                y: parent.height / 2 - height / 2
                radius: 13
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
            spacing: 2
            visible: _joint
            Repeater {
                model: 6
                MFrame {
                    width: parent.width
                    height: (parent.height - 50) / 6.0
                    Grid {
                        anchors.horizontalCenter: parent.horizontalCenter
                        columns: 3
                        spacing: 1
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
                            text: "<b>" + rightviewmodel.ActualPosition[index].toFixed(3) + "</b>"
                            color: "#21be2b"
                        }
                    }
                }
            }
        }

        Grid {
            //carthesian
            id: cartGrid
            rows: 8
            width: parent.width * 0.98
            height: parent.height * 0.5
            spacing: 2
            visible: !_joint
            ////////////////////////////////
            ComboBox {
                id: cmb_frame
                height: (parent.height) / 5
                width: parent.width
                currentIndex: 0
                model: ["object", "task", /*"tool",*/ "world", "base"]

                delegate: ItemDelegate {
                    width: cmb_frame.width
                    contentItem: Text {
                        text: modelData
                        color: "#21be2b"
                        font: cmb_frame.font
                        elide: Text.ElideRight
                        verticalAlignment: Text.AlignVCenter
                    }
                    highlighted: cmb_frame.highlightedIndex === index
                }

                indicator: Canvas {
                    id: canvas_frame
                    x: cmb_frame.width - width - cmb_frame.rightPadding
                    y: cmb_frame.topPadding + (cmb_frame.availableHeight - height) / 2
                    width: 12
                    height: 8
                    contextType: "2d"

                    Connections {
                        target: cmb_frame
                        onPressedChanged: {
                            canvas_frame.requestPaint()
                        }
                    }

                    onPaint: {
                        context.reset()
                        context.moveTo(0, 0)
                        context.lineTo(width, 0)
                        context.lineTo(width / 2, height)
                        context.closePath()
                        context.fillStyle = cmb_frame.pressed ? "#17a81a" : "#21be2b"
                        context.fill()
                    }
                }

                contentItem: Text {
                    leftPadding: 10
                    rightPadding: cmb_frame.indicator.width + cmb_frame.spacing

                    text: cmb_frame.displayText
                    font: cmb_frame.font
                    color: cmb_frame.pressed ? "#17a81a" : "#21be2b"
                    verticalAlignment: Text.AlignVCenter
                    elide: Text.ElideRight
                }

                background: Rectangle {
                    implicitWidth: 120
                    implicitHeight: 40
                    border.color: cmb_frame.pressed ? "#17a81a" : "#21be2b"
                    border.width: cmb_frame.visualFocus ? 2 : 1
                    radius: 2
                }

                popup: Popup {
                    y: cmb_frame.height - 1
                    width: cmb_frame.width
                    implicitHeight: contentItem.implicitHeight
                    padding: 1

                    contentItem: ListView {
                        clip: true
                        implicitHeight: contentHeight
                        model: cmb_frame.popup.visible ? cmb_frame.delegateModel : null
                        currentIndex: cmb_frame.highlightedIndex

                        ScrollIndicator.vertical: ScrollIndicator {
                        }
                    }

                    background: Rectangle {
                        border.color: "#21be2b"
                        radius: 5
                    }
                }

                onCurrentIndexChanged: {
                    _frame: currentIndex
                    console.log(currentIndex)

                    //change frame
                }
            }

            ///////////////////////////////////////
            Repeater {
                model: 6
                MFrame {
                    width: parent.width
                    height: (parent.height) / 8.0
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
            id: frame
            width: parent.width
            height: parent.height * 0.41
            Grid {
                anchors.top: parent.top
                rows: 4
                spacing: 5
                width: parent.width
                height: parent.height
                anchors.topMargin: 0 // * 0.7
                horizontalItemAlignment: Grid.AlignHCenter
                verticalItemAlignment: Grid.AlignVCenter
                Label {
                    width: parent.width
                    height: parent.height / 15
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "<b>" + rightviewmodel.StatusWordStr + "</b>"
                    color: "#21be2b"
                }
                //                Label {
                //                    width: parent.width
                //                    height: parent.height / 15
                //                    horizontalAlignment: Text.AlignHCenter
                //                    verticalAlignment: Text.AlignVCenter
                //                    text: "<b>" + rightviewmodel.StatusWord + "</b>"
                //                    color: "#21be2b"
                //                }
                MButton {
                    id: bu
                    _text: "More"
                    _height: parent.height / 15
                    _width: parent.width //2
                    Connections {
                        onBtnClick: {
                            bu.visible = false
                            lu.visible = true
                            details.visible = true
                        }
                    }
                }
                MButton {
                    id: lu
                    _text: "Less"
                    visible: false
                    _height: parent.height / 15
                    _width: parent.width //2
                    Connections {
                        onBtnClick: {
                            lu.visible = false
                            bu.visible = true
                            details.visible = false
                        }
                    }
                }

                Grid {
                    topPadding: 15
                    height: parent.height * 0.8
                    width: parent.width
                    id: details
                    rows: 7
                    spacing: 5
                    visible: false
                    horizontalItemAlignment: Grid.AlignHCenter
                    verticalItemAlignment: Grid.AlignVCenter
//                    anchors.left: frame.left
                    Repeater {
                        model: 6
                        Label {
                            width: parent.width
                            height: parent.height / 10
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            text: "<b>" + rightviewmodel.StatusWord[index] + "</b>"
                            font.pixelSize: 10
                            color: "#21be2b"
                        }
                    }
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
