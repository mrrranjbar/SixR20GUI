#ifndef TEACHPOINTVIEWMODEL_H
#define TEACHPOINTVIEWMODEL_H


#include <QObject>
#include "../Controller/controller.h"
#include "points.h"
#include "math.h"

class teachpointviewmodel :public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString tempName READ getTempName WRITE setTempName NOTIFY tempNameChanged)
    Q_PROPERTY(QString errorMassage READ getErrorMessage)
    Q_PROPERTY(QList <double> tempPoints READ getTempPoints WRITE setTempPoints NOTIFY TempPointsChanged)
//    Q_PROPERTY(QString showFilePopup READ getTempName WRITE setTempName NOTIFY tempNameChanged)
public:
    teachpointviewmodel(QObject *parent=nullptr);
    QString generateNewPointNumber();
    //    double* getActualPositions();

Q_SIGNALS:
    void tempNameChanged();
    void TempPointsChanged();
    void openPopUp(QVariant exceptionMsg);
    void viewErrorPopup();

public Q_SLOTS:

    QString getTempName();
    QString getErrorMessage();
    void setTempName(QString str);

    QList <double> getTempPoints();
    void setTempPoints(QList <double> points);

    void editList(int index,QString name);
    void saveBtn(bool isJoint);
    void deleteBtn(int index);
    void updateNameBtn(int index);
    void updatePositionBtn(int index,bool isJoint);
    void updateBtn(int index);
    void goToBtn(int index);
    void getSelectedCombo(int listIndex,QString itemName);
    QString getPointName(int index);
    QString savedAndUpdatedString(int index);
    void setPointCoordinate(int index);
    QList<double> calc_mainpoints();

    void writePointListFile();



private:
    Controller *controller;
    QString _tempName;
    QString _errorMessage;
    int _newPointNumber;
    QString newPointName = "POINT";
    QList <double> _tempPoints;



};

#endif // TEACHPOINTVIEWMODEL_H
