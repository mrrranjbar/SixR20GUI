import QtQuick 2.12
import QtQuick.Controls 2.12
import MainViewModel 1.0


Item {
    Resource
    {
        id:rsc
    }

//    Rectangle {
//        width: 200
//        height: 200
//        id:rtc1
//        anchors.fill: parent
        //color: "blue"
//        MButton
//        {
//            _text : "test"
//            onMyClick: {
//                mainview1.TestSlot()
//            }
//        }
//        MCheckbox{

//        }
//        MComboBox
//        {

//        }

//    }
    MFrame{
        anchors.fill: parent
        Label{
            text: "test"
        }
//        ListView {
//            width: 100; height: 100

//            model: TeachPointModel
//            delegate: Rectangle {
//                height: 25
//                width: 100
//                color: model.modelData.color
//                Text { text: name }
//            }
//        }

    }
    MainViewModel {
        id: mainview1
    }

}

