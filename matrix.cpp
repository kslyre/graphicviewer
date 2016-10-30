#include "matrix.h"

Matrix::Matrix()
{

}

Matrix::Matrix(int h, int w)
{
    init(h, w);
}

Matrix::Matrix(int s)
{
    init(s,s);
}

Matrix::Matrix(int s, bool t)
{
    init(s,s);
    for(int i=0;i<s;i++)
        for(int j=0;j<s;j++)
            if(i==j)
                a[i][j] = 1;
            else
                a[i][j] = 0;
}

void Matrix::init(int h, int w)
{
    a = matrix(h);
    for(int i=0;i<h;i++)
        a[i] = vector(w);

    W = w;
    H = h;
}

void Matrix::clear()
{
    for(int i=0; i<H; i++)
        a[H].clear();
    a.clear();
}

void Matrix::fillMatrix(matrix b)
{
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            a[i][j] = b[i][j];
}

QSize Matrix::getWH() const
{
    return QSize(W,H);
}

Matrix Matrix::operator +(const Matrix b)
{
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            a[i][j] += b.a[i][j];
    return *this;
}

Matrix Matrix::operator +=(const Matrix b)
{

}

Matrix Matrix::operator *(const Matrix b)
{
    /*Matrix c = Matrix(H, b.getWH().width());
    int h = b.getWH().height();

    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < h; j++)
        {
            for (int inner = 0; inner < H; inner++)
            {
                c.a[i][j] = c.a[i][j] + a[i][inner] * b.a[inner][j];
            }
        }
    }*/
    int w = b.getWH().width();
    Matrix c = Matrix(H, w);
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < w; j++)
        {
            for (int inner = 0; inner < W; inner++)
            {
                c.a[i][j] = c.a[i][j] + a[i][inner] * b.a[inner][j];
            }
        }
    }
    return c;
}

Matrix Matrix::operator *(const int b)
{
    for (int i = 0; i < H-1; i++)
    {
        for (int j = 0; j < W; j++)
        {
            a[i][j] *= b;
        }
    }
    return *this;
}

Matrix Matrix::operator *=(const Matrix b)
{

}
