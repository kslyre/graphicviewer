#include "modelmv.h"

Model::Model()
{

}

Model::Model(int id)
{
    setId(id);
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
    if(!edge.a.empty()) edge.deleteMatrix();
    if(!apex.a.empty()) apex.deleteMatrix();
    if(!apexres.a.empty()) apexres.deleteMatrix();
    if(!affres.a.empty()) affres.deleteMatrix();
    if(!affines.empty()) affines.clear();

    switch (id) {
    case HOME_MODEL:
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
        apexres = apex;

        break;
    case HOME_LINE:
        apex = Matrix(3,2);
        apex.fillMatrix(matrix({vector({-3, 3}),
                                vector({-3, 10}),
                                vector({1, 1})
                               }));
        edge = Matrix(1,2);
        edge.fillMatrix(matrix({vector({0,1})
                               }));
        apex = apex * 20;
        apexres = apex;
        break;
    case HOME3D:
        apex = Matrix(4,5);
        apex.fillMatrix(matrix({vector({1, 5, 5, 1, 3}),
                                vector({1, 1, 4, 4, 5.5}),
                                vector({1, 2, 3, 4, 5}),
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
    affres = aff;
    apexres = affres * apexres;
}

int Model::findClosest(QPointF m, double sc)
{
    int index = -1;
    int max = 10*sc;
    QPointF p = QPointF(0,0);
    for(int i=0; i<apexres.a[0].length(); i++)
    {
        p.setX(apexres.a[0][i]);
        p.setY(apexres.a[1][i]);
        if(((m.x()-p.x())*(m.x()-p.x()) + (m.y()-p.y())*(m.y()-p.y())) < max*max)
        {
            index = i;
            break;
        }
    }
    return index;
}
