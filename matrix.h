#ifndef MATRIX_H
#define MATRIX_H

#include <QVariant>
#include <QVector>
#include <QSize>

typedef QVector<double> vector;
typedef QVector<vector> matrix;

class Matrix
{
public:
    Matrix();
    Matrix(int, int);
    Matrix(int);

    matrix a;

    QSize getWH() const;
    Matrix operator +(const Matrix);
    Matrix operator +=(const Matrix);
    Matrix operator *(const Matrix);
    Matrix operator *=(const Matrix);


    void fillMatrix(matrix b);

    void clear();




    Matrix(int s, bool t);
    Matrix operator *(const int b);
private:
    int W,H;

    void init(int w, int h);
};

#endif // MATRIX_H
