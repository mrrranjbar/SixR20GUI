#ifndef POINTS_H
#define POINTS_H

#include <QObject>
#include <QStringList>
#include <QList>
//#include <QVariant>
//#include <QVariantList>

class points : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString stringFrameType READ getStringFrameType WRITE setStringFrameType NOTIFY stringFrameTypeChanged)
    Q_PROPERTY(QString stringFrameName READ getStringFrameName WRITE setStringFrameName NOTIFY stringFrameNameChanged)
    Q_PROPERTY(QString type READ getType WRITE setType NOTIFY typeChanged)
    Q_PROPERTY(QList <double> points READ getPoints WRITE setPoints NOTIFY pointsChanged)
    Q_PROPERTY(int saved READ getSaved WRITE setSaved NOTIFY savedChanged)
    Q_PROPERTY(int updated READ getUpdated WRITE setUpdated NOTIFY updatedChanged)
    Q_PROPERTY(int duplicated READ getDuplicated WRITE setDuplicated NOTIFY duplicatedChanged)

public:
    points(QObject *parent=0);
    points (const QString &name, QObject *parent=0);
    points (const QString &name,  QList<double> points, QObject *parent=0);
    points (const QString &name, const int &saved , QObject *parent=0);
    points (const QString &name, const int &saved , QList<double> points, QObject *parent=0);
    points (const int &saved , QList<double> points, QObject *parent=0);
    points (const QString &name,const QString &type,QList<double> points,const QString &stringFrameType,const QString &stringFrameName, const int myIndexInList,QObject *parent=0);

    QString getName() const;
    void setName(const QString &name);

    QList <double> getPoints();
    void setPoints(QList<double> &points);

    int getSaved();
    void setSaved(const int &saved);

    int getUpdated();
    void setUpdated(const int &updated);

    int getDuplicated();
    void setDuplicated(const int &dup);

    int getCreated();
    void setCreated(const int &created);

    QString getType();
    void setType(const QString &type);

    QString getStringFrameName();
    void setStringFrameName(const QString &stringFrameName);

    QString getStringFrameType();
    void setStringFrameType(const QString &stringFrameType);

    void edit();
    int myIndexInList = 0;

Q_SIGNALS:
    void nameChanged();
    void pointsChanged();
    void savedChanged();
    void updatedChanged();
    void stringFrameNameChanged();
    void stringFrameTypeChanged();
    void typeChanged();
    void duplicatedChanged();

private:
    QList <double> _points;
    int m_saved = false;
    int m_updated = false;
    int m_created = false;
    int m_duplicate = false;
    QString m_name;
    QString m_type;
    QString m_stringFrameType;
    QString m_stringFrameName;

};

#endif // POINTS_H
