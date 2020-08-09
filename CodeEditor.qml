import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Dialogs 1.2
import QtQuick.Controls.Styles 1.4
import CodeEditor 1.0


Item {
    id: root
    property alias text: textArea.text
    property alias textArea: textArea
    property string title: changedSinceLastSave ? fileName+"*" : fileName
    property alias fileName: backend.fileName
    property bool changedSinceLastSave: false
    property bool isUnsavedFile: true
    property bool isReadOnly: false
    property alias fileUrl: backend.fileUrl
    property CodeEditorBackend currentBackEnd: backend

    property string errors: backend.Errors

    property int mucount: 0


    function open(fileUrl) {
        backend.fileUrl = fileUrl
        backend.load()
        textArea.text = backend.text
        isUnsavedFile = false
        changedSinceLastSave = false
    }
    function setFileUrl(file_url){
        backend.fileUrl=file_url
    }

    function create_directory(path)
    {
        return backend.createDirectory(path)
    }

    function save(cb) {
        backend.text = textArea.text
//        fileDialogSave.nameFilters = [ "SixR program files (*.mnr)", "All files (*)" ]
//        if(fileName === "untitled") {
//            fileDialogSave.cb = function() {
//                save(cb)
//                fileDialogSave.cb = undefined
//            }
//            fileDialogSave.visible = true
//        } else {

//            var ext = fileName.split(".").pop()
//            if(ext!="mnr"){
//                backend.fileUrl+=".mnr"
//                //backend.fileName+=".mnr"
//            }
//            if(backend.save()) {
//                changedSinceLastSave = false
//                isUnsavedFile = false
//                console.log(backend.fileUrl)
//                if(cb != undefined) cb()
//            }else{
//                console.log('Failed to save ', backend.fileUrl)
//            }
//        }




//        backend.fileUrl="file:///home/hossein/"+cb
        console.log(backend.fileUrl)
        if(backend.save()) {
            changedSinceLastSave = false
            isUnsavedFile = false
//            if(cb != undefined) cb()
        }else{
            console.log('Failed to save ', backend.fileUrl)
        }
    }

    function saveAs() {
        backend.text = textArea.text
        fileDialogSave.cb = function() {
            save()
            fileDialogSave.cb = undefined
        }
        fileDialogSave.visible = true
    }

    function play(runFromLine){
        backend.play(runFromLine)
        errors = backend.Errors
    }
    function pause(){
        backend.pause()
    }

    function stop(){
        backend.stop()
    }
    function insertCMD(cmd, targetP1, targetP2, targetP3, frameType, frameTargetPoint, moveParam, theta, exp1, exp2, id){
        if(cmd==12)
            textArea.cursorPosition=0
        textArea.insert(textArea.cursorPosition,backend.addCommandToCurrentLine(cmd,targetP1, targetP2, targetP3,frameType,frameTargetPoint,moveParam, theta, exp1, exp2, id))
        textArea.update()
        backend.text = textArea.text
        changedSinceLastSave = true
    }
    function undoText()
    {
        textArea.undo()
    }

    LineNumbers {
        id: lineNumbers
        height: parent.height
        width: 40
    }

    CodeEditorBackend {
        id: backend
        fileName: "untitled"
        onLineSelect: {
            if(title=="final.code")
            {
                textArea.updateScrollPosition()
                textArea.update()
            }
        }
        onCursorPos:{
            backend.setCursorPos(lineNumbers.cursorPosition);
        }
    }

    TextArea {
        id: textArea
        //backgroundVisible: false
        style: TextAreaStyle {
                textColor: "#EFECCA"
                selectionColor: "#046380"
                selectedTextColor: "#EFECCA"
                backgroundColor: "#002F2F"
            }
        height: parent.height
        width: parent.width-lineNumbers.width
        anchors.left: lineNumbers.right
        wrapMode: TextEdit.NoWrap
        text:backend.text;
        readOnly: isReadOnly
        function updateScrollPosition()
        {
            if(lineNumbers.currentLine <= 7)
                flickableItem.contentY = 0
            else if(lineNumbers.currentLine > (lineCount - 6))
                flickableItem.contentY = (lineCount - (12 + (11.25/17)))*17
            else
                flickableItem.contentY = (lineNumbers.currentLine - 7) * 17
        }
        function update() {
            console.log("mrrrrrr    "+ flickableItem.contentY)
            var lineHeight = (contentHeight-8) / lineCount
            lineNumbers.lineCount = lineCount
            lineNumbers.scrollY = flickableItem.contentY
            lineNumbers.lineHeight = lineHeight
            lineNumbers.cursorPosition = cursorPosition
            lineNumbers.selectionStart = selectionStart
            lineNumbers.selectionEnd = selectionEnd
            lineNumbers.text = text
            lineNumbers.update()
            mucount++;
        }

        Component.onCompleted: {
//            flickableItem.contentY = 175
            flickableItem.contentYChanged.connect(update)
            update()
        }

        onTextChanged: {
            changedSinceLastSave = true
            //title= changedSinceLastSave ? fileName+"*" : fileName
        }

        onLineCountChanged: update()
        onHeightChanged: update()
        onCursorPositionChanged: update()
    }

    FileDialog {
        id: fileDialogSave
        selectExisting : false
        property var cb
        title: "Please choose a location to save"
        nameFilters: [ "Program files (*.mnr)", "All files (*)" ]
        onAccepted: {
            //            var a = fileDialogSave.fileUrl
            //            a.
            //            var ext = a.split(".")
            //            if(ext!="mnr"){
            //                fileDialogSave.fileUrl+=".mnr"
            //            }
            backend.fileUrl = fileDialogSave.fileUrl
            if(cb != undefined) {
                cb()
                cb = null
            }
        }
    }

    FileDialog {
        id: fileDialogLoad
        selectExisting : true
        property var cb
        title: "Please choose a file"

        onAccepted: {
            backend.fileUrl = fileDialogSave.fileUrl
            if(cb != undefined) {
                cb()
                cancelCloseEditor = false
                cb = null
            }
        }
        onRejected: {
            cancelCloseEditor = true
            cb = null
        }
    }
}
