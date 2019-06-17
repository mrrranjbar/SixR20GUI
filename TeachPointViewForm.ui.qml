
//import QtQuick 2.7
//import QtQuick.Controls 2.2
//import Teachpointviewmodel 1.0

//Item {
//    property int _width: 255
//    property int _height: 75
//    property bool _joint: true

//    property var _nameJoint: ["M1", "M2", "M3", "M4", "M5", "M6"]
//    property var _valueJoint: ["1234.1234", "1234.1234", "1234.1234", "1234.1234", "1234.1234", "1234.1234"]


//    property var _nameCartesian: ["X", "Y", "Z", "Ro", "Pi", "Ya"]
//    property var _valueCartesian: ["25", "4544", "789", "12345", "453642", "4563456"]





//    Teachpointviewmodel{
//        id:teachpoint
//    }


//    Grid{ // main grid
//        width: parent.width
//        height: parent.height * 9/10
//        columns: 2 // change it to 2
//        spacing: 5
//        Grid{
//            width: parent.width/2
//            height: parent.height * 9/10
//            columns: 1

//            Column{
//                width: parent.width
//                height: parent.height
//                //            color: "#fffff0"
//                //            border.width: 5
//                //            border.color: "#fff5ee"
//                ListView {
//                    id : teachPointList
//                    width:  parent.width
//                    height:  parent.height

//                    model: TeachPointModel
//                    delegate: Column{
//                        id: itemView
//                        height: 25
//                        width:  parent.width
//                        Label {
//                            text: model.name
//                        }
//                        TextInput {
//                            width: parent.width
//                            onTextChanged: model.answer = text

//                            Rectangle {
//                                anchors.fill: parent
//                                color: "transparent"
//                                //border.color: "grey"
//                            }
//                        }
//                        MouseArea
//                        {
//                            anchors.fill: parent
//                            onClicked:
//                            {
//                                console.log("clicked: " + modelData + " at index: " + index);
//                                teachPointList.currentIndex = index;
//                            }
//                        }
//                    }
//                    highlightFollowsCurrentItem: true
//                    highlight: Rectangle
//                    {
//                        width: parent.width
//                        color: "#7fff00"
//                    }

//                    focus: true
//                }

//            }

//        }
//        Grid{
//            width: parent.width/2
//            height: parent.height * 9/10
//            columns: 3
//            rows: 1
//            Rectangle{
//                width : parent.width/4
//                height : 50
//                Label {
//                    text: "Name : "

//                }
//            }
//            MButton{
//                _text : "Edit"
//                _width : parent.width/4
//                _height : 50
//                onBtnClick: teachpoint.editList(teachPointList.currentIndex,teachpoint.tempName)
//            }
//            TextInput{
//                id : nameInput
//                width : parent.width/4
//                height : 50
//                onTextChanged: teachpoint.tempName = text
//            }

//        }




//    }
//}

import QtQuick 2.7
import QtQuick.Controls 2.2
import TeachPointViewModel 1.0


Item {

    property int _listIndex: 0
    


    TeachPointViewModel{

        id:teachpointviewmodel
    }


    MFrame{
        width: parent.width
        height: parent.height




        Grid{ // main grid
            width: parent.width * 0.95
            height: parent.height * 0.93
            padding: 10
            rows: 2
            spacing: 10



            Grid{ //Top Grid
                width: parent.width
                height: parent.height * 6/8
                columns: 2
                topPadding: -13
                spacing: 10


                MFrame
                { // Left ListView
                    width: parent.width/ 2
                    height: parent.height + 9

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
                                    text: model.name + teachpointviewmodel.savedAndUpdatedString(index)
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
                                color: "#7fff00"
                            }

                            focus: true
                        }

                    }
                }


                //************************************************
                //************************************************


                Grid{ // Right Grid
                    width: parent.width / 2
                    height: parent.height
                    rows: 6
                    topPadding: -5
                    spacing: 8

                    Grid //Joint&Cartesian Grid
                    {
                        width: parent.width
                        topPadding: -5
                        height: parent.height * 1/7
                        columns: 2


                        RadioButton { // Joint Radio
                            id: jointRadio
                            text: qsTr("Joint")
                            checked: TeachPointModel[_listIndex].type == "joint"
                            width: parent.width * 1/2
                            onClicked: teachpointviewmodel.cartesianRadioBtnClicked(_listIndex)

                            indicator: Rectangle {
                                implicitWidth: 26
                                implicitHeight: 26
                                x: jointRadio.leftPadding
                                y: parent.height / 2 - height / 2
                                radius: 13
                                border.color: jointRadio.down ? "#17a81a" : "#21be2b"

                                Rectangle {
                                    width: 14
                                    height: 14
                                    x: 6
                                    y: 6
                                    radius: 7
                                    color: jointRadio.down ? "#17a81a" : "#21be2b"
                                    visible: jointRadio.checked
                                }
                            }

                            contentItem: Text {
                                text: jointRadio.text
                                font: jointRadio.font
                                opacity: enabled ? 1.0 : 0.3
                                color: jointRadio.down ? "#17a81a" : "#21be2b"
                                verticalAlignment: Text.AlignVCenter
                                leftPadding: jointRadio.indicator.width + jointRadio.spacing
                            }
                        }


                        RadioButton { // Cartesian Radio
                            id: cartesianRadio
                            text: qsTr("Cartesian")
                            checked: TeachPointModel[_listIndex].type == "cartesian"
                            width: parent.width * 1/2
                            onClicked: teachpointviewmodel.cartesianRadioBtnClicked(_listIndex)

                            indicator: Rectangle {
                                implicitWidth: 26
                                implicitHeight: 26
                                x: cartesianRadio.leftPadding
                                y: parent.height / 2 - height / 2
                                radius: 13
                                border.color: cartesianRadio.down ? "#17a81a" : "#21be2b"

                                Rectangle {
                                    width: 14
                                    height: 14
                                    x: 6
                                    y: 6
                                    radius: 7
                                    color: cartesianRadio.down ? "#17a81a" : "#21be2b"
                                    visible: cartesianRadio.checked
                                }
                            }

                            contentItem: Text {
                                text: cartesianRadio.text
                                font: cartesianRadio.font
                                opacity: enabled ? 1.0 : 0.3
                                color: cartesianRadio.down ? "#17a81a" : "#21be2b"
                                verticalAlignment: Text.AlignVCenter
                                leftPadding: cartesianRadio.indicator.width + cartesianRadio.spacing
                            }
                        }
                    }



                    Grid //Select Name Grid
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
                                text: qsTr("Name")
                                color: "#21be2b"
                            }
                        }

                        MFrame{
                            width: parent.width  * 2/3
                            height: parent.height
                            TextInput {
                                id: nameTextInput
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#9E9E9E"
                                text: teachpointviewmodel.tempName || "Text Here ..."
                                onTextChanged: teachpointviewmodel.tempName = text
                            }
                        }


                    }

                    Grid
                    {
                        width: parent.width
                        height: parent.height * 1/7
                        columns: 2
                        spacing: 3


                        MButton {
                            id: btn_save
                            _text: "Save"
                            _height: parent.height
                            _width:parent.width * 1/2 - 3/2
                            // _isActive:false
                            onBtnClick: teachpointviewmodel.saveBtn(_listIndex,false);
                            //                            onBtnClick: teachpointviewmodel.editList(teachPointList.currentIndex,teachpointviewmodel.tempName)
                        }

                        MButton {
                            id: btn_create
                            _text: "Create"
                            _height: parent.height
                            _width:parent.width * 1/2 - 3/2
                            //                            _isActive:false
                            onBtnClick:  teachpointviewmodel.createBtn()
                        }
                    }


                    Grid
                    {
                        width: parent.width
                        height: parent.height * 1/7
                        columns: 2
                        spacing: 3

                        MButton {
                            id: btn_remove
                            _text: "Remove"
                            _height: parent.height
                            _width:parent.width * 1/2 - 3/2
                            //                            _isActive:false
                            onBtnClick: {
                                teachpointviewmodel.deleteBtn(_listIndex)
                            }
                        }

                        MButton {
                            id: btn_update
                            _text: "Update"
                            _height: parent.height
                            _width:parent.width * 1/2 - 3/2
                            //                            _isActive:false
                            onBtnClick: teachpointviewmodel.updateBtn(_listIndex)
                        }


                    }



                    MButton {
                        id: btn_goto
                        _text: "Go to"
                        _height: parent.height  * 1/7
                        _width:parent.width
                        //                        _isActive:false
                        onBtnClick: {
                        }
                    }


                    // combobox
                    //***************************************************
                    //***************************************************
                    ComboBox {
                        id: cmb_data
                        height: parent.height * 1/5
                        width: parent.width
                        model: ["object","task","tool","world","base"]

                        delegate: ItemDelegate {
                            width: cmb_data.width
                            contentItem: Text {
                                text: modelData
                                color: "#21be2b"
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
                                context.fillStyle = cmb_data.pressed ? "#17a81a" : "#21be2b";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_data.indicator.width + cmb_data.spacing

                            text: cmb_data.displayText
                            font: cmb_data.font
                            color: cmb_data.pressed ? "#17a81a" : "#21be2b"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_data.pressed ? "#17a81a" : "#21be2b"
                            border.width: cmb_data.visualFocus ? 2 : 1
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
                                border.color: "#21be2b"
                                radius: 5
                            }
                        }
                    }


                }

            }



            Grid{ //Bottom Grid
                width: parent.width * 0.97
                height: parent.height * 2/8
                rows: 2
                spacing: 5

                //**************************************************
                //**************************************************


                Grid{ // Left bottom grid

                    width: parent.width
                    height: parent.height * 1/2
                    columns: 3




                    Grid
                    {
                        width: parent.width * 1/3
                        height: parent.height
                        columns: 2
                        visible: jointRadio.checked


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
                                id: nameTextInput0
                                anchors.centerIn: parent
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#9E9E9E"
                                text: TeachPointModel[_listIndex].points[0]
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
                        visible: jointRadio.checked


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
                                id: nameTextInput1
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#9E9E9E"
                                text: TeachPointModel[_listIndex].points[1]
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
                        visible: jointRadio.checked


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
                                id: nameTextInput2
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#9E9E9E"
                                text: TeachPointModel[_listIndex].points[2]
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
                        visible: cartesianRadio.checked


                        Rectangle{

                            width: parent.width * 1/3
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("C1")
                                color: "#21be2b"

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
                                text: Math.round(TeachPointModel[_listIndex].points[0])
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
                        visible: cartesianRadio.checked


                        Rectangle{

                            width: parent.width * 1/3
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("C2")
                                color: "#21be2b"

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
                                text: Math.round(TeachPointModel[_listIndex].points[1])
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
                        visible: cartesianRadio.checked


                        Rectangle{

                            width: parent.width * 1/3
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("C3")
                                color: "#21be2b"

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
                                text: Math.round(TeachPointModel[_listIndex].points[2])
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

                Grid{ // Right bottom grid

                    width: parent.width
                    height: parent.height * 1/2
                    columns: 3

                    Grid
                    {
                        width: parent.width * 1/3
                        height: parent.height
                        columns: 2
                        visible: jointRadio.checked


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
                                id: nameTextInput3
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#9E9E9E"
                                text: TeachPointModel[_listIndex].points[3]
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
                        visible: jointRadio.checked


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
                                id: nameTextInput4
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#9E9E9E"
                                text: TeachPointModel[_listIndex].points[4]
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
                        visible: jointRadio.checked


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
                                id: nameTextInput5
                                width: parent.width
                                height:parent.height
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                color: "#9E9E9E"
                                text: TeachPointModel[_listIndex].points[5]
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
                        visible: cartesianRadio.checked


                        Rectangle{

                            width: parent.width * 1/3
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("C4")
                                color: "#21be2b"

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
                                text: Math.round(TeachPointModel[_listIndex].points[3])
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
                        visible: cartesianRadio.checked


                        Rectangle{

                            width: parent.width * 1/3
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("C5")
                                color: "#21be2b"

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
                                text: Math.round(TeachPointModel[_listIndex].points[4])
                                onTextChanged:{
                                    if(cartNameTextInput4.focus){
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
                        visible: cartesianRadio.checked


                        Rectangle{

                            width: parent.width * 1/3
                            height: parent.height
                            color: "transparent"
                            Label
                            {
                                anchors.centerIn: parent
                                text: qsTr("C6")
                                color: "#21be2b"

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
                                text: Math.round(TeachPointModel[_listIndex].points[5])
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



    }
}
