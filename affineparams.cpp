#include "affineparams.h"


AffineParams::AffineParams(QObject *parent) : QObject(parent)
{
    /*Tx=Ty=Tz=0;
    angle=angleX=angleY=0;
    x=y=z=false;
    scaleX=scaleY=scaleZ=0;*/
}

void AffineParams::setParams(double Tx, double Ty, double angle, bool x, bool y, double scaleX, double scaleY)
{
    this->Tx = Tx;
    this->Ty = Ty;
    this->angle = angle;
    this->x = x;
    this->y = y;
    this->scaleX = scaleX;
    this->scaleY = scaleY;
}

void AffineParams::setT(double Tx, double Ty)
{
    this->Tx = Tx;
    this->Ty = Ty;
}

void AffineParams::setAngle(double angle)
{
    this->angle = angle;
}

void AffineParams::setM(bool x, bool y)
{
    this->x = x;
    this->y = y;
}

void AffineParams::setScale(double scaleX, double scaleY)
{
    this->scaleX = scaleX;
    this->scaleY = scaleY;
}
