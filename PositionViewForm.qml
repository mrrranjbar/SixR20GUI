import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import PositionViewModel 1.0

Item {

    id:mainitem
    property int _width: 260
    property int _height: 75
    property bool _joint: true
    property var _current_active_txtbox_obj: null
    property var _nameJoint: ["M1", "M2", "M3", "M4", "M5", "M6"]
    property var _nameCartesian: ["X", "Y", "Z", "A", "B", "C"]


    PositionViewModel
    {
        id:positionviewmodel
    }

    Component.onCompleted: {
        btnptp._isActive = positionviewmodel.IsPTP
        control.checked = !positionviewmodel.IsJoint
        _joint = positionviewmodel.IsJoint
    }

    Grid{ // main Grid
        id:mainGrid
        width: parent.width
        height: parent.height * 0.95
        rows: 4
        spacing: 5


        Popup {
            id:popupsetting
            //y: settingButton.height - 1
            //width: settingButton.width * 2
            implicitHeight: contentItem.implicitHeight
            //anchors.centerIn: parent
            width: mainGrid.width * 0.5
            height: mainGrid.height
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
                        height: parent.height * 0.3
                        columns: 1
                        spacing: 2
                        // velocity setting
                        MFrame{
                            width: parent.width
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
                                    text:
                                    {
                                        if(positionviewmodel.IsJoint)
                                            "<b> Velocity(deg/sec) </b>"
                                        else
                                            positionviewmodel.IsPTP ? "<b> Velocity(deg/sec) </b>":"<b> Velocity(mm/sec) </b>"
                                    }
                                    color: "#EFECCA"
                                }

                                TextInput {
                                    id: txtvelocity
                                    width: parent.width * 0.5
                                    height: 55
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "#EFECCA"
                                    text: positionviewmodel.Velocity

                                    onActiveFocusChanged:
                                    {
                                        _current_active_txtbox_obj=txtvelocity
                                        my_keyboard._writen_txt=txtvelocity.text;
                                        if(my_keyboard._writen_txt=="0")
                                            my_keyboard._writen_txt=""
                                        keyboardPopup.open()
                                    }
                                }
//                                Label{
//                                    width: parent.width * 0.5
//                                    height: 55
//                                    horizontalAlignment: Text.AlignHCenter
//                                    verticalAlignment: Text.AlignVCenter
//                                    text: "<b> Acceleration </b>"
//                                    color: "#EFECCA"
//                                }

//                                TextInput {
//                                    id: txtacceleration
//                                    width: parent.width * 0.5
//                                    height: 55
//                                    horizontalAlignment: Text.AlignHCenter
//                                    verticalAlignment: Text.AlignVCenter
//                                    color: "#EFECCA"
//                                    text: "0"//jogviewmodel.Acceleration
//                                }
//                                Label{
//                                    width: parent.width * 0.5
//                                    height: 55
//                                    horizontalAlignment: Text.AlignHCenter
//                                    verticalAlignment: Text.AlignVCenter
//                                    text: "<b> Deceleration </b>"
//                                    color: "#EFECCA"
//                                }

//                                TextInput {
//                                    id: txtdeceleration
//                                    width: parent.width * 0.5
//                                    height: 55
//                                    horizontalAlignment: Text.AlignHCenter
//                                    verticalAlignment: Text.AlignVCenter
//                                    color: "#EFECCA"
//                                    text:"0" //jogviewmodel.Deceleration
//                                }
                            }
                        }

                    }
                    Label // empty
                    {
                        width: parent.width
                        height: parent.height * 0.37
                    }

                    Grid{
                        width: parent.width
                        height: parent.height * 0.33
                        spacing: 4
                        columns: 1
                        MButton{
                            id:setbtn
                            _width: parent.width
                            _height: 48
                            _text:"set"
                            onBtnClick: {
                                positionviewmodel.Velocity = parseInt(txtvelocity.text)
                                popupsetting.close()
                            }
                        }
                        MButton{
                            id:cancelbtn
                            _width: parent.width
                            _height: 48
                            _text:"cancel"
                            onBtnClick: {
                                txtvelocity.text = positionviewmodel.Velocity
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




        Grid // Top grid
        {
            width: parent.width * 0.98
            height: parent.height * 0.15
            columns: 4
            spacing: 5

            //***************************************************************
            //***************************************************************


            // switch button
            Switch {
                id: control
                text:control.checked ? qsTr("Cartesian") : qsTr("Joint")
                width: parent.width * 0.25
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
            //********************************************************
            //********************************************************



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
                    model: ["object","task","tool","world","base"]

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
                }


            }

            MButton{
                id:btnptp
                _width: parent.width * 0.25
                _height: parent.height
                _text:"PTP"
                onBtnClick: {
                    positionviewmodel.IsPTP = !positionviewmodel.IsPTP
                    _isActive = positionviewmodel.IsPTP
                    positionviewmodel.Velocity = parseInt(txtvelocity.text)
                }
            }
            MButton{
                id:btnsetting
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
                        color: "#EFECCA"
                    }

                    TextInput {
                        id: mTextField1
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#EFECCA"
                        text: positionviewmodel.Positions[0]

                        onActiveFocusChanged:
                        {
                            _current_active_txtbox_obj=mTextField1
                            my_keyboard._writen_txt=mTextField1.text;
                            if(my_keyboard._writen_txt=="0")
                                my_keyboard._writen_txt=""
                            keyboardPopup.open()
                        }
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
                        color: "#EFECCA"
                    }

                    TextInput {
                        id: mTextField2
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#EFECCA"
                        text: positionviewmodel.Positions[1]

                        onActiveFocusChanged:
                        {
                            _current_active_txtbox_obj=mTextField2
                            my_keyboard._writen_txt=mTextField2.text;
                            if(my_keyboard._writen_txt=="0")
                                my_keyboard._writen_txt=""
                            keyboardPopup.open()
                        }
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
                        color: "#EFECCA"
                    }

                    TextInput {
                        id: mTextField3
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#EFECCA"
                        text: positionviewmodel.Positions[2]

                        onActiveFocusChanged:
                        {
                            _current_active_txtbox_obj=mTextField3
                            my_keyboard._writen_txt=mTextField3.text;
                            if(my_keyboard._writen_txt=="0")
                                my_keyboard._writen_txt=""
                            keyboardPopup.open()
                        }
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
                        color: "#EFECCA"
                    }

                    TextInput {
                        id: mTextField4
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#EFECCA"
                        text: positionviewmodel.Positions[3]

                        onActiveFocusChanged:
                        {
                            _current_active_txtbox_obj=mTextField4
                            my_keyboard._writen_txt=mTextField4.text;
                            if(my_keyboard._writen_txt=="0")
                                my_keyboard._writen_txt=""
                            keyboardPopup.open()
                        }
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
                        color: "#EFECCA"
                    }

                    TextInput {
                        id: mTextField5
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#EFECCA"
                        text: positionviewmodel.Positions[4]

                        onActiveFocusChanged:
                        {
                            _current_active_txtbox_obj=mTextField5
                            my_keyboard._writen_txt=mTextField5.text;
                            if(my_keyboard._writen_txt=="0")
                                my_keyboard._writen_txt=""
                            keyboardPopup.open()
                        }
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
                        color: "#EFECCA"
                    }

                    TextInput {
                        id: mTextField6
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#EFECCA"
                        text: positionviewmodel.Positions[5]

                        onActiveFocusChanged:
                        {
                            _current_active_txtbox_obj=mTextField6
                            my_keyboard._writen_txt=mTextField6.text;
                            if(my_keyboard._writen_txt=="0")
                                my_keyboard._writen_txt=""
                            keyboardPopup.open()
                        }
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
                        color: "#EFECCA"
                    }

                    TextInput {
                        id: mTextField1_cartesian
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#EFECCA"
                        text: positionviewmodel.CartPositions[0]

                        onActiveFocusChanged:
                        {
                            _current_active_txtbox_obj=mTextField1_cartesian
                            my_keyboard._writen_txt=mTextField1_cartesian.text;
                            if(my_keyboard._writen_txt=="0")
                                my_keyboard._writen_txt=""
                            keyboardPopup.open()
                        }
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
                        color: "#EFECCA"
                    }

                    TextInput {
                        id: mTextField2_cartesian
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#EFECCA"
                        text: positionviewmodel.CartPositions[1]

                        onActiveFocusChanged:
                        {
                            _current_active_txtbox_obj=mTextField2_cartesian
                            my_keyboard._writen_txt=mTextField2_cartesian.text;
                            if(my_keyboard._writen_txt=="0")
                                my_keyboard._writen_txt=""
                            keyboardPopup.open()
                        }
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
                        color: "#EFECCA"
                    }

                    TextInput {
                        id: mTextField3_cartesian
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#EFECCA"
                        text: positionviewmodel.CartPositions[2]

                        onActiveFocusChanged:
                        {
                            _current_active_txtbox_obj=mTextField3_cartesian
                            my_keyboard._writen_txt=mTextField3_cartesian.text;
                            if(my_keyboard._writen_txt=="0")
                                my_keyboard._writen_txt=""
                            keyboardPopup.open()
                        }
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
                        color: "#EFECCA"
                    }

                    TextInput {
                        id: mTextField4_cartesian
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#EFECCA"
                        text: positionviewmodel.CartPositions[3]

                        onActiveFocusChanged:
                        {
                            _current_active_txtbox_obj=mTextField4_cartesian
                            my_keyboard._writen_txt=mTextField4_cartesian.text;
                            if(my_keyboard._writen_txt=="0")
                                my_keyboard._writen_txt=""
                            keyboardPopup.open()
                        }
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
                        color: "#EFECCA"
                    }

                    TextInput {
                        id: mTextField5_cartesian
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#EFECCA"
                        text: positionviewmodel.CartPositions[4]

                        onActiveFocusChanged:
                        {
                            _current_active_txtbox_obj=mTextField5_cartesian
                            my_keyboard._writen_txt=mTextField5_cartesian.text;
                            if(my_keyboard._writen_txt=="0")
                                my_keyboard._writen_txt=""
                            keyboardPopup.open()
                        }
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
                        color: "#EFECCA"
                    }

                    TextInput {
                        id: mTextField6_cartesian
                        width: parent.width * 1/2
                        height:parent.height
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        color: "#EFECCA"
                        text: positionviewmodel.CartPositions[5]

                        onActiveFocusChanged:
                        {
                            _current_active_txtbox_obj=mTextField6_cartesian
                            my_keyboard._writen_txt=mTextField6_cartesian.text;
                            if(my_keyboard._writen_txt=="0")
                                my_keyboard._writen_txt=""
                            keyboardPopup.open()
                        }
                    }
                }
            }
        }

        //***************************************************************
        //***************************************************************


        Grid{ // End Buttons

            width: parent.width * 0.98
            height: parent.height * 0.25
            columns: 1
            spacing: 12

            MButton{
                _width: parent.width * 0.25
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
                        positionviewmodel.setCartPositions( mTextField1_cartesian.text,0)
                        positionviewmodel.setCartPositions( mTextField2_cartesian.text,1)
                        positionviewmodel.setCartPositions( mTextField3_cartesian.text,2)
                        positionviewmodel.setCartPositions( mTextField4_cartesian.text,3)
                        positionviewmodel.setCartPositions( mTextField5_cartesian.text,4)
                        positionviewmodel.setCartPositions( mTextField6_cartesian.text,5)
                    }
                    positionviewmodel.TypeOfFrame = cmb_frame.currentText
                    positionviewmodel.MoveAll()
                }

            }
//            MButton{
//                _width: parent.width * 0.25
//                _height: parent.height
//                _text:"Go Home"
//                onBtnClick: {
//                    mTextField1.text = "0"
//                    mTextField2.text = "0"
//                    mTextField3.text = "0"
//                    mTextField4.text = "0"
//                    mTextField5.text = "0"
//                    mTextField6.text = "0"
//                    mTextField1_cartesian.text = "0"
//                    mTextField2_cartesian.text = "0"
//                    mTextField3_cartesian.text = "0"
//                    mTextField4_cartesian.text = "0"
//                    mTextField5_cartesian.text = "0"
//                    mTextField6_cartesian.text = "0"
//                    positionviewmodel.GoHome()
//                }

//            }
//            MButton{
//                _width: parent.width * 0.25
//                _height: parent.height
//                _text:"Clear Alarm"
//                onBtnClick: {
//                    positionviewmodel.ClearAlarms()
//                }

//            }
//            MButton{
//                _width: parent.width * 0.25 - 25
//                _height: parent.height
//                _text:"Run Motors"
//                onBtnClick: {
//                    positionviewmodel.RunMotors()
//                }

//            }
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
