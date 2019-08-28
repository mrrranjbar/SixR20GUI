import QtQuick 2.4
import QtQuick.Controls 2.2
import MainViewModel 1.0
import RightViewModel 1.0


Item {

    Timer{
           interval: 20; running: true; repeat: true
           onTriggered: {
               //rightviewmodel.UpdateStatusWord()
               rightviewmodel.UpdateActualPosition()
           }
    }

    MFrame{
        anchors.fill: parent
        Label{
            text:
            "S1: " + rightviewmodel.StatusWord[0] +"\n" +
            "S2: " + rightviewmodel.StatusWord[1] +"\n" +
            "S3: " + rightviewmodel.StatusWord[2] +"\n" +
            "S4: " + rightviewmodel.StatusWord[3] +"\n" +
            "S5: " + rightviewmodel.StatusWord[4] +"\n" +
            "S6: " + rightviewmodel.StatusWord[5] +"\n" +
            "POS1: " + rightviewmodel.ActualPosition[0].toFixed(3) +"\n" +
            "POS2: " + rightviewmodel.ActualPosition[1].toFixed(3) +"\n" +
            "POS3: " + rightviewmodel.ActualPosition[2].toFixed(3) +"\n" +
            "POS4: " + rightviewmodel.ActualPosition[3].toFixed(3) +"\n" +
            "POS5: " + rightviewmodel.ActualPosition[4].toFixed(3) +"\n" +
            "POS6: " + rightviewmodel.ActualPosition[5].toFixed(3) +"\n"
        }
    }

    RightViewModel{
        id:rightviewmodel
    }
}
