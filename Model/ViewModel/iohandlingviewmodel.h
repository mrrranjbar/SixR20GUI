#ifndef IOHANDLINGVIEWMODEL_H
#define IOHANDLINGVIEWMODEL_H

#include <QObject>
#include "Model/Controller/controller.h"


class iohandlingviewmodel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<bool> IoOutput READ IoOutput WRITE setOutput NOTIFY IoChanged)

public:
    explicit iohandlingviewmodel(QObject *parent = nullptr);

Q_SIGNALS:
    void IoChanged();

public Q_SLOTS:
    QList<bool> IoOutput();
    void setOutputAtIndex(bool value,int index);
    void setOutput(QList<bool> value);
    void updateIO();


private:
    Controller *controller;
    QList<bool> *_ioOutput;

};

#endif // IOHANDLINGVIEWMODEL_H

