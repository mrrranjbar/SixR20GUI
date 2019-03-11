import QtQuick 2.4
import QtQuick.Controls 2.2
import InterpreterViewModel 1.0

Item {
    property int _width: 260
    property int _height: 75
    InterpreterViewModel {
        id: interpreterviewmodel
    }
   Grid{
       width: parent.width
       height: parent.height

       MFrame{
           width:  parent.width
           height: parent.height
            Grid{
                columns: 3
                rows: 2
                spacing:5

                MButton{
                    _width:100
                    _height:30
                    _text:"Play"
                    onBtnClick: {
                        interpreterviewmodel.textEditString=txe_interpreter.text
                        interpreterviewmodel.play()
                    }
                }
                MButton{

                    _width:100
                    _height:30
                    _text:"Pause"
                    onBtnClick: {
                        interpreterviewmodel.pause()
                }

                }
                CheckBox{
                    text: "Chrcked"

                }
                TextEdit{
                    id:txe_interpreter
                    height:100
                    width:100


                }

            }










   }
}
}










/*##^## Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
 ##^##*/
