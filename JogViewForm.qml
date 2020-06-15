import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import JogViewModel 1.0

Item {
    property int _width: 255
    property int _height: 75
    property bool _joint: true
    property int _velocity: jogviewmodel.FineVelocity
    property int _acceleration: jogviewmodel.FineAcceleration
    property int _deceleration: jogviewmodel.FineDeceleration
    property var _abcRaio: jogviewmodel.AbcRatio
    property var _current_active_txtbox_obj: null


    property var _nameJoint: ["M1", "M2", "M3", "M4", "M5", "M6"]
    property var _valueJoint: ["1234.1234", "1234.1234", "1234.1234", "1234.1234", "1234.1234", "1234.1234"]


    property var _nameCartesian: ["X", "Y", "Z", "A", "B", "C"]
    property var _valueCartesian: ["25", "4544", "789", "12345", "453642", "4563456"]



    Timer{
        id:timer_actual
        interval: 20; running: true; repeat: true
        onTriggered: {
            //               rightviewmodel.UpdateStatusWord()
            jogviewmodel.UpdateActualPosition()
        }
    }

    JogViewModel{
        id:jogviewmodel
    }
    Component.onCompleted: {
        btnfine._isActive = jogviewmodel.Fine
        control.checked = !jogviewmodel.IsJoint
        _joint = jogviewmodel.IsJoint
        control1.value = jogviewmodel.FineVelocity
        control2.value = jogviewmodel.FineAcceleration
        control3.value = jogviewmodel.FineDeceleration
        _velocity = control1.value
        _acceleration = control2.value
        _deceleration = control3.value
        txtvelocity.text = jogviewmodel.Velocity
        txtacceleration.text = jogviewmodel.Acceleration
        txtdeceleration.text = jogviewmodel.Deceleration
        txtabcratio.text = jogviewmodel.AbcRatio
        cmb_frame.currentIndex = jogviewmodel.CurrentFrame - 1
    }

    Grid{ // main grid
        id:mainGrid
        width: parent.width
        height: parent.height * 9/10
        columns: 1
        rows: 2
        spacing: 5

        Popup {
            id:popupsetting
            //y: settingButton.height - 1
            //width: settingButton.width * 2
            implicitHeight: contentItem.implicitHeight
            //anchors.centerIn: parent
            width: mainGrid.width * 0.75
            height: mainGrid.height + 30
            modal: true
            focus: true
            closePolicy: Popup.CloseOnEscape
            padding: 1
            Rectangle
            {
                anchors.fill: parent
                color: "#002F2F"
            }
            Frame{
                width: parent.width
                height: parent.height
                background: Rectangle {
                    color: "transparent"
                    border.color: "#EFECCA"
                    radius: 2
                }
                Grid{
                    id:mainpopupgrid
                    width: parent.width
                    height: parent.height
                    columns: 1
                    spacing: 2
                    Grid
                    {
                        width: parent.width
                        height: parent.height * 0.6
                        columns: 2
                        spacing: 2
                        // usual jog setting
                        MFrame{
                            width: parent.width * 0.5
                            height: parent.height

                            Grid
                            {
                                width: parent.width
                                height: parent.height
                                columns: 2
                                Label{
                                    width: parent.width * 0.5
                                    height: 55
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    text:_joint? "<b> Velocity(deg/sec) </b>": "<b> Velocity(mm/sec) </b>"
                                    color: "#EFECCA"
                                }

                                TextInput {
                                    id: txtvelocity
                                    width: parent.width * 0.5
                                    height: 55
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "#EFECCA"
                                    text: jogviewmodel.Velocity
                                    onActiveFocusChanged:
                                    {
                                        _current_active_txtbox_obj=txtvelocity
                                        my_keyboard._writen_txt=txtvelocity.text;
                                        if(my_keyboard._writen_txt=="0")
                                            my_keyboard._writen_txt=""
                                        keyboardPopup.open()
                                    }
                                }
                                Label{
                                    width: parent.width * 0.5
                                    height: 55
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    text:_joint? "<b> Acc(deg/sec^2) </b>": "<b> Acc(mm/sec^2) </b>"
                                    color: "#EFECCA"

                                }

                                TextInput {
                                    id: txtacceleration
                                    width: parent.width * 0.5
                                    height: 55
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "#EFECCA"
                                    text: jogviewmodel.Acceleration
                                    onActiveFocusChanged:
                                    {
                                        _current_active_txtbox_obj=txtacceleration
                                        my_keyboard._writen_txt=txtacceleration.text;
                                        if(my_keyboard._writen_txt=="0")
                                            my_keyboard._writen_txt=""
                                        keyboardPopup.open()
                                    }
                                }
                                Label{
                                    width: parent.width * 0.5
                                    height: 55
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    text:_joint? "<b> Dcc(deg/sec^2) </b>": "<b> Dcc(mm/sec^2) </b>"
                                    color: "#EFECCA"
                                }

                                TextInput {
                                    id: txtdeceleration
                                    width: parent.width * 0.5
                                    height: 55
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "#EFECCA"
                                    text: jogviewmodel.Deceleration
                                    onActiveFocusChanged:
                                    {
                                        _current_active_txtbox_obj=txtdeceleration
                                        my_keyboard._writen_txt=txtdeceleration.text;
                                        if(my_keyboard._writen_txt=="0")
                                            my_keyboard._writen_txt=""
                                        keyboardPopup.open()
                                    }
                                }
                            }
                        }
                        //fine jog setting
                        MFrame{
                            width: parent.width * 0.5
                            height: parent.height
                            Grid
                            {
                                width: parent.width
                                height: parent.height
                                columns: 2

                                //fine jog velocity
                                Label{
                                    padding: 2
                                    text: "<b>Fine Velocity</b>"
                                    width: parent.width * 0.55
                                    height: 55
                                    color: "#EFECCA"
                                    verticalAlignment: Text.AlignVCenter
                                    horizontalAlignment: Text.AlignLeft
                                }


                                Slider {
                                    id: control1
                                    width: parent.width * 0.45
                                    height: 55
                                    from: 5
                                    value: jogviewmodel.FineVelocity
                                    to: 100
                                    //stepSize: 20
                                    onMoved: {
                                        _velocity = control1.value
                                        //jogviewmodel.FineVelocity = control1.value
                                        //rightviewmodel.FeedOverRide = _feed / 100.0
                                    }

                                    background: Rectangle {
                                        x: control1.leftPadding
                                        y: control1.topPadding + control1.availableHeight / 2 - height / 2
                                        implicitWidth: 200
                                        implicitHeight: 4
                                        width: control1.availableWidth
                                        height: implicitHeight
                                        radius: 2
                                        color: "#bdbebf"

                                        Rectangle {
                                            width: control1.visualPosition * parent.width
                                            height: parent.height
                                            color: "#EFECCA"
                                            radius: 2

                                        }
                                    }

                                    handle: Rectangle {
                                        x: control1.leftPadding + control1.visualPosition * (control1.availableWidth - width)
                                        y: control1.topPadding + control1.availableHeight / 2 - height / 2
                                        implicitWidth: 48
                                        implicitHeight: 48
                                        radius: 25
                                        color: control1.pressed ? "#A7A37E" : "#046380"
                                        Text {
                                            text: " "+_velocity + " % "
                                            font.pixelSize: 15
                                            anchors.verticalCenter: parent.verticalCenter
                                            anchors.horizontalCenter: parent.horizontalCenter
                                            horizontalAlignment: Text.AlignHCenter
                                            verticalAlignment: Text.AlignVCenter
                                            color: "#EFECCA"
                                        }
                                        border.color: "#046380"
                                    }
                                }

                                // fine jog acceleration
                                Label{
                                    padding: 2
                                    text: "<b>Fine Acceleration</b>"
                                    width: parent.width * 0.55
                                    height: 55
                                    color: "#EFECCA"
                                    verticalAlignment: Text.AlignVCenter
                                    horizontalAlignment: Text.AlignLeft
                                }
                                Slider {
                                    id: control2
                                    width: parent.width * 0.45
                                    height: 55
                                    from: 5
                                    value: jogviewmodel.FineAcceleration
                                    to: 100
                                    //stepSize: 20
                                    onMoved: {
                                        _acceleration = control2.value
                                        //jogviewmodel.FineAcceleration = control2.value
                                        //rightviewmodel.FeedOverRide = _feed / 100.0
                                    }

                                    background: Rectangle {
                                        x: control2.leftPadding
                                        y: control2.topPadding + control2.availableHeight / 2 - height / 2
                                        implicitWidth: 200
                                        implicitHeight: 4
                                        width: control2.availableWidth
                                        height: implicitHeight
                                        radius: 2
                                        color: "#bdbebf"

                                        Rectangle {
                                            width: control2.visualPosition * parent.width
                                            height: parent.height
                                            color: "#EFECCA"
                                            radius: 2

                                        }
                                    }

                                    handle: Rectangle {
                                        x: control2.leftPadding + control2.visualPosition * (control2.availableWidth - width)
                                        y: control2.topPadding + control2.availableHeight / 2 - height / 2
                                        implicitWidth: 48
                                        implicitHeight: 48
                                        radius: 25
                                        color: control2.pressed ? "#A7A37E" : "#046380"
                                        Text {
                                            text: " "+_acceleration + " % "
                                            font.pixelSize: 15
                                            anchors.verticalCenter: parent.verticalCenter
                                            anchors.horizontalCenter: parent.horizontalCenter
                                            horizontalAlignment: Text.AlignHCenter
                                            verticalAlignment: Text.AlignVCenter
                                            color: "#EFECCA"
                                        }
                                        border.color: "#046380"
                                    }
                                }
                                //fine jog deceleration
                                Label{
                                    padding: 2
                                    text: "<b>Fine Deceleration</b>"
                                    width: parent.width * 0.55
                                    height: 55
                                    color: "#EFECCA"
                                    verticalAlignment: Text.AlignVCenter
                                    horizontalAlignment: Text.AlignLeft
                                }
                                Slider {
                                    id: control3
                                    width: parent.width * 0.45
                                    height: 55
                                    from: 5
                                    value: jogviewmodel.FineDeceleration
                                    to: 100
                                    //stepSize: 20
                                    onMoved: {
                                        _deceleration = control3.value
                                        //jogviewmodel.FineDeceleration = control3.value
                                        //rightviewmodel.FeedOverRide = _feed / 100.0
                                    }

                                    background: Rectangle {
                                        x: control3.leftPadding
                                        y: control3.topPadding + control3.availableHeight / 2 - height / 2
                                        implicitWidth: 200
                                        implicitHeight: 4
                                        width: control3.availableWidth
                                        height: implicitHeight
                                        radius: 2
                                        color: "#bdbebf"

                                        Rectangle {
                                            width: control3.visualPosition * parent.width
                                            height: parent.height
                                            color: "#EFECCA"
                                            radius: 2

                                        }
                                    }

                                    handle: Rectangle {
                                        x: control3.leftPadding + control3.visualPosition * (control3.availableWidth - width)
                                        y: control3.topPadding + control3.availableHeight / 2 - height / 2
                                        implicitWidth: 48
                                        implicitHeight: 48
                                        radius: 25
                                        color: control3.pressed ? "#A7A37E" : "#046380"
                                        Text {
                                            text: " "+_deceleration + " % "
                                            font.pixelSize: 15
                                            anchors.verticalCenter: parent.verticalCenter
                                            anchors.horizontalCenter: parent.horizontalCenter
                                            horizontalAlignment: Text.AlignHCenter
                                            verticalAlignment: Text.AlignVCenter
                                            color: "#EFECCA"
                                        }
                                        border.color: "#046380"
                                    }
                                }

                            }
                        }
                    }
                    Label // empty
                    {
                        visible:_joint
                        width: parent.width
                        height: parent.height * 0.10
                    }
                    Grid
                    {
                        visible:!_joint
                        width: parent.width
                        height: parent.height * 0.10
                        columns: 2
                        Label{
                            width: parent.width * 0.5
                            height: parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            text: "<b> ABC Ratio </b>"
                            color: "#EFECCA"
                        }

                        TextInput {
                            id: txtabcratio
                            width: parent.width * 0.5
                            height: parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#EFECCA"
                            text: jogviewmodel.AbcRatio
                        }

                    }

                    Grid{
                        width: parent.width
                        height: parent.height * 0.30
                        spacing: 4
                        columns: 1
                        MButton{
                            id:setbtn
                            _width: parent.width
                            _height: 48
                            _text:"set"
                            onBtnClick: {
                                jogviewmodel.FineVelocity = control1.value
                                jogviewmodel.FineAcceleration = control2.value
                                jogviewmodel.FineDeceleration = control3.value
                                jogviewmodel.Velocity = parseInt(txtvelocity.text)
                                jogviewmodel.Acceleration = parseInt(txtacceleration.text)
                                jogviewmodel.Deceleration = parseInt(txtdeceleration.text)
                                jogviewmodel.AbcRatio = parseInt(txtabcratio.text)
                                popupsetting.close()
                            }
                        }
                        MButton{
                            id:cancelbtn
                            _width: parent.width
                            _height: 48
                            _text:"cancel"
                            onBtnClick: {
                                control1.value = jogviewmodel.FineVelocity
                                control2.value = jogviewmodel.FineAcceleration
                                control3.value = jogviewmodel.FineDeceleration
                                _velocity = control1.value
                                _acceleration = control2.value
                                _deceleration = control3.value
                                txtvelocity.text = jogviewmodel.Velocity
                                txtacceleration.text = jogviewmodel.Acceleration
                                txtdeceleration.text = jogviewmodel.Deceleration
                                txtabcratio.text = jogviewmodel.AbcRatio
                                popupsetting.close()
                            }
                        }
                    }
                }


            }

            background: Rectangle {
                border.color: "#EFECCA"
                radius: 5
            }
        }

        Grid{
            id:mainGridRow1
            width: parent.width
            height: parent.height * 0.15
            columns: 4
            spacing: 5


            // switch button
            Switch {
                id: control
                text:control.checked ? qsTr("Cartesian") : qsTr("Joint")
                width: parent.width * 0.25
                height: parent.height
                onClicked: {
                    _joint = ! _joint
                    jogviewmodel.IsJoint = !jogviewmodel.IsJoint
                    control1.value = jogviewmodel.FineVelocity
                    control2.value = jogviewmodel.FineAcceleration
                    control3.value = jogviewmodel.FineDeceleration
                    _velocity = control1.value
                    _acceleration = control2.value
                    _deceleration = control3.value
                    txtvelocity.text = jogviewmodel.Velocity
                    txtacceleration.text = jogviewmodel.Acceleration
                    txtdeceleration.text = jogviewmodel.Deceleration
                }
                indicator: Rectangle {
                    implicitWidth: 48
                    implicitHeight: 26
                    x: control.leftPadding
                    y: parent.height / 2 - height / 2
                    radius: 13
                    border.color: control.checked ? "#046380" : "#cccccc"
                    color: "#002F2F"

                    Rectangle {
                        x: control.checked ? parent.width - width : 0
                        width: 26
                        height: 26
                        radius: 13
                        color: "#046380"
                        border.color: control.checked ? (control.down ? "#046380" : "#EFECCA") : "#999999"
                    }
                }

                contentItem: Text {
                    text: control.text
                    font: control.font
                    opacity: enabled ? 1.0 : 0.3
                    color: control.down ? "#046380" : "#EFECCA"
                    verticalAlignment: Text.AlignVCenter
                    leftPadding: control.indicator.width + control.spacing
                }
            }


            Label{
                width: parent.width * 0.25
                height: parent.height
                visible: _joint
            }

            Grid //Select Frame Grid
            {
                width: parent.width * 0.25
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
                        color: "#EFECCA"
                    }
                }

                //**********************************************

                ComboBox {
                    id: cmb_frame
                    height: parent.height
                    width: parent.width * 2/3
                    model: ["world","base","task","object","tool"]

                    delegate: ItemDelegate {
                        width: cmb_frame.width
                        contentItem: Text {
                            text: modelData
                            color: "#EFECCA"
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
                            context.fillStyle = cmb_frame.pressed ? "#046380" : "#EFECCA";
                            context.fill();
                        }
                    }

                    contentItem: Text {
                        leftPadding: 10
                        rightPadding: cmb_frame.indicator.width + cmb_frame.spacing

                        text: cmb_frame.displayText
                        font: cmb_frame.font
                        color: cmb_frame.pressed ? "#046380" : "#EFECCA"
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 40
                        border.color: cmb_frame.pressed ? "#046380" : "#EFECCA"
                        border.width: cmb_frame.visualFocus ? 2 : 1
                        color: "#046380"
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
                            border.color: "#EFECCA"
                            color: "#046380"
                            radius: 5
                        }
                    }

                    onCurrentIndexChanged:
                    {

                    }
                    onActivated:
                    {
                       jogviewmodel.CurrentFrame = cmb_frame.currentIndex + 1
                    }
                }


            }
            MButton{
                id:btnfine
                _width: parent.width * 0.25
                _height: parent.height
                _text:"fine"
                onBtnClick: {
                    jogviewmodel.Fine = !jogviewmodel.Fine
                    _isActive = jogviewmodel.Fine
                    jogviewmodel.FineVelocity = control1.value
                    jogviewmodel.FineAcceleration = control2.value
                    jogviewmodel.FineDeceleration = control3.value
                    jogviewmodel.Velocity = parseInt(txtvelocity.text)
                    jogviewmodel.Acceleration = parseInt(txtacceleration.text)
                    jogviewmodel.Deceleration = parseInt(txtdeceleration.text)
                }
            }
            MButton{
                id:settingButton
                _width: parent.width * 0.25 - 10
                _height: parent.height
                _text:"setting"
                onBtnClick: {
                    popupsetting.open()
                }
            }

        }



        //********************************************************
        //********************************************************

        Grid{
            id:mainGridRow2
            width: parent.width
            height: parent.height
            columns: 2
            spacing: 5
            //Joint
            MFrame{ // Motor1
                width: parent.width * 0.5
                height: parent.height * 0.25
                visible: _joint
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 4
                    spacing: 0
                    Label{
                        width: parent.width * 0.15
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameJoint[0] + "</b>"
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"-"
                        onBtnPress: {
                            jogviewmodel.jogJoint(0,0,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogJoint(0,0,0)
                        }
                    }

                    Label{
                        width: parent.width * 0.55
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: jogviewmodel.ActualPosition[0].toFixed(3)
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"+"
                        onBtnPress: {
                            jogviewmodel.jogJoint(1,0,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogJoint(1,0,0)
                        }
                    }
                }
            }

            //************************************************************************
            //************************************************************************


            MFrame{ // Motor2
                width: parent.width * 0.5
                height: parent.height * 0.25
                visible: _joint
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 4
                    spacing: 0
                    Label{
                        width: parent.width * 0.15
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameJoint[1] + "</b>"
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"-"
                        onBtnPress: {
                            jogviewmodel.jogJoint(0,1,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogJoint(0,1,0)
                        }
                    }

                    Label{
                        width: parent.width * 0.55
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: jogviewmodel.ActualPosition[1].toFixed(3)
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"+"
                        onBtnPress: {
                            jogviewmodel.jogJoint(1,1,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogJoint(1,1,0)
                        }
                    }
                }
            }

            //************************************************************************
            //************************************************************************


            MFrame{ // Motor3
                width: parent.width * 0.5
                height: parent.height * 0.25
                visible: _joint
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 4
                    spacing: 0
                    Label{
                        width: parent.width * 0.15
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameJoint[2] + "</b>"
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"-"
                        onBtnPress: {
                            jogviewmodel.jogJoint(1,2,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogJoint(1,2,0)
                        }
                    }

                    Label{
                        width: parent.width * 0.55
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: jogviewmodel.ActualPosition[2].toFixed(3)
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"+"
                        onBtnPress: {
                            jogviewmodel.jogJoint(0,2,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogJoint(0,2,0)
                        }
                    }
                }
            }

            //************************************************************************
            //************************************************************************


            MFrame{ // Motor4
                width: parent.width * 0.5
                height: parent.height * 0.25
                visible: _joint
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 4
                    spacing: 0
                    Label{
                        width: parent.width * 0.15
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameJoint[3] + "</b>"
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"-"
                        onBtnPress: {
                            jogviewmodel.jogJoint(0,3,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogJoint(0,3,0)
                        }
                    }

                    Label{
                        width: parent.width * 0.55
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: jogviewmodel.ActualPosition[3].toFixed(3)
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"+"
                        onBtnPress: {
                            jogviewmodel.jogJoint(1,3,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogJoint(1,3,0)
                        }
                    }
                }
            }

            //************************************************************************
            //************************************************************************


            MFrame{ // Motor5
                width: parent.width * 0.5
                height: parent.height * 0.25
                visible: _joint
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 4
                    spacing: 0
                    Label{
                        width: parent.width * 0.15
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameJoint[4] + "</b>"
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"-"
                        onBtnPress: {
                            jogviewmodel.jogJoint(0,4,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogJoint(0,4,0)
                        }
                    }

                    Label{
                        width: parent.width * 0.55
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: jogviewmodel.ActualPosition[4].toFixed(3)
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"+"
                        onBtnPress: {
                            jogviewmodel.jogJoint(1,4,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogJoint(1,4,0)
                        }
                    }
                }
            }

            //************************************************************************
            //************************************************************************


            MFrame{ // Motor6
                width: parent.width * 0.5
                height: parent.height * 0.25
                visible: _joint
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 4
                    spacing: 0
                    Label{
                        width: parent.width * 0.15
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameJoint[5] + "</b>"
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"-"
                        onBtnPress: {
                            jogviewmodel.jogJoint(1,5,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogJoint(1,5,0)
                        }
                    }

                    Label{
                        width: parent.width * 0.55
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: jogviewmodel.ActualPosition[5].toFixed(3)
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"+"
                        onBtnPress: {
                            jogviewmodel.jogJoint(0,5,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogJoint(0,5,0)
                        }
                    }
                }
            }


            //************************************************************************
            //************************************************************************
            //************************************************************************
            //************************************************************************


            //Cartesian
            MFrame{ //Motor1
                width: parent.width * 0.5
                height: parent.height * 0.25
                visible: !_joint
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 4
                    spacing: 0
                    Label{
                        width: parent.width * 0.15
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameCartesian[0] + "</b>"
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"-"
                        onBtnPress: {
                            jogviewmodel.jogCart(0,0,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogCart(0,0,0)
                        }
                    }

                    Label{
                        width: parent.width * 0.55
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text:  jogviewmodel.ActualPosition[0].toFixed(3)
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"+"
                        onBtnPress: {
                            jogviewmodel.jogCart(1,0,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogCart(1,0,0)
                        }
                    }
                }
            }

            //************************************************************************
            //************************************************************************


            MFrame{//Motor2
                width: parent.width * 0.5
                height: parent.height * 0.25
                visible: !_joint
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 4
                    spacing: 0
                    Label{
                        width: parent.width * 0.15
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameCartesian[1] + "</b>"
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"-"
                        onBtnPress: {
                            jogviewmodel.jogCart(0,1,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogCart(0,1,0)
                        }
                    }

                    Label{
                        width: parent.width * 0.55
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: jogviewmodel.ActualPosition[1].toFixed(3)
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"+"
                        onBtnPress: {
                            jogviewmodel.jogCart(1,1,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogCart(1,1,0)
                        }
                    }
                }
            }

            //************************************************************************
            //************************************************************************


            MFrame{//Motor3
                width: parent.width * 0.5
                height: parent.height * 0.25
                visible: !_joint
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 4
                    spacing: 0
                    Label{
                        width: parent.width * 0.15
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameCartesian[2] + "</b>"
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"-"
                        onBtnPress: {
                            jogviewmodel.jogCart(0,2,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogCart(0,2,0)
                        }
                    }

                    Label{
                        width: parent.width * 0.55
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: jogviewmodel.ActualPosition[2].toFixed(3)
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"+"
                        onBtnPress: {
                            jogviewmodel.jogCart(1,2,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogCart(1,2,0)
                        }
                    }
                }
            }

            //************************************************************************
            //************************************************************************


            MFrame{ //Motor4
                width: parent.width * 0.5
                height: parent.height * 0.25
                visible: !_joint
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 4
                    spacing: 0
                    Label{
                        width: parent.width * 0.15
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameCartesian[3] + "</b>"
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"-"
                        onBtnPress: {
                            jogviewmodel.jogCart(0,3,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogCart(0,3,0)
                        }
                    }

                    Label{
                        width: parent.width * 0.55
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: jogviewmodel.ActualPosition[3].toFixed(3)
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"+"
                        onBtnPress: {
                            jogviewmodel.jogCart(1,3,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogCart(1,3,0)
                        }
                    }
                }
            }

            //************************************************************************
            //************************************************************************


            MFrame{//Motor5
                width: parent.width * 0.5
                height: parent.height * 0.25
                visible: !_joint
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 4
                    spacing: 0
                    Label{
                        width: parent.width * 0.15
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameCartesian[4] + "</b>"
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"-"
                        onBtnPress: {
                            jogviewmodel.jogCart(0,4,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogCart(0,4,0)
                        }
                    }

                    Label{
                        width: parent.width * 0.55
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: jogviewmodel.ActualPosition[4].toFixed(3)
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"+"
                        onBtnPress: {
                            jogviewmodel.jogCart(1,4,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogCart(1,4,0)
                        }
                    }
                }
            }

            //************************************************************************
            //************************************************************************


            MFrame{//Motor6
                width: parent.width * 0.5
                height: parent.height * 0.25
                visible: !_joint
                Grid{
                    width: parent.width
                    height: parent.height
                    columns: 4
                    spacing: 0
                    Label{
                        width: parent.width * 0.15
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: "<b>" + _nameCartesian[5] + "</b>"
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"-"
                        onBtnPress: {
                            jogviewmodel.jogCart(0,5,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogCart(0,5,0)
                        }
                    }

                    Label{
                        width: parent.width * 0.55
                        height: parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text:  jogviewmodel.ActualPosition[5].toFixed(3)
                        color: "#EFECCA"
                    }
                    MButton{
                        _width: parent.width * 0.15
                        _height: parent.height
                        _text:"+"
                        onBtnPress: {
                            jogviewmodel.jogCart(1,5,1)
                        }
                        onBtnReleased: {
                            jogviewmodel.jogCart(1,5,0)
                        }
                    }
                }
            }

            //************************************************************************
            //************************************************************************

        }

    }


    //**************************************************
    //**************************************************


    Popup
    {
        id: keyboardPopup
        //anchors.centerIn: parent
        modal: true
        focus: true
        closePolicy: Popup.NoAutoClose
        background: Rectangle {
            visible: true
            color: "#002F2F"
        }
        ColumnLayout
        {
            anchors.fill: parent
            KeyBoard
            {
                id:my_keyboard
            }
            Rectangle
            {
                width: parent.width
                height:25
                color: "transparent"
            }

            MButton
            {
                _text: "ok"
                anchors.horizontalCenter: parent.horizontalCenter
                onBtnClick:
                {
                    _current_active_txtbox_obj.focus=false
                    _current_active_txtbox_obj.text=my_keyboard._writen_txt
                    keyboardPopup.close()
                }
            }
        }
    }
}

