import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import Qt.labs.folderlistmodel 2.2

Item {
    anchors.fill: parent
    property string prjPath: ""
    Component.onCompleted: {
        //openPrj()
    }


    function urlExists(testUrl) {
        var request = new XMLHttpRequest();
        request.open("GET", testUrl, false);
        request.send(null);
        return request.status==200;
    }
    function openPrj(){
        fileDialogLoad.nameFilters= [ "SixR files (*.six)", "All files (*)" ]
        fileDialogLoad.cb = function() {
            var xhr = new XMLHttpRequest;
            prjPath =fileDialogLoad.fileUrl
            xhr.open("GET", fileDialogLoad.fileUrl);
            //var path ="/"+fileDialogLoad.folder.toLocaleString().replace("file:///","")+"/"
            xhr.onreadystatechange = function() {
                if (xhr.readyState == XMLHttpRequest.DONE) {
                    var response = xhr.responseText;
                    var files = response.split(("\n"))
                    for(var i in files){
                        if(files[i]){
                            var newCodeEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
                            var newTabButton = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
                            newTabButton.codeEditor = newCodeEditor
                            newCodeEditor.open(files[i])//path+files[i])
                            newCodeEditor.changedSinceLastSave = false
                            tabBar.setCurrentIndex(tabBar.count-1)
                            newTabButton.color = "#fff" // Hack since focus isn't set correctly when it's the first tab?
                        }
                    }
                }
            };
            xhr.send();
            if(urlExists(prjPath+".mnr")){
                projectEditor.open(prjPath+".mnr")
            }
        }
        fileDialogLoad.visible = true
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

    ColumnLayout {
        anchors.fill: parent
        spacing: 0
        Row {
            Layout.fillWidth: true
            spacing: 1
            MButton {
                _width: 60
                _height: 35
                id: openPrjButton
                _text: "Open"
                onBtnClick: {
                    openPrj()
                }
            }
            MButton {
                _width: 60
                _height: 35
                id: playCurrentTabButton
                _text: "Play"
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
                }
            }
            Text {
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("From Line")
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
                onBtnClick: {
                    pauseCurrentTabButton._text="Pause"
                    pauseCurrentTabButton._background.color = "white"
                    //if(text: "Play")
                    stopCurrentTab()
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

    Item {
        id: shortcuts
        Shortcut {
            sequence: StandardKey.Open
            onActivated: {
                openPrj()
            }
        }
    }

}
