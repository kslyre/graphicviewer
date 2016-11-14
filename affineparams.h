#ifndef AFFINEPARAMS_H
#define AFFINEPARAMS_H

#include <QObject>

class AffineParams : public QObject
{
    Q_OBJECT

public:
    AffineParams(QObject *parent = 0);

    void setParams(double Tx, double Ty, double angle, bool x, bool y, double scaleX, double scaleY);

    void setAngle(double angle);
    void setM(bool x, bool y);
    void setScale(double scaleX, double scaleY);

    double Tx, Ty, Tz;
    double angle, angleX, angleY;
    bool x,y,z;
    double scaleX, scaleY, scaleZ;
public slots:
    void setT(double, double);

private:


};

#endif // AFFINEPARAMS_H
