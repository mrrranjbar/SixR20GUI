#ifndef SCOORDINATESVIEWMODEL_H
#define SCOORDINATESVIEWMODEL_H

#include <QObject>

class scoordinatesviewmodel : public QObject
{
    Q_OBJECT
public:
    explicit scoordinatesviewmodel(QObject *parent = nullptr);

signals:

public slots:
    void saveFrame(int id,QString name,QString x,QString y,QString z,QString a,QString b,QString c);
    void readFrame();
};

#endif // SCOORDINATESVIEWMODEL_H
