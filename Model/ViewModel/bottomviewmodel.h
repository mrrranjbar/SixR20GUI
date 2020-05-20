#ifndef BOTTOMVIEWMODEL_H
#define BOTTOMVIEWMODEL_H

#include <QObject>
#include "alarm.h"
#include "Model/Controller/controller.h"

class BottomViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString labelText READ labelText() WRITE setLabelText() NOTIFY labelTextChanged)
    Q_PROPERTY(QString labelColor READ labelColor() WRITE setLabelColor() NOTIFY labelColorChanged)

public:

    explicit BottomViewModel(QObject *parent = nullptr);
    void setLabelText(QString a);
    void setLabelColor(QString a);
    QString labelColor();
    QString labelText();
    QString LastLabelText;
    QString LastLabelColor;



Q_SIGNALS:

    void labelTextChanged();
    void labelColorChanged();

public slots:

    void showDetails();
    void clearAll();
    void ChangeAlarmState();
    void ChangeMovementStopDetected();


private:
    Controller *controller;
    QString _labelText;
    QString _labelColor;
};

#endif // BOTTOMVIEWMODEL_H
