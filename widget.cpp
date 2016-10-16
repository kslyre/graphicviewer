#include "widget.h"
#include "renderer.h"

#include <QMouseEvent>
#include <QWheelEvent>
#include <QPainter>
#include <QtMath>
#include <QTimer>

Widget::Widget(Renderer *renderer, QWidget *parent)
    : QWidget(parent), renderer(renderer)
{
    initiated = false;
    this->setMinimumSize(QSize(30, 30));
    graphType = 1;
    //calc = Calculation();
}

void Widget::setGraphFunc(int t)
{
    graphType = t;
    this->update();
}


void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    //renderer->graph = generateGraph1();
    //generateGraph1();
    buildGraph();
    renderer->paint(&painter, event);
    painter.end();
}

void Widget::resizeEvent(QResizeEvent *event)
{
    QPoint wh = renderer->camera.getWH();
    renderer->camera.setWH(this->size().width(), this->size().height());
    if(wh.x() > 0 & wh.y() > 0)
        renderer->camera.recalcLRTB((double)renderer->camera.getWH().x()/(double)wh.x(), (double)renderer->camera.getWH().y()/(double)wh.y());
    //renderer->camera.navigate(renderer->camera.getWH() - wh);
    if(!initiated)
    {
        renderer->camera.initWH(this->size());
        initiated = true;
    }
    this->update();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(renderer->camera.mouseIsPressed)
    {
        QPoint curMouse = this->mapFromGlobal(QCursor::pos());
        QPoint dp = curMouse - oldMouse;
        renderer->camera.navigate(dp);
        oldMouse = curMouse;
        this->update();
    }
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
        renderer->camera.mouseIsPressed = true;
        oldMouse = this->mapFromGlobal(QCursor::pos());
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
        renderer->camera.mouseIsPressed = false;
}

void Widget::wheelEvent(QWheelEvent *event)
{
    QPoint angle = event->angleDelta();
    renderer->camera.scale(this->mapFromGlobal(QCursor::pos()), angle.y() > 0 ? 105./100. : 100./105.);
    //renderer->camera.navigate(angle);
    this->update();
}

void Widget::buildGraph()
{
    switch (graphType) {
    case 1:
        generateGraph1();
        break;
    case 2:
        generateGraph2();
        break;
    case 3:
        customGraph();
        break;
    default:
        break;
    }
}

void Widget::generateGraph1()
{
    renderer->graph.clear();
    QPoint lr = renderer->camera.getLR();
    if(lr.x() != lr.y())
    for(int i=lr.x(); i < lr.y(); i++)
    {
        renderer->graph.append(QPoint(i, 100*qSin(i*M_PI/180)-30*qCos(i*M_PI/45))); //qDegreesToRadians(M_PI))));
    }
}

void Widget::generateGraph2()
{
    renderer->graph.clear();
    for(int i=0; i < 240*M_PI; i++)
    {
        double pi = i*M_PI/45;
        double r = qExp(qCos(pi))-2*qCos(4*pi)+qPow(qSin(1./12.*pi),5);
        renderer->graph.append(QPoint(100*qSin(pi)*r, 100*qCos(pi)*r));
    }
}

void Widget::customGraph()
{
    renderer->graph.clear();
    renderer->graph.append(QPoint(10, 10));
    renderer->graph.append(QPoint(10, 30));
    renderer->graph.append(QPoint(5, 30));
    renderer->graph.append(QPoint(35, 50));
    renderer->graph.append(QPoint(65, 30));
    renderer->graph.append(QPoint(60, 30));
    renderer->graph.append(QPoint(60, 10));
    renderer->graph.append(QPoint(10, 10));
    for(int i=0;i<renderer->graph.size();++i)
    {
        renderer->graph[i] *= 3;
    }


    //renderer->graph.append(QPoint(,));
}


