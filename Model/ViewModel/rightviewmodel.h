#ifndef RIGHTVIEWMODEL_H
#define RIGHTVIEWMODEL_H

#include <QObject>
#include "Model/Controller/controller.h"

class RightViewModel : public QObject
{
    Q_OBJECT
     Q_PROPERTY(QList<int> StatusWord READ StatusWord WRITE setStatusWord NOTIFY StatusWordChanged)
public:
    explicit RightViewModel(QObject *parent = nullptr);

signals:
    void StatusWordChanged();

public slots:
    QList<int> StatusWord();
    void setStatusWord(QList<int> value);
    void UpdateStatusWord();

private:
    QList<int> *_statusWord;
    Controller *controller;
};


#endif // RIGHTVIEWMODEL_H
