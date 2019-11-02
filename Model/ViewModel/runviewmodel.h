#ifndef RUNVIEWMODEL_H
#define RUNVIEWMODEL_H

#include <QObject>

class runviewmodel : public QObject
{
    Q_OBJECT
public:
    explicit runviewmodel(QObject *parent = nullptr);

Q_SIGNALS:

public Q_SLOTS:
};

#endif // RUNVIEWMODEL_H