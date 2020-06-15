import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import ScoordinatesViewModel 1.0

Item {

    property bool _flag: true
    property int _listIndex: 0
    property int _frameTypeIndex: 0
    property int _cmbFrameTypeIndex: 0
    property bool _isCurrentStatus: true
    property bool _isSavedStatus: true
    property bool _isPoint3Clicked: false
    property string _lastFrameType: ""
    property var _current_active_txtbox_obj: null

    property bool _isUpdateFrameoptionsSelected: false
    property bool _isAnyFrameSelected: false
    property bool _isBaseTypeSelected: false
    property variant _cmbUpdatePositionMethodListDefault: ["3-point","position"]
    property variant _cmbUpdatePositionMethodListToolCase: ["3-config","position","4-config"]

    ScoordinatesViewModel{
        id:scoordinatesviewmodel

        onViewErrorPopup:
        {
            lblmessage.text=errorMassage
            myMessageBox.open()
        }
        onUpdateFrameDone:
        {
            scoordinatesviewmodel.setUpdateOptionsStatus(false)
            _isUpdateFrameoptionsSelected=false
            _isAnyFrameSelected=false
        }
    }

    //******************************************
    //******************************************
    // Run When Ui Cunstruct Compeleted
    Component.onCompleted:
    {
        //            _frameTypeIndex = cmb_frame_type_display.find(SCoordinateModel[_listIndex].type)
        //            cmb_frame_type_display.currentIndex=_frameTypeIndex
        //            _teachedFrameTypeIndex = cmb_teached_frame.find(SCoordinateModel[_listIndex].frameType)
        //            cmb_teached_frame.currentIndex=_teachedFrameTypeIndex

//        _isCurrentStatus=!SCoordinateModel[_listIndex].iscurrent
//        _isSavedStatus=!SCoordinateModel[_listIndex].saved
        console.log("888888888888888888scoordinatesviewmodel.tempCreateFrameType")
        console.log(scoordinatesviewmodel.isUpdatePositionChecked)
        updatepositionChkbox.checked=scoordinatesviewmodel.isUpdatePositionChecked
        _isUpdateFrameoptionsSelected=scoordinatesviewmodel.isUpdateBtnClicked
        if(_isUpdateFrameoptionsSelected)
        {
            _cmbFrameTypeIndex = cmb_update_frame_method.find(scoordinatesviewmodel.tempCreateFrameMethod)
            cmb_update_frame_method.currentIndex=_cmbFrameTypeIndex
        }
        else
        {
            _cmbFrameTypeIndex = cmb_frame_type_create.find(scoordinatesviewmodel.tempCreateFrameType)
            cmb_frame_type_create.currentIndex=_cmbFrameTypeIndex

            _cmbFrameTypeIndex = cmb_method.find(scoordinatesviewmodel.tempCreateFrameMethod)
            cmb_method.currentIndex=_cmbFrameTypeIndex
        }
        _cmbFrameTypeIndex = cmb_frame_type_display.find(scoordinatesviewmodel.tempCreateFrameType)
        cmb_frame_type_display.currentIndex=_cmbFrameTypeIndex
        _listIndex=frameList.currentIndex
    }

    //******************************************
    //******************************************

    Grid{ // main grid
        width: parent.width * 0.95
        height: parent.height * 0.93
        padding: 10
        columns: 2
        spacing: 10


        //******************************************************
        //******************************************************
        //left Grid
        Grid{
            width: parent.width * 2/5
            height: parent.height
            spacing: 5
            topPadding: -10
            rows: 4


            //************************************************
            //************************************************
            //Select Type Grid
            Grid
            {
                width: parent.width
                height: parent.height * 1/7
                columns: 2


                Rectangle
                {

                    width: parent.width * 1/3
                    height: parent.height
                    color: "transparent"
                    Label
                    {
                        anchors.centerIn: parent
                        text: qsTr("Type")
                        color: "#EFECCA"
                    }
                }

                //*****************************************

                ComboBox
                {
                    id: cmb_frame_type_display
                    height: parent.height
                    width: parent.width * 2/3
                    enabled: !_isUpdateFrameoptionsSelected
                    model: ["all","object","base","task","tool","world"]


                    //enabled: (_isSavedStatus && cmb_method.currentIndex==1|| _isPoint3Clicked)

                    delegate: ItemDelegate {
                        width: cmb_frame_type_display.width
                        contentItem: Text {
                            text: modelData
                            color: "#EFECCA"
                            font: cmb_frame_type_display.font
                            elide: Text.ElideRight
                            verticalAlignment: Text.AlignVCenter
                        }
                        highlighted: cmb_frame_type_display.highlightedIndex === index
                    }

                    indicator: Canvas {
                        id: canvas_cmb_frame_type_display
                        x: cmb_frame_type_display.width - width - cmb_frame_type_display.rightPadding
                        y: cmb_frame_type_display.topPadding + (cmb_frame_type_display.availableHeight - height) / 2
                        width: 12
                        height: 8
                        //height: (_isSavedStatus && cmb_method.currentIndex==1|| _isPoint3Clicked) ? 8 : 0
                        contextType: "2d"


                        Connections {
                            target: cmb_frame_type_display
                            onPressedChanged: canvas_cmb_frame_type_display.requestPaint()
                        }

                        onPaint: {
                            context.reset();
                            context.moveTo(0, 0);
                            context.lineTo(width, 0);
                            context.lineTo(width / 2, height);
                            context.closePath();
                            context.fillStyle = cmb_frame_type_display.pressed ? "#046380" : "#EFECCA";
                            context.fill();
                        }
                    }

                    contentItem: Text {
                        leftPadding: 10
                        rightPadding: cmb_frame_type_display.indicator.width + cmb_frame_type_display.spacing

                        text: cmb_frame_type_display.displayText
                        font: cmb_frame_type_display.font
                        //color: (_isSavedStatus && cmb_method.currentIndex==1|| _isPoint3Clicked) ? "#EFECCA" : "#C5E1A5"
                        color: "#EFECCA"
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 40
                        //border.color: (_isSavedStatus && cmb_method.currentIndex==1|| _isPoint3Clicked) ? "#EFECCA" : "#C5E1A5"
                        border.color: "#EFECCA"
                        border.width: cmb_frame_type_display.visualFocus ? 2 : 1
                        color: "#046380"
                        radius: 2
                    }

                    popup: Popup {
                        y: cmb_frame_type_display.height - 1
                        width: cmb_frame_type_display.width
                        implicitHeight: contentItem.implicitHeight
                        padding: 1

                        contentItem: ListView {
                            clip: true
                            implicitHeight: contentHeight
                            model: cmb_frame_type_display.popup.visible ? cmb_frame_type_display.delegateModel : null
                            currentIndex: cmb_frame_type_display.highlightedIndex

                            ScrollIndicator.vertical: ScrollIndicator { }
                        }

                        background: Rectangle {
                            border.color: "#EFECCA"
                            color: "#046380"
                            radius: 5
                        }
                    }

                    onActivated:
                    {
                        _isAnyFrameSelected=false
                        if(cmb_frame_type_display.currentText==model[0] || cmb_frame_type_display.currentText==model[2])
                        {
                            _isBaseTypeSelected=true
                        }
                        else
                            _isBaseTypeSelected=false

                    }
                }


            }


            //************************************************
            //************************************************

            MFrame
            { //ListView
                width: parent.width
                height: parent.height * 4/7
                clip: true

                Column{
                    width: parent.width
                    height: parent.height

                    ListView {
                        id : frameList
                        currentIndex:scoordinatesviewmodel.getCurrentListIndex()
                        width:  parent.width
                        height:  parent.height
                        model: SCoordinateModel
                        delegate: Column{
                            id: itemView
                            width:  parent.width
                            visible: (model.type==cmb_frame_type_display.currentText || cmb_frame_type_display.currentText=="all") ? true : false
                            height: visible ? 25 : 0
                            Label {
                                color: "#EFECCA"
                                text: model.name + " " + (model.saved ? "" : "(unsaved)")+ " " + (model.iscurrent ? "*" : "")
                            }
                            TextInput {
                                width: parent.width
                                onTextChanged: model.answer = text

                                Rectangle {
                                    anchors.fill: parent
                                    color: "transparent"
                                    //border.color: "grey"
                                }
                            }
                            MouseArea
                            {
                                anchors.fill: parent
                                onClicked:
                                {
                                    //console.log("clicked: " + modelData + " at index: " + index);
                                    console.log(model.type);
                                    _isPoint3Clicked=false
                                    _isAnyFrameSelected=true
                                    frameList.currentIndex = index;
                                    _listIndex = index;
                                    //                                        _teachedFrameTypeIndex = cmb_teached_frame.find(SCoordinateModel[_listIndex].frameType)
                                    //                                        cmb_teached_frame.currentIndex=_teachedFrameTypeIndex


                                    //*******************************
                                    // if frame Is Current "SetCurrent" Button To be Disable
                                    //btn_setcurrentframe.enabled=!SCoordinateModel[_listIndex].iscurrent
                                    //*******************************

                                    _isSavedStatus=!SCoordinateModel[_listIndex].saved

                                    //***************************************************************
                                    // keep current index of selected frame in list
                                    scoordinatesviewmodel.setCurrentListIndex(_listIndex)
                                    frameList.currentIndex = _listIndex;
                                    //****************************************************************


                                    //***************************************************************
                                    // keep current selected frame type
                                    _lastFrameType=cmb_frame_type_display.textAt(cmb_frame_type_display.currentIndex)
                                    scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                                    //***************************************************************

                                }
                            }
                        }
                        highlightFollowsCurrentItem: true
                        highlight: Rectangle
                        {
                            width: parent.width
                            color: "#046380"
                        }

                        focus: true
                    }

                }


            }



            //************************************************
            //************************************************
            //Point1 - Point2 - Point3 buttons for show mainpoints
            Grid
            {
                width: parent.width
                height: parent.height * 1/7
                columns: 3
                spacing: 5


                //**************************************************
                //**************************************************
                // button point 1
                MButton {
                    id: btn_show_point1
                    _text: "point1"
                    _height: parent.height
                    _width:parent.width * 1/3 - 2.5
                    onBtnClick:
                    {
                        if(SCoordinateModel[_listIndex].type=="object")
                        {
                            cmb_popup_frame_type.model=["world","base","task"]
                        }
                        else if(SCoordinateModel[_listIndex].type=="task")
                        {
                            cmb_popup_frame_type.model=["world","base","object"]
                        }
                        else if(SCoordinateModel[_listIndex].type=="base")
                        {
                            cmb_popup_frame_type.model=["world","task","object"]
                        }
                        else if(SCoordinateModel[_listIndex].type=="world")
                        {
                            cmb_popup_frame_type.model=["base","task","object"]
                        }
                        x_for_show_lbl.text=SCoordinateModel[_listIndex].p1Point[0].toFixed(3)
                        y_for_show_lbl.text=SCoordinateModel[_listIndex].p1Point[1].toFixed(3)
                        z_for_show_lbl.text=SCoordinateModel[_listIndex].p1Point[2].toFixed(3)
                        a_for_show_lbl.text=SCoordinateModel[_listIndex].p1Point[3].toFixed(3)
                        b_for_show_lbl.text=SCoordinateModel[_listIndex].p1Point[4].toFixed(3)
                        c_for_show_lbl.text=SCoordinateModel[_listIndex].p1Point[5].toFixed(3)
                        popup.open()

                        //***************************************************************
                        // keep current selected frame type
                        _lastFrameType=cmb_frame_type_display.textAt(cmb_frame_type_display.currentIndex)
                        scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                        //***************************************************************
                    }
                }


                //**************************************************
                //**************************************************
                // button point 2
                MButton {
                    id: btn_show_point2
                    _text: "point2"
                    _height: parent.height
                    _width:parent.width * 1/3 - 2.5
                    onBtnClick:
                    {
                        if(SCoordinateModel[_listIndex].type=="object")
                        {
                            cmb_popup_frame_type.model=["world","base","task"]
                        }
                        else if(SCoordinateModel[_listIndex].type=="task")
                        {
                            cmb_popup_frame_type.model=["world","base","object"]
                        }
                        else if(SCoordinateModel[_listIndex].type=="base")
                        {
                            cmb_popup_frame_type.model=["world","task","object"]
                        }
                        else if(SCoordinateModel[_listIndex].type=="world")
                        {
                            cmb_popup_frame_type.model=["base","task","object"]
                        }
                        x_for_show_lbl.text=SCoordinateModel[_listIndex].p2Point[0].toFixed(3)
                        y_for_show_lbl.text=SCoordinateModel[_listIndex].p2Point[1].toFixed(3)
                        z_for_show_lbl.text=SCoordinateModel[_listIndex].p2Point[2].toFixed(3)
                        a_for_show_lbl.text=SCoordinateModel[_listIndex].p2Point[3].toFixed(3)
                        b_for_show_lbl.text=SCoordinateModel[_listIndex].p2Point[4].toFixed(3)
                        c_for_show_lbl.text=SCoordinateModel[_listIndex].p2Point[5].toFixed(3)
                        popup.open()

                        //***************************************************************
                        // keep current selected frame type
                        _lastFrameType=cmb_frame_type_display.textAt(cmb_frame_type_display.currentIndex)
                        scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                        //***************************************************************
                    }
                }
                //**************************************************
                //**************************************************
                // button point 3
                MButton {
                    id: btn_show_point3
                    _text: "point3"
                    _height: parent.height
                    _width:parent.width * 1/3 - 2.5
                    onBtnClick:
                    {
                        if(SCoordinateModel[_listIndex].type=="object")
                        {
                            cmb_popup_frame_type.model=["world","base","task"]
                        }
                        else if(SCoordinateModel[_listIndex].type=="task")
                        {
                            cmb_popup_frame_type.model=["world","base","object"]
                        }
                        else if(SCoordinateModel[_listIndex].type=="base")
                        {
                            cmb_popup_frame_type.model=["world","task","object"]
                        }
                        else if(SCoordinateModel[_listIndex].type=="world")
                        {
                            cmb_popup_frame_type.model=["base","task","object"]
                        }
                        x_for_show_lbl.text=SCoordinateModel[_listIndex].p3Point[0].toFixed(3)
                        y_for_show_lbl.text=SCoordinateModel[_listIndex].p3Point[1].toFixed(3)
                        z_for_show_lbl.text=SCoordinateModel[_listIndex].p3Point[2].toFixed(3)
                        a_for_show_lbl.text=SCoordinateModel[_listIndex].p3Point[3].toFixed(3)
                        b_for_show_lbl.text=SCoordinateModel[_listIndex].p3Point[4].toFixed(3)
                        c_for_show_lbl.text=SCoordinateModel[_listIndex].p3Point[5].toFixed(3)
                        popup.open()

                        //***************************************************************
                        // keep current selected frame type
                        _lastFrameType=cmb_frame_type_display.textAt(cmb_frame_type_display.currentIndex)
                        scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                        //***************************************************************
                    }
                }


            }


            //**************************************************
            //**************************************************
            // button frame
            MButton {
                id: btn_show_frame
                _text: "frame"
                _height: parent.height * 1/7
                _width:parent.width
                onBtnClick:
                {
                    if(SCoordinateModel[_listIndex].type=="object")
                    {
                        cmb_popup_frame_type.model=["world","base","task"]
                    }
                    else if(SCoordinateModel[_listIndex].type=="task")
                    {
                        cmb_popup_frame_type.model=["world","base","object"]
                    }
                    else if(SCoordinateModel[_listIndex].type=="base")
                    {
                        cmb_popup_frame_type.model=["world","task","object"]
                    }
                    else if(SCoordinateModel[_listIndex].type=="world")
                    {
                        cmb_popup_frame_type.model=["base","task","object"]
                    }
                    x_for_show_lbl.text=SCoordinateModel[_listIndex].mainPoints[0].toFixed(3)
                    y_for_show_lbl.text=SCoordinateModel[_listIndex].mainPoints[1].toFixed(3)
                    z_for_show_lbl.text=SCoordinateModel[_listIndex].mainPoints[2].toFixed(3)
                    a_for_show_lbl.text=SCoordinateModel[_listIndex].mainPoints[3].toFixed(3)
                    b_for_show_lbl.text=SCoordinateModel[_listIndex].mainPoints[4].toFixed(3)
                    c_for_show_lbl.text=SCoordinateModel[_listIndex].mainPoints[5].toFixed(3)
                    popup.open()

                    //***************************************************************
                    // keep current selected frame type
                    _lastFrameType=cmb_frame_type_display.textAt(cmb_frame_type_display.currentIndex)
                    scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                    //***************************************************************
                }
            }


            //**************************************************
            //**************************************************
            // PopUp
            Popup {
                id: popup
                //anchors.centerIn: parent
                width: 500
                height: 500
                modal: true
                focus: true
                closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

                Rectangle
                {
                    anchors.fill: parent
                    color: "#046380"
                }

                MFrame{
                    width: parent.width
                    height: parent.height

                    //************************************************
                    //************************************************
                    // main grid
                    Grid{

                        width: parent.width
                        height: parent.height * 0.93
                        rows: 7
                        spacing: 5

                        //************************************************
                        //************************************************
                        //Select Type Grid
                        Grid
                        {
                            width: parent.width
                            height: parent.height * 1/7
                            columns: 2


                            Rectangle{

                                width: parent.width * 1/3
                                height: parent.height
                                color: "transparent"
                                Label
                                {
                                    anchors.centerIn: parent
                                    text: qsTr("Type")
                                    color: "#EFECCA"
                                }
                            }

                            //*****************************************

                            ComboBox {
                                id: cmb_popup_frame_type
                                height: parent.height
                                width: parent.width * 2/3
                                model: ["all","object","base","task","tool","world"]

                                //enabled: (_isSavedStatus && cmb_method.currentIndex==1|| _isPoint3Clicked)

                                delegate: ItemDelegate {
                                    width: cmb_popup_frame_type.width
                                    contentItem: Text {
                                        text: modelData
                                        color: "#EFECCA"
                                        font: cmb_popup_frame_type.font
                                        elide: Text.ElideRight
                                        verticalAlignment: Text.AlignVCenter
                                    }
                                    highlighted: cmb_popup_frame_type.highlightedIndex === index
                                }

                                indicator: Canvas {
                                    id: canvas_popup_frame_type
                                    x: cmb_popup_frame_type.width - width - cmb_popup_frame_type.rightPadding
                                    y: cmb_popup_frame_type.topPadding + (cmb_popup_frame_type.availableHeight - height) / 2
                                    width: 12
                                    height: 8
                                    //height: (_isSavedStatus && cmb_method.currentIndex==1|| _isPoint3Clicked) ? 8 : 0
                                    contextType: "2d"


                                    Connections {
                                        target: cmb_popup_frame_type
                                        onPressedChanged: canvas_popup_frame_type.requestPaint()
                                    }

                                    onPaint: {
                                        context.reset();
                                        context.moveTo(0, 0);
                                        context.lineTo(width, 0);
                                        context.lineTo(width / 2, height);
                                        context.closePath();
                                        context.fillStyle = cmb_popup_frame_type.pressed ? "#046380" : "#EFECCA";
                                        context.fill();
                                    }
                                }

                                contentItem: Text {
                                    leftPadding: 10
                                    rightPadding: cmb_popup_frame_type.indicator.width + cmb_popup_frame_type.spacing

                                    text: cmb_popup_frame_type.displayText
                                    font: cmb_popup_frame_type.font
                                    //color: (_isSavedStatus && cmb_method.currentIndex==1|| _isPoint3Clicked) ? "#EFECCA" : "#C5E1A5"
                                    color: "#EFECCA"
                                    verticalAlignment: Text.AlignVCenter
                                    elide: Text.ElideRight
                                }

                                background: Rectangle {
                                    implicitWidth: 120
                                    implicitHeight: 40
                                    //border.color: (_isSavedStatus && cmb_method.currentIndex==1|| _isPoint3Clicked) ? "#EFECCA" : "#C5E1A5"
                                    border.color: "#EFECCA"
                                    border.width: cmb_popup_frame_type.visualFocus ? 2 : 1
                                    color: "#046380"
                                    radius: 2
                                }

                                popup: Popup {
                                    y: cmb_popup_frame_type.height - 1
                                    width: cmb_popup_frame_type.width
                                    implicitHeight: contentItem.implicitHeight
                                    padding: 1

                                    contentItem: ListView {
                                        clip: true
                                        implicitHeight: contentHeight
                                        model: cmb_popup_frame_type.popup.visible ? cmb_popup_frame_type.delegateModel : null
                                        currentIndex: cmb_popup_frame_type.highlightedIndex

                                        ScrollIndicator.vertical: ScrollIndicator { }
                                    }

                                    background: Rectangle {
                                        border.color: "#EFECCA"
                                        color: "#046380"
                                        radius: 5
                                    }
                                }
                            }


                        }

                        //************************************************
                        //************************************************
                        // X
                        MFrame{
                            width: parent.width
                            height: parent.height * 1/7

                            Grid
                            {
                                width: parent.width
                                height: parent.height
                                columns: 2



                                Rectangle{

                                    width: parent.width * 2/10
                                    height: parent.height
                                    color: "transparent"
                                    Label
                                    {
                                        anchors.centerIn: parent
                                        text: qsTr("X")
                                        color: "#EFECCA"

                                    }
                                }

                                //*********************************

                                Rectangle{

                                    width: parent.width * 8/10
                                    height: parent.height
                                    color: "transparent"
                                    Label
                                    {
                                        id: x_for_show_lbl
                                        anchors.centerIn: parent
                                        text: qsTr("111.111")
                                        color: "#EFECCA"

                                    }
                                }

                            }
                        }

                        //************************************************
                        //************************************************
                        // Y
                        MFrame{
                            width: parent.width
                            height: parent.height * 1/7

                            Grid
                            {
                                width: parent.width
                                height: parent.height
                                columns: 2



                                Rectangle{

                                    width: parent.width * 2/10
                                    height: parent.height
                                    color: "transparent"
                                    Label
                                    {
                                        anchors.centerIn: parent
                                        text: qsTr("Y")
                                        color: "#EFECCA"

                                    }
                                }

                                //*********************************

                                Rectangle{

                                    width: parent.width * 8/10
                                    height: parent.height
                                    color: "transparent"
                                    Label
                                    {
                                        id: y_for_show_lbl
                                        anchors.centerIn: parent
                                        text: qsTr("111.111")
                                        color: "#EFECCA"

                                    }
                                }

                            }
                        }

                        //************************************************
                        //************************************************
                        // Z
                        MFrame{
                            width: parent.width
                            height: parent.height * 1/7

                            //                    Grid
                            //                    {
                            //                        width: parent.width
                            //                        height: parent.height * 1/6
                            //                        columns: 3
                            //                        spacing: 3

                            //                        //**************************

                            //                        MButton {
                            //                            id: btn_save
                            //                            _text: "Save"
                            //                            _height: parent.height
                            //                            _width:parent.width * 1/3
                            //                            enabled: (_isSavedStatus && cmb_method.currentIndex==1 || _isPoint3Clicked)
                            //                            onBtnClick:{
                            //                                scoordinatesviewmodel.saveFrame(SCoordinateModel[_listIndex].name,nameTextInput.text,cmb_frame_type_display.currentText,cmb_method.currentText,cmb_teached_frame.currentText,xTextInput.text,yTextInput.text,zTextInput.text,aTextInput.text,bTextInput.text,cTextInput.text)
                            //                                cmb_method.currentIndex=0
                            //                            }
                            //                        }
                            Grid
                            {
                                width: parent.width
                                height: parent.height
                                columns: 2




                                Rectangle{

                                    width: parent.width * 2/10
                                    height: parent.height
                                    color: "transparent"
                                    Label
                                    {
                                        anchors.centerIn: parent
                                        text: qsTr("Z")
                                        color: "#EFECCA"

                                    }
                                }

                                //*********************************

                                Rectangle{

                                    width: parent.width * 8/10
                                    height: parent.height
                                    color: "transparent"
                                    Label
                                    {
                                        id: z_for_show_lbl
                                        anchors.centerIn: parent
                                        text: qsTr("111.111")
                                        color: "#EFECCA"

                                    }
                                }

                            }
                        }

                        //************************************************
                        //************************************************
                        // A
                        MFrame{
                            width: parent.width
                            height: parent.height * 1/7

                            Grid
                            {
                                width: parent.width
                                height: parent.height
                                columns: 2



                                Rectangle{

                                    width: parent.width * 2/10
                                    height: parent.height
                                    color: "transparent"
                                    Label
                                    {
                                        anchors.centerIn: parent
                                        text: qsTr("A")
                                        color: "#EFECCA"

                                    }
                                }

                                //*********************************

                                Rectangle{

                                    width: parent.width * 8/10
                                    height: parent.height
                                    color: "transparent"
                                    Label
                                    {
                                        id: a_for_show_lbl
                                        anchors.centerIn: parent
                                        text: qsTr("111.111")
                                        color: "#EFECCA"

                                    }
                                }

                            }
                        }

                        //************************************************
                        //************************************************
                        // B
                        MFrame{
                            width: parent.width
                            height: parent.height * 1/7

                            Grid
                            {
                                width: parent.width
                                height: parent.height
                                columns: 2

                                Rectangle{

                                    width: parent.width * 2/10
                                    height: parent.height
                                    color: "transparent"
                                    Label
                                    {
                                        anchors.centerIn: parent
                                        text: qsTr("B")
                                        color: "#EFECCA"

                                    }
                                }

                                //*********************************

                                Rectangle{

                                    width: parent.width * 8/10
                                    height: parent.height
                                    color: "transparent"
                                    Label
                                    {
                                        id: b_for_show_lbl
                                        anchors.centerIn: parent
                                        text: qsTr("111.111")
                                        color: "#EFECCA"

                                    }
                                }

                            }
                        }

                        //************************************************
                        //************************************************
                        // C
                        MFrame{
                            width: parent.width
                            height: parent.height * 1/7

                            Grid
                            {
                                width: parent.width
                                height: parent.height
                                columns: 2



                                Rectangle{

                                    width: parent.width * 2/10
                                    height: parent.height
                                    color: "transparent"
                                    Label
                                    {
                                        anchors.centerIn: parent
                                        text: qsTr("C")
                                        color: "#EFECCA"

                                    }
                                }

                                //*********************************

                                Rectangle{

                                    width: parent.width * 8/10
                                    height: parent.height
                                    color: "transparent"
                                    Label
                                    {
                                        id: c_for_show_lbl
                                        anchors.centerIn: parent
                                        text: qsTr("111.111")
                                        color: "#EFECCA"

                                    }
                                }

                            }
                        }

                        //************************************************
                        //************************************************


                    }
                }
            }


        }


        //************************************************
        //************************************************
        // End Of Left Grid


        //******************************************
        // Right Grid
        Column
        {
            width: parent.width * 3/5 + 20
            height: parent.height
            topPadding: -10
            spacing: 5


            //**********************************************
            //**********************************************
            // create frame section
            MFrame
            {
                width: parent.width
                height: parent.height * 2/3 + 20
                visible: !_isUpdateFrameoptionsSelected

                Column
                {
                    width: parent.width
                    height: parent.height
                    spacing: 1

                    //***************************
                    // create type
                    Row
                    {
                        width: parent.width
                        height: parent.height * 1/6

                        Rectangle
                        {

                            width: parent.width * 1/3
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("Type")
                                color: "#EFECCA"
                            }
                        }

                        //*****************************************

                        ComboBox
                        {
                            id: cmb_frame_type_create
                            height: parent.height
                            width: parent.width * 2/3
                            model: ["object","task","tool","world"]

                            delegate: ItemDelegate {
                                width: cmb_frame_type_create.width
                                contentItem: Text {
                                    text: modelData
                                    color: "#EFECCA"
                                    font: cmb_frame_type_create.font
                                    elide: Text.ElideRight
                                    verticalAlignment: Text.AlignVCenter
                                }
                                highlighted: cmb_frame_type_create.highlightedIndex === index
                            }

                            indicator: Canvas {
                                id: canvas_cmb_frame_type_create
                                x: cmb_frame_type_create.width - width - cmb_frame_type_create.rightPadding
                                y: cmb_frame_type_create.topPadding + (cmb_frame_type_create.availableHeight - height) / 2
                                width: 12
                                height: 8
                                contextType: "2d"


                                Connections {
                                    target: cmb_frame_type_create
                                    onPressedChanged: canvas_cmb_frame_type_create.requestPaint()
                                }

                                onPaint: {
                                    context.reset();
                                    context.moveTo(0, 0);
                                    context.lineTo(width, 0);
                                    context.lineTo(width / 2, height);
                                    context.closePath();
                                    context.fillStyle = cmb_frame_type_create.pressed ? "#046380" : "#EFECCA";
                                    context.fill();
                                }
                            }

                            contentItem: Text {
                                leftPadding: 10
                                rightPadding: cmb_frame_type_create.indicator.width + cmb_frame_type_create.spacing

                                text: cmb_frame_type_create.displayText
                                font: cmb_frame_type_create.font
                                color: "#EFECCA"
                                verticalAlignment: Text.AlignVCenter
                                elide: Text.ElideRight
                            }

                            background: Rectangle {
                                implicitWidth: 120
                                implicitHeight: 40
                                border.color: "#EFECCA"
                                border.width: cmb_frame_type_create.visualFocus ? 2 : 1
                                color: "#046380"
                                radius: 2
                            }

                            popup: Popup {
                                y: cmb_frame_type_create.height - 1
                                width: cmb_frame_type_create.width
                                implicitHeight: contentItem.implicitHeight
                                padding: 1

                                contentItem: ListView {
                                    clip: true
                                    implicitHeight: contentHeight
                                    model: cmb_frame_type_create.popup.visible ? cmb_frame_type_create.delegateModel : null
                                    currentIndex: cmb_frame_type_create.highlightedIndex

                                    ScrollIndicator.vertical: ScrollIndicator { }
                                }

                                background: Rectangle {
                                    border.color: "#EFECCA"
                                    color: "#046380"
                                    radius: 5
                                }
                            }

                            onActivated:
                            {
                                scoordinatesviewmodel.tempCreateFrameType=cmb_frame_type_create.currentText
                                _cmbFrameTypeIndex = cmb_frame_type_display.find(cmb_frame_type_create.currentText)
                                cmb_frame_type_display.currentIndex=_cmbFrameTypeIndex

                                //***********************************
                                // empty Inputs add so far
                                nameTextInput.text=""
                                btn_point1._isActive=false
                                btn_point2._isActive=false
                                btn_point3._isActive=false
                                scoordinatesviewmodel.emptyTempCreateFrame()
                                //***********************************

                            }
                        }
                    }


                    //***************************
                    // create name
                    Row
                    {
                        width: parent.width
                        height: parent.height * 1/6
                        Rectangle{

                            width: parent.width * 1/3
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("Name")
                                color: "#EFECCA"
                            }
                        }

                        MFrame
                        {
                            width: parent.width  * 2/3
                            height: parent.height
                            TextInput {
                                id: nameTextInput
                                //enabled: (_isSavedStatus && cmb_method.currentIndex==1|| _isPoint3Clicked)
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                //color: (_isSavedStatus && cmb_method.currentIndex==1) ? "#EFECCA" : "#EFECCA"
                                color: "#EFECCA"
                                text: scoordinatesviewmodel.tempCreateFrameName

                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=nameTextInput
                                    // Delete 'Frame' From Text
                                    my_keyboard._writen_txt=nameTextInput.text.substring(5, nameTextInput.text.length);
                                    keyboardPopup.open()
                                }
                                //onTextChanged: teachpointviewmodel.tempName = text
                            }
                        }
                    }


                    //***************************
                    // create method
                    Row
                    {
                        width: parent.width
                        height: parent.height * 1/6
                        Rectangle{

                            width: parent.width * 1/3
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("Method")
                                color: "#EFECCA"
                            }
                        }

                        //**********************************************

                        ComboBox
                        {
                            id: cmb_method
                            height: parent.height
                            width: parent.width * 2/3
                            model: cmb_frame_type_create.currentIndex==2 ? _cmbUpdatePositionMethodListToolCase : _cmbUpdatePositionMethodListDefault

                            delegate: ItemDelegate {
                                width: cmb_method.width
                                contentItem: Text {
                                    text: modelData
                                    color: "#EFECCA"
                                    font: cmb_method.font
                                    elide: Text.ElideRight
                                    verticalAlignment: Text.AlignVCenter
                                }
                                highlighted: cmb_method.highlightedIndex === index
                            }

                            indicator: Canvas {
                                id: canvas_method
                                x: cmb_method.width - width - cmb_method.rightPadding
                                y: cmb_method.topPadding + (cmb_method.availableHeight - height) / 2
                                width: 12
                                height: 8
                                contextType: "2d"

                                Connections {
                                    target: cmb_method
                                    onPressedChanged: canvas_method.requestPaint()
                                }

                                onPaint: {
                                    context.reset();
                                    context.moveTo(0, 0);
                                    context.lineTo(width, 0);
                                    context.lineTo(width / 2, height);
                                    context.closePath();
                                    context.fillStyle = cmb_method.pressed ? "#046380" : "#EFECCA";
                                    context.fill();
                                }
                            }

                            contentItem: Text {
                                leftPadding: 10
                                rightPadding: cmb_method.indicator.width + cmb_method.spacing

                                text: cmb_method.displayText
                                font: cmb_method.font
                                color: cmb_method.pressed ? "#046380" : "#EFECCA"
                                verticalAlignment: Text.AlignVCenter
                                elide: Text.ElideRight
                            }

                            background: Rectangle {
                                implicitWidth: 120
                                implicitHeight: 40
                                border.color: cmb_method.pressed ? "#046380" : "#EFECCA"
                                border.width: cmb_method.visualFocus ? 2 : 1
                                color: "#046380"
                                radius: 2
                            }

                            popup: Popup {
                                y: cmb_method.height - 1
                                width: cmb_method.width
                                implicitHeight: contentItem.implicitHeight
                                padding: 1

                                contentItem: ListView {
                                    clip: true
                                    implicitHeight: contentHeight
                                    model: cmb_method.popup.visible ? cmb_method.delegateModel : null
                                    currentIndex: cmb_method.highlightedIndex

                                    ScrollIndicator.vertical: ScrollIndicator { }
                                }

                                background: Rectangle {
                                    border.color: "#EFECCA"
                                    color: "#046380"
                                    radius: 5
                                }
                            }

                            onActivated:
                            {
                                scoordinatesviewmodel.tempCreateFrameMethod=cmb_method.currentText
                            }
                        }
                    }

                    //***************************
                    // empty row
                    Row
                    {
                        width: parent.width
                        height: parent.height * 1/12
                        visible: (cmb_method.currentIndex==0||cmb_method.currentIndex==2) ? true : false
                    }

                    //***************************
                    // 3-point method
                    Row
                    {
                        width: parent.width
                        height: parent.height * 1/6
                        visible: (cmb_method.currentIndex==0||cmb_method.currentIndex==2) ? true : false
                        spacing: 5
                        //**************************************************
                        //**************************************************
                        // button point 1
                        MButton {
                            id: btn_point1
                            _text: cmb_frame_type_create.currentIndex==2 ? "config1" : "point1"
                            _height: parent.height
                            _width: cmb_method.currentIndex==2 ? parent.width * 1/4 - 2.5 : parent.width * 1/3 - 2.5
                            //enabled: ((cmb_frame_type_display.currentIndex==0) ||(cmb_frame_type_display.currentIndex==2)) ? false : true
                            _isActive: (scoordinatesviewmodel.tempCreateFrameThreePointsStatus[0]=='1')
                            //enabled: (SCoordinateModel[_listIndex].threePointsStatus[0]=='1')
                            onBtnClick:
                            {
                                scoordinatesviewmodel.point1Btn(nameTextInput.text,cmb_frame_type_create.currentText)
                                btn_point1._isActive=true
                                //***************************************************************
                                // keep current index of selected frame in list
                                scoordinatesviewmodel.setCurrentListIndex(_listIndex)
                                frameList.currentIndex = _listIndex;
                                //****************************************************************

                                //***************************************************************
                                // keep current selected frame type
                                _lastFrameType=cmb_frame_type_display.textAt(cmb_frame_type_display.currentIndex)
                                scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                                //***************************************************************
                            }
                        }


                        //**************************************************
                        //**************************************************
                        // button point 2
                        MButton {
                            id: btn_point2
                            _text: cmb_frame_type_create.currentIndex==2 ? "config2" : "point2"
                            _height: parent.height
                            _width:cmb_method.currentIndex==2 ? parent.width * 1/4 - 2.5 : parent.width * 1/3 - 2.5
                            //enabled: ((cmb_frame_type_display.currentIndex==0) ||(cmb_frame_type_display.currentIndex==2)) ? false : true
                            _isActive: (scoordinatesviewmodel.tempCreateFrameThreePointsStatus[1]=='1')
                            //enabled: (SCoordinateModel[_listIndex].threePointsStatus[1]=='1')
                            onBtnClick:
                            {
                                scoordinatesviewmodel.point2Btn()
                                btn_point2._isActive=true
                                //***************************************************************
                                // keep current index of selected frame in list
                                scoordinatesviewmodel.setCurrentListIndex(_listIndex)
                                frameList.currentIndex = _listIndex;
                                //****************************************************************


                                //***************************************************************
                                // keep current selected frame type
                                _lastFrameType=cmb_frame_type_display.textAt(cmb_frame_type_display.currentIndex)
                                scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                                //***************************************************************
                            }
                        }


                        //**************************************************
                        //**************************************************
                        // button point 3
                        MButton {
                            id: btn_point3
                            _text: cmb_frame_type_create.currentIndex==2 ? "config3" : "point3"
                            _height: parent.height
                            _width: cmb_method.currentIndex==2 ? parent.width * 1/4 - 2.5 : parent.width * 1/3 - 2.5
                            //enabled: ((cmb_frame_type_display.currentIndex==0) ||(cmb_frame_type_display.currentIndex==2)) ? false : true
                            _isActive: (scoordinatesviewmodel.tempCreateFrameThreePointsStatus[2]=='1')
                            //enabled: (SCoordinateModel[_listIndex].threePointsStatus[2]=='1')
                            onBtnClick:
                            {
                                scoordinatesviewmodel.point3Btn()
                                _isPoint3Clicked=true
                                btn_point3._isActive=true
                                //***************************************************************
                                // keep current index of selected frame in list
                                scoordinatesviewmodel.setCurrentListIndex(_listIndex)
                                frameList.currentIndex = _listIndex;
                                //****************************************************************

                                //***************************************************************
                                // keep current selected frame type
                                _lastFrameType=cmb_frame_type_display.textAt(cmb_frame_type_display.currentIndex)
                                scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                                //***************************************************************
                            }
                        }
                        //**************************************************
                        //**************************************************
                        // button config 3
                        MButton {
                            id: btn_point4
                            _text: "config4"
                            _height: parent.height
                            _width: parent.width * 1/4 - 2.5
                            visible: (cmb_frame_type_create.currentIndex==2&&cmb_method.currentIndex==2)
                            onBtnClick:
                            {
                                scoordinatesviewmodel.point4Btn()
                                btn_point4._isActive=true
                            }
                        }
                    }

                    //***************************
                    // empty row
                    Row
                    {
                        width: parent.width
                        height: parent.height * 1/12
                        visible: (cmb_method.currentIndex==0||cmb_method.currentIndex==2) ? true : false
                    }

                    //***************************
                    // Direct Position Method X-Y-Z
                    Row
                    {
                        width: parent.width
                        height: parent.height * 1/6
                        visible: cmb_method.currentIndex==1 ? true : false

                        Rectangle{

                            width: parent.width * 2/30
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("X")
                                color: "#EFECCA"

                            }
                        }

                        MFrame{
                            width: parent.width  * 8/30
                            height: parent.height
                            TextInput {
                                id: xTextInput
                                anchors.centerIn: parent
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: "820"

                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=xTextInput
                                    my_keyboard._writen_txt=xTextInput.text
                                    if(my_keyboard._writen_txt=="0")
                                        my_keyboard._writen_txt=""
                                    keyboardPopup.open()
                                }
                            }
                        }

                        Rectangle{

                            width: parent.width * 2/30
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("Y")
                                color: "#EFECCA"

                            }
                        }

                        MFrame{
                            width: parent.width  * 8/30
                            height: parent.height
                            TextInput {
                                id: yTextInput
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: "0"

                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=yTextInput
                                    my_keyboard._writen_txt=yTextInput.text
                                    if(my_keyboard._writen_txt=="0")
                                        my_keyboard._writen_txt=""
                                    keyboardPopup.open()
                                }
                            }
                        }


                        Rectangle{

                            width: parent.width * 2/30
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("Z")
                                color: "#EFECCA"

                            }
                        }

                        MFrame{
                            width: parent.width  * 8/30
                            height: parent.height
                            TextInput {
                                id: zTextInput
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: "1189"

                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=zTextInput
                                    my_keyboard._writen_txt=zTextInput.text
                                    if(my_keyboard._writen_txt=="0")
                                        my_keyboard._writen_txt=""
                                    keyboardPopup.open()
                                }
                            }
                        }

                    }


                    //***************************
                    // Direct Position Method A-B-C
                    Row
                    {
                        width: parent.width
                        height: parent.height * 1/6
                        visible: cmb_method.currentIndex==1 ? true : false

                        Rectangle{

                            width: parent.width * 2/30
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("A")
                                color: "#EFECCA"

                            }
                        }

                        MFrame{
                            width: parent.width  * 8/30
                            height: parent.height
                            TextInput {
                                id: aTextInput
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: "0"

                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=aTextInput
                                    my_keyboard._writen_txt=aTextInput.text
                                    if(my_keyboard._writen_txt=="0")
                                        my_keyboard._writen_txt=""
                                    keyboardPopup.open()
                                }
                            }
                        }

                        Rectangle{

                            width: parent.width * 2/30
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("B")
                                color: "#EFECCA"

                            }
                        }

                        MFrame{
                            width: parent.width  * 8/30
                            height: parent.height
                            TextInput {
                                id: bTextInput
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: "0"

                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=bTextInput
                                    my_keyboard._writen_txt=bTextInput.text
                                    if(my_keyboard._writen_txt=="0")
                                        my_keyboard._writen_txt=""
                                    keyboardPopup.open()
                                }
                            }
                        }

                        Rectangle{

                            width: parent.width * 2/30
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("C")
                                color: "#EFECCA"

                            }
                        }

                        MFrame{
                            width: parent.width  * 8/30
                            height: parent.height
                            TextInput {
                                id: cTextInput
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: "0"

                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=cTextInput
                                    my_keyboard._writen_txt=cTextInput.text
                                    if(my_keyboard._writen_txt=="0")
                                        my_keyboard._writen_txt=""
                                    keyboardPopup.open()
                                }
                            }
                        }

                    }


                    //***************************
                    // Save Button
                    MButton {
                        id: btn_save
                        _text: "Save"
                        _height: parent.height * 1/6
                        _width:parent.width * 2/3
                        anchors.horizontalCenter: parent.horizontalCenter
                        //enabled: ((cmb_frame_type_display.currentIndex==0) ||(cmb_frame_type_display.currentIndex==2)) ? false : true
                        //enabled: (_isSavedStatus && cmb_method.currentIndex==1 || _isPoint3Clicked)
                        onBtnClick:{
                            scoordinatesviewmodel.saveFrame(nameTextInput.text,cmb_frame_type_create.currentText,cmb_method.currentText,xTextInput.text,yTextInput.text,zTextInput.text,aTextInput.text,bTextInput.text,cTextInput.text)
                            //btn_save.enabled = false

                            //***************************************************************
                            // keep current index of selected frame in list
                            scoordinatesviewmodel.setCurrentListIndex(_listIndex)
                            frameList.currentIndex = _listIndex;
                            //****************************************************************

                            cmb_method.currentIndex=0

                            //***************************************************************
                            // keep current selected frame type
                            _lastFrameType=cmb_frame_type_display.textAt(cmb_frame_type_display.currentIndex)
                            scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                            //***************************************************************

                            //***********************************
                            // empty Inputs add so far
                            nameTextInput.text=""
                            btn_point1._isActive=false
                            btn_point2._isActive=false
                            btn_point3._isActive=false
                            scoordinatesviewmodel.emptyTempCreateFrame()
                            //***********************************

                        }
                    }

                }

            }

            Row
            {
                width: parent.width
                height: parent.height * 1/8

                //***************************
                // View Update Frame Options Button
                MButton
                {
                    id: btn_update_frame_options
                    visible: !_isUpdateFrameoptionsSelected && _isAnyFrameSelected && !_isBaseTypeSelected
                    _text: "update frame options"
                    _height: parent.height
                    _width:parent.width * 3/7
                    onBtnClick:
                    {
                        scoordinatesviewmodel.tempCreateFrameType=cmb_frame_type_display.currentText
                        scoordinatesviewmodel.setUpdateOptionsStatus(true)
                        _isUpdateFrameoptionsSelected=true
                    }
                }

                Rectangle
                {
                    width: parent.width * 1/7
                    height: parent.height
                    color: "transparent"
                }

                //***************************
                // remove Frame Button
                MButton
                {
                    id: btn_remove
                    _text: "Remove"
                    visible: !_isUpdateFrameoptionsSelected && _isAnyFrameSelected && !_isBaseTypeSelected
                    _height: parent.height
                    _width:parent.width * 3/7
                    onBtnClick: {
                        if(scoordinatesviewmodel.removeBtn(SCoordinateModel[_listIndex].name))
                        {
                            //***************************************************************
                            // keep current index of selected frame in list
                            _listIndex=scoordinatesviewmodel.getSizeOfFrameList()-1
                            frameList.currentIndex=_listIndex
                            //***************************************************************
                            _isAnyFrameSelected=false
                        }
                        else
                        {
                            lblmessage.text="You can not remove a current frame."
                            myMessageBox.open()
                        }
                        //***************************************************************
                        // keep current selected frame type
                        _lastFrameType=cmb_frame_type_display.textAt(cmb_frame_type_display.currentIndex)
                        scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                        //***************************************************************
                    }
                }

            }
            //***************************
            // Set Current Frame Button
            MButton
            {
                id: btn_setcurrentframe
                _text: "Set Current"
                visible: !_isUpdateFrameoptionsSelected && _isAnyFrameSelected && !_isBaseTypeSelected
                _height: parent.height * 1/8
                _width:parent.width * 2/3
                anchors.horizontalCenter: parent.horizontalCenter
//                enabled: ((cmb_frame_type_display.currentIndex==0) ||(cmb_frame_type_display.currentIndex==2)) ? false : true
                //enabled: _isCurrentStatus
                onBtnClick: {
                    scoordinatesviewmodel.setCurrentBtn(SCoordinateModel[_listIndex].name,SCoordinateModel[_listIndex].type)

                    _isAnyFrameSelected=false
                    //***************************************************************
                    // keep current index of selected frame in list
                    scoordinatesviewmodel.setCurrentListIndex(_listIndex)
                    frameList.currentIndex = _listIndex;
                    //****************************************************************




                    //***************************************************************
                    // keep current selected frame type
                    _lastFrameType=cmb_frame_type_display.textAt(cmb_frame_type_display.currentIndex)
                    scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                    //***************************************************************
                }
            }



            //**********************************************
            //**********************************************
            // update frame section
            MFrame
            {
                width: parent.width
                height: parent.height * 2/3 + 20
                visible: _isUpdateFrameoptionsSelected

                Column
                {
                    width: parent.width
                    height: parent.height
                    spacing: 1

                    //***************************
                    // update name
                    Row
                    {
                        width: parent.width
                        height: parent.height * 1/5


                        CheckBox
                        {
                            id: updateNamechkbox
                            width: parent.width * 1/10
                            height: parent.height
                            text: ""
                            checked: false
                        }
                        Rectangle
                        {

                            width: parent.width * 2/10
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("New Name")
                                color: "#EFECCA"
                            }
                        }

                        MFrame
                        {
                            width: parent.width  * 7/10
                            height: parent.height
                            TextInput {
                                id: newNameTextInput
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                enabled: updateNamechkbox.checked
                                text: SCoordinateModel[_listIndex].name

                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=newNameTextInput
                                    // Delete 'Frame' From Text
                                    my_keyboard._writen_txt=newNameTextInput.text.substring(5, newNameTextInput.text.length);
                                    keyboardPopup.open()
                                }
                            }
                        }
                    }


                    //***************************
                    // update Position method
                    Row
                    {
                        width: parent.width
                        height: parent.height * 1/5

                        CheckBox
                        {
                            id: updatepositionChkbox
                            width: parent.width * 1/10
                            height: parent.height
                            text: ""
                            checked: false
                            onCheckedChanged:
                            {
                                scoordinatesviewmodel.setUpdatePositionChkboxStatus(updatepositionChkbox.checked)
                            }
                        }
                        Rectangle{

                            width: parent.width * 4/10
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("Update Position")
                                color: "#EFECCA"
                            }
                        }

                        //**********************************************

                        ComboBox
                        {
                            id: cmb_update_frame_method
                            height: parent.height
                            width: parent.width * 5/10
                            model: (SCoordinateModel[_listIndex].type=='tool') ? _cmbUpdatePositionMethodListToolCase : _cmbUpdatePositionMethodListDefault
                            enabled: updatepositionChkbox.checked
                            delegate: ItemDelegate {
                                width: cmb_update_frame_method.width
                                contentItem: Text {
                                    text: modelData
                                    color: "#EFECCA"
                                    font: cmb_update_frame_method.font
                                    elide: Text.ElideRight
                                    verticalAlignment: Text.AlignVCenter
                                }
                                highlighted: cmb_update_frame_method.highlightedIndex === index
                            }

                            indicator: Canvas {
                                id: canvas_update_frame_method
                                x: cmb_update_frame_method.width - width - cmb_update_frame_method.rightPadding
                                y: cmb_update_frame_method.topPadding + (cmb_update_frame_method.availableHeight - height) / 2
                                width: 12
                                height: 8
                                contextType: "2d"

                                Connections {
                                    target: cmb_update_frame_method
                                    onPressedChanged: canvas_update_frame_method.requestPaint()
                                }

                                onPaint: {
                                    context.reset();
                                    context.moveTo(0, 0);
                                    context.lineTo(width, 0);
                                    context.lineTo(width / 2, height);
                                    context.closePath();
                                    context.fillStyle = cmb_update_frame_method.pressed ? "#046380" : "#EFECCA";
                                    context.fill();
                                }
                            }

                            contentItem: Text {
                                leftPadding: 10
                                rightPadding: cmb_update_frame_method.indicator.width + cmb_update_frame_method.spacing

                                text: cmb_update_frame_method.displayText
                                font: cmb_update_frame_method.font
                                color: cmb_update_frame_method.pressed ? "#046380" : "#EFECCA"
                                verticalAlignment: Text.AlignVCenter
                                elide: Text.ElideRight
                            }

                            background: Rectangle {
                                implicitWidth: 120
                                implicitHeight: 40
                                border.color: cmb_update_frame_method.pressed ? "#046380" : "#EFECCA"
                                border.width: cmb_update_frame_method.visualFocus ? 2 : 1
                                color: "#046380"
                                radius: 2
                            }

                            popup: Popup {
                                y: cmb_update_frame_method.height - 1
                                width: cmb_update_frame_method.width
                                implicitHeight: contentItem.implicitHeight
                                padding: 1

                                contentItem: ListView {
                                    clip: true
                                    implicitHeight: contentHeight
                                    model: cmb_update_frame_method.popup.visible ? cmb_update_frame_method.delegateModel : null
                                    currentIndex: cmb_update_frame_method.highlightedIndex

                                    ScrollIndicator.vertical: ScrollIndicator { }
                                }

                                background: Rectangle {
                                    border.color: "#EFECCA"
                                    color: "#046380"
                                    radius: 5
                                }
                            }

                            onActivated:
                            {
                                scoordinatesviewmodel.tempCreateFrameMethod=cmb_update_frame_method.currentText
                            }
                        }
                    }

                    //***************************
                    // empty row
                    Row
                    {
                        width: parent.width
                        height: parent.height * 1/10
                        visible: (cmb_update_frame_method.currentIndex==0||cmb_update_frame_method.currentIndex==2) ? true : false
                    }

                    //***************************
                    // update 3-point method
                    Row
                    {
                        width: parent.width
                        height: parent.height * 1/5
                        visible: (cmb_update_frame_method.currentIndex==0||cmb_update_frame_method.currentIndex==2) ? true : false
                        spacing: 5
                        //**************************************************
                        //**************************************************
                        // button point 1
                        MButton {
                            id: btn_point1_update
                            _text: (SCoordinateModel[_listIndex].type=='tool') ? "config1" : "point1"
                            _height: parent.height
                            _width:(cmb_update_frame_method.currentIndex==2) ? parent.width * 1/4 - 2.5 : parent.width * 1/3 - 2.5
                            enabled: updatepositionChkbox.checked
                            _isActive: (scoordinatesviewmodel.tempCreateFrameThreePointsStatus[0]=='1')
                            onBtnClick:
                            {
                                scoordinatesviewmodel.point1BtnUpdate(SCoordinateModel[_listIndex].name)
                                btn_point1_update._isActive=true
                                //***************************************************************
                                // keep current index of selected frame in list
                                scoordinatesviewmodel.setCurrentListIndex(_listIndex)
                                frameList.currentIndex = _listIndex;
                                //****************************************************************

                                //***************************************************************
                                // keep current selected frame type
                                _lastFrameType=cmb_frame_type_display.textAt(cmb_frame_type_display.currentIndex)
                                scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                                //***************************************************************
                            }
                        }


                        //**************************************************
                        //**************************************************
                        // button point 2
                        MButton {
                            id: btn_point2_update
                            _text: (SCoordinateModel[_listIndex].type=='tool') ? "config2" : "point2"
                            _height: parent.height
                            _width:(cmb_update_frame_method.currentIndex==2) ? parent.width * 1/4 - 2.5 : parent.width * 1/3 - 2.5
                            enabled: updatepositionChkbox.checked
                            _isActive: (scoordinatesviewmodel.tempCreateFrameThreePointsStatus[1]=='1')
                            onBtnClick:
                            {
                                scoordinatesviewmodel.point2BtnUpdate(SCoordinateModel[_listIndex].name)
                                btn_point2_update._isActive=true
                                //***************************************************************
                                // keep current index of selected frame in list
                                scoordinatesviewmodel.setCurrentListIndex(_listIndex)
                                frameList.currentIndex = _listIndex;
                                //****************************************************************


                                //***************************************************************
                                // keep current selected frame type
                                _lastFrameType=cmb_frame_type_display.textAt(cmb_frame_type_display.currentIndex)
                                scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                                //***************************************************************
                            }
                        }


                        //**************************************************
                        //**************************************************
                        // button point 3
                        MButton {
                            id: btn_point3_update
                            _text: (SCoordinateModel[_listIndex].type=='tool') ? "config3" : "point3"
                            _height: parent.height
                            _width:(cmb_update_frame_method.currentIndex==2) ? parent.width * 1/4 - 2.5 : parent.width * 1/3 - 2.5
                            enabled: updatepositionChkbox.checked
                            _isActive: (scoordinatesviewmodel.tempCreateFrameThreePointsStatus[2]=='1')
                            onBtnClick:
                            {
                                scoordinatesviewmodel.point3BtnUpdate(SCoordinateModel[_listIndex].name)
                                _isPoint3Clicked=true
                                btn_point3_update._isActive=true
                                //***************************************************************
                                // keep current index of selected frame in list
                                scoordinatesviewmodel.setCurrentListIndex(_listIndex)
                                frameList.currentIndex = _listIndex;
                                //****************************************************************

                                //***************************************************************
                                // keep current selected frame type
                                _lastFrameType=cmb_frame_type_display.textAt(cmb_frame_type_display.currentIndex)
                                scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                                //***************************************************************
                            }
                        }

                        //**************************************************
                        //**************************************************
                        // button config 3
                        MButton {
                            id: btn_point4_update
                            _text: "config4"
                            _height: parent.height
                            _width:parent.width * 1/4 - 2.5
                            enabled: updatepositionChkbox.checked
                            visible: (SCoordinateModel[_listIndex].type=='tool'&&cmb_update_frame_method.currentIndex==2)
                            onBtnClick:
                            {
                                scoordinatesviewmodel.point4BtnUpdate()
                            }
                        }

                    }

                    //***************************
                    // empty row
                    Row
                    {
                        width: parent.width
                        height: parent.height * 1/10
                        visible: (cmb_update_frame_method.currentIndex==0||cmb_update_frame_method.currentIndex==2) ? true : false
                    }

                    //***************************
                    // Direct Position Method X-Y-Z
                    Row
                    {
                        width: parent.width
                        height: parent.height * 1/5
                        visible: cmb_update_frame_method.currentIndex==1 ? true : false

                        Rectangle{

                            width: parent.width * 2/30
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("X")
                                color: "#EFECCA"

                            }
                        }

                        MFrame{
                            width: parent.width  * 8/30
                            height: parent.height
                            TextInput {
                                id: xTextInputUpdate
                                anchors.centerIn: parent
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: "820"

                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=xTextInputUpdate
                                    my_keyboard._writen_txt=xTextInputUpdate.text
                                    if(my_keyboard._writen_txt=="0")
                                        my_keyboard._writen_txt=""
                                    keyboardPopup.open()
                                }
                            }
                        }

                        Rectangle{

                            width: parent.width * 2/30
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("Y")
                                color: "#EFECCA"

                            }
                        }

                        MFrame{
                            width: parent.width  * 8/30
                            height: parent.height
                            TextInput {
                                id: yTextInputUpdate
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: "0"

                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=yTextInputUpdate
                                    my_keyboard._writen_txt=yTextInputUpdate.text
                                    if(my_keyboard._writen_txt=="0")
                                        my_keyboard._writen_txt=""
                                    keyboardPopup.open()
                                }
                            }
                        }


                        Rectangle{

                            width: parent.width * 2/30
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("Z")
                                color: "#EFECCA"

                            }
                        }

                        MFrame{
                            width: parent.width  * 8/30
                            height: parent.height
                            TextInput {
                                id: zTextInputUpdate
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: "1189"

                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=zTextInputUpdate
                                    my_keyboard._writen_txt=zTextInputUpdate.text
                                    if(my_keyboard._writen_txt=="0")
                                        my_keyboard._writen_txt=""
                                    keyboardPopup.open()
                                }
                            }
                        }

                    }


                    //***************************
                    // Direct Position Method A-B-C
                    Row
                    {
                        width: parent.width
                        height: parent.height * 1/5
                        visible: cmb_update_frame_method.currentIndex==1 ? true : false

                        Rectangle{

                            width: parent.width * 2/30
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("A")
                                color: "#EFECCA"

                            }
                        }

                        MFrame{
                            width: parent.width  * 8/30
                            height: parent.height
                            TextInput {
                                id: aTextInputUpdate
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: "0"

                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=aTextInputUpdate
                                    my_keyboard._writen_txt=aTextInputUpdate.text
                                    if(my_keyboard._writen_txt=="0")
                                        my_keyboard._writen_txt=""
                                    keyboardPopup.open()
                                }
                            }
                        }

                        Rectangle{

                            width: parent.width * 2/30
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("B")
                                color: "#EFECCA"

                            }
                        }

                        MFrame{
                            width: parent.width  * 8/30
                            height: parent.height
                            TextInput {
                                id: bTextInputUpdate
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: "0"

                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=bTextInputUpdate
                                    my_keyboard._writen_txt=bTextInputUpdate.text
                                    if(my_keyboard._writen_txt=="0")
                                        my_keyboard._writen_txt=""
                                    keyboardPopup.open()
                                }
                            }
                        }

                        Rectangle{

                            width: parent.width * 2/30
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("C")
                                color: "#EFECCA"

                            }
                        }

                        MFrame{
                            width: parent.width  * 8/30
                            height: parent.height
                            TextInput {
                                id: cTextInputUpdate
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#EFECCA"
                                text: "0"

                                onActiveFocusChanged:
                                {
                                    _current_active_txtbox_obj=cTextInputUpdate
                                    my_keyboard._writen_txt=cTextInputUpdate.text
                                    if(my_keyboard._writen_txt=="0")
                                        my_keyboard._writen_txt=""
                                    keyboardPopup.open()
                                }
                            }
                        }

                    }


                    //***************************
                    // ok & cancle update row
                    Row
                    {
                        width: parent.width
                        height: parent.height * 1/5

                        MButton
                        {
                            id: btn_cancle_update
                            _text: "cancle"
                            _height: parent.height
                            _width:parent.width * 3/7
                            onBtnClick:
                            {
                                // should set three point status to 000
                                //88888888888888888888888888888888888888
                                scoordinatesviewmodel.setUpdateOptionsStatus(false)
                                _isUpdateFrameoptionsSelected=false

                                //***********************************
                                // empty Inputs add so far
                                nameTextInput.text=""
                                btn_point1_update._isActive=false
                                btn_point2_update._isActive=false
                                btn_point3_update._isActive=false
                                scoordinatesviewmodel.emptyTempCreateFrame()
                                //***********************************
                            }
                        }
                        Rectangle
                        {
                            width: parent.width * 1/7
                            height: parent.height
                            color: "transparent"
                        }

                        MButton
                        {
                            id: btn_cofirm_update
                            _text: "confirm"
                            _height: parent.height
                            _width:parent.width * 3/7
                            enabled: updateNamechkbox.checked || updatepositionChkbox.checked
                            onBtnClick:
                            {
                                scoordinatesviewmodel.updateFrame(updateNamechkbox.checked,updatepositionChkbox.checked,SCoordinateModel[_listIndex].name,newNameTextInput.text,SCoordinateModel[_listIndex].type,cmb_update_frame_method.currentText,xTextInputUpdate.text,yTextInputUpdate.text,zTextInputUpdate.text,aTextInputUpdate.text,bTextInputUpdate.text,cTextInputUpdate.text)
                                //***********************************
                                // empty Inputs add so far
                                nameTextInput.text=""
                                btn_point1_update._isActive=false
                                btn_point2_update._isActive=false
                                btn_point3_update._isActive=false
                                scoordinatesviewmodel.emptyTempCreateFrame()
                                //***********************************
                            }
                        }
                    }

                }

            }

        }



        //*********************************
        //*********************************
        // End Of Right Grid

    }

    //*********************************
    //*********************************
    // End Of main Grid


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
                    if(_current_active_txtbox_obj==nameTextInput||_current_active_txtbox_obj==newNameTextInput)
                    {
                        if(my_keyboard._writen_txt!="")
                            _current_active_txtbox_obj.text="frame"+my_keyboard._writen_txt
                        else
                            _current_active_txtbox_obj.text=""
                    }
                    else
                    {
                        _current_active_txtbox_obj.text=my_keyboard._writen_txt
                    }
                    keyboardPopup.close()
                }
            }
        }
    }


    //**************************************************
    //**************************************************
    // PopUp MessageBox
    Popup {
        id: myMessageBox
        //anchors.centerIn: parent
        modal: true
        focus: true
        closePolicy: Popup.NoAutoClose
        background: Rectangle {
            visible: true
            color: "#002F2F"
        }
        enter: Transition
        {
            NumberAnimation { property: "opacity"; from: 0.0; to: 1.0;duration: 500 }
        }

        MFrame {
            anchors.fill: parent
            ColumnLayout {
                anchors.fill: parent
                spacing: 30

                Text {
                    id: lblmessage
                    color: "#EFECCA"
                    text: qsTr("")
                }

                MButton {
                    _text: "OK"
                    anchors.horizontalCenter: parent.horizontalCenter
                    onBtnClick:
                    {
                        myMessageBox.close()
                    }
                }
            }
        }
    }





    //*************************************
    //*************************************
    // End of Mframe

}

