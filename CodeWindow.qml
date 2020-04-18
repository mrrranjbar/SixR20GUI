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
    function openPrjFromPath(path){
        if(urlExists(path)){
            projectEditor.open(path)
        }
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
            openPrjFromPath(prjPath+".mnr")
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
                    openPrj()
                }
            }
            MButton {
                _width: 60
                _height: 35
                id: playCurrentTabButton
                _text: "Start"
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
