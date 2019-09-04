#include "bottomviewmodel.h"
#include <QGuiApplication>
#include <QQuickView>
#include "alarm.h"

BottomViewModel::BottomViewModel(QObject *parent) : QObject(parent)
{
    controller = Controller::getInstance();
    connect(controller->beckhoff, SIGNAL(AlarmDetected()),this, SLOT(ChangeAlarmState()));
//    ChangeAlarmState();
}
void BottomViewModel::showDetails()
{


}

void BottomViewModel::clearAll()
{

    controller->beckhoff->setGUIManager(99);
    controller->alarmList.clear();
    controller->AlarmDetection();

}

void BottomViewModel::ChangeAlarmState(){
    QList<QObject*> alarmList = controller->alarmList;
    int state = -1;
    if(alarmList.size()>0)state = 0;

    if(state == 0){
        setLabelColor("#E74C3C");
        setLabelText("Error");
    }else{
        setLabelText("No Alarm");
        setLabelColor("#17a81a");
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

