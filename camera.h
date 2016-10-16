#ifndef CAMERA_H
#define CAMERA_H

#include <QPoint>
#include <QSize>


class Camera
{
public:
    Camera();

    QPoint axis;
    bool mouseIsPressed;

    void initWH(QSize);
    void setWH(int, int);
    QPoint getWH();
    QPoint getLR();
    QPoint toDisplay(QPoint);
    QPoint toCamera(QPoint);
    void recalcLRTB(double, double);
    void navigate(QPoint);
    void scale(QPoint, double);

private:
    int L=0, R=0, T=0, B=0, W=0, H=0;
    double Lx, Rx, Tx, Bx;
    // E- M
    // scale
};

#endif // CAMERA_H
