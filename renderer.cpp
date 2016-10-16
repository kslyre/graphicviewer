#include "renderer.h"

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <QtMath>

Renderer::Renderer()
{
    background = QBrush(Qt::white);
    axisPen = QPen(Qt::black);
    axisPen.setWidth(1);
    graphPen = QPen(Qt::blue);
    graphPen.setWidth(1);

    camera = Camera();
}

void Renderer::paint(QPainter *painter, QPaintEvent *event)
{
    painter->fillRect(event->rect(), background);
    painter->setPen(axisPen);
    QPoint axis = camera.toDisplay(camera.axis);
    painter->drawLine(QLine(0, axis.y(), camera.getWH().x(), axis.y()));    //x
    //painter->drawLine(QLine(axis.x()+50, axis.y()+5, axis.x()+50, axis.y()-5));
    painter->drawLine(QLine(axis.x(), 0, axis.x(), camera.getWH().y()));    //y

    /*painter->drawLine(QLine(camera.toDisplay(QPoint(0, camera.axis.y())),
                            camera.toDisplay(QPoint(camera.getWH().x(), camera.axis.y()))));
    painter->drawLine(QLine(camera.toDisplay(QPoint(camera.axis.x(), 0)),
                            camera.toDisplay(QPoint(camera.axis.x(), camera.getWH().y()))));*/

    painter->setPen(graphPen);
    for(int i=0; i < graph.count()-1; ++i)
    {
        painter->drawLine(camera.toDisplay(graph[i]), camera.toDisplay(graph[i+1]));
    }
}
