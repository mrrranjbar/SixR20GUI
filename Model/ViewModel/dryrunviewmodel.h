#ifndef DRYRUNVIEWMODEL_H
#define DRYRUNVIEWMODEL_H

#include <QObject>

class dryrunviewmodel : public QObject
{
    Q_OBJECT
public:
    explicit dryrunviewmodel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // DRYRUNVIEWMODEL_H