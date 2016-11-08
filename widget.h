#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>
#include "affine2d.h"
#include <models/basemodel.h>
#include <models/graphicmv.h>
#include <models/modelmv.h>
#include "typeEnums.h"
#include "affineparams.h"
#include "chosenpoint.h"
#include <QtMath>

class Renderer;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(Renderer *renderer, QWidget *parent);

    void setAffine(AffineParams*, AffineTypes);

    ChosenPoint *chPoint;

public slots:
    void setModel(int);

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void wheelEvent(QWheelEvent *event);

private:
    Renderer *renderer;
    QPointF oldMouse;
    bool initiated;

};

#endif // WIDGET_H
