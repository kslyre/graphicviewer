#include "affine3d.h"

Affine3D::Affine3D()
{
    aff3d = Matrix(4);
}

void Affine3D::affine(vector v1, vector v2, vector v3)
{
    aff3d.fillMatrix(matrix({v1,
                             v2,
                             v3,
                             vector({0,0,0,1})
                            }));
}

Matrix Affine3D::T(double x, double y, double z)
{
    affine(vector({1,0,0,x}),
           vector({0,1,0,y}),
           vector({0,0,1,z}));

    return aff3d;
}

Matrix Affine3D::S(double kx, double ky, double kz)
{
    kx = kx!=0 ? kx : 1;
    ky = ky!=0 ? ky : 1;
    ky = ky!=0 ? ky : 1;

    affine(vector({kx,0,0,0}),
           vector({0,ky,0,0}),
           vector({0,0,kz,0}));

    return aff3d;
}

Matrix Affine3D::M(double x, double y, double z)
{
    x = x<0 ? x: -x;
    y = y<0 ? y: -y;
    z = z<0 ? z: -z;

    S(x,y,z);

    return aff3d;
}

Matrix Affine3D::R(double angle, char c)
{
    double cos = qCos(angle*M_PI/180);
    double sin = qSin(angle*M_PI/180);

    switch (c) {
    case 'x':

        break;
    case 'y':

        break;
    case 'z':
        affine(vector({cos,-sin,0,0}),
               vector({sin, cos,0,0}),
               vector({0,   0,  1,0}));
        break;
    default:
        break;
    }

    return aff3d;
}



