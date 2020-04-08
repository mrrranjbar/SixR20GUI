//import QtQuick 2.7
//import QtQuick.Controls 2.0
//import QtQuick.Layouts 1.3
//import QtQuick.Dialogs 1.2
//import Qt.labs.folderlistmodel 2.2
//import CodeEditorWindow 1.0
//Item {
//    id: root
//    anchors.fill: parent
//    property CodeEditor currentEditor: (stackLayout.currentIndex==-1) ? null : stackLayout.itemAt(stackLayout.currentIndex)
//    property CodeEditorTabButton currentTabButton: (tabBar.currentIndex==-1) ? null : tabBar.itemAt(tabBar.currentIndex)
//    property CodeEditor interruptEditor:null
//    property CodeEditorTabButton interruptTab: null
//    property CodeEditor functionEditor:null
//    property CodeEditorTabButton functionTab: null
//    property alias editorCount: stackLayout.count
//    property string prjPath: ""
//    property bool newRequest:false
//    //    Component.onCompleted: {
//    //        initTabs()
//    //        focusCurrentEditor()
//    //    }
//    function initEditor(){
//        fileDialogSave.visible=true
//    }

//    function focusCurrentEditor() {
//        var indexOfCurrentTab = stackLayout.currentIndex
//        currentEditor = stackLayout.itemAt(indexOfCurrentTab)
//        currentTabButton = tabBar.itemAt(indexOfCurrentTab)
//        currentEditor.textArea.focus = true
//    }
//    function newPrj(){
//        openPrjFromPath()
//        saveFile(prjPath, "")
//        initTabs()
//    }

//    function openPrj(){
//        fileDialogLoad.nameFilters= [ "SixR files (*.six)", "All files (*)" ]
//        fileDialogLoad.cb = function() {
//            prjPath =fileDialogLoad.fileUrl
//            openPrjFromPath()
//        }
//        fileDialogLoad.visible = true
//    }
//    function openPrjFromPath(){
//        closeAllTab();
//        var response = openFile(prjPath)
//        var files = response.split(("\n"))
//        for(var i in files){
//            if(files[i]){
//                var newCodeEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
//                var newTabButton = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
//                newTabButton.codeEditor = newCodeEditor
//                newCodeEditor.open(files[i])//path+files[i])
//                newCodeEditor.changedSinceLastSave = false
//                tabBar.setCurrentIndex(tabBar.count-1)
//                newTabButton.color = "#fff" // Hack since focus isn't set correctly when it's the first tab?
//            }
//        }
//        if(urlExists(prjPath+".mnr")){
//            projectEditor.open(prjPath+".mnr")
//        }
//    }

//    function newMainTab(){
//        var newCodeEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
//        var newTabButton = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
//        newTabButton.codeEditor = newCodeEditor
//        newCodeEditor.setFileUrl(prjPath.replace(".six",".mnr"))
//        newCodeEditor.changedSinceLastSave = false
//        newCodeEditor.title="main.mnr"
//        newCodeEditor.text="main()\r\nend"
//        tabBar.setCurrentIndex(tabBar.count-1) // select it
//        newTabButton.color = "#fff" // Hack since focus isn't set correctly when it's the first tab?
//        focusCurrentEditor()
//        newCodeEditor.save()
//    }
//    function newFunctionTab(){
//        var newCodeEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
//        var newTabButton = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
//        newCodeEditor.title="func.mnr"
//        newTabButton.codeEditor = newCodeEditor
//        newCodeEditor.changedSinceLastSave = false
//        newCodeEditor.save()
//    }
//    function initTabs(){
//        closeAllTab()
//        newMainTab()
//        //newFunctionTab()
//    }
//    function newTab() {
//        var newCodeEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
//        var newTabButton = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
//        newTabButton.codeEditor = newCodeEditor
//        newCodeEditor.changedSinceLastSave = false
//        tabBar.setCurrentIndex(tabBar.count-1) // select it
//        newTabButton.color = "#fff" // Hack since focus isn't set correctly when it's the first tab?
//        focusCurrentEditor()
//        newCodeEditor.save()
//        refreshProjectFiles()
//    }
//    function showDoYouWantToSave(fileName) {
//        messageDialog.text = "Do you want to save the changes you made to "+fileName+"?"
//        messageDialog.visible = true
//    }
//    function closeAllTab(){
//        while(editorCount>0){
//            var indexOfCurrentTab = 0//stackLayout.currentIndex
//            //var editor = currentEditor
//            currentEditor = stackLayout.itemAt(indexOfCurrentTab)
//            currentTabButton = tabBar.itemAt(indexOfCurrentTab)
//            currentTabButton.codeEditor = null
//            currentEditor.parent = null
//            currentEditor.destroy()
//            tabBar.removeItem(indexOfCurrentTab)

//        }

//    }
//    function closeTab() {
//        focusCurrentEditor()
//        if(currentEditor === null) return;

//        if(currentEditor.changedSinceLastSave) {
//            // Ask user to save the file before we close the tab

//            messageDialog.cb = function() {
//                // Callback is to close the tab
//                var indexOfCurrentTab = stackLayout.currentIndex
//                var editor = currentEditor
//                currentTabButton.codeEditor = null
//                currentEditor.parent = null
//                editor.destroy()
//                tabBar.removeItem(indexOfCurrentTab)
//                messageDialog.cb = null
//            }

//            showDoYouWantToSave(currentEditor.fileName)
//        } else {
//            var indexOfCurrentTab = stackLayout.currentIndex
//            var editor = currentEditor

//            currentTabButton.codeEditor = null
//            currentEditor.parent = null
//            editor.destroy()
//            tabBar.removeItem(indexOfCurrentTab)
//            messageDialog.cb = null
//        }

//        if(editorCount == 0) {
//            newMainTab()
//        }
//    }
//    function refreshProjectFiles(){
//        if(prjPath=="")
//            return
//        var indexOfCurrentTab = 0
//        var fileNames=[]
//        var fileUrls = ""
//        var projectContain=""
//        while(editorCount>indexOfCurrentTab){
//            currentEditor = stackLayout.itemAt(indexOfCurrentTab)
//            if(currentEditor.changedSinceLastSave){
//                currentEditor.save()
//            }
//            fileNames.push(currentEditor.fileName)
//            fileUrls += currentEditor.fileUrl+"\n"
//            projectContain += currentEditor.text+"\n"
//            indexOfCurrentTab++
//        }
//        if(projectContain!=projectEditor.text){
//            saveFile(prjPath+".mnr", projectContain)
//            saveFile(prjPath, fileUrls)
//            projectEditor.open(prjPath+".mnr")
//        }
//    }

//    function playProject(){
//        refreshProjectFiles()
//        projectEditor.play(runFromLine.textInput.text)
//    }
//    function puaseCurrentTab(){
//        projectEditor.pause()
//    }
//    function stopCurrentTab(){
//        projectEditor.stop()
//    }
//    function openTab() {
//        fileDialogLoad.nameFilters= [ "Program files (*.mnr)", "All files (*)" ]
//        fileDialogLoad.cb = function() {
//            if(currentEditor.title === "untitled" && currentEditor.text === "") {
//                currentEditor.open(fileDialogLoad.fileUrl)
//            } else {
//                fileDialogLoad.fileUrl.toString()
//                var newCodeEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
//                var newTabButton = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
//                newTabButton.codeEditor = newCodeEditor
//                newCodeEditor.open(fileDialogLoad.fileUrl)
//                newCodeEditor.changedSinceLastSave = false
//                tabBar.setCurrentIndex(tabBar.count-1)
//                newTabButton.color = "#fff" // Hack since focus isn't set correctly when it's the first tab?
//                focusCurrentEditor()
//            }
//        }
//        fileDialogLoad.visible = true
//    }
//    function urlExists(testUrl) {
//        var request = new XMLHttpRequest();
//        request.open("GET", testUrl, false);
//        request.send(null);
//        return request.status==200;
//    }
//    function openFile(fileUrl){
//        fileio.setSource(fileUrl)
//        fileio.read()
//        return fileio.text
//    }

//    function saveFile(fileUrl, text){
//        fileio.setSource(fileUrl)
//        fileio.text=text
//        fileio.write()
//    }
//    function checkData(){
//        newRequest=true;
//    }
//    FileIO{
//        id: fileio
//    }

//    ColumnLayout {
//        anchors.fill: parent
//        spacing: 0
//        Row {
//            Layout.fillWidth: true
//            spacing: 1
//            MButton {
//                _width: 30
//                _height: 35
//                id: closeTabButton
//                _text: "x"
//                onBtnClick: {
//                    closeTab()
//                }
//            }
//            TabBar {
//                id: tabBar
//                width: parent.width-closeTabButton.width - newTabButton.width - openTabButton.width
//                CodeEditorTabButton {
//                    text: codeEditor_1.title
//                    codeEditor: codeEditor_1
//                }
//            }

//            MButton {
//                _width: 100
//                _height: 35
//                id: newTabButton
//                _text: "New File"
//                onBtnClick: {
//                    newTab()
//                }
//            }
//            MButton {
//                _width: 100
//                _height: 35
//                id: openTabButton
//                _text: "Open File"
//                onBtnClick: {
//                    openTab()
//                }
//            }
//        }
//        RowLayout {
//            Layout.fillWidth: true
//            spacing: 0
//            StackLayout {
//                id:stackLayout2
//                visible: false
//                CodeEditor {
//                    id: projectEditor
//                    Component.onCompleted: {
//                        changedSinceLastSave = false
//                    }
//                }
//            }
//            StackLayout {
//                id: stackLayout
//                Layout.fillWidth: true
//                Layout.fillHeight: true
//                currentIndex: tabBar.currentIndex

//                CodeEditor {
//                    id: codeEditor_1
//                    Component.onCompleted: {
//                        changedSinceLastSave = false
//                    }
//                }
//            }
//            Column{
//                MLabel{
//                    _text:"Project"
//                }
//                MButton {
//                    _width: 60
//                    _height: 35
//                    id: newPrjButton
//                    _text: "New"
//                    onBtnClick: {//initialize
//                        fileDialogSave.visible=true
//                        //                        newPrj()
//                    }
//                }
//                MButton {
//                    _width: 60
//                    _height: 35
//                    id: openPrjButton
//                    _text: "Open"
//                    onBtnClick: {
//                        openPrj()
//                    }
//                }
//                MButton {
//                    _width: 60
//                    _height: 35
//                    id: savePrjButton
//                    _text: "Save"
//                    onBtnClick: {
//                        refreshProjectFiles()
//                    }
//                }
//                MButton {
//                    _width: 60
//                    _height: 35
//                    id: playCurrentTabButton
//                    _text: "Play"
//                    onBtnClick: {
//                        //if(text: "Play")
//                        if(pauseCurrentTabButton._text == "Run"){
//                            stopCurrentTab()
//                            var times = new Date().getTime()
//                            while(new Date().getTime() - times<500);
//                            pauseCurrentTabButton._text="Pause"
//                            pauseCurrentTabButton._background.color = "white"
//                        }
//                        playProject()
//                    }
//                }
//                MTextField{
//                    visible: false
//                    _width:60
//                    id: runFromLine
//                    _text:"-1"
//                }
//                MButton {
//                    _width: 60
//                    _height: 35
//                    id: pauseCurrentTabButton
//                    _text: "Pause"
//                    onBtnClick: {
//                        if(_text== "Pause"){
//                            _background.color = "red"
//                            _text="Run"
//                        }
//                        else{
//                            _background.color = "white"
//                            _text = "Pause"
//                        }
//                        puaseCurrentTab()
//                    }
//                }
//                MButton {
//                    _width: 60
//                    _height: 35
//                    id: stopCurrentTabButton
//                    _text: "Stop"
//                    onBtnClick: {
//                        pauseCurrentTabButton._text="Pause"
//                        pauseCurrentTabButton._background.color = "white"
//                        //if(text: "Play")
//                        stopCurrentTab()
//                    }
//                }
//            }
//        }
//        Row {
//            Layout.fillWidth: true
//            Row{
//                MButton {
//                    property string frameType: "TOOL"
//                    property string targetPoint: ""
//                    _width : 60
//                    _height :40
//                    id: btnMovement
//                    _text: "Add"
//                    height: parent.height
//                    onBtnClick:{
//                        focusCurrentEditor()
//                        if(radioGroup.selectedIndex==9){
//                            if(functionEditor==null){
//                                functionEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
//                                functionTab = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
//                                functionTab.codeEditor = functionEditor
//                                functionEditor.title="function.mnr"
//                                functionEditor.save()
//                            }
//                            //functionEditor.insertCMD(radioGroup.selectedIndex,myComboBoxTeachP1.currentText, myComboBoxTeachP2.currentText, myComboBoxTeachP3.currentText, myComboBoxSetFrT.currentText,myComboBoxSetFrP.currentText,"F "+myFF.textInput.text+" CON "+myCON.textInput.text+" Approx "+myApprx.textInput.text, "Theta "+myTheta.textInput.text, myExp1.textInput.text, myExp2.textInput.text, myId.textInput.text);
//                            currentEditor = functionEditor
//                            currentTabButton = functionTab
//                            currentEditor.textArea.focus = true
//                        }else if(radioGroup.selectedIndex==5){
//                            if(interruptEditor==null){
//                                interruptEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
//                                interruptTab = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
//                                interruptTab.codeEditor = interruptEditor
//                                interruptEditor.title="interrupt.mnr"
//                                interruptEditor.save()
//                            }
//                            //interruptEditor.insertCMD(radioGroup.selectedIndex,myComboBoxTeachP1.currentText, myComboBoxTeachP2.currentText, myComboBoxTeachP3.currentText, myComboBoxSetFrT.currentText,myComboBoxSetFrP.currentText,"F "+myFF.textInput.text+" CON "+myCON.textInput.text+" Approx "+myApprx.textInput.text, "Theta "+myTheta.textInput.text, myExp1.textInput.text, myExp2.textInput.text, myId.textInput.text);
//                            currentEditor = interruptEditor
//                            currentTabButton = interruptTab
//                            currentEditor.textArea.focus = true
//                        }
//                        currentEditor.insertCMD(radioGroup.selectedIndex,myComboBoxTeachP1.currentText, myComboBoxTeachP2.currentText, myComboBoxTeachP3.currentText, myComboBoxSetFrT.currentText,myComboBoxSetFrP.currentText,"F "+myFF.textInput.text+" CON "+myCON.textInput.text+" Approx "+myApprx.textInput.text, "Theta "+myTheta.textInput.text, myExp1.textInput.text, myExp2.textInput.text, myId.textInput.text);
//                    }
//                }

//                ButtonGroup {
//                    id: radioGroup
//                    property int selectedIndex : 6
//                    //                onCheckedButtonChanged:
//                    //                    console.log("clicked:", selectedIndex)
//                }
//                Column{
//                    Row {
//                        Layout.fillWidth: true
//                        RadioButton {
//                            checked: true
//                            text: qsTr("PTP")
//                            ButtonGroup.group: radioGroup
//                            onCheckedChanged: radioGroup.selectedIndex = 6
//                        }
//                        RadioButton {
//                            text: qsTr("LIN")
//                            ButtonGroup.group: radioGroup
//                            onCheckedChanged: radioGroup.selectedIndex = 7
//                        }
//                        RadioButton {
//                            text: qsTr("CIRC")
//                            ButtonGroup.group: radioGroup
//                            onCheckedChanged: radioGroup.selectedIndex = 8
//                        }
//                        RadioButton {
//                            text: qsTr("SET Frame")
//                            ButtonGroup.group: radioGroup
//                            onCheckedChanged: radioGroup.selectedIndex = 4
//                        }
//                        ComboBox {
//                            visible: (radioGroup.selectedIndex == 6 || radioGroup.selectedIndex == 7 || radioGroup.selectedIndex == 8)
//                            //width: 200
//                            id: myComboBoxTeachP1
//                            model: myTeachPointModel
//                            //                        onCurrentTextChanged: {
//                            //                            console.log(myComboBoxTeachP1.currentText)
//                            //                        }
//                        }
//                        ComboBox {
//                            visible: radioGroup.selectedIndex == 8
//                            //width: 200
//                            id: myComboBoxTeachP2
//                            model: myTeachPointModel
//                            //                        onCurrentTextChanged: {
//                            //                            console.log(myComboBoxTeachP2.currentText)
//                            //                        }
//                        }
//                        ComboBox {
//                            visible: false//radioGroup.selectedIndex == 8
//                            //width: 200
//                            id: myComboBoxTeachP3
//                            model: myTeachPointModel
//                            //                        onCurrentTextChanged: {
//                            //                            console.log(myComboBoxTeachP3.currentText)
//                            //                        }
//                        }
//                        ComboBox {
//                            visible: radioGroup.selectedIndex == 4
//                            //width: 200
//                            id: myComboBoxSetFrT
//                            model: ["TOOL", "BASE", "OBJECT", "TSAK"]
//                            //                        onCurrentTextChanged: {
//                            //                            console.log(myComboBoxSetFrT.currentText)
//                            //                        }
//                        }
//                        ComboBox {
//                            visible: radioGroup.selectedIndex == 4
//                            //width: 200
//                            id: myComboBoxSetFrP
//                            model: myTeachFrameModel
//                            //                        onCurrentTextChanged: {
//                            //                            console.log(myComboBoxSetFrP.currentText)
//                            //                        }
//                        }

//                    }
//                    Row {
//                        Layout.fillWidth: true
//                        RadioButton {
//                            text: qsTr("IF")
//                            ButtonGroup.group: radioGroup
//                            onCheckedChanged: radioGroup.selectedIndex = 0
//                        }
//                        RadioButton {
//                            text: qsTr("IF ELESE")
//                            ButtonGroup.group: radioGroup
//                            onCheckedChanged: radioGroup.selectedIndex = 1
//                        }
//                        RadioButton {
//                            text: qsTr("FOR")
//                            ButtonGroup.group: radioGroup
//                            onCheckedChanged: radioGroup.selectedIndex = 2
//                        }
//                        RadioButton {
//                            text: qsTr("WHILE")
//                            ButtonGroup.group: radioGroup
//                            onCheckedChanged: radioGroup.selectedIndex = 3
//                        }


//                    }
//                    Row{
//                        Layout.fillWidth: true
//                        RadioButton {
//                            text: qsTr("Interrupt")
//                            ButtonGroup.group: radioGroup
//                            onCheckedChanged: radioGroup.selectedIndex = 5
//                        }
//                        RadioButton {
//                            text: qsTr("Function")
//                            ButtonGroup.group: radioGroup
//                            onCheckedChanged: radioGroup.selectedIndex = 9
//                        }
//                    }
//                    Row{
//                        Layout.fillWidth: true
//                        Row{
//                            visible:  radioGroup.selectedIndex == 8
//                            Text {
//                                anchors.verticalCenter: parent.verticalCenter
//                                //                        width: 2
//                                text: qsTr("Theta:")
//                            }
//                            MTextField{
//                                id: myTheta
//                                _text:"0"
//                            }
//                        }
//                        Row{
//                            visible: (radioGroup.selectedIndex == 6 || radioGroup.selectedIndex == 7 || radioGroup.selectedIndex == 8)
//                            Text {
//                                anchors.verticalCenter: parent.verticalCenter
//                                //                        width: 2
//                                text: qsTr("F:")
//                            }
//                            MTextField{
//                                id: myFF
//                                _text:"10"
//                            }
//                            Text {
//                                anchors.verticalCenter: parent.verticalCenter
//                                //                        width: 2
//                                text: qsTr("CON:")
//                            }
//                            MTextField{
//                                id:myCON

//                                _text:"0"
//                            }
//                            Text {
//                                anchors.verticalCenter: parent.verticalCenter
//                                //                        width: 2
//                                text: qsTr("Approx:")
//                            }
//                            MTextField{
//                                id:myApprx

//                                _text:"0"
//                            }
//                        }
//                        Row{
//                            visible: !(radioGroup.selectedIndex == 6 || radioGroup.selectedIndex == 7 || radioGroup.selectedIndex == 8)
//                            Row{
//                                visible:  (radioGroup.selectedIndex == 2 || radioGroup.selectedIndex == 5 || radioGroup.selectedIndex==9)
//                                Text {
//                                    anchors.verticalCenter: parent.verticalCenter
//                                    //                        width: 2
//                                    text: (radioGroup.selectedIndex==9)?qsTr("name:"):qsTr("ID:")
//                                }
//                                MTextField{
//                                    id: myId
//                                    _text:"0"
//                                }
//                            }
//                            Row{
//                                visible:  (radioGroup.selectedIndex != 4 )
//                                Text {
//                                    anchors.verticalCenter: parent.verticalCenter
//                                    text: (radioGroup.selectedIndex==9)?qsTr("return:"):((radioGroup.selectedIndex==0 || radioGroup.selectedIndex==1 || radioGroup.selectedIndex==3 || radioGroup.selectedIndex==5)?qsTr("Condition:"):qsTr("Expression1:"))
//                                }
//                                MTextField{
//                                    id:myExp1
//                                    _text:"0"
//                                }
//                            }

//                            Row{
//                                visible:  radioGroup.selectedIndex == 2 || radioGroup.selectedIndex == 9
//                                Text {
//                                    anchors.verticalCenter: parent.verticalCenter
//                                    text: (radioGroup.selectedIndex==9)?qsTr("arguments:"):qsTr("Expression2:")
//                                }
//                                MTextField{
//                                    id:myExp2
//                                    _text:"0"
//                                }
//                            }
//                        }
////                        Row{
////                            visible: (radioGroup.selectedIndex == 5||radioGroup.selectedIndex == 9)
////                        }
//                    }
//                }
//            }
//        }

//    }
//    FileDialog {
//        id: fileDialogSave
//        selectExisting : false
//        property var cb
//        title: "Please choose a location to save"
//        nameFilters: [ "SixR files (*.six)", "All files (*)" ]
//        onAccepted: {
//            prjPath = fileDialogSave.fileUrl//+".six"
//            var ext = prjPath.split(".").pop()
//            if(ext!="six"){
//                prjPath+=".six"
//            }
//            newPrj()
//            if(cb != undefined) {
//                cb()
//                cb = null
//            }
//        }
//    }
//    FileDialog {
//        id: fileDialogLoad
//        selectExisting : true
//        //selectFolder: true
//        nameFilters: [ "SixR files (*.six)", "All files (*)" ]
//        property var cb
//        title: "Please choose project"

//        onAccepted: {
//            cb()
//            cb = undefined
//        }
//    }
//    MessageDialog {
//        id: messageDialog
//        property var cb
//        property int saveAndClose:-1
//        property int saveOnly:-1
//        title: "Save Changes"
//        text: "Do you want to save the changes you made to "
//        standardButtons: StandardButton.Save  | StandardButton.Discard | StandardButton.Cancel
//        onAccepted: {
//            currentEditor.save(function() {
//                if(saveOnly==1){
//                    currentEditor.changedSinceLastSave = false
//                    currentEditor.play()
//                    saveOnly=-1
//                }else{
//                    console.log("Save dialog callback and cancel: ", currentEditor.cancelCloseEditor)
//                    if(!currentEditor.cancelCloseEditor) {
//                        closeTab()
//                    }
//                    currentEditor.cancelCloseEditor = false
//                }
//            })
//        }

//        onDiscard: {
//            if(saveOnly==1){
//                currentEditor.play()
//                saveOnly=-1
//            }else{
//                currentEditor.changedSinceLastSave = false
//                closeTab()
//            }
//        }
//    }
//    Item {
//        id: shortcuts
//        Shortcut {
//            sequence: "Ctrl+1"
//            onActivated: {
//                if(editorCount >= 1) tabBar.setCurrentIndex(0)
//            }
//        }
//        Shortcut {
//            sequence: "Ctrl+2"
//            onActivated: {
//                if(editorCount >= 2) tabBar.setCurrentIndex(1)
//            }
//        }
//        Shortcut {
//            sequence: "Ctrl+3"
//            onActivated: {
//                if(editorCount >= 3) tabBar.setCurrentIndex(2)
//            }
//        }
//        Shortcut {
//            sequence: "Ctrl+4"
//            onActivated: {
//                if(editorCount >= 4) tabBar.setCurrentIndex(3)
//            }
//        }
//        Shortcut {
//            sequence: "Ctrl+5"
//            onActivated: {
//                if(editorCount >= 5) tabBar.setCurrentIndex(4)
//            }
//        }
//        Shortcut {
//            sequence: "Ctrl+6"
//            onActivated: {
//                if(editorCount >= 6) tabBar.setCurrentIndex(5)
//            }
//        }
//        Shortcut {
//            sequence: "Ctrl+7"
//            onActivated: {
//                if(editorCount >= 7) tabBar.setCurrentIndex(6)
//            }
//        }
//        Shortcut {
//            sequence: "Ctrl+8"
//            onActivated: {
//                if(editorCount >= 8) tabBar.setCurrentIndex(7)
//            }
//        }
//        Shortcut {
//            sequence: "Ctrl+9"
//            onActivated: {
//                if(editorCount >= 9) tabBar.setCurrentIndex(8)
//            }
//        }
//        Shortcut {
//            sequence: "Ctrl+0"
//            onActivated: {
//                if(editorCount >= 10) tabBar.setCurrentIndex(9)
//            }
//        }
//        Shortcut {
//            sequence: StandardKey.New
//            onActivated: {
//                newTab()
//            }
//        }
//        Shortcut {
//            sequence: StandardKey.AddTab
//            onActivated: {
//                newTab()
//            }
//        }
//        Shortcut {
//            sequence: StandardKey.Open
//            onActivated: {
//                openTab()
//            }
//        }

//        Shortcut {
//            sequence: StandardKey.Save
//            onActivated: {
//                currentEditor.save()
//            }
//        }

//        Shortcut {
//            sequence: StandardKey.Close
//            onActivated: {
//                closeTab()
//            }
//        }

//        Shortcut {
//            sequence: StandardKey.SaveAs
//            onActivated: {
//                currentEditor.saveAs()
//            }
//        }
//    }
//}
















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

    //**********************************
    // flags
    property bool _is_motion_selected: false
    property bool _is_program_flow_selected: false
    property bool _is_wait_selected: false
    property bool _is_ptp_selected: false
    property bool _is_lin_selected: false
    property bool _is_circ_selected: false
    property bool _is_reach_step4: false
    property bool _is_if_selected: false
    property bool _is_if_else_selected: false
    property bool _is_for_selected: false
    property bool _is_while_selected: false
    property bool _is_wait_for_selected: false
    property bool _is_wait_sec_selected: false
    property bool _is_interupt_selected: false
    property bool _is_subroutine_selected: false
    property bool _is_set_frame_selected: false
    property variant _frames_name: []
    //**********************************

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

    function getPointsList()
    {
        var points=[]
        for(var i=0;i<TeachPointModel.length;i++)
            points.push(TeachPointModel[i].name)
        return points
    }
    function getFrmaesList(type)
    {
        var frames=[]
        for(var i=0;i<SCoordinateModel.length;i++)
        {
            if(type==SCoordinateModel[i].type)
                frames.push(SCoordinateModel[i].name)
        }
        return frames
    }

    FileIO{
        id: fileio
    }


    Grid
    {
        anchors.fill: parent
        rows: 3

        //*********************************************************************
        //*********************************************************************
        // first Row
        Row
        {
            width: parent.width
            height: parent.height * 1/10
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

        //*********************************************************************
        //*********************************************************************
        // second Row

        Row
        {
            width: parent.width
            height: parent.height * 5/10
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
                width: parent.width * 9/10
                height: parent.height
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

        //*********************************************************************
        //*********************************************************************
        // Third Row

        Row
        {
            width: parent.width
            height: parent.height * 4/10


            Rectangle
            {
                width: parent.width * 1/10
                height: parent.height
                color: "transparent"
            }

            Column
            {
                width: parent.width
                height: parent.height


                // Main Combobox
                //***************************************************
                //***************************************************

                Row
                {
                    height: parent.height * 1/5
                    width: parent.width

                    ComboBox
                    {
                        id: cmb_main
                        height: parent.height
                        width: parent.width * 1/5
                        visible: true
                        model: ["Motion","program flow","wait","Interupt","Subroutine","Set Frame"]
                        displayText: cmb_main.currentText
                        delegate: ItemDelegate {
                            width: cmb_main.width
                            contentItem: Text {
                                text: modelData
                                color: "#21be2b"
                                font: cmb_main.font
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }
                            highlighted: cmb_main.highlightedIndex === index
                        }

                        indicator: Canvas {
                            id: cmb_main_canvas
                            x: cmb_main.width - width - cmb_main.rightPadding
                            y: cmb_main.topPadding + (cmb_main.availableHeight - height) / 2
                            width: 12
                            height: 8
                            contextType: "2d"

                            Connections {
                                target: cmb_main
                                onPressedChanged: cmb_main_canvas.requestPaint()
                            }

                            onPaint: {
                                context.reset();
                                context.moveTo(0, 0);
                                context.lineTo(width, 0);
                                context.lineTo(width / 2, height);
                                context.closePath();
                                context.fillStyle = cmb_main.pressed ? "#17a81a" : "#21be2b";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_main.indicator.width + cmb_main.spacing

                            text: cmb_main.displayText
                            font: cmb_main.font
                            color: cmb_main.pressed ? "#17a81a" : "#21be2b"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_main.pressed ? "#17a81a" : "#21be2b"
                            border.width: cmb_main.visualFocus ? 2 : 1
                            radius: 2
                        }

                        popup: Popup {
                            y: cmb_main.height - 1
                            width: cmb_main.width
                            implicitHeight: contentItem.implicitHeight
                            padding: 1

                            contentItem: ListView {
                                clip: true
                                implicitHeight: contentHeight
                                model: cmb_main.popup.visible ? cmb_main.delegateModel : null
                                currentIndex: cmb_main.highlightedIndex

                                ScrollIndicator.vertical: ScrollIndicator { }
                            }

                            background: Rectangle {
                                border.color: "#21be2b"
                                radius: 5
                            }
                        }
                        onActivated:{
                            //                        teachpointviewmodel.getSelectedCombo(_listIndex,cmb_main.currentText)

                            _is_ptp_selected=false
                            _is_lin_selected=false
                            _is_circ_selected=false
                            _is_if_selected=false
                            _is_if_else_selected=false
                            _is_for_selected=false
                            _is_while_selected=false
                            _is_wait_for_selected=false
                            _is_wait_sec_selected=false
                            _is_reach_step4=false
                            //motion
                            if(cmb_main.currentText==model[0])
                            {
                                _is_reach_step4=false
                                //****************************
                                _is_motion_selected=true
                                _is_program_flow_selected=false
                                _is_wait_selected=false
                                _is_interupt_selected=false
                                _is_subroutine_selected=false
                                _is_set_frame_selected=false
                            }
                            //program flow
                            else if(cmb_main.currentText==model[1])
                            {
                                _is_reach_step4=false
                                //****************************
                                _is_motion_selected=false
                                _is_program_flow_selected=true
                                _is_wait_selected=false
                                _is_interupt_selected=false
                                _is_subroutine_selected=false
                                _is_set_frame_selected=false
                            }
                            //wait
                            else if(cmb_main.currentText==model[2])
                            {
                                _is_reach_step4=false
                                //****************************
                                _is_motion_selected=false
                                _is_program_flow_selected=false
                                _is_wait_selected=true
                                _is_interupt_selected=false
                                _is_subroutine_selected=false
                                _is_set_frame_selected=false
                            }
                            //Interupt
                            else if(cmb_main.currentText==model[3])
                            {
                                _is_reach_step4=true
                                //****************************
                                _is_motion_selected=false
                                _is_program_flow_selected=false
                                _is_wait_selected=false
                                _is_interupt_selected=true
                                _is_subroutine_selected=false
                                _is_set_frame_selected=false
                            }
                            //Subroutine
                            else if(cmb_main.currentText==model[4])
                            {
                                _is_reach_step4=true
                                //****************************
                                _is_motion_selected=false
                                _is_program_flow_selected=false
                                _is_wait_selected=false
                                _is_interupt_selected=false
                                _is_subroutine_selected=true
                                _is_set_frame_selected=false
                            }
                            //Set Frame
                            else if(cmb_main.currentText==model[5])
                            {
                                _is_reach_step4=true
                                //****************************
                                _is_motion_selected=false
                                _is_program_flow_selected=false
                                _is_wait_selected=false
                                _is_interupt_selected=false
                                _is_subroutine_selected=false
                                _is_set_frame_selected=true
                            }

                        }
                    }


                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 2/5
                        color: "transparent"
                    }

                    MButton {
                        id: addButton
                        _height: parent.height
                        visible: _is_reach_step4
                        _text: "ADD"
                        onBtnClick: {
                            focusCurrentEditor()
//                            if(radioGroup.selectedIndex==9)
//                            {
//                                if(functionEditor==null)
//                                {
//                                    functionEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
//                                    functionTab = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
//                                    functionTab.codeEditor = functionEditor
//                                    functionEditor.title="function.mnr"
//                                    functionEditor.save()
//                                }
//                                //functionEditor.insertCMD(radioGroup.selectedIndex,myComboBoxTeachP1.currentText, myComboBoxTeachP2.currentText, myComboBoxTeachP3.currentText, myComboBoxSetFrT.currentText,myComboBoxSetFrP.currentText,"F "+myFF.textInput.text+" CON "+myCON.textInput.text+" Approx "+myApprx.textInput.text, "Theta "+myTheta.textInput.text, myExp1.textInput.text, myExp2.textInput.text, myId.textInput.text);
//                                currentEditor = functionEditor
//                                currentTabButton = functionTab
//                                currentEditor.textArea.focus = true
//                            }
//                            else if(radioGroup.selectedIndex==5)
//                            {
//                                if(interruptEditor==null)
//                                {
//                                    interruptEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
//                                    interruptTab = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
//                                    interruptTab.codeEditor = interruptEditor
//                                    interruptEditor.title="interrupt.mnr"
//                                    interruptEditor.save()
//                                }
//                                //interruptEditor.insertCMD(radioGroup.selectedIndex,myComboBoxTeachP1.currentText, myComboBoxTeachP2.currentText, myComboBoxTeachP3.currentText, myComboBoxSetFrT.currentText,myComboBoxSetFrP.currentText,"F "+myFF.textInput.text+" CON "+myCON.textInput.text+" Approx "+myApprx.textInput.text, "Theta "+myTheta.textInput.text, myExp1.textInput.text, myExp2.textInput.text, myId.textInput.text);
//                                currentEditor = interruptEditor
//                                currentTabButton = interruptTab
//                                currentEditor.textArea.focus = true
//                            }
//                            currentEditor.insertCMD(radioGroup.selectedIndex,myComboBoxTeachP1.currentText, myComboBoxTeachP2.currentText, myComboBoxTeachP3.currentText, myComboBoxSetFrT.currentText,myComboBoxSetFrP.currentText,"F "+myFF.textInput.text+" CON "+myCON.textInput.text+" Approx "+myApprx.textInput.text, "Theta "+myTheta.textInput.text, myExp1.textInput.text, myExp2.textInput.text, myId.textInput.text);
                            if(_is_ptp_selected || _is_lin_selected)
                            {
                                var _moveParam="F "+ptpLinFTextInput.text;
                                if(ptpLinTimechkbox.checked)
                                    _moveParam+=" TIME "+ptpLinTimeTextInput.text;
                                if(ptpLinConchkbox.checked)
                                    _moveParam+=" CON "+ptpLinConTextInput.text;
                                if(ptpLinApproxchkbox.checked)
                                    _moveParam+=" Approx "+ptpLinApproxTextInput.text;
                                if(_is_ptp_selected)
                                    currentEditor.insertCMD(6,cmb_point1.currentText, "", "", "","",_moveParam, "Theta "+"", "", "", "");
                                else if(_is_lin_selected)
                                    currentEditor.insertCMD(7,cmb_point1.currentText, "", "", "","",_moveParam, "Theta "+"", "", "", "");
                            }
                            else if(_is_circ_selected)
                            {
                                var _theta="";
                                _moveParam="F "+circFTextInput.text;
                                if(circTimechkbox.checked)
                                    _moveParam+=" TIME "+circTimeTextInput.text;
                                if(circConchkbox.checked)
                                    _moveParam+=" CON "+circConTextInput.text;
                                if(circApproxchkbox.checked)
                                    _moveParam+=" Approx "+circApproxTextInput.text;
                                if(circThetachkbox.checked)
                                    _theta+="Theta "+circThetaTextInput.text;
                                currentEditor.insertCMD(8,cmb_point1.currentText, cmb_point2.currentText, "", "","",_moveParam, _theta, "", "", "");
                            }
                            else if(_is_if_selected)
                            {
                                currentEditor.insertCMD(0,"", "", "", "","","", "", ifConditionTextInput.text, "", "");
                            }
                            else if(_is_if_else_selected)
                            {
                                currentEditor.insertCMD(1,"", "", "", "","","", "", ifConditionTextInput.text, "", "");
                            }
                            else if(_is_for_selected)
                            {
                                currentEditor.insertCMD(2,"", "", "", "","","", "", forExperission1TextInput.text, forExperission2TextInput.text, forIdTextInput.text);
                            }
                            else if(_is_while_selected)
                            {
                                currentEditor.insertCMD(3,"", "", "", "","","", "", ifConditionTextInput.text, "", "");
                            }
                            else if(_is_set_frame_selected)
                            {
                                currentEditor.insertCMD(4,"", "", "", cmb_frame_type.currentText,cmb_frame_name.currentText,"", "", "" , "", "");
                            }
                            else if(_is_wait_for_selected)
                            {
                                currentEditor.insertCMD(10,"", "", "", "","","", "", ifConditionTextInput.text, "", "");
                            }
                            else if(_is_wait_sec_selected)
                            {
                                currentEditor.insertCMD(11,"", "", "", "","","", "", ifConditionTextInput.text, "", "");
                            }

                            else if(_is_subroutine_selected)
                            {
                                if(functionEditor==null)
                                {
                                    functionEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
                                    functionTab = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
                                    functionTab.codeEditor = functionEditor
                                    functionEditor.title="subroutine_"+subroutineNameTextInput.text+".mnr"
                                    functionEditor.save("subroutine_"+subroutineNameTextInput.text+".mnr")
                                }
                                currentEditor = functionEditor
                                currentTabButton = functionTab
                                currentEditor.textArea.focus = true

                                currentEditor.insertCMD(9,"", "", "", "","","", "", "" , "" , subroutineNameTextInput.text);

                            }
                            else if(_is_interupt_selected)
                            {
                                if(interruptEditor==null)
                                {
                                    interruptEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
                                    interruptTab = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
                                    interruptTab.codeEditor = interruptEditor
                                    interruptEditor.title="interrupt_"+interuptNameTextInput.text+".mnr"
                                    interruptEditor.save()
                                }
                                currentEditor = interruptEditor
                                currentTabButton = interruptTab
                                currentEditor.textArea.focus = true

                                currentEditor.insertCMD(5,"", "", "", "","","", "", interuptPriorityTextInput.text , interuptConditionTextInput.text , interuptNameTextInput.text);
                            }
                        }
                    }

                }


                // Motion Combobox
                //***************************************************
                //***************************************************

                ComboBox
                {
                    id: cmb_motion
                    height: parent.height * 1/5
                    width: parent.width * 1/5
                    visible: _is_motion_selected
                    model: ["PTP","LIN","CIRC"]
                    displayText: cmb_motion.currentText
                    delegate: ItemDelegate {
                        width: cmb_motion.width
                        contentItem: Text {
                            text: modelData
                            color: "#21be2b"
                            font: cmb_motion.font
                            elide: Text.ElideRight
                            verticalAlignment: Text.AlignVCenter
                        }
                        highlighted: cmb_motion.highlightedIndex === index
                    }

                    indicator: Canvas {
                        id: cmb_motion_canvas
                        x: cmb_motion.width - width - cmb_motion.rightPadding
                        y: cmb_motion.topPadding + (cmb_motion.availableHeight - height) / 2
                        width: 12
                        height: 8
                        contextType: "2d"

                        Connections {
                            target: cmb_motion
                            onPressedChanged: cmb_motion_canvas.requestPaint()
                        }

                        onPaint: {
                            context.reset();
                            context.moveTo(0, 0);
                            context.lineTo(width, 0);
                            context.lineTo(width / 2, height);
                            context.closePath();
                            context.fillStyle = cmb_motion.pressed ? "#17a81a" : "#21be2b";
                            context.fill();
                        }
                    }

                    contentItem: Text {
                        leftPadding: 10
                        rightPadding: cmb_motion.indicator.width + cmb_motion.spacing

                        text: cmb_motion.displayText
                        font: cmb_motion.font
                        color: cmb_motion.pressed ? "#17a81a" : "#21be2b"
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 40
                        border.color: cmb_motion.pressed ? "#17a81a" : "#21be2b"
                        border.width: cmb_motion.visualFocus ? 2 : 1
                        radius: 2
                    }

                    popup: Popup {
                        y: cmb_motion.height - 1
                        width: cmb_motion.width
                        implicitHeight: contentItem.implicitHeight
                        padding: 1

                        contentItem: ListView {
                            clip: true
                            implicitHeight: contentHeight
                            model: cmb_motion.popup.visible ? cmb_motion.delegateModel : null
                            currentIndex: cmb_motion.highlightedIndex

                            ScrollIndicator.vertical: ScrollIndicator { }
                        }

                        background: Rectangle {
                            border.color: "#21be2b"
                            radius: 5
                        }
                    }
                    onActivated:{
                        //ptp
                        if(cmb_motion.currentText==model[0])
                        {
                            _is_ptp_selected=true
                            _is_lin_selected=false
                            _is_circ_selected=false
                        }
                        //lin
                        else if(cmb_motion.currentText==model[1])
                        {
                            _is_ptp_selected=false
                            _is_lin_selected=true
                            _is_circ_selected=false
                        }
                        //circ
                        else if(cmb_motion.currentText==model[2])
                        {
                            _is_ptp_selected=false
                            _is_lin_selected=false
                            _is_circ_selected=true
                        }
                    }
                }


                // Program_flow Combobox
                //***************************************************
                //***************************************************
                ComboBox {
                    id: cmb_program_flow
                    height: parent.height * 1/5
                    width: parent.width * 1/5
                    visible: _is_program_flow_selected
                    model: ["IF","IF/ELSE","FOR","WHILE"]
                    displayText: cmb_program_flow.currentText
                    delegate: ItemDelegate {
                        width: cmb_program_flow.width
                        contentItem: Text {
                            text: modelData
                            color: "#21be2b"
                            font: cmb_program_flow.font
                            elide: Text.ElideRight
                            verticalAlignment: Text.AlignVCenter
                        }
                        highlighted: cmb_program_flow.highlightedIndex === index
                    }

                    indicator: Canvas {
                        id: cmb_program_flow_canvas
                        x: cmb_program_flow.width - width - cmb_program_flow.rightPadding
                        y: cmb_program_flow.topPadding + (cmb_program_flow.availableHeight - height) / 2
                        width: 12
                        height: 8
                        contextType: "2d"

                        Connections {
                            target: cmb_program_flow
                            onPressedChanged: cmb_program_flow_canvas.requestPaint()
                        }

                        onPaint: {
                            context.reset();
                            context.moveTo(0, 0);
                            context.lineTo(width, 0);
                            context.lineTo(width / 2, height);
                            context.closePath();
                            context.fillStyle = cmb_program_flow.pressed ? "#17a81a" : "#21be2b";
                            context.fill();
                        }
                    }

                    contentItem: Text {
                        leftPadding: 10
                        rightPadding: cmb_program_flow.indicator.width + cmb_program_flow.spacing

                        text: cmb_program_flow.displayText
                        font: cmb_program_flow.font
                        color: cmb_program_flow.pressed ? "#17a81a" : "#21be2b"
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 40
                        border.color: cmb_program_flow.pressed ? "#17a81a" : "#21be2b"
                        border.width: cmb_program_flow.visualFocus ? 2 : 1
                        radius: 2
                    }

                    popup: Popup {
                        y: cmb_program_flow.height - 1
                        width: cmb_program_flow.width
                        implicitHeight: contentItem.implicitHeight
                        padding: 1

                        contentItem: ListView {
                            clip: true
                            implicitHeight: contentHeight
                            model: cmb_program_flow.popup.visible ? cmb_program_flow.delegateModel : null
                            currentIndex: cmb_program_flow.highlightedIndex

                            ScrollIndicator.vertical: ScrollIndicator { }
                        }

                        background: Rectangle {
                            border.color: "#21be2b"
                            radius: 5
                        }
                    }
                    onActivated:{
                        ifConditionTextInput.text="i==0"
                        ifConditionLabel.text="Condition:"
                        _is_reach_step4=true
                        //if
                        if(cmb_program_flow.currentText==model[0])
                        {
                            _is_if_selected=true
                            _is_if_else_selected=false
                            _is_for_selected=false
                            _is_while_selected=false
                        }
                        //if/else
                        else if(cmb_program_flow.currentText==model[1])
                        {
                            _is_if_selected=false
                            _is_if_else_selected=true
                            _is_for_selected=false
                            _is_while_selected=false
                        }
                        //for
                        else if(cmb_program_flow.currentText==model[2])
                        {
                           _is_if_selected=false
                           _is_if_else_selected=false
                           _is_for_selected=true
                            _is_while_selected=false
                        }
                        //while
                        else if(cmb_program_flow.currentText==model[3])
                        {
                           _is_if_selected=false
                           _is_if_else_selected=false
                           _is_for_selected=false
                           _is_while_selected=true
                        }
                    }
                }


                // wait ComboBox
                //***************************************************
                //***************************************************
                ComboBox {
                    id: cmb_wait
                    height: parent.height * 1/5
                    width: parent.width * 1/5
                    visible: _is_wait_selected
                    model: ["wait for","wait second"]
                    displayText: cmb_wait.currentText
                    delegate: ItemDelegate {
                        width: cmb_wait.width
                        contentItem: Text {
                            text: modelData
                            color: "#21be2b"
                            font: cmb_wait.font
                            elide: Text.ElideRight
                            verticalAlignment: Text.AlignVCenter
                        }
                        highlighted: cmb_wait.highlightedIndex === index
                    }

                    indicator: Canvas {
                        id: cmb_wait_canvas
                        x: cmb_wait.width - width - cmb_wait.rightPadding
                        y: cmb_wait.topPadding + (cmb_wait.availableHeight - height) / 2
                        width: 12
                        height: 8
                        contextType: "2d"

                        Connections {
                            target: cmb_wait
                            onPressedChanged: cmb_wait_canvas.requestPaint()
                        }

                        onPaint: {
                            context.reset();
                            context.moveTo(0, 0);
                            context.lineTo(width, 0);
                            context.lineTo(width / 2, height);
                            context.closePath();
                            context.fillStyle = cmb_wait.pressed ? "#17a81a" : "#21be2b";
                            context.fill();
                        }
                    }

                    contentItem: Text {
                        leftPadding: 10
                        rightPadding: cmb_wait.indicator.width + cmb_wait.spacing

                        text: cmb_wait.displayText
                        font: cmb_wait.font
                        color: cmb_wait.pressed ? "#17a81a" : "#21be2b"
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 40
                        border.color: cmb_wait.pressed ? "#17a81a" : "#21be2b"
                        border.width: cmb_wait.visualFocus ? 2 : 1
                        radius: 2
                    }

                    popup: Popup {
                        y: cmb_wait.height - 1
                        width: cmb_wait.width
                        implicitHeight: contentItem.implicitHeight
                        padding: 1

                        contentItem: ListView {
                            clip: true
                            implicitHeight: contentHeight
                            model: cmb_wait.popup.visible ? cmb_wait.delegateModel : null
                            currentIndex: cmb_wait.highlightedIndex

                            ScrollIndicator.vertical: ScrollIndicator { }
                        }

                        background: Rectangle {
                            border.color: "#21be2b"
                            radius: 5
                        }
                    }
                    onActivated:{
                        ifConditionTextInput.text="5"
                        ifConditionLabel.text="Parameter:"
                        _is_reach_step4=true
                        //wait for
                        if(cmb_wait.currentText==model[0])
                        {
                            _is_wait_for_selected=true
                            _is_wait_sec_selected=false
                        }
                        //wait sec
                        else if(cmb_wait.currentText==model[1])
                        {
                            _is_wait_for_selected=false
                            _is_wait_sec_selected=true
                        }
                    }
                }


                Row
                {
                    height: parent.height * 1/5
                    width: parent.width
                    spacing: 5

                    // point1 ComboBox
                    //***************************************************
                    //***************************************************
                    ComboBox {
                        id: cmb_point1
                        height: parent.height
                        width: parent.width * 1/5
                        visible: (_is_ptp_selected || _is_lin_selected || _is_circ_selected)&&_is_motion_selected
                        model: getPointsList()
                        displayText: cmb_point1.currentText
                        delegate: ItemDelegate {
                            width: cmb_point1.width
                            contentItem: Text {
                                text: modelData
                                color: "#21be2b"
                                font: cmb_point1.font
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }
                            highlighted: cmb_point1.highlightedIndex === index
                        }

                        indicator: Canvas {
                            id: cmb_point1_canvas
                            x: cmb_point1.width - width - cmb_point1.rightPadding
                            y: cmb_point1.topPadding + (cmb_point1.availableHeight - height) / 2
                            width: 12
                            height: 8
                            contextType: "2d"

                            Connections {
                                target: cmb_point1
                                onPressedChanged: cmb_point1_canvas.requestPaint()
                            }

                            onPaint: {
                                context.reset();
                                context.moveTo(0, 0);
                                context.lineTo(width, 0);
                                context.lineTo(width / 2, height);
                                context.closePath();
                                context.fillStyle = cmb_point1.pressed ? "#17a81a" : "#21be2b";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_point1.indicator.width + cmb_point1.spacing

                            text: cmb_point1.displayText
                            font: cmb_point1.font
                            color: cmb_point1.pressed ? "#17a81a" : "#21be2b"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_point1.pressed ? "#17a81a" : "#21be2b"
                            border.width: cmb_point1.visualFocus ? 2 : 1
                            radius: 2
                        }

                        popup: Popup {
                            y: cmb_point1.height - 1
                            width: cmb_point1.width
                            implicitHeight: contentItem.implicitHeight
                            padding: 1

                            contentItem: ListView {
                                clip: true
                                implicitHeight: contentHeight
                                model: cmb_point1.popup.visible ? cmb_point1.delegateModel : null
                                currentIndex: cmb_point1.highlightedIndex

                                ScrollIndicator.vertical: ScrollIndicator { }
                            }

                            background: Rectangle {
                                border.color: "#21be2b"
                                radius: 5
                            }
                        }
                        onActivated:{
                            _is_reach_step4=true
                        }
                    }



                    // point2 ComboBox
                    //***************************************************
                    //***************************************************
                    ComboBox {
                        id: cmb_point2
                        height: parent.height
                        width: parent.width * 1/5
                        visible: _is_circ_selected && _is_motion_selected
                        model: getPointsList()
                        displayText: cmb_point2.currentText
                        delegate: ItemDelegate {
                            width: cmb_point2.width
                            contentItem: Text {
                                text: modelData
                                color: "#21be2b"
                                font: cmb_point2.font
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }
                            highlighted: cmb_point2.highlightedIndex === index
                        }

                        indicator: Canvas {
                            id: cmb_point2_canvas
                            x: cmb_point2.width - width - cmb_point2.rightPadding
                            y: cmb_point2.topPadding + (cmb_point2.availableHeight - height) / 2
                            width: 12
                            height: 8
                            contextType: "2d"

                            Connections {
                                target: cmb_point2
                                onPressedChanged: cmb_point2_canvas.requestPaint()
                            }

                            onPaint: {
                                context.reset();
                                context.moveTo(0, 0);
                                context.lineTo(width, 0);
                                context.lineTo(width / 2, height);
                                context.closePath();
                                context.fillStyle = cmb_point2.pressed ? "#17a81a" : "#21be2b";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_point2.indicator.width + cmb_point2.spacing

                            text: cmb_point2.displayText
                            font: cmb_point2.font
                            color: cmb_point2.pressed ? "#17a81a" : "#21be2b"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_point2.pressed ? "#17a81a" : "#21be2b"
                            border.width: cmb_point2.visualFocus ? 2 : 1
                            radius: 2
                        }

                        popup: Popup {
                            y: cmb_point2.height - 1
                            width: cmb_point2.width
                            implicitHeight: contentItem.implicitHeight
                            padding: 1

                            contentItem: ListView {
                                clip: true
                                implicitHeight: contentHeight
                                model: cmb_point2.popup.visible ? cmb_point2.delegateModel : null
                                currentIndex: cmb_point2.highlightedIndex

                                ScrollIndicator.vertical: ScrollIndicator { }
                            }

                            background: Rectangle {
                                border.color: "#21be2b"
                                radius: 5
                            }
                        }
                        onActivated:{
                            teachpointviewmodel.getSelectedCombo(_listIndex,cmb_point2.currentText)
                        }
                    }
                }



                // ptp & lin Row
                //***************************************************
                //***************************************************
                Row
                {
                    id: ptp_lin_parameters_row
                    height: parent.height * 1/5
                    width: parent.width
                    visible: _is_reach_step4 && (_is_ptp_selected || _is_lin_selected )

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/15
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("F:")
                            color: "#21be2b"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/15
                        height: parent.height

                        TextInput {
                            id: ptpLinFTextInput
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "10"
                        }
                    }



//                    MCheckbox
//                    {
//                        _width : parent.width  * 1/15
//                        _height:  parent.height
//                        _text:""
//                    }

                    CheckBox
                    {
                        id: ptpLinTimechkbox
                        width: parent.width * 1/15
                        height: parent.height
                        text: ""
                    }

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/15
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("TIME:")
                            color: "#21be2b"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/15
                        height: parent.height

                        TextInput {
                            id: ptpLinTimeTextInput
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "0"
                        }
                    }



                    CheckBox
                    {
                        id: ptpLinConchkbox
                        width: parent.width * 1/15
                        height: parent.height
                        text: ""
                    }

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/15
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("CON:")
                            color: "#21be2b"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/15
                        height: parent.height

                        TextInput {
                            id: ptpLinConTextInput
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "0"
                        }
                    }

                    CheckBox
                    {
                        id: ptpLinApproxchkbox
                        width: parent.width * 1/15
                        height: parent.height
                        text: ""
                    }

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/15
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("Approx:")
                            color: "#21be2b"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/15
                        height: parent.height

                        TextInput {
                            id: ptpLinApproxTextInput
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "0"
                        }
                    }
                }


                // circ Row
                //***************************************************
                //***************************************************
                Row
                {
                    id: circ_parameters_row
                    height: parent.height * 1/5
                    width: parent.width
                    visible: _is_reach_step4 && _is_circ_selected

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/15
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("F:")
                            color: "#21be2b"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/18
                        height: parent.height

                        TextInput {
                            id: circFTextInput
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "10"
                        }
                    }

                    CheckBox
                    {
                        id: circTimechkbox
                        width: parent.width * 1/15
                        height: parent.height
                        text: ""
                    }

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/15
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("TIME:")
                            color: "#21be2b"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/18
                        height: parent.height

                        TextInput {
                            id: circTimeTextInput
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "0"
                        }
                    }



                    CheckBox
                    {
                        id: circThetachkbox
                        width: parent.width * 1/15
                        height: parent.height
                        text: ""
                    }

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/15
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("TETHA:")
                            color: "#21be2b"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/18
                        height: parent.height

                        TextInput {
                            id: circThetaTextInput
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "0"
                        }
                    }


                    CheckBox
                    {
                        id: circConchkbox
                        width: parent.width * 1/15
                        height: parent.height
                        text: ""
                    }

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/15
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("CON:")
                            color: "#21be2b"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/18
                        height: parent.height

                        TextInput {
                            id: circConTextInput
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "0"
                        }
                    }

                    CheckBox
                    {
                        id: circApproxchkbox
                        width: parent.width * 1/15
                        height: parent.height
                        text: ""
                    }

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/15
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("Approx:")
                            color: "#21be2b"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/18
                        height: parent.height

                        TextInput {
                            id: circApproxTextInput
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "0"
                        }
                    }
                }



                // IF & IF/ELSE & WHILE & Wait_For & WAit_Sec Row
                //***************************************************
                //***************************************************
                Row
                {
                    id: if_parameters_row
                    height: parent.height * 1/5
                    width: parent.width
                    visible: _is_reach_step4 && (_is_if_selected || _is_if_else_selected || _is_while_selected || _is_wait_for_selected || _is_wait_sec_selected)

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/7
                        color: "transparent"
                        Label
                        {
                            id: ifConditionLabel
                            anchors.centerIn: parent
                            text: qsTr("Condition:")
                            color: "#21be2b"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/11
                        height: parent.height

                        TextInput {
                            id: ifConditionTextInput
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "i==0"
                        }
                    }
                }


                // FOR Row
                //***************************************************
                //***************************************************
                Row
                {
                    id: for_parameters_row
                    height: parent.height * 1/5
                    width: parent.width
                    visible: _is_reach_step4 && _is_for_selected

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/11
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("ID:")
                            color: "#21be2b"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/11
                        height: parent.height

                        TextInput {
                            id: forIdTextInput
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "i"
                        }
                    }


                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/7
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("Expression1:")
                            color: "#21be2b"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/11
                        height: parent.height

                        TextInput {
                            id: forExperission1TextInput
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "0"
                        }
                    }

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/7
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("Expression2:")
                            color: "#21be2b"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/11
                        height: parent.height

                        TextInput {
                            id: forExperission2TextInput
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "10"
                        }
                    }
                }



                // Interupt Row
                //***************************************************
                //***************************************************
                Row
                {
                    id: interupt_parameters_row
                    height: parent.height * 1/5
                    width: parent.width
                    visible: _is_reach_step4 && _is_interupt_selected

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/11
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("Name:")
                            color: "#21be2b"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/7
                        height: parent.height

                        TextInput {
                            id: interuptNameTextInput
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "sample"
                        }
                    }


                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/7
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("Priority:")
                            color: "#21be2b"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/11
                        height: parent.height

                        TextInput {
                            id: interuptPriorityTextInput
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "1"
                        }
                    }

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/7
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("Condition:")
                            color: "#21be2b"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/11
                        height: parent.height

                        TextInput {
                            id: interuptConditionTextInput
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "10"
                        }
                    }

                }




                // subroutine Row
                //***************************************************
                //***************************************************
                Row
                {
                    id: subroutine_parameters_row
                    height: parent.height * 1/5
                    width: parent.width
                    visible: _is_reach_step4 && _is_subroutine_selected

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/11
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("Name:")
                            color: "#21be2b"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/7
                        height: parent.height

                        TextInput {
                            id: subroutineNameTextInput
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "sample"
                        }
                    }
                }



                // set frame Row
                //***************************************************
                //***************************************************
                Row
                {
                    height: parent.height * 1/5
                    width: parent.width
                    spacing: 5
                    visible: _is_set_frame_selected

                    // frame type ComboBox
                    //***************************************************
                    //***************************************************
                    ComboBox {
                        id: cmb_frame_type
                        height: parent.height
                        width: parent.width * 1/5
                        model: ["object","task","tool","world","base"]
                        displayText: cmb_frame_type.currentText
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
                            id: cmb_frame_type_canvas
                            x: cmb_frame_type.width - width - cmb_frame_type.rightPadding
                            y: cmb_frame_type.topPadding + (cmb_frame_type.availableHeight - height) / 2
                            width: 12
                            height: 8
                            contextType: "2d"

                            Connections {
                                target: cmb_frame_type
                                onPressedChanged: cmb_frame_type_canvas.requestPaint()
                            }

                            onPaint: {
                                context.reset();
                                context.moveTo(0, 0);
                                context.lineTo(width, 0);
                                context.lineTo(width / 2, height);
                                context.closePath();
                                context.fillStyle = cmb_frame_type.pressed ? "#17a81a" : "#21be2b";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_frame_type.indicator.width + cmb_frame_type.spacing

                            text: cmb_frame_type.displayText
                            font: cmb_frame_type.font
                            color: cmb_frame_type.pressed ? "#17a81a" : "#21be2b"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_frame_type.pressed ? "#17a81a" : "#21be2b"
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
                        onActivated:{
                            _frames_name=getFrmaesList(cmb_frame_type.currentText)
                        }
                    }



                    // frame name ComboBox
                    //***************************************************
                    //***************************************************
                    ComboBox {
                        id: cmb_frame_name
                        height: parent.height
                        width: parent.width * 1/5
                        model: _frames_name
                        displayText: cmb_frame_name.currentText
                        delegate: ItemDelegate {
                            width: cmb_frame_name.width
                            contentItem: Text {
                                text: modelData
                                color: "#21be2b"
                                font: cmb_frame_name.font
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }
                            highlighted: cmb_frame_name.highlightedIndex === index
                        }

                        indicator: Canvas {
                            id: cmb_frame_name_canvas
                            x: cmb_frame_name.width - width - cmb_frame_name.rightPadding
                            y: cmb_frame_name.topPadding + (cmb_frame_name.availableHeight - height) / 2
                            width: 12
                            height: 8
                            contextType: "2d"

                            Connections {
                                target: cmb_frame_name
                                onPressedChanged: cmb_frame_name_canvas.requestPaint()
                            }

                            onPaint: {
                                context.reset();
                                context.moveTo(0, 0);
                                context.lineTo(width, 0);
                                context.lineTo(width / 2, height);
                                context.closePath();
                                context.fillStyle = cmb_frame_name.pressed ? "#17a81a" : "#21be2b";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_frame_name.indicator.width + cmb_frame_name.spacing

                            text: cmb_frame_name.displayText
                            font: cmb_frame_name.font
                            color: cmb_frame_name.pressed ? "#17a81a" : "#21be2b"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_frame_name.pressed ? "#17a81a" : "#21be2b"
                            border.width: cmb_frame_name.visualFocus ? 2 : 1
                            radius: 2
                        }

                        popup: Popup {
                            y: cmb_frame_name.height - 1
                            width: cmb_frame_name.width
                            implicitHeight: contentItem.implicitHeight
                            padding: 1

                            contentItem: ListView {
                                clip: true
                                implicitHeight: contentHeight
                                model: cmb_frame_name.popup.visible ? cmb_frame_name.delegateModel : null
                                currentIndex: cmb_frame_name.highlightedIndex

                                ScrollIndicator.vertical: ScrollIndicator { }
                            }

                            background: Rectangle {
                                border.color: "#21be2b"
                                radius: 5
                            }
                        }
                        onActivated:{
                        }
                    }
                }
            }

        }

    }

//    ColumnLayout {
//        anchors.fill: parent
//        spacing: 0
//        Row {
//            Layout.fillWidth: true
//            spacing: 1
//            MButton {
//                _width: 30
//                _height: 35
//                id: closeTabButton
//                _text: "x"
//                onBtnClick: {
//                    closeTab()
//                }
//            }
//            TabBar {
//                id: tabBar
//                width: parent.width-closeTabButton.width - newTabButton.width - openTabButton.width
//                CodeEditorTabButton {
//                    text: codeEditor_1.title
//                    codeEditor: codeEditor_1
//                }
//            }

//            MButton {
//                _width: 100
//                _height: 35
//                id: newTabButton
//                _text: "New File"
//                onBtnClick: {
//                    newTab()
//                }
//            }
//            MButton {
//                _width: 100
//                _height: 35
//                id: openTabButton
//                _text: "Open File"
//                onBtnClick: {
//                    openTab()
//                }
//            }
//        }
//        RowLayout {
//            Layout.fillWidth: true
//            spacing: 0
//            StackLayout {
//                id:stackLayout2
//                visible: false
//                CodeEditor {
//                    id: projectEditor
//                    Component.onCompleted: {
//                        changedSinceLastSave = false
//                    }
//                }
//            }
//            StackLayout {
//                id: stackLayout
//                Layout.fillWidth: true
//                Layout.fillHeight: true
//                currentIndex: tabBar.currentIndex

//                CodeEditor {
//                    id: codeEditor_1
//                    Component.onCompleted: {
//                        changedSinceLastSave = false
//                    }
//                }
//            }
//            Column{
//                MLabel{
//                    _text:"Project"
//                }
//                MButton {
//                    _width: 60
//                    _height: 35
//                    id: newPrjButton
//                    _text: "New"
//                    onBtnClick: {//initialize
//                        fileDialogSave.visible=true
//                        //                        newPrj()
//                    }
//                }
//                MButton {
//                    _width: 60
//                    _height: 35
//                    id: openPrjButton
//                    _text: "Open"
//                    onBtnClick: {
//                        openPrj()
//                    }
//                }
//                MButton {
//                    _width: 60
//                    _height: 35
//                    id: savePrjButton
//                    _text: "Save"
//                    onBtnClick: {
//                        refreshProjectFiles()
//                    }
//                }
//                MButton {
//                    _width: 60
//                    _height: 35
//                    id: playCurrentTabButton
//                    _text: "Play"
//                    onBtnClick: {
//                        //if(text: "Play")
//                        if(pauseCurrentTabButton._text == "Run"){
//                            stopCurrentTab()
//                            var times = new Date().getTime()
//                            while(new Date().getTime() - times<500);
//                            pauseCurrentTabButton._text="Pause"
//                            pauseCurrentTabButton._background.color = "white"
//                        }
//                        playProject()
//                    }
//                }
//                MTextField{
//                    visible: false
//                    _width:60
//                    id: runFromLine
//                    _text:"-1"
//                }
//                MButton {
//                    _width: 60
//                    _height: 35
//                    id: pauseCurrentTabButton
//                    _text: "Pause"
//                    onBtnClick: {
//                        if(_text== "Pause"){
//                            _background.color = "red"
//                            _text="Run"
//                        }
//                        else{
//                            _background.color = "white"
//                            _text = "Pause"
//                        }
//                        puaseCurrentTab()
//                    }
//                }
//                MButton {
//                    _width: 60
//                    _height: 35
//                    id: stopCurrentTabButton
//                    _text: "Stop"
//                    onBtnClick: {
//                        pauseCurrentTabButton._text="Pause"
//                        pauseCurrentTabButton._background.color = "white"
//                        //if(text: "Play")
//                        stopCurrentTab()
//                    }
//                }
//            }
//        }
//        Row {
//            Layout.fillWidth: true
//            Row{
//                MButton {
//                    property string frameType: "TOOL"
//                    property string targetPoint: ""
//                    _width : 60
//                    _height :40
//                    id: btnMovement
//                    _text: "Add"
//                    height: parent.height
//                    onBtnClick:{
//                        focusCurrentEditor()
//                        if(radioGroup.selectedIndex==9){
//                            if(functionEditor==null){
//                                functionEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
//                                functionTab = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
//                                functionTab.codeEditor = functionEditor
//                                functionEditor.title="function.mnr"
//                                functionEditor.save()
//                            }
//                            //functionEditor.insertCMD(radioGroup.selectedIndex,myComboBoxTeachP1.currentText, myComboBoxTeachP2.currentText, myComboBoxTeachP3.currentText, myComboBoxSetFrT.currentText,myComboBoxSetFrP.currentText,"F "+myFF.textInput.text+" CON "+myCON.textInput.text+" Approx "+myApprx.textInput.text, "Theta "+myTheta.textInput.text, myExp1.textInput.text, myExp2.textInput.text, myId.textInput.text);
//                            currentEditor = functionEditor
//                            currentTabButton = functionTab
//                            currentEditor.textArea.focus = true
//                        }else if(radioGroup.selectedIndex==5){
//                            if(interruptEditor==null){
//                                interruptEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
//                                interruptTab = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
//                                interruptTab.codeEditor = interruptEditor
//                                interruptEditor.title="interrupt.mnr"
//                                interruptEditor.save()
//                            }
//                            //interruptEditor.insertCMD(radioGroup.selectedIndex,myComboBoxTeachP1.currentText, myComboBoxTeachP2.currentText, myComboBoxTeachP3.currentText, myComboBoxSetFrT.currentText,myComboBoxSetFrP.currentText,"F "+myFF.textInput.text+" CON "+myCON.textInput.text+" Approx "+myApprx.textInput.text, "Theta "+myTheta.textInput.text, myExp1.textInput.text, myExp2.textInput.text, myId.textInput.text);
//                            currentEditor = interruptEditor
//                            currentTabButton = interruptTab
//                            currentEditor.textArea.focus = true
//                        }
//                        currentEditor.insertCMD(radioGroup.selectedIndex,myComboBoxTeachP1.currentText, myComboBoxTeachP2.currentText, myComboBoxTeachP3.currentText, myComboBoxSetFrT.currentText,myComboBoxSetFrP.currentText,"F "+myFF.textInput.text+" CON "+myCON.textInput.text+" Approx "+myApprx.textInput.text, "Theta "+myTheta.textInput.text, myExp1.textInput.text, myExp2.textInput.text, myId.textInput.text);
//                    }
//                }

//                ButtonGroup {
//                    id: radioGroup
//                    property int selectedIndex : 6
//                    //                onCheckedButtonChanged:
//                    //                    console.log("clicked:", selectedIndex)
//                }
//                Column{
//                    Row {
//                        Layout.fillWidth: true
//                        RadioButton {
//                            checked: true
//                            text: qsTr("PTP")
//                            ButtonGroup.group: radioGroup
//                            onCheckedChanged: radioGroup.selectedIndex = 6
//                        }
//                        RadioButton {
//                            text: qsTr("LIN")
//                            ButtonGroup.group: radioGroup
//                            onCheckedChanged: radioGroup.selectedIndex = 7
//                        }
//                        RadioButton {
//                            text: qsTr("CIRC")
//                            ButtonGroup.group: radioGroup
//                            onCheckedChanged: radioGroup.selectedIndex = 8
//                        }
//                        RadioButton {
//                            text: qsTr("SET Frame")
//                            ButtonGroup.group: radioGroup
//                            onCheckedChanged: radioGroup.selectedIndex = 4
//                        }
//                        ComboBox {
//                            visible: (radioGroup.selectedIndex == 6 || radioGroup.selectedIndex == 7 || radioGroup.selectedIndex == 8)
//                            //width: 200
//                            id: myComboBoxTeachP1
//                            model: myTeachPointModel
//                            //                        onCurrentTextChanged: {
//                            //                            console.log(myComboBoxTeachP1.currentText)
//                            //                        }
//                        }
//                        ComboBox {
//                            visible: radioGroup.selectedIndex == 8
//                            //width: 200
//                            id: myComboBoxTeachP2
//                            model: myTeachPointModel
//                            //                        onCurrentTextChanged: {
//                            //                            console.log(myComboBoxTeachP2.currentText)
//                            //                        }
//                        }
//                        ComboBox {
//                            visible: false//radioGroup.selectedIndex == 8
//                            //width: 200
//                            id: myComboBoxTeachP3
//                            model: myTeachPointModel
//                            //                        onCurrentTextChanged: {
//                            //                            console.log(myComboBoxTeachP3.currentText)
//                            //                        }
//                        }
//                        ComboBox {
//                            visible: radioGroup.selectedIndex == 4
//                            //width: 200
//                            id: myComboBoxSetFrT
//                            model: ["TOOL", "BASE", "OBJECT", "TSAK"]
//                            //                        onCurrentTextChanged: {
//                            //                            console.log(myComboBoxSetFrT.currentText)
//                            //                        }
//                        }
//                        ComboBox {
//                            visible: radioGroup.selectedIndex == 4
//                            //width: 200
//                            id: myComboBoxSetFrP
//                            model: myTeachFrameModel
//                            //                        onCurrentTextChanged: {
//                            //                            console.log(myComboBoxSetFrP.currentText)
//                            //                        }
//                        }

//                    }
//                    Row {
//                        Layout.fillWidth: true
//                        RadioButton {
//                            text: qsTr("IF")
//                            ButtonGroup.group: radioGroup
//                            onCheckedChanged: radioGroup.selectedIndex = 0
//                        }
//                        RadioButton {
//                            text: qsTr("IF ELESE")
//                            ButtonGroup.group: radioGroup
//                            onCheckedChanged: radioGroup.selectedIndex = 1
//                        }
//                        RadioButton {
//                            text: qsTr("FOR")
//                            ButtonGroup.group: radioGroup
//                            onCheckedChanged: radioGroup.selectedIndex = 2
//                        }
//                        RadioButton {
//                            text: qsTr("WHILE")
//                            ButtonGroup.group: radioGroup
//                            onCheckedChanged: radioGroup.selectedIndex = 3
//                        }


//                    }
//                    Row{
//                        Layout.fillWidth: true
//                        RadioButton {
//                            text: qsTr("Interrupt")
//                            ButtonGroup.group: radioGroup
//                            onCheckedChanged: radioGroup.selectedIndex = 5
//                        }
//                        RadioButton {
//                            text: qsTr("Function")
//                            ButtonGroup.group: radioGroup
//                            onCheckedChanged: radioGroup.selectedIndex = 9
//                        }
//                    }
//                    Row{
//                        Layout.fillWidth: true
//                        Row{
//                            visible:  radioGroup.selectedIndex == 8
//                            Text {
//                                anchors.verticalCenter: parent.verticalCenter
//                                //                        width: 2
//                                text: qsTr("Theta:")
//                            }
//                            MTextField{
//                                id: myTheta
//                                _text:"0"
//                            }
//                        }
//                        Row{
//                            visible: (radioGroup.selectedIndex == 6 || radioGroup.selectedIndex == 7 || radioGroup.selectedIndex == 8)
//                            Text {
//                                anchors.verticalCenter: parent.verticalCenter
//                                //                        width: 2
//                                text: qsTr("F:")
//                            }
//                            MTextField{
//                                id: myFF
//                                _text:"10"
//                            }
//                            Text {
//                                anchors.verticalCenter: parent.verticalCenter
//                                //                        width: 2
//                                text: qsTr("CON:")
//                            }
//                            MTextField{
//                                id:myCON

//                                _text:"0"
//                            }
//                            Text {
//                                anchors.verticalCenter: parent.verticalCenter
//                                //                        width: 2
//                                text: qsTr("Approx:")
//                            }
//                            MTextField{
//                                id:myApprx

//                                _text:"0"
//                            }
//                        }
//                        Row{
//                            visible: !(radioGroup.selectedIndex == 6 || radioGroup.selectedIndex == 7 || radioGroup.selectedIndex == 8)
//                            Row{
//                                visible:  (radioGroup.selectedIndex == 2 || radioGroup.selectedIndex == 5 || radioGroup.selectedIndex==9)
//                                Text {
//                                    anchors.verticalCenter: parent.verticalCenter
//                                    //                        width: 2
//                                    text: (radioGroup.selectedIndex==9)?qsTr("name:"):qsTr("ID:")
//                                }
//                                MTextField{
//                                    id: myId
//                                    _text:"0"
//                                }
//                            }
//                            Row{
//                                visible:  (radioGroup.selectedIndex != 4 )
//                                Text {
//                                    anchors.verticalCenter: parent.verticalCenter
//                                    text: (radioGroup.selectedIndex==9)?qsTr("return:"):((radioGroup.selectedIndex==0 || radioGroup.selectedIndex==1 || radioGroup.selectedIndex==3 || radioGroup.selectedIndex==5)?qsTr("Condition:"):qsTr("Expression1:"))
//                                }
//                                MTextField{
//                                    id:myExp1
//                                    _text:"0"
//                                }
//                            }

//                            Row{
//                                visible:  radioGroup.selectedIndex == 2 || radioGroup.selectedIndex == 9
//                                Text {
//                                    anchors.verticalCenter: parent.verticalCenter
//                                    text: (radioGroup.selectedIndex==9)?qsTr("arguments:"):qsTr("Expression2:")
//                                }
//                                MTextField{
//                                    id:myExp2
//                                    _text:"0"
//                                }
//                            }
//                        }
////                        Row{
////                            visible: (radioGroup.selectedIndex == 5||radioGroup.selectedIndex == 9)
////                        }
//                    }
//                }
//            }
//        }

//    }
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
