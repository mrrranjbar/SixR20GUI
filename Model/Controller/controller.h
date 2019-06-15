#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model/Robot/robot.h"
#include "beckhoff.h"
#include <qqmlcontext.h>

#include <qqmlcontext.h>

class Controller
{    
    private:
        /* Here will be the instance stored. */
        static Controller* instance;

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

        QList<QObject*> framesList;

    signals :

    public slots:

};

#endif // CONTROLLER_H
