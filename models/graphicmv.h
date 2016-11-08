#ifndef GRAPHIC_H
#define GRAPHIC_H

#include "basemodel.h"

#include <QPoint>
#include <QtMath>

class Graphic : public BaseModel
{
public:
    Graphic();
    Graphic(int);
    ~Graphic();

    void buildModel(QPointF, QPointF) override;

    QList<QPointF> data;
};

#endif // GRAPHIC_H
