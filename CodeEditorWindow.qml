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
    property var _current_active_txtbox_obj: null

    //**********************************

    property variant _frames_name: []
    property variant _exist_projects_name: []
    property variant _exist_files_name: []
    property variant _config_parameter_values: []
    property variant _interrup_names_list: []
    property string _defaultPrjPath: "SixR_Projects"
    property string _mainPrjCodePath: ""
    property string _current_prj_name: ""
    property int _count_of_fors_in_current_prj: 1
    property int _count_of_subroutines_in_current_prj: 1
    property int _count_of_interupts_in_current_prj: 1

    //**********************************
    // flags
    property bool _is_motion_selected: false
    property bool _is_program_flow_selected: false
    property bool _is_wait_selected: false
    property bool _is_ptp_selected: false
    property bool _is_lin_selected: false
    property bool _is_circ_selected: false
    property bool _is_teached_point_selected: false
    property bool _is_direct_point_selected: false
    property bool _is_joint_type_selected: false
    property bool _is_cartesian_type_selected: false
    property bool _is_reach_step4: false
    property bool _is_if_selected: false
    property bool _is_if_else_selected: false
    property bool _is_for_selected: false
    property bool _is_while_selected: false
    property bool _is_wait_for_selected: false
    property bool _is_wait_sec_selected: false
    property bool _is_interupt_selected: false
    property bool _is_interupt_difinition_selected: false
    property bool _is_interupt_change_priority_selected: false
    property bool _is_subroutine_selected: false
    property bool _is_set_frame_selected: false
    property bool _is_goto_start_selected: false
    property bool _is_config_selected: false
    property bool _is_singulptp_selected: false
    property bool _is_singulcp_selected: false
    property bool _is_confj_selected: false
    property bool _is_confdata_selected: false
    property bool _is_io_selected: false
    property bool _is_input_selected: false
    property bool _is_output_selected: false

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
            //************************************************
            // read prj config file info
            var config_file_path=prjPath.replace(cmb_openExistProjectPopUp.currentText+".six",'config')
            var config_txt = openFile(config_file_path)
            var configs = config_txt.split("\n");
            _count_of_fors_in_current_prj = configs[0].split("=")[1];
            _count_of_subroutines_in_current_prj=configs[1].split("=")[1];
            _count_of_interupts_in_current_prj=configs[2].split("=")[1];
            console.log(_count_of_interupts_in_current_prj)
            //*************************************************

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
                    focusCurrentEditor()
                    if(i==0)
                    {
                        newCodeEditor.isReadOnly=true
                        newTabButton.enabled=false
                    }
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
        newTabButton.enabled=false
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

    function initTabs(){
        closeAllTab()
        newFinalTab()
        newMainTab()
        refreshProjectFiles()
    }
    function newTab() {
        var newCodeEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
        var newTabButton = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
        newTabButton.codeEditor = newCodeEditor
        newCodeEditor.title=""
        newCodeEditor.text=""
        newCodeEditor.changedSinceLastSave = false
        tabBar.setCurrentIndex(tabBar.count-1) // select it
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

            var _configs_txt="_count_of_fors_in_current_prj="+_count_of_fors_in_current_prj
            _configs_txt+="\n_count_of_subroutines_in_current_prj="+_count_of_subroutines_in_current_prj
            _configs_txt+="\n_count_of_interupts_in_current_prj="+_count_of_interupts_in_current_prj
            var _prj_config_file_path=_mainPrjCodePath.replace('main.sbr','config')
            saveFile(_prj_config_file_path, _configs_txt)

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
    function startCurrentPrj()
    {
        fileio.startedCurrentPrj();
    }

    FileIO{
        id: fileio
        onFinProject:
        {
            _is_started_prj=false
            // jump to main.sbr Tab
            tabBar.setCurrentIndex(1)
            currentEditor = stackLayout.itemAt(1)
            focusCurrentEditor()
        }
    }


    Popup {
        id:popuperrors

        implicitHeight: contentItem.implicitHeight
        //anchors.centerIn: parent
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
                Material.accent: Material.color(Material.Yellow,Material.Shade50)

                onCurrentIndexChanged: {
                    stackLayout.currentIndex=tabBar.currentIndex
                    focusCurrentEditor()
                }

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
            StackLayout
            {
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
            StackLayout
            {
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
            Grid
            {
                spacing: 5
                rows: 7
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
                MButton
                {
                    _width: 125
                    _height: 35
                    enabled: !_is_started_prj
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
                        enabled:!_is_started_prj
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
                        enabled:_have_active_prj && !_is_started_prj
                        id: savePrjButton
                        _text: "Save"
                        onBtnClick: {
                            refreshProjectFiles()
                        }
                    }
                }

                MButton
                {
                    _width: 125
                    _height: 35
                    enabled:_have_active_prj && !_is_started_prj
                    id: openTabButton
                    _text: "Open Exist File"
                    onBtnClick: {
                        var res=getExistFilesName()
                        _exist_files_name=res.split('#')
                        openExistFilePopUp.open()
                        //                        openTab()
                    }
                }

                MButton
                {
                    _width: 125
                    _height: 35
                    enabled:_have_active_prj && !_is_started_prj
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
                        else
                        {
                            startCurrentPrj()
                            _is_started_prj = true
                        }
                    }
                }
                MTextField
                {
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
                                _isActive = true
                                _text="Run"
                            }
                            else{
                                _isActive = false
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
                            pauseCurrentTabButton._isActive=false
                            _isActive = false
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


            //            Rectangle
            //            {
            //                width: parent.width * 1/10
            //                height: parent.height
            //                color: "transparent"
            //            }

            Column
            {
                width: parent.width
                height: parent.height


                Row
                {
                    height: parent.height * 1/5
                    width: parent.width
                    spacing: 2

                    // Main Combobox
                    //***************************************************
                    //***************************************************
                    ComboBox
                    {
                        id: cmb_main
                        height: parent.height
                        width: parent.width * 1/5
                        visible: _have_active_prj
                        model: ["Motion","program flow","wait","Interrupt","Subroutine","Set Frame","GotoStart","Config","I/O"]
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
                            _is_interupt_selected=false
                            _is_interupt_difinition_selected=false
                            _is_interupt_change_priority_selected=false
                            _is_reach_step4=false
                            _is_singulptp_selected=false
                            _is_singulcp_selected=false
                            _is_confj_selected=false
                            _is_confdata_selected=false
                            _is_goto_start_selected = false
                            _is_config_selected=false
                            _is_io_selected=false
                            _is_input_selected=false
                            _is_output_selected=false
                            _is_direct_point_selected=false
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
                                _is_goto_start_selected = false
                                _is_config_selected=false
                                _is_io_selected=false
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
                                _is_goto_start_selected = false
                                _is_config_selected=false
                                _is_io_selected=false
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
                                _is_goto_start_selected = false
                                _is_config_selected=false
                                _is_io_selected=false
                            }
                            //Interrupt
                            else if(cmb_main.currentText==model[3])
                            {
                                _is_reach_step4=false
                                //****************************
                                _is_motion_selected=false
                                _is_program_flow_selected=false
                                _is_wait_selected=false
                                _is_interupt_selected=true
                                _is_subroutine_selected=false
                                _is_set_frame_selected=false
                                _is_goto_start_selected = false
                                _is_config_selected=false
                                _is_io_selected=false
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
                                _is_goto_start_selected = false
                                _is_config_selected=false
                                _is_io_selected=false
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
                                _is_goto_start_selected = false
                                _is_config_selected=false
                                _is_io_selected=false
                            }
                            //GotoStart
                            else if(cmb_main.currentText==model[6])
                            {
                                _is_reach_step4=true
                                //****************************
                                _is_motion_selected=false
                                _is_program_flow_selected=false
                                _is_wait_selected=false
                                _is_interupt_selected=false
                                _is_subroutine_selected=false
                                _is_set_frame_selected=false
                                _is_goto_start_selected = true
                                _is_config_selected=false
                                _is_io_selected=false
                            }
                            //Config
                            else if(cmb_main.currentText==model[7])
                            {
                                _is_reach_step4=false
                                //****************************
                                _is_motion_selected=false
                                _is_program_flow_selected=false
                                _is_wait_selected=false
                                _is_interupt_selected=false
                                _is_subroutine_selected=false
                                _is_set_frame_selected=false
                                _is_goto_start_selected = false
                                _is_config_selected=true
                                _is_io_selected=false
                            }
                            // io
                            else if(cmb_main.currentText==model[8])
                            {
                                _is_reach_step4=false
                                //****************************
                                _is_motion_selected=false
                                _is_program_flow_selected=false
                                _is_wait_selected=false
                                _is_interupt_selected=false
                                _is_subroutine_selected=false
                                _is_set_frame_selected=false
                                _is_goto_start_selected = false
                                _is_config_selected=false
                                _is_io_selected=true
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
                                if(ptpLinConchkbox.checked)
                                    _moveParam+=" CON "+ptpLinConTextInput.text;
                                if(ptpLinTimechkbox.checked)
                                    _moveParam+=" TIME "+ptpLinTimeTextInput.text;
                                if(ptpLinApproxchkbox.checked)
                                    _moveParam+=" Approx "+ptpLinApproxTextInput.text;

                                if(_is_teached_point_selected)
                                {
                                    if(_is_ptp_selected)
                                        currentEditor.insertCMD(6,cmb_point1.currentText, "", "", "","",_moveParam, "Theta "+"", "", "", "");
                                    else if(_is_lin_selected)
                                        currentEditor.insertCMD(7,cmb_point1.currentText, "", "", "","",_moveParam, "Theta "+"", "", "", "");
                                }
                                else if(_is_direct_point_selected)
                                {
                                    if(_is_joint_type_selected)
                                    {
                                        var _pointParam="J1:"+directPoint1J1_Input.text;
                                        _pointParam+=" , J2:"+directPoint1J2_Input.text;
                                        _pointParam+=" , J3:"+directPoint1J3_Input.text;
                                        _pointParam+=" , J4:"+directPoint1J4_Input.text;
                                        _pointParam+=" , J5:"+directPoint1J5_Input.text;
                                        _pointParam+=" , J6:"+directPoint1J6_Input.text;
                                    }
                                    else if(_is_cartesian_type_selected)
                                    {
                                        _pointParam="X:"+directPoint1X_Input.text;
                                        _pointParam+=" , Y:"+directPoint1Y_Input.text;
                                        _pointParam+=" , Z:"+directPoint1Z_Input.text;
                                        _pointParam+=" , A:"+directPoint1A_Input.text;
                                        _pointParam+=" , B:"+directPoint1B_Input.text;
                                        _pointParam+=" , C:"+directPoint1C_Input.text;
                                    }
                                    if(_is_ptp_selected)
                                        currentEditor.insertCMD(18,"", "", "", "","",_moveParam, "Theta "+"", _pointParam, "", "");
                                    else if(_is_lin_selected)
                                        currentEditor.insertCMD(19,"", "", "", "","",_moveParam, "Theta "+"", _pointParam, "", "");
                                }
                            }
                            else if(_is_circ_selected)
                            {
                                var _theta="";
                                _moveParam="F "+circFTextInput.text;
                                if(circConchkbox.checked)
                                    _moveParam+=" CON "+circConTextInput.text;
                                if(circTimechkbox.checked)
                                    _moveParam+=" TIME "+circTimeTextInput.text;
                                if(circApproxchkbox.checked)
                                    _moveParam+=" Approx "+circApproxTextInput.text;
                                if(circThetachkbox.checked)
                                    _theta+="Theta "+circThetaTextInput.text;

                                if(_is_teached_point_selected)
                                {
                                    currentEditor.insertCMD(8,cmb_point1.currentText, cmb_point2.currentText, "", "","",_moveParam, _theta, "", "", "");
                                }
                                else if(_is_cartesian_type_selected)
                                {
                                    var _point1Param="X:"+directPoint1X_Input.text;
                                    _point1Param+=" , Y:"+directPoint1Y_Input.text;
                                    _point1Param+=" , Z:"+directPoint1Z_Input.text;
                                    _point1Param+=" , A:"+directPoint1A_Input.text;
                                    _point1Param+=" , B:"+directPoint1B_Input.text;
                                    _point1Param+=" , C:"+directPoint1C_Input.text;

                                    var _point2Param="X:"+directPoint2X_Input.text;
                                    _point2Param+=" , Y:"+directPoint2Y_Input.text;
                                    _point2Param+=" , Z:"+directPoint2Z_Input.text;

                                    currentEditor.insertCMD(20,"", "", "", "","",_moveParam, _theta, _point1Param, _point2Param, "");
                                }
                            }
                            else if(_is_if_selected)
                            {
                                currentEditor.insertCMD(0,"", "", "", "","","", "", cmb_io_index.currentText, cmb_io_value.currentText, "");
                            }
                            else if(_is_if_else_selected)
                            {
                                currentEditor.insertCMD(1,"", "", "", "","","", "", cmb_io_index.currentText, cmb_io_value.currentText, "");
                            }
                            else if(_is_for_selected)
                            {
                                currentEditor.insertCMD(2,"", "", "", "","","", "", _count_of_fors_in_current_prj, forExperission2TextInput.text, "");
                                _count_of_fors_in_current_prj++;
                            }
                            else if(_is_while_selected)
                            {
                                currentEditor.insertCMD(3,"", "", "", "","","", "", cmb_io_index.currentText, cmb_io_value.currentText, "");
                            }
                            else if(_is_set_frame_selected)
                            {
                                currentEditor.insertCMD(4,"", "", "", cmb_frame_type.currentText,cmb_frame_name.currentText,"", "", "" , "", "");
                            }
                            else if(_is_wait_for_selected)
                            {
                                currentEditor.insertCMD(10,"", "", "", "","","", "", wait_parameter_input.text, "", "");
                            }
                            else if(_is_wait_sec_selected)
                            {
                                currentEditor.insertCMD(11,"", "", "", "","","", "", wait_parameter_input.text, "", "");
                            }

                            else if(_is_subroutine_selected)
                            {
                                //****************************************************
                                // add subroutine Definition to main.sbr
                                currentEditor.insertCMD(13,"", "", "", "","","", "", "" , "" , _count_of_subroutines_in_current_prj);
                                //****************************************************

                                functionEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
                                functionTab = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
                                functionTab.codeEditor = functionEditor
                                functionTab.color = "#002F2F"
                                functionEditor.title="subroutine_"+_count_of_subroutines_in_current_prj+".sbr"


                                currentEditor = functionEditor
                                currentTabButton = functionTab
                                currentEditor.textArea.focus = true

                                currentEditor.insertCMD(9,"", "", "", "","","", "", "" , "" , _count_of_subroutines_in_current_prj);
                                functionEditor.setFileUrl(_mainPrjCodePath.replace('main.sbr','subroutine_'+_count_of_subroutines_in_current_prj+'.sbr'))
                                functionEditor.save()

                                _count_of_subroutines_in_current_prj++;

                            }
                            else if(_is_interupt_selected)
                            {
                                if(_is_interupt_difinition_selected)
                                {
                                    //****************************************************
                                    // add interupt Definition to main.sbr
                                    currentEditor.insertCMD(12,"", "", "", "","","", interuptPriorityTextInput.text, cmb_io_index.currentText , cmb_io_value.currentText , _count_of_interupts_in_current_prj);
                                    //****************************************************

                                    interruptEditor = Qt.createQmlObject("import QtQuick 2.7; CodeEditor { }", stackLayout);
                                    interruptTab = Qt.createQmlObject("import QtQuick 2.7; import QtQuick.Controls 2.0; CodeEditorTabButton { }", tabBar);
                                    interruptTab.codeEditor = interruptEditor
                                    interruptTab.color = "#002F2F"
                                    interruptEditor.title="interrupt_"+_count_of_interupts_in_current_prj+".itp"


                                    currentEditor = interruptEditor
                                    currentTabButton = interruptTab
                                    currentEditor.textArea.focus = true

                                    currentEditor.insertCMD(5,"", "", "", "","","", "", "" , "", _count_of_interupts_in_current_prj);
                                    interruptEditor.setFileUrl(_mainPrjCodePath.replace('main.sbr','interrupt_'+_count_of_interupts_in_current_prj+'.itp'))
                                    interruptEditor.save()

                                    _count_of_interupts_in_current_prj++;
                                }
                                else if(_is_interupt_change_priority_selected)
                                {
                                    currentEditor.insertCMD(21,"", "", "", "","","", "", "" , interuptPriorityTextInput.text, cmb_interrupt_list.currentText);
                                }
                            }
                            else if(_is_goto_start_selected)
                            {
                                currentEditor.insertCMD(14,"", "", "", "","","", "", "", "", "");
                            }
                            else if(_is_config_selected)
                            {
                                currentEditor.insertCMD(15,"", "", "", "","","", "", cmb_config.currentText, cmb_config_value.currentText, "");
                            }
                            else if(_is_input_selected)
                            {
                                currentEditor.insertCMD(16,"", "", "", "","","", "", cmb_io_index.currentText, "", "");
                            }
                            else if(_is_output_selected)
                            {
                                currentEditor.insertCMD(17,"", "", "", "","","", "", cmb_io_index.currentText, cmb_io_value.currentText, "");
                            }
                        }
                    }

                    MButton
                    {
                        id: undoButton
                        _height: parent.height
                        visible: _is_reach_step4 && _have_active_prj
                        _text: "UNDO"
                        onBtnClick:
                        {
                            currentEditor.undoText()
                        }
                    }
                }


                // Motion
                //***************************************************
                //***************************************************


                Row
                {
                    height: parent.height * 1/5
                    width: parent.width
                    spacing: 5
                    visible: _is_motion_selected && _have_active_prj


                    // Motion combobox
                    //***************************************************
                    //***************************************************
                    ComboBox
                    {
                        id: cmb_motion
                        height: parent.height
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
                                _is_cartesian_type_selected=true
                                _is_joint_type_selected=false
                            }
                            //circ
                            else if(cmb_motion.currentText==model[2])
                            {
                                _is_ptp_selected=false
                                _is_lin_selected=false
                                _is_circ_selected=true
                                _is_cartesian_type_selected=true
                                _is_joint_type_selected=false
                            }
                        }
                    }

                    // select point type ComboBox
                    //***************************************************
                    //***************************************************
                    ComboBox
                    {
                        id: cmb_select_point_type
                        height: parent.height
                        width: parent.width * 1/5
                        visible: (_is_ptp_selected||_is_lin_selected||_is_circ_selected) && _have_active_prj
                        model: ["Teached Point","Direct Point"]
                        displayText: cmb_select_point_type.currentText
                        delegate: ItemDelegate {
                            width: cmb_select_point_type.width
                            contentItem: Text {
                                text: modelData
                                color: "#EFECCA"
                                font: cmb_select_point_type.font
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }
                            highlighted: cmb_select_point_type.highlightedIndex === index
                        }

                        indicator: Canvas {
                            id: cmb_select_point_type_canvas
                            x: cmb_select_point_type.width - width - cmb_select_point_type.rightPadding
                            y: cmb_select_point_type.topPadding + (cmb_select_point_type.availableHeight - height) / 2
                            width: 12
                            height: 8
                            contextType: "2d"

                            Connections {
                                target: cmb_select_point_type
                                onPressedChanged: cmb_select_point_type_canvas.requestPaint()
                            }

                            onPaint: {
                                context.reset();
                                context.moveTo(0, 0);
                                context.lineTo(width, 0);
                                context.lineTo(width / 2, height);
                                context.closePath();
                                context.fillStyle = cmb_select_point_type.pressed ? "#046380" : "#EFECCA";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_select_point_type.indicator.width + cmb_select_point_type.spacing

                            text: cmb_select_point_type.displayText
                            font: cmb_select_point_type.font
                            color: cmb_select_point_type.pressed ? "#046380" : "#EFECCA"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_select_point_type.pressed ? "#046380" : "#EFECCA"
                            border.width: cmb_select_point_type.visualFocus ? 2 : 1
                            color: "#046380"
                            radius: 2
                        }

                        popup: Popup {
                            y: cmb_select_point_type.height - 1
                            width: cmb_select_point_type.width
                            implicitHeight: contentItem.implicitHeight
                            padding: 1

                            contentItem: ListView {
                                clip: true
                                implicitHeight: contentHeight
                                model: cmb_select_point_type.popup.visible ? cmb_select_point_type.delegateModel : null
                                currentIndex: cmb_select_point_type.highlightedIndex

                                ScrollIndicator.vertical: ScrollIndicator { }
                            }

                            background: Rectangle {
                                border.color: "#EFECCA"
                                color: "#046380"
                                radius: 5
                            }
                        }
                        onActivated:{
                            //teached point
                            if(cmb_select_point_type.currentText==model[0])
                            {
                                _is_teached_point_selected=true
                                _is_direct_point_selected=false
                            }
                            //direct point
                            else if(cmb_select_point_type.currentText==model[1])
                            {
                                if(_is_circ_selected)
                                    _is_reach_step4=true
                                _is_teached_point_selected=false
                                _is_direct_point_selected=true
                            }
                        }
                    }


                    // select point type JOINT/CART
                    //***************************************************
                    //***************************************************
                    ComboBox
                    {
                        id: cmb_select_point_type_joint_cart
                        height: parent.height
                        width: parent.width * 1/5
                        visible: _is_ptp_selected && _is_direct_point_selected && _have_active_prj
                        model: ["Joint","Cartesian"]
                        displayText: cmb_select_point_type_joint_cart.currentText
                        delegate: ItemDelegate {
                            width: cmb_select_point_type_joint_cart.width
                            contentItem: Text {
                                text: modelData
                                color: "#EFECCA"
                                font: cmb_select_point_type_joint_cart.font
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }
                            highlighted: cmb_select_point_type_joint_cart.highlightedIndex === index
                        }

                        indicator: Canvas {
                            id: cmb_select_point_type_joint_cart_canvas
                            x: cmb_select_point_type_joint_cart.width - width - cmb_select_point_type_joint_cart.rightPadding
                            y: cmb_select_point_type_joint_cart.topPadding + (cmb_select_point_type_joint_cart.availableHeight - height) / 2
                            width: 12
                            height: 8
                            contextType: "2d"

                            Connections {
                                target: cmb_select_point_type_joint_cart
                                onPressedChanged: cmb_select_point_type_joint_cart_canvas.requestPaint()
                            }

                            onPaint: {
                                context.reset();
                                context.moveTo(0, 0);
                                context.lineTo(width, 0);
                                context.lineTo(width / 2, height);
                                context.closePath();
                                context.fillStyle = cmb_select_point_type_joint_cart.pressed ? "#046380" : "#EFECCA";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_select_point_type_joint_cart.indicator.width + cmb_select_point_type_joint_cart.spacing

                            text: cmb_select_point_type_joint_cart.displayText
                            font: cmb_select_point_type_joint_cart.font
                            color: cmb_select_point_type_joint_cart.pressed ? "#046380" : "#EFECCA"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_select_point_type_joint_cart.pressed ? "#046380" : "#EFECCA"
                            border.width: cmb_select_point_type_joint_cart.visualFocus ? 2 : 1
                            color: "#046380"
                            radius: 2
                        }

                        popup: Popup {
                            y: cmb_select_point_type_joint_cart.height - 1
                            width: cmb_select_point_type_joint_cart.width
                            implicitHeight: contentItem.implicitHeight
                            padding: 1

                            contentItem: ListView {
                                clip: true
                                implicitHeight: contentHeight
                                model: cmb_select_point_type_joint_cart.popup.visible ? cmb_select_point_type_joint_cart.delegateModel : null
                                currentIndex: cmb_select_point_type_joint_cart.highlightedIndex

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
                            //teached point
                            if(cmb_select_point_type_joint_cart.currentText==model[0])
                            {
                                _is_joint_type_selected=true
                                _is_cartesian_type_selected=false
                            }
                            //direct point
                            else if(cmb_select_point_type_joint_cart.currentText==model[1])
                            {
                                _is_joint_type_selected=false
                                _is_cartesian_type_selected=true
                            }
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


                // interupt
                //***************************************************
                //***************************************************
                Row
                {
                    height: parent.height * 1/5
                    width: parent.width
                    spacing: 5
                    visible: _is_interupt_selected && _have_active_prj

                    ComboBox
                    {
                        id: cmb_interrupt
                        height: parent.height
                        width: parent.width * 1/5
                        visible: _is_interupt_selected && _have_active_prj
                        model: ["definition","change priority"]
                        displayText: cmb_interrupt.currentText
                        delegate: ItemDelegate {
                            width: cmb_interrupt.width
                            contentItem: Text {
                                text: modelData
                                color: "#EFECCA"
                                font: cmb_interrupt.font
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }
                            highlighted: cmb_interrupt.highlightedIndex === index
                        }

                        indicator: Canvas {
                            id: cmb_interrupt_canvas
                            x: cmb_interrupt.width - width - cmb_interrupt.rightPadding
                            y: cmb_interrupt.topPadding + (cmb_interrupt.availableHeight - height) / 2
                            width: 12
                            height: 8
                            contextType: "2d"

                            Connections {
                                target: cmb_interrupt
                                onPressedChanged: cmb_interrupt_canvas.requestPaint()
                            }

                            onPaint: {
                                context.reset();
                                context.moveTo(0, 0);
                                context.lineTo(width, 0);
                                context.lineTo(width / 2, height);
                                context.closePath();
                                context.fillStyle = cmb_interrupt.pressed ? "#046380" : "#EFECCA";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_interrupt.indicator.width + cmb_interrupt.spacing

                            text: cmb_interrupt.displayText
                            font: cmb_interrupt.font
                            color: cmb_interrupt.pressed ? "#046380" : "#EFECCA"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_interrupt.pressed ? "#046380" : "#EFECCA"
                            border.width: cmb_interrupt.visualFocus ? 2 : 1
                            color: "#046380"
                            radius: 2
                        }

                        popup: Popup {
                            y: cmb_interrupt.height - 1
                            width: cmb_interrupt.width
                            implicitHeight: contentItem.implicitHeight
                            padding: 1

                            contentItem: ListView {
                                clip: true
                                implicitHeight: contentHeight
                                model: cmb_interrupt.popup.visible ? cmb_interrupt.delegateModel : null
                                currentIndex: cmb_interrupt.highlightedIndex

                                ScrollIndicator.vertical: ScrollIndicator { }
                            }

                            background: Rectangle {
                                border.color: "#EFECCA"
                                color: "#046380"
                                radius: 5
                            }
                        }
                        onActivated:{
                            //definition
                            if(cmb_interrupt.currentText==model[0])
                            {
                                _is_reach_step4=true
                                _is_interupt_difinition_selected=true
                                _is_interupt_change_priority_selected=false
                            }
                            //change priority
                            else if(cmb_interrupt.currentText==model[1])
                            {
                                var _temp_arr=[]
                                for(var i=1;i<_count_of_interupts_in_current_prj;i++)
                                    _temp_arr.push("interrupt_"+i)
                                _interrup_names_list=_temp_arr

                                _is_interupt_difinition_selected=false
                                _is_interupt_change_priority_selected=true
                            }
                        }
                    }



                    ComboBox
                    {
                        id: cmb_interrupt_list
                        height: parent.height
                        width: parent.width * 1/5
                        visible: _is_interupt_change_priority_selected
                        model:_interrup_names_list
                        displayText: cmb_interrupt_list.currentText
                        delegate: ItemDelegate {
                            width: cmb_interrupt_list.width
                            contentItem: Text {
                                text: modelData
                                color: "#EFECCA"
                                font: cmb_interrupt_list.font
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }
                            highlighted: cmb_interrupt_list.highlightedIndex === index
                        }

                        indicator: Canvas {
                            id: cmb_interrupt_list_canvas
                            x: cmb_interrupt_list.width - width - cmb_interrupt_list.rightPadding
                            y: cmb_interrupt_list.topPadding + (cmb_interrupt_list.availableHeight - height) / 2
                            width: 12
                            height: 8
                            contextType: "2d"

                            Connections {
                                target: cmb_interrupt_list
                                onPressedChanged: cmb_interrupt_list_canvas.requestPaint()
                            }

                            onPaint: {
                                context.reset();
                                context.moveTo(0, 0);
                                context.lineTo(width, 0);
                                context.lineTo(width / 2, height);
                                context.closePath();
                                context.fillStyle = cmb_interrupt_list.pressed ? "#046380" : "#EFECCA";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_interrupt_list.indicator.width + cmb_interrupt_list.spacing

                            text: cmb_interrupt_list.displayText
                            font: cmb_interrupt_list.font
                            color: cmb_interrupt_list.pressed ? "#046380" : "#EFECCA"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_interrupt_list.pressed ? "#046380" : "#EFECCA"
                            border.width: cmb_interrupt_list.visualFocus ? 2 : 1
                            color: "#046380"
                            radius: 2
                        }

                        popup: Popup {
                            y: cmb_interrupt_list.height - 1
                            width: cmb_interrupt_list.width
                            implicitHeight: contentItem.implicitHeight
                            padding: 1

                            contentItem: ListView {
                                clip: true
                                implicitHeight: contentHeight
                                model: cmb_interrupt_list.popup.visible ? cmb_interrupt_list.delegateModel : null
                                currentIndex: cmb_interrupt_list.highlightedIndex

                                ScrollIndicator.vertical: ScrollIndicator { }
                            }

                            background: Rectangle {
                                border.color: "#EFECCA"
                                color: "#046380"
                                radius: 5
                            }
                        }
                        onActivated:
                        {
                            _is_reach_step4=true
                        }
                    }



                }

                // config ComboBox
                //***************************************************
                //***************************************************
                ComboBox
                {
                    id: cmb_config
                    height: parent.height * 1/5
                    width: parent.width * 1/5
                    visible: _is_config_selected && _have_active_prj
                    model: ["SingulPTP","SingulCP","ConfJ","ConfData"]
                    displayText: cmb_config.currentText
                    delegate: ItemDelegate {
                        width: cmb_config.width
                        contentItem: Text {
                            text: modelData
                            color: "#EFECCA"
                            font: cmb_config.font
                            elide: Text.ElideRight
                            verticalAlignment: Text.AlignVCenter
                        }
                        highlighted: cmb_config.highlightedIndex === index
                    }

                    indicator: Canvas {
                        id: cmb_config_canvas
                        x: cmb_config.width - width - cmb_config.rightPadding
                        y: cmb_config.topPadding + (cmb_config.availableHeight - height) / 2
                        width: 12
                        height: 8
                        contextType: "2d"

                        Connections {
                            target: cmb_config
                            onPressedChanged: cmb_config_canvas.requestPaint()
                        }

                        onPaint: {
                            context.reset();
                            context.moveTo(0, 0);
                            context.lineTo(width, 0);
                            context.lineTo(width / 2, height);
                            context.closePath();
                            context.fillStyle = cmb_config.pressed ? "#046380" : "#EFECCA";
                            context.fill();
                        }
                    }

                    contentItem: Text {
                        leftPadding: 10
                        rightPadding: cmb_config.indicator.width + cmb_config.spacing

                        text: cmb_config.displayText
                        font: cmb_config.font
                        color: cmb_config.pressed ? "#046380" : "#EFECCA"
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 40
                        border.color: cmb_config.pressed ? "#046380" : "#EFECCA"
                        border.width: cmb_config.visualFocus ? 2 : 1
                        color: "#046380"
                        radius: 2
                    }

                    popup: Popup {
                        y: cmb_config.height - 1
                        width: cmb_config.width
                        implicitHeight: contentItem.implicitHeight
                        padding: 1

                        contentItem: ListView {
                            clip: true
                            implicitHeight: contentHeight
                            model: cmb_config.popup.visible ? cmb_config.delegateModel : null
                            currentIndex: cmb_config.highlightedIndex

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
                        //singulptp
                        if(cmb_config.currentText==model[0])
                        {
                            _config_parameter_values=[0,1]
                            _is_singulptp_selected=true
                            _is_singulcp_selected=false
                            _is_confj_selected=false
                            _is_confdata_selected=false
                        }
                        //singulcp
                        else if(cmb_config.currentText==model[1])
                        {
                            _config_parameter_values=[0,1]
                            _is_singulptp_selected=false
                            _is_singulcp_selected=true
                            _is_confj_selected=false
                            _is_confdata_selected=false
                        }
                        //confj
                        else if(cmb_config.currentText==model[2])
                        {
                            _config_parameter_values=[0,1]
                            _is_singulptp_selected=false
                            _is_singulcp_selected=false
                            _is_confj_selected=true
                            _is_confdata_selected=false
                        }
                        //confdata
                        else if(cmb_config.currentText==model[3])
                        {
                            _config_parameter_values=[0,1,2,3,4,5,6,7]
                            _is_singulptp_selected=false
                            _is_singulcp_selected=false
                            _is_confj_selected=false
                            _is_confdata_selected=true
                        }
                    }
                }



                // i/o ComboBox
                //***************************************************
                //***************************************************
                ComboBox
                {
                    id: cmb_io
                    height: parent.height * 1/5
                    width: parent.width * 1/5
                    visible: _is_io_selected && _have_active_prj
                    model: ["Input","Output"]
                    displayText: cmb_io.currentText
                    delegate: ItemDelegate {
                        width: cmb_io.width
                        contentItem: Text {
                            text: modelData
                            color: "#EFECCA"
                            font: cmb_io.font
                            elide: Text.ElideRight
                            verticalAlignment: Text.AlignVCenter
                        }
                        highlighted: cmb_io.highlightedIndex === index
                    }

                    indicator: Canvas {
                        id: cmb_io_canvas
                        x: cmb_io.width - width - cmb_io.rightPadding
                        y: cmb_io.topPadding + (cmb_io.availableHeight - height) / 2
                        width: 12
                        height: 8
                        contextType: "2d"

                        Connections {
                            target: cmb_io
                            onPressedChanged: cmb_io_canvas.requestPaint()
                        }

                        onPaint: {
                            context.reset();
                            context.moveTo(0, 0);
                            context.lineTo(width, 0);
                            context.lineTo(width / 2, height);
                            context.closePath();
                            context.fillStyle = cmb_io.pressed ? "#046380" : "#EFECCA";
                            context.fill();
                        }
                    }

                    contentItem: Text {
                        leftPadding: 10
                        rightPadding: cmb_io.indicator.width + cmb_io.spacing

                        text: cmb_io.displayText
                        font: cmb_io.font
                        color: cmb_io.pressed ? "#046380" : "#EFECCA"
                        verticalAlignment: Text.AlignVCenter
                        elide: Text.ElideRight
                    }

                    background: Rectangle {
                        implicitWidth: 120
                        implicitHeight: 40
                        border.color: cmb_io.pressed ? "#046380" : "#EFECCA"
                        border.width: cmb_io.visualFocus ? 2 : 1
                        color: "#046380"
                        radius: 2
                    }

                    popup: Popup {
                        y: cmb_io.height - 1
                        width: cmb_io.width
                        implicitHeight: contentItem.implicitHeight
                        padding: 1

                        contentItem: ListView {
                            clip: true
                            implicitHeight: contentHeight
                            model: cmb_io.popup.visible ? cmb_io.delegateModel : null
                            currentIndex: cmb_io.highlightedIndex

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
                        //input
                        if(cmb_io.currentText==model[0])
                        {
                            _is_input_selected=true
                            _is_output_selected=false
                        }
                        //output
                        else if(cmb_io.currentText==model[1])
                        {
                            _is_input_selected=false
                            _is_output_selected=true
                        }
                    }
                }






                //Select Teached point1&Point2 ComboBox
                //***************************************************
                //***************************************************
                Row
                {
                    height: parent.height * 1/5
                    width: parent.width
                    spacing: 5
                    visible: _is_teached_point_selected &&_is_motion_selected && _have_active_prj

                    // point1 ComboBox
                    //***************************************************
                    //***************************************************
                    ComboBox {
                        id: cmb_point1
                        height: parent.height
                        width: parent.width * 1/5
                        visible: _is_teached_point_selected &&_is_motion_selected && _have_active_prj
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
                        visible: _is_circ_selected && _is_teached_point_selected && _is_motion_selected && _have_active_prj
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



                // Direct point values Row
                //***************************************************
                //***************************************************
                Row
                {
                    id: direct_point_values_row
                    height: parent.height * 1/5
                    width: parent.width
                    visible: _is_reach_step4 && _is_direct_point_selected && _have_active_prj

                    //*********************************************************************
                    //*********************************************************************
                    // Joint

                    //*********************************************
                    // ponit1 J1
                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/25
                        color: "transparent"
                        visible: _is_joint_type_selected
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("J1:")
                            color: "#EFECCA"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/15
                        height: parent.height
                        visible: _is_joint_type_selected

                        TextInput {
                            id: directPoint1J1_Input
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "10"
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=directPoint1J1_Input
                                my_keyboard._writen_txt=directPoint1J1_Input.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
                        }
                    }


                    //*********************************************
                    // ponit1 J2
                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/25
                        color: "transparent"
                        visible: _is_joint_type_selected
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("J2:")
                            color: "#EFECCA"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/15
                        height: parent.height
                        visible: _is_joint_type_selected

                        TextInput {
                            id: directPoint1J2_Input
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "10"
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=directPoint1J2_Input
                                my_keyboard._writen_txt=directPoint1J2_Input.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
                        }
                    }


                    //*********************************************
                    // ponit1 J3
                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/25
                        color: "transparent"
                        visible: _is_joint_type_selected
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("J3:")
                            color: "#EFECCA"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/15
                        height: parent.height
                        visible: _is_joint_type_selected

                        TextInput {
                            id: directPoint1J3_Input
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "10"
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=directPoint1J3_Input
                                my_keyboard._writen_txt=directPoint1J3_Input.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
                        }
                    }


                    //*********************************************
                    // ponit1 J4
                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/25
                        color: "transparent"
                        visible: _is_joint_type_selected
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("J4:")
                            color: "#EFECCA"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/15
                        height: parent.height
                        visible: _is_joint_type_selected

                        TextInput {
                            id: directPoint1J4_Input
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "10"
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=directPoint1J4_Input
                                my_keyboard._writen_txt=directPoint1J4_Input.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
                        }
                    }


                    //*********************************************
                    // ponit1 J5
                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/25
                        color: "transparent"
                        visible: _is_joint_type_selected
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("J5:")
                            color: "#EFECCA"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/15
                        height: parent.height
                        visible: _is_joint_type_selected

                        TextInput {
                            id: directPoint1J5_Input
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "10"
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=directPoint1J5_Input
                                my_keyboard._writen_txt=directPoint1J5_Input.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
                        }
                    }


                    //*********************************************
                    // ponit1 J6
                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/25
                        color: "transparent"
                        visible: _is_joint_type_selected
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("J6:")
                            color: "#EFECCA"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/15
                        height: parent.height
                        visible: _is_joint_type_selected

                        TextInput {
                            id: directPoint1J6_Input
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "10"
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=directPoint1J6_Input
                                my_keyboard._writen_txt=directPoint1J6_Input.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
                        }
                    }


                    //********************************************************************
                    //********************************************************************
                    // Cartesian

                    //*********************************************
                    // ponit1 X
                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/25
                        color: "transparent"
                        visible: _is_cartesian_type_selected
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("X:")
                            color: "#EFECCA"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/15
                        height: parent.height
                        visible: _is_cartesian_type_selected

                        TextInput {
                            id: directPoint1X_Input
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "10"
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=directPoint1X_Input
                                my_keyboard._writen_txt=directPoint1X_Input.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
                        }
                    }


                    //*********************************************
                    // ponit1 Y
                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/25
                        color: "transparent"
                        visible: _is_cartesian_type_selected
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("Y:")
                            color: "#EFECCA"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/15
                        height: parent.height
                        visible: _is_cartesian_type_selected

                        TextInput {
                            id: directPoint1Y_Input
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "10"
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=directPoint1Y_Input
                                my_keyboard._writen_txt=directPoint1Y_Input.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
                        }
                    }


                    //*********************************************
                    // ponit1 Z
                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/25
                        color: "transparent"
                        visible: _is_cartesian_type_selected
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("Z:")
                            color: "#EFECCA"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/15
                        height: parent.height
                        visible: _is_cartesian_type_selected

                        TextInput {
                            id: directPoint1Z_Input
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "10"
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=directPoint1Z_Input
                                my_keyboard._writen_txt=directPoint1Z_Input.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
                        }
                    }


                    //*********************************************
                    // ponit1 A
                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/25
                        color: "transparent"
                        visible: _is_cartesian_type_selected
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("A:")
                            color: "#EFECCA"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/15
                        height: parent.height
                        visible: _is_cartesian_type_selected

                        TextInput {
                            id: directPoint1A_Input
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "10"
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=directPoint1A_Input
                                my_keyboard._writen_txt=directPoint1A_Input.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
                        }
                    }


                    //*********************************************
                    // ponit1 B
                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/25
                        color: "transparent"
                        visible: _is_cartesian_type_selected
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("B:")
                            color: "#EFECCA"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/15
                        height: parent.height
                        visible: _is_cartesian_type_selected

                        TextInput {
                            id: directPoint1B_Input
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "10"
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=directPoint1B_Input
                                my_keyboard._writen_txt=directPoint1B_Input.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
                        }
                    }


                    //*********************************************
                    // ponit1 C
                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/25
                        color: "transparent"
                        visible: _is_cartesian_type_selected
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("C:")
                            color: "#EFECCA"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/15
                        height: parent.height
                        visible: _is_cartesian_type_selected

                        TextInput {
                            id: directPoint1C_Input
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "10"
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=directPoint1C_Input
                                my_keyboard._writen_txt=directPoint1C_Input.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
                        }
                    }


                    //*********************************************

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/25
                        color: "transparent"
                        visible: _is_cartesian_type_selected
                    }

                    //*********************************************
                    // ponit2 X
                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/25
                        color: "transparent"
                        visible: _is_cartesian_type_selected && _is_circ_selected
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("X:")
                            color: "#EFECCA"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/15
                        height: parent.height
                        visible: _is_cartesian_type_selected && _is_circ_selected

                        TextInput {
                            id: directPoint2X_Input
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "10"
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=directPoint2X_Input
                                my_keyboard._writen_txt=directPoint2X_Input.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
                        }
                    }


                    //*********************************************
                    // ponit2 Y
                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/25
                        color: "transparent"
                        visible: _is_cartesian_type_selected && _is_circ_selected
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("Y:")
                            color: "#EFECCA"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/15
                        height: parent.height
                        visible: _is_cartesian_type_selected && _is_circ_selected

                        TextInput {
                            id: directPoint2Y_Input
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "10"
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=directPoint2Y_Input
                                my_keyboard._writen_txt=directPoint2Y_Input.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
                        }
                    }



                    //*********************************************
                    // ponit2 Z
                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/25
                        color: "transparent"
                        visible: _is_cartesian_type_selected && _is_circ_selected
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("Z:")
                            color: "#EFECCA"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/15
                        height: parent.height
                        visible: _is_cartesian_type_selected && _is_circ_selected

                        TextInput {
                            id: directPoint2Z_Input
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "10"
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=directPoint2Z_Input
                                my_keyboard._writen_txt=directPoint2Z_Input.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
                        }
                    }

                }



                Rectangle
                {
                    height: parent.height * 1/10
                    width: parent.width
                    color: "transparent"
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
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=ptpLinFTextInput
                                my_keyboard._writen_txt=ptpLinFTextInput.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
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
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=ptpLinConTextInput
                                my_keyboard._writen_txt=ptpLinConTextInput.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
                        }
                    }


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
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=ptpLinTimeTextInput
                                my_keyboard._writen_txt=ptpLinTimeTextInput.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
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
                        width: parent.width * 1/12
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
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=ptpLinApproxTextInput
                                my_keyboard._writen_txt=ptpLinApproxTextInput.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
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
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=circFTextInput
                                my_keyboard._writen_txt=circFTextInput.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
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
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=circThetaTextInput
                                my_keyboard._writen_txt=circThetaTextInput.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
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
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=circConTextInput
                                my_keyboard._writen_txt=circConTextInput.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
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
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=circTimeTextInput
                                my_keyboard._writen_txt=circTimeTextInput.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
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
                        width: parent.width * 1/12
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
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=circApproxTextInput
                                my_keyboard._writen_txt=circApproxTextInput.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
                        }
                    }
                }


                // Wait_For & WAit_Sec Row
                //***************************************************
                //***************************************************
                Row
                {
                    height: parent.height * 1/5
                    width: parent.width
                    visible: _is_reach_step4 && (_is_wait_for_selected || _is_wait_sec_selected) && _have_active_prj

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/7
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("Parameter:")
                            color: "#EFECCA"
                        }
                    }

                    MFrame{
                        width: parent.width  * 1/6
                        height: parent.height

                        TextInput {
                            id: wait_parameter_input
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "5"
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
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=forExperission2TextInput
                                my_keyboard._writen_txt=forExperission2TextInput.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
                        }
                    }
                }



                // Config Row
                //***************************************************
                //***************************************************
                Row
                {
                    id: config_parameters_row
                    height: parent.height * 1/5
                    width: parent.width
                    visible: _is_reach_step4 && (_is_confj_selected || _is_confdata_selected || _is_singulptp_selected || _is_singulcp_selected) && _have_active_prj

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/7
                        color: "transparent"
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("value:")
                            color: "#EFECCA"
                        }
                    }

                    ComboBox
                    {
                        id: cmb_config_value
                        height: parent.height
                        width: parent.width * 1/5
                        model: _config_parameter_values
                        displayText: cmb_config_value.currentText
                        delegate: ItemDelegate {
                            width: cmb_config_value.width
                            contentItem: Text {
                                text: modelData
                                color: "#EFECCA"
                                font: cmb_config_value.font
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }
                            highlighted: cmb_config_value.highlightedIndex === index
                        }

                        indicator: Canvas {
                            id: cmb_config_value_canvas
                            x: cmb_config_value.width - width - cmb_config_value.rightPadding
                            y: cmb_config_value.topPadding + (cmb_config_value.availableHeight - height) / 2
                            width: 12
                            height: 8
                            contextType: "2d"

                            Connections {
                                target: cmb_config_value
                                onPressedChanged: cmb_config_value_canvas.requestPaint()
                            }

                            onPaint: {
                                context.reset();
                                context.moveTo(0, 0);
                                context.lineTo(width, 0);
                                context.lineTo(width / 2, height);
                                context.closePath();
                                context.fillStyle = cmb_config_value.pressed ? "#046380" : "#EFECCA";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_config_value.indicator.width + cmb_config_value.spacing

                            text: cmb_config_value.displayText
                            font: cmb_config_value.font
                            color: cmb_config_value.pressed ? "#046380" : "#EFECCA"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_config_value.pressed ? "#046380" : "#EFECCA"
                            border.width: cmb_config_value.visualFocus ? 2 : 1
                            color: "#046380"
                            radius: 2
                        }

                        popup: Popup {
                            y: cmb_config_value.height - 1
                            width: cmb_config_value.width
                            implicitHeight: contentItem.implicitHeight
                            padding: 1

                            contentItem: ListView {
                                clip: true
                                implicitHeight: contentHeight
                                model: cmb_config_value.popup.visible ? cmb_config_value.delegateModel : null
                                currentIndex: cmb_config_value.highlightedIndex

                                ScrollIndicator.vertical: ScrollIndicator { }
                            }

                            background: Rectangle {
                                border.color: "#EFECCA"
                                color: "#046380"
                                radius: 5
                            }
                        }
                        onActivated:
                        {

                        }
                    }
                }


                // io & if & if\else & while & interupt Row
                //***************************************************
                //***************************************************
                Row
                {
                    id: io_parameters_row
                    height: parent.height * 1/5
                    width: parent.width
                    visible: _is_reach_step4 && (_is_input_selected || _is_output_selected || _is_if_selected || _is_if_else_selected || _is_while_selected || _is_interupt_selected) && _have_active_prj

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/7
                        color: "transparent"
                        visible: _is_interupt_selected
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
                        visible: _is_interupt_selected

                        TextInput {
                            id: interuptPriorityTextInput
                            width: parent.width
                            height:parent.height
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "#9E9E9E"
                            text: "1"
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=interuptPriorityTextInput
                                my_keyboard._writen_txt=interuptPriorityTextInput.text;
                                if(my_keyboard._writen_txt=="0")
                                    my_keyboard._writen_txt=""
                                keyboardPopup.open()
                            }
                        }
                    }

                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/7
                        color: "transparent"
                        visible: !_is_interupt_change_priority_selected
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("index:")
                            color: "#EFECCA"
                        }
                    }
                    ComboBox
                    {
                        id: cmb_io_index
                        height: parent.height
                        width: parent.width * 1/5
                        model: ["0","1","2","3","4","5","6","7","8","9","10","11","12","13","14","15"]
                        visible: !_is_interupt_change_priority_selected
                        displayText: cmb_io_index.currentText
                        delegate: ItemDelegate {
                            width: cmb_io_index.width
                            contentItem: Text {
                                text: modelData
                                color: "#EFECCA"
                                font: cmb_io_index.font
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }
                            highlighted: cmb_io_index.highlightedIndex === index
                        }

                        indicator: Canvas {
                            id: cmb_io_index_canvas
                            x: cmb_io_index.width - width - cmb_io_index.rightPadding
                            y: cmb_io_index.topPadding + (cmb_io_index.availableHeight - height) / 2
                            width: 12
                            height: 8
                            contextType: "2d"

                            Connections {
                                target: cmb_io_index
                                onPressedChanged: cmb_io_index_canvas.requestPaint()
                            }

                            onPaint: {
                                context.reset();
                                context.moveTo(0, 0);
                                context.lineTo(width, 0);
                                context.lineTo(width / 2, height);
                                context.closePath();
                                context.fillStyle = cmb_io_index.pressed ? "#046380" : "#EFECCA";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_io_index.indicator.width + cmb_io_index.spacing

                            text: cmb_io_index.displayText
                            font: cmb_io_index.font
                            color: cmb_io_index.pressed ? "#046380" : "#EFECCA"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_io_index.pressed ? "#046380" : "#EFECCA"
                            border.width: cmb_io_index.visualFocus ? 2 : 1
                            color: "#046380"
                            radius: 2
                        }

                        popup: Popup {
                            y: cmb_io_index.height - 1
                            width: cmb_io_index.width
                            implicitHeight: contentItem.implicitHeight
                            padding: 1

                            contentItem: ListView {
                                clip: true
                                implicitHeight: contentHeight
                                model: cmb_io_index.popup.visible ? cmb_io_index.delegateModel : null
                                currentIndex: cmb_io_index.highlightedIndex

                                ScrollIndicator.vertical: ScrollIndicator { }
                            }

                            background: Rectangle {
                                border.color: "#EFECCA"
                                color: "#046380"
                                radius: 5
                            }
                        }
                        onActivated:
                        {

                        }
                    }


                    Rectangle
                    {
                        height: parent.height
                        width: parent.width * 1/7
                        color: "transparent"
                        visible: (_is_output_selected || _is_if_selected || _is_if_else_selected || _is_while_selected || _is_interupt_selected ) && !_is_interupt_change_priority_selected
                        Label
                        {
                            anchors.centerIn: parent
                            text: qsTr("value:")
                            color: "#EFECCA"
                        }
                    }
                    ComboBox
                    {
                        id: cmb_io_value
                        height: parent.height
                        width: parent.width * 1/5
                        visible: (_is_output_selected || _is_if_selected || _is_if_else_selected || _is_while_selected || _is_interupt_selected ) && !_is_interupt_change_priority_selected
                        model: ["0","1"]
                        displayText: cmb_io_value.currentText
                        delegate: ItemDelegate {
                            width: cmb_io_value.width
                            contentItem: Text {
                                text: modelData
                                color: "#EFECCA"
                                font: cmb_io_value.font
                                elide: Text.ElideRight
                                verticalAlignment: Text.AlignVCenter
                            }
                            highlighted: cmb_io_value.highlightedIndex === index
                        }

                        indicator: Canvas {
                            id: cmb_io_value_canvas
                            x: cmb_io_value.width - width - cmb_io_value.rightPadding
                            y: cmb_io_value.topPadding + (cmb_io_value.availableHeight - height) / 2
                            width: 12
                            height: 8
                            contextType: "2d"

                            Connections {
                                target: cmb_io_value
                                onPressedChanged: cmb_io_value_canvas.requestPaint()
                            }

                            onPaint: {
                                context.reset();
                                context.moveTo(0, 0);
                                context.lineTo(width, 0);
                                context.lineTo(width / 2, height);
                                context.closePath();
                                context.fillStyle = cmb_io_value.pressed ? "#046380" : "#EFECCA";
                                context.fill();
                            }
                        }

                        contentItem: Text {
                            leftPadding: 10
                            rightPadding: cmb_io_value.indicator.width + cmb_io_value.spacing

                            text: cmb_io_value.displayText
                            font: cmb_io_value.font
                            color: cmb_io_value.pressed ? "#046380" : "#EFECCA"
                            verticalAlignment: Text.AlignVCenter
                            elide: Text.ElideRight
                        }

                        background: Rectangle {
                            implicitWidth: 120
                            implicitHeight: 40
                            border.color: cmb_io_value.pressed ? "#046380" : "#EFECCA"
                            border.width: cmb_io_value.visualFocus ? 2 : 1
                            color: "#046380"
                            radius: 2
                        }

                        popup: Popup {
                            y: cmb_io_value.height - 1
                            width: cmb_io_value.width
                            implicitHeight: contentItem.implicitHeight
                            padding: 1

                            contentItem: ListView {
                                clip: true
                                implicitHeight: contentHeight
                                model: cmb_io_value.popup.visible ? cmb_io_value.delegateModel : null
                                currentIndex: cmb_io_value.highlightedIndex

                                ScrollIndicator.vertical: ScrollIndicator { }
                            }

                            background: Rectangle {
                                border.color: "#EFECCA"
                                color: "#046380"
                                radius: 5
                            }
                        }
                        onActivated:
                        {

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
                        model: ["object","task","tool","base"]
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
                    if(_current_active_txtbox_obj==projectNameTextInput)
                    {
                        if(my_keyboard._writen_txt!="")
                            _current_active_txtbox_obj.text="project"+my_keyboard._writen_txt
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

    //********************************************************
    //********************************************************


    Popup
    {
        id: getProjectNamePopUp
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
                            text: "project"
                            onActiveFocusChanged:
                            {
                                _current_active_txtbox_obj=projectNameTextInput
                                // Delete 'project' From Text
                                my_keyboard._writen_txt=projectNameTextInput.text.substring(7, projectNameTextInput.text.length);
                                keyboardPopup.open()
                            }
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
                                _count_of_fors_in_current_prj=1
                                _count_of_subroutines_in_current_prj=1
                                _count_of_interupts_in_current_prj=1
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
