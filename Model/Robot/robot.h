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
    double DriveEncoderRes = 524287;
    double PulsToDegFactor1[6] = { 360.0 / (DriveEncoderRes * 162.0), 360.0 / (DriveEncoderRes * 161.0), -1.0 * 360.0 / (DriveEncoderRes * 161.0), 360.0 / (DriveEncoderRes * 102.0), 360.0 / (DriveEncoderRes * 100.0), (-1.0 * 360.0) / (DriveEncoderRes * 102.0)};


private:

};

#endif // ROBOT_H
