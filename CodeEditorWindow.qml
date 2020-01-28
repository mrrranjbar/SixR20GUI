import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2

Item {
    anchors.fill: parent
    property CodeEditor currentEditor: (stackLayout.currentIndex==-1) ? null : stackLayout.itemAt(stackLayout.currentIndex)
    property CodeEditorTabButton currentTabButton: (tabBar.currentIndex==-1) ? null : tabBar.itemAt(tabBar.currentIndex)
    property alias editorCount: stackLayout.count

    Component.onCompleted: {
        focusCurrentEditor()
    }

    function focusCurrentEditor() {
        if(currentEditor) currentEditor.textArea.focus = true
    }

    function newTab() {
        var newCodeEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
        var newTabButton = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
        newTabButton.codeEditor = newCodeEditor
        newCodeEditor.changedSinceLastSave = false
        tabBar.setCurrentIndex(tabBar.count-1) // select it
        newTabButton.color = "#fff" // Hack since focus isn't set correctly when it's the first tab?
        focusCurrentEditor()
    }

    function showDoYouWantToSave(fileName) {
        messageDialog.text = "Do you want to save the changes you made to "+fileName+"?"
        messageDialog.visible = true
    }

    function closeTab() {
        if(currentEditor === null) return;

        if(currentEditor.changedSinceLastSave) {
            // Ask user to save the file before we close the tab

            messageDialog.cb = function() {
                // Callback is to close the tab
                var indexOfCurrentTab = stackLayout.currentIndex
                var editor = currentEditor
                currentTabButton.codeEditor = null
                currentEditor.parent = null
                editor.destroy()
                tabBar.removeItem(indexOfCurrentTab)
                messageDialog.cb = null
            }

            showDoYouWantToSave(currentEditor.fileName)
        } else {
            var indexOfCurrentTab = stackLayout.currentIndex
            var editor = currentEditor

            currentTabButton.codeEditor = null
            currentEditor.parent = null
            editor.destroy()
            tabBar.removeItem(indexOfCurrentTab)
            messageDialog.cb = null
        }

        if(editorCount == 0) {
            newTab()
        }
    }
    function playCurrentTab(){
        if(currentEditor.changedSinceLastSave){
            // Ask user to save the file before we play the tab
            messageDialog.saveOnly=1;
            //            messageDialog.cb = function() {
            //                // Callback is to play the tab
            //                currentEditor.save()
            //                messageDialog.cb=null
            //            }
            showDoYouWantToSave(currentEditor.fileName)
        }else
            currentEditor.play(runFromLine.textInput.text)
    }
    function puaseCurrentTab(){
        currentEditor.pause()
    }
    function programReadyCurrentTab(){
        currentEditor.programReady()
    }
    function stopCurrentTab(){
        currentEditor.stop()
    }
    function openTab() {
        fileDialogLoad.cb = function() {
            if(currentEditor.title === "untitled" && currentEditor.text === "") {
                currentEditor.open(fileDialogLoad.fileUrl)
            } else {
                fileDialogLoad.fileUrl.toString()
                var newCodeEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
                var newTabButton = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
                newTabButton.codeEditor = newCodeEditor
                newCodeEditor.open(fileDialogLoad.fileUrl)
                newCodeEditor.changedSinceLastSave = false
                tabBar.setCurrentIndex(tabBar.count-1)
                newTabButton.color = "#fff" // Hack since focus isn't set correctly when it's the first tab?
                focusCurrentEditor()
            }

        }
        fileDialogLoad.visible = true
    }


    ColumnLayout {
        anchors.fill: parent
        spacing: 0
        Row {
            Layout.fillWidth: true
            spacing: 1
            MButton {
                _width: 30
                _height: 35
                id: closeTabButton
                _text: "x"
                onBtnClick: {
                    closeTab()
                }
            }
            TabBar {
                id: tabBar
                width: parent.width / 2 - 50//parent.width - newTabButton.width - openTabButton.width - playCurrentTabButton.width - pauseCurrentTabButton.width - stopCurrentTabButton.width - loadCurrentTabButton

                CodeEditorTabButton {
                    text: codeEditor_1.title
                    codeEditor: codeEditor_1
                }
            }

            MButton {
                _width: 60
                _height: 35
                id: newTabButton
                _text: "New"
                onBtnClick: {
                    newTab()
                }
            }
            MButton {
                _width: 60
                _height: 35
                id: openTabButton
                _text: "Open"
                onBtnClick: {
                    openTab()
                }
            }
            MButton {
                _width: 60
                _height: 35
                id: programCurrentTabButton
                _text: "Load"
                onBtnClick: {
                    programReadyCurrentTab()
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
                    playCurrentTab()
                }
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
            id: stackLayout
            Layout.fillWidth: true
            Layout.fillHeight: true
            currentIndex: tabBar.currentIndex

            CodeEditor {
                id: codeEditor_1
                Component.onCompleted: {
                    changedSinceLastSave = false
                }
            }
        }
        Row {
            Layout.fillWidth: true

            Column{
                Row{
                    Text {
                        anchors.verticalCenter: parent.verticalCenter
                        text: qsTr("Run From Line: ")
                    }
                    MTextField{
                        id: runFromLine
                        _text:"-1"
                    }
                }
                Row{
                    MButton {
                        property string frameType: "TOOL"
                        property string targetPoint: ""
                        _width : 60
                        _height :40
                        id: btnMovement
                        _text: "Add"
                        height: parent.height
                        onBtnClick:{
                            currentEditor.insertCMD(radioGroup.selectedIndex,myComboBoxTeachP1.currentText, myComboBoxTeachP2.currentText, myComboBoxTeachP3.currentText, myComboBoxSetFrT.currentText,myComboBoxSetFrP.currentText,"F: "+myFF.textInput.text+" CON: "+myCON.textInput.text+" "+myApprx.textInput.text, "Theta: "+myTheta.textInput.text, myExp1.textInput.text, myExp2.textInput.text, myId.textInput.text);
                        }
                    }

                    ButtonGroup {
                        id: radioGroup
                        property int selectedIndex : 6
                        //                onCheckedButtonChanged:
                        //                    console.log("clicked:", selectedIndex)
                    }
                    Column{
                        Row {
                            Layout.fillWidth: true
                            RadioButton {
                                checked: true
                                text: qsTr("PTP")
                                ButtonGroup.group: radioGroup
                                onCheckedChanged: radioGroup.selectedIndex = 6
                            }
                            RadioButton {
                                text: qsTr("LIN")
                                ButtonGroup.group: radioGroup
                                onCheckedChanged: radioGroup.selectedIndex = 7
                            }
                            RadioButton {
                                text: qsTr("CIRC")
                                ButtonGroup.group: radioGroup
                                onCheckedChanged: radioGroup.selectedIndex = 8
                            }
                            RadioButton {
                                text: qsTr("SET Frame")
                                ButtonGroup.group: radioGroup
                                onCheckedChanged: radioGroup.selectedIndex = 4
                            }
                            ComboBox {
                                visible: (radioGroup.selectedIndex == 6 || radioGroup.selectedIndex == 7 || radioGroup.selectedIndex == 8)
                                //width: 200
                                id: myComboBoxTeachP1
                                model: myTeachPointModel
                                //                        onCurrentTextChanged: {
                                //                            console.log(myComboBoxTeachP1.currentText)
                                //                        }
                            }
                            ComboBox {
                                visible: radioGroup.selectedIndex == 8
                                //width: 200
                                id: myComboBoxTeachP2
                                model: myTeachPointModel
                                //                        onCurrentTextChanged: {
                                //                            console.log(myComboBoxTeachP2.currentText)
                                //                        }
                            }
                            ComboBox {
                                visible: false//radioGroup.selectedIndex == 8
                                //width: 200
                                id: myComboBoxTeachP3
                                model: myTeachPointModel
                                //                        onCurrentTextChanged: {
                                //                            console.log(myComboBoxTeachP3.currentText)
                                //                        }
                            }
                            ComboBox {
                                visible: radioGroup.selectedIndex == 4
                                //width: 200
                                id: myComboBoxSetFrT
                                model: ["TOOL", "BASE", "OBJECT", "TSAK"]
                                //                        onCurrentTextChanged: {
                                //                            console.log(myComboBoxSetFrT.currentText)
                                //                        }
                            }
                            ComboBox {
                                visible: radioGroup.selectedIndex == 4
                                //width: 200
                                id: myComboBoxSetFrP
                                model: myTeachFrameModel
                                //                        onCurrentTextChanged: {
                                //                            console.log(myComboBoxSetFrP.currentText)
                                //                        }
                            }

                        }
                        Row {
                            Layout.fillWidth: true
                            RadioButton {
                                text: qsTr("IF")
                                ButtonGroup.group: radioGroup
                                onCheckedChanged: radioGroup.selectedIndex = 0
                            }
                            RadioButton {
                                text: qsTr("IF ELESE")
                                ButtonGroup.group: radioGroup
                                onCheckedChanged: radioGroup.selectedIndex = 1
                            }
                            RadioButton {
                                text: qsTr("FOR")
                                ButtonGroup.group: radioGroup
                                onCheckedChanged: radioGroup.selectedIndex = 2
                            }
                            RadioButton {
                                text: qsTr("WHILE")
                                ButtonGroup.group: radioGroup
                                onCheckedChanged: radioGroup.selectedIndex = 3
                            }

                            RadioButton {
                                text: qsTr("Interrupt")
                                ButtonGroup.group: radioGroup
                                onCheckedChanged: radioGroup.selectedIndex = 5
                            }
                        }
                        Row{
                            Layout.fillWidth: true
                            Row{
                                visible:  radioGroup.selectedIndex == 8
                                Text {
                                    anchors.verticalCenter: parent.verticalCenter
                                    //                        width: 2
                                    text: qsTr("Theta:")
                                }
                                MTextField{
                                    id: myTheta
                                    _text:"0"
                                }
                            }
                            Row{
                                visible: (radioGroup.selectedIndex == 6 || radioGroup.selectedIndex == 7 || radioGroup.selectedIndex == 8)
                                Text {
                                    anchors.verticalCenter: parent.verticalCenter
                                    //                        width: 2
                                    text: qsTr("F:")
                                }
                                MTextField{
                                    id: myFF
                                    _text:"0"
                                }
                                Text {
                                    anchors.verticalCenter: parent.verticalCenter
                                    //                        width: 2
                                    text: qsTr("CON:")
                                }
                                MTextField{
                                    id:myCON

                                    _text:"0"
                                }
                                Text {
                                    anchors.verticalCenter: parent.verticalCenter
                                    //                        width: 2
                                    text: qsTr("Approx:")
                                }
                                MTextField{
                                    id:myApprx

                                    _text:"0"
                                }
                            }
                            Row{
                                visible: !(radioGroup.selectedIndex == 6 || radioGroup.selectedIndex == 7 || radioGroup.selectedIndex == 8)
                                Row{
                                    visible:  (radioGroup.selectedIndex == 2 || radioGroup.selectedIndex == 5)
                                    Text {
                                        anchors.verticalCenter: parent.verticalCenter
                                        //                        width: 2
                                        text: qsTr("ID:")
                                    }
                                    MTextField{
                                        id: myId

                                        _text:"0"
                                    }
                                }
                                Row{
                                    visible:  (radioGroup.selectedIndex != 4 )
                                    Text {
                                        anchors.verticalCenter: parent.verticalCenter
                                        //                        width: 2
                                        text: qsTr("Expression1:")
                                    }
                                    MTextField{
                                        id:myExp1
                                        _text:"0"
                                    }
                                }

                                Row{
                                    visible:  radioGroup.selectedIndex == 2
                                    Text {
                                        anchors.verticalCenter: parent.verticalCenter
                                        //                        width: 2
                                        text: qsTr("Expression2:")
                                    }
                                    MTextField{
                                        id:myExp2
                                        _text:"0"
                                    }
                                }

                            }

                        }
                    }
                }
            }
        }
    }

    FileDialog { //MRR
        id: fileDialogLoad
        selectExisting : true
        property var cb
        title: "Please choose a file"

        onAccepted: {
            cb()
            cb = undefined
        }
    }

    MessageDialog {
        id: messageDialog
        property var cb
        property int saveAndClose:-1
        property int saveOnly:-1
        title: "Save Changes"
        text: "Do you want to save the changes you made to "
        standardButtons: StandardButton.Save  | StandardButton.Discard | StandardButton.Cancel
        onAccepted: {
            currentEditor.save(function() {
                if(saveOnly==1){
                    currentEditor.changedSinceLastSave = false
                    currentEditor.play()
                    saveOnly=-1
                }else{
                    console.log("Save dialog callback and cancel: ", currentEditor.cancelCloseEditor)
                    if(!currentEditor.cancelCloseEditor) {
                        closeTab()
                    }
                    currentEditor.cancelCloseEditor = false
                }
            })
        }

        onDiscard: {
            if(saveOnly==1){
                currentEditor.play()
                saveOnly=-1
            }else{
                currentEditor.changedSinceLastSave = false
                closeTab()
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
