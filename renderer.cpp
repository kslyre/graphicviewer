#include "renderer.h"

#include <QPainter>
#include <QPaintEvent>
#include <QWidget>
#include <QtMath>

#include <models/graphicmv.h>
#include <models/modelmv.h>

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
    painter->drawLine(QLine(0, axis.y(), camera.getWH().x(), axis.y()));    //x
    painter->drawLine(QLine(axis.x(), 0, axis.x(), camera.getWH().y()));    //y


    painter->setPen(graphPen);


    if(Graphic *gr = dynamic_cast<Graphic*>(model))
    {
        for(int i=0; i < gr->data.count()-1; ++i)
            {
                painter->drawLine(camera.toDisplay(gr->data[i]), camera.toDisplay(gr->data[i+1]));
            }
    }
    if(Model *md = dynamic_cast<Model*>(model))
    {
        for(int i=0; i< md->edge.a.length(); i++)
        {
            int ia = md->edge.a[i][0]; // индексы для извлечения координат точек
            int ib = md->edge.a[i][1];
            QPoint a = QPoint(md->apexres.a[0][ia], md->apexres.a[1][ia]);
            QPoint b = QPoint(md->apexres.a[0][ib], md->apexres.a[1][ib]);
            painter->drawLine(camera.toDisplay(a), camera.toDisplay(b));
        }
    }




    QString s = "%1 %2";
    painter->drawText(10,10, s.arg(camera.getLR().x()).arg(camera.getLR().y()));
}

void Renderer::chooseAction(int type)
{
    switch (type) {
    case 1:
        model = new Graphic();
        model->setId(1);
        break;
    case 2:
        model = new Graphic();
        model->setId(2);
        break;
    case 3:
        model = new Model();
        model->setId(1);
        break;
    case 4:
        dynamic_cast<Model*>(model)->pushAffine(Affine2D().T(40,40));
        break;
    case 5:
        dynamic_cast<Model*>(model)->pushAffine(Affine2D().R(90));
        break;
    case 6:
        dynamic_cast<Model*>(model)->pushAffine(Affine2D().M(1,-1));
        break;
    case 7:
        dynamic_cast<Model*>(model)->pushAffine(Affine2D().S(1.2,1.2));
        break;
    case 8:
        dynamic_cast<Model*>(model)->pushAffine(Affine2D().T(20,20));
        dynamic_cast<Model*>(model)->pushAffine(Affine2D().R(30));
        dynamic_cast<Model*>(model)->pushAffine(Affine2D().T(-20,-20));
        // rotate a,b
        // поворот на угол cos alp = A/sqta2+b2
        // поворот относ ребра
        /*dynamic_cast<Model*>(model)->pushAffine(Affine2D().T(-20,0));
        dynamic_cast<Model*>(model)->pushAffine(Affine2D().R(-45));
        dynamic_cast<Model*>(model)->pushAffine(Affine2D().M(-1,1));
        dynamic_cast<Model*>(model)->pushAffine(Affine2D().R(45));
        dynamic_cast<Model*>(model)->pushAffine(Affine2D().T(20,0));*/
        break;
    case 10:
        dynamic_cast<Model*>(model)->applyAffines();
        break;
    default:
        break;
    }

}
