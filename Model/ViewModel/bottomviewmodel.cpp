#include "bottomviewmodel.h"
#include <QGuiApplication>
#include <QQuickView>
#include "alarm.h"

BottomViewModel::BottomViewModel(QObject *parent) : QObject(parent)
{
    controller = Controller::getInstance();
    connect(controller->beckhoff, SIGNAL(AlarmDetected()),this, SLOT(ChangeAlarmState()));
    connect(controller->beckhoff, SIGNAL(MovementStopDetected()),this, SLOT(ChangeMovementStopDetected()));
    //    ChangeAlarmState();
}
void BottomViewModel::showDetails()
{


}

void BottomViewModel::clearAll()
{
    controller->beckhoff->doNextLine=true;
    controller->beckhoff->stopAnltrRun=true;
    controller->beckhoff->setGUIManager(99);
    while(controller->beckhoff->getGUIManager()!=100);
    controller->beckhoff->setGUIManager(4);
    setLabelText("ROBOT IS READY!");
    setLabelColor("#17a81a");
    controller->alarmList.clear();

    if(controller->beckhoff->MovementStop == 1)
    {
        controller->IsClearMovementStop = true;
//        setLabelText(LastLabelText);
//        setLabelColor(LastLabelColor);
    }
//    else{
//        setLabelText("ROBOT IS READY!");
//        setLabelColor("#17a81a");
//    }
}

void BottomViewModel::ChangeAlarmState(){
    QList<QObject*> alarmList = controller->alarmList;
    int state = -1;
    if(alarmList.size()>0)state = 0;

    if(state == 0){
        setLabelText("ROBOT HAS ALARM!");
        setLabelColor("#E74C3C");
    }else{
        if(controller->GeneralRobotStatus() == "NOT READY"){
            setLabelText("EMERGENCY IS ON OR POWER IS OFF. ROBOT IS NOT READY!");
            setLabelColor("#e0c31e");
        }
        else if(controller->GeneralRobotStatus() == "RUN")
        {
            setLabelText("ROBOT IS RUN!");
            setLabelColor("#17a81a");
        }
        else if(controller->GeneralRobotStatus() == "READY")
        {
            setLabelText("ROBOT IS READY!");
            setLabelColor("#17a81a");
        }
        else{
            setLabelText("ROBOT IS NOT READY!");
            setLabelColor("#e0c31e");
        }

    }

}

void BottomViewModel::ChangeMovementStopDetected()
{
    if(controller->beckhoff->MovementStop == 1 && !controller->IsMovementStop)
    {
        LastLabelText = labelText();
        LastLabelColor = labelColor();
        setLabelText("TARGET IS NOT REACHABLE");
        setLabelColor("#E74C3C");
        controller->IsMovementStop = false;
    }
    if(controller->IsClearMovementStop)
    {
        setLabelText(LastLabelText);
        setLabelColor(LastLabelColor);
        controller->IsClearMovementStop = false;
        controller->IsMovementStop = true;
    }
}
void BottomViewModel::setLabelText(QString a) {
    _labelText = a;
    emit labelTextChanged();
}
void BottomViewModel::setLabelColor(QString a) {
    _labelColor = a;
    emit labelColorChanged();
}
QString BottomViewModel::labelColor() {
    return _labelColor;
}
QString BottomViewModel::labelText() {
    return _labelText;
}

