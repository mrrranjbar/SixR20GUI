
#pragma hdrstop
#include "slerp.h"

inline void Quaternion::Multiply(const Quaternion q)
{
    Quaternion tmp;
    tmp.u.x = ((w * q.u.x) + (u.x * q.w) + (u.y * q.u.z) - (u.z * q.u.y));
    tmp.u.y = ((w * q.u.y) - (u.x * q.u.z) + (u.y * q.w) + (u.z * q.u.x));
    tmp.u.z = ((w * q.u.z) + (u.x * q.u.y) - (u.y * q.u.x) + (u.z * q.w));
    tmp.w = ((w * q.w) - (u.x * q.u.x) - (u.y * q.u.y) - (u.z * q.u.z));
    *this = tmp;
}

inline double Quaternion::Norm()
{
    return sqrt(u.x*u.x + u.y*u.y + u.z*u.z + w*w);
}


inline void Quaternion::Normalize()
{
    double norm = Norm();
    u.x /= norm; u.y /= norm; u.z /= norm; w /= norm;
}

inline void Quaternion::Conjugate()
{
    u.x = -u.x;
    u.y = -u.y;
    u.z = -u.z;
}

inline void Quaternion::Inverse()
{
    double norm = Norm();
    Conjugate();
    u.x /= norm;
    u.y /= norm;
    u.z /= norm;
    w /= norm;
}

void Quaternion::ExportToMatrix(float matrix[16])
{
    float wx, wy, wz, xx, yy, yz, xy, xz, zz;
    // adapted from Shoemake
    xx = u.x * u.x;
    xy = u.x * u.y;
    xz = u.x * u.z;
    yy = u.y * u.y;
    zz = u.z * u.z;
    yz = u.y * u.z;

    wx = w * u.x;
    wy = w * u.y;
    wz = w * u.z;

    matrix[0] = 1.0f - 2.0f*(yy + zz);
    matrix[4] = 2.0f*(xy - wz);
    matrix[8] = 2.0f*(xz + wy);
    matrix[12] = 0.0;

    matrix[1] = 2.0f*(xy + wz);
    matrix[5] = 1.0f - 2.0f*(xx + zz);
    matrix[9] = 2.0f*(yz - wx);
    matrix[13] = 0.0;

    matrix[2] = 2.0f*(xz - wy);
    matrix[6] = 2.0f*(yz + wx);
    matrix[10] = 1.0f - 2.0f*(xx + yy);
    matrix[14] = 0.0;

    matrix[3] = 0;
    matrix[7] = 0;
    matrix[11] = 0;
    matrix[15] = 1;
}


Quaternion slerp::RotateAboutAxis(Point3D pt, double angle, Point3D axis)
{
    Quaternion q, p, qinv;

    q.w = cos(0.5*angle);
    q.u.x = sin(0.5*angle)*axis.x;
    q.u.y = sin(0.5*angle)*axis.y;
    q.u.z = sin(0.5*angle)*axis.z;

    p.w = 0;
    p.u = pt;

    qinv = q;
    qinv.Inverse();

    q.Multiply(p);
    q.Multiply(qinv);

    return q;
}


void slerp::Slerp(Quaternion q1, Quaternion q2, Quaternion &qr, double lambda)
{
    //float dotproduct = q1.u.x * q2.u.x + q1.u.y * q2.u.y + q1.u.z * q2.u.z + q1.w * q2.w;
    //float theta, st, sut, sout, coeff1, coeff2;

    //// algorithm adapted from Shoemake's paper
    //lambda = lambda / 2.0;

    //theta = (float)acos_(dotproduct);
    //if (theta < 0.0) theta = -theta;

    //st = (float)sin_(theta);
    //sut = (float)sin_(lambda*theta);
    //sout = (float)sin_((1 - lambda)*theta);
    //coeff1 = sout / st;
    //coeff2 = sut / st;

    //qr.u.x = coeff1*q1.u.x + coeff2*q2.u.x;
    //qr.u.y = coeff1*q1.u.y + coeff2*q2.u.y;
    //qr.u.z = coeff1*q1.u.z + coeff2*q2.u.z;
    //qr.w = coeff1*q1.w + coeff2*q2.w;

    //qr.Normalize();
}
void slerp::Slerp1(Quaternion v0, Quaternion v1, Quaternion &qr, double t) {
    // Only unit quaternions are valid rotations.
    // Normalize to avoid undefined behavior.
    v0.Normalize();
    v1.Normalize();

    // Compute the cosine of the angle between the two vectors.
    double dot = v0.u.x * v1.u.x + v0.u.y * v1.u.y + v0.u.z * v1.u.z + v0.w * v1.w; //dot_product(v0, v1);

    // If the dot product is negative, slerp won't take
    // the shorter path. Note that v1 and -v1 are equivalent when
    // the negation is applied to all four components. Fix by
    // reversing one quaternion.
    if (dot < 0.0f) {
        v1.u.x = -1 * v1.u.x;
        v1.u.y = -1 * v1.u.y;
        v1.u.z = -1 * v1.u.z;
        v1.w = -1 * v1.w;
        dot = -dot;
    }

    const double DOT_THRESHOLD = 0.9995;
    if (dot > DOT_THRESHOLD) {
        // If the inputs are too close for comfort, linearly interpolate
        // and normalize the result.

        qr.u.x = v0.u.x + t*(v1.u.x - v0.u.x);
        qr.u.y = v0.u.y + t*(v1.u.y - v0.u.y);
        qr.u.z = v0.u.z + t*(v1.u.z - v0.u.z);
        qr.w = v0.w + t*(v1.w - v0.w);
        qr.Normalize();
        return;
    }

    // Since dot is in range [0, DOT_THRESHOLD], acos is safe
    double theta_0 = acos(dot);        // theta_0 = angle between input vectors
    double theta = theta_0*t;          // theta = angle between v0 and result
    double sin_theta = sin(theta);     // compute this value only once
    double sin_theta_0 = sin(theta_0); // compute this value only once

    double s0 = cos(theta) - dot * sin_theta / sin_theta_0;  // == sin(theta_0 - theta) / sin(theta_0)
    double s1 = sin_theta / sin_theta_0;
    qr.u.x = (s0 * v0.u.x) + (s1 * v1.u.x);
    qr.u.y = (s0 * v0.u.y) + (s1 * v1.u.y);
    qr.u.z = (s0 * v0.u.z) + (s1 * v1.u.z);
    qr.w = (s0 * v0.w) + (s1 * v1.w);
}

void slerp::MultiplyPointMatrix(float m[16], Point3D p, Point3D& rotp)
{
    rotp.x = m[0] * p.x + m[1] * p.y + m[2] * p.z;
    rotp.y = m[4] * p.x + m[5] * p.y + m[6] * p.z;
    rotp.z = m[8] * p.x + m[9] * p.y + m[10] * p.z;
}
