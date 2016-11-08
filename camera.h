#ifndef CAMERA_H
#define CAMERA_H

#include <QPoint>
#include <QSize>


class Camera
{
public:
    Camera();

    QPointF axis;
    bool mouseIsPressed;

    void initWH(QSize);
    void setWH(QSize);
    QPointF getWH();
    QPointF getLR();
    QPointF getTB();
    double getScale();
    QPointF toDisplay(QPointF);
    QPointF toCamera(QPointF);
    void recalcLRTB(QSize);
    void navigate(QPointF);
    void scale(QPointF, double);

private:
    double L=0, R=0, T=0, B=0, W=0, H=0;

};

#endif // CAMERA_H
