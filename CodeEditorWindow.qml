import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Controls.Material 2.0
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

    property variant _frames_name: []
    property variant _exist_projects_name: []
    property variant _exist_files_name: []
    property string _defaultPrjPath: "SixR_Projects"
    property string _mainPrjCodePath: ""
    property string _current_prj_name: ""

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


    property bool _have_active_prj: false
    property bool _is_started_prj: false
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
//        openPrjFromPath()
//        saveFile(prjPath, "")
        initTabs()
    }

    function openPrj(){
        prjPath ="file://"+getHomeAddress()+"/"+_defaultPrjPath+"/"+cmb_openExistProjectPopUp.currentText+"/"+cmb_openExistProjectPopUp.currentText+".six"
        _mainPrjCodePath=_defaultPrjPath+"/"+cmb_openExistProjectPopUp.currentText+"/main.sbr"
        _current_prj_name=cmb_openExistProjectPopUp.currentText
        fileio.currentProject=_mainPrjCodePath.replace('main.sbr','final.code')
        openPrjFromPath()
    }
    function openPrjFromPath(){
        var response = openFile(prjPath)
        if(response=="Error")
        {
            errorPopupText.text="The '"+_current_prj_name+".six' File Does Not Find."
            error_popup.open()
        }
        else
        {
            closeAllTab();
            var files = response.split(("\n"))
            for(var i in files){
                if(files[i]){
                    var newCodeEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
                    var newTabButton = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
                    newTabButton.codeEditor = newCodeEditor
                    newCodeEditor.open(files[i].replace('qrc:/View/',''))//path+files[i])
                    newCodeEditor.changedSinceLastSave = false
                    tabBar.setCurrentIndex(tabBar.count-1)
                    if(i==0)
                        newCodeEditor.isReadOnly=true
//                    newTabButton.color = "#fff" // Hack since focus isn't set correctly when it's the first tab?
                }
            }
            _have_active_prj=true
        }
//        focusCurrentEditor()
//        if(urlExists(prjPath+".mnr")){
//            projectEditor.open(prjPath+".mnr")
//        }
    }

    function newMainTab(){
        var newCodeEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
        var newTabButton = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
        newTabButton.codeEditor = newCodeEditor
        newCodeEditor.setFileUrl(_mainPrjCodePath)
        newCodeEditor.changedSinceLastSave = false
        newCodeEditor.title="main.sbr"
        newCodeEditor.text="main()\r\nend"
        tabBar.setCurrentIndex(tabBar.count-1) // select it
        focusCurrentEditor()
        newCodeEditor.save()
    }

    function newFinalTab(){
        var newCodeEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
        var newTabButton = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
        newTabButton.codeEditor = newCodeEditor
         var _prj_final_code_path=_mainPrjCodePath.replace('main.sbr','final.code')
        newCodeEditor.setFileUrl(_prj_final_code_path)
        newCodeEditor.changedSinceLastSave = false
        newCodeEditor.title="final.code"
        newCodeEditor.text="main()\r\nend"
        tabBar.setCurrentIndex(tabBar.count-1) // select it
        focusCurrentEditor()
        newCodeEditor.save()
        newCodeEditor.isReadOnly=true
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
        newFinalTab()
        newMainTab()
        //newFunctionTab()
    }
    function newTab() {
        var newCodeEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
        var newTabButton = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
        newTabButton.codeEditor = newCodeEditor
        newCodeEditor.title=""
        newCodeEditor.text=""
        newCodeEditor.changedSinceLastSave = false
        tabBar.setCurrentIndex(tabBar.count-1) // select it
        newTabButton.color = "#fff" // Hack since focus isn't set correctly when it's the first tab?
        focusCurrentEditor()
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
            _current_prj_name=""
            newTab()
            _have_active_prj=false
        }
    }
    function refreshProjectFiles(){
        if(prjPath=="")
            return
        var indexOfCurrentTab = editorCount
        var fileNames=[]
        var fileUrls = ""
        var projectContain=""
        while(indexOfCurrentTab>0){
            currentEditor = stackLayout.itemAt(indexOfCurrentTab-1)
            if(currentEditor.changedSinceLastSave){
                currentEditor.save()
            }
            fileNames.push(currentEditor.fileName)
            if(indexOfCurrentTab==1)
            {
                fileUrls = currentEditor.fileUrl+"\n" + fileUrls;
            }
            else if(indexOfCurrentTab==2)
            {
                fileUrls = currentEditor.fileUrl+"\n" + fileUrls;
                projectContain += currentEditor.text+"\n"
            }
            else
            {
                fileUrls += currentEditor.fileUrl+"\n"
                projectContain += currentEditor.text+"\n"
            }
            indexOfCurrentTab--
            currentEditor = stackLayout.itemAt(0)
            currentEditor.text=projectContain
        }
        if(projectContain!=projectEditor.text){
            var _final_code_path=_mainPrjCodePath.replace('main.sbr','final.code')
            var _prj_urls_path=_mainPrjCodePath.replace('main.sbr',_current_prj_name+'.six')
            var _prj_final_code_path=_mainPrjCodePath.replace('main.sbr','final.code')
            saveFile(_final_code_path, projectContain)
            saveFile(_prj_urls_path, fileUrls)
            projectEditor.open(_prj_final_code_path)
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

        var filePath =_defaultPrjPath+"/"+_current_prj_name+"/"+cmb_openExistFilePopUp.currentText
        var newCodeEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
        var newTabButton = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
        newTabButton.codeEditor = newCodeEditor
        newCodeEditor.open(filePath)
        newCodeEditor.changedSinceLastSave = false
        tabBar.setCurrentIndex(tabBar.count-1)
        newTabButton.color = "#fff" // Hack since focus isn't set correctly when it's the first tab?
        focusCurrentEditor()

    }
    function urlExists(testUrl) {
        var request = new XMLHttpRequest();
        request.open("GET", testUrl, false);
        request.send(null);
        return request.status==200;
    }
    function openFile(fileUrl){
        fileio.setSource(fileUrl)
        if(fileio.read())
            return fileio.text
        else
            return "Error"
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
    function getExistProjectsName()
    {
        return fileio.getExistProjectList(_defaultPrjPath)
    }

    function getExistFilesName()
    {
        return fileio.getExistFileList(_defaultPrjPath+"/"+_current_prj_name)
    }

    function getHomeAddress()
    {
        return fileio.homeAddress
    }

    function setCurrentProjectName(value)
    {
        fileio.currentProject=value;
    }

    FileIO{
        id: fileio
    }


    Popup {
        id:popuperrors

        implicitHeight: contentItem.implicitHeight
        anchors.centerIn: parent
        width: 500
        height: 500
        modal: true
        focus: true
        closePolicy: Popup.CloseOnEscape
        padding: 1
        Frame{
            width: parent.width
            height: parent.height
            background: Rectangle {
                color: "transparent"
                border.color: "#F32013"
                radius: 2
            }
            Grid{
                id:mainpopupgrid
                width: parent.width
                height: parent.height
                columns: 1
                Flickable
                    {
                        width: mainpopupgrid.width
                        height: mainpopupgrid.height * 0.8
                        flickableDirection: Flickable.VerticalFlick

                        TextArea.flickable: TextArea
                        {
                            //font.pixelSize: 225
                            text:projectEditor.errors
                            readOnly: true
                            background: null
                            color: "#F32013"
                            MouseArea
                            {
                                anchors.fill: parent
                                enabled: false
                            }
                        }
                    }


                MButton{
                    id:cancelbtn
                    _width: parent.width
                    _height: 48
                    _text:"close"
                    onBtnClick: {
                        popuperrors.close()
                    }
                }

            }
        }

        background: Rectangle {
            border.color: "#F32013"
            radius: 5
        }
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
                width: parent.width-closeTabButton.width
                Material.accent: Material.Dark
                CodeEditorTabButton {
                    text: codeEditor_1.title
                    codeEditor: codeEditor_1
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
            spacing: 5
            StackLayout {
                id:stackLayout2
                visible: false
                enabled: _have_active_prj
                CodeEditor {
                    id: projectEditor
                    Component.onCompleted: {
                        changedSinceLastSave = false
                    }
                }
            }
            StackLayout {
                id: stackLayout
                width: parent.width * 8/10
                height: parent.height
                enabled: _have_active_prj
                currentIndex: tabBar.currentIndex

                CodeEditor {
                    id: codeEditor_1
                    Component.onCompleted: {
                        changedSinceLastSave = false
                    }
                }
            }
            Column{
                spacing: 5
                Rectangle
                {
                    width: 125
                    height: 20
                    color: "transparent"
                    Label
                    {
                        anchors.centerIn: parent
                        text: _current_prj_name
                        color: "#EFECCA"
                    }
                }
                MButton {
                    _width: 125
                    _height: 35
                    enabled: true
                    id: newPrjButton
                    _text: "New"
                    onBtnClick: {//initialize
                        getProjectNamePopUp.open()
                    }
                }
                Row
                {
                    spacing: 5
                    MButton {
                        _width: 60
                        _height: 35
                        enabled:true
                        id: openPrjButton
                        _text: "Open"
                        onBtnClick: {
                            var res=getExistProjectsName()
                            _exist_projects_name=res.split('#')
                            openExistProjectPopUp.open()
                            focusCurrentEditor()
                        }
                    }
                    MButton {
                        _width: 60
                        _height: 35
                        enabled:_have_active_prj
                        id: savePrjButton
                        _text: "Save"
                        onBtnClick: {
                            refreshProjectFiles()
                        }
                    }
                }

                MButton {
                    _width: 125
                    _height: 35
                    enabled:_have_active_prj
                    id: openTabButton
                    _text: "Open Exist File"
                    onBtnClick: {
                        var res=getExistFilesName()
                        _exist_files_name=res.split('#')
                        openExistFilePopUp.open()
//                        openTab()
                    }
                }

                MButton {
                    _width: 125
                    _height: 35
                    enabled:_have_active_prj
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
                        tabBar.currentIndex=0
                        playProject()
                        if(!(projectEditor.errors == ""))
                        {
                            popuperrors.open()
                        }
                    }
                }
                MTextField{
                    visible: false
                    _width:60
                    id: runFromLine
                    _text:"-1"
                }
                Row
                {
                    spacing: 5
                    MButton {
                        _width: 60
                        _height: 35
                        enabled:_is_started_prj
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
                        enabled:_is_started_prj
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
                        visible: _have_active_prj
                        model: ["Motion","program flow","wait","Interupt","Subroutine","Set Frame"]
                        displayText: cmb_main.currentText
                        delegate: ItemDelegate {
                            width: cmb_main.width
                            contentItem: Text {
                                text: modelData
                                color: "#EFECCA"
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
                                context.fillStyle = cmb_main.pressed ? "#046380" : "#EFECCA";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_main.indicator.width + cmb_main.spacing

                            text: cmb_main.displayText
                            font: cmb_main.font
                            color: cmb_main.pressed ? "#046380" : "#EFECCA"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_main.pressed ? "#046380" : "#EFECCA"
                            border.width: cmb_main.visualFocus ? 2 : 1
                            color: "#046380"
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
                                border.color: "#EFECCA"
                                color: "#046380"
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
                        visible: _is_reach_step4 && _have_active_prj
                        _text: "ADD"
                        onBtnClick: {
                            focusCurrentEditor()

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
                                //****************************************************
                                // add subroutine Definition to main.sbr
                                currentEditor.insertCMD(13,"", "", "", "","","", "", "" , "" , subroutineNameTextInput.text);
                                //****************************************************

                                functionEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
                                functionTab = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
                                functionTab.codeEditor = functionEditor
                                functionEditor.title="subroutine_"+subroutineNameTextInput.text+".sbr"


                                currentEditor = functionEditor
                                currentTabButton = functionTab
                                currentEditor.textArea.focus = true

                                currentEditor.insertCMD(9,"", "", "", "","","", "", "" , "" , subroutineNameTextInput.text);
                                functionEditor.setFileUrl(_mainPrjCodePath.replace('main.sbr','subroutine_'+subroutineNameTextInput.text+'.sbr'))
                                functionEditor.save()

                            }
                            else if(_is_interupt_selected)
                            {
                                //****************************************************
                                // add interupt Definition to main.sbr
                                currentEditor.insertCMD(12,"", "", "", "","","", "", interuptPriorityTextInput.text , interuptConditionTextInput.text , interuptNameTextInput.text);
                                //****************************************************

                                interruptEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
                                interruptTab = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
                                interruptTab.codeEditor = interruptEditor
                                interruptEditor.title="interrupt_"+interuptNameTextInput.text+".itp"


                                currentEditor = interruptEditor
                                currentTabButton = interruptTab
                                currentEditor.textArea.focus = true

                                currentEditor.insertCMD(5,"", "", "", "","","", "", "" , "", interuptNameTextInput.text);
                                interruptEditor.setFileUrl(_mainPrjCodePath.replace('main.sbr','interrupt_'+interuptNameTextInput.text+'.itp'))
                                interruptEditor.save()
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
                    visible: _is_motion_selected && _have_active_prj
                    model: ["PTP","LIN","CIRC"]
                    displayText: cmb_motion.currentText
                    delegate: ItemDelegate {
                        width: cmb_motion.width
                        contentItem: Text {
                            text: modelData
                            color: "#EFECCA"
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
                            context.fillStyle = cmb_motion.pressed ? "#046380" : "#EFECCA";
                            context.fill();
                        }
                    }

                    contentItem: Text {
                        leftPadding: 10
                        rightPadding: cmb_motion.indicator.width + cmb_motion.spacing

                        text: cmb_motion.displayText
                        font: cmb_motion.font
                        color: cmb_motion.pressed ? "#046380" : "#EFECCA"
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 40
                        border.color: cmb_motion.pressed ? "#046380" : "#EFECCA"
                        border.width: cmb_motion.visualFocus ? 2 : 1
                        color: "#046380"
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
                            border.color: "#EFECCA"
                            color: "#046380"
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
                    visible: _is_program_flow_selected && _have_active_prj
                    model: ["IF","IF/ELSE","FOR","WHILE"]
                    displayText: cmb_program_flow.currentText
                    delegate: ItemDelegate {
                        width: cmb_program_flow.width
                        contentItem: Text {
                            text: modelData
                            color: "#EFECCA"
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
                            context.fillStyle = cmb_program_flow.pressed ? "#046380" : "#EFECCA";
                            context.fill();
                        }
                    }

                    contentItem: Text {
                        leftPadding: 10
                        rightPadding: cmb_program_flow.indicator.width + cmb_program_flow.spacing

                        text: cmb_program_flow.displayText
                        font: cmb_program_flow.font
                        color: cmb_program_flow.pressed ? "#046380" : "#EFECCA"
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 40
                        border.color: cmb_program_flow.pressed ? "#046380" : "#EFECCA"
                        border.width: cmb_program_flow.visualFocus ? 2 : 1
                        color: "#046380"
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
                            border.color: "#EFECCA"
                            color: "#046380"
                            radius: 5
                        }
                    }
                    onActivated:{
                        ifConditionTextInput.text="counter==0"
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
                    visible: _is_wait_selected && _have_active_prj
                    model: ["wait for","wait second"]
                    displayText: cmb_wait.currentText
                    delegate: ItemDelegate {
                        width: cmb_wait.width
                        contentItem: Text {
                            text: modelData
                            color: "#EFECCA"
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
                            context.fillStyle = cmb_wait.pressed ? "#046380" : "#EFECCA";
                            context.fill();
                        }
                    }

                    contentItem: Text {
                        leftPadding: 10
                        rightPadding: cmb_wait.indicator.width + cmb_wait.spacing

                        text: cmb_wait.displayText
                        font: cmb_wait.font
                        color: cmb_wait.pressed ? "#046380" : "#EFECCA"
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 40
                        border.color: cmb_wait.pressed ? "#046380" : "#EFECCA"
                        border.width: cmb_wait.visualFocus ? 2 : 1
                        color: "#046380"
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
                            border.color: "#EFECCA"
                            color: "#046380"
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
                        visible: (_is_ptp_selected || _is_lin_selected || _is_circ_selected)&&_is_motion_selected && _have_active_prj
                        model: getPointsList()
                        displayText: cmb_point1.currentText
                        delegate: ItemDelegate {
                            width: cmb_point1.width
                            contentItem: Text {
                                text: modelData
                                color: "#EFECCA"
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
                                context.fillStyle = cmb_point1.pressed ? "#046380" : "#EFECCA";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_point1.indicator.width + cmb_point1.spacing

                            text: cmb_point1.displayText
                            font: cmb_point1.font
                            color: cmb_point1.pressed ? "#046380" : "#EFECCA"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_point1.pressed ? "#046380" : "#EFECCA"
                            border.width: cmb_point1.visualFocus ? 2 : 1
                            color: "#046380"
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
                                border.color: "#EFECCA"
                                color: "#046380"
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
                        visible: _is_circ_selected && _is_motion_selected && _have_active_prj
                        model: getPointsList()
                        displayText: cmb_point2.currentText
                        delegate: ItemDelegate {
                            width: cmb_point2.width
                            contentItem: Text {
                                text: modelData
                                color: "#EFECCA"
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
                                context.fillStyle = cmb_point2.pressed ? "#046380" : "#EFECCA";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_point2.indicator.width + cmb_point2.spacing

                            text: cmb_point2.displayText
                            font: cmb_point2.font
                            color: cmb_point2.pressed ? "#046380" : "#EFECCA"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_point2.pressed ? "#046380" : "#EFECCA"
                            border.width: cmb_point2.visualFocus ? 2 : 1
                            color: "#046380"
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
                                border.color: "#EFECCA"
                                color: "#046380"
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
                    visible: _is_reach_step4 && (_is_ptp_selected || _is_lin_selected ) && _have_active_prj

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/15
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("F:")
                            color: "#EFECCA"
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
                            color: "#EFECCA"
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
                            color: "#EFECCA"
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
                            color: "#EFECCA"
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
                    visible: _is_reach_step4 && _is_circ_selected && _have_active_prj

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/15
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("F:")
                            color: "#EFECCA"
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
                            color: "#EFECCA"
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
                            color: "#EFECCA"
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
                            color: "#EFECCA"
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
                            color: "#EFECCA"
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
                    visible: _is_reach_step4 && (_is_if_selected || _is_if_else_selected || _is_while_selected || _is_wait_for_selected || _is_wait_sec_selected) && _have_active_prj

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
                            color: "#EFECCA"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/6
                        height: parent.height

                        TextInput {
                            id: ifConditionTextInput
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "counter==0"
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
                    visible: _is_reach_step4 && _is_for_selected && _have_active_prj

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/11
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("ID:")
                            color: "#EFECCA"
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
                            color: "#EFECCA"
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
                            color: "#EFECCA"
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
                    visible: _is_reach_step4 && _is_interupt_selected && _have_active_prj

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/11
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("Name:")
                            color: "#EFECCA"
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
                            color: "#EFECCA"
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
                            color: "#EFECCA"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/6
                        height: parent.height

                        TextInput {
                            id: interuptConditionTextInput
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "DIN[5]==1"
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
                    visible: _is_reach_step4 && _is_subroutine_selected && _have_active_prj

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/11
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("Name:")
                            color: "#EFECCA"
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
                    visible: _is_set_frame_selected && _have_active_prj

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
                                color: "#EFECCA"
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
                                context.fillStyle = cmb_frame_type.pressed ? "#046380" : "#EFECCA";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_frame_type.indicator.width + cmb_frame_type.spacing

                            text: cmb_frame_type.displayText
                            font: cmb_frame_type.font
                            color: cmb_frame_type.pressed ? "#046380" : "#EFECCA"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_frame_type.pressed ? "#046380" : "#EFECCA"
                            border.width: cmb_frame_type.visualFocus ? 2 : 1
                            color: "#046380"
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
                                color: "#046380"
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
                                color: "#EFECCA"
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
                                context.fillStyle = cmb_frame_name.pressed ? "#046380" : "#EFECCA";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_frame_name.indicator.width + cmb_frame_name.spacing

                            text: cmb_frame_name.displayText
                            font: cmb_frame_name.font
                            color: cmb_frame_name.pressed ? "#046380" : "#EFECCA"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_frame_name.pressed ? "#046380" : "#EFECCA"
                            border.width: cmb_frame_name.visualFocus ? 2 : 1
                            color: "#046380"
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
                                border.color: "#EFECCA"
                                color: "#046380"
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

    //********************************************************
    //********************************************************


    Popup
    {
        id: getProjectNamePopUp
        anchors.centerIn: parent
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
                            text: qsTr("Project Name")
                            color: "#EFECCA"
                        }
                    }

                    MFrame
                    {
                        width: parent.width * 4/5
                        height: parent.height

                        TextInput {
                            id: projectNameTextInput
                            width: parent.width
                            height: parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#EFECCA"
                            text: "temp"
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
                            getProjectNamePopUp.close()
                        }
                    }
                    MButton {
                        _text: "Ok"
                        _width:parent.width * 1/4
                        height: parent.height
                        onBtnClick:
                        {
                            currentEditor.create_directory(_defaultPrjPath)
                            if(currentEditor.create_directory(_defaultPrjPath+"/"+projectNameTextInput.text))
                            {

                                _current_prj_name=projectNameTextInput.text
                                prjPath=_defaultPrjPath+"/"+projectNameTextInput.text+"/"+projectNameTextInput.text+".six"
                                _mainPrjCodePath=_defaultPrjPath+"/"+projectNameTextInput.text+"/main.sbr"
                                fileio.currentProject=_mainPrjCodePath.replace('main.sbr','final.code')
                                newPrj()
                                _have_active_prj=true
                                getProjectNamePopUp.close()
                            }
                            else
                            {
                                errorPopupText.text="The Project Name is Duplicate. Try Another."
                                error_popup.open()
                            }

//                            prjPath = fileDialogSave.fileUrl//+".six"
//                            var ext = prjPath.split(".").pop()
//                            if(ext!="six"){
//                                prjPath+=".six"
//                            }
//                            newPrj()
//                            if(cb != undefined) {
//                                cb()
//                                cb = null
//                            }
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
        id: openExistProjectPopUp
        anchors.centerIn: parent
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
                            openPrj()
                            openExistProjectPopUp.close()
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
        id: openExistFilePopUp
        anchors.centerIn: parent
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
                            text: qsTr("File")
                            color: "#EFECCA"
                        }
                    }

                    //***************************************************
                    //***************************************************
                    ComboBox {
                        id: cmb_openExistFilePopUp
                        height: parent.height
                        width: parent.width * 3/5
                        model: _exist_files_name
                        displayText: cmb_openExistFilePopUp.currentText
                        delegate: ItemDelegate {
                            width: cmb_openExistFilePopUp.width
                            contentItem: Text {
                                text: modelData
                                color: "#EFECCA"
                                font: cmb_openExistFilePopUp.font
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }
                            highlighted: cmb_openExistFilePopUp.highlightedIndex === index
                        }

                        indicator: Canvas {
                            id: cmb_openExistFilePopUp_canvas
                            x: cmb_openExistFilePopUp.width - width - cmb_openExistFilePopUp.rightPadding
                            y: cmb_openExistFilePopUp.topPadding + (cmb_openExistFilePopUp.availableHeight - height) / 2
                            width: 12
                            height: 8
                            contextType: "2d"

                            Connections {
                                target: cmb_openExistFilePopUp
                                onPressedChanged: cmb_openExistFilePopUp_canvas.requestPaint()
                            }

                            onPaint: {
                                context.reset();
                                context.moveTo(0, 0);
                                context.lineTo(width, 0);
                                context.lineTo(width / 2, height);
                                context.closePath();
                                context.fillStyle = cmb_openExistFilePopUp.pressed ? "#046380" : "#EFECCA";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_openExistFilePopUp.indicator.width + cmb_openExistFilePopUp.spacing

                            text: cmb_openExistFilePopUp.displayText
                            font: cmb_openExistFilePopUp.font
                            color: cmb_openExistFilePopUp.pressed ? "#046380" : "#EFECCA"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_openExistFilePopUp.pressed ? "#046380" : "#EFECCA"
                            border.width: cmb_openExistFilePopUp.visualFocus ? 2 : 1
                            color: "#046380"
                            radius: 2
                        }

                        popup: Popup {
                            y: cmb_openExistFilePopUp.height - 1
                            width: cmb_openExistFilePopUp.width
                            implicitHeight: contentItem.implicitHeight
                            padding: 1

                            contentItem: ListView {
                                clip: true
                                implicitHeight: contentHeight
                                model: cmb_openExistFilePopUp.popup.visible ? cmb_openExistFilePopUp.delegateModel : null
                                currentIndex: cmb_openExistFilePopUp.highlightedIndex

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
                            openExistFilePopUp.close()
                        }
                    }
                    MButton {
                        _text: "Open"
                        _width:parent.width * 1/4
                        height: parent.height
                        onBtnClick:
                        {
                            openTab()
                            openExistFilePopUp.close()
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
        id: error_popup
        anchors.centerIn: parent
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

    //********************************************************
    //********************************************************

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
