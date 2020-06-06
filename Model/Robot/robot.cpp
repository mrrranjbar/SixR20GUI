#include "robot.h"
#include "Model/Controller/controller.h"
#include "slerp.h"
Robot::Robot()
{


    QString frameName,type,savedStatus,frameMethod,correspondingFrameName="";
    QString TempIndex="0",threePointsStatus="000";
    bool saved,iscurrent=false;

    double Qbase[8] = { 1,0,0,0,0,0,0,0 };
    double out[6];
    DQToCartesian(Qbase,out);
    QList<double> mainpointsList = {out[0],out[1],out[2],out[3],out[4],out[5]};

    currentWorldFrame=new frame(TempIndex,type,frameName,correspondingFrameName,saved,iscurrent,mainpointsList,threePointsStatus,mainpointsList,"",mainpointsList,"",mainpointsList,"",frameMethod);
    currentObjectFrame=new frame(TempIndex,type,frameName,correspondingFrameName,saved,iscurrent,mainpointsList,threePointsStatus,mainpointsList,"",mainpointsList,"",mainpointsList,"",frameMethod);
    currentTaskFrame=new frame(TempIndex,type,frameName,correspondingFrameName,saved,iscurrent,mainpointsList,threePointsStatus,mainpointsList,"",mainpointsList,"",mainpointsList,"",frameMethod);
    currentToolFrame=new frame(TempIndex,type,frameName,correspondingFrameName,saved,iscurrent,mainpointsList,threePointsStatus,mainpointsList,"",mainpointsList,"",mainpointsList,"",frameMethod);
    currentBaseFrame=new frame(TempIndex,type,frameName,correspondingFrameName,saved,iscurrent,mainpointsList,threePointsStatus,mainpointsList,"",mainpointsList,"",mainpointsList,"",frameMethod);

    jogTempFrame=new frame(TempIndex,type,frameName,correspondingFrameName,saved,iscurrent,mainpointsList,threePointsStatus,mainpointsList,"",mainpointsList,"",mainpointsList,"",frameMethod);
    createFrameTemp=new frame(TempIndex,"object",frameName,correspondingFrameName,saved,iscurrent,mainpointsList,threePointsStatus,mainpointsList,"",mainpointsList,"",mainpointsList,"","3-point");

    modify_or_create=true;
    lastFrameType="world";

}

//*********************************************************************
//*********************************************************************

void Robot::GetCartPos(double theta[], double ToolParams[], double out[])
{
    double temp[] = { theta[0] , theta[1], theta[2],theta[3],theta[4],theta[5],theta[6] };
    double Q1[] = { (double)(cos((double)theta[0] / 2.0)), 0, 0,(double)(sin((double)theta[0] / 2.0)), 0, 0, 0, L[0] };
    double Q2[] = { (double)(cos((double)theta[1] / 2.0)), 0,  (double)(sin((double)theta[1] / 2.0)), 0, 0, 0, 0, 0 };
    double Q3[] = { (double)(cos((double)theta[2] / 2.0)), 0, (double)(sin((double)theta[2] / 2.0)), 0, 0, 0, 0, L[2] };
    double Q4[] = { (double)(cos((double)theta[3] / 2.0)), (double)(sin((double)theta[3] / 2.0)), 0, 0, 0, L[4], 0, L[3] };
    double Q5[] = { (double)(cos((double)theta[4] / 2.0)), 0, (double)(sin((double)theta[4] / 2.0)), 0, 0, 0, 0, 0 };
    double Q6[] = { (double)(cos((double)theta[5] / 2.0)), (double)(sin((double)theta[5] / 2.0)), 0, 0, 0, 0, 0, 0 };

    double M7[8];
    DQmultiply(QEndEffector, ToolParams, M7);
    double M6[8];
    DQmultiply(Q6, M7, M6);
    double M5[8];
    DQmultiply(Q5, M6, M5);
    double M4[8];
    DQmultiply(Q4, M5, M4);
    double M3[8];
    DQmultiply(Q3, M4, M3);
    double M2[8];
    DQmultiply(Q2, M3, M2);
    DQmultiply(Q1, M2, out);
}
void Robot::DQmultiply(double Q1[], double Q2[], double out[])
{
    out[0] = Q1[0] * Q2[0] - Q1[1] * Q2[1] - Q1[2] * Q2[2] - Q1[3] * Q2[3];
    out[1] = Q1[0] * Q2[1] + Q1[1] * Q2[0] + Q1[2] * Q2[3] - Q1[3] * Q2[2];
    out[2] = Q1[0] * Q2[2] + Q1[2] * Q2[0] - Q1[1] * Q2[3] + Q1[3] * Q2[1];
    out[3] = Q1[0] * Q2[3] + Q1[1] * Q2[2] - Q1[2] * Q2[1] + Q1[3] * Q2[0];
    out[4] = 0;
    out[5] = Q1[5] + Q2[5] + Q1[2] * (Q1[1] * Q2[6] - Q1[2] * Q2[5]) * 2 + Q1[0] * (Q1[2] * Q2[7] - Q1[3] * Q2[6]) * 2 + Q1[3] * (Q1[1] * Q2[7] - Q1[3] * Q2[5]) * 2;
    out[6] = Q1[6] + Q2[6] - Q1[1] * (Q1[1] * Q2[6] - Q1[2] * Q2[5]) * 2 - Q1[0] * (Q1[1] * Q2[7] - Q1[3] * Q2[5]) * 2 + Q1[3] * (Q1[2] * Q2[7] - Q1[3] * Q2[6]) * 2;
    out[7] = Q1[7] + Q2[7] + Q1[0] * (Q1[1] * Q2[6] - Q1[2] * Q2[5]) * 2 - Q1[1] * (Q1[1] * Q2[7] - Q1[3] * Q2[5]) * 2 - Q1[2] * (Q1[2] * Q2[7] - Q1[3] * Q2[6]) * 2;

    //return Q;
}
void Robot::toEulerianAngle(double quar[], double output[])
{
    double quar0 = quar[0];
    double quar1 = quar[1];
    double quar2 = quar[2];
    double quar3 = quar[3];
    //quar = quar.Normalize(2).ToArray();
    //double output[3];// = new decimal[3];
    double ysqr = quar2 * quar2;

    // roll (x-axis rotation)
    double t0 = +2.0 * (quar0 * quar1 + quar2 * quar3);
    double t1 = +1.0 - 2.0 * (quar1 * quar1 + ysqr);
    output[0] = (atan2(t0, t1) * 180) / (double)(M_PI);

    // pitch (y-axis rotation)
    double t2 = +2.0 * (quar0 * quar2 - quar3 * quar1);
    t2 = t2 > 1.0 ? 1.0 : t2;
    t2 = t2 < -1.0 ? -1.0 : t2;
    output[1] = (double)((asin((double)t2) * 180) / M_PI);

    // yaw (z-axis rotation)
    double t3 = +2.0 * (quar0 * quar3 + quar1 * quar2);
    double t4 = +1.0 - 2.0 * (ysqr + quar3 * quar3);
    output[2] = (atan2(t3, t4) * 180) / (double)(M_PI);

    //return output;
}
void Robot::toQuaternion(double roll, double pitch, double yaw, double q[])
{
    //double q[4];// = new decimal[4];
    double t0 = cos((double)yaw * 0.5);
    double t1 = sin((double)yaw * 0.5);
    double t2 = cos((double)roll * 0.5);
    double t3 = sin((double)roll * 0.5);
    double t4 = cos((double)pitch * 0.5);
    double t5 = sin((double)pitch * 0.5);

    q[0] = (double)(t0 * t2 * t4 + t1 * t3 * t5);
    q[1] = (double)(t0 * t3 * t4 - t1 * t2 * t5);
    q[2] = (double)(t0 * t2 * t5 + t1 * t3 * t4);
    q[3] = (double)(t1 * t2 * t4 - t0 * t3 * t5);
    //return q;
}

void Robot::JointToCartesian(double joint[], double out[])
{
    //    QList<double> tmpValue = currentBaseFrame->mainPoints();
    //    if(CurrentFrame=="world")
    //    {
    //        tmpValue = currentWorldFrame->mainPoints();
    //    }
    //    else if(CurrentFrame=="object")
    //    {
    //        tmpValue = currentObjectFrame->mainPoints();
    //    }
    //    else if(CurrentFrame=="task")
    //    {
    //        tmpValue = currentTaskFrame->mainPoints();
    //    }
    //    else if(CurrentFrame=="tool")
    //    {
    //        tmpValue = currentToolFrame->mainPoints();
    //    }
    //    else if(CurrentFrame=="base")
    //    {
    //        tmpValue = currentBaseFrame->mainPoints();
    //    }

    double tmptool[6] = {currentToolFrame->mainPoints().at(0),
                         currentToolFrame->mainPoints().at(1),
                         currentToolFrame->mainPoints().at(2),
                         currentToolFrame->mainPoints().at(3),
                         currentToolFrame->mainPoints().at(4),
                         currentToolFrame->mainPoints().at(5)};
    double tmpCurrentFrame[8];
    CartesianToDQ(tmptool,tmpCurrentFrame);
    double currentCartesian[8];
    for (int i=0;i<6;i++) {
        joint[i] = degreesToRadians(joint[i]);
    }
    GetCartPos(joint,tmpCurrentFrame,currentCartesian);
    DQToCartesian(currentCartesian, out);
}

void Robot::CartesianToJoint(double Cartesian[], double out[])
{

}
void Robot::CartesianToDQ(double cartesian[], double out[])
{
    double q[4];
    toQuaternion(degreesToRadians(cartesian[3]),degreesToRadians(cartesian[4]),degreesToRadians(cartesian[5]),q);
    out[0] = q[0];
    out[1] = q[1];
    out[2] = q[2];
    out[3] = q[3];
    out[4] = 0;
    out[5] = cartesian[0];
    out[6] = cartesian[1];
    out[7] = cartesian[2];
}

void Robot::DQToCartesian(double DQ[], double out[])
{
    double rpy[3];
    toEulerianAngle(DQ,rpy);
    out[0] = DQ[5];
    out[1] = DQ[6];
    out[2] = DQ[7];
    out[3] = rpy[0];
    out[4] = rpy[1];
    out[5] = rpy[2];
}

void Robot::RotMToEuler(double val[3][3], double out[])
{
    double m00 = val[0][0];
    double m02 = val[0][2];
    double m10 = val[1][0];
    double m11 = val[1][1];
    double m12 = val[1][2];
    double m20 = val[2][0];
    double m21 = val[2][1];
    double m22 = val[2][2];

    double x, y, z;

    float sy = sqrt(m00 * m00 +  m10 * m10 );

    bool singular = sy < 1e-6;


    if (!singular)
    {
        x = atan2(m21 , m22);
        y = atan2(-m20, sy);
        z = atan2(m10, m00);
    }
    else
    {
        x = atan2(-m12, m11);
        y = atan2(-m20, sy);
        z = 0;
    }

    out[0] = x;
    out[1] = y;
    out[2] = z;

    //**************************************************
    //**************************************************
    // old function
    // Assuming the angles are in radians.
    //    if (m10 > 0.998) { // singularity at north pole
    //        x = 0;
    //        y = M_PI / 2;
    //        z = atan2(m02, m22);
    //    }
    //    else if (m10 < -0.998) { // singularity at south pole
    //        x = 0;
    //        y = -M_PI / 2;
    //        z = atan2(m02, m22);
    //    }
    //    else
    //    {
    //        x = atan2(-m12, m11);
    //        y = asin(m10);
    //        z = atan2(-m20, m00);
    //    }

    //    out[0] = x;
    //    out[1] = y;
    //    out[2] = z;

    //**************************************************
    //**************************************************
}

void Robot::EulerToRotM(double theta[], double **out)
{
    // Calculates rotation matrix given euler angles.

    // Calculate rotation about x axis
    double** R_x = new double*[3];
    for(int i = 0; i < 3; ++i)
        R_x[i] = new double[3];
    R_x[0][0] = 1;
    R_x[0][1] = 0;
    R_x[0][2] = 0;
    R_x[1][0] = 0;
    R_x[1][1] = cos(theta[0]);
    R_x[1][2] = -sin(theta[0]);
    R_x[2][0] = 0;
    R_x[2][1] = sin(theta[0]);
    R_x[2][2] = cos(theta[0]);


    // Calculate rotation about y axis
    double** R_y = new double*[3];
    for(int i = 0; i < 3; ++i)
        R_y[i] = new double[3];
    R_y[0][0] = cos(theta[1]);
    R_y[0][1] = 0;
    R_y[0][2] = sin(theta[1]);
    R_y[1][0] = 0;
    R_y[1][1] = 1;
    R_y[1][2] = 0;
    R_y[2][0] = -sin(theta[1]);
    R_y[2][1] = 0;
    R_y[2][2] = cos(theta[1]);



    // Calculate rotation about z axis
    double** R_z = new double*[3];
    for(int i = 0; i < 3; ++i)
        R_z[i] = new double[3];
    R_z[0][0] = cos(theta[2]);
    R_z[0][1] = -sin(theta[2]);
    R_z[0][2] = 0;
    R_z[1][0] = sin(theta[2]);
    R_z[1][1] = cos(theta[2]);
    R_z[1][2] = 0;
    R_z[2][0] = 0;
    R_z[2][1] = 0;
    R_z[2][2] = 1;


    double** tmp = new double*[3];
    for(int i = 0; i < 3; ++i)
        tmp[i] = new double[3];
    MultipleMatrix(R_z,3,3,R_y,3,3,tmp);
    MultipleMatrix(tmp,3,3,R_x,3,3,out);
}

//*********************************************************************
//*********************************************************************

void Robot::DQinv(double Q1[], double Q[])
{
    //double Q[8];
    Q[0] = Q1[0];
    Q[1] = -Q1[1];
    Q[2] = -Q1[2];
    Q[3] = -Q1[3];
    Q[4] = 0;
    Q[5] = -Q1[5] - Q1[2] * (Q1[1] * Q1[6] - Q1[2] * Q1[5]) * 2 + Q1[0] * (Q1[2] * Q1[7] - Q1[3] * Q1[6]) * 2 - Q1[3] * (Q1[1] * Q1[7] - Q1[3] * Q1[5]) * 2;
    Q[6] = -Q1[6] + Q1[1] * (Q1[1] * Q1[6] - Q1[2] * Q1[5]) * 2 - Q1[0] * (Q1[1] * Q1[7] - Q1[3] * Q1[5]) * 2 - Q1[3] * (Q1[2] * Q1[7] - Q1[3] * Q1[6]) * 2;
    Q[7] = -Q1[7] + Q1[0] * (Q1[1] * Q1[6] - Q1[2] * Q1[5]) * 2 + Q1[1] * (Q1[1] * Q1[7] - Q1[3] * Q1[5]) * 2 + Q1[2] * (Q1[2] * Q1[7] - Q1[3] * Q1[6]) * 2;
    //return Q;
}

double Robot::MatlabMod(double x, double y)
{
    double result = fmod(x, y);
    return result >= 0 ? result : result + y;
}
double Robot::abs(double x)
{
    return x >= 0 ? x : -x;
}

void Robot::PointInReference(double point[], double frame[], QString frameName, double out[])
{
    double DQPointInFrame[8];
    CartesianToDQ(point,DQPointInFrame);
    double DQCurrentBase[8];
    double tmpCurrentBase[6] = {currentBaseFrame->mainPoints().at(0),
                                currentBaseFrame->mainPoints().at(1),
                                currentBaseFrame->mainPoints().at(2),
                                currentBaseFrame->mainPoints().at(3),
                                currentBaseFrame->mainPoints().at(4),
                                currentBaseFrame->mainPoints().at(5)};
    CartesianToDQ(tmpCurrentBase,DQCurrentBase);
    double DQCurrentTask[8];
    double tmpCurrentTask[6] = {currentTaskFrame->mainPoints().at(0),
                                currentTaskFrame->mainPoints().at(1),
                                currentTaskFrame->mainPoints().at(2),
                                currentTaskFrame->mainPoints().at(3),
                                currentTaskFrame->mainPoints().at(4),
                                currentTaskFrame->mainPoints().at(5)};
    CartesianToDQ(tmpCurrentTask,DQCurrentTask);
    double DQCurrentObject[8];
    double tmpCurrentObject[6] = {currentObjectFrame->mainPoints().at(0),
                                  currentObjectFrame->mainPoints().at(1),
                                  currentObjectFrame->mainPoints().at(2),
                                  currentObjectFrame->mainPoints().at(3),
                                  currentObjectFrame->mainPoints().at(4),
                                  currentObjectFrame->mainPoints().at(5)};
    CartesianToDQ(tmpCurrentObject,DQCurrentObject);
    double DQCurrentTool[8];
    double tmpCurrentTool[6] = {currentToolFrame->mainPoints().at(0),
                                currentToolFrame->mainPoints().at(1),
                                currentToolFrame->mainPoints().at(2),
                                currentToolFrame->mainPoints().at(3),
                                currentToolFrame->mainPoints().at(4),
                                currentToolFrame->mainPoints().at(5)};
    CartesianToDQ(tmpCurrentTool,DQCurrentTool);
    if(frameName == "world")
    {
        for(int i=0; i<6;i++)
        {
            out[i]=point[i];
        }
    }
    else if(frameName == "base")
    {
        double tmpOut[8];
        DQmultiply(DQCurrentBase,DQPointInFrame,tmpOut);
        DQToCartesian(tmpOut,out);
    }
    else if(frameName == "task")
    {
        double tmpOut1[8];
        DQmultiply(DQCurrentBase,DQCurrentTask,tmpOut1);
        double tmpOut2[8];
        DQmultiply(tmpOut1,DQPointInFrame,tmpOut2);
        DQToCartesian(tmpOut2,out);
    }
    else if(frameName == "object")
    {
        double tmpOut[8];
        DQmultiply(DQCurrentBase,DQCurrentTask,tmpOut);
        double tmpOut1[8];
        DQmultiply(tmpOut,DQCurrentObject,tmpOut1);
        double tmpOut2[8];
        DQmultiply(tmpOut1,DQPointInFrame,tmpOut2);
        DQToCartesian(tmpOut2,out);
    }
    else if(frameName == "tool")
    {
        double DQTCP[8];
        GetCartPos(ActualPositionRadian,DQCurrentTool,DQTCP);
        double DQTemp[8];
        DQmultiply(DQCurrentBase,DQTCP,DQTemp);
        double DQTemp1[8];
        DQmultiply(DQTemp,DQPointInFrame,DQTemp1);
        DQToCartesian(DQTemp1,out);
    }
}

void Robot::PointInReferenceFrame(double point[], double localFrame[], double out[])
{
    double DQPointInLocal[8];
    CartesianToDQ(point,DQPointInLocal);
    double DQLocalFrameInRef[8];
    CartesianToDQ(localFrame,DQLocalFrameInRef);
    double tmpOut[8];
    DQmultiply(DQLocalFrameInRef,DQPointInLocal,tmpOut);
    DQToCartesian(tmpOut,out);
}
void Robot::Inversekinematic(double MT[], double CurPos[], double Q[6])//mnr
{
    double temp[6],temp2[6];
    for (int i = 0;i < currentBaseFrame->mainPoints().size();i++) {
        temp[i] = currentBaseFrame->mainPoints().at(i);
        temp2[i] = currentToolFrame->mainPoints().at(i);
    }
    double QBase[8],QTool[8];
    CartesianToDQ(temp,QBase);
    CartesianToDQ(temp2,QTool);
    double InK[8][6];// = double[8][6];
    //Ink[1][1] = 1;
    double M8[8], M7[8], M6[8], M5[8], M4[8], M3[8], M2[8];
    double res[8];
    DQinv(QBase, res);
    DQmultiply(res, MT, M8);

    DQinv(QTool, res);
    DQmultiply(M8, res, M7);

    DQinv(QEndEffector, res);
    DQmultiply(M7, res, M6);

    double Qg1 = round(M6[0]*10000)/10000, Qg2 = round(M6[1]*10000)/10000, Qg3 = round(M6[2]*10000)/10000,
            Qg4 = round(M6[3]*10000)/10000, Qg5 = round(M6[4]*10000)/10000, Qg6 = round(M6[5]*10000)/10000,
            Qg7 = round(M6[6]*10000)/10000, Qg8 = round(M6[7]*10000)/10000;
    double Teta1[2], Teta2[2][2], Teta3[2][2], Teta4[2][2][2], Teta5[2][2][2], Teta6[2][2][2];
    double N4[4];
    double t1, t2, t3, t4, t5, t6;
    double H1;
    for (int i = 1; i <= 2; i++) {
        //%Teta1
        double a = Qg6;
        double b = Qg7;
        double c = 0;
        Teta1[i - 1] = atan2(b, a) - atan2(c, (-2 * i + 3)*sqrt(a*a + b*b - c*c));
        InK[(4 * i  - 3) - 1][0] = Teta1[i - 1];// *180 / M_PI;
        InK[(4 * i  - 2) - 1][0] = Teta1[i - 1];// *180 / M_PI;
        InK[(4 * i  - 1) - 1][0] = Teta1[i - 1];// *180 / M_PI;
        InK[(4 * i  - 0) - 1][0] = Teta1[i - 1];// *180 / M_PI;
        t1 = round(Teta1[i - 1]);

        for (int j = 1; j <= 2; j++) {
            //%Teta2
            a = (-2 * L[2] * Qg6*cos(t1) - 2 * L[2] * Qg7*sin(t1) + 2 * L[1] * L[2]);
            b = (2 * L[2] * Qg8 - 2 * L[0] * L[2]);
            c = Qg6 * Qg6 * cos(t1) *cos(t1) - Qg7 *Qg7 * cos(t1) *cos(t1) + L[0] * L[0] + L[1] * L[1] + L[2] * L[2] + Qg7 * Qg7 + Qg8 * Qg8 - 2 * L[0] * Qg8 + Qg6*Qg7*sin(2 * t1) - 2 * L[1] * Qg6*cos(t1) - 2 * L[1] * Qg7*sin(t1) - L[3] * L[3] - L[4] * L[4];
            Teta2[i-1][j-1] = atan2(b, a) - atan2(c, (2 * j - 3)*sqrt(abs(a *a + b *b - c *c)));
            InK[(4 * i + 2 * j  - 5) - 1][1] = Teta2[i-1][j-1];// *180 / M_PI;
            InK[(4 * i  + 2 * j  - 4) -1][1] = Teta2[i-1][j-1];// *180 / M_PI;
            t2 = round(Teta2[i-1][j-1]);
            H1 = a *a + b*b - c *c;
            // % Verification of Secend Branch of Teta1
            if ((a *a + b*b - c *c) < 0)
                H1 = 1;

            //%Teta3
            a = 2 * L[2] * L[4];
            b = 2 * L[2] * L[3];
            c = (Qg6*cos(t1) + Qg7*sin(t1) - L[1]) * (Qg6*cos(t1) + Qg7*sin(t1) - L[1]) + (Qg8 - L[0]) *(Qg8 - L[0]) - L[2] * L[2] - L[3] * L[3] - L[4] * L[4];

            Teta3[i-1][j-1] = atan2(b, a) - atan2(c, (-2 * j + 3)*sqrt(abs(a *a + b*b - c *c)));
            InK[(4 * i  + 2 * j  - 5) - 1][2] = Teta3[i-1][j-1];// *180 / pi;
            InK[(4 * i  + 2 * j  - 4) - 1][2] = Teta3[i-1][j-1];// *180 / pi;
            t3 = round(Teta3[i-1][j-1]);
            for (int k = 1; k <= 2; k++) {

                N4[0] = cos(t3 / 2)*(cos(t2 / 2)*(Qg1*cos(t1 / 2) + Qg4*sin(t1 / 2)) + sin(t2 / 2)*(Qg3*cos(t1 / 2) - Qg2*sin(t1 / 2))) + sin(t3 / 2)*(cos(t2 / 2)*(Qg3*cos(t1 / 2) - Qg2*sin(t1 / 2)) - sin(t2 / 2)*(Qg1*cos(t1 / 2) + Qg4*sin(t1 / 2)));
                N4[1] = cos(t3 / 2)*(cos(t2 / 2)*(Qg2*cos(t1 / 2) + Qg3*sin(t1 / 2)) - sin(t2 / 2)*(Qg4*cos(t1 / 2) - Qg1*sin(t1 / 2))) - sin(t3 / 2)*(cos(t2 / 2)*(Qg4*cos(t1 / 2) - Qg1*sin(t1 / 2)) + sin(t2 / 2)*(Qg2*cos(t1 / 2) + Qg3*sin(t1 / 2)));
                N4[2] = cos(t3 / 2)*(cos(t2 / 2)*(Qg3*cos(t1 / 2) - Qg2*sin(t1 / 2)) - sin(t2 / 2)*(Qg1*cos(t1 / 2) + Qg4*sin(t1 / 2))) - sin(t3 / 2)*(cos(t2 / 2)*(Qg1*cos(t1 / 2) + Qg4*sin(t1 / 2)) + sin(t2 / 2)*(Qg3*cos(t1 / 2) - Qg2*sin(t1 / 2)));
                N4[3] = cos(t3 / 2)*(cos(t2 / 2)*(Qg4*cos(t1 / 2) - Qg1*sin(t1 / 2)) + sin(t2 / 2)*(Qg2*cos(t1 / 2) + Qg3*sin(t1 / 2))) + sin(t3 / 2)*(cos(t2 / 2)*(Qg2*cos(t1 / 2) + Qg3*sin(t1 / 2)) - sin(t2 / 2)*(Qg4*cos(t1 / 2) - Qg1*sin(t1 / 2)));
                a = 2 * atan2(N4[1], N4[0]);
                b = 2 * atan2(N4[3], N4[2]);
                //%Teta4
                Teta4[i-1][j-1][k-1] = (a + b) / 2 - (k - 1)*M_PI;
                InK[(4 * i  + 2 * j  + k  - 6) - 1][3] = Teta4[i-1][j-1][k-1];// *180 / M_PI;
                t4 = round(Teta4[i-1][j-1][k-1]);
                //%Teta5
                Teta5[i-1][j-1][k-1] = (2 * atan2(sqrt((N4[2]) *N4[2] + (N4[3]) *N4[3]), sqrt((N4[0]) *(N4[0]) + (N4[1]) *(N4[1]))))*(-2 * k + 3);
                InK[(4 * i  + 2 * j  + k  - 6) - 1][4] = Teta5[i-1][j-1][k-1];// *180 / M_PI;
                t5 = round(Teta5[i-1][j-1][k-1]);
                //%Teta6
                Teta6[i-1][j-1][k-1] = (a - b) / 2 - (k - 1)*M_PI;
                InK[(4 * i + 2 * j  + k  - 6 ) - 1][5] = Teta6[i-1][j-1][k-1];// *180 / M_PI;
                t6 = round(Teta6[i-1][j-1][k-1]);
            }
        }
    }
    double DInk[8][6];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 6; j++) {
            InK[i][j] =  MatlabMod(InK[i][j] + M_PI, 2 * M_PI) - M_PI;
            DInk[i][j] = abs(InK[i][j] - CurPos[j]);
            DInk[i][j] = MatlabMod(DInk[i][j] + M_PI, 2 * M_PI) - M_PI;
            DInk[i][j] = abs(DInk[i][j]);
            if (j < 3)
            {
                DInk[i][j] *= 5;
            }
        }
    }
    int min = 0;
    double minSum = 0;
    if (H1==1) {
        //%     X = ['The Solution Branch #5 to #8 is Fault'];
        min = 0;
        minSum = 0;
        for (int j = 0; j < 6; j++) {
            minSum += DInk[0][j];
        }
        double sum;
        for (int i = 0; i < 4; i++) {
            sum = 0;
            for (int j = 0; j < 6; j++) {
                sum += DInk[i][j];
            }
            if (sum < minSum) {
                minSum = sum;
                min = i;
            }
        }
        for (int i = 0; i < 6; i++)
            Q[i] = InK[min][i];
    }
    else {
        min = 0;
        minSum = 0;
        for (int j = 0; j < 6; j++) {
            minSum += DInk[0][j];
        }
        double sum;
        for (int i = 0; i < 8; i++) {
            sum = 0;
            for (int j = 0; j < 6; j++) {
                sum += DInk[i][j];
            }
            if (sum < minSum) {
                minSum = sum;
                min = i;
            }
        }
        for (int i = 0; i < 6; i++)
            Q[i] = InK[min][i];
    }
    double a = Q[5] - CurPos[5];
    if (abs(a) >= 2.0 * M_PI * 359.0 / 360.0) {
        double a0 = a;
        if (a > 0) {
            while (abs(a0) >= (M_PI/180)) {
                Q[5] = Q[5] - 2 * M_PI;
                a0 = Q[5] - CurPos[5];
            }
        }
        else {
            while (abs(a0) >= (M_PI / 180)) {
                Q[5] = Q[5]+ 2 * M_PI;
                a0 = Q[5] - CurPos[5];
            }
        }
    }
    double a1 = Q[3] - CurPos[3];
    if (abs(a1) >= 2.0 * M_PI * 359.0 / 360.0) {
        double a00 = a1;
        if (a1 > 0) {
            while (abs(a00) >= (M_PI / 180)) {
                Q[3] = Q[3] - 2 * M_PI;
                a00 = Q[3] - CurPos[3];
            }
        }
        else {
            while (abs(a00) >= (M_PI / 180)) {
                Q[3] = Q[3] + 2 * M_PI;
                a00 = Q[3] - CurPos[3];
            }
        }
    }
    // Modificatin of Wrist Singularity
    double Q46;
    if (abs(CurPos[4]) < 0.001)
    {
        Q46 = Q[3] + Q[5];
        Q[3] = CurPos[3];
        Q[5] = Q46 - Q[3];
    }
}

double* Robot::jointForView(){
    Controller * controller = Controller::getInstance();
    double * tmp= new double[controller->beckhoff->NumberOfRobotMotors];
    for(int i =0; i<controller->beckhoff->NumberOfRobotMotors; ++i)
        tmp[i] =i*2;//(double)(controller->beckhoff->ActualPositions[0] * controller->robot->PulsToDegFactor1[0]);
    return tmp;
}
double* Robot::cartesianForView(){//change
    Controller * controller = Controller::getInstance();
    double *tmp= new double[controller->beckhoff->NumberOfRobotMotors];
    for(int i =0; i<controller->beckhoff->NumberOfRobotMotors; ++i)
        tmp[i] = i;
    return tmp;

}

TrajectoryPointList<double> Robot::SingleAxisTraj(TrajectoryPoint p0, TrajectoryPoint p1, double vmax, double amax, double jmax, double TS, double landa)//, TrajectoryPointList<double> out)
{
    TrajectoryPointList<double> trjp;// = new TrajectoryPointList<decimal>();
    //double[] q = new double[100000];
    //double[] v = new double[100000];
    //double[] a = new double[100000];
    double vlim, alima, alimd;
    if (p1.Q - p0.Q == 0)
    {
        trjp.init = false;
        return trjp;// NULL;
    }
    int sigma = 1;
    if (p1.Q < p0.Q)
    {
        sigma = -1;
        p0.Q *= -1;
        p0.V *= -1;
        p1.Q *= -1;
        p1.V *= -1;
    }
    double Tj1, Ta, Tj2, Td;
    if ((vmax - p0.V) * jmax < (amax * amax))
    {
        Tj1 = sqrt((vmax - p0.V) / jmax);
        Ta = 2 * Tj1;
    }
    else
    {
        Tj1 = amax / jmax;
        Ta = Tj1 + (vmax - p0.V) / amax;
    }

    if ((vmax - p1.V) * jmax < (amax * amax))
    {
        Tj2 = sqrt((vmax - p1.V) / jmax);
        Td = 2 * Tj2;
    }
    else
    {
        Tj2 = amax / jmax;
        Td = Tj2 + (vmax - p1.V) / amax;
    }
    double Tv = (p1.Q - p0.Q) / vmax - (Ta / 2) * (1 + p0.V / vmax) - (Td / 2) * (1 + p1.V / vmax);
    if (Tv < 0)
    {
        Tv = 0;
        while (true)
        {
            Tj1 = Tj2 = amax / jmax;
            double amax4 = pow(amax, 4);
            double delta = (amax4 / (jmax * jmax)) + 2 * (p0.V * p0.V + p1.V * p1.V) + amax * (4 * (p1.Q - p0.Q) - 2 * (amax / jmax) * (p0.V + p1.V));
            Ta = ((amax * amax / jmax) - 2 * p0.V + sqrt(delta)) / (2 * amax);
            Td = ((amax * amax / jmax) - 2 * p1.V + sqrt(delta)) / (2 * amax);
            if (Ta < 0)
            {
                Ta = 0;
                Td = 2 * (p1.Q - p0.Q) / (p1.V + p0.V);
                Tj2 = (jmax * (p1.Q - p0.Q) - sqrt(jmax * (jmax * (p1.Q - p0.Q) * (p1.Q - p0.Q) + (p1.V + p0.V) * (p1.V + p0.V) * (p1.V - p0.V)))) / (jmax * (p1.V + p0.V));
            }
            else if (Td < 0)
            {
                Td = 0;
                Ta = 2 * (p1.Q - p0.Q) / (p1.V + p0.V);
                Tj1 = (jmax * (p1.Q - p0.Q) - sqrt(jmax * (jmax * (p1.Q - p0.Q) * (p1.Q - p0.Q) + (p1.V + p0.V) * (p1.V + p0.V) * (p1.V - p0.V)))) / (jmax * (p1.V + p0.V));
            }

            if (Ta >= 2 * Tj1 && Td >= 2 * Tj2)
            {
                break;
            }
            else
                amax = landa * amax;
        }
        alima = jmax * Tj1;
        alimd = -jmax * Tj2;
        vlim = p0.V + (Ta - Tj1) * alima;
    }
    else
    {
        alima = amax;
        alimd = -amax;
        vlim = vmax;
    }
    double dur = Ta + Tv + Td; //pre process
    double jmin = -jmax;
    int i = 0;
    double t = 0;
    trjp.TrajLength = 0;
    while (t <= dur)
    {
        if (t < Tj1)
        {
            trjp.AddPoint(
                        (double)(p0.Q + p0.V * t + jmax * t * t * t / 6),
                        (double)(p0.V + jmax * t * t / 2),
                        (double)(jmax * t));

        }
        else if (t < Ta - Tj1)
        {
            trjp.AddPoint(
                        (double)(p0.Q + p0.V * t + alima * (3 * t * t - 3 * Tj1 * t + Tj1 * Tj1) / 6),
                        (double)(p0.V + alima * (t - Tj1 / 2)),
                        (double)(alima));
        }
        else if (t < Ta)
        {
            trjp.AddPoint(
                        (double)(p0.Q + (vlim + p0.V) * Ta / 2 - vlim * (Ta - t) - jmin * (Ta - t) * (Ta - t) * (Ta - t) / 6),
                        (double)(vlim + jmin * (Ta - t) * (Ta - t) / 2),
                        (double)(-jmin * (Ta - t)));
        }
        else if (t < Ta + Tv)
        {
            trjp.AddPoint(
                        (double)(p0.Q + (vlim + p0.V) * Ta / 2 + vlim * (t - Ta)),
                        (double)(vlim),
                        0);
        }
        else if (t < dur - Ta + Tj2)
        {
            trjp.AddPoint(
                        (double)(p1.Q - (vlim + p1.V) * Td / 2 + vlim * (t - dur + Td) -
                                 jmax * (t - dur + Td) * (t - dur + Td) * (t - dur + Td) / 6),
                        (double)(vlim - jmax * (t - dur + Td) * (t - dur + Td) / 2),
                        (double)(-jmax * (t - dur + Td)));
        }
        else if (t < dur - Tj2)
        {
            trjp.AddPoint(
                        (double)(p1.Q - (vlim + p1.V) * Td / 2 + vlim * (t - dur + Td) +
                                 alimd * (3 * (t - dur + Td) * (t - dur + Td) - 3 * Tj2 * (t - dur + Td) + Tj2 * Tj2) / 6),
                        (double)(vlim + alimd * (t - dur + Td - Tj2 / 2)),
                        (double)(alimd));
        }
        else if (t <= dur)
        {
            trjp.AddPoint(
                        (double)(p1.Q - p1.V * (dur - t) - (jmax * (dur - t) * (dur - t) * (dur - t) / 6)),
                        (double)(p1.V + (jmax * (dur - t) * (dur - t) / 2)),
                        (double)(-jmax * (dur - t)));
        }
        trjp.q.at(i) = trjp.q.at(i) * sigma;
        trjp.v.at(i) = trjp.v.at(i) * sigma;
        trjp.a.at(i) = trjp.a.at(i) * sigma;
        t += TS;
        i++;
    }
    if (p1.Q >= p0.Q)
    {
        p0.Q *= -1;
        p0.V *= -1;
        p1.Q *= -1;
        p1.V *= -1;
    }
    /*if (trjp == null)
            trjp = new TrajectoryPointList<double>();*/
    //for each (double var in trjp.q)
    //{
    //	out->q[i] = var;
    //}
    return trjp;
    /*out.q= trjp.q;
        out.TrajLength = trjp.TrajLength;
        out.v = trjp.v;
        out.init = trjp.init;
        out.a = trjp.a;*/
    //out = trjp;
}
void Robot::MultiAxisTraj(TrajectoryPoint p0[], TrajectoryPoint p1[], double vmax[], double amax[], double jmax[], double TS, double landa, TrajectoryPointList<double> out[])
{
    //TrajectoryPointList<double> trjp[6];// = new TrajectoryPointList<decimal>[6];
    for (int i = 0; i < 6; i++)
    {
        TrajectoryPoint p00(p0[i].Q, p0[i].V);// = TrajectoryPoint(p0.at(i).Q, p0.at(i).V);
        TrajectoryPoint p11(p1[i].Q, p1[i].V);// = TrajectoryPoint(p1[i].Q, p1[i].V);
        out[i] = SingleAxisTraj(p00, p11, vmax[i], amax[i], jmax[i], TS, landa);
    }
    //out= trjp;
}
void Robot::PTPList(double ActualPos[], double vals[], TrajectoryPointList<double> out[])
{
    int wmax_def = 300;
    int almax_def = 100; // Rotational Acceleration
    int gamax_def = 250; // Rotational Jerk
    //auto it = std::find(keys.begin(), keys.end(), "F");
    //int index = std::distance(keys.begin(), it);
    double wmax = std::min(vals[6], (double)wmax_def);
    TrajectoryPointList<double> outputs[6];// = new TrajectoryPointList<decimal>[6];
    TrajectoryPoint X0[6];
    //std::vector<TrajectoryPoint> X0;// = new TrajectoryPoint[6];

    for (int i = 0; i < 6; i++)
    {
        X0[i] = TrajectoryPoint(ActualPos[i], 0);
    }

    TrajectoryPoint X1[6];// = new TrajectoryPoint[6];
    double wmaxS[6];// = new double[6];
    double almaxS[6];// = new double[6];
    double gamaxS[6];// = new double[6];

    for (int i = 0; i < 6; i++)
    {
        X1[i] = TrajectoryPoint(vals[i], 0);
        wmaxS[i] = (double)wmax;
        almaxS[i] = almax_def;
        gamaxS[i] = gamax_def;
    }

    TrajectoryPointList<double> points[6];
    MultiAxisTraj(X0, X1, wmaxS, almaxS, gamaxS, .001, .999, points);
    int maxLength = 0;
    if (points[0].init == false)	//null
        points[0] = TrajectoryPointList<double>();
    for (int i = 1; i < 6; i++)
    {

        if (points[i].init == false)// == null)
            points[i] = TrajectoryPointList<double>();
        if (points[i].TrajLength > points[maxLength].TrajLength)
            maxLength = i;
    }
    for (int i = 0; i < 6; i++)
    {
        if (outputs[i].init == false)// == null)
            outputs[i] = TrajectoryPointList<double>();
        double ratio = (X1[i].Q - X0[i].Q) / (X1[maxLength].Q - X0[maxLength].Q);
        for (int j = 0; j < points[maxLength].TrajLength; j++)
            outputs[i].AddPoint((double)(X0[i].Q + ((double)points[maxLength].q[j] - X0[maxLength].Q) * ratio), 0, 0);
        // outputs[i].q[j] = X0[i].Q + (points[maxLength].q[j] - X0[maxLength].Q) * ratio;

        outputs[i].TrajLength = points[maxLength].TrajLength;
    }
    for (int i = 0; i < 6; i++)
    {
        out[i] = outputs[i];
    }

    //out = outputs;
}
void Robot::PTPCartesian(double ActualPos[], double vals[], TrajectoryPointList<double> out[])
{
    double res[6];
    double Quat[4];
    toQuaternion(vals[3] * (M_PI / 180.0), vals[4] * (M_PI / 180.0), vals[5] * (M_PI / 180.0), Quat);
    double q[] = { Quat[0], Quat[1], Quat[2], Quat[3], 0, vals[0], vals[1], vals[2] };
    //for (i = 0; i < 6; i++) {
    //	actualPos[i] = (actualPos[i] * M_PI) / 180.0; //to radian
    //}
    double tmpActualPos[6] = { (ActualPos[0] * M_PI) / 180.0 , (ActualPos[1] * M_PI) / 180.0 ,(ActualPos[2] * M_PI) / 180.0 ,(ActualPos[3] * M_PI) / 180.0 ,(ActualPos[4] * M_PI) / 180.0 ,(ActualPos[5] * M_PI) / 180.0 };
    Inversekinematic(q, tmpActualPos, res);//, res);
    double targetPos[] = { res[0] * (180.0 / M_PI),res[1] * (180.0 / M_PI),res[2] * (180.0 / M_PI),res[3] * (180.0 / M_PI),res[4] * (180.0 / M_PI),res[5] * (180.0 / M_PI),vals[6],vals[7]};
    PTPList(ActualPos, targetPos, out);

}
void Robot::LIN(double actualPosition[], double targetPosition[], TrajectoryPointList<double> resultList[])
{
    double temp[6],temp2[6];
    for (int i = 0;i < currentBaseFrame->mainPoints().size();i++) {
        temp[i] = currentBaseFrame->mainPoints().at(i);
        temp2[i] = currentToolFrame->mainPoints().at(i);
    }
    double QBase[8],QTool[8];
    CartesianToDQ(temp,QBase);
    CartesianToDQ(temp2,QTool);
    Controller * controller = Controller::getInstance();
    double DQCurrentPosition[8];
    GetCartPos(actualPosition, QTool, DQCurrentPosition);
    double DQCurrentPositionInRef[8];
    DQmultiply(QBase, DQCurrentPosition, DQCurrentPositionInRef);
    double DQTargetPositionInRef[8];
    // for X,Y,Z
    for (int i = 0; i < 3; i++)
    {
        DQTargetPositionInRef[i + 5] = targetPosition[i];
    }
    //for A,B,C
    double QuatRPYTargetPosition[4];
    double QuatRPYCurrentPosition[4] = { DQCurrentPositionInRef[0], DQCurrentPositionInRef[1], DQCurrentPositionInRef[2], DQCurrentPositionInRef[3] };
    toQuaternion(targetPosition[3] * (M_PI / 180.0), targetPosition[4] * (M_PI / 180.0), targetPosition[5] * (M_PI / 180.0), QuatRPYTargetPosition);
    for (int i = 0; i < 4; i++)
        DQTargetPositionInRef[i] = QuatRPYTargetPosition[i];
    //double tmpVals[8] = { 0, 0, 0, 0, 0, 0, targetPosition[6], 1 }; //mrr
    //double tolerance = .00001;
    //if (abs(targetPosition[6] - (-1)) > tolerance)
    //	tmpVals[6] = targetPosition[6];//mrr
    //if (abs(targetPosition[7] - (-1)) > tolerance)//mrr
    //	tmpVals[7] = targetPosition[7];//mrr
    double distance = sqrt(pow(DQTargetPositionInRef[5] - DQCurrentPositionInRef[5], 2) + pow(DQTargetPositionInRef[6] - DQCurrentPositionInRef[6], 2) + pow(DQTargetPositionInRef[7] - DQCurrentPositionInRef[7], 2));
    TrajectoryPointList<double> pointList = SingleAxisTraj(TrajectoryPoint(0, 0), TrajectoryPoint(distance, 0), targetPosition[6], 100, 250, .001, .999); //a:5000, j:10000 tmpVals[6]
    //double tmpTeta[6];
    Quaternion Qend = Quaternion(QuatRPYTargetPosition);
    Quaternion QCurrent = Quaternion(QuatRPYCurrentPosition);
    Quaternion Qnext;
    slerp s;
    for (int i = 0; i < pointList.TrajLength; i++)
    {
        //XYZ
        double x = DQCurrentPositionInRef[5] + (pointList.q[i] / distance) * (DQTargetPositionInRef[5] - DQCurrentPositionInRef[5]);
        double y = DQCurrentPositionInRef[6] + (pointList.q[i] / distance) * (DQTargetPositionInRef[6] - DQCurrentPositionInRef[6]);
        double z = DQCurrentPositionInRef[7] + (pointList.q[i] / distance) * (DQTargetPositionInRef[7] - DQCurrentPositionInRef[7]);
        //Quat ABC
        s.Slerp1(QCurrent, Qend, Qnext, pointList.q[i] / distance);
        double res[6];
        double DQPath[] = {Qnext.u.x, Qnext.u.y, Qnext.u.z, Qnext.w, 0, x, y, z };
        if (i == 0)
        {
            Inversekinematic(DQPath, actualPosition, res);//, res);
        }
        else
        {
            double PrePosition[6];
            for (int j = 0; j < 6; j++)
            {
                PrePosition[j] = resultList[j].q[i - 1] * (M_PI/ 180.0);
            }
            Inversekinematic(DQPath, PrePosition, res);
        }
        // checking for wrist singularity
        //        if(res[4] == 0) // wrist singularity has happend
        //        {
        //            if(controller->beckhoff->getSingulCP())
        //            {

        //            }
        //        }
        for (int j = 0; j < 6; j++)
        {
            resultList[j].AddPoint(res[j] * (180.0 / M_PI), 0, 0);
        }
    }
}
void Robot::CIRC(double zero[], double one[], double second[], TrajectoryPointList<double> resultList[])//double zero[], double v0, double one[], double v1, double second[], double vmax, double amax, double jmax, double Ta, TrajectoryPointList<double> resultList[])
{
    //zero: XYZYPR source
    //one: XYZYPR dest
    double temp[6],temp2[6];
    for (int i = 0;i < currentBaseFrame->mainPoints().size();i++) {
        temp[i] = currentBaseFrame->mainPoints().at(i);
        temp2[i] = currentToolFrame->mainPoints().at(i);
    }
    double QBase[8],QTool[8];
    CartesianToDQ(temp,QBase);
    CartesianToDQ(temp2,QTool);
    double v0 = 0, v1 = 0, vmax = one[6], amax = 100, jmax = 250, Ta = second[3];
    double DQCurrentPosition[8];
    GetCartPos(zero, QTool, DQCurrentPosition);
    double DQCurrentPositionInRef[8];
    DQmultiply(QBase, DQCurrentPosition, DQCurrentPositionInRef);

    double A[3];
    double B[3];
    double C[3];
    A[0] = DQCurrentPositionInRef[5];
    A[1] = DQCurrentPositionInRef[6];
    A[2] = DQCurrentPositionInRef[7];
    B[0] = one[0];
    B[1] = one[1];
    B[2] = one[2];
    C[0] = second[0];
    C[1] = second[1];
    C[2] = second[2];
    double u1[3];
    sub(B, A, u1, 3);
    double tmp[3];
    double w1[3];
    sub(C, A, tmp, 3);
    // 	w1 = cross(u1,C-A);
    cross(u1, tmp, w1, 3);
    // u  = u1/norm(u1);
    double u[3];
    double uNorm = normA(u1, 3);
    for (int i = 0; i<3; i++)
        u[i] = u1[i] / uNorm;
    // w  = w1/norm(w1);
    double w[3];
    double wNorm = normA(w1, 3);
    for (int i = 0; i<3; i++)
        w[i] = w1[i] / wNorm;
    // v  = cross(w,u);
    double v[3];
    cross(w, u, v, 3);
    // bx = dot(B-A,u);
    double bx = dot(u1, u, 3);
    // cx = dot(C-A,u);
    double cx = dot(tmp, u, 3);
    // cy = dot(C-A,v);
    double cy = dot(tmp, v, 3);
    // h  = ((cx-bx/2)^2 + cy^2 - (bx/2)^2) / (2*cy);
    double h;
    h = ((cx - bx / 2)*(cx - bx / 2) + cy*cy - (bx / 2)*(bx / 2)) / (2 * cy);
    // A2d= [0 0];
    double A2d[2] = { 0,0 };

    // B2d= [bx 0];
    double B2d[2] = { bx, 0 };

    // C2d= [cx cy];
    double C2d[2] = { cx,cy };


    // Cen2d= [bx/2 h]; %center of circle in 2d
    double Cen2d[2] = { bx / 2, h };

    // R  = norm(Cen2d); %radius of circle
    double R = normA(Cen2d, 2);
    double D0, D1, T0;
    // if nargin==20
    if (Ta == -1) {
        //     Ta = acos(dot((A2d-Cen2d),(B2d-Cen2d))/(norm(A2d-Cen2d)*norm(B2d-Cen2d)));
        double x[2]; double y[2];
        sub(A2d, Cen2d, x, 2);
        sub(B2d, Cen2d, y, 2);
        Ta = acos(dot(x, y, 2) / (normA(x, 2)*normA(y, 2)));
        //     if h > 0
        if (h>0)
            Ta = 2 * M_PI - Ta;
        //         Ta = 2*pi - Ta;
        //     end
        //     D0 = (pi+Ta)/2;
        D0 = (M_PI + Ta) / 2;
        //     D1 = (pi-Ta)/2;
        D1 = (M_PI - Ta) / 2;

        // else
    }
    else {
        //     T0 = acos(dot((A2d-Cen2d),(B2d-Cen2d))/(norm(A2d-Cen2d)*norm(B2d-Cen2d)));
        double x[2]; double y[2];
        sub(A2d, Cen2d, x, 2);
        sub(B2d, Cen2d, y, 2);
        T0 = acos(dot(x, y, 2) / (normA(x, 2)*normA(y, 2)));
        //     if h > 0
        //         T0 = 2*pi - T0;
        //     end
        if (h>0)
            T0 = 2 * M_PI - T0;
        //     D0 = (pi+Ta)/2 - (Ta-T0)/2 ;
        D0 = (M_PI + Ta) / 2 - (Ta - T0) / 2;
        //     D1 = (pi-Ta)/2 - (Ta-T0)/2 ;
        D1 = (M_PI - Ta) / 2 - (Ta - T0) / 2;
        // end
    }
    v0 = -1 * v0 / R;
    v1 = -1 * v1 / R;
    vmax /= R;
    amax /= R;
    jmax /= R;
    // [time,L]=Single_Axis_7Segment_Trajectory(D0,D1,v0,v1,vmax,amax,jmax);
    TrajectoryPointList<double> pointList;
    pointList = SingleAxisTraj(TrajectoryPoint(D0, 0), TrajectoryPoint(D1, 0), vmax, amax, jmax, .001, .999); //a:5000, j:10000 tmpVals[6]
    double  x, y, z, ratio;
    slerp s;
    Quaternion Qtmp;
    //cout << pointList.TrajLength << endl;
    for (int i = 0; i < pointList.TrajLength; i++) {
        //XYZ
        // X = (X0 + Cen2d(1,1)*u(1,1) + Cen2d(1,2)*v(1,1))+(R*cos(L)*u(1,1)+ R*sin(L)*v(1,1));
        x=(DQCurrentPositionInRef[5] + Cen2d[0] * u[0] + Cen2d[1] * v[0]) + R*cos(pointList.q[i])*u[0] + R* sin(pointList.q[i])*v[0];
        // Y = (Y0 + Cen2d(1,1)*u(1,2) + Cen2d(1,2)*v(1,2))+(R*cos(L)*u(1,2)+ R*sin(L)*v(1,2));
        y=(DQCurrentPositionInRef[6] + Cen2d[0] * u[1] + Cen2d[1] * v[1]) + R*cos(pointList.q[i])*u[1] + R*sin(pointList.q[i])*v[1];
        // Z = (Z0 + Cen2d(1,1)*u(1,3) + Cen2d(1,2)*v(1,3))+(R*cos(L)*u(1,3)+ R*sin(L)*v(1,3));
        z= DQCurrentPositionInRef[7] + Cen2d[0] * u[2] + Cen2d[1] * v[2] + R*cos(pointList.q[i])*u[2] + R*sin(pointList.q[i])*v[2];
        // ratio=(L-D0)/(D1-D0);
        ratio=(pointList.q[i] - D0) / (D1 - D0);


        //RPY
        double Q0[4] = { DQCurrentPositionInRef[0], DQCurrentPositionInRef[1], DQCurrentPositionInRef[2], DQCurrentPositionInRef[3] };
        //toQuaternion(zero[3]*(M_PI/180.0), zero[4] * (M_PI / 180.0), zero[5] * (M_PI / 180.0), Q0);

        double Q1[4];
        toQuaternion(one[3] * (M_PI / 180.0), one[4] * (M_PI / 180.0), one[5] * (M_PI / 180.0), Q1);

        s.Slerp1(Q0, Q1, Qtmp, ratio);

        double res[6];
        double DQPath[] = { Qtmp.u.x, Qtmp.u.y, Qtmp.u.z, Qtmp.w, 0, x, y, z };
        if (i == 0)
        {
            Inversekinematic(DQPath, zero , res);//, res);
        }
        else
        {
            double PrePosition[6];
            for (int j = 0; j < 6; j++)
            {
                PrePosition[j] = resultList[j].q[i - 1] * (M_PI / 180.0);
            }
            Inversekinematic(DQPath, PrePosition, res);
        }
        for (int j = 0; j < 6; j++)
        {
            resultList[j].AddPoint(res[j] * (180.0 / M_PI), 0, 0);
        }
    }
}
void Robot::sub(double a[], double b[], double out[], int len) {
    for (int i = 0; i<len; i++)
        out[i] = a[i] - b[i];
}
void Robot::cross(double a[], double b[], double out[], int len) {
    out[0] = a[1] * b[2] - a[2] * b[1];
    out[1] = a[2] * b[0] - a[0] * b[2];
    out[2] = a[0] * b[1] - a[1] * b[0];

}
double Robot::dot(double a[], double b[], int len) {
    double s = 0;
    for (int i = 0; i<len; i++)
        s += a[i] * b[i];
    return s;
}
double Robot::normA(double a[], int len) {
    double s = 0;
    for (int i = 0; i<len; i++)
        s += (a[i] * a[i]);
    // cout<<"s: "<<s<<endl;
    return sqrt(s);
}

bool Robot::sumMatrix(double **N, int n1, int n2, double **M, int m1,int m2, double **out)
{
    if(n1 == m1 && n2 == m2)
    {
        for(int i=0; i< n1;i++)
        {
            for(int j =0; j < m1; j++)
            {
                out[i][j] = N[i][j] + M[i][j];
            }
        }
        return true;
    }
    else {
        return false;
    }
}
bool Robot::subMatrix(double **N, int n1, int n2, double **M, int m1,int m2, double **out)
{
    if(n1 == m1 && n2 == m2)
    {
        for(int i=0; i< n1;i++)
        {
            for(int j =0; j < m1; j++)
            {
                out[i][j] = N[i][j] - M[i][j];
            }
        }
        return true;
    }
    else {
        return false;
    }
}

bool Robot::MultipleMatrix(double **N, int n1, int n2, double **M, int m1, int m2, double **out)
{
    if(n2 == m1)
    {
        for (int i = 0; i < n1; i++)
        {
            for (int j = 0; j < m2; j++)
            {
                out[i][j] = 0;
                for (int k = 0; k < m1; k++)
                {
                    out[i][j] += N[i][k] * M[k][j];
                }
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

void Robot::TransposeMatrix(double **N, int n1, int n2, double **out)
{
    for (int i = 0; i < n1; ++i)
    {
        for (int j = 0; j < n2; ++j) {
            out[j][i] = N[i][j];
        }
    }
}

void Robot::InverseMatrix(double **N, int n1, int n2, double **out)
{
    // computes the inverse of a matrix m
    double det = N[0][0] * (N[1][1] * N[2][2] - N[2][1] * N[1][2]) -
            N[0][1] * (N[1][0] * N[2][2] - N[1][2] * N[2][0]) +
            N[0][2] * (N[1][0] * N[2][1] - N[1][1] * N[2][0]);

    double invdet = 1 / det;

    out[0][0] = (N[1][1] * N[2][2] - N[2][1] * N[1][2]) * invdet;
    out[0][1] = (N[0][2] * N[2][1] - N[0][1] * N[2][2]) * invdet;
    out[0][2] = (N[0][1] * N[1][2] - N[0][2] * N[1][1]) * invdet;
    out[1][0] = (N[1][2] * N[2][0] - N[1][0] * N[2][2]) * invdet;
    out[1][1] = (N[0][0] * N[2][2] - N[0][2] * N[2][0]) * invdet;
    out[1][2] = (N[1][0] * N[0][2] - N[0][0] * N[1][2]) * invdet;
    out[2][0] = (N[1][0] * N[2][1] - N[2][0] * N[1][1]) * invdet;
    out[2][1] = (N[2][0] * N[0][1] - N[0][0] * N[2][1]) * invdet;
    out[2][2] = (N[0][0] * N[1][1] - N[1][0] * N[0][1]) * invdet;
}
