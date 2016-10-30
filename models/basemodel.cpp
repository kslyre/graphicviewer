#include "basemodel.h"

BaseModel::BaseModel()
{
    id = 1;
}

void BaseModel::buildModel(QPointF, QPointF)
{

}

void BaseModel::setId(int id)
{
    this->id = id;
}
