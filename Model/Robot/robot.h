#ifndef ROBOT_H
#define ROBOT_H

#include "../ViewModel/frame.h"
#include "math.h"
#define degreesToRadians(angleDegrees) (angleDegrees * M_PI / 180.0)
#define radiansToDegrees(angleRadians) (angleRadians * 180.0 / M_PI)


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
    bool modify_or_create; // create = true , modify = false
    int currentFrameListIndex=0;

    const double L[6] = { 389.5, 0 , 600, 200, 685.5, 135 };
    double QEndEffector[8] = { 1, 0,0,0,0 , L[5], 0 ,0 };//QT
    double DriveEncoderRes = 524287;
    double PulsToDegFactor1[6] = { 360.0 / (DriveEncoderRes * 162.0), 360.0 / (DriveEncoderRes * 161.0), -1.0 * 360.0 / (DriveEncoderRes * 161.0), 360.0 / (DriveEncoderRes * 102.0), 360.0 / (DriveEncoderRes * 100.0),  (-1.0 * 360.0) / (DriveEncoderRes * 102.0)  };



    void JointToCartesian(double joint[], double out[]);
    void CartesianToJoint(double Cartesian[], double out[]);
    void CartesianToDQ(double cartesian[], double out[]);
    void DQToCartesian(double DQ[], double out[]);
    void RotMToEuler(double val[3][3], double out[]);
     void GetCartPos(double theta[6], double ToolParams[], double out[]);
     void DQmultiply(double Q1[], double Q2[], double out[]);
     void toEulerianAngle(double quar[], double output[]);
     void toQuaternion(double roll, double pitch, double yaw, double q[]);
     void Inversekinematic(double MT[], double QBase[], double QTool[], double CurPos[], double Q[6]);//mnr
     void DQinv(double Q1[], double Q[]);
     double MatlabMod(double x, double y);
     double abs(double x);
     void PointInReference(double point[], double frameValue[], QString frameName, double out[]);
     void PointInReferenceFrame(double point[], double localFrame[], double out[]);

private:



};

#endif // ROBOT_H
