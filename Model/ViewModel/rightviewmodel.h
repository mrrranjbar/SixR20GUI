#ifndef RIGHTVIEWMODEL_H
#define RIGHTVIEWMODEL_H

#include <QObject>
#include "Model/Controller/controller.h"

class RightViewModel : public QObject
{
    Q_OBJECT
     Q_PROPERTY(QList<int> StatusWord READ StatusWord WRITE setStatusWord NOTIFY StatusWordChanged)
    Q_PROPERTY(QList<double> ActualPosition READ ActualPosition WRITE setActualPosition NOTIFY ActualPositionChanged)
public:
    explicit RightViewModel(QObject *parent = nullptr);

signals:
    void StatusWordChanged();
    void ActualPositionChanged();

public slots:
    QList<int> StatusWord();
    QList<double> ActualPosition();
    void setStatusWord(QList<int> value);
    void UpdateStatusWord();
    void setActualPosition(QList<double> value);
    void UpdateActualPosition();

private:
    QList<int> *_statusWord;
    QList<double> *_actualPosition;
    Controller *controller;
};


#endif // RIGHTVIEWMODEL_H
