import QtQuick 2.7
import QtQuick.Controls 2.2
import IOHandlingViewModel 1.0

Item {
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



            // new Row
            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 1/11
            }


            //****************************************************************
            //****************************************************************

            MFrame{ // Output1
                width: parent.width * 4/12
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
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchOutput1
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[0]
                        onClicked: {
                            switchOutput1.checked = switchOutput1.checked
                            iohandlingviewmodel.setOutputAtIndex(switchOutput1.checked,0)
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput1.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput1.checked ? "#046380" : "#ffffff"
                            border.color: switchOutput1.checked ? "#046380" : "#cccccc"

                            Rectangle {
                                x: switchOutput1.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput1.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput1.checked ? (switchOutput1.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }

                }
            }

            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 2/12
                height: parent.height * 1/11
            }


            //****************************************************************
            //****************************************************************

            MFrame{ // Output9
                width: parent.width * 4/12
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
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchOutput9
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[8]
                        onClicked: {
                            switchOutput9.checked = switchOutput9.checked
                            iohandlingviewmodel.setOutputAtIndex(switchOutput9.checked,8)
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput9.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput9.checked ? "#046380" : "#ffffff"
                            border.color: switchOutput9.checked ? "#046380" : "#cccccc"

                            Rectangle {
                                x: switchOutput9.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput9.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput9.checked ? (switchOutput9.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }
                }
            }

            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 1/11
            }


            // new Row
            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 1/11
            }

            //****************************************************************
            //****************************************************************

            MFrame{ // Output2
                width: parent.width * 4/12
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
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchOutput2
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[1]
                        onClicked: {
                            switchOutput2.checked = switchOutput2.checked
                            iohandlingviewmodel.setOutputAtIndex(switchOutput2.checked,1)
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput2.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput2.checked ? "#046380" : "#ffffff"
                            border.color: switchOutput2.checked ? "#046380" : "#cccccc"

                            Rectangle {
                                x: switchOutput2.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput2.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput2.checked ? (switchOutput2.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }
                }
            }

            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 2/12
                height: parent.height * 1/11
            }


            //****************************************************************
            //****************************************************************

            MFrame{ // Output10
                width: parent.width * 4/12
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
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchOutput10
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[9]
                        onClicked: {
                            switchOutput10.checked = switchOutput10.checked
                            iohandlingviewmodel.setOutputAtIndex(switchOutput10.checked,9)
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput10.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput10.checked ? "#046380" : "#ffffff"
                            border.color: switchOutput10.checked ? "#046380" : "#cccccc"

                            Rectangle {
                                x: switchOutput10.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput10.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput10.checked ? (switchOutput10.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }
                }
            }

            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 1/11
            }


            // new Row
            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 1/11
            }


            //****************************************************************
            //****************************************************************

            MFrame{ // Output3
                width: parent.width * 4/12
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
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchOutput3
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[2]
                        onClicked: {
                            switchOutput3.checked = switchOutput3.checked
                            iohandlingviewmodel.setOutputAtIndex(switchOutput3.checked,2)
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput3.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput3.checked ? "#046380" : "#ffffff"
                            border.color: switchOutput3.checked ? "#046380" : "#cccccc"

                            Rectangle {
                                x: switchOutput3.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput3.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput3.checked ? (switchOutput3.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }
                }
            }

            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 2/12
                height: parent.height * 1/11
            }

            //****************************************************************
            //****************************************************************

            MFrame{ // Output11
                width: parent.width * 4/12
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
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchOutput11
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[10]
                        onClicked: {
                            switchOutput11.checked = switchOutput11.checked
                            iohandlingviewmodel.setOutputAtIndex(switchOutput11.checked,10)
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput11.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput11.checked ? "#046380" : "#ffffff"
                            border.color: switchOutput11.checked ? "#046380" : "#cccccc"

                            Rectangle {
                                x: switchOutput11.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput11.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput11.checked ? (switchOutput11.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }
                }
            }
            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 1/11
            }



            // new Row
            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 1/11
            }


            //****************************************************************
            //****************************************************************


            MFrame{ // Output4
                width: parent.width * 4/12
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
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchOutput4
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[3]
                        onClicked: {
                            switchOutput4.checked = switchOutput4.checked
                            iohandlingviewmodel.setOutputAtIndex(switchOutput4.checked,3)
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput4.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput4.checked ? "#046380" : "#ffffff"
                            border.color: switchOutput4.checked ? "#046380" : "#cccccc"

                            Rectangle {
                                x: switchOutput4.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput4.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput4.checked ? (switchOutput4.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }
                }
            }


            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 2/12
                height: parent.height * 1/11
            }


            //****************************************************************
            //****************************************************************

            MFrame{ // Output12
                width: parent.width * 4/12
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
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchOutput12
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[11]
                        onClicked: {
                            switchOutput12.checked = switchOutput12.checked
                            iohandlingviewmodel.setOutputAtIndex(switchOutput12.checked,11)
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput12.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput12.checked ? "#046380" : "#ffffff"
                            border.color: switchOutput12.checked ? "#046380" : "#cccccc"
                            Rectangle {
                                x: switchOutput12.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput12.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput12.checked ? (switchOutput12.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }
                }
            }
            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 1/11
            }


            // new Row
            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 1/11
            }


            //****************************************************************
            //****************************************************************

            MFrame{ // Output5
                width: parent.width * 4/12
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
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchOutput5
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[4]
                        onClicked: {
                            switchOutput5.checked = switchOutput5.checked
                            iohandlingviewmodel.setOutputAtIndex(switchOutput5.checked,4)
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput5.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput5.checked ? "#046380" : "#ffffff"
                            border.color: switchOutput5.checked ? "#046380" : "#cccccc"

                            Rectangle {
                                x: switchOutput5.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput5.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput5.checked ? (switchOutput5.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }
                }
            }


            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 2/12
                height: parent.height * 1/11
            }


            //****************************************************************
            //****************************************************************

            MFrame{ // Output13
                width: parent.width * 4/12
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
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchOutput13
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[12]
                        onClicked: {
                            switchOutput13.checked = switchOutput13.checked
                            iohandlingviewmodel.setOutputAtIndex(switchOutput13.checked,12)
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput13.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput13.checked ? "#046380" : "#ffffff"
                            border.color: switchOutput13.checked ? "#046380" : "#cccccc"

                            Rectangle {
                                x: switchOutput13.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput13.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput13.checked ? (switchOutput13.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }
                }
            }
            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 1/11
            }



            // new Row
            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 1/11
            }

            //****************************************************************
            //****************************************************************

            MFrame{ // Output6
                width: parent.width * 4/12
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
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchOutput6
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[5]
                        onClicked: {
                            switchOutput6.checked = switchOutput6.checked
                            iohandlingviewmodel.setOutputAtIndex(switchOutput6.checked,5)
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput6.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput6.checked ? "#046380" : "#ffffff"
                            border.color: switchOutput6.checked ? "#046380" : "#cccccc"

                            Rectangle {
                                x: switchOutput6.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput6.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput6.checked ? (switchOutput6.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }
                }
            }

            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 2/12
                height: parent.height * 1/11
            }

            //****************************************************************
            //****************************************************************

            MFrame{ // Output14
                width: parent.width * 4/12
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
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchOutput14
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[13]
                        onClicked: {
                            switchOutput14.checked = switchOutput14.checked
                            iohandlingviewmodel.setOutputAtIndex(switchOutput14.checked,13)
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput14.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput14.checked ? "#046380" : "#ffffff"
                            border.color: switchOutput14.checked ? "#046380" : "#cccccc"

                            Rectangle {
                                x: switchOutput14.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput14.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput14.checked ? (switchOutput14.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }
                }
            }
            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 1/11
            }

            // new Row
            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 1/11
            }

            //****************************************************************
            //****************************************************************

            MFrame{ // Output7
                width: parent.width * 4/12
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
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchOutput7
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[6]
                        onClicked: {
                            switchOutput7.checked = switchOutput7.checked
                            iohandlingviewmodel.setOutputAtIndex(switchOutput7.checked,6)
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput7.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput7.checked ? "#046380" : "#ffffff"
                            border.color: switchOutput7.checked ? "#046380" : "#cccccc"

                            Rectangle {
                                x: switchOutput7.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput7.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput7.checked ? (switchOutput7.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }
                }
            }

            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 2/12
                height: parent.height * 1/11
            }

            //****************************************************************
            //****************************************************************

            MFrame{ // Output15
                width: parent.width * 4/12
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
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchOutput15
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[14]
                        onClicked: {
                            switchOutput15.checked = switchOutput15.checked
                            iohandlingviewmodel.setOutputAtIndex(switchOutput15.checked,14)
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput15.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput15.checked ? "#046380" : "#ffffff"
                            border.color: switchOutput15.checked ? "#046380" : "#cccccc"

                            Rectangle {
                                x: switchOutput15.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput15.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput15.checked ? (switchOutput15.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }
                }
            }
            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 1/11
            }

            // new Row
            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 1/11
            }

            //****************************************************************
            //****************************************************************

            MFrame{ // Output8
                width: parent.width * 4/12
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
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchOutput8
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[7]
                        onClicked: {
                            switchOutput8.checked = switchOutput8.checked
                            iohandlingviewmodel.setOutputAtIndex(switchOutput8.checked,7)
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput8.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput8.checked ? "#046380" : "#ffffff"
                            border.color: switchOutput8.checked ? "#046380" : "#cccccc"

                            Rectangle {
                                x: switchOutput8.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput8.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput8.checked ? (switchOutput8.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }
                }
            }


            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 2/12
                height: parent.height * 1/11
            }

            //****************************************************************
            //****************************************************************

            MFrame{ // Output16
                width: parent.width * 4/12
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
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchOutput16
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[15]
                        onClicked: {
                            switchOutput16.checked = switchOutput16.checked
                            iohandlingviewmodel.setOutputAtIndex(switchOutput16.checked,15)
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchOutput16.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchOutput16.checked ? "#046380" : "#ffffff"
                            border.color: switchOutput16.checked ? "#046380" : "#cccccc"

                            Rectangle {
                                x: switchOutput16.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchOutput16.down ? "#cccccc" : "#ffffff"
                                border.color: switchOutput16.checked ? (switchOutput16.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }
                }
            }
            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 1/11
            }

            //****************************************************************
            //****************************************************************


        }
    }
}
