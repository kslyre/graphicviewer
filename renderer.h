#ifndef RENDERER_H
#define RENDERER_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>
#include <models/basemodel.h>
#include "camera.h"
#include "affine2d.h"

class Renderer
{
public:
    Renderer();
    Camera camera;
    //QList<QPointF> graph;
    BaseModel *model;

public:
    void paint(QPainter *painter, QPaintEvent *event);
    void chooseAction(int);

private:
    QBrush background;
    QPen axisPen;
    QPen graphPen;
};

#endif // RENDERER_H
