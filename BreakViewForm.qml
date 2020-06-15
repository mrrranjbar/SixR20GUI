import QtQuick 2.7
import QtQuick.Controls 2.2
import BreakViewModel 1.0
import QtQuick.Layouts 1.3

Item {

    property var _motors_name: ["MOTOR-1","MOTOR-2","MOTOR-3","MOTOR-4","MOTOR-5","MOTOR-6"]
    property int _current_motor: 1

    BreakViewModel
    {
        id:breakviewmodel
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
                height: parent.height * 3/11
            }


            //****************************************************************
            //****************************************************************

            MFrame{ // MOTOR-1
                width: parent.width * 4/12
                height: parent.height * 3/11

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
                        text: "<b>" + _motors_name[0] + "</b>"
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchMotor1
                        width: parent.width*1/2
                        height: parent.height
                        checked: false
                        onClicked: {
                            if(!switchMotor1.checked)
                            {
                                switchMotor1.checked=true
                                _current_motor=0
                                confirmPopup.open()
                            }
                            else
                            {
                                breakviewmodel.setBreakAtIndex(switchMotor1.checked,0)
                            }
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchMotor1.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchMotor1.checked ? "#046380" : "#ffffff"
                            border.color: switchMotor1.checked ? "#046380" : "#cccccc"

                            Rectangle {
                                x: switchMotor1.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchMotor1.down ? "#cccccc" : "#ffffff"
                                border.color: switchMotor1.checked ? (switchMotor1.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }

                }
            }

            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 2/12
                height: parent.height * 3/11
            }


            //****************************************************************
            //****************************************************************

            MFrame{ // MOTOR-4
                width: parent.width * 4/12
                height: parent.height * 3/11

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
                        text: "<b>" + _motors_name[3] + "</b>"
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchMotor4
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[0]
                        onClicked: {
                            if(!switchMotor4.checked)
                            {
                                switchMotor4.checked=true
                                _current_motor=3
                                confirmPopup.open()
                            }
                            else
                            {
                                breakviewmodel.setBreakAtIndex(switchMotor4.checked,3)
                            }
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchMotor4.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchMotor4.checked ? "#046380" : "#ffffff"
                            border.color: switchMotor4.checked ? "#046380" : "#cccccc"

                            Rectangle {
                                x: switchMotor4.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchMotor4.down ? "#cccccc" : "#ffffff"
                                border.color: switchMotor4.checked ? (switchMotor4.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }

                }
            }

            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 3/11
            }


            // new Row
            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 3/11
            }

            //****************************************************************
            //****************************************************************

            MFrame{ // MOTOR-2
                width: parent.width * 4/12
                height: parent.height * 3/11

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
                        text: "<b>" + _motors_name[1] + "</b>"
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchMotor2
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[0]
                        onClicked: {
                            if(!switchMotor2.checked)
                            {
                                switchMotor2.checked=true
                                _current_motor=1
                                confirmPopup.open()
                            }
                            else
                            {
                                breakviewmodel.setBreakAtIndex(switchMotor2.checked,1)
                            }
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchMotor2.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchMotor2.checked ? "#046380" : "#ffffff"
                            border.color: switchMotor2.checked ? "#046380" : "#cccccc"

                            Rectangle {
                                x: switchMotor2.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchMotor2.down ? "#cccccc" : "#ffffff"
                                border.color: switchMotor2.checked ? (switchMotor2.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }

                }
            }

            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 2/12
                height: parent.height * 3/11
            }


            //****************************************************************
            //****************************************************************

            MFrame{ // MOTOR-5
                width: parent.width * 4/12
                height: parent.height * 3/11

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
                        text: "<b>" + _motors_name[4] + "</b>"
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchMotor5
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[0]
                        onClicked: {
                            if(!switchMotor5.checked)
                            {
                                switchMotor5.checked=true
                                _current_motor=4
                                confirmPopup.open()
                            }
                            else
                            {
                                breakviewmodel.setBreakAtIndex(switchMotor5.checked,4)
                            }
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchMotor5.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchMotor5.checked ? "#046380" : "#ffffff"
                            border.color: switchMotor5.checked ? "#046380" : "#cccccc"
                            Rectangle {
                                x: switchMotor5.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchMotor5.down ? "#cccccc" : "#ffffff"
                                border.color: switchMotor5.checked ? (switchMotor5.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }

                }
            }

            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 3/11
            }


            // new Row
            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 3/11
            }


            //****************************************************************
            //****************************************************************

            MFrame{ // MOTOR-3
                width: parent.width * 4/12
                height: parent.height * 3/11

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
                        text: "<b>" + _motors_name[2] + "</b>"
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchMotor3
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[0]
                        onClicked: {
                            if(!switchMotor3.checked)
                            {
                                switchMotor3.checked=true
                                _current_motor=2
                                confirmPopup.open()
                            }
                            else
                            {
                                breakviewmodel.setBreakAtIndex(switchMotor3.checked,2)
                            }
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchMotor3.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchMotor3.checked ? "#046380" : "#ffffff"
                            border.color: switchMotor3.checked ? "#046380" : "#cccccc"

                            Rectangle {
                                x: switchMotor3.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchMotor3.down ? "#cccccc" : "#ffffff"
                                border.color: switchMotor3.checked ? (switchMotor3.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }

                }
            }

            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 2/12
                height: parent.height * 3/11
            }

            //****************************************************************
            //****************************************************************

            MFrame{ // MOTOR-6
                width: parent.width * 4/12
                height: parent.height * 3/11

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
                        text: "<b>" + _motors_name[5] + "</b>"
                        color: "#EFECCA"
                    }
                    Switch {
                        id: switchMotor6
                        width: parent.width*1/2
                        height: parent.height
                        checked: iohandlingviewmodel.IoOutput[0]
                        onClicked: {
                            if(!switchMotor6.checked)
                            {
                                switchMotor6.checked=true
                                _current_motor=5
                                confirmPopup.open()
                            }
                            else
                            {
                                breakviewmodel.setBreakAtIndex(switchMotor6.checked,5)
                            }
                        }
                        indicator: Rectangle {
                            implicitWidth: 35
                            implicitHeight: 20
                            x: switchMotor6.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            color: switchMotor6.checked ? "#046380" : "#ffffff"
                            border.color: switchMotor6.checked ? "#046380" : "#cccccc"

                            Rectangle {
                                x: switchMotor6.checked ? parent.width - width : 0
                                width: 20
                                height: 20
                                radius: 13
                                color: switchMotor6.down ? "#cccccc" : "#ffffff"
                                border.color: switchMotor6.checked ? (switchMotor6.down ? "#046380" : "#EFECCA") : "#046380"
                            }
                        }
                    }

                }
            }
            //****************************************************************
            //****************************************************************

            Label{
                width: parent.width * 1/12
                height: parent.height * 3/11
            }

        }
    }


    //**************************************************
    //**************************************************


    Popup
    {
        id: confirmPopup
        //anchors.centerIn: parent
        modal: true
        focus: true
        closePolicy: Popup.NoAutoClose
        background: Rectangle {
            visible: true
            color: "#002F2F"
        }
        ColumnLayout {
            anchors.fill: parent
            spacing: 30

            Text {
                id: confirmPopupText
                color: "#EFECCA"
                text: qsTr("Are You Sure To Turn Off MOTOR-"+(_current_motor+1)+" Break?")
            }

            RowLayout
            {
                anchors.right: parent.right
                MButton {
                    _text: "Yes"
                    onBtnClick:
                    {
                        if(_current_motor==0)
                            switchMotor1.checked=false
                        else if(_current_motor==1)
                            switchMotor2.checked=false
                        else if(_current_motor==2)
                            switchMotor3.checked=false
                        else if(_current_motor==3)
                            switchMotor4.checked=false
                        else if(_current_motor==4)
                            switchMotor5.checked=false
                        else if(_current_motor==5)
                            switchMotor6.checked=false
                        breakviewmodel.setBreakAtIndex(false,_current_motor)
                        confirmPopup.close()
                    }
                }
                MButton {
                    _text: "No"
                    onBtnClick:
                    {
                        if(_current_motor==0)
                            switchMotor1.checked=true
                        else if(_current_motor==1)
                            switchMotor2.checked=true
                        else if(_current_motor==2)
                            switchMotor3.checked=true
                        else if(_current_motor==3)
                            switchMotor4.checked=true
                        else if(_current_motor==4)
                            switchMotor5.checked=true
                        else if(_current_motor==5)
                            switchMotor6.checked=true
                        confirmPopup.close()
                    }
                }
            }
        }
    }
}

