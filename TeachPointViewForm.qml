import QtQuick 2.7
import QtQuick.Controls 2.2
import TeachPointViewModel 1.0
import QtQuick.Layouts 1.3


Item {

    property int _listIndex: 0
    property var _current_active_txtbox_obj: null
    property string _confirm_Action: "Update Point Name"
    property int _confirm_what: 0 // update_name=0 , update_position=1 , delete=2



    TeachPointViewModel{

        id:teachpointviewmodel

        onViewErrorPopup:
        {
            errorPopupText.text=errorMassage
            error_popup.open()
        }
    }


    //    MFrame{
    //        width: parent.width
    //        height: parent.height




    Grid{ // main grid
        width: parent.width * 0.95
        height: parent.height * 0.93
        padding: 10
        rows: 2
        spacing: 5


        //*****************************************************************************
        //*****************************************************************************
        // Top Grid
        //*****************************************************************************
        //*****************************************************************************


        Grid{ //Top Grid
            width: parent.width
            height: parent.height * 5/8
            columns: 2
            topPadding: -10
            spacing: 10


            MFrame
            { // Left ListView
                width: parent.width/ 2
                height: parent.height + 9
                clip: true

                Column{
                    width: parent.width
                    height: parent.height
                    //            color: "#fffff0"
                    //            border.width: 5
                    //            border.color: "#fff5ee"
                    ListView {
                        id : teachPointList
                        width:  parent.width
                        height:  parent.height

                        model: TeachPointModel
                        delegate: Column{
                            id: itemView
                            height: 25
                            width:  parent.width
                            Label {
//                                text: model.name + teachpointviewmodel.savedAndUpdatedString(index)
                                text: model.name
                                color: "#EFECCA"
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
                                    console.log("clicked: " + modelData + " at index: " + index);
                                    teachPointList.currentIndex = index;
                                    teachpointviewmodel.setTempName(teachpointviewmodel.getPointName(index))
                                    teachpointviewmodel.setTempPoints(TeachPointModel[index].points)
                                    bottomGrid.visible = true;
                                    jointRadio.checked=false;
                                    cartesianRadio.checked=false;
                                    _listIndex = index;
                                }
                            }
                            Component.onCompleted : {
                                teachPointList.currentIndex = 0;
                                teachpointviewmodel.setTempName(teachpointviewmodel.getPointName(0))
                                teachpointviewmodel.setTempPoints(TeachPointModel[0].points)
                                _listIndex = 0;
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


            Grid
            { // Right Grid
                width: parent.width / 2
                height: parent.height
                rows: 2
                spacing: 8


                MFrame
                {
                    width: parent.width * 1.05
                    height: parent.height * 3/5

                    Grid
                    {
                        width: parent.width
                        height: parent.height
                        rows: 3
                        spacing: 6

                        Grid //Joint&Cartesian Grid
                        {
                            width: parent.width
                            topPadding: -5
                            height: parent.height * 2/9
                            columns: 2


                            RadioButton { // Joint Radio
                                id: jointRadio
                                text: qsTr("Joint")
                                height: parent.height
                                width: parent.width * 1/2
                                onClicked: bottomGrid.visible=false

                                indicator: Rectangle {
                                    implicitWidth: 26
                                    implicitHeight: 26
                                    x: jointRadio.leftPadding
                                    y: parent.height / 2 - height / 2
                                    radius: 13
                                    border.color: jointRadio.down ? "#046380" : "#EFECCA"

                                    Rectangle {
                                        width: 14
                                        height: 14
                                        x: 6
                                        y: 6
                                        radius: 7
                                        color: "#046380"
                                        visible: jointRadio.checked
                                    }
                                }

                                contentItem: Text {
                                    text: jointRadio.text
                                    font: jointRadio.font
                                    opacity: enabled ? 1.0 : 0.3
                                    color: jointRadio.down ? "#046380" : "#EFECCA"
                                    verticalAlignment: Text.AlignVCenter
                                    leftPadding: jointRadio.indicator.width + jointRadio.spacing
                                }
                            }


                            RadioButton { // Cartesian Radio
                                id: cartesianRadio
                                text: qsTr("Cartesian")
                                height: parent.height
                                width: parent.width * 1/2
                                checked: true
                                onClicked: bottomGrid.visible=false

                                indicator: Rectangle {
                                    implicitWidth: 26
                                    implicitHeight: 26
                                    x: cartesianRadio.leftPadding
                                    y: parent.height / 2 - height / 2
                                    radius: 13
                                    border.color: cartesianRadio.down ? "#046380" : "#EFECCA"

                                    Rectangle {
                                        width: 14
                                        height: 14
                                        x: 6
                                        y: 6
                                        radius: 7
                                        color: "#046380"
                                        visible: cartesianRadio.checked
                                    }
                                }

                                contentItem: Text {
                                    text: cartesianRadio.text
                                    font: cartesianRadio.font
                                    opacity: enabled ? 1.0 : 0.3
                                    color: cartesianRadio.down ? "#046380" : "#EFECCA"
                                    verticalAlignment: Text.AlignVCenter
                                    leftPadding: cartesianRadio.indicator.width + cartesianRadio.spacing
                                }
                            }
                        }



                        Grid //Select Name Grid
                        {
                            width: parent.width
                            height: parent.height * 1/3
                            columns: 2


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

                            MFrame{
                                width: parent.width  * 2/3
                                height: parent.height

                                TextInput {
                                    id: nameTextInput
                                    width: parent.width
                                    height:parent.height
                                    //property string placeholderText: "Enter Name here..."
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "#EFECCA"
                                    text: ""
                                    //                            Text {
                                    //                                text: "ali"//teachpointviewmodel.tempName //|| "Text Here ..."
                                    //                                //text: qsTr("text")
                                    //                                //visible:  !nameTextInput.text
                                    //                            }

                                    onTextChanged: teachpointviewmodel.tempName = nameTextInput.text

                                    onActiveFocusChanged:
                                    {
                                        _current_active_txtbox_obj=nameTextInput
                                        // Delete 'POINT' From Text
                                        my_keyboard._writen_txt=nameTextInput.text.substring(5, nameTextInput.text.length);
                                        keyboardPopup.open()
                                    }
                                }
                            }


                        }




                        MButton {
                            id: btn_save
                            _text: "Save point"
                            _height: parent.height * 1/3
                            _width:parent.width
                            // _isActive:false
                            onBtnClick:
                            {
                                teachpointviewmodel.saveBtn(jointRadio.checked)
                                nameTextInput.text=""
                                jointRadio.checked=false
                                cartesianRadio.checked=true
                            }
                        }
                    }

                }

                MFrame
                {
                    width: parent.width * 1.05
                    height: parent.height * 2/5

                    Grid
                    {
                        width: parent.width
                        height: parent.height
                        rows: 2
                        spacing: 5


                        Grid
                        {
                            width: parent.width
                            height: parent.height * 1/2
                            columns: 2
                            spacing: 3

                            MButton {
                                id: btn_remove
                                _text: "Remove"
                                _height: parent.height
                                _width:parent.width * 1/2 - 3/2
                                onBtnClick: {
                                    _confirm_what=0
                                    _confirm_Action="Delete Point"
                                    confirmPopup.open()
                                }
                            }

                            MButton {
                                id: btn_goto
                                _text: "Go to"
                                _height: parent.height
                                _width:parent.width * 1/2 - 3/2
                                onBtnClick: {
                                    teachpointviewmodel.goToBtn(_listIndex)
                                }
                            }

                        }


                        Grid
                        {
                            width: parent.width
                            height: parent.height * 1/2
                            columns: 2
                            spacing: 3

                            MButton {
                                id: btn_update_name
                                _text: "Update Name"
                                _height: parent.height
                                _width:parent.width * 1/2 - 3/2
                                onBtnClick:
                                {
                                    newNameTextInput.text=TeachPointModel[_listIndex].name
                                    updateNamePopUp.open()
                                }
                            }

                            MButton {
                                id: btn_update_position
                                _text: "Update Position"
                                _height: parent.height
                                _width:parent.width * 1/2 - 3/2
                                onBtnClick:
                                {
                                    updatePositionPopUp.open()
                                }
                            }
                        }



                    }


                }
            }
        }


        //*****************************************************************************
        //*****************************************************************************
        // Top Grid
        //*****************************************************************************
        //*****************************************************************************


        //*****************************************************************************
        //*****************************************************************************
        // bottom Grid
        //*****************************************************************************
        //*****************************************************************************


        MFrame
        {
            id:bottomGrid
            width: parent.width * 1.04
            height: parent.height * 10/24
            visible: false


            Grid
            {
                width: parent.width
                height: parent.height
                rows: 3
                spacing:3


                Grid
                {
                    width: parent.width
                    height: parent.height * 1/3
                    columns: 2

                    Rectangle{

                        width: parent.width * 1/2
                        height: parent.height
                        color: "transparent"
                        Label
                        {
                            id:pointTypeViewLable
                            anchors.centerIn: parent
                            text: (TeachPointModel[_listIndex].type=="POINTJ") ? "JOINT" : "CARTESIAN"
                            color: "#EFECCA"
                        }
                    }

                    //***************************************************

                    // combobox
                    //***************************************************
                    //***************************************************
                    ComboBox {
                        id: cmb_data
                        height: parent.height
                        width: parent.width * 1/2
                        visible: (TeachPointModel[_listIndex].type=="POINTJ") ? false : true
                        model: ["object","task","tool","world","base"]
                        displayText: TeachPointModel[_listIndex].stringFrameType || "object"
                        delegate: ItemDelegate {
                            width: cmb_data.width
                            contentItem: Text {
                                text: modelData
                                color: "#EFECCA"
                                font: cmb_data.font
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }
                            highlighted: cmb_data.highlightedIndex === index
                        }

                        indicator: Canvas {
                            id: canvas
                            x: cmb_data.width - width - cmb_data.rightPadding
                            y: cmb_data.topPadding + (cmb_data.availableHeight - height) / 2
                            width: 12
                            height: 8
                            contextType: "2d"

                            Connections {
                                target: cmb_data
                                onPressedChanged: canvas.requestPaint()
                            }

                            onPaint: {
                                context.reset();
                                context.moveTo(0, 0);
                                context.lineTo(width, 0);
                                context.lineTo(width / 2, height);
                                context.closePath();
                                context.fillStyle = cmb_data.pressed ? "#046380" : "#EFECCA";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_data.indicator.width + cmb_data.spacing

                            text: cmb_data.displayText
                            font: cmb_data.font
                            color: cmb_data.pressed ? "#046380" : "#EFECCA"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_data.pressed ? "#046380" : "#EFECCA"
                            border.width: cmb_data.visualFocus ? 2 : 1
                            color: "#046380"
                            radius: 2
                        }

                        popup: Popup {
                            y: cmb_data.height - 1
                            width: cmb_data.width
                            implicitHeight: contentItem.implicitHeight
                            padding: 1

                            contentItem: ListView {
                                clip: true
                                implicitHeight: contentHeight
                                model: cmb_data.popup.visible ? cmb_data.delegateModel : null
                                currentIndex: cmb_data.highlightedIndex

                                ScrollIndicator.vertical: ScrollIndicator { }
                            }

                            background: Rectangle {
                                border.color: "#EFECCA"
                                color: "#046380"
                                radius: 5
                            }
                        }
                        onActivated:{
                            teachpointviewmodel.getSelectedCombo(_listIndex,cmb_data.currentText)
                        }
                    }
                }

                //**************************************************
                //**************************************************


                Grid{

                    width: parent.width
                    height: parent.height * 1/3
                    columns: 3




                    Grid
                    {
                        width: parent.width * 1/3
                        height: parent.height
                        columns: 2
                        visible: (TeachPointModel[_listIndex].type=="POINTJ") ? true : false



                        Rectangle{

                            width: parent.width * 1/3
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("J1")
                                color: "#EFECCA"

                            }
                        }

                        MFrame{
                            width: parent.width  * 2/3
                            height: parent.height
                            TextInput {
                                id: nameTextInput0
                                anchors.centerIn: parent
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#9E9E9E"
                                text: TeachPointModel[_listIndex].points[0].toFixed(3)
                                onTextChanged:{
                                    if(nameTextInput0.focus){
                                        teachpointviewmodel.tempPoints[0]= text
                                        //                                        teachpointviewmodel.setPointCoordinate(_listIndex)
                                    }

                                }
                                focus : true
                                //                                MouseArea {
                                //                                    anchors.fill: parent
                                //                                    propagateComposedEvents: true
                                //                                    onClicked: {
                                //                                        mouse.accepted = true
                                //                                        console.log('clicked-----------')
                                //                                    }
                                //                                    onPressed: mouse.accepted = false;
                                //                                }
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
                        visible: (TeachPointModel[_listIndex].type=="POINTJ") ? true : false



                        Rectangle{

                            width: parent.width * 1/3
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("J2")
                                color: "#EFECCA"

                            }
                        }

                        MFrame{
                            width: parent.width  * 2/3
                            height: parent.height
                            TextInput {
                                id: nameTextInput1
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#9E9E9E"
                                text: TeachPointModel[_listIndex].points[1].toFixed(3)
                                onTextChanged:{
                                    if(nameTextInput1.focus){
                                        teachpointviewmodel.tempPoints[1]= text
                                        //                                        teachpointviewmodel.setPointCoordinate(_listIndex)
                                    }

                                }
                                focus : true

                            }
                        }


                    }//**************************************************
                    //**************************************************


                    Grid
                    {
                        width: parent.width * 1/3
                        height: parent.height
                        columns: 2
                        visible: (TeachPointModel[_listIndex].type=="POINTJ") ? true : false



                        Rectangle{

                            width: parent.width * 1/3
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("J3")
                                color: "#EFECCA"

                            }
                        }

                        MFrame{
                            width: parent.width  * 2/3
                            height: parent.height
                            TextInput {
                                id: nameTextInput2
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#9E9E9E"
                                text: TeachPointModel[_listIndex].points[2].toFixed(3)
                                onTextChanged:{
                                    if(nameTextInput2.focus){
                                        teachpointviewmodel.tempPoints[2]= text
                                        //                                        teachpointviewmodel.setPointCoordinate(_listIndex)
                                    }

                                }
                                focus : true

                            }
                        }


                    }




                    //***************************************************
                    //***************************************************
                    // Cartesian

                    Grid
                    {
                        width: parent.width * 1/3
                        height: parent.height
                        columns: 2
                        visible: (TeachPointModel[_listIndex].type=="POINTP") ? true : false



                        Rectangle{

                            width: parent.width * 1/3
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
                            width: parent.width  * 2/3
                            height: parent.height
                            TextInput {
                                id: cartNameTextInput0
                                anchors.centerIn: parent
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#9E9E9E"
                                text: TeachPointModel[_listIndex].points[0].toFixed(3)
                                onTextChanged:{
                                    if(cartNameTextInput0.focus){
                                        teachpointviewmodel.tempPoints[0]= text
                                        //                                        teachpointviewmodel.setPointCoordinate(_listIndex)
                                    }

                                }
                                focus : true
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
                        visible: (TeachPointModel[_listIndex].type=="POINTP") ? true : false



                        Rectangle{

                            width: parent.width * 1/3
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
                            width: parent.width  * 2/3
                            height: parent.height
                            TextInput {
                                id: cartNameTextInput1
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#9E9E9E"
                                text: TeachPointModel[_listIndex].points[1].toFixed(3)
                                onTextChanged:{
                                    if(cartNameTextInput1.focus){
                                        teachpointviewmodel.tempPoints[1]= text
                                        //                                        teachpointviewmodel.setPointCoordinate(_listIndex)
                                    }

                                }
                                focus : true
                            }
                        }


                    }//**************************************************
                    //**************************************************


                    Grid
                    {
                        width: parent.width * 1/3
                        height: parent.height
                        columns: 2
                        visible: (TeachPointModel[_listIndex].type=="POINTP") ? true : false



                        Rectangle{

                            width: parent.width * 1/3
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
                            width: parent.width  * 2/3
                            height: parent.height
                            TextInput {
                                id: cartNameTextInput2
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#9E9E9E"
                                text: TeachPointModel[_listIndex].points[2].toFixed(3)
                                onTextChanged:{
                                    if(cartNameTextInput2.focus){
                                        teachpointviewmodel.tempPoints[2]= text
                                        //                                        teachpointviewmodel.setPointCoordinate(_listIndex)
                                    }

                                }
                                focus : true
                            }
                        }


                    }


                }
                //**************************************************
                //**************************************************

                Grid{

                        width: parent.width
                        height: parent.height * 1/3
                        columns: 3

                        Grid
                        {
                            width: parent.width * 1/3
                            height: parent.height
                            columns: 2
                            visible: (TeachPointModel[_listIndex].type=="POINTJ") ? true : false



                            Rectangle{

                                width: parent.width * 1/3
                                height: parent.height
                                color: "transparent"
                                Label
                                {
                                    anchors.centerIn: parent
                                    text: qsTr("J4")
                                    color: "#EFECCA"

                                }
                            }

                            MFrame{
                                width: parent.width  * 2/3
                                height: parent.height
                                TextInput {
                                    id: nameTextInput3
                                    width: parent.width
                                    height:parent.height
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "#9E9E9E"
                                    text: TeachPointModel[_listIndex].points[3].toFixed(3)
                                    onTextChanged:{
                                        if(nameTextInput3.focus){
                                            teachpointviewmodel.tempPoints[3]= text
                                            //                                        teachpointviewmodel.setPointCoordinate(_listIndex)
                                        }

                                    }
                                    focus : true

                                }
                            }


                        }//**************************************************
                        //**************************************************


                        Grid
                        {
                            width: parent.width * 1/3
                            height: parent.height
                            columns: 2
                            visible: (TeachPointModel[_listIndex].type=="POINTJ") ? true : false



                            Rectangle{

                                width: parent.width * 1/3
                                height: parent.height
                                color: "transparent"
                                Label
                                {
                                    anchors.centerIn: parent
                                    text: qsTr("J5")
                                    color: "#EFECCA"

                                }
                            }

                            MFrame{
                                width: parent.width  * 2/3
                                height: parent.height
                                TextInput {
                                    id: nameTextInput4
                                    width: parent.width
                                    height:parent.height
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "#9E9E9E"
                                    text: TeachPointModel[_listIndex].points[4].toFixed(3)
                                    onTextChanged:{
                                        if(nameTextInput4.focus){
                                            teachpointviewmodel.tempPoints[4]= text
                                            //                                        teachpointviewmodel.setPointCoordinate(_listIndex)
                                        }

                                    }
                                    focus : true

                                }
                            }


                        }//**************************************************
                        //**************************************************


                        Grid
                        {
                            width: parent.width * 1/3
                            height: parent.height
                            columns: 2
                            visible: (TeachPointModel[_listIndex].type=="POINTJ") ? true : false



                            Rectangle{

                                width: parent.width * 1/3
                                height: parent.height
                                color: "transparent"
                                Label
                                {
                                    anchors.centerIn: parent
                                    text: qsTr("J6")
                                    color: "#EFECCA"

                                }
                            }

                            MFrame{
                                width: parent.width  * 2/3
                                height: parent.height
                                TextInput {
                                    id: nameTextInput5
                                    width: parent.width
                                    height:parent.height
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "#9E9E9E"
                                    text: TeachPointModel[_listIndex].points[5].toFixed(3)
                                    onTextChanged:{
                                        if(nameTextInput5.focus){
                                            teachpointviewmodel.tempPoints[5]= text
                                            //                                        teachpointviewmodel.setPointCoordinate(_listIndex)
                                        }

                                    }
                                    focus : true

                                }
                            }


                        }


                        //*****************************************************
                        //*****************************************************
                        // Cartezian



                        Grid
                        {
                            width: parent.width * 1/3
                            height: parent.height
                            columns: 2
                            visible: (TeachPointModel[_listIndex].type=="POINTP") ? true : false



                            Rectangle{

                                width: parent.width * 1/3
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
                                width: parent.width  * 2/3
                                height: parent.height
                                TextInput {
                                    id: cartNameTextInput3
                                    anchors.centerIn: parent
                                    width: parent.width
                                    height:parent.height
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "#9E9E9E"
                                    text: TeachPointModel[_listIndex].points[3].toFixed(3)
                                    onTextChanged:{
                                        if(cartNameTextInput3.focus){
                                            teachpointviewmodel.tempPoints[3]= text
                                            //                                        teachpointviewmodel.setPointCoordinate(_listIndex)
                                        }

                                    }
                                    focus : true
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
                            visible: (TeachPointModel[_listIndex].type=="POINTP") ? true : false



                            Rectangle{

                                width: parent.width * 1/3
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
                                width: parent.width  * 2/3
                                height: parent.height
                                TextInput {
                                    id: cartNameTextInput4
                                    width: parent.width
                                    height:parent.height
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "#9E9E9E"
                                    text: TeachPointModel[_listIndex].points[4].toFixed(3)
                                    onTextChanged:{
                                        if(cartNameTextInput4.focus){
                                            teachpointviewmodel.tempPoints[4]= text
                                            //                                        teachpointviewmodel.setPointCoordinate(_listIndex)
                                        }

                                    }
                                    focus : true
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
                            visible: (TeachPointModel[_listIndex].type=="POINTP") ? true : false



                            Rectangle{

                                width: parent.width * 1/3
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
                                width: parent.width  * 2/3
                                height: parent.height
                                TextInput {
                                    id: cartNameTextInput5
                                    width: parent.width
                                    height:parent.height
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    color: "#9E9E9E"
                                    text: TeachPointModel[_listIndex].points[5].toFixed(3)
                                    onTextChanged:{
                                        if(cartNameTextInput5.focus){
                                            teachpointviewmodel.tempPoints[5]= text
                                            //                                        teachpointviewmodel.setPointCoordinate(_listIndex)
                                        }

                                    }
                                    focus : true
                                }
                            }


                        }
                    }




            }
        }

        //*****************************************************************************
        //*****************************************************************************
        // bottom Grid
        //*****************************************************************************
        //*****************************************************************************


    }
    Popup
    {
        id: error_popup
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
            anchors.fill: parent
            ColumnLayout {
                anchors.fill: parent
                spacing: 30

                Text {
                    id: errorPopupText
                    color: "#EFECCA"
                    text: qsTr("")
                }

                MButton {
                    _text: "OK"
                    anchors.horizontalCenter: parent.horizontalCenter
                    onBtnClick:
                    {
                        error_popup.close()
                    }
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
                    if(_current_active_txtbox_obj==nameTextInput||_current_active_txtbox_obj==newNameTextInput)
                    {
                        if(my_keyboard._writen_txt!="")
                            _current_active_txtbox_obj.text="POINT"+my_keyboard._writen_txt
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


    Popup
    {
        id: confirmPopup
        //anchors.centerIn: parent
        //        width: 100
        //        height: 100
        modal: true
        focus: true
        closePolicy: Popup.NoAutoClose // change closePolicy when write done
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
                            teachpointviewmodel.deleteBtn(_listIndex)

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


    //********************************************************
    //********************************************************


    Popup
    {
        id: updateNamePopUp
        //anchors.centerIn: parent
        width: 450
        height: 200
        modal: true
        focus: true
        closePolicy: Popup.NoAutoClose // change closePolicy when write done
        background: Rectangle {
            visible: true
            color: "#002F2F"
        }
        MFrame
        {
            anchors.fill: parent
            Grid
            {
                anchors.fill: parent
                rows: 3


                Grid
                {
                    width: parent.width
                    height: parent.height * 1/3
                    spacing: 5
                    columns: 2

                    Rectangle
                    {
                        width: parent.width * 1/5
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

                        width: parent.width * 4/5
                        height: parent.height

                        TextInput {
                            id: newNameTextInput
                            width: parent.width
                            height: parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#EFECCA"
                            text: TeachPointModel[_listIndex].name

                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=newNameTextInput
                                // Delete 'POINT' From Text
                                my_keyboard._writen_txt=newNameTextInput.text.substring(5, newNameTextInput.text.length);
                                keyboardPopup.open()
                            }

                            //                        onTextChanged: teachpointviewmodel.tempName = nameTextInput.text
                        }
                    }

                }

                Rectangle
                {
                    width: parent.width
                    height: parent.height * 1/3 - 10
                    color: "transparent"
                }


                Grid
                {
                    width: parent.width
                    height: parent.height * 1/3
                    columns: 3
                    spacing: 5

                    Rectangle
                    {
                        width: parent.width * 1/2 - 10
                        height: parent.height
                        color: "transparent"
                    }
                    MButton {
                        _text: "cancle"
                        _width:parent.width * 1/4
                        height: parent.height
                        onBtnClick:
                        {
                            updateNamePopUp.close()
                        }
                    }
                    MButton {
                        _text: "Change"
                        _width:parent.width * 1/4
                        height: parent.height
                        onBtnClick:
                        {
                            teachpointviewmodel.tempName = newNameTextInput.text
                            teachpointviewmodel.updateNameBtn(_listIndex)
                            updateNamePopUp.close()
                        }
                    }
                }
            }
        }
    }


    //********************************************************
    //********************************************************

    Popup
    {
        id: updatePositionPopUp
        //anchors.centerIn: parent
        width: 450
        height: 200
        modal: true
        focus: true
        closePolicy: Popup.NoAutoClose // change closePolicy when write done
        background: Rectangle {
            visible: true
            color: "#002F2F"
        }
        MFrame
        {
            anchors.fill: parent
            Grid
            {
                anchors.fill: parent
                rows: 3


                Grid //Joint&Cartesian Grid
                {
                    width: parent.width
                    height: parent.height * 1/3
                    spacing: 5
                    columns: 2


                    RadioButton { // Joint Radio
                        id: jointRadioNewPosition
                        text: qsTr("Joint")
                        height: parent.height
                        width: parent.width * 1/2
                        checked: (TeachPointModel[_listIndex].type=="POINTJ") ? true : false

                        indicator: Rectangle {
                            implicitWidth: 26
                            implicitHeight: 26
                            x: jointRadioNewPosition.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            border.color: jointRadioNewPosition.down ? "#046380" : "#EFECCA"

                            Rectangle {
                                width: 14
                                height: 14
                                x: 6
                                y: 6
                                radius: 7
                                color: "#046380"
                                visible: jointRadioNewPosition.checked
                            }
                        }

                        contentItem: Text {
                            text: jointRadioNewPosition.text
                            font: jointRadioNewPosition.font
                            opacity: enabled ? 1.0 : 0.3
                            color: jointRadioNewPosition.down ? "#046380" : "#EFECCA"
                            verticalAlignment: Text.AlignVCenter
                            leftPadding: jointRadioNewPosition.indicator.width + jointRadioNewPosition.spacing
                        }
                    }


                    RadioButton { // Cartesian Radio
                        id: cartesianRadioNewPosition
                        text: qsTr("Cartesian")
                        height: parent.height
                        width: parent.width * 1/2
                        checked: (TeachPointModel[_listIndex].type=="POINTJ") ? false : true

                        indicator: Rectangle {
                            implicitWidth: 26
                            implicitHeight: 26
                            x: cartesianRadioNewPosition.leftPadding
                            y: parent.height / 2 - height / 2
                            radius: 13
                            border.color: cartesianRadioNewPosition.down ? "#046380" : "#EFECCA"

                            Rectangle {
                                width: 14
                                height: 14
                                x: 6
                                y: 6
                                radius: 7
                                color: "#046380"
                                visible: cartesianRadioNewPosition.checked
                            }
                        }

                        contentItem: Text {
                            text: cartesianRadioNewPosition.text
                            font: cartesianRadioNewPosition.font
                            opacity: enabled ? 1.0 : 0.3
                            color: cartesianRadioNewPosition.down ? "#046380" : "#EFECCA"
                            verticalAlignment: Text.AlignVCenter
                            leftPadding: cartesianRadioNewPosition.indicator.width + cartesianRadioNewPosition.spacing
                        }
                    }
                }

                //******************************************************************

                Rectangle
                {
                    width: parent.width
                    height: parent.height * 1/3 - 10
                    color: "transparent"
                }


                //******************************************************************


                Grid
                {
                    width: parent.width
                    height: parent.height * 1/3
                    columns: 3
                    spacing: 5

                    Rectangle
                    {
                        width: parent.width * 1/2 - 10
                        height: parent.height
                        color: "transparent"
                    }
                    MButton {
                        _text: "cancle"
                        _width:parent.width * 1/4
                        height: parent.height
                        onBtnClick:
                        {
                            updatePositionPopUp.close()
                        }
                    }
                    MButton {
                        _text: "Change"
                        _width:parent.width * 1/4
                        height: parent.height
                        onBtnClick:
                        {
//                            ,jointRadioNewPosition.checked
                            teachpointviewmodel.updatePositionBtn(_listIndex,jointRadioNewPosition.checked)
                            updatePositionPopUp.close()
                        }
                    }
                }
            }
        }
    }



    //    }
}
