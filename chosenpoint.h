#ifndef CHOSENPOINT_H
#define CHOSENPOINT_H

#include <QObject>
#include <QPoint>

class ChosenPoint : public QObject
{
    Q_OBJECT

public:
    ChosenPoint();

    QPointF getPoint();
    int getIndex();
    void setPoint(QPointF, int);

signals:
    void pointIsChosen();

private:
    QPointF point;
    int index;      // point index in model
};

#endif // CHOSENPOINT_H
