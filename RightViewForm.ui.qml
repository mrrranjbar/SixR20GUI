import QtQuick 2.4
import QtQuick.Controls 2.2
import MainViewModel 1.0
import RightViewModel 1.0


Item {

    Timer{
           interval: 500; running: true; repeat: true
           onTriggered: rightviewmodel.UpdateStatusWord()
    }

    MFrame{
        anchors.fill: parent
        Label{
            text: "StatusWord1: " + rightviewmodel.StatusWord[0] +"\n" +
             "StatusWord2: " + rightviewmodel.StatusWord[1] +"\n" +
            "StatusWord3: " + rightviewmodel.StatusWord[2] +"\n" +
            "StatusWord4: " + rightviewmodel.StatusWord[3] +"\n" +
            "StatusWord5: " + rightviewmodel.StatusWord[4] +"\n" +
            "StatusWord6: " + rightviewmodel.StatusWord[5] +"\n"
        }
    }

    RightViewModel{
        id:rightviewmodel
    }
}
