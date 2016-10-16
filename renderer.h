#ifndef RENDERER_H
#define RENDERER_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>
#include "camera.h"

class Renderer
{
public:
    Renderer();
    Camera camera;
    QList<QPoint> graph;

public:
    void paint(QPainter *painter, QPaintEvent *event);

private:
    QBrush background;
    QPen axisPen;
    QPen graphPen;
};

#endif // RENDERER_H
