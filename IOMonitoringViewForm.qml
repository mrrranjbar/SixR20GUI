import QtQuick 2.7
import QtQuick.Controls 2.2
import IOMonitoringViewModel 1.0
//import QtQuick.Controls 1.4


Item {
    property bool _IOFlag: false
    property string _active_bck: "#046380"
    property string _passive_bck: "#EFECCA"
    property string _active_txt_color: "#EFECCA"
    property string _passive_txt_color: "#046380"
    property var _InName: ["DI-1","DI-2","DI-3","DI-4","DI-5","DI-6","DI-7","DI-8","DI-9","DI-10","DI-11","DI-12","DI-13","DI-14","DI-15","DI-16",]
    property var _OutName: ["DO-1","DO-2","DO-3","DO-4","DO-5","DO-6","DO-7","DO-8","DO-9","DO-10","DO-11","DO-12","DO-13","DO-14","DO-15","DO-16",]


    Timer {
        interval: 200
        running: true
        repeat: true
        onTriggered: {
           iomonitoringviewmodel.updateIO()

        }
    }

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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[0] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _InName[0] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoInput[0] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[8] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _InName[8] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoInput[8] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[0] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _OutName[0] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoOutput[0] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[8] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _OutName[8] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoOutput[8] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[1] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _InName[1] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoInput[1] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[9] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _InName[9] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoInput[9] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[1] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _OutName[1] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoOutput[1] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[9] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _OutName[9] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoOutput[9] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[2] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _InName[2] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoInput[2] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[10] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _InName[10] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoInput[10] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[2] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _OutName[2] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoOutput[2] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[10] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _OutName[10] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoOutput[10] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[3] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _InName[3] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoInput[3] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[11] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _InName[11] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoInput[11] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[3] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _OutName[3] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoOutput[3] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[11] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _OutName[11] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoOutput[11] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[4] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _InName[4] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoInput[4] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[12] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _InName[12] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoInput[12] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[4] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _OutName[4] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoOutput[4] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[12] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _OutName[12] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoOutput[12] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[5] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _InName[5] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoInput[5] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[13] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _InName[13] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoInput[13] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[5] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _OutName[5] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoOutput[5] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[13] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _OutName[13] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoOutput[13] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[6] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _InName[6] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoInput[6] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[14] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _InName[14] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoInput[14] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[6] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _OutName[6] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoOutput[6] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[14] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _OutName[14] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoOutput[14] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[7] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _InName[7] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoInput[7] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoInput[15] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _InName[15] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoInput[15] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[7] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _OutName[7] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoOutput[7] ? _active_txt_color : _passive_txt_color
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
                    border.color:  _active_txt_color
                    border.width: 1
                    radius:6
                    color: iomonitoringviewmodel.IoOutput[15] ? _active_bck : _passive_bck

                    Text {
                        text: qsTr("<b>" + _OutName[15] + "</b>")
                        anchors.centerIn: parent
                        color: iomonitoringviewmodel.IoOutput[15] ? _active_txt_color : _passive_txt_color
                    }
                }

            }


        }
    }






//    ListView {
//            anchors.fill: parent

//            FolderListModel {
//                id: folderModel
//                showDirs: true
//                showDirsFirst: true
//                folder: "file:///home/behrooz/SixR_Projects"
//                nameFilters: ["*.*"]
//            }

//            Component {
//                id: fileDelegate
//                Text { text: fileName }
//            }

//            model: folderModel
//            delegate: fileDelegate
//        }






//    TreeView {
//            anchors.fill: parent
//            model: theModel
//            itemDelegate: Rectangle {
//               color: ( styleData.row % 2 == 0 ) ? "white" : "lightblue"
//               height: 20

//               Text {
//                   anchors.verticalCenter: parent.verticalCenter
//                   anchors.left: parent.left // by default x is set to 0 so this had no effect
//                   text: styleData.value
//               }
//           }

//            TableViewColumn {
//                role: "name_role"
//                title: "Name"
//            }
//            TableViewColumn {
//                role: "description_role"
//                title: "Description"
//            }
//        }
}
