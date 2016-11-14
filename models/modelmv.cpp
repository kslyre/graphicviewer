#include "modelmv.h"

Model::Model()
{

}

Model::~Model()
{
    //model2d.reset();
}

void Model::reset()
{
    apexres = apex;
}

void Model::buildModel(QPointF lr, QPointF tb)
{

}

void Model::setId(int id)
{
    if(!edge.a.empty()) edge.clear();
    if(!apex.a.empty()) apex.clear();
    if(!apexres.a.empty()) apexres.clear();
    if(!affines.empty()) affines.clear();

    switch (id) {
    case 1:
        apex = Matrix(3,5);
        apex.fillMatrix(matrix({vector({1, 5, 5, 1, 3}),
                                vector({1, 1, 4, 4, 5.5}),
                                vector({1, 1, 1, 1, 1})
                               }));
        edge = Matrix(6,2);
        edge.fillMatrix(matrix({vector({0,1}),
                                vector({1,2}),
                                vector({0,3}),
                                vector({2,3}),
                                vector({2,4}),
                                vector({3,4})
                               }));
        apex = apex * 20;
        affres = Matrix(3,true);
        apexres = apex;

        break;
    default:
        break;
    }
}

void Model::pushAffine(Matrix am)
{
    affines.push(am);
}

void Model::applyAffines()
{
    Matrix aff = Matrix(3,true);
    while(affines.length() > 0)
    {
        aff = affines.pop() * aff;
    }
    affres = aff * affres;
    apexres = affres * apex;
}
