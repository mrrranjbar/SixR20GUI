#ifndef DRYRUNVIEWMODEL_H
#define DRYRUNVIEWMODEL_H

#include <QObject>

class dryrunviewmodel : public QObject
{
    Q_OBJECT
public:
    explicit dryrunviewmodel(QObject *parent = nullptr);

Q_SIGNALS:

public Q_SLOTS:
};

#endif // DRYRUNVIEWMODEL_H