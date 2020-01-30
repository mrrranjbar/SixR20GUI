#ifndef SCOORDINATESVIEWMODEL_H
#define SCOORDINATESVIEWMODEL_H

#include <QObject>
#include "../Controller/controller.h"

class scoordinatesviewmodel : public QObject
{
    Q_OBJECT
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
    void point1Btn(QString frameName);
    void point2Btn(QString frameName);
    void point3Btn(QString frameName);

    QList<double> calc_mainpoints(frame *frm);
    int getCurrentListIndex();
    void setCurrentListIndex(int val);
    int getSizeOfFrameList();
    void setLastFrameType(QString val);
    QString getLastFrameType();
   // void saveBtn(QString frameType,QString frameName,QString x,QString y,QString z,QString a,QString b,QString c,QString frameMethod,);



private:
    Controller *controller;
};

#endif // SCOORDINATESVIEWMODEL_H

