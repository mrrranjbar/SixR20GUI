#ifndef BREAKVIEWMODEL_H
#define BREAKVIEWMODEL_H

#include <QObject>

class breakviewmodel : public QObject
{
    Q_OBJECT
public:
    explicit breakviewmodel(QObject *parent = nullptr);

signals:


public Q_SLOTS:
    void setBreakAtIndex(bool value,int index);

public slots:
};

#endif // BREAKVIEWMODEL_H
