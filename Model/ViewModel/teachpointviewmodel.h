#ifndef TEACHPOINTVIEWMODEL_H
#define TEACHPOINTVIEWMODEL_H

#include <QObject>
#include "../Controller/controller.h"
#include "points.h"

class teachpointviewmodel :public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString tempName READ getTempName WRITE setTempName NOTIFY tempNameChanged)
    Q_PROPERTY(QList <double> tempPoints READ getTempPoints WRITE setTempPoints NOTIFY TempPointsChanged)

public:
    teachpointviewmodel(QObject *parent=nullptr);
    QString generateNewPointNumber();
    //    double* getActualPositions();

signals:
    void tempNameChanged();
    void TempPointsChanged();

public slots:

    QString getTempName();
    void setTempName(QString str);

    QList <double> getTempPoints();
    void setTempPoints(QList <double> points);

    void editList(int index,QString name);
    void saveBtn(int listIndex,bool fromDeleteBtn);
    void createBtn();
    void deleteBtn(int index);
    void updateBtn(int index);

    QString getPointName(int index);
    void radioBtnClicked(int index,QString value);
    QString savedAndUpdatedString(int index);
    void setPointCoordinate(int index);

private:
    Controller *controller;
    QString _tempName;
    int _newPointNumber;
    QString newPointName = "POINT ";
    QList <double> _tempPoints;
};

#endif // TEACHPOINTVIEWMODEL_H
