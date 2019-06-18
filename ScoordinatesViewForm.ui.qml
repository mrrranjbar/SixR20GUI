import QtQuick 2.7
import QtQuick.Controls 2.2
import ScoordinatesViewModel 1.0

Item {

    property bool _flag: true
    property int _listIndex: 0
    property int _frameTypeIndex: 0
    property int _teachedFrameTypeIndex: 0
    property bool _isCurrentStatus: true
    property bool _isSavedStatus: true
    property bool _isPoint3Clicked: false

    ScoordinatesViewModel{
        id:scoordinatesviewmodel
    }


    MFrame
    {

        //******************************************
        //******************************************
        // Run When Ui Cunstruct Compeleted
        Component.onCompleted:
        {
            _frameTypeIndex = cmb_frame_type.find(SCoordinateModel[_listIndex].type)
            cmb_frame_type.currentIndex=_frameTypeIndex
            _teachedFrameTypeIndex = cmb_teached_frame.find(SCoordinateModel[_listIndex].frameType)
            cmb_teached_frame.currentIndex=_teachedFrameTypeIndex

            _isCurrentStatus=!SCoordinateModel[_listIndex].iscurrent
            _isSavedStatus=!SCoordinateModel[_listIndex].saved
        }

        //******************************************
        //******************************************



        width: parent.width
        height: parent.height




        Grid{ // main grid
            width: parent.width * 0.95
            height: parent.height * 0.93
            padding: 10
            rows: 2
            spacing: 10


            //******************************************************
            //******************************************************
            //Top Grid
            Grid{
                width: parent.width
                height: parent.height * 6/8
                columns: 2
                spacing: 10
                topPadding: -10

                //******************************************
                // left Top Grid
                Grid{
                    width: parent.width * 2/5
                    height: parent.height
                    rows: 3
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
                                color: "#21be2b"
                            }
                        }

                        //*****************************************

                        /*MComboBox{

                        }*/

                        ComboBox {
                            id: cmb_type_for_view
                            height: parent.height
                            width: parent.width * 2/3
                            //model: ["object","task","tool","world","base"]
                            model: ListModel {
                                id: cmb_type_for_view_items
                                ListElement { text: "object";}
                                ListElement { text: "task";}
                                ListElement { text: "tool";}
                                ListElement { text: "world";}
                                ListElement { text: "base";}
                                ListElement { text: "all";}
                            }

                            delegate: ItemDelegate {
                                width: cmb_type_for_view.width
                                contentItem: Text {
                                    text: modelData
                                    color: "#21be2b"
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
                                                color: "#21be2b"
                                            }
                                        }

                                        //*****************************************

                                        /*MComboBox{

                                        }*/

                                        ComboBox {
                                            id: cmb_type_for_view
                                            height: parent.height
                                            width: parent.width * 2/3
                                            //model: ["object","task","tool","world","base"]
                                            model: ListModel {
                                                id: cmb_type_for_view_items
                                                ListElement { text: "object";}
                                                ListElement { text: "task";}
                                                ListElement { text: "tool";}
                                                ListElement { text: "world";}
                                                ListElement { text: "base";}
                                                ListElement { text: "all";}
                                            }

                                            delegate: ItemDelegate {
                                                width: cmb_type_for_view.width
                                                contentItem: Text {
                                                    text: modelData
                                    font: cmb_type_for_view.font
                                    elide: Text.ElideRight
                                    verticalAlignment: Text.AlignVCenter
                                }
                                highlighted: cmb_type_for_view.highlightedIndex === index
                            }

                            indicator: Canvas {
                                id: canvas_type_for_view
                                x: cmb_type_for_view.width - width - cmb_type_for_view.rightPadding
                                y: cmb_type_for_view.topPadding + (cmb_type_for_view.availableHeight - height) / 2
                                width: 12
                                height: 8
                                contextType: "2d"

                                Connections {
                                    target: cmb_type_for_view
                                    onPressedChanged: canvas_type_for_view.requestPaint()
                                }

                                onPaint: {
                                    context.reset();
                                    context.moveTo(0, 0);
                                    context.lineTo(width, 0);
                                    context.lineTo(width / 2, height);
                                    context.closePath();
                                    context.fillStyle = cmb_type_for_view.pressed ? "#17a81a" : "#21be2b";
                                    context.fill();
                                }
                            }

                            contentItem: Text {
                                leftPadding: 10
                                rightPadding: cmb_type_for_view.indicator.width + cmb_type_for_view.spacing

                                text: cmb_type_for_view.displayText
                                font: cmb_type_for_view.font
                                color: cmb_type_for_view.pressed ? "#17a81a" : "#21be2b"
                                verticalAlignment: Text.AlignVCenter
                                elide: Text.ElideRight
                            }

                            background: Rectangle {
                                implicitWidth: 120
                                implicitHeight: 40
                                border.color: cmb_type_for_view.pressed ? "#17a81a" : "#21be2b"
                                border.width: cmb_type_for_view.visualFocus ? 2 : 1
                                radius: 2
                            }

                            popup: Popup {
                                y: cmb_type_for_view.height - 1
                                width: cmb_type_for_view.width
                                implicitHeight: contentItem.implicitHeight
                                padding: 1

                                contentItem: ListView {
                                    clip: true
                                    implicitHeight: contentHeight
                                    model: cmb_type_for_view.popup.visible ? cmb_type_for_view.delegateModel : null
                                    currentIndex: cmb_type_for_view.highlightedIndex

                                    ScrollIndicator.vertical: ScrollIndicator { }
                                }

                                background: Rectangle {
                                    border.color: "#21be2b"
                                    radius: 5
                                }
                            }

                            onCurrentIndexChanged:{

                            }
                        }


                    }

                    //************************************************
                    //************************************************


                    Grid //Select Method Grid
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
                                text: qsTr("Method")
                                color: "#21be2b"
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
                                    color: "#21be2b"
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
                                    context.fillStyle = cmb_method.pressed ? "#17a81a" : "#21be2b";
                                    context.fill();
                                }
                            }

                            contentItem: Text {
                                leftPadding: 10
                                rightPadding: cmb_method.indicator.width + cmb_method.spacing

                                text: cmb_method.displayText
                                font: cmb_method.font
                                color: cmb_method.pressed ? "#17a81a" : "#21be2b"
                                verticalAlignment: Text.AlignVCenter
                                elide: Text.ElideRight
                            }

                            background: Rectangle {
                                implicitWidth: 120
                                implicitHeight: 40
                                border.color: cmb_method.pressed ? "#17a81a" : "#21be2b"
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
                                    border.color: "#21be2b"
                                    radius: 5
                                }
                            }

                            onCurrentIndexChanged:
                            {

                            }
                        }


                    }


                    //************************************************
                    //************************************************

                    MFrame
                    { //ListView
                        width: parent.width
                        height: parent.height * 5/7


                        Column{
                            width: parent.width
                            height: parent.height

                            ListView {
                                id : frameList
                                width:  parent.width
                                height:  parent.height
                                model: SCoordinateModel
                                delegate: Column{
                                    id: itemView
                                    width:  parent.width
                                    visible: (model.type==cmb_type_for_view.currentText || cmb_type_for_view.currentText=="all") ? true : false
                                    height: visible ? 25 : 0
                                    Label {
                                        text: model.name + " " + (model.saved ? "" : "(unsaved)")
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
                                            _frameTypeIndex = cmb_frame_type.find(SCoordinateModel[_listIndex].type)
                                            cmb_frame_type.currentIndex=_frameTypeIndex
                                            _teachedFrameTypeIndex = cmb_teached_frame.find(SCoordinateModel[_listIndex].frameType)
                                            cmb_teached_frame.currentIndex=_teachedFrameTypeIndex


                                            //*******************************
                                            // if frame Is Current "SetCurrent" Button To be Disable
                                            btn_setcurrentframe.enabled=!SCoordinateModel[_listIndex].iscurrent
                                            //*******************************

                                            _isSavedStatus=!SCoordinateModel[_listIndex].saved
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
                }


                //************************************************
                //************************************************
                // End Of Left Top Grid


                //******************************************
                // Right Top Grid
                Grid{
                    width: parent.width * 3/5
                    height: parent.height
                    rows: 5
                    spacing: 3


                    Grid //Select Name Grid
                    {
                        width: parent.width
                        height: parent.height * 1/6
                        columns: 2


                        Rectangle{

                            width: parent.width * 1/3 + 3
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("Name")
                                color: "#21be2b"
                            }
                        }

                        MFrame{
                            width: parent.width  * 2/3
                            height: parent.height
                            TextInput {
                                id: nameTextInput
                                enabled: (_isSavedStatus && cmb_method.currentIndex==1|| _isPoint3Clicked)
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: (_isSavedStatus && cmb_method.currentIndex==1) ? "#21be2b" : "#9E9E9E"
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
                        height: parent.height * 2/6
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
                                        color: "#21be2b"

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
                                        text: "111.111"
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
                                        color: "#21be2b"

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
                                        text: "111.111"
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
                                        color: "#21be2b"

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
                                        text: "111.111"
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
                                        color: "#21be2b"

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
                                        text: "111.111"
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
                                        color: "#21be2b"

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
                                        text: "111.111"
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
                                        color: "#21be2b"

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
                                        text: "111.111"
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
                        height: parent.height * 1/6
                        columns: 3
                        spacing: 3

                        //**************************************************
                        //**************************************************
                        // button point 1
                        MButton {
                            id: btn_point1
                            _text: "point1"
                            _height: parent.height
                            _width:parent.width * 1/3
                            enabled: (SCoordinateModel[_listIndex].threePointsStatus[0]=='1')
                            onBtnClick:
                            {
                                scoordinatesviewmodel.point1Btn(SCoordinateModel[_listIndex].name)
                            }
                        }


                        //**************************************************
                        //**************************************************
                        // button point 2
                        MButton {
                            id: btn_point2
                            _text: "point2"
                            _height: parent.height
                            _width:parent.width * 1/3
                            enabled: (SCoordinateModel[_listIndex].threePointsStatus[1]=='1')
                            onBtnClick:
                            {
                                scoordinatesviewmodel.point2Btn(SCoordinateModel[_listIndex].name)
                            }
                        }
                        //**************************************************
                        //**************************************************
                        // button point 3
                        MButton {
                            id: btn_point3
                            _text: "point3"
                            _height: parent.height
                            _width:parent.width * 1/3
                            enabled: (SCoordinateModel[_listIndex].threePointsStatus[2]=='1')
                            onBtnClick:
                            {
                                scoordinatesviewmodel.point3Btn(SCoordinateModel[_listIndex].name)
                                _isPoint3Clicked=true
                            }
                        }
                    }
                    //*********************************
                    //*********************************
                    // End of 3-point buttons grid



                    //*********************************
                    //*********************************

                    Grid
                    {
                        width: parent.width
                        height: parent.height * 1/6
                        columns: 3
                        spacing: 3

                        //**************************

                        MButton {
                            id: btn_save
                            _text: "Save"
                            _height: parent.height
                            _width:parent.width * 1/3
                            enabled: (_isSavedStatus && cmb_method.currentIndex==1 || _isPoint3Clicked)
                            onBtnClick:{
                                scoordinatesviewmodel.saveFrame(SCoordinateModel[_listIndex].name,nameTextInput.text,cmb_frame_type.currentText,cmb_method.currentText,cmb_teached_frame.currentText,xTextInput.text,yTextInput.text,zTextInput.text,aTextInput.text,bTextInput.text,cTextInput.text)
                                btn_save.enabled = false
                                cmb_method.currentIndex=0
                            }
                        }

                        //**************************

                        MButton {
                            id: btn_create
                            _text: "Create"
                            _height: parent.height
                            _width:parent.width * 1/3
                            //                            _isActive:false
                            onBtnClick: {
                                scoordinatesviewmodel.createBtn()
                            }
                        }

                        //**************************

                        MButton {
                            id: btn_remove
                            _text: "Remove"
                            _height: parent.height
                            _width:parent.width * 1/3
                            //                            _isActive:false
                            onBtnClick: {
                                scoordinatesviewmodel.removeBtn(SCoordinateModel[_listIndex].name)
                                _listIndex=0
                            }
                        }
                    }


                    //*********************************
                    //*********************************


                    Grid
                    {
                        width: parent.width
                        height: parent.height * 1/6
                        columns: 2
                        spacing: 3

                        MButton {
                            id: btn_modify
                            _text: "Modify"
                            _height: parent.height
                            _width:parent.width * 1/2
                            enabled: !_isSavedStatus
                            onBtnClick: {
                                scoordinatesviewmodel.modifyBtn(SCoordinateModel[_listIndex].name)
                            }
                        }

                        //**************************

                        MButton {
                            id: btn_setcurrentframe
                            _text: "Set Current"
                            _height: parent.height
                            _width:parent.width * 1/2
                            enabled: _isCurrentStatus
                            onBtnClick: {
                                scoordinatesviewmodel.setCurrentBtn(SCoordinateModel[_listIndex].name,SCoordinateModel[_listIndex].type)
                            }
                        }


                    }

                    //*********************************
                    //*********************************


                    Grid
                    {

                        width: parent.width
                        height: parent.height * 1/6
                        columns: 2


                        Grid //Select frame Type
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
                                    text: qsTr("Type")
                                    color: "#21be2b"
                                }
                            }

                            //**********************************************

                            ComboBox {
                                id: cmb_frame_type
                                height: parent.height
                                width: parent.width * 2/3
                                model: ["object","base","task","tool","world"]

                                enabled: (_isSavedStatus && cmb_method.currentIndex==1|| _isPoint3Clicked)

                                delegate: ItemDelegate {
                                    width: cmb_frame_type.width
                                    contentItem: Text {
                                        text: modelData
                                        color: "#21be2b"
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
                                    height: (_isSavedStatus && cmb_method.currentIndex==1|| _isPoint3Clicked) ? 8 : 0
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
                                        context.fillStyle = cmb_method.pressed ? "#17a81a" : "#21be2b";
                                        context.fill();
                                    }
                                }

                                contentItem: Text {
                                    leftPadding: 10
                                    rightPadding: cmb_frame_type.indicator.width + cmb_frame_type.spacing

                                    text: cmb_frame_type.displayText
                                    font: cmb_frame_type.font
                                    color: (_isSavedStatus && cmb_method.currentIndex==1|| _isPoint3Clicked) ? "#21be2b" : "#C5E1A5"
                                    verticalAlignment: Text.AlignVCenter
                                    elide: Text.ElideRight
                                }

                                background: Rectangle {
                                    implicitWidth: 120
                                    implicitHeight: 40
                                    border.color: (_isSavedStatus && cmb_method.currentIndex==1|| _isPoint3Clicked) ? "#21be2b" : "#C5E1A5"
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
                                        border.color: "#21be2b"
                                        radius: 5
                                    }
                                }
                            }


                        }


                        //****************************************************

                    Grid //Select Teached frame
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
                                text: qsTr("Teach")
                                color: "#21be2b"
                            }
                        }

                        //**********************************************

                        ComboBox {
                            id: cmb_teached_frame
                            height: parent.height
                            width: parent.width * 2/3
                            model: ["base","object","task","tool","world"]

                            delegate: ItemDelegate {
                                width: cmb_teached_frame.width
                                contentItem: Text {
                                    text: modelData
                                    color: "#21be2b"
                                    font: cmb_teached_frame.font
                                    elide: Text.ElideRight
                                    verticalAlignment: Text.AlignVCenter
                                }
                                highlighted: cmb_teached_frame.highlightedIndex === index
                            }

                            indicator: Canvas {
                                id: canvas_teached_frame
                                x: cmb_teached_frame.width - width - cmb_teached_frame.rightPadding
                                y: cmb_teached_frame.topPadding + (cmb_teached_frame.availableHeight - height) / 2
                                width: 12
                                height: 8
                                contextType: "2d"

                                Connections {
                                    target: cmb_teached_frame
                                    onPressedChanged: canvas_teached_frame.requestPaint()
                                }

                                onPaint: {
                                    context.reset();
                                    context.moveTo(0, 0);
                                    context.lineTo(width, 0);
                                    context.lineTo(width / 2, height);
                                    context.closePath();
                                    context.fillStyle = cmb_method.pressed ? "#17a81a" : "#21be2b";
                                    context.fill();
                                }
                            }

                            contentItem: Text {
                                leftPadding: 10
                                rightPadding: cmb_teached_frame.indicator.width + cmb_teached_frame.spacing

                                text: cmb_teached_frame.displayText
                                font: cmb_teached_frame.font
                                color: cmb_teached_frame.pressed ? "#17a81a" : "#21be2b"
                                verticalAlignment: Text.AlignVCenter
                                elide: Text.ElideRight
                            }

                            background: Rectangle {
                                implicitWidth: 120
                                implicitHeight: 40
                                border.color: cmb_teached_frame.pressed ? "#17a81a" : "#21be2b"
                                border.width: cmb_teached_frame.visualFocus ? 2 : 1
                                radius: 2
                            }

                            popup: Popup {
                                y: cmb_teached_frame.height - 1
                                width: cmb_teached_frame.width
                                implicitHeight: contentItem.implicitHeight
                                padding: 1

                                contentItem: ListView {
                                    clip: true
                                    implicitHeight: contentHeight
                                    model: cmb_teached_frame.popup.visible ? cmb_teached_frame.delegateModel : null
                                    currentIndex: cmb_teached_frame.highlightedIndex

                                    ScrollIndicator.vertical: ScrollIndicator { }
                                }

                                background: Rectangle {
                                    border.color: "#21be2b"
                                    radius: 5
                                }
                            }
                        }


                    }


                    }


                    //*********************************
                    //*********************************


                }

                //*********************************
                //*********************************
                // End Of Right Top Grid

            }

            //*********************************
            //*********************************
            // End Of Top Grid



            Grid
            { //Bottom Grid
                width: parent.width
                height: parent.height * 2/8
                rows: 2
                spacing: 5

                //**************************************************
                //**************************************************


                Grid{ // top bottom grid

                    width: parent.width
                    height: parent.height * 1/2
                    columns: 3




                    Grid
                    {
                        width: parent.width * 1/3
                        height: parent.height
                        columns: 2


                        Rectangle{

                            width: parent.width * 1/3
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("J1")
                                color: "#21be2b"

                            }
                        }

                        MFrame{
                            width: parent.width  * 2/3
                            height: parent.height
                            TextInput {
                                //id: nameTextInput
                                anchors.centerIn: parent
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#9E9E9E"
                                text: SCoordinateModel[_listIndex].mainPoints[0]
                            }
                        }


                    }





                    //**************************************************
                    //**************************************************


                    Grid
                    {
                        width: parent.width * 1/3
                        height: parent.height
                        columns: 2


                        Rectangle{

                            width: parent.width * 1/3
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("J2")
                                color: "#21be2b"

                            }
                        }

                        MFrame{
                            width: parent.width  * 2/3
                            height: parent.height
                            TextInput {
                                //id: nameTextInput
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#9E9E9E"
                                text: SCoordinateModel[_listIndex].mainPoints[1]
                            }
                        }


                    }//**************************************************
                    //**************************************************


                    Grid
                    {
                        width: parent.width * 1/3
                        height: parent.height
                        columns: 2


                        Rectangle{

                            width: parent.width * 1/3
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("J3")
                                color: "#21be2b"

                            }
                        }

                        MFrame{
                            width: parent.width  * 2/3
                            height: parent.height
                            TextInput {
                                //id: nameTextInput
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#9E9E9E"
                                text: SCoordinateModel[_listIndex].mainPoints[2]
                            }
                        }


                    }


                }
                //**************************************************
                //**************************************************

                Grid{ // bottom bottom grid

                    width: parent.width
                    height: parent.height * 1/2
                    columns: 3

                    Grid
                    {
                        width: parent.width * 1/3
                        height: parent.height
                        columns: 2


                        Rectangle{

                            width: parent.width * 1/3
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("J4")
                                color: "#21be2b"

                            }
                        }

                        MFrame{
                            width: parent.width  * 2/3
                            height: parent.height
                            TextInput {
                                //id: nameTextInput
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#9E9E9E"
                                text: SCoordinateModel[_listIndex].mainPoints[3]
                            }
                        }


                    }//**************************************************
                    //**************************************************


                    Grid
                    {
                        width: parent.width * 1/3
                        height: parent.height
                        columns: 2


                        Rectangle{

                            width: parent.width * 1/3
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("J5")
                                color: "#21be2b"

                            }
                        }

                        MFrame{
                            width: parent.width  * 2/3
                            height: parent.height
                            TextInput {
                                //id: nameTextInput
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#9E9E9E"
                                text: SCoordinateModel[_listIndex].mainPoints[4]
                            }
                        }


                    }

                    //**************************************************
                    //**************************************************


                    Grid
                    {
                        width: parent.width * 1/3
                        height: parent.height
                        columns: 2


                        Rectangle{

                            width: parent.width * 1/3
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("J6")
                                color: "#21be2b"

                            }
                        }

                        MFrame{
                            width: parent.width  * 2/3
                            height: parent.height
                            TextInput {
                                //id: nameTextInput
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#9E9E9E"
                                text: SCoordinateModel[_listIndex].mainPoints[5]
                            }
                        }


                    }


                }
            }

            //*************************************
            //*************************************
            // End of bottom grid



        }


        //*************************************
        //*************************************
        // End of main grid



    }
}
            }
        }
    }
}
