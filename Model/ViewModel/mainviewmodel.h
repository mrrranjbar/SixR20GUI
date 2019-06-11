#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include "Model/Controller/controller.h"


#include <QObject>

class MainViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int Count READ Count WRITE setCount NOTIFY CountChanged)
public:
    static MainViewModel* instance;
    static MainViewModel* getInstance();
    explicit MainViewModel(QObject *parent = nullptr);
    void Initialize();


signals:
    void CountChanged();

public slots:
    void TestSlot();
    int Count();
    void setCount(int count);



private:
    int _count;
    Controller *controller;

};

#endif // MAINVIEWMODEL_H
