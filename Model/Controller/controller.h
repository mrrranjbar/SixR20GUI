#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model/Robot/robot.h"
#include "beckhoff.h"
#include <qqmlcontext.h>

#include <qqmlcontext.h>
#include "Model/ViewModel/alarm.h"


class Controller
{    
    private:
        /* Here will be the instance stored. */
        static Controller* instance;
        QHash<QString,alarm*> *_alarmTable;
        alarm* getAlarm(QString key);


        /* Private constructor to prevent instancing. */
        Controller();

    public:
        QQmlContext *ctxt;
        /* Static access method. */
        static Controller* getInstance();
        Robot *robot;
        Beckhoff *beckhoff;
        QList<QObject*> dataList;
        void Initialize();
//        void editList(int index);
        void InitializePoints();
        void InitializeAlarm();
        void initializeHashTable();
//        void InitializeChartPoints();

        QList<QObject*> framesList;
        QList<QObject*> alarmList;
//        QList<QObject*> chartpointsList;

        void AlarmDetection();
        void InitializeFrames();


    Q_SIGNALS :

    public Q_SLOTS:

};

#endif // CONTROLLER_H
