import QtQuick 2.4
import QtQuick.Controls 2.2
import MainViewModel 1.0
import BottomViewModel 1.0
import QtQuick.Window 2.2

Item {
    BottomViewModel {
        id: bottomViewModel
    }
    MFrame {
        anchors.fill: parent
        id: frame
        Grid {

            width: parent.width
            height: parent.height * 9 / 10
            anchors.centerIn: frame
            columns: 3
            spacing: 5
            //            padding :(parent.width - label.width -showDetails.width - clear.width)/2
            Label {
                id: label
                width: parent.width * 0.5
                height: parent.height
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: "<b>" + bottomViewModel.labelText + "</b>"
                color: bottomViewModel.labelColor
            }

            MButton {
                id: showDetails
                //                anchors.left: label.right
                _width: parent.width * 0.25
                _height: parent.height
                //visible: (bottomViewModel.labelText == "Robot is READY!") ? false : true
                _text: "Show Details Alarm"
                Connections {
                    onBtnClick: {
                        popup.open()
                    }
                }

                Popup {

                    id: popup

                    //anchors.centerIn: frame
                    //                        x: Math.round((frame.width - width) / 4)
                    //                        y: Math.round((frame.height - height) / 4)
                    width: frame.width + 100
                    height: 400
                    modal: true
                    focus: true
                    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent
                    ScrollView {
                        width: parent.width
                        height: parent.height
                        //                                        clip: true
                        Row {
                            width: parent.width
                            height: 25
                            id: topRow

                            Label {
                                height: parent.height
                                width: parent.width / 5
                                text: "<b>Motor Number</b>"
                            }
                            Label {
                                height: parent.height
                                width: parent.width / 5
                                text: "<b>Alarm Code</b"
                            }
                            Label {
                                height: parent.height
                                width: parent.width / 5
                                text: "<b>Name</b>"
                            }
                            Label {
                                height: parent.height
                                width: parent.width / 5
                                text: "<b>Detail</b>"
                            }
                            Label {
                                height: parent.height
                                width: parent.width / 5
                                text: "<b>What to check</b>"
                            }
                        }

                        MFrame {
                            //ListView
                            width: parent.width
                            height: parent.height - topRow.height - 10
                            anchors.top: topRow.bottom

                            Row {
                                width: parent.width
                                height: parent.height

                                ListView {
                                    id: alarmList
                                    width: parent.width
                                    height: parent.height
                                    model: AlarmModel
                                    clip: true

                                    delegate: Row {
                                        property int indexOfThisDelegate: index
                                        id: itemView
                                        //                                        y: indexOfThisDelegate * itemView.height
                                        width: parent.width
                                        height: check.height
                                        //                                        anchors.bottom: ItemDelegate.childAt(indexOfThisDelegate - 1)
                                        Grid {
                                            width: parent.width
                                            height: parent.height
                                            columns: 5

                                            Label {

                                                height: parent.height
                                                width: parent.width / 5
                                                text: model.motorNum
                                            }

                                            Label {

                                                height: parent.height
                                                width: parent.width / 5
                                                text: model.key
                                            }
                                            Label {
                                                height: parent.height
                                                width: parent.width / 5
                                                text: model.name
                                            }
                                            Label {

                                                height: check.height
                                                width: parent.width / 5
                                                text: model.detail
                                            }
                                            Label {
                                                id: check
                                                height: model.check.length / 20 * 10 + 40
                                                width: parent.width / 5
                                                text: model.check
                                                wrapMode: Text.WordWrap
                                            }
                                        }
                                    }
                                    //                                    highlightFollowsCurrentItem: true
                                    //                                    highlight: Rectangle
                                    //                                    {
                                    //                                        width: parent.width
                                    //                                        color: "#7fff00"
                                    //                                    }

                                    //                                    focus: true
                                }
                            }
                        }
                    }
                }
            }

            MButton {
                id: clear
                _width: parent.width * 0.25
                _height: parent.height
                //                anchors.left: showDetails.right
                //visible: (bottomViewModel.labelText == "Robot is READY!") ? false : true
                _text: "Clear Alarm"
                 onBtnClick: {
                        bottomViewModel.clearAll()
                    }
            }
        }
    }
}






/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/

