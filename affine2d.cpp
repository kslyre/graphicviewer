#include "affine2d.h"

Affine2D::Affine2D()
{
    aff2d = Matrix(3);
}

void Affine2D::affine(vector f, vector s)
{
    aff2d.fillMatrix(matrix({f,
                             s,
                             vector({0,0,1})
                            }));
}

Matrix Affine2D::T(double x, double y)
{
    affine(vector({1,0,x}),
           vector({0,1,y}));

    return aff2d;
}

Matrix Affine2D::S(double kx, double ky)
{
    kx = kx!=0 ? kx : 1;
    ky = ky!=0 ? ky : 1;

    affine(vector({kx,0,0}),
           vector({0,ky,0}));

    return aff2d;
}

Matrix Affine2D::M(double x, double y)
{
    x = x<0 ? x: -x;
    y = y<0 ? y: -y;

    S(x,y);

    return aff2d;
}

Matrix Affine2D::R(double angle)
{
    double cos = qCos(angle*M_PI/180);
    double sin = qSin(angle*M_PI/180);
    affine(vector({cos,-sin,0}),
           vector({sin, cos,0}));

    return aff2d;
}
