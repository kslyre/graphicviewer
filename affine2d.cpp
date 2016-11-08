#include "affine2d.h"

Affine2D::Affine2D()
{
    aff2d = Matrix(3);
}

// filling Matrix using selected vectors
void Affine2D::affine(vector f, vector s)
{
    aff2d.fillMatrix(matrix({f,
                             s,
                             vector({0,0,1})
                            }));
}

// Transform
Matrix Affine2D::T(double x, double y)
{
    affine(vector({1,0,x}),
           vector({0,1,y}));

    return aff2d;
}

// Scale
Matrix Affine2D::S(double kx, double ky)
{
    kx = kx!=0 ? kx : 1;
    ky = ky!=0 ? ky : 1;

    affine(vector({kx,0,0}),
           vector({0,ky,0}));

    return aff2d;
}

// Mirror
Matrix Affine2D::M(double x, double y)
{
    x = x<0 ? -1: 1;
    y = y<0 ? -1: 1;

    S(x,y);

    return aff2d;
}

// Rotate (Angle)
Matrix Affine2D::R(double angle)
{
    double cos = qCos(angle*M_PI/180);
    double sin = qSin(angle*M_PI/180);

    return R(cos, sin);;
}

// Rotate (cos and sin)
Matrix Affine2D::R(double cos, double sin)
{
    affine(vector({cos,-sin,0}),
           vector({sin, cos,0}));

    return aff2d;
}
