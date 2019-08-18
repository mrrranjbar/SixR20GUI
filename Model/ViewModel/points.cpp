#include "points.h"

points::points(QObject *parent) : QObject(parent)
{
}

points::points(const QString &name, QObject *parent)
    : QObject(parent), m_name(name)
{
}

points::points(const QString &name, QList<double> points, QObject *parent)
    : QObject(parent),_points(points) ,m_name(name)
{
}

points::points(const QString &name, const int &saved, QObject *parent)
    : QObject(parent),m_saved(saved) ,m_name(name)
{
}

points::points(const QString &name, const int &saved, QList<double> points, QObject *parent)
    : QObject(parent),_points(points),m_saved(saved) ,m_name(name)
{
}

points::points(const int &saved, QList<double> points, QObject *parent)
    : QObject(parent),_points(points),m_saved(saved)
{
}

points::points(const QString &name, const QString &type, QList<double> points, const QString &stringFrameType, const QString &stringFrameName, const int myIndexInList, QObject *parent)
    : QObject(parent),myIndexInList(myIndexInList), m_stringFrameName(stringFrameName),m_stringFrameType(stringFrameType),_points(points),  m_type(type),  m_name(name)
{
}

QString points::getName() const
{
    return m_name;
}

void points::setName(const QString &name)
{
    if (name != m_name) {
        m_name = name;
        nameChanged();
    }
}

QList<double> points::getPoints()
{
    return _points;
}

void points::setPoints(QList<double> &points)
{
    _points = points;
    pointsChanged();
}

int points::getSaved()
{
    return m_saved;
}

void points::setSaved(const int &saved)
{
    m_saved = saved;
    savedChanged();
}

int points::getUpdated()
{
    return m_updated;
}

void points::setUpdated(const int &updated)
{
    m_updated = updated;
    updatedChanged();
}

int points::getDuplicated()
{
    return m_duplicate;
}

void points::setDuplicated(const int &dup)
{
    m_duplicate = dup;
    duplicatedChanged();
}

int points::getCreated()
{
    return m_created;
}

void points::setCreated(const int &created)
{
    m_created = created;
}

QString points::getType()
{
    return m_type;
}

void points::setType(const QString &type)
{
    m_type = type;
    typeChanged();
}

QString points::getStringFrameName()
{
    return m_stringFrameName;
}

void points::setStringFrameName(const QString &stringFrameName)
{
    m_stringFrameName = stringFrameName;
    stringFrameNameChanged();
}

QString points::getStringFrameType()
{
    return m_stringFrameType;
}

void points::setStringFrameType(const QString &stringFrameType)
{
    m_stringFrameType = stringFrameType;
    stringFrameTypeChanged();
}

void points::edit()
{
}

