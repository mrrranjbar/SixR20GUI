import QtQuick 2.7
import QtQuick.Controls 2.2
import VelocityAccelerationViewModel 1.0;
import QtQuick.Layouts 1.3
Item {
    property int jogMaxVelocity: velaccviewmodel.JogMaxVelocity
    property int jogMaxAcceleration: velaccviewmodel.JogMaxAcceleration
    property int jogMaxDeceleration: velaccviewmodel.JogMaxDeceleration
    property string _base2: "000"
    property string _confirm_Action: ""
    property int _confirm_what: 0
    property var _current_active_txtbox_obj: null
    VelocityAccelerationViewModel
    {
        id: velaccviewmodel
    }

    Component.onCompleted:
    {
        var base2=['0-0-0','0-0-1','0-1-0','0-1-1','1-0-0','1-0-1','1-1-0','1-1-1']
        _base2=base2[velaccviewmodel.confData]
    }

    MFrame {
        width: parent.width
        height: parent.height * 0.95
        Grid
        { // main Grid
            id:maingrid
            width: parent.width
            height: parent.height
            columns: 1
            spacing: 8
            Grid
            {
                width: parent.width
                height: parent.height * 0.85
                columns: 2
                spacing: 4
                MFrame
                {
                    width: parent.width * 0.5
                    height: parent.height * 0.6
                    Grid
                    {
                        width:parent.width
                        height: parent.height
                        columns: 1

                        Label{
                            width: parent.width
                            height: parent.height * 0.15
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            text: "<b> Configuration & Singul Strategy </b>"
                            color: "#EFECCA"
                        }
                        Grid
                        {
                            width: parent.width
                            height: parent.height * 0.85
                            columns: 2
                            spacing: 2

                            //*************************************************
                            // row 1
                            Label{
                                width: parent.width * 0.5
                                height: parent.height * 0.2
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> ConfJ: </b>"
                                color: "#EFECCA"
                            }

                            Switch
                            {
                                id: confj_switch
                                width: parent.width * 0.5
                                height: parent.height * 0.2
                                checked: velaccviewmodel.confj
//                                onClicked:
//                                {
//                                }
                                indicator: Rectangle {
                                    implicitWidth: 35
                                    implicitHeight: 20
                                    x: confj_switch.leftPadding
                                    y: parent.height / 2 - height / 2
                                    radius: 13
                                    color: confj_switch.checked ? "#046380" : "#ffffff"
                                    border.color: confj_switch.checked ? "#046380" : "#cccccc"

                                    Rectangle {
                                        x: confj_switch.checked ? parent.width - width : 0
                                        width: 20
                                        height: 20
                                        radius: 13
                                        color: confj_switch.down ? "#cccccc" : "#ffffff"
                                        border.color: confj_switch.checked ? (confj_switch.down ? "#046380" : "#EFECCA") : "#046380"
                                    }
                                }
                            }
                            //*************************************************
                            // row 2
                            Label{
                                width: parent.width * 0.5
                                height: parent.height * 0.2
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> ConfData: </b>"
                                color: "#EFECCA"
                            }

                            Row
                            {
                                width: parent.width * 0.5
                                height: parent.height * 0.2

                                //***************************************************
                                //***************************************************
                                ComboBox
                                {
                                    id: cmb_confData
                                    height: parent.height
                                    width: parent.width * 0.5
                                    model: [0,1,2,3,4,5,6,7]
                                    currentIndex: velaccviewmodel.confData
                                    displayText: cmb_confData.currentText
                                    delegate: ItemDelegate {
                                        width: cmb_confData.width
                                        contentItem: Text {
                                            text: modelData
                                            color: "#EFECCA"
                                            font: cmb_confData.font
                                            elide: Text.ElideRight
                                            verticalAlignment: Text.AlignVCenter
                                        }
                                        highlighted: cmb_confData.highlightedIndex === index
                                    }

                                    indicator: Canvas {
                                        id: cmb_confData_canvas
                                        x: cmb_confData.width - width - cmb_confData.rightPadding
                                        y: cmb_confData.topPadding + (cmb_confData.availableHeight - height) / 2
                                        width: 12
                                        height: 8
                                        contextType: "2d"

                                        Connections {
                                            target: cmb_confData
                                            onPressedChanged: cmb_confData_canvas.requestPaint()
                                        }

                                        onPaint: {
                                            context.reset();
                                            context.moveTo(0, 0);
                                            context.lineTo(width, 0);
                                            context.lineTo(width / 2, height);
                                            context.closePath();
                                            context.fillStyle = cmb_confData.pressed ? "#046380" : "#EFECCA";
                                            context.fill();
                                        }
                                    }

                                    contentItem: Text {
                                        leftPadding: 10
                                        rightPadding: cmb_confData.indicator.width + cmb_confData.spacing

                                        text: cmb_confData.displayText
                                        font: cmb_confData.font
                                        color: cmb_confData.pressed ? "#046380" : "#EFECCA"
                                        verticalAlignment: Text.AlignVCenter
                                        elide: Text.ElideRight
                                    }

                                    background: Rectangle {
                                        implicitWidth: 120
                                        implicitHeight: 40
                                        border.color: cmb_confData.pressed ? "#046380" : "#EFECCA"
                                        border.width: cmb_confData.visualFocus ? 2 : 1
                                        color: "#046380"
                                        radius: 2
                                    }

                                    popup: Popup {
                                        y: cmb_confData.height - 1
                                        width: cmb_confData.width
                                        implicitHeight: contentItem.implicitHeight
                                        padding: 1

                                        contentItem: ListView {
                                            clip: true
                                            implicitHeight: contentHeight
                                            model: cmb_confData.popup.visible ? cmb_confData.delegateModel : null
                                            currentIndex: cmb_confData.highlightedIndex

                                            ScrollIndicator.vertical: ScrollIndicator { }
                                        }

                                        background: Rectangle {
                                            border.color: "#EFECCA"
                                            color: "#046380"
                                            radius: 5
                                        }
                                    }
                                    onActivated:{
                                        var base2=['0-0-0','0-0-1','0-1-0','0-1-1','1-0-0','1-0-1','1-1-0','1-1-1']
                                        _base2=base2[cmb_confData.currentIndex]
                                    }
                                }

                                Label
                                {
                                    width: parent.width * 0.5
                                    height: parent.height
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    text: _base2
                                    color: "#EFECCA"
                                }
                            }
                            //*************************************************
                            // row 3
                            Label{
                                width: parent.width * 0.5
                                height: parent.height * 0.2
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Singul PTP: </b>"
                                color: "#EFECCA"
                            }

                            Switch
                            {
                                id: singulPTP_switch
                                width: parent.width * 0.5
                                height: parent.height * 0.2
                                checked: velaccviewmodel.singulPTP
                                indicator: Rectangle {
                                    implicitWidth: 35
                                    implicitHeight: 20
                                    x: singulPTP_switch.leftPadding
                                    y: parent.height / 2 - height / 2
                                    radius: 13
                                    color: singulPTP_switch.checked ? "#046380" : "#ffffff"
                                    border.color: singulPTP_switch.checked ? "#046380" : "#cccccc"

                                    Rectangle {
                                        x: singulPTP_switch.checked ? parent.width - width : 0
                                        width: 20
                                        height: 20
                                        radius: 13
                                        color: singulPTP_switch.down ? "#cccccc" : "#ffffff"
                                        border.color: singulPTP_switch.checked ? (singulPTP_switch.down ? "#046380" : "#EFECCA") : "#046380"
                                    }
                                }
                            }
                            //*************************************************
                            // row 4
                            Label{
                                width: parent.width * 0.5
                                height: parent.height * 0.2
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Singul CP: </b>"
                                color: "#EFECCA"
                            }

                            Switch
                            {
                                id: singulCP_switch
                                width: parent.width * 0.5
                                height: parent.height * 0.2
                                checked: velaccviewmodel.singulCP
                                indicator: Rectangle {
                                    implicitWidth: 35
                                    implicitHeight: 20
                                    x: singulCP_switch.leftPadding
                                    y: parent.height / 2 - height / 2
                                    radius: 13
                                    color: singulCP_switch.checked ? "#046380" : "#ffffff"
                                    border.color: singulCP_switch.checked ? "#046380" : "#cccccc"

                                    Rectangle {
                                        x: singulCP_switch.checked ? parent.width - width : 0
                                        width: 20
                                        height: 20
                                        radius: 13
                                        color: singulCP_switch.down ? "#cccccc" : "#ffffff"
                                        border.color: singulCP_switch.checked ? (singulCP_switch.down ? "#046380" : "#EFECCA") : "#046380"
                                    }
                                }
                            }
                        }

                    }
                }
                MFrame
                {
                    width: parent.width * 0.5
                    height: parent.height * 0.6
                    Grid
                    {
                        width:parent.width
                        height: parent.height
                        columns: 1

                        Label{
                            width: parent.width
                            height: parent.height * 0.15
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            text: "<b> All Moving Functions </b>"
                            color: "#EFECCA"
                        }
                        Grid
                        {
                            width: parent.width
                            height: parent.height * 0.85
                            columns: 3
                            spacing: 2
                            //*************************************************
                            // row 1
                            Rectangle{
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                color: "transparent"
                            }
                            Label{
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> PTP </b>"
                                color: "#EFECCA"
                            }
                            Label{
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> CP </b>"
                                color: "#EFECCA"
                            }
                            //*************************************************
                            // row 2
                            Label{
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Max Velocity: </b>"
                                color: "#EFECCA"
                            }

                            TextInput {
                                id: txtvelocityall_ptp
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: velaccviewmodel.maxVelocityPTP
                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=txtvelocityall_ptp
                                    my_keyboard._writen_txt=txtvelocityall_ptp.text;
                                    if(my_keyboard._writen_txt=="0")
                                        my_keyboard._writen_txt=""
                                    keyboardPopup.open()
                                }
                            }
                            TextInput {
                                id: txtvelocityall_cp
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: velaccviewmodel.maxVelocityCP
                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=txtvelocityall_cp
                                    my_keyboard._writen_txt=txtvelocityall_cp.text;
                                    if(my_keyboard._writen_txt=="0")
                                        my_keyboard._writen_txt=""
                                    keyboardPopup.open()
                                }
                            }
                            //*************************************************
                            // row 3
                            Label{
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Jerk: </b>"
                                color: "#EFECCA"
                            }

                            TextInput {
                                id: txtjerk_ptp
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: velaccviewmodel.jerkPTP
                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=txtjerk_ptp
                                    my_keyboard._writen_txt=txtjerk_ptp.text;
                                    if(my_keyboard._writen_txt=="0")
                                        my_keyboard._writen_txt=""
                                    keyboardPopup.open()
                                }
                            }
                            TextInput {
                                id: txtjerk_cp
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: velaccviewmodel.jerkCP
                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=txtjerk_cp
                                    my_keyboard._writen_txt=txtjerk_cp.text;
                                    if(my_keyboard._writen_txt=="0")
                                        my_keyboard._writen_txt=""
                                    keyboardPopup.open()
                                }
                            }
                            //*************************************************
                            // row 4
                            Label{
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Acceleration: </b>"
                                color: "#EFECCA"
                            }

                            TextInput {
                                id: txtaccelerationall_ptp
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: velaccviewmodel.accelerationPTP
                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=txtaccelerationall_ptp
                                    my_keyboard._writen_txt=txtaccelerationall_ptp.text;
                                    if(my_keyboard._writen_txt=="0")
                                        my_keyboard._writen_txt=""
                                    keyboardPopup.open()
                                }
                            }

                            TextInput {
                                id: txtaccelerationall_cp
                                width: parent.width * 0.33
                                height: parent.height * 0.25
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: velaccviewmodel.accelerationCP
                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=txtaccelerationall_cp
                                    my_keyboard._writen_txt=txtaccelerationall_cp.text;
                                    if(my_keyboard._writen_txt=="0")
                                        my_keyboard._writen_txt=""
                                    keyboardPopup.open()
                                }
                            }
                        }

                    }
                }
                MFrame
                {
                    width: parent.width * 0.5
                    height: parent.height * 0.4
                    Grid
                    {
                        width:parent.width
                        height: parent.height
                        columns: 1

                        Label{
                            width: parent.width
                            height: parent.height * 0.25
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            text: "<b> HOME </b>"
                            color: "#EFECCA"
                        }
                        MButton{
                            id:setpositionbtn
                            _width: parent.width
                            _height: parent.height * 0.25
                            _text:"Set Position"
                            onBtnClick:
                            {
                                _confirm_what=1;
                                _confirm_Action="Set Home Position With Current Actual Position";
                                confirmPopup.open()
                            }
                        }

                        Grid
                        {
                            width: parent.width
                            height: parent.height * 0.50
                            columns: 2
                            spacing: 2
                            Label{
                                width: parent.width * 0.5
                                height: parent.height
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Velocity: </b>"
                                color: "#EFECCA"
                            }

                            TextInput {
                                id: txtvelocityhome
                                width: parent.width * 0.5
                                height: parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: velaccviewmodel.homeVelocity
                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=txtvelocityhome
                                    my_keyboard._writen_txt=txtvelocityhome.text;
                                    if(my_keyboard._writen_txt=="0")
                                        my_keyboard._writen_txt=""
                                    keyboardPopup.open()
                                }
                            }

                        }

                    }
                }
                MFrame
                {
                    width: parent.width * 0.5
                    height: parent.height * 0.4
                    Grid
                    {
                        width:parent.width
                        height: parent.height
                        columns: 1

                        Label{
                            width: parent.width
                            height: parent.height * 0.25
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            text: "<b> \"Go To\" In Teach Point </b>"
                            color: "#EFECCA"
                        }
                        Grid
                        {
                            width: parent.width
                            height: parent.height * 0.75
                            columns: 2
                            spacing: 2
                            Label{
                                width: parent.width * 0.5
                                height: parent.height * 0.33
                                horizontalAlignment: Text.AlignLeft
                                verticalAlignment: Text.AlignVCenter
                                text: "<b> Velocity: </b>"
                                color: "#EFECCA"
                            }

                            TextInput {
                                id: txtvelocitygoto
                                width: parent.width * 0.5
                                height: parent.height * 0.33
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: velaccviewmodel.gotoVelocity
                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=txtvelocitygoto
                                    my_keyboard._writen_txt=txtvelocitygoto.text;
                                    if(my_keyboard._writen_txt=="0")
                                        my_keyboard._writen_txt=""
                                    keyboardPopup.open()
                                }
                            }

                        }

                    }
                }
            }

            Grid
            {
                width: parent.width
                height: parent.height * 0.15
                columns: 3
                Label // empty space
                {
                    width: parent.width * 0.33
                    height: parent.height
                }

                MButton{
                    id:setconfigbtn
                    _width: parent.width * 0.33
                    _height: parent.height
                    _text:"Set Config"
                    onBtnClick:
                    {
                        _confirm_what=0
                        _confirm_Action="Update Settings"
                        confirmPopup.open()
                    }
                }
                Label // empty space
                {
                    width: parent.width * 0.33
                    height: parent.height
                }
            }
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

    //**************************************************
    //**************************************************


    Popup
    {
        id: confirmPopup
        //anchors.centerIn: parent
        modal: true
        focus: true
        closePolicy: Popup.NoAutoClose // change closePolicy when write done
        background: Rectangle {
            visible: true
            color: "#002F2F"
        }

        MFrame
        {
            height: parent.height
            width: parent.width
            ColumnLayout {
                anchors.fill: parent
                spacing: 30

                Text {
                    id: confirmPopupText
                    color: "#EFECCA"
                    text: qsTr("Are You Sure To "+_confirm_Action+"?")
                }

                RowLayout
                {
                    anchors.right: parent.right
                    MButton {
                        _text: "Yes"
                        onBtnClick:
                        {
                            if(_confirm_what==0)
                            {
                                if(confj_switch.checked)
                                {
                                    velaccviewmodel.confj=true
                                    confj_switch.checked=true
                                }
                                else
                                {
                                    velaccviewmodel.confj=false
                                    confj_switch.checked=false
                                }


                                velaccviewmodel.confData=cmb_confData.currentIndex

                                if(singulPTP_switch.checked)
                                {
                                    velaccviewmodel.singulPTP=true
                                    singulPTP_switch.checked=true
                                }
                                else
                                {
                                    velaccviewmodel.singulPTP=false
                                    singulPTP_switch.checked=false
                                }


                                if(singulCP_switch.checked)
                                {
                                    velaccviewmodel.singulCP=true
                                    singulCP_switch.checked=true
                                }
                                else
                                {
                                    velaccviewmodel.singulCP=false
                                    singulCP_switch.checked=false
                                }


                                velaccviewmodel.maxVelocityPTP=txtvelocityall_ptp.text;
                                velaccviewmodel.jerkPTP=txtjerk_ptp.text;
                                velaccviewmodel.accelerationPTP=txtaccelerationall_ptp.text
                                velaccviewmodel.maxVelocityCP=txtvelocityall_cp.text;
                                velaccviewmodel.jerkCP=txtjerk_cp.text;
                                velaccviewmodel.accelerationCP=txtaccelerationall_cp.text


                                velaccviewmodel.homeVelocity=txtvelocityhome.text


                                velaccviewmodel.gotoVelocity=txtvelocitygoto.text
                            }
                            else
                            {
                                velaccviewmodel.setHomePosition()
                            }

                            confirmPopup.close()
                        }
                    }
                    MButton {
                        _text: "No"
                        onBtnClick:
                        {
                            confirmPopup.close()
                        }
                    }
                }
            }
        }
    }
}
