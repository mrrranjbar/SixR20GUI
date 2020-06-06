#ifndef ROBOT_H
#define ROBOT_H

#include "../ViewModel/frame.h"
#include "math.h"
#include "TrajectoryPoint.h"

//#include <TcMath.h>
//#include <RtlR0.h>	//abs
#include "TrajectoryPoint.h"
//#include <iostream.h>
#include <vector>
#include <string.h>
//#include <numeric>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>    // std::min
#define M_PI  3.14159265358979323846

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
    frame *createFrameTemp;
    double ActualPositionRadian[6];
    bool modify_or_create; // create = true , modify = false
    int currentFrameListIndex=0;
    QString lastFrameType="world";

    const double L[6] = { 389.5, 0 , 600, 200, 685.5, 135 };
    double QEndEffector[8] = { 1, 0,0,0,0 , L[5], 0 ,0 };//QT
    double DriveEncoderRes = 524287;
    double PulsToDegFactor1[6] = { 360.0 / (DriveEncoderRes * 162.0), 360.0 / (DriveEncoderRes * 161.0), -1.0 * 360.0 / (DriveEncoderRes * 161.0), 360.0 / (DriveEncoderRes * 102.0), 360.0 / (DriveEncoderRes * 100.0),  (-1.0 * 360.0) / (DriveEncoderRes * 102.0)  };



    void JointToCartesian(double joint[], double out[]);
    void CartesianToJoint(double Cartesian[], double out[]);
    void CartesianToDQ(double cartesian[], double out[]);
    void DQToCartesian(double DQ[], double out[]);
    void RotMToEuler(double val[3][3], double out[]);
    void EulerToRotM(double val[3], double **out);
     void GetCartPos(double theta[6], double ToolParams[], double out[]);
     void DQmultiply(double Q1[], double Q2[], double out[]);
     void toEulerianAngle(double quar[], double output[]);
     void toQuaternion(double roll, double pitch, double yaw, double q[]);
     void Inversekinematic(double MT[], double CurPos[], double Q[6]);//mnr
     void DQinv(double Q1[], double Q[]);
     double MatlabMod(double x, double y);
     double abs(double x);
     void PointInReference(double point[], double frameValue[], QString frameName, double out[]);
     void PointInReferenceFrame(double point[], double localFrame[], double out[]);
     //ffff
     double* jointForView(void);
     double* cartesianForView(void);

     TrajectoryPointList<double> SingleAxisTraj(TrajectoryPoint p0, TrajectoryPoint p1, double vmax, double amax, double jmax, double TS, double landa);//, TrajectoryPointList<double> out);
     void MultiAxisTraj(TrajectoryPoint p0[], TrajectoryPoint p1[], double vmax[], double amax[], double jmax[], double TS, double landa, TrajectoryPointList<double> out[]);
     void PTPList(double ActualPos[], double vals[], TrajectoryPointList<double> out[]);
     void PTPCartesian(double ActualPos[], double vals[], TrajectoryPointList<double> out[]);
     //TrajectoryPointList<double>* PTPList(double ActualPos[], std::map <char*, double> dict);
     void LIN(double ActualPos[], double vals[], TrajectoryPointList<double> outputs[]);


     void CIRC(double zero[], double one[], double second[], TrajectoryPointList<double> resultList[]);
     void sub(double a[], double b[], double out[], int len);
     void cross(double a[], double b[], double out[], int len);
     double dot(double a[], double b[], int len);
     double normA(double a[], int len);
     bool sumMatrix(double **N, int n1, int n2, double **M, int m1,int m2, double **out);
     bool subMatrix(double **N, int n1, int n2, double **M, int m1,int m2, double **out);
     bool MultipleMatrix(double **N, int n1, int n2, double **M, int m1,int m2, double **out);
     void TransposeMatrix(double **N, int n1, int n2, double **out);
     void InverseMatrix(double **N, int n1, int n2, double **out);


private:

};

#endif // ROBOT_H
