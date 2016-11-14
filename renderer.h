#ifndef RENDERER_H
#define RENDERER_H

#include <QBrush>
#include <QFont>
#include <QPen>
#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <QtMath>
#include "camera.h"
#include <models/basemodel.h>
#include <models/graphicmv.h>
#include <models/modelmv.h>


class Renderer
{
public:
    Renderer();

    Camera camera;
    QVector<BaseModel*> model;

public:
    void paint(QPainter *painter, QPaintEvent *event);

private:
    QBrush background;
    QPen axisPen;
    QPen graphPen;
};

#endif // RENDERER_H
