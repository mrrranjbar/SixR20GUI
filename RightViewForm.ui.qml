import QtQuick 2.4
import QtQuick.Controls 2.2
import MainViewModel 1.0
import RightViewModel 1.0


Item {

    Timer{
           interval: 20; running: true; repeat: true
           onTriggered: {
//               rightviewmodel.UpdateStatusWord()
               rightviewmodel.UpdateActualPosition()
           }
    }

    MFrame{
        anchors.fill: parent
        Label{
//            text: "StatusWord1: " + rightviewmodel.StatusWord[0] +"\n" +
//             "StatusWord2: " + rightviewmodel.StatusWord[1] +"\n" +
//            "StatusWord3: " + rightviewmodel.StatusWord[2] +"\n" +
//            "StatusWord4: " + rightviewmodel.StatusWord[3] +"\n" +
//            "StatusWord5: " + rightviewmodel.StatusWord[4] +"\n" +
//            "StatusWord6: " + rightviewmodel.StatusWord[5] +"\n"
            text:"ActualPosition1: " + rightviewmodel.ActualPosition[0].toFixed(3) +"\n" +
            "ActualPosition2: " + rightviewmodel.ActualPosition[1].toFixed(3) +"\n" +
            "ActualPosition3: " + rightviewmodel.ActualPosition[2].toFixed(3) +"\n" +
            "ActualPosition4: " + rightviewmodel.ActualPosition[3].toFixed(3) +"\n" +
            "ActualPosition5: " + rightviewmodel.ActualPosition[4].toFixed(3) +"\n" +
            "ActualPosition6: " + rightviewmodel.ActualPosition[5].toFixed(3) +"\n"
        }
    }

    RightViewModel{
        id:rightviewmodel
    }
}
