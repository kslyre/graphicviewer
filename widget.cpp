#include "widget.h"
#include "renderer.h"

#include <QMouseEvent>
#include <QWheelEvent>
#include <QPainter>
#include <QTimer>

Widget::Widget(Renderer *renderer, QWidget *parent)
    : QWidget(parent), renderer(renderer)
{
    initiated = false;
    this->setMinimumSize(QSize(30, 30));
    setAutoFillBackground(false);
    setGraphFunc(1);
}

void Widget::setGraphFunc(int t)
{
    renderer->chooseAction(t);
    this->update();
}


void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    renderer->model->buildModel(renderer->camera.getLR(), renderer->camera.getTB());
    renderer->paint(&painter, event);
    painter.end();
}

void Widget::resizeEvent(QResizeEvent *event)
{
    renderer->camera.setWH(event->size());
    renderer->camera.recalcLRTB(event->oldSize());

    if(!initiated)
    {
        renderer->camera.initWH(event->size());
        initiated = true;
    }
    this->update();
}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    if(renderer->camera.mouseIsPressed)
    {
        QPointF curMouse = event->pos();
        QPointF dp = curMouse - oldMouse;
        renderer->camera.navigate(dp);
        oldMouse = curMouse;
        this->update();
    }
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
        renderer->camera.mouseIsPressed = true;
        oldMouse = event->pos();
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
        renderer->camera.mouseIsPressed = false;
}

void Widget::wheelEvent(QWheelEvent *event)
{
    QPointF angle = event->angleDelta();
    renderer->camera.scale(event->pos(), angle.y() > 0 ? 105./100. : 100./105.);
    this->update();
}
