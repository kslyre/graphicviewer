#ifndef AFFINE3D_H
#define AFFINE3D_H

#include "matrix.h"
#include "QtMath"

class Affine3D : public Matrix
{
public:
    Affine3D();

    Matrix T(double x, double y, double z);
    Matrix S(double kx, double ky, double kz);
    Matrix M(double x, double y, double z);
    Matrix R(double a, char c);

private:
    Matrix aff3d;

    void affine(vector v1, vector v2, vector v3);
};

#endif // AFFINE3D_H
