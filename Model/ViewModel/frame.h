#ifndef FRAME_H
#define FRAME_H

#include <QObject>
#include "points.h"

class frame : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString frameIndex READ frameIndex WRITE setFrameIndex NOTIFY frameIndexChanged)
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(bool saved READ saved WRITE setSaved NOTIFY savedChanged)
    Q_PROPERTY(bool iscurrent READ iscurrent WRITE setIscurrent NOTIFY iscurrentChanged)
    Q_PROPERTY(QList<double> mainPoints READ mainPoints WRITE setMainPoints NOTIFY mainPointsChanged)
    Q_PROPERTY(QString threePointsStatus READ threePointsStatus WRITE setThreePointsStatus NOTIFY threePointsStatusChanged)
    Q_PROPERTY(QString method READ method WRITE setMethod NOTIFY methodChanged)
    Q_PROPERTY(QList<double> p1Point READ p1Point WRITE setP1Point)
    Q_PROPERTY(QList<double> p2Point READ p2Point WRITE setP2Point)
    Q_PROPERTY(QList<double> p3Point READ p3Point WRITE setP3Point)

public:
    explicit frame(QObject *parent = nullptr);
    frame(QString index,QString frameType,QString frameName,QString correspondingFrameName,bool savedStatus,bool iscurrentStatus,QList<double> mainPoints,QString threePointsStatus,QList<double> p1points,QString p1framename,QList<double> p2points,QString p2framename,QList<double> p3points,QString p3framename,QString method, QObject *parent=0);

Q_SIGNALS:
    void frameIndexChanged();
    void typeChanged();
    void nameChanged();
    void savedChanged();
    void iscurrentChanged();
    void mainPointsChanged();
    void threePointsStatusChanged();
    void methodChanged();
    void frameNameChanged();
    void frameTypeChanged();

public Q_SLOTS:
    QString frameIndex();
    void setFrameIndex(QString value);
    QString type();
    void setType(QString value);
    QString name();
    void setName(QString value);
    bool saved();
    void setSaved(bool value);
    bool iscurrent();
    void setIscurrent(bool value);
    QList<double> mainPoints();
    void setMainPoints(QList<double> values);
    QString threePointsStatus();
    void setThreePointsStatus(QString value);
    QString method();
    void setMethod(QString value);

    QList<double> p1Point();
    void setP1Point(QList<double> values);
    QString p1frameName();
    void setP1frameName(QString value);
    QList<double> p2Point();
    void setP2Point(QList<double> values);
    QString p2frameName();
    void setP2frameName(QString value);
    QList<double> p3Point();
    void setP3Point(QList<double> values);
    QString p3frameName();
    void setP3frameName(QString value);
    QString correspondingFrameName();
    void setCorrespondingFrameName(QString value);


private:
    QString _frameIndex;
    QString _type;
    QString _name;
    QString _corresponding_frame_name;
    bool _saved;
    bool _iscurrent;
    QList<double> _mainPoint;
    QString _threePointsStatus;
    QList<double> _p1Point;
    QString _p1frameName;
    QList<double> _p2Point;
    QString _p2frameName;
    QList<double> _p3Point;
    QString _p3frameName;
    QString _method;
};

#endif // FRAME_H
