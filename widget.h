#ifndef WIDGET_H
#define WIDGET_H

#include <QOpenGLWidget>
#include "matrices.h"


class Renderer;

class Widget : public QOpenGLWidget
{
    Q_OBJECT

public:
    Widget(Renderer *renderer, QWidget *parent);


public slots:
    void setGraphFunc(int); //void (*f_func)());

protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;
    void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
    void wheelEvent(QWheelEvent *event);

private:
    //typedef void (*buildGraph)(void);
    void chooseModel();
    void generateGraph1();
    void generateGraph2();
    void customGraph();

    Renderer *renderer;
    //Calculation calc;
    QPointF oldMouse;
    bool initiated;
    int graphType;
};

#endif // WIDGET_H
