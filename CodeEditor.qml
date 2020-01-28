import QtQuick 2.7
import QtQuick.Controls 1.5
import QtQuick.Dialogs 1.2
import CodeEditor 1.0

Item {
    id: root
    property alias text: textArea.text
    property alias textArea: textArea
    property string title: changedSinceLastSave ? fileName+"*" : fileName
    property alias fileName: backend.fileName
    property bool changedSinceLastSave: false
    property bool isUnsavedFile: true
    property CodeEditorBackend currentBackEnd: backend


    function open(fileUrl) {
        backend.fileUrl = fileUrl
        backend.load()
        textArea.text = backend.text
        isUnsavedFile = false
        changedSinceLastSave = false
    }

    function save(cb) {
        backend.text = textArea.text
        if(fileName === "untitled") {
            fileDialogSave.cb = function() {
                save(cb)
                fileDialogSave.cb = undefined
            }
            fileDialogSave.visible = true
        } else {
            if(backend.save()) {
                changedSinceLastSave = false
                isUnsavedFile = false
                if(cb != undefined) cb()
            }
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
        backend.play(runFromLine);
    }
    function pause(){
        backend.pause();
    }
    function programReady(){
        backend.programReady();
    }
    function stop(){
        backend.stop();
    }
    function insertCMD(cmd, targetP1, targetP2, targetP3, frameType, frameTargetPoint, moveParam, theta, exp1, exp2, id){
        textArea.insert(textArea.cursorPosition,backend.addCommandToCurrentLine(cmd,targetP1, targetP2, targetP3,frameType,frameTargetPoint,moveParam, theta, exp1, exp2, id))
        textArea.update()
        backend.text = textArea.text
        changedSinceLastSave = true
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
            //textArea.select(start, end)
            //            console.log("You chose xxx: ", start, end)
            textArea.update()
        }
        onCursorPos:{
            backend.setCursorPos(lineNumbers.cursorPosition);
        }
    }

    TextArea {
        id: textArea
        height: parent.height
        width: parent.width-lineNumbers.width
        anchors.left: lineNumbers.right
        wrapMode: TextEdit.NoWrap
        text:backend.text;
        function update() {
            var lineHeight = (contentHeight-8) / lineCount
            lineNumbers.lineCount = lineCount
            lineNumbers.scrollY = flickableItem.contentY
            lineNumbers.lineHeight = lineHeight
            lineNumbers.cursorPosition = cursorPosition
            lineNumbers.selectionStart = selectionStart
            lineNumbers.selectionEnd = selectionEnd
            lineNumbers.text = text
            lineNumbers.update()
        }

        Component.onCompleted: {
            flickableItem.contentYChanged.connect(update)
            update()
        }

        onTextChanged: {
            changedSinceLastSave = true
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

        onAccepted: {
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
