#ifndef SCOORDINATESVIEWMODEL_H
#define SCOORDINATESVIEWMODEL_H

#include <QObject>
#include "../Controller/controller.h"

class scoordinatesviewmodel : public QObject
{
    Q_OBJECT
public:
    explicit scoordinatesviewmodel(QObject *parent = nullptr);

signals:

public slots:
    void saveFrame(QString oldName,QString newName,QString frameType,QString frameMethod,QString teachedFrameType,QString x,QString y,QString z,QString a,QString b,QString c);
    void createBtn();
    void removeBtn(QString frameName);
    void modifyBtn(QString frameName);
    void writeListToFile();
    void writePointListFile();
    void setCurrentBtn(QString frameName,QString frameType);
    void point1Btn(QString frameName);
    void point2Btn(QString frameName);
    void point3Btn(QString frameName);

private:
    Controller *controller;
};

#endif // SCOORDINATESVIEWMODEL_H

