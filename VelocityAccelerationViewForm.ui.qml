import QtQuick 2.12
import QtQuick.Controls 2.12

Item {
    property string _title: "Velocity page"
    Grid {
        width: parent.width
        height: parent.height
        spacing: 2
        rows: 3
        MFrame {
            width: parent.width
            height: parent.height * 0.2
            Grid {
                width: parent.width
                height: parent.height
                columns: 2
                spacing: 2
                Grid {
                    width: parent.width / 2
                    height: parent.height
                    rows: 4
                    spacing: 2
                    Label {
                        color: '#17a81a'
                        width: parent.width
                        height: parent.height / 4
                        text: "Linear Cartesian"
                        horizontalAlignment: Text.AlignHCenter
                    }
                    Grid {
                        width: parent.width
                        height: parent.height / 4
                        columns: 5
                        Label {
                            horizontalAlignment: Text.AlignHCenter
                            width: parent.width/2
                            color: '#17a81a'
                            text: "Velocity"
                        }
                        TextEdit {
                            horizontalAlignment: Text.AlignHCenter
                            width: parent.width/2
                            color: "#17a81a"
                            text: "5020"
                        }
                    }
                    Grid {
                        width: parent.width
                        height: parent.height / 4
                        //anchors.horizontalCenter: parent.horizontalCenter
                        columns: 2
                        Label {
                            horizontalAlignment: Text.AlignHCenter
                            width: parent.width/2
                            color: '#17a81a'
                            text: "Acceleration"
                        }
                        TextEdit {
                            horizontalAlignment: Text.AlignHCenter
                            width: parent.width/2
                            color: '#17a81a'
                            text: "500"
                        }
                    }
                    Grid {
                        width: parent.width
                        height: parent.height / 4
                        //anchors.horizontalCenter: parent.horizontalCenter
                        columns: 2
                        Label {
                            horizontalAlignment: Text.AlignHCenter
                            width: parent.width/2
                            color: '#17a81a'
                            text: "Declaration"
                        }
                        TextEdit {
                            horizontalAlignment: Text.AlignHCenter
                            width: parent.width/2
                            color: '#17a81a'
                            text: "500"
                        }
                    }
                }
                Grid {
                    width: parent.width / 2
                    height: parent.height
                    rows: 4
                    spacing: 2
                    Label {
                        color: '#17a81a'
                        width: parent.width
                        height: parent.height / 4
                        horizontalAlignment: Text.AlignHCenter
                        text: "Angular Cartesian"
                    }
                    Grid {
                        width: parent.width
                        height: parent.height / 4
                        columns: 2
                        Label {
                            horizontalAlignment: Text.AlignHCenter
                            width: parent.width/2
                            color: '#17a81a'
                            text: "Velocity"
                        }
                        TextEdit {
                            horizontalAlignment: Text.AlignHCenter
                            width: parent.width/2
                            color: '#17a81a'
                            text: "510"
                        }
                    }
                    Grid {
                        width: parent.width
                        height: parent.height / 4
                        columns: 2
                        Label {
                            horizontalAlignment: Text.AlignHCenter
                            width: parent.width/2
                            color: '#17a81a'
                            text: "Acceleration"
                        }
                        TextEdit {
                            horizontalAlignment: Text.AlignHCenter
                            width: parent.width/2
                            color: '#17a81a'
                            text: "500"
                        }
                    }
                    Grid {
                        width: parent.width
                        height: parent.height / 4
                        columns: 2
                        Label {
                            horizontalAlignment: Text.AlignHCenter
                            width: parent.width/2
                            color: '#17a81a'
                            text: "Declaration"
                        }
                        TextEdit {
                            horizontalAlignment: Text.AlignHCenter
                            width: parent.width/2
                            color: '#17a81a'
                            text: "500"
                        }
                    }
                }
            }
        }
        MFrame {
            width: parent.width
            height: parent.height * 0.6
            Grid {
                width: parent.width
                height: parent.height
                rows: 2
                spacing: 2
                Label {
                    horizontalAlignment: Text.AlignHCenter
                    color: '#17a81a'
                    width: parent.width
                    height: parent.height * 0.1
                    text: 'Joint'
                }
                Grid {
                    width: parent.width
                    height: parent.height * 0.9
                    columns: 3
                    spacing: 2
                    Grid {
                        width: parent.width / 3
                        height: parent.height //*0.3
                        rows: 7
                        spacing: 2
                        Label {
                            color: '#17a81a'
                            width: parent.width
                            height: parent.height / 7
                            text: 'Velocity'
                            horizontalAlignment: Text.horizontalAlignment
                        }
                        Grid {
                            width: parent.width / 2
                            height: parent.height / 7
                            columns: 2
                            spacing: 2
                            Label {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: 'M1'
                            }
                            TextEdit {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: '100'
                            }
                        }
                        Grid {
                            width: parent.width / 2
                            height: parent.height / 7
                            columns: 2
                            spacing: 2
                            Label {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: 'M2'
                            }
                            TextEdit {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: '100'
                            }
                        }
                        Grid {
                            width: parent.width / 2
                            height: parent.height / 7
                            columns: 2
                            spacing: 2
                            Label {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: 'M3'
                            }
                            TextEdit {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: '100'
                            }
                        }
                        Grid {
                            width: parent.width / 2
                            height: parent.height / 7
                            columns: 2
                            spacing: 2
                            Label {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: 'M4'
                            }
                            TextEdit {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: '100'
                            }
                        }
                        Grid {
                            width: parent.width / 2
                            height: parent.height / 7
                            columns: 2
                            spacing: 2
                            Label {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: 'M5'
                            }
                            TextEdit {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: '100'
                            }
                        }
                        Grid {
                            width: parent.width / 2
                            height: parent.height / 7
                            columns: 2
                            spacing: 2
                            Label {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: 'M6'
                            }
                            TextEdit {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: '100'
                            }
                        }
                    }
                    Grid {
                        width: parent.width / 3
                        height: parent.height //*0.3
                        rows: 7
                        spacing: 2
                        Label {
                            color: '#17a81a'
                            width: parent.width
                            height: parent.height / 7
                            horizontalAlignment: Text.horizontalAlignment
                            text: 'Acceleration'
                        }
                        Grid {
                            width: parent.width / 2
                            height: parent.height / 7
                            columns: 2
                            spacing: 2
                            Label {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: 'M1'
                            }
                            TextEdit {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: '100'
                            }
                        }
                        Grid {
                            width: parent.width / 2
                            height: parent.height / 7
                            columns: 2
                            spacing: 2
                            Label {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: 'M2'
                            }
                            TextEdit {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: '100'
                            }
                        }
                        Grid {
                            width: parent.width / 2
                            height: parent.height / 7
                            columns: 2
                            spacing: 2
                            Label {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: 'M3'
                            }
                            TextEdit {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: '100'
                            }
                        }
                        Grid {
                            width: parent.width / 2
                            height: parent.height / 7
                            columns: 2
                            spacing: 2
                            Label {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: 'M4'
                            }
                            TextEdit {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: '100'
                            }
                        }
                        Grid {
                            width: parent.width / 2
                            height: parent.height / 7
                            columns: 2
                            spacing: 2
                            Label {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: 'M5'
                            }
                            TextEdit {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: '100'
                            }
                        }
                        Grid {
                            width: parent.width / 2
                            height: parent.height / 7
                            columns: 2
                            spacing: 2
                            Label {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: 'M6'
                            }
                            TextEdit {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: '100'
                            }
                        }
                    }
                    Grid {
                        width: parent.width / 3
                        height: parent.height //*0.3
                        rows: 7
                        spacing: 2
                        Label {
                            horizontalAlignment: Text.horizontalAlignment
                            color: '#17a81a'
                            width: parent.width
                            height: parent.height / 7
                            text: 'Deceleration'
                        }
                        Grid {
                            width: parent.width / 2
                            height: parent.height / 7
                            columns: 2
                            spacing: 2
                            Label {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: 'M1'
                            }
                            TextEdit {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: '100'
                            }
                        }
                        Grid {
                            width: parent.width / 2
                            height: parent.height / 7
                            columns: 2
                            spacing: 2
                            Label {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: 'M2'
                            }
                            TextEdit {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: '100'
                            }
                        }
                        Grid {
                            width: parent.width / 2
                            height: parent.height / 7
                            columns: 2
                            spacing: 2
                            Label {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: 'M3'
                            }
                            TextEdit {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: '100'
                            }
                        }
                        Grid {
                            width: parent.width / 2
                            height: parent.height / 7
                            columns: 2
                            spacing: 2
                            Label {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: 'M4'
                            }
                            TextEdit {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: '100'
                            }
                        }
                        Grid {
                            width: parent.width / 2
                            height: parent.height / 7
                            columns: 2
                            spacing: 2
                            Label {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: 'M5'
                            }
                            TextEdit {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: '100'
                            }
                        }
                        Grid {
                            width: parent.width / 2
                            height: parent.height / 7
                            columns: 2
                            spacing: 2
                            Label {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: 'M6'
                            }

                            TextEdit {
                                horizontalAlignment: Text.AlignHCenter
                                width: parent.width/2
                                color: '#17a81a'
                                text: '100'
                            }
                        }
                    }
                }
            }
        }

        MFrame {
            width: parent.width
            height: parent.height * 0.2
            Grid{
                width: parent.width
                height: parent.height
                spacing: 2
                MButton {
                    width: parent.width
                    height: parent.height
                    _text: 'Set'
                }
            }
        }
    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/

