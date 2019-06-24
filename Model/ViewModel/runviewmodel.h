#ifndef RUNVIEWMODEL_H
#define RUNVIEWMODEL_H

#include <QObject>

class runviewmodel : public QObject
{
    Q_OBJECT
public:
    explicit runviewmodel(QObject *parent = nullptr);

signals:

public slots:
};

#endif // RUNVIEWMODEL_H