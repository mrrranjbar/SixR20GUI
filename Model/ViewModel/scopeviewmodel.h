#ifndef SCOPEVIEWMODEL_H
#define SCOPEVIEWMODEL_H

#include <QObject>

class scopeviewmodel : public QObject
{
    Q_OBJECT
public:
    explicit scopeviewmodel(QObject *parent = nullptr);

Q_SIGNALS:

public Q_SLOTS:
};

#endif // SCOPEVIEWMODEL_H