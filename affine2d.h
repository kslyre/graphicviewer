#ifndef AFFINE2D_H
#define AFFINE2D_H

#include "matrix.h"
#include "QtMath"

class Affine2D : public Matrix
{
public:
    Affine2D();

    Matrix T(double x, double y);
    Matrix S(double kx, double ky);
    Matrix M(double, double);
    Matrix R(double angle);
    Matrix R(double cos, double sin);
private:
    Matrix aff2d;

    void affine(vector, vector);
};

#endif // AFFINE2D_H
