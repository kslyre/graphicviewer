#ifndef BASEMODEL_H
#define BASEMODEL_H

#include <QList>
#include <QPoint>

class BaseModel
{
public:
    BaseModel();

    virtual void buildModel(QPointF, QPointF);
    virtual void setId(int);
protected:
    int id;

};

#endif // BASEMODEL_H
