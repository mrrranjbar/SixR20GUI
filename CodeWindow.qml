import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import Qt.labs.folderlistmodel 2.2
import CodeWindow 1.0

Item {
    anchors.fill: parent
    property string prjPath: ""
    property variant _exist_projects_name: []
    property string _defaultPrjPath: "SixR_Projects"
    property string _current_prj_name: ""
    property bool _have_active_prj: false
    property bool _is_started_prj: false

    FileIO{
        id: fileio
    }

    Component.onCompleted: {
        console.log("*********************")
//        if(fileio.currentProject!="")
//        {
//            console.log("**************** in if")
//            openPrj(fileio.currentProject)
//        }
//        openPrj("SixR_Projects/temp2/final.code")
//        console.log(fileio.getCurrentProject())
        openPrj(fileio.currentProject)
        console.log(fileio.currentProject)
    }

    function urlExists(testUrl) {
        var request = new XMLHttpRequest();
        request.open("GET", testUrl, false);
        request.send(null);
        return request.status==200;
    }
    function openPrjFromPath(path){
        if(urlExists(path)){
            projectEditor.open(path)
        }
    }

    function openPrj(f_path){
//        fileDialogLoad.nameFilters= [ "SixR files (*.six)", "All files (*)" ]
//        fileDialogLoad.cb = function() {
//            var xhr = new XMLHttpRequest;
//            prjPath =fileDialogLoad.fileUrl
//            xhr.open("GET", fileDialogLoad.fileUrl);
//            //var path ="/"+fileDialogLoad.folder.toLocaleString().replace("file:///","")+"/"
//            xhr.onreadystatechange = function() {
//                if (xhr.readyState == XMLHttpRequest.DONE) {
//                    var response = xhr.responseText;
//                    var files = response.split(("\n"))
//                    for(var i in files){
//                        if(files[i]){
//                            var newCodeEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
//                            var newTabButton = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
//                            newTabButton.codeEditor = newCodeEditor
//                            newCodeEditor.open(files[i])//path+files[i])
//                            newCodeEditor.changedSinceLastSave = false
//                            tabBar.setCurrentIndex(tabBar.count-1)
//                            newTabButton.color = "#fff" // Hack since focus isn't set correctly when it's the first tab?
//                        }
//                    }
//                }
//            };
//            xhr.send();
//            openPrjFromPath(prjPath+".mnr")
//        }
//        fileDialogLoad.visible = true

        projectEditor.open(f_path)


    }
    function playProject(){
        projectEditor.play(runFromLine.textInput.text)
    }
    function puaseCurrentTab(){
        projectEditor.pause()
    }

    function stopCurrentTab(){
        projectEditor.stop()
    }
    function getExistProjectsName()
    {
        return fileio.getExistProjectList(_defaultPrjPath)
    }



    ColumnLayout {
        anchors.fill: parent
        spacing: 2
        Row {
            Layout.fillWidth: true
            spacing: 3
            MButton {
                _width: 60
                _height: 35
                id: openPrjButton
                _text: "Open"
                onBtnClick: {
                    var res=getExistProjectsName()
                    _exist_projects_name=res.split('#')
                    openExistProjectPopUp.open()
                }
            }
            MButton {
                _width: 60
                _height: 35
                id: playCurrentTabButton
                _text: "Start"
                enabled: _have_active_prj
                onBtnClick: {
                    //if(text: "Play")
                    if(pauseCurrentTabButton._text == "Run"){
                        stopCurrentTab()
                        var times = new Date().getTime()
                        while(new Date().getTime() - times<500);
                        pauseCurrentTabButton._text="Pause"
                        pauseCurrentTabButton._background.color = "white"
                    }
                    playProject()
                    _is_started_prj=true
                }
            }
            Label {
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("From Line")
                color: "#EFECCA"
            }
            MTextField{
                _width:60
                id: runFromLine
                _text:"-1"
            }
            MButton {
                _width: 60
                _height: 35
                id: pauseCurrentTabButton
                _text: "Pause"
                enabled: _is_started_prj
                onBtnClick: {
                    if(_text== "Pause"){
                        _background.color = "red"
                        _text="Run"
                    }
                    else{
                        _background.color = "white"
                        _text = "Pause"
                    }
                    puaseCurrentTab()
                }
            }
            MButton {
                _width: 60
                _height: 35
                id: stopCurrentTabButton
                _text: "Stop"
                enabled: _is_started_prj
                onBtnClick: {
                    pauseCurrentTabButton._text="Pause"
                    pauseCurrentTabButton._background.color = "white"
                    //if(text: "Play")
                    stopCurrentTab()
                }
            }
            MButton {
                _width: 60
                _height: 35
                id: refreshButton
                _text: "Refresh"
                onBtnClick: {
                    openPrj(fileio.currentProject)
                    _have_active_prj=true
                }
            }
        }
        StackLayout {
            id:stackLayout
            Layout.fillWidth: true
            Layout.fillHeight: true
            CodeEditor {
                id: projectEditor
                Component.onCompleted: {
                    changedSinceLastSave = false
                    textArea.readOnly=true
                }
            }
        }
    }
    FileDialog {
        id: fileDialogLoad
        selectExisting : true
        //selectFolder: true
        nameFilters: [ "SixR files (*.six)", "All files (*)" ]
        property var cb
        title: "Please choose project"
        onAccepted: {
            cb()
            cb = undefined
        }
    }

    //********************************************************
    //********************************************************


    Popup
    {
        id: openExistProjectPopUp
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
                        width: parent.width * 2/5
                        height: parent.height
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("Project Name")
                            color: "#EFECCA"
                        }
                    }

                    //***************************************************
                    //***************************************************
                    ComboBox {
                        id: cmb_openExistProjectPopUp
                        height: parent.height
                        width: parent.width * 3/5
                        model: _exist_projects_name
                        displayText: cmb_openExistProjectPopUp.currentText
                        delegate: ItemDelegate {
                            width: cmb_openExistProjectPopUp.width
                            contentItem: Text {
                                text: modelData
                                color: "#EFECCA"
                                font: cmb_openExistProjectPopUp.font
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }
                            highlighted: cmb_openExistProjectPopUp.highlightedIndex === index
                        }

                        indicator: Canvas {
                            id: cmb_openExistProjectPopUp_canvas
                            x: cmb_openExistProjectPopUp.width - width - cmb_openExistProjectPopUp.rightPadding
                            y: cmb_openExistProjectPopUp.topPadding + (cmb_openExistProjectPopUp.availableHeight - height) / 2
                            width: 12
                            height: 8
                            contextType: "2d"

                            Connections {
                                target: cmb_openExistProjectPopUp
                                onPressedChanged: cmb_openExistProjectPopUp_canvas.requestPaint()
                            }

                            onPaint: {
                                context.reset();
                                context.moveTo(0, 0);
                                context.lineTo(width, 0);
                                context.lineTo(width / 2, height);
                                context.closePath();
                                context.fillStyle = cmb_openExistProjectPopUp.pressed ? "#046380" : "#EFECCA";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_openExistProjectPopUp.indicator.width + cmb_openExistProjectPopUp.spacing

                            text: cmb_openExistProjectPopUp.displayText
                            font: cmb_openExistProjectPopUp.font
                            color: cmb_openExistProjectPopUp.pressed ? "#046380" : "#EFECCA"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_openExistProjectPopUp.pressed ? "#046380" : "#EFECCA"
                            border.width: cmb_openExistProjectPopUp.visualFocus ? 2 : 1
                            color: "#046380"
                            radius: 2
                        }

                        popup: Popup {
                            y: cmb_openExistProjectPopUp.height - 1
                            width: cmb_openExistProjectPopUp.width
                            implicitHeight: contentItem.implicitHeight
                            padding: 1

                            contentItem: ListView {
                                clip: true
                                implicitHeight: contentHeight
                                model: cmb_openExistProjectPopUp.popup.visible ? cmb_openExistProjectPopUp.delegateModel : null
                                currentIndex: cmb_openExistProjectPopUp.highlightedIndex

                                ScrollIndicator.vertical: ScrollIndicator { }
                            }

                            background: Rectangle {
                                border.color: "#EFECCA"
                                color: "#046380"
                                radius: 5
                            }
                        }
                        onActivated:{

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
                            openExistProjectPopUp.close()
                        }
                    }
                    MButton {
                        _text: "Open"
                        _width:parent.width * 1/4
                        height: parent.height
                        onBtnClick:
                        {
                            _current_prj_name=cmb_openExistProjectPopUp.currentText
                            openPrj(_defaultPrjPath+"/"+_current_prj_name+"/final.code")
                            _have_active_prj=true
                            openExistProjectPopUp.close()
                        }
                    }
                }
            }
        }
    }

    Item {
            id: shortcuts
            Shortcut {
                sequence: "Ctrl+1"
                onActivated: {
                    if(editorCount >= 1) tabBar.setCurrentIndex(0)
                }
            }
            Shortcut {
                sequence: "Ctrl+2"
                onActivated: {
                    if(editorCount >= 2) tabBar.setCurrentIndex(1)
                }
            }
            Shortcut {
                sequence: "Ctrl+3"
                onActivated: {
                    if(editorCount >= 3) tabBar.setCurrentIndex(2)
                }
            }
            Shortcut {
                sequence: "Ctrl+4"
                onActivated: {
                    if(editorCount >= 4) tabBar.setCurrentIndex(3)
                }
            }
            Shortcut {
                sequence: "Ctrl+5"
                onActivated: {
                    if(editorCount >= 5) tabBar.setCurrentIndex(4)
                }
            }
            Shortcut {
                sequence: "Ctrl+6"
                onActivated: {
                    if(editorCount >= 6) tabBar.setCurrentIndex(5)
                }
            }
            Shortcut {
                sequence: "Ctrl+7"
                onActivated: {
                    if(editorCount >= 7) tabBar.setCurrentIndex(6)
                }
            }
            Shortcut {
                sequence: "Ctrl+8"
                onActivated: {
                    if(editorCount >= 8) tabBar.setCurrentIndex(7)
                }
            }
            Shortcut {
                sequence: "Ctrl+9"
                onActivated: {
                    if(editorCount >= 9) tabBar.setCurrentIndex(8)
                }
            }
            Shortcut {
                sequence: "Ctrl+0"
                onActivated: {
                    if(editorCount >= 10) tabBar.setCurrentIndex(9)
                }
            }
            Shortcut {
                sequence: StandardKey.New
                onActivated: {
                    newTab()
                }
            }
            Shortcut {
                sequence: StandardKey.AddTab
                onActivated: {
                    newTab()
                }
            }
            Shortcut {
                sequence: StandardKey.Open
                onActivated: {
                    openTab()
                }
            }

            Shortcut {
                sequence: StandardKey.Save
                onActivated: {
                    currentEditor.save()
                }
            }

            Shortcut {
                sequence: StandardKey.Close
                onActivated: {
                    closeTab()
                }
            }

            Shortcut {
                sequence: StandardKey.SaveAs
                onActivated: {
                    currentEditor.saveAs()
                }
            }
        }
}
