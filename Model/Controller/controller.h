#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model/Robot/robot.h"
#include "beckhoff.h"
#include <qqmlcontext.h>


class Controller
{    
    private:
        /* Here will be the instance stored. */
        static Controller* instance;

        /* Private constructor to prevent instancing. */
        Controller();

    public:
        /* Static access method. */
        QQmlContext *ctxt;
        static Controller* getInstance();
        Robot *robot;
        Beckhoff *beckhoff;
        QList<QObject*> dataList;
        void Initialize();
        QList<QObject*> framesList;


};

#endif // CONTROLLER_H
