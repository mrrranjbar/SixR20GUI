import QtQuick 2.7
import QtQuick.Controls 2.2
import PositionViewModel 1.0

Item {

    id:mainitem
    property int _width: 260
    property int _height: 75
    property bool _joint: true
    property var _nameJoint: ["M1", "M2", "M3", "M4", "M5", "M6"]
    property var _nameCartesian: ["X", "Y", "Z", "Ro", "Pi", "Ya"]

    PositionViewModel
    {
        id:positionviewmodel
    }

    Grid{ // main Grid
        width: parent.width
        height: parent.height * 0.95
        rows: 4
        spacing: 5

        Grid // Top grid
        {
            width: parent.width * 0.98
            height: parent.height * 0.25
            columns: 2
            spacing: 5

            //***************************************************************
            //***************************************************************


            // switch button
            Switch {
                id: control
                text:control.checked ? qsTr("Cartesian") : qsTr("Joint")
                width: parent.width * 0.5
                height: parent.height
                onClicked: {
                    _joint = ! _joint
                    positionviewmodel.IsJoint = !positionviewmodel.IsJoint
                }
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


            //********************************************************
            //********************************************************


            Grid //Select Frame Grid
            {
                width: parent.width * 0.5
                height: parent.height
                columns: 2
                visible: !_joint

                Rectangle{

                    width: parent.width * 1/3
                    height: parent.height
                    color: "transparent"
                    Label
                    {
                        anchors.centerIn: parent
                        text: qsTr("Frame")
                        color: "#21be2b"
                    }
                }

                //**********************************************

                ComboBox {
                    id: cmb_frame
                    height: parent.height
                    width: parent.width * 2/3
                    model: ["object","task","tool","world","base"]

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
                            context.reset();
                            context.moveTo(0, 0);
                            context.lineTo(width, 0);
                            context.lineTo(width / 2, height);
                            context.closePath();
                            context.fillStyle = cmb_frame.pressed ? "#17a81a" : "#21be2b";
                            context.fill();
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

                            ScrollIndicator.vertical: ScrollIndicator { }
                        }

                        background: Rectangle {
                            border.color: "#21be2b"
                            radius: 5
                        }
                    }

                    onCurrentIndexChanged:
                    {

                    }
                }


            }

        }



        //********************************************************
        //********************************************************

        // Joint
        Grid{ // Motor 1 & Motor 2 & Motor 3 Grid

            width: parent.width * 0.98
            height: parent.height * 0.25
            columns: 3
            spacing: 5
            visible: _joint

            MFrame{ // Motor1
                width: parent.width * 1/3
                height: parent.height
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width * 1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameJoint[0] + "</b>"
                        color: "#21be2b"
                    }

                    TextInput {
                        id: mTextField1
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#21be2b"
                        text: "0"
                    }
//                    MButton{
//                        _width: parent.width * 1/3
//                        _height: parent.height
//                        _text:"Go"
//                        onBtnClick: {
//                            positionviewmodel.setPosition( mTextField1.text,0)
//                            //positionviewmodel.Positions[0] = mTextField1._text
//                            positionviewmodel.Move(0)
//                        }

//                    }
                }
            }


            //***************************************************************
            //***************************************************************

            MFrame{ // Motor2
                width: parent.width * 1/3
                height: parent.height
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width * 1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameJoint[1] + "</b>"
                        color: "#21be2b"
                    }

                    TextInput {
                        id: mTextField2
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#21be2b"
                        text: "0"
                    }
                }
            }

            //***************************************************************
            //***************************************************************


            MFrame{ // Motor3
                width: parent.width * 1/3
                height: parent.height
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width * 1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameJoint[2] + "</b>"
                        color: "#21be2b"
                    }

                    TextInput {
                        id: mTextField3
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#21be2b"
                        text: "0"
                    }
                }
            }

        }

        //***************************************************************
        //***************************************************************

        // Joint
        Grid{ // Motor 4 & Motor 5 & Motor 6 Grid

            width: parent.width * 0.98
            height: parent.height * 0.25
            columns: 3
            spacing: 5
            visible: _joint

            MFrame{ // Motor4
                width: parent.width * 1/3
                height: parent.height
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width * 1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameJoint[3] + "</b>"
                        color: "#21be2b"
                    }

                    TextInput {
                        id: mTextField4
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#21be2b"
                        text: "0"
                    }
                }
            }

            //***************************************************************
            //***************************************************************


            MFrame{ // Motor5
                width: parent.width * 1/3
                height: parent.height
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width * 1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameJoint[4] + "</b>"
                        color: "#21be2b"
                    }

                    TextInput {
                        id: mTextField5
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#21be2b"
                        text: "0"
                    }
                }
            }

            //***************************************************************
            //***************************************************************

            MFrame{ // Motor6
                width: parent.width * 1/3
                height: parent.height
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width * 1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameJoint[5] + "</b>"
                        color: "#21be2b"
                    }

                    TextInput {
                        id: mTextField6
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#21be2b"
                        text: "0"
                    }
                }
            }
        }

        //***************************************************************
        //***************************************************************

        // Cartesian
        Grid{ // Motor 1 & Motor 2 & Motor 3 Grid

            width: parent.width * 0.98
            height: parent.height * 0.25
            columns: 3
            spacing: 5
            visible: !_joint

            MFrame{ // Motor1
                width: parent.width * 1/3
                height: parent.height
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width * 1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameCartesian[0] + "</b>"
                        color: "#21be2b"
                    }

                    TextInput {
                        id: mTextField1_cartesian
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#21be2b"
                        text: "820"
                    }
                }
            }


            //***************************************************************
            //***************************************************************

            MFrame{ // Motor2
                width: parent.width * 1/3
                height: parent.height
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width * 1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameCartesian[1] + "</b>"
                        color: "#21be2b"
                    }

                    TextInput {
                        id: mTextField2_cartesian
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#21be2b"
                        text: "0"
                    }
                }
            }

            //***************************************************************
            //***************************************************************


            MFrame{ // Motor3
                width: parent.width * 1/3
                height: parent.height
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width * 1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameCartesian[2] + "</b>"
                        color: "#21be2b"
                    }

                    TextInput {
                        id: mTextField3_cartesian
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#21be2b"
                        text: "1189"
                    }
                }
            }

        }

        //***************************************************************
        //***************************************************************

        // Cartesian
        Grid{ // Motor 4 & Motor 5 & Motor 6 Grid

            width: parent.width * 0.98
            height: parent.height * 0.25
            columns: 3
            spacing: 5
            visible: !_joint

            MFrame{ // Motor4
                width: parent.width * 1/3
                height: parent.height
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width * 1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameCartesian[3] + "</b>"
                        color: "#21be2b"
                    }

                    TextInput {
                        id: mTextField4_cartesian
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#21be2b"
                        text: "0"
                    }
                }
            }

            //***************************************************************
            //***************************************************************


            MFrame{ // Motor5
                width: parent.width * 1/3
                height: parent.height
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width * 1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameCartesian[4] + "</b>"
                        color: "#21be2b"
                    }

                    TextInput {
                        id: mTextField5_cartesian
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#21be2b"
                        text: "0"
                    }
                }
            }

            //***************************************************************
            //***************************************************************

            MFrame{ // Motor6
                width: parent.width * 1/3
                height: parent.height
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 2
                    spacing: 0
                    Label{
                        width: parent.width * 1/2
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameCartesian[5] + "</b>"
                        color: "#21be2b"
                    }

                    TextInput {
                        id: mTextField6_cartesian
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#21be2b"
                        text: "0"
                    }
                }
            }
        }

        //***************************************************************
        //***************************************************************


        Grid{ // End Buttons

            width: parent.width * 0.98
            height: parent.height * 0.25
            columns: 2
            spacing: 12

            MButton{
                _width: parent.width * 0.5
                _height:parent.height
                _text:"Move All"
                onBtnClick: {
                    if(_joint){
                    positionviewmodel.setPosition( mTextField1.text,0)
                    positionviewmodel.setPosition( mTextField2.text,1)
                    positionviewmodel.setPosition( mTextField3.text,2)
                    positionviewmodel.setPosition( mTextField4.text,3)
                    positionviewmodel.setPosition( mTextField5.text,4)
                    positionviewmodel.setPosition( mTextField6.text,5)
                    }
                    else
                    {
                        positionviewmodel.setPosition( mTextField1_cartesian.text,0)
                        positionviewmodel.setPosition( mTextField2_cartesian.text,1)
                        positionviewmodel.setPosition( mTextField3_cartesian.text,2)
                        positionviewmodel.setPosition( mTextField4_cartesian.text,3)
                        positionviewmodel.setPosition( mTextField5_cartesian.text,4)
                        positionviewmodel.setPosition( mTextField6_cartesian.text,5)
                    }
                    positionviewmodel.TypeOfFrame = cmb_frame.currentText
                    positionviewmodel.MoveAll()
                }

            }
            MButton{
                _width: parent.width * 0.5
                _height: parent.height
                _text:"Go Home"
                onBtnClick: {
                    mTextField1.text = "0"
                    mTextField2.text = "0"
                    mTextField3.text = "0"
                    mTextField4.text = "0"
                    mTextField5.text = "0"
                    mTextField6.text = "0"
                    positionviewmodel.GoHome()
                }

            }
        }
    }

}
