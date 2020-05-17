#ifndef SCOORDINATESVIEWMODEL_H
#define SCOORDINATESVIEWMODEL_H

#include <QObject>
#include "../Controller/controller.h"

class scoordinatesviewmodel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString tempCreateFrameName READ getTempCreateFrameName)
    Q_PROPERTY(QString tempCreateFrameType READ getTempCreateFrameType)
public:
    explicit scoordinatesviewmodel(QObject *parent = nullptr);

Q_SIGNALS:

public Q_SLOTS:
    void saveFrame(QString oldName,QString newName,QString frameType,QString frameMethod,QString x,QString y,QString z,QString a,QString b,QString c);
    void createBtn(QString frameType);
    bool removeBtn(QString frameName);
    void modifyBtn(QString frameName);
    //void writeListToFile();
    void writePointListFile();
    void setCurrentBtn(QString frameName,QString frameType);
    void point1Btn(QString frameName,QString frameType);
    void point2Btn();
    void point3Btn();

    QList<double> calc_mainpoints(frame *frm);
    int getCurrentListIndex();
    void setCurrentListIndex(int val);
    int getSizeOfFrameList();
    void setLastFrameType(QString val);
    QString getLastFrameType();
   // void saveBtn(QString frameType,QString frameName,QString x,QString y,QString z,QString a,QString b,QString c,QString frameMethod,);

    QString getTempCreateFrameName();
    QString getTempCreateFrameType();



private:
    Controller *controller;
};

#endif // SCOORDINATESVIEWMODEL_H

