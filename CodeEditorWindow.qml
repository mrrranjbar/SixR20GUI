import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2
import Qt.labs.folderlistmodel 2.2
import CodeEditorWindow 1.0
Item {
    id: root
    anchors.fill: parent
    property CodeEditor currentEditor: (stackLayout.currentIndex==-1) ? null : stackLayout.itemAt(stackLayout.currentIndex)
    property CodeEditorTabButton currentTabButton: (tabBar.currentIndex==-1) ? null : tabBar.itemAt(tabBar.currentIndex)
    property CodeEditor interruptEditor:null
    property CodeEditorTabButton interruptTab: null
    property CodeEditor functionEditor:null
    property CodeEditorTabButton functionTab: null
    property alias editorCount: stackLayout.count
    property string prjPath: ""
    property bool newRequest:false
    //    Component.onCompleted: {
    //        initTabs()
    //        focusCurrentEditor()
    //    }
    function initEditor(){
        fileDialogSave.visible=true
    }

    function focusCurrentEditor() {
        var indexOfCurrentTab = stackLayout.currentIndex
        currentEditor = stackLayout.itemAt(indexOfCurrentTab)
        currentTabButton = tabBar.itemAt(indexOfCurrentTab)
        currentEditor.textArea.focus = true
    }
    function newPrj(){
        openPrjFromPath()
        saveFile(prjPath, "")
        initTabs()
    }

    function openPrj(){
        fileDialogLoad.nameFilters= [ "SixR files (*.six)", "All files (*)" ]
        fileDialogLoad.cb = function() {
            prjPath =fileDialogLoad.fileUrl
            openPrjFromPath()
        }
        fileDialogLoad.visible = true
    }
    function openPrjFromPath(){
        closeAllTab();
        var response = openFile(prjPath)
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
        if(urlExists(prjPath+".mnr")){
            projectEditor.open(prjPath+".mnr")
        }
    }

    function newMainTab(){
        var newCodeEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
        var newTabButton = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
        newTabButton.codeEditor = newCodeEditor
        newCodeEditor.setFileUrl(prjPath.replace(".six",".mnr"))
        newCodeEditor.changedSinceLastSave = false
        newCodeEditor.title="main.mnr"
        newCodeEditor.text="main()\r\nend"
        tabBar.setCurrentIndex(tabBar.count-1) // select it
        newTabButton.color = "#fff" // Hack since focus isn't set correctly when it's the first tab?
        focusCurrentEditor()
        newCodeEditor.save()
    }
    function newFunctionTab(){
        var newCodeEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
        var newTabButton = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
        newCodeEditor.title="func.mnr"
        newTabButton.codeEditor = newCodeEditor
        newCodeEditor.changedSinceLastSave = false
        newCodeEditor.save()
    }
    function initTabs(){
        closeAllTab()
        newMainTab()
        //newFunctionTab()
    }
    function newTab() {
        var newCodeEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
        var newTabButton = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
        newTabButton.codeEditor = newCodeEditor
        newCodeEditor.changedSinceLastSave = false
        tabBar.setCurrentIndex(tabBar.count-1) // select it
        newTabButton.color = "#fff" // Hack since focus isn't set correctly when it's the first tab?
        focusCurrentEditor()
        newCodeEditor.save()
        refreshProjectFiles()
    }
    function showDoYouWantToSave(fileName) {
        messageDialog.text = "Do you want to save the changes you made to "+fileName+"?"
        messageDialog.visible = true
    }
    function closeAllTab(){
        while(editorCount>0){
            var indexOfCurrentTab = 0//stackLayout.currentIndex
            //var editor = currentEditor
            currentEditor = stackLayout.itemAt(indexOfCurrentTab)
            currentTabButton = tabBar.itemAt(indexOfCurrentTab)
            currentTabButton.codeEditor = null
            currentEditor.parent = null
            currentEditor.destroy()
            tabBar.removeItem(indexOfCurrentTab)

        }

    }
    function closeTab() {
        focusCurrentEditor()
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
            newMainTab()
        }
    }
    function refreshProjectFiles(){
        if(prjPath=="")
            return
        var indexOfCurrentTab = 0
        var fileNames=[]
        var fileUrls = ""
        var projectContain=""
        while(editorCount>indexOfCurrentTab){
            currentEditor = stackLayout.itemAt(indexOfCurrentTab)
            if(currentEditor.changedSinceLastSave){
                currentEditor.save()
            }
            fileNames.push(currentEditor.fileName)
            fileUrls += currentEditor.fileUrl+"\n"
            projectContain += currentEditor.text+"\n"
            indexOfCurrentTab++
        }
        if(projectContain!=projectEditor.text){
            saveFile(prjPath+".mnr", projectContain)
            saveFile(prjPath, fileUrls)
            projectEditor.open(prjPath+".mnr")
        }
    }

    function playProject(){
        refreshProjectFiles()
        projectEditor.play(runFromLine.textInput.text)
    }
    function puaseCurrentTab(){
        projectEditor.pause()
    }
    function stopCurrentTab(){
        projectEditor.stop()
    }
    function openTab() {
        fileDialogLoad.nameFilters= [ "Program files (*.mnr)", "All files (*)" ]
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
    function urlExists(testUrl) {
        var request = new XMLHttpRequest();
        request.open("GET", testUrl, false);
        request.send(null);
        return request.status==200;
    }
    function openFile(fileUrl){
        fileio.setSource(fileUrl)
        fileio.read()
        return fileio.text
    }

    function saveFile(fileUrl, text){
        fileio.setSource(fileUrl)
        fileio.text=text
        fileio.write()
    }
    function checkData(){
        newRequest=true;
    }
    FileIO{
        id: fileio
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
                width: parent.width-closeTabButton.width - newTabButton.width - openTabButton.width
                CodeEditorTabButton {
                    text: codeEditor_1.title
                    codeEditor: codeEditor_1
                }
            }

            MButton {
                _width: 100
                _height: 35
                id: newTabButton
                _text: "New File"
                onBtnClick: {
                    newTab()
                }
            }
            MButton {
                _width: 100
                _height: 35
                id: openTabButton
                _text: "Open File"
                onBtnClick: {
                    openTab()
                }
            }
        }
        RowLayout {
            Layout.fillWidth: true
            spacing: 0
            StackLayout {
                id:stackLayout2
                visible: false
                CodeEditor {
                    id: projectEditor
                    Component.onCompleted: {
                        changedSinceLastSave = false
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
            Column{
                MLabel{
                    _text:"Project"
                }
                MButton {
                    _width: 60
                    _height: 35
                    id: newPrjButton
                    _text: "New"
                    onBtnClick: {//initialize
                        fileDialogSave.visible=true
                        //                        newPrj()
                    }
                }
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
                    id: savePrjButton
                    _text: "Save"
                    onBtnClick: {
                        refreshProjectFiles()
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
                MTextField{
                    visible: false
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
        }
        Row {
            Layout.fillWidth: true
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
                        focusCurrentEditor()
                        if(radioGroup.selectedIndex==9){
                            if(functionEditor==null){
                                functionEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
                                functionTab = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
                                functionTab.codeEditor = functionEditor
                                functionEditor.title="function.mnr"
                                functionEditor.save()
                            }
                            //functionEditor.insertCMD(radioGroup.selectedIndex,myComboBoxTeachP1.currentText, myComboBoxTeachP2.currentText, myComboBoxTeachP3.currentText, myComboBoxSetFrT.currentText,myComboBoxSetFrP.currentText,"F "+myFF.textInput.text+" CON "+myCON.textInput.text+" Approx "+myApprx.textInput.text, "Theta "+myTheta.textInput.text, myExp1.textInput.text, myExp2.textInput.text, myId.textInput.text);
                            currentEditor = functionEditor
                            currentTabButton = functionTab
                            currentEditor.textArea.focus = true
                        }else if(radioGroup.selectedIndex==5){
                            if(interruptEditor==null){
                                interruptEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
                                interruptTab = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
                                interruptTab.codeEditor = interruptEditor
                                interruptEditor.title="interrupt.mnr"
                                interruptEditor.save()
                            }
                            //interruptEditor.insertCMD(radioGroup.selectedIndex,myComboBoxTeachP1.currentText, myComboBoxTeachP2.currentText, myComboBoxTeachP3.currentText, myComboBoxSetFrT.currentText,myComboBoxSetFrP.currentText,"F "+myFF.textInput.text+" CON "+myCON.textInput.text+" Approx "+myApprx.textInput.text, "Theta "+myTheta.textInput.text, myExp1.textInput.text, myExp2.textInput.text, myId.textInput.text);
                            currentEditor = interruptEditor
                            currentTabButton = interruptTab
                            currentEditor.textArea.focus = true
                        }
                        currentEditor.insertCMD(radioGroup.selectedIndex,myComboBoxTeachP1.currentText, myComboBoxTeachP2.currentText, myComboBoxTeachP3.currentText, myComboBoxSetFrT.currentText,myComboBoxSetFrP.currentText,"F "+myFF.textInput.text+" CON "+myCON.textInput.text+" Approx "+myApprx.textInput.text, "Theta "+myTheta.textInput.text, myExp1.textInput.text, myExp2.textInput.text, myId.textInput.text);
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


                    }
                    Row{
                        Layout.fillWidth: true
                        RadioButton {
                            text: qsTr("Interrupt")
                            ButtonGroup.group: radioGroup
                            onCheckedChanged: radioGroup.selectedIndex = 5
                        }
                        RadioButton {
                            text: qsTr("Function")
                            ButtonGroup.group: radioGroup
                            onCheckedChanged: radioGroup.selectedIndex = 9
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
                                _text:"10"
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
                                visible:  (radioGroup.selectedIndex == 2 || radioGroup.selectedIndex == 5 || radioGroup.selectedIndex==9)
                                Text {
                                    anchors.verticalCenter: parent.verticalCenter
                                    //                        width: 2
                                    text: (radioGroup.selectedIndex==9)?qsTr("name:"):qsTr("ID:")
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
                                    text: (radioGroup.selectedIndex==9)?qsTr("return:"):((radioGroup.selectedIndex==0 || radioGroup.selectedIndex==1 || radioGroup.selectedIndex==3 || radioGroup.selectedIndex==5)?qsTr("Condition:"):qsTr("Expression1:"))
                                }
                                MTextField{
                                    id:myExp1
                                    _text:"0"
                                }
                            }

                            Row{
                                visible:  radioGroup.selectedIndex == 2 || radioGroup.selectedIndex == 9
                                Text {
                                    anchors.verticalCenter: parent.verticalCenter
                                    text: (radioGroup.selectedIndex==9)?qsTr("arguments:"):qsTr("Expression2:")
                                }
                                MTextField{
                                    id:myExp2
                                    _text:"0"
                                }
                            }
                        }
//                        Row{
//                            visible: (radioGroup.selectedIndex == 5||radioGroup.selectedIndex == 9)
//                        }
                    }
                }
            }
        }

    }
    FileDialog {
        id: fileDialogSave
        selectExisting : false
        property var cb
        title: "Please choose a location to save"
        nameFilters: [ "SixR files (*.six)", "All files (*)" ]
        onAccepted: {
            prjPath = fileDialogSave.fileUrl//+".six"
            var ext = prjPath.split(".").pop()
            if(ext!="six"){
                prjPath+=".six"
            }
            newPrj()
            if(cb != undefined) {
                cb()
                cb = null
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
