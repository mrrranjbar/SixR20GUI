import QtQuick 2.7
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.0
import Qt.labs.platform 1.1
import InterpreterViewModel 1.0

Item {
    property int _width: 260
    property int _height: 75
    InterpreterViewModel {
        id: interpreterviewmodel
    }
    MFrame{
        width: parent.width
        height: parent.height
        FileDialog {
            id: fileDialogSave
            title: "New file"
            //folder: shortcuts.home
            onAccepted: {
                //console.log("You chose: " + fileDialog.fileUrls)
                interpreterviewmodel.address = fileDialogSave.file
                interpreterviewmodel.newproject()
                //Qt.quit()
            }
            onRejected: {
                //console.log("Canceled")
                //Qt.quit()
            }
            fileMode: FileDialog.SaveFile
            Component.onCompleted: visible = false
        }
        FileDialog {
            id: fileDialogOpen
            title: "Open file"
            //folder: shortcuts.home
            onAccepted: {
                //console.log("You chose: " + fileDialog.fileUrls)
                interpreterviewmodel.address = fileDialogOpen.file
                interpreterviewmodel.openproject()
                //Qt.quit()
            }
            onRejected: {
                //console.log("Canceled")
                //Qt.quit()
            }
            fileMode: FileDialog.OpenFile
            Component.onCompleted: visible = false
        }
        Grid {
            width: parent.width
            height: parent.height
            rows: 2
            spacing: 5
            Grid{
                width: parent.width
                columns: 5
                spacing: 5
                MButton{

                    _width:parent.width / 6
                    _height:30
                    _text:"New"
                    onBtnClick: {
                        fileDialogSave.open()

                    }
                }
                MButton{

                    _width:parent.width / 6
                    _height:30
                    _text:"Open"
                    onBtnClick: {
                        fileDialogOpen.open()

                    }
                }

                MButton{

                    _width:parent.width / 6
                    _height:30
                    _text:"Save"
                    onBtnClick: {
                        interpreterviewmodel.textEditString=textarea.text
                        interpreterviewmodel.saveproject()
                    }
                }
                MButton{
                    _width:parent.width / 6
                    _height:30
                    _text:"Play"
                    onBtnClick: {
                        interpreterviewmodel.textEditString=textarea.text
                        interpreterviewmodel.play()
                    }
                }
                MButton{
                    _width:parent.width / 6
                    _height:30
                    _text:"Stop"
                    onBtnClick: {
                        interpreterviewmodel.stop()
                    }
                }

            }

            MFrame {
                id:textframe
                width: parent.width
                height:  parent.height - 40
                clip: true
                //padding: 20


                ScrollView {
                    width: parent.width - 5
                    height: parent.height
                    clip: true

                    Rectangle {
                        id: lineColumn
                        property int rowHeight: textarea.font.pixelSize + 3
                        color: "#f2f2f2"
                        width: 50
                        height: parent.height + textframe.height-5
                        Rectangle {
                            height: parent.height
                            anchors.right: parent.right
                            width: 1
                            color: "#ddd"
                        }
                        Column {
                            y:10 //-textarea.flickable.contentHeight + 4
                            width: parent.width
                            Repeater {
                                model: Math.max(
                                           textarea.lineCount +10  ,
                                           (lineColumn.height / lineColumn.rowHeight))
                                delegate: Text {
                                    id: text
                                    color: "#666"
                                    font: textarea.font
                                    width: lineColumn.width
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                    height: lineColumn.rowHeight
                                    renderType: Text.NativeRendering
                                    text: index
                                }
                            }

                        }
                    }
                        TextArea {
                            id: textarea
                            anchors.left: lineColumn.right
                            wrapMode: TextEdit.NoWrap
                            text: interpreterviewmodel.textEditString
                        }

                }


            }
        }
    }
}






/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
