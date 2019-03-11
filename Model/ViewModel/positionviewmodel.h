#ifndef POSITIONVIEWMODEL_H
#define POSITIONVIEWMODEL_H

#include "Model/Controller/controller.h"
#include <QObject>

class PositionViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QString> Positions READ Positions)
public:
    explicit PositionViewModel(QObject *parent = nullptr);

signals:

public slots:
    void Move(int index);
    void MoveAll();
    void GoHome();
    QList<QString> Positions();

private:
     QList<QString> *_positions;
    Controller *controller;
};

#endif // POSITIONVIEWMODEL_H
