#ifndef IOMONITORINGVIEWMODEL_H
#define IOMONITORINGVIEWMODEL_H

#include <QObject>

class iomonitoringviewmodel : public QObject
{
    Q_OBJECT
public:
    explicit iomonitoringviewmodel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // IOMONITORINGVIEWMODEL_H