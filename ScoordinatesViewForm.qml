import QtQuick 2.7
import QtQuick.Controls 2.2
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

    ScoordinatesViewModel{
        id:scoordinatesviewmodel
    }


    MFrame{

        width: parent.width
        height: parent.height

        //******************************************
        //******************************************
        // Run When Ui Cunstruct Compeleted
        Component.onCompleted:
        {
            //            _frameTypeIndex = cmb_frame_type.find(SCoordinateModel[_listIndex].type)
            //            cmb_frame_type.currentIndex=_frameTypeIndex
            //            _teachedFrameTypeIndex = cmb_teached_frame.find(SCoordinateModel[_listIndex].frameType)
            //            cmb_teached_frame.currentIndex=_teachedFrameTypeIndex

            _isCurrentStatus=!SCoordinateModel[_listIndex].iscurrent
            _isSavedStatus=!SCoordinateModel[_listIndex].saved
            _cmbFrameTypeIndex = cmb_frame_type.find(scoordinatesviewmodel.getLastFrameType())
            cmb_frame_type.currentIndex=_cmbFrameTypeIndex
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
                        id: cmb_frame_type
                        height: parent.height
                        width: parent.width * 2/3
                        model: ["all","object","base","task","tool","world"]


                        //enabled: (_isSavedStatus && cmb_method.currentIndex==1|| _isPoint3Clicked)

                        delegate: ItemDelegate {
                            width: cmb_frame_type.width
                            contentItem: Text {
                                text: modelData
                                color: "#EFECCA"
                                font: cmb_frame_type.font
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }
                            highlighted: cmb_frame_type.highlightedIndex === index
                        }

                        indicator: Canvas {
                            id: canvas_frame_type
                            x: cmb_frame_type.width - width - cmb_frame_type.rightPadding
                            y: cmb_frame_type.topPadding + (cmb_frame_type.availableHeight - height) / 2
                            width: 12
                            height: 8
                            //height: (_isSavedStatus && cmb_method.currentIndex==1|| _isPoint3Clicked) ? 8 : 0
                            contextType: "2d"


                            Connections {
                                target: cmb_frame_type
                                onPressedChanged: canvas_frame_type.requestPaint()
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
                            rightPadding: cmb_frame_type.indicator.width + cmb_frame_type.spacing

                            text: cmb_frame_type.displayText
                            font: cmb_frame_type.font
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
                            border.width: cmb_frame_type.visualFocus ? 2 : 1
                            radius: 2
                        }

                        popup: Popup {
                            y: cmb_frame_type.height - 1
                            width: cmb_frame_type.width
                            implicitHeight: contentItem.implicitHeight
                            padding: 1

                            contentItem: ListView {
                                clip: true
                                implicitHeight: contentHeight
                                model: cmb_frame_type.popup.visible ? cmb_frame_type.delegateModel : null
                                currentIndex: cmb_frame_type.highlightedIndex

                                ScrollIndicator.vertical: ScrollIndicator { }
                            }

                            background: Rectangle {
                                border.color: "#EFECCA"
                                radius: 5
                            }
                        }

                        onCurrentIndexChanged:{

                        }
                    }


                }


                //************************************************
                //************************************************

                MFrame
                { //ListView
                    width: parent.width
                    height: parent.height * 4/7


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
                                visible: (model.type==cmb_frame_type.currentText || cmb_frame_type.currentText=="all") ? true : false
                                height: visible ? 25 : 0
                                Label {
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
                                        _lastFrameType=cmb_frame_type.textAt(cmb_frame_type.currentIndex)
                                        scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                                        //***************************************************************

                                    }
                                }
                            }
                            highlightFollowsCurrentItem: true
                            highlight: Rectangle
                            {
                                width: parent.width
                                color: "#7fff00"
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
                            _lastFrameType=cmb_frame_type.textAt(cmb_frame_type.currentIndex)
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
                            _lastFrameType=cmb_frame_type.textAt(cmb_frame_type.currentIndex)
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
                            _lastFrameType=cmb_frame_type.textAt(cmb_frame_type.currentIndex)
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
                        _lastFrameType=cmb_frame_type.textAt(cmb_frame_type.currentIndex)
                        scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                        //***************************************************************
                    }
                }


                //**************************************************
                //**************************************************
                // PopUp
                Popup {
                    id: popup
                    anchors.centerIn: parent
                    width: 500
                    height: 500
                    modal: true
                    focus: true
                    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutsideParent

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
                                            context.fillStyle = cmb_method.pressed ? "#046380" : "#EFECCA";
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
//                                scoordinatesviewmodel.saveFrame(SCoordinateModel[_listIndex].name,nameTextInput.text,cmb_frame_type.currentText,cmb_method.currentText,cmb_teached_frame.currentText,xTextInput.text,yTextInput.text,zTextInput.text,aTextInput.text,bTextInput.text,cTextInput.text)
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
            Grid{
                width: parent.width * 3/5
                height: parent.height
                rows: 5
                spacing: 3


                //************************************************
                //************************************************
                // Select Method and Type Grid
                Grid
                {
                    width: parent.width
                    height: parent.height * 1/8
                    columns: 2


                    //************************************************
                    //************************************************
                    //Select Method Grid
                    Grid
                    {
                        width: parent.width * 1/2
                        height: parent.height
                        columns: 2


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

                        ComboBox {
                            id: cmb_method
                            height: parent.height
                            width: parent.width * 2/3
                            model: ["3-point","position"]

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
                                    radius: 5
                                }
                            }

                            onCurrentIndexChanged:
                            {

                            }
                        }

                    }

                    Rectangle{

                        width: parent.width * 1/2
                        height: parent.height
                        color: "transparent"
                        visible: cmb_frame_type.currentIndex==0
                        Label
                        {
                            id:frameTypelbl
                            anchors.centerIn: parent
                            text: SCoordinateModel[_listIndex].type
                            color: "#EFECCA"
                        }
                    }
                }

                //************************************************
                //************************************************
                //Select Name Grid
                Grid
                {
                    width: parent.width
                    height: parent.height * 1/8
                    columns: 2


                    Rectangle{

                        width: parent.width * 1/3 + 3
                        height: parent.height
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("Name")
                            color: "#EFECCA"
                        }
                    }

                    MFrame{
                        width: parent.width  * 2/3
                        height: parent.height
                        TextInput {
                            id: nameTextInput
                            //enabled: (_isSavedStatus && cmb_method.currentIndex==1|| _isPoint3Clicked)
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            //color: (_isSavedStatus && cmb_method.currentIndex==1) ? "#EFECCA" : "#9E9E9E"
                            color: "#EFECCA"
                            text: SCoordinateModel[_listIndex].name
                            //onTextChanged: teachpointviewmodel.tempName = text
                        }
                    }


                }

                //**************************
                //**************************


                //**************************
                //**************************
                // X Y Z A B C Inputs

                Grid
                {
                    visible: cmb_method.currentIndex==1 ? true : false
                    width: parent.width
                    height: parent.height * 2/8
                    rows: 2
                    spacing: 2

                    //**************************************************
                    //**************************************************


                    Grid{ // X Y Z

                        width: parent.width
                        height: parent.height * 1/2
                        columns: 3


                        //**************************************************
                        //**************************************************

                        Grid // X
                        {
                            width: parent.width * 1/3
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

                            MFrame{
                                width: parent.width  * 8/10
                                height: parent.height
                                TextInput {
                                    id: xTextInput
                                    anchors.centerIn: parent
                                    width: parent.width
                                    height:parent.height
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "#9E9E9E"
                                    text: "820"
                                }
                            }


                        }





                        //**************************************************
                        //**************************************************


                        Grid //Y
                        {
                            width: parent.width * 1/3
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

                            MFrame{
                                width: parent.width  * 8/10
                                height: parent.height
                                TextInput {
                                    id: yTextInput
                                    width: parent.width
                                    height:parent.height
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "#9E9E9E"
                                    text: "0"
                                }
                            }


                        }//**************************************************
                        //**************************************************


                        Grid //Z
                        {
                            width: parent.width * 1/3
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

                            MFrame{
                                width: parent.width  * 8/10
                                height: parent.height
                                TextInput {
                                    id: zTextInput
                                    width: parent.width
                                    height:parent.height
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "#9E9E9E"
                                    text: "1189"
                                }
                            }


                        }
                    }

                    //**************************************************
                    //**************************************************

                    Grid{ // A B C

                        width: parent.width
                        height: parent.height * 1/2
                        columns: 3

                        //**************************************************
                        //**************************************************

                        Grid //A
                        {
                            width: parent.width * 1/3
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

                            MFrame{
                                width: parent.width  * 8/10
                                height: parent.height
                                TextInput {
                                    id: aTextInput
                                    width: parent.width
                                    height:parent.height
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "#9E9E9E"
                                    text: "0"
                                }
                            }


                        }


                        //**************************************************
                        //**************************************************


                        Grid //B
                        {
                            width: parent.width * 1/3
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

                            MFrame{
                                width: parent.width  * 8/10
                                height: parent.height
                                TextInput {
                                    id: bTextInput
                                    width: parent.width
                                    height:parent.height
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "#9E9E9E"
                                    text: "0"
                                }
                            }


                        }//**************************************************
                        //**************************************************


                        Grid //C
                        {
                            width: parent.width * 1/3
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

                            MFrame{
                                width: parent.width  * 8/10
                                height: parent.height
                                TextInput {
                                    id: cTextInput
                                    width: parent.width
                                    height:parent.height
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "#9E9E9E"
                                    text: "0"
                                }
                            }


                        }
                    }


                }

                //*********************************
                //*********************************
                // End Of X Y Z A B C



                //*********************************
                //*********************************
                // 3-point buttons grid

                Grid
                {
                    visible: cmb_method.currentIndex==0 ? true : false
                    width: parent.width
                    height: parent.height * 1/8
                    columns: 3
                    spacing: 5

                    //**************************************************
                    //**************************************************
                    // button point 1
                    MButton {
                        id: btn_point1
                        _text: "point1"
                        _height: parent.height
                        _width:parent.width * 1/3 - 2.5
                        enabled: ((cmb_frame_type.currentIndex==0) ||(cmb_frame_type.currentIndex==2)) ? false : true
                        _isActive: (SCoordinateModel[_listIndex].threePointsStatus[0]=='1')
                        //enabled: (SCoordinateModel[_listIndex].threePointsStatus[0]=='1')
                        onBtnClick:
                        {
                            scoordinatesviewmodel.point1Btn(SCoordinateModel[_listIndex].name)

                            //***************************************************************
                            // keep current index of selected frame in list
                            scoordinatesviewmodel.setCurrentListIndex(_listIndex)
                            frameList.currentIndex = _listIndex;
                            //****************************************************************

                            //***************************************************************
                            // keep current selected frame type
                            _lastFrameType=cmb_frame_type.textAt(cmb_frame_type.currentIndex)
                            scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                            //***************************************************************
                        }
                    }


                    //**************************************************
                    //**************************************************
                    // button point 2
                    MButton {
                        id: btn_point2
                        _text: "point2"
                        _height: parent.height
                        _width:parent.width * 1/3 - 2.5
                        enabled: ((cmb_frame_type.currentIndex==0) ||(cmb_frame_type.currentIndex==2)) ? false : true
                        _isActive: (SCoordinateModel[_listIndex].threePointsStatus[1]=='1')
                        //enabled: (SCoordinateModel[_listIndex].threePointsStatus[1]=='1')
                        onBtnClick:
                        {
                            scoordinatesviewmodel.point2Btn(SCoordinateModel[_listIndex].name)

                            //***************************************************************
                            // keep current index of selected frame in list
                            scoordinatesviewmodel.setCurrentListIndex(_listIndex)
                            frameList.currentIndex = _listIndex;
                            //****************************************************************


                            //***************************************************************
                            // keep current selected frame type
                            _lastFrameType=cmb_frame_type.textAt(cmb_frame_type.currentIndex)
                            scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                            //***************************************************************
                        }
                    }
                    //**************************************************
                    //**************************************************
                    // button point 3
                    MButton {
                        id: btn_point3
                        _text: "point3"
                        _height: parent.height
                        _width:parent.width * 1/3 - 2.5
                        enabled: ((cmb_frame_type.currentIndex==0) ||(cmb_frame_type.currentIndex==2)) ? false : true
                        _isActive: (SCoordinateModel[_listIndex].threePointsStatus[2]=='1')
                        //enabled: (SCoordinateModel[_listIndex].threePointsStatus[2]=='1')
                        onBtnClick:
                        {
                            scoordinatesviewmodel.point3Btn(SCoordinateModel[_listIndex].name)
                            _isPoint3Clicked=true

                            //***************************************************************
                            // keep current index of selected frame in list
                            scoordinatesviewmodel.setCurrentListIndex(_listIndex)
                            frameList.currentIndex = _listIndex;
                            //****************************************************************

                            //***************************************************************
                            // keep current selected frame type
                            _lastFrameType=cmb_frame_type.textAt(cmb_frame_type.currentIndex)
                            scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                            //***************************************************************
                        }
                    }
                }
                //*********************************
                //*********************************
                // End of 3-point buttons grid



                //*********************************
                //*********************************
                // btn create - save - remove Grid
                Grid
                {
                    width: parent.width
                    height: parent.height * 1/8
                    columns: 3
                    spacing: 5

                    //**************************

                    MButton {
                        id: btn_save
                        _text: "Save"
                        _height: parent.height
                        _width:parent.width * 1/3 - 2.5
                        enabled: ((cmb_frame_type.currentIndex==0) ||(cmb_frame_type.currentIndex==2)) ? false : true
                        //enabled: (_isSavedStatus && cmb_method.currentIndex==1 || _isPoint3Clicked)
                        onBtnClick:{
                            scoordinatesviewmodel.saveFrame(SCoordinateModel[_listIndex].name,nameTextInput.text,cmb_frame_type.currentText,cmb_method.currentText,xTextInput.text,yTextInput.text,zTextInput.text,aTextInput.text,bTextInput.text,cTextInput.text)
                            //btn_save.enabled = false

                            //***************************************************************
                            // keep current index of selected frame in list
                            scoordinatesviewmodel.setCurrentListIndex(_listIndex)
                            frameList.currentIndex = _listIndex;
                            //****************************************************************

                            cmb_method.currentIndex=0

                            //***************************************************************
                            // keep current selected frame type
                            _lastFrameType=cmb_frame_type.textAt(cmb_frame_type.currentIndex)
                            scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                            //***************************************************************
                        }
                    }

                    //**************************

                    MButton {
                        id: btn_create
                        _text: "Create"
                        _height: parent.height
                        _width:parent.width * 1/3 - 2.5
                        enabled: ((cmb_frame_type.currentIndex==0) ||(cmb_frame_type.currentIndex==2)) ? false : true
                        //                            _isActive:false
                        onBtnClick: {
                            scoordinatesviewmodel.createBtn(cmb_frame_type.currentText)

                            //***************************************************************
                            // keep current index of selected frame in list
                            _listIndex = scoordinatesviewmodel.getSizeOfFrameList()-1;
                            scoordinatesviewmodel.setCurrentListIndex(_listIndex)
                            frameList.currentIndex=_listIndex
                            //***************************************************************


                            //***************************************************************
                            // keep current selected frame type
                            _lastFrameType=cmb_frame_type.textAt(cmb_frame_type.currentIndex)
                            scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                            //***************************************************************
                        }
                    }

                    //**************************

                    MButton {
                        id: btn_remove
                        _text: "Remove"
                        _height: parent.height
                        _width:parent.width * 1/3 - 2.5
                        enabled: ((cmb_frame_type.currentIndex==0) ||(cmb_frame_type.currentIndex==2)) ? false : true
                        //                            _isActive:false
                        onBtnClick: {
                            if(scoordinatesviewmodel.removeBtn(SCoordinateModel[_listIndex].name))
                            {
                                //***************************************************************
                                // keep current index of selected frame in list
                                _listIndex=scoordinatesviewmodel.getSizeOfFrameList()-1
                                frameList.currentIndex=_listIndex
                                //***************************************************************
                            }
                            else
                            {
                                lblmessage.text="You can not remove a current frame."
                                myMessageBox.open()
                            }
                            //***************************************************************
                            // keep current selected frame type
                            _lastFrameType=cmb_frame_type.textAt(cmb_frame_type.currentIndex)
                            scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                            //***************************************************************
                        }
                    }
                }


                //*********************************
                //*********************************
                // btn setCurrent - modify Grid
                Grid
                {
                    width: parent.width
                    height: parent.height * 1/8
                    columns: 2
                    spacing: 3

                    MButton {
                        id: btn_modify
                        _text: "Modify"
                        _height: parent.height
                        _width:parent.width * 1/2
                        enabled: ((cmb_frame_type.currentIndex==0) ||(cmb_frame_type.currentIndex==2)) ? false : true
                        //enabled: !_isSavedStatus
                        onBtnClick: {
                            scoordinatesviewmodel.modifyBtn(SCoordinateModel[_listIndex].name)


                            //***************************************************************
                            // keep current index of selected frame in list
                            scoordinatesviewmodel.setCurrentListIndex(_listIndex)
                            frameList.currentIndex = _listIndex;
                            //****************************************************************

                            //***************************************************************
                            // keep current selected frame type
                            _lastFrameType=cmb_frame_type.textAt(cmb_frame_type.currentIndex)
                            scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                            //***************************************************************
                        }
                    }

                    //**************************

                    MButton {
                        id: btn_setcurrentframe
                        _text: "Set Current"
                        _height: parent.height
                        _width:parent.width * 1/2
                        enabled: ((cmb_frame_type.currentIndex==0) ||(cmb_frame_type.currentIndex==2)) ? false : true
                        //enabled: _isCurrentStatus
                        onBtnClick: {
                            scoordinatesviewmodel.setCurrentBtn(SCoordinateModel[_listIndex].name,SCoordinateModel[_listIndex].type)


                            //***************************************************************
                            // keep current index of selected frame in list
                            scoordinatesviewmodel.setCurrentListIndex(_listIndex)
                            frameList.currentIndex = _listIndex;
                            //****************************************************************




                            //***************************************************************
                            // keep current selected frame type
                            _lastFrameType=cmb_frame_type.textAt(cmb_frame_type.currentIndex)
                            scoordinatesviewmodel.setLastFrameType(_lastFrameType)
                            //***************************************************************
                        }
                    }


                }

                //*********************************
                //*********************************



            }

            //*********************************
            //*********************************
            // End Of Right Grid

        }

        //*********************************
        //*********************************
        // End Of main Grid

    }


    //**************************************************
    //**************************************************
    // PopUp MessageBox
    Popup {
        id: myMessageBox
        anchors.centerIn: parent
        width: 500
        height: 200
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside

        enter: Transition
        {
            NumberAnimation { property: "opacity"; from: 0.0; to: 1.0;duration: 1000 }
        }

        Frame {
            width: parent.width
            height: parent.height
            background: Rectangle {
                color: "transparent"
                border.color: "red"
                radius: 2
            }



            Label
            {
                id: lblmessage
                anchors.centerIn: parent
                text: qsTr("")
                color: "red"

            }
        }
    }





    //*************************************
    //*************************************
    // End of Mframe

}

