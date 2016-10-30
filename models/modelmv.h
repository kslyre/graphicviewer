#ifndef MODEL_H
#define MODEL_H

#include "basemodel.h"
#include <matrix.h>
#include "affine2d.h"
#include <QStack>

class Model : public BaseModel
{
public:
    Model();
    ~Model();

    void buildModel(QPointF, QPointF) override;

    Matrix apex, apexres;
    Matrix edge;
    QStack<Matrix> affines;
    void reset();
    void setId(int id) override;
    void pushAffine(Matrix am);
    void applyAffines();
};

#endif // MODEL_H
