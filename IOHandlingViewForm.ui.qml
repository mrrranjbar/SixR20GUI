import QtQuick 2.7
import QtQuick.Controls 2.2
import IOHandlingViewModel 1.0

Item {
    property bool _IOFlag: true
    property var _InName: ["DI-1","DI-2","DI-3","DI-4","DI-5","DI-6","DI-7","DI-8","DI-9","DI-10","DI-11","DI-12","DI-13","DI-14","DI-15","DI-16",]
    property var _OutName: ["DO-1","DO-2","DO-3","DO-4","DO-5","DO-6","DO-7","DO-8","DO-9","DO-10","DO-11","DO-12","DO-13","DO-14","DO-15","DO-16",]


    IOHandlingViewModel{
        id:iohandlingviewmodel
    }


    MFrame{
        width: parent.width
        height: parent.height


        Grid{ // main grid
            width: parent.width * 9/10
            height: parent.height
            padding: 10
            columns: 5
            spacing: 10

            //****************************************************************
            //****************************************************************


            MFrame{ // Input1
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _InName[0] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchInput1
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchInput1.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchInput1.checked ? "#17a81a" : "#ffffff"
                            border.color: switchInput1.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchInput1.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchInput1.down ? "#cccccc" : "#ffffff"
                                border.color: switchInput1.checked ? (switchInput1.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }

            //****************************************************************
            //****************************************************************

            MFrame{ // Input9
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _InName[8] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchInput9
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchInput9.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchInput9.checked ? "#17a81a" : "#ffffff"
                            border.color: switchInput9.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchInput9.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchInput9.down ? "#cccccc" : "#ffffff"
                                border.color: switchInput9.checked ? (switchInput9.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }


            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/13
                height: parent.height * 1/11
            }


            //****************************************************************
            //****************************************************************

            MFrame{ // Output1
                width: parent.width * 3/13
                height: parent.height * 1/11

                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0

                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _OutName[0] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchOutput1
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput1.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput1.checked ? "#17a81a" : "#ffffff"
                            border.color: switchOutput1.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchOutput1.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput1.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput1.checked ? (switchOutput1.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }

                }
            }
            //****************************************************************
            //****************************************************************

            MFrame{ // Output9
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _OutName[8] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchOutput9
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput9.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput9.checked ? "#17a81a" : "#ffffff"
                            border.color: switchOutput9.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchOutput9.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput9.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput9.checked ? (switchOutput9.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }


            // new Row
            //****************************************************************
            //****************************************************************

            MFrame{ // Input2
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _InName[1] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchInput2
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchInput2.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchInput2.checked ? "#17a81a" : "#ffffff"
                            border.color: switchInput2.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchInput2.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchInput2.down ? "#cccccc" : "#ffffff"
                                border.color: switchInput2.checked ? (switchInput2.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }




            //****************************************************************
            //****************************************************************


            MFrame{ // Input10
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _InName[9] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchInput10
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchInput10.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchInput10.checked ? "#17a81a" : "#ffffff"
                            border.color: switchInput10.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchInput10.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchInput10.down ? "#cccccc" : "#ffffff"
                                border.color: switchInput10.checked ? (switchInput10.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }


            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/13
                height: parent.height * 1/11
            }


            //****************************************************************
            //****************************************************************



            MFrame{ // Output2
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _OutName[1] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchOutput2
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput2.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput2.checked ? "#17a81a" : "#ffffff"
                            border.color: switchOutput2.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchOutput2.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput2.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput2.checked ? (switchOutput2.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }
            //****************************************************************
            //****************************************************************

            MFrame{ // Output10
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _OutName[9] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchOutput10
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput10.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput10.checked ? "#17a81a" : "#ffffff"
                            border.color: switchOutput10.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchOutput10.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput10.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput10.checked ? (switchOutput10.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }



            // new Row
            //****************************************************************
            //****************************************************************

            MFrame{ // Input3
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _InName[2] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchInput3
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchInput3.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchInput3.checked ? "#17a81a" : "#ffffff"
                            border.color: switchInput3.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchInput3.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchInput3.down ? "#cccccc" : "#ffffff"
                                border.color: switchInput3.checked ? (switchInput3.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }




            //****************************************************************
            //****************************************************************


            MFrame{ // Input11
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _InName[10] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchInput11
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchInput11.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchInput11.checked ? "#17a81a" : "#ffffff"
                            border.color: switchInput11.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchInput11.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchInput11.down ? "#cccccc" : "#ffffff"
                                border.color: switchInput11.checked ? (switchInput11.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }


            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/13
                height: parent.height * 1/11
            }


            //****************************************************************
            //****************************************************************

            MFrame{ // Output3
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _OutName[2] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchOutput3
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput3.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput3.checked ? "#17a81a" : "#ffffff"
                            border.color: switchOutput3.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchOutput3.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput3.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput3.checked ? (switchOutput3.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }
            //****************************************************************
            //****************************************************************

            MFrame{ // Output11
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _OutName[10] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchOutput11
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput11.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput11.checked ? "#17a81a" : "#ffffff"
                            border.color: switchOutput11.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchOutput11.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput11.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput11.checked ? (switchOutput11.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }



            // new Row
            //****************************************************************
            //****************************************************************

            MFrame{ // Input4
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _InName[3] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchInput4
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchInput4.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchInput4.checked ? "#17a81a" : "#ffffff"
                            border.color: switchInput4.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchInput4.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchInput4.down ? "#cccccc" : "#ffffff"
                                border.color: switchInput4.checked ? (switchInput4.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }




            //****************************************************************
            //****************************************************************


            MFrame{ // Input12
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _InName[11] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchInput12
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchInput12.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchInput12.checked ? "#17a81a" : "#ffffff"
                            border.color: switchInput12.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchInput12.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchInput12.down ? "#cccccc" : "#ffffff"
                                border.color: switchInput12.checked ? (switchInput12.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }


            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/13
                height: parent.height * 1/11
            }


            //****************************************************************
            //****************************************************************

            MFrame{ // Output4
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _OutName[3] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchOutput4
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput4.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput4.checked ? "#17a81a" : "#ffffff"
                            border.color: switchOutput4.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchOutput4.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput4.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput4.checked ? (switchOutput4.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }
            //****************************************************************
            //****************************************************************

            MFrame{ // Output12
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _OutName[11] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchOutput12
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput12.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput12.checked ? "#17a81a" : "#ffffff"
                            border.color: switchOutput12.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchOutput12.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput12.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput12.checked ? (switchOutput12.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }


            // new Row
            //****************************************************************
            //****************************************************************

            MFrame{ // Input5
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _InName[4] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchInput5
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchInput5.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchInput5.checked ? "#17a81a" : "#ffffff"
                            border.color: switchInput5.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchInput5.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchInput5.down ? "#cccccc" : "#ffffff"
                                border.color: switchInput5.checked ? (switchInput5.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }




            //****************************************************************
            //****************************************************************


            MFrame{ // Input13
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _InName[12] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchInput13
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchInput13.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchInput13.checked ? "#17a81a" : "#ffffff"
                            border.color: switchInput13.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchInput13.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchInput13.down ? "#cccccc" : "#ffffff"
                                border.color: switchInput13.checked ? (switchInput13.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }


            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/13
                height: parent.height * 1/11
            }


            //****************************************************************
            //****************************************************************

            MFrame{ // Output5
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _OutName[4] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchOutput5
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput5.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput5.checked ? "#17a81a" : "#ffffff"
                            border.color: switchOutput5.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchOutput5.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput5.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput5.checked ? (switchOutput5.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }
            //****************************************************************
            //****************************************************************

            MFrame{ // Output13
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _OutName[12] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchOutput13
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput13.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput13.checked ? "#17a81a" : "#ffffff"
                            border.color: switchOutput13.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchOutput13.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput13.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput13.checked ? (switchOutput13.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }



            // new Row
            //****************************************************************
            //****************************************************************

            MFrame{ // Input6
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _InName[5] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchInput6
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchInput6.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchInput6.checked ? "#17a81a" : "#ffffff"
                            border.color: switchInput6.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchInput6.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchInput6.down ? "#cccccc" : "#ffffff"
                                border.color: switchInput6.checked ? (switchInput6.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }




            //****************************************************************
            //****************************************************************


            MFrame{ // Input14
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _InName[13] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchInput14
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchInput14.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchInput14.checked ? "#17a81a" : "#ffffff"
                            border.color: switchInput14.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchInput14.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchInput14.down ? "#cccccc" : "#ffffff"
                                border.color: switchInput14.checked ? (switchInput14.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }


            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/13
                height: parent.height * 1/11
            }


            //****************************************************************
            //****************************************************************

            MFrame{ // Output6
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _OutName[5] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchOutput6
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput6.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput6.checked ? "#17a81a" : "#ffffff"
                            border.color: switchOutput6.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchOutput6.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput6.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput6.checked ? (switchOutput6.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }
            //****************************************************************
            //****************************************************************

            MFrame{ // Output14
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _OutName[13] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchOutput14
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput14.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput14.checked ? "#17a81a" : "#ffffff"
                            border.color: switchOutput14.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchOutput14.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput14.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput14.checked ? (switchOutput14.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }

            // new Row
            //****************************************************************
            //****************************************************************

            MFrame{ // Input7
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _InName[6] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchInput7
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchInput7.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchInput7.checked ? "#17a81a" : "#ffffff"
                            border.color: switchInput7.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchInput7.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchInput7.down ? "#cccccc" : "#ffffff"
                                border.color: switchInput7.checked ? (switchInput7.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }




            //****************************************************************
            //****************************************************************


            MFrame{ // Input15
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _InName[14] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchInput15
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchInput15.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchInput15.checked ? "#17a81a" : "#ffffff"
                            border.color: switchInput15.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchInput15.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchInput15.down ? "#cccccc" : "#ffffff"
                                border.color: switchInput15.checked ? (switchInput15.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }


            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/13
                height: parent.height * 1/11
            }


            //****************************************************************
            //****************************************************************

            MFrame{ // Output7
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _OutName[6] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchOutput7
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput7.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput7.checked ? "#17a81a" : "#ffffff"
                            border.color: switchOutput7.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchOutput7.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput7.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput7.checked ? (switchOutput7.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }
            //****************************************************************
            //****************************************************************

            MFrame{ // Output15
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _OutName[14] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchOutput15
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput15.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput15.checked ? "#17a81a" : "#ffffff"
                            border.color: switchOutput15.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchOutput15.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput15.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput15.checked ? (switchOutput15.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }

            // new Row
            //****************************************************************
            //****************************************************************

            MFrame{ // Input8
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _InName[7] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchInput8
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchInput8.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchInput8.checked ? "#17a81a" : "#ffffff"
                            border.color: switchInput8.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchInput8.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchInput8.down ? "#cccccc" : "#ffffff"
                                border.color: switchInput8.checked ? (switchInput8.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }




            //****************************************************************
            //****************************************************************


            MFrame{ // Input16
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _InName[15] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchInput16
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchInput16.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchInput16.checked ? "#17a81a" : "#ffffff"
                            border.color: switchInput16.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchInput16.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchInput16.down ? "#cccccc" : "#ffffff"
                                border.color: switchInput16.checked ? (switchInput16.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }


            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/13
                height: parent.height * 1/11
            }


            //****************************************************************
            //****************************************************************

            MFrame{ // Output8
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _OutName[7] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchOutput8
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput8.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput8.checked ? "#17a81a" : "#ffffff"
                            border.color: switchOutput8.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchOutput8.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput8.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput8.checked ? (switchOutput8.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }
            //****************************************************************
            //****************************************************************

            MFrame{ // Output16
                width: parent.width * 3/13
                height: parent.height * 1/11
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width*1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _OutName[15] + "</b>"
                        color: "#21be2b"
                    }
                    Switch {
                        id: switchOutput16
                        width: parent.width*1/2
                        height: parent.height
                        onClicked: _IOFlag = ! _IOFlag
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput16.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput16.checked ? "#17a81a" : "#ffffff"
                            border.color: switchOutput16.checked ? "#17a81a" : "#cccccc"

                            Rectangle {
                                x: switchOutput16.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput16.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput16.checked ? (switchOutput16.down ? "#17a81a" : "#21be2b") : "#999999"
                            }
                        }
                    }
                }
            }


        }
    }
}

/*##^## Designer {
    D{i:0;autoSize:true;height:350;width:640}
}
 ##^##*/
