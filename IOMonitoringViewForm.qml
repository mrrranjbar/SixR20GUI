import QtQuick 2.7
import QtQuick.Controls 2.2
import IOMonitoringViewModel 1.0

Item {
    property bool _IOFlag: false
    property var _InName: ["DI-1","DI-2","DI-3","DI-4","DI-5","DI-6","DI-7","DI-8","DI-9","DI-10","DI-11","DI-12","DI-13","DI-14","DI-15","DI-16",]
    property var _OutName: ["DO-1","DO-2","DO-3","DO-4","DO-5","DO-6","DO-7","DO-8","DO-9","DO-10","DO-11","DO-12","DO-13","DO-14","DO-15","DO-16",]




    IOMonitoringViewModel{
        id:iomonitoringviewmodel
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

            Label //input1
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[0] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _InName[0] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }

            //****************************************************************
            //****************************************************************

            Label //input9
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[8] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _InName[8] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
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

            Label //output1
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[0] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _OutName[0] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }
            //****************************************************************
            //****************************************************************

            Label //output9
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[8] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _OutName[8] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }


            // new Row
            //****************************************************************
            //****************************************************************

            Label //input2
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[1] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _InName[1] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }

            //****************************************************************
            //****************************************************************

            Label //input10
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[9] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _InName[9] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
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

            Label //output2
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[1] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _OutName[1] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }
            //****************************************************************
            //****************************************************************

            Label //output10
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[9] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _OutName[9] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }



            // new Row
            //****************************************************************
            //****************************************************************

            Label //input3
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[2] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _InName[2] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }

            //****************************************************************
            //****************************************************************

            Label //input11
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[10] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _InName[10] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
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

            Label //output3
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[2] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _OutName[2] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }
            //****************************************************************
            //****************************************************************

            Label //output11
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[10] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _OutName[10] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }



            // new Row
            //****************************************************************
            //****************************************************************

            Label //input4
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[3] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _InName[3] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }

            //****************************************************************
            //****************************************************************

            Label //input12
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[11] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _InName[11] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
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

            Label //output4
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[3] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _OutName[3] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }
            //****************************************************************
            //****************************************************************

            Label //output12
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[11] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _OutName[11] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }


            // new Row
            //****************************************************************
            //****************************************************************

            Label //input5
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[4] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _InName[4] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }

            //****************************************************************
            //****************************************************************

            Label //input13
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[12] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _InName[12] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
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

            Label //output5
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[4] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _OutName[4] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }
            //****************************************************************
            //****************************************************************

            Label //output13
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[12] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _OutName[12] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }



            // new Row
            //****************************************************************
            //****************************************************************

            Label //input6
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[5] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _InName[5] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }

            //****************************************************************
            //****************************************************************

            Label //input14
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[13] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _InName[13] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
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

            Label //output6
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[5] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _OutName[5] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }
            //****************************************************************
            //****************************************************************

            Label //output14
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[13] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _OutName[13] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }

            // new Row
            //****************************************************************
            //****************************************************************

            Label //input7
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[6] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _InName[6] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }

            //****************************************************************
            //****************************************************************

            Label //input15
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[14] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _InName[14] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
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

            Label //output7
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[6] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _OutName[6] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }
            //****************************************************************
            //****************************************************************

            Label //output15
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[14] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _OutName[14] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }

            // new Row
            //****************************************************************
            //****************************************************************

            Label //input8
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[7] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _InName[7] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }

            //****************************************************************
            //****************************************************************

            Label //input16
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[15] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _InName[15] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
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

            Label //output8
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[7] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _OutName[7] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }
            //****************************************************************
            //****************************************************************

            Label //output16
            {
                width: parent.width * 3/13
                height: parent.height * 1/11

                Rectangle{
                    width: parent.width
                    height: parent.height
                    border.color:  "#EFECCA"
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[15] ? "#C5E1A5" : "white"

                    Text {
                        text: qsTr("<b>" + _OutName[15] + "</b>")
                        anchors.centerIn: parent
                        color: "#EFECCA"
                    }
                }

            }


        }
    }
}
