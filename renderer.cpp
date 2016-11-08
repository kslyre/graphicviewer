#include "renderer.h"



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
    QPointF axis = camera.toDisplay(camera.axis);
    painter->drawLine(QLine(0, axis.y(), camera.getWH().x(), axis.y()));    //x axis
    painter->drawLine(QLine(axis.x(), 0, axis.x(), camera.getWH().y()));    //y axis

    painter->setPen(graphPen);

    foreach (BaseModel* mdl, model)
    {
        if(Graphic *gr = dynamic_cast<Graphic*>(mdl))
        {
            for(int i=0; i < gr->data.count()-1; ++i)
                {
                    painter->drawLine(camera.toDisplay(gr->data[i]), camera.toDisplay(gr->data[i+1]));
                }
        }
        if(Model *md = dynamic_cast<Model*>(mdl))
        {
            for(int i=0; i< md->edge.a.length(); i++)
            {
                int ia = md->edge.a[i][0]; // индексы для извлечения координат точек
                int ib = md->edge.a[i][1];
                if(md->apexres.getWH().height() == 3)
                {
                    painter->drawLine(camera.toDisplay(QPoint(md->apexres.a[0][ia], md->apexres.a[1][ia])),
                                      camera.toDisplay(QPoint(md->apexres.a[0][ib], md->apexres.a[1][ib])));
                }
                else
                {
                    //QPoint a = QPoint(md->apexres.a[0][ia], md->apexres.a[1][ia]);
                }
            }
        }
    }

    QString s = "%1 %2 %3";
    painter->drawText(10,10, s.arg(camera.getLR().x()).arg(camera.getLR().y()).arg(0));
}
