#include "graphicmv.h"

Graphic::Graphic()
{

}

Graphic::~Graphic()
{
    data.clear();
}

void Graphic::buildModel(QPointF lr, QPointF tb)
{
    data.clear();
    switch (this->id) {
    case 1:
        if(lr.x() != lr.y())
        for(int i=lr.x(); i < lr.y(); i++)
        {
            data.append(QPointF(i, 100*qSin(i*M_PI/180)-30*qCos(i*M_PI/45)));
        }
        break;
    case 2:
        for(int i=0; i < 240*M_PI; i++)
        {
            double pi = i*M_PI/45;
            double r = qExp(qCos(pi))-2*qCos(4*pi)+qPow(qSin(1./12.*pi),5);
            data.append(QPointF(100*qSin(pi)*r, 100*qCos(pi)*r));
        }
        break;
    default:
        break;
    }
}
