#include "graphicmv.h"

Graphic::Graphic()
{

}

Graphic::Graphic(int id)
{
    setId(id);
}

Graphic::~Graphic()
{
    data.clear();
}

void Graphic::buildModel(QPointF lr, QPointF tb)    // parameters for model borders. unused
{
    data.clear();
    switch (this->id) {
    case SIN_COS:
        if(lr.x() != lr.y())
        for(int i=lr.x(); i < lr.y(); i++)
        {
            data.append(QPointF(i, 100*qSin(i*M_PI/180)-30*qCos(i*M_PI/45)));
        }
        break;
    case PARAMETRIC_1:
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
