#include "frame.h"

frame::frame(QObject *parent) : QObject(parent)
{

}

//*****************************************************
//*****************************************************

frame::frame(QString index,QString frameType, QString frameName,QString correspondingFrameName,bool savedStatus,bool iscurrentStatus, QList<double> mainPoints,QString threePointsStatus, QList<double> p1points,QString p1framename,QList<double> p2points,QString p2framename,QList<double> p3points,QString p3framename, QString method, QObject *parent)
    : QObject(parent)
{
    _frameIndex=index;
    _type=frameType;
    _name=frameName;
    _corresponding_frame_name=correspondingFrameName;
    _saved=savedStatus;
    _iscurrent=iscurrentStatus;
    _mainPoint=mainPoints;
    _threePointsStatus=threePointsStatus;
    _p1Point=p1points;
    _p1frameName=p1framename;
    _p2Point=p2points;
    _p2frameName=p2framename;
    _p3Point=p3points;
    _p3frameName=p3framename;
    _method=method;

}

//*****************************************************
//*****************************************************

QString frame::frameIndex()
{
    return _frameIndex;
}

//*****************************************************
//*****************************************************

void frame::setFrameIndex(QString value)
{
    _frameIndex=value;
}

//*****************************************************
//*****************************************************

QString frame::type()
{
    return _type;
}

//*****************************************************
//*****************************************************

void frame::setType(QString value)
{
    _type=value;
}

//*****************************************************
//*****************************************************

QString frame::name()
{
    return _name;
}

//*****************************************************
//*****************************************************

void frame::setName(QString value)
{
    _name=value;
}


//*****************************************************
//*****************************************************

bool frame::saved()
{
    return _saved;
}


//*****************************************************
//*****************************************************

void frame::setSaved(bool value)
{
    _saved=value;
}

//*****************************************************
//*****************************************************

bool frame::iscurrent()
{
    return _iscurrent;
}

//*****************************************************
//*****************************************************

void frame::setIscurrent(bool value)
{
    _iscurrent=value;
}

//*****************************************************
//*****************************************************

QList<double> frame::mainPoints()
{
    return _mainPoint;
}

//*****************************************************
//*****************************************************

void frame::setMainPoints(QList<double> values)
{
    _mainPoint=values;
}

//*****************************************************
//*****************************************************


QString frame::threePointsStatus()
{
    return _threePointsStatus;
}


//*****************************************************
//*****************************************************


void frame::setThreePointsStatus(QString value)
{
    _threePointsStatus=value;
}


//*****************************************************
//*****************************************************

QString frame::method()
{
    return _method;
}


//*****************************************************
//*****************************************************

void frame::setMethod(QString value)
{
    _method=value;
}

//*****************************************************
//*****************************************************

QList<double> frame::p1Point()
{
    return _p1Point;
}

//*****************************************************
//*****************************************************

void frame::setP1Point(QList<double> values)
{
    _p1Point=values;
}

//*****************************************************
//*****************************************************

QString frame::p1frameName()
{
    return _p1frameName;
}

//*****************************************************
//*****************************************************

void frame::setP1frameName(QString value)
{
    _p1frameName=value;
}

//*****************************************************
//*****************************************************

QList<double> frame::p2Point()
{
    return _p2Point;
}

//*****************************************************
//*****************************************************

void frame::setP2Point(QList<double> values)
{
    _p2Point=values;
}

//*****************************************************
//*****************************************************

QString frame::p2frameName()
{
    return _p2frameName;
}

//*****************************************************
//*****************************************************

void frame::setP2frameName(QString value)
{
    _p2frameName=value;
}

//*****************************************************
//*****************************************************

QList<double> frame::p3Point()
{
    return _p3Point;
}

//*****************************************************
//*****************************************************

void frame::setP3Point(QList<double> values)
{
    _p3Point=values;
}

//*****************************************************
//*****************************************************

QString frame::p3frameName()
{
    return _p3frameName;
}

//*****************************************************
//*****************************************************

void frame::setP3frameName(QString value)
{
    _p3frameName=value;
}

QString frame::correspondingFrameName()
{
    return _corresponding_frame_name;
}

void frame::setCorrespondingFrameName(QString value)
{
    _corresponding_frame_name=value;
}

//*****************************************************
//*****************************************************
