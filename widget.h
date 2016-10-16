#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "calculation.h"


class Renderer;

class Widget : public QWidget
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
    void buildGraph();
    void generateGraph1();
    void generateGraph2();
    void customGraph();

    Renderer *renderer;
    //Calculation calc;
    QPoint oldMouse;
    bool initiated;
    int graphType;
};

#endif // WIDGET_H