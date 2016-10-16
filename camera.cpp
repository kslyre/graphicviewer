#include "camera.h"

#include <QDebug>

Camera::Camera()
{
    axis = QPoint(0, 0);
    mouseIsPressed = false;

    L=Lx=-0.0; R=Rx=-Lx;
    T=Tx=0.0; B=Bx=-Tx;
}

void Camera::initWH(QSize s)
{
    L=Lx= -s.width()/2; R=Rx=-Lx;
    T=Tx= s.height()/2; B=Bx=-Tx;
}

void Camera::setWH(int x, int y)
{
    W = x;
    H = y;
}

QPoint Camera::getWH()
{
    return QPoint(W, H);
}

QPoint Camera::getLR()
{
    return QPoint(L, R);
}

QPoint Camera::toDisplay(QPoint p)
{
    //qInfo() << t.x() << " " << t.y();
    return QPoint((float)(p.x()-L)/(float)(R-L)*W,
                  (float)(T-p.y())/(float)(T-B)*H);
}

QPoint Camera::toCamera(QPoint p)
{
    return QPoint(L+(R-L)*(p.x()+0.5)/W, T-(T-B)*(p.y()+0.5)/H);
}

void Camera::recalcLRTB(double w, double h)
{
    L=Lx *= w;
    R=Rx *= w;
    T=Tx *= h;
    B=Bx *= h;
    //qInfo() << L << " " << R;
}

void Camera::navigate(QPoint dp)
{
    L=Lx -= (Rx-Lx)*(double)dp.x()/(double)W;
    R=Rx -= (Rx-Lx)*(double)dp.x()/(double)W;
    T=Tx += (Tx-Bx)*(double)dp.y()/(double)H;
    B=Bx += (Tx-Bx)*(double)dp.y()/(double)H;
}

void Camera::scale(QPoint p, double k)
{
    QPoint dp = toCamera(p);
    L=Lx = dp.x() - (double)(dp.x() - Lx)/k;
    R=Rx = dp.x() - (double)(dp.x() - Rx)/k;
    T=Tx = dp.y() + (double)(Tx - dp.y())/k;
    B=Bx = dp.y() + (double)(Bx - dp.y())/k;
}

