#ifndef MAINVIEWMODEL_H
#define MAINVIEWMODEL_H

#include "Model/Controller/controller.h"
#include "Model/Controller/readinfo.h"


#include <QObject>

class MainViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int Count READ Count WRITE setCount NOTIFY CountChanged)
    Q_PROPERTY(bool IsPowerOn READ IsPowerOn WRITE setIsPowerOn NOTIFY IsPowerOnChanged)
public:
    static MainViewModel* instance;
    static MainViewModel* getInstance();
    explicit MainViewModel(QObject *parent = nullptr);
    void Initialize();


Q_SIGNALS:
    void CountChanged();
    void IsPowerOnChanged();
    void startedPrj();
    void endedPrj();
    void readInfoBegin();

public Q_SLOTS:
    void TestSlot();
    int Count();
    bool IsPowerOn();
    void setIsPowerOn(bool value);
    void setCount(int count);
    void RunClicked();
    void PowerOnClicked();
    void HomePositionClicked();
    void startPrj();
    void endPrj();

    void RunTh();



private:
    int _count;
    bool _isPowerOn;
    bool _isRun;
    Controller *controller;

};

#endif // MAINVIEWMODEL_H
