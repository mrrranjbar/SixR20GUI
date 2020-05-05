import QtQuick 2.7
import QtQuick.Controls 2.0

TabButton {
    id: root
    property CodeEditor codeEditor
    property alias color: rect.color
    height: parent ? parent.height : 0
    onCodeEditorChanged: {
        if(codeEditor === undefined || codeEditor === null) return
        if(codeEditor != undefined) {
            text ="<font color='#EFECCA'>"+codeEditor.title+"</font>"
        }

        codeEditor.titleChanged.connect(function() {
            var arr =codeEditor.title.split("/")
            text ="<font color='#EFECCA'>"+ (arr[arr.length-1])+"</font>"//.split(".")[0]
        })
    }

    background: Rectangle {
        id: rect
        width: parent.width
        height: parent.height
        color: "#046380"
    }
    onFocusChanged: {
        rect.color = root.focus ? "#046380" : "#002F2F"
    }

    implicitWidth: width
    width: parent ? parent.width / parent.count : 0
}
