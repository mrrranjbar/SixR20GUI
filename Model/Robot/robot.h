#ifndef ROBOT_H
#define ROBOT_H

#include "../ViewModel/frame.h"


class Robot
{
public:
    Robot();
    frame *currentWorldFrame;
    frame *currentObjectFrame;
    frame *currentTaskFrame;
    frame *currentToolFrame;
    frame *currentBaseFrame;
    frame *jogTempFrame;


private:

};

#endif // ROBOT_H
