#ifndef SCOORDINATESVIEWMODEL_H
#define SCOORDINATESVIEWMODEL_H

#include <QObject>
#include "../Controller/controller.h"

class scoordinatesviewmodel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString tempCreateFrameName READ getTempCreateFrameName)
    Q_PROPERTY(QString tempCreateFrameType READ getTempCreateFrameType)
    Q_PROPERTY(QString tempCreateFrameThreePointsStatus READ getTempCreateFrameThreePointsStatus)
    Q_PROPERTY(QString errorMassage READ getErrorMessage)
    Q_PROPERTY(bool isUpdateBtnClicked READ isUpdateBtnClicked)
public:
    explicit scoordinatesviewmodel(QObject *parent = nullptr);

Q_SIGNALS:
    void viewErrorPopup();
    void updateFrameDone();
public Q_SLOTS:
    void saveFrame(QString newName,QString frameType,QString frameMethod,QString x,QString y,QString z,QString a,QString b,QString c);
    void updateFrame(QString oldName,QString newName,QString frameType,QString frameMethod,QString x,QString y,QString z,QString a,QString b,QString c);
    void setUpdateOptionsStatus(bool value);
    bool removeBtn(QString frameName);
    //void writeListToFile();
    void setCurrentBtn(QString frameName,QString frameType);
    void point1Btn(QString frameName,QString frameType);
    void point2Btn();
    void point3Btn();
    void point1BtnUpdate(QString frameName);
    void point2BtnUpdate(QString frameName);
    void point3BtnUpdate(QString frameName);

    QList<double> calc_mainpoints(frame *frm);
    int getCurrentListIndex();
    void setCurrentListIndex(int val);
    int getSizeOfFrameList();
    void setLastFrameType(QString val);
    QString getLastFrameType();
   // void saveBtn(QString frameType,QString frameName,QString x,QString y,QString z,QString a,QString b,QString c,QString frameMethod,);

    QString getTempCreateFrameName();
    QString getTempCreateFrameType();
    QString getTempCreateFrameThreePointsStatus();
    QString getErrorMessage();
    bool isUpdateBtnClicked();



private:
    Controller *controller;
    QString _errorMessage;
};

#endif // SCOORDINATESVIEWMODEL_H

