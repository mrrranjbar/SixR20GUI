#ifndef TEACHPOINTVIEWMODEL_H
#define TEACHPOINTVIEWMODEL_H
#define degreesToRadians(angleDegrees) (angleDegrees * M_PI / 180.0)
#define radiansToDegrees(angleRadians) (angleRadians * 180.0 / M_PI)

#include <QObject>
#include "../Controller/controller.h"
#include "points.h"
#include "math.h"

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
    void cartesianRadioBtnClicked(int index);
    QString savedAndUpdatedString(int index);
    void setPointCoordinate(int index);

    void GetCartPos(double theta[6], double ToolParams[], double out[]);
    void DQmultiply(double Q1[], double Q2[], double out[]);
    void toEulerianAngle(double quar[], double output[]);
    
private:
    Controller *controller;
    QString _tempName;
    int _newPointNumber;
    QString newPointName = "POINT ";
    QList <double> _tempPoints;

    const double L[6] = { 389.5, 0 , 600, 200, 685.5, 135 };
    double QEndEffector[8] = { 1, 0,0,0,0 , L[5], 0 ,0 };//QT
    double Qbase[8] = { 1,0,0,0,0,0,0,0 };
    double toolParam[8] = { 1,0,0,0,0,0,0,0 };
    double DriveEncoderRes = 524287;
    double PulsToDegFactor1[6] = { 360.0 / DriveEncoderRes, 360.0 / DriveEncoderRes, (-1.0 * 360.0) / DriveEncoderRes, 360.0 / DriveEncoderRes, 360.0 / DriveEncoderRes , (-1.0 * 360.0) / DriveEncoderRes };

};

#endif // TEACHPOINTVIEWMODEL_H
