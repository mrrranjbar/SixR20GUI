#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Model/Robot/robot.h"
#include "beckhoff.h"


class Controller
{    
    private:
        /* Here will be the instance stored. */
        static Controller* instance;

        /* Private constructor to prevent instancing. */
        Controller();

    public:
        /* Static access method. */
        static Controller* getInstance();
        Robot *robot;
        Beckhoff *beckhoff;


};

#endif // CONTROLLER_H
