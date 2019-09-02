#ifndef IOMONITORINGVIEWMODEL_H
#define IOMONITORINGVIEWMODEL_H

#include <QObject>
#include "Model/Controller/controller.h"

class iomonitoringviewmodel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<bool> IoInput READ IoInput WRITE setIoInput NOTIFY IoChanged)
    Q_PROPERTY(QList<bool> IoOutput READ IoOutput WRITE setOutput NOTIFY IoChanged)
    //WRITE setStatusWord NOTIFY StatusWordChanged

public:
    explicit iomonitoringviewmodel(QObject *parent = nullptr);

Q_SIGNALS:
    void IoChanged();

public Q_SLOTS:
    QList<bool> IoInput();
    void setIoInput(QList<bool> value);
    QList<bool> IoOutput();
    void setOutput(QList<bool> value);
    void updateIO();


private:
    Controller *controller;
    QList<bool> *_ioInput;
    QList<bool> *_ioOutput;
};

#endif // IOMONITORINGVIEWMODEL_H

