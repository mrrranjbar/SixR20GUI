#include "robot.h"

Robot::Robot()
{

    QString frameName,type,savedStatus,frameMethod="";
    QString TempIndex="0",threePointsStatus="100";
    bool saved,iscurrent=false;

    double Qbase[8] = { 1,0,0,0,0,0,0,0 };
    double out[6];
    DQToCartesian(Qbase,out);
    QList<double> mainpointsList = {out[0],out[1],out[2],out[3],out[4],out[5]};

    currentWorldFrame=new frame(TempIndex,type,frameName,saved,iscurrent,mainpointsList,threePointsStatus,mainpointsList,"",mainpointsList,"",mainpointsList,"",frameMethod);
    currentObjectFrame=new frame(TempIndex,type,frameName,saved,iscurrent,mainpointsList,threePointsStatus,mainpointsList,"",mainpointsList,"",mainpointsList,"",frameMethod);
    currentTaskFrame=new frame(TempIndex,type,frameName,saved,iscurrent,mainpointsList,threePointsStatus,mainpointsList,"",mainpointsList,"",mainpointsList,"",frameMethod);
    currentToolFrame=new frame(TempIndex,type,frameName,saved,iscurrent,mainpointsList,threePointsStatus,mainpointsList,"",mainpointsList,"",mainpointsList,"",frameMethod);
    currentBaseFrame=new frame(TempIndex,type,frameName,saved,iscurrent,mainpointsList,threePointsStatus,mainpointsList,"",mainpointsList,"",mainpointsList,"",frameMethod);

    jogTempFrame=new frame(TempIndex,type,frameName,saved,iscurrent,mainpointsList,threePointsStatus,mainpointsList,"",mainpointsList,"",mainpointsList,"",frameMethod);

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

//*********************************************************************
//*********************************************************************

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

//*********************************************************************
//*********************************************************************

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

//*********************************************************************
//*********************************************************************

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

//*********************************************************************
//*********************************************************************

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

//*********************************************************************
//*********************************************************************

void Robot::CartesianToJoint(double Cartesian[], double out[])
{

}

//*********************************************************************
//*********************************************************************

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

//*********************************************************************
//*********************************************************************

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

//*********************************************************************
//*********************************************************************

void Robot::RotMToEuler(double val[3][3], double out[])
{
    double m00 = val[0][0];
    double m02 = val[0][2];
    double m10 = val[1][0];
    double m11 = val[1][1];
    double m12 = val[1][2];
    double m20 = val[2][0];
    double m22 = val[2][2];

    double x, y, z;

    // Assuming the angles are in radians.
    if (m10 > 0.998) { // singularity at north pole
        x = 0;
        y = M_PI / 2;
        z = atan2(m02, m22);
    }
    else if (m10 < -0.998) { // singularity at south pole
        x = 0;
        y = -M_PI / 2;
        z = atan2(m02, m22);
    }
    else
    {
        x = atan2(-m12, m11);
        y = asin(m10);
        z = atan2(-m20, m00);
    }

    out[0] = x;
    out[1] = y;
    out[2] = z;
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

//*********************************************************************
//*********************************************************************

double Robot::MatlabMod(double x, double y)
{
    double result = fmod(x, y);
    return result >= 0 ? result : result + y;
}

//*********************************************************************
//*********************************************************************

double Robot::abs(double x)
{
    return x >= 0 ? x : -x;
}

//*********************************************************************
//*********************************************************************

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
}


//*********************************************************************
//*********************************************************************

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


//*********************************************************************
//*********************************************************************


void Robot::Inversekinematic(double MT[], double QBase[], double QTool[], double CurPos[], double Q[6])//mnr
{
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
        t1 = round(Teta1[i - 1]*10000)/10000;

        for (int j = 1; j <= 2; j++) {
            //%Teta2
            a = (-2 * L[2] * Qg6*cos(t1) - 2 * L[2] * Qg7*sin(t1) + 2 * L[1] * L[2]);
            b = (2 * L[2] * Qg8 - 2 * L[0] * L[2]);
            c = Qg6 * Qg6 * cos(t1) *cos(t1) - Qg7 *Qg7 * cos(t1) *cos(t1) + L[0] * L[0] + L[1] * L[1] + L[2] * L[2] + Qg7 * Qg7 + Qg8 * Qg8 - 2 * L[0] * Qg8 + Qg6*Qg7*sin(2 * t1) - 2 * L[1] * Qg6*cos(t1) - 2 * L[1] * Qg7*sin(t1) - L[3] * L[3] - L[4] * L[4];
            Teta2[i-1][j-1] = atan2(b, a) - atan2(c, (2 * j - 3)*sqrt(abs(a *a + b *b - c *c)));
            InK[(4 * i + 2 * j  - 5) - 1][1] = Teta2[i-1][j-1];// *180 / M_PI;
            InK[(4 * i  + 2 * j  - 4) -1][1] = Teta2[i-1][j-1];// *180 / M_PI;
            t2 = round(Teta2[i-1][j-1]*10000)/10000;
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
            t3 = round(Teta3[i-1][j-1]*10000)/10000;
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
                t4 = round(Teta4[i-1][j-1][k-1]*10000)/10000;
                //%Teta5
                Teta5[i-1][j-1][k-1] = (2 * atan2(sqrt((N4[2]) *N4[2] + (N4[3]) *N4[3]), sqrt((N4[0]) *(N4[0]) + (N4[1]) *(N4[1]))))*(-2 * k + 3);
                InK[(4 * i  + 2 * j  + k  - 6) - 1][4] = Teta5[i-1][j-1][k-1];// *180 / M_PI;
                t5 = round(Teta5[i-1][j-1][k-1]*10000)/10000;
                //%Teta6
                Teta6[i-1][j-1][k-1] = (a - b) / 2 - (k - 1)*M_PI;
                InK[(4 * i + 2 * j  + k  - 6 ) - 1][5] = Teta6[i-1][j-1][k-1];// *180 / M_PI;
                t6 = round(Teta6[i-1][j-1][k-1]*10000)/10000;
            }
        }
    }
    double DInk[8][6];
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 6; j++) {
            InK[i][j] = MatlabMod(InK[i][j] + M_PI, 2 * M_PI) - M_PI;
            DInk[i][j] = abs(InK[i][j] - CurPos[j]);
        }
    }
    int min = 0;
    double minSum = 0;
    if (H1) {
        //%     X = ['The Solution Branch #5 to #8 is Fault'];
        min = 0;
        minSum = 0;
        for (int j = 0; j < 6; j++) {
            minSum += DInk[0][j];
        }
        double sum;
        for (int i = 1; i < 4; i++) {
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
        for (int i = 1; i < 8; i++) {
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
            while (abs(a0) > (M_PI/180)) {
                Q[5] = Q[5] - 2 * M_PI;
                a0 = Q[5] - CurPos[5];
            }
        }
        else {
            while (abs(a0) > (M_PI / 180)) {
                Q[5] = Q[5]+ 2 * M_PI;
                a0 = Q[5] - CurPos[5];
            }
        }
    }
}


