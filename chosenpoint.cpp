#include "chosenpoint.h"

ChosenPoint::ChosenPoint()
{
    point = QPointF(0,0);
}

QPointF ChosenPoint::getPoint()
{
    return point;
}

int ChosenPoint::getIndex()
{
    return index;
}

void ChosenPoint::setPoint(QPointF p, int index)
{
    if(index > -1)
    {
        point = p;
    }
    pointIsChosen();
}


