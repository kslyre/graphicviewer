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
    chPoint = new ChosenPoint();
    setAutoFillBackground(false);
    setModel(SIN_COS);              // default model
}

void Widget::setModel(int type)
{
    switch (type) {
    case SIN_COS:
    case PARAMETRIC_1:
        renderer->model.clear();
        renderer->model.append(new Graphic(type));
        break;
    case HOME_MODEL:
        renderer->model.clear();
        renderer->model.append(new Model(HOME_MODEL));
        renderer->model.append(new Model(HOME_LINE));
        break;
    default:
        break;
    }

    this->update();
}

void Widget::setAffine(AffineParams *p,  AffineTypes type)
{
    if(Model *m = dynamic_cast<Model*>(renderer->model[0]))
    {
    switch (type) {
    case TRANSFORM:
        m->pushAffine(Affine2D().T(p->Tx, p->Ty));
        break;
    case ROTATE:
        m->pushAffine(Affine2D().R(p->angle));
        break;
    case MIRROR:
        m->pushAffine(Affine2D().M(p->x?-1:1, p->y?-1:1));
        break;
    case SCALE:
        m->pushAffine(Affine2D().S(p->scaleX, p->scaleY));
        break;
    case CUSTOM_R:
        m->pushAffine(Affine2D().T(p->Tx, p->Ty));
        m->pushAffine(Affine2D().R(p->angle));
        m->pushAffine(Affine2D().T(-p->Tx,-p->Ty));
        break;
    case CUSTOM_M:
        if(Model *m2 = dynamic_cast<Model*>(renderer->model[1]))
        {
            // get vector coords
            QPointF xy1 = QPointF(m2->apexres.a[0][0], m2->apexres.a[1][0]);
            QPointF xy2 = QPointF(m2->apexres.a[0][1], m2->apexres.a[1][1]);
            // result vector
            QPointF ab = xy2 - xy1;
            double cos = ab.x()/(qSqrt(qPow(ab.x(),2) + qPow(ab.y(), 2)));
            double sin = ab.y()/(qSqrt(qPow(ab.x(),2) + qPow(ab.y(), 2)));
            m->pushAffine(Affine2D().T(xy1.x(), xy1.y()));
            m->pushAffine(Affine2D().R(cos, sin));
            m->pushAffine(Affine2D().M(1, -1));
            m->pushAffine(Affine2D().R(cos, -sin));
            m->pushAffine(Affine2D().T(-xy1.x(), -xy1.y()));
        }
        break;
    case APPLY:
        m->applyAffines();
        break;
    default:
        break;
    }

    this->update();
    }
}


void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);
    foreach (BaseModel* mdl, renderer->model) {
        mdl->buildModel(renderer->camera.getLR(), renderer->camera.getTB());
    }
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
    if(event->button() == Qt::LeftButton)
    {
        if(Model *md = dynamic_cast<Model*>(renderer->model[0]))
        {
            int ind = md->findClosest(renderer->camera.toCamera(event->pos()), renderer->camera.getScale());
            if(ind > -1)
            {
                chPoint->setPoint(QPointF(md->apexres.a[0][ind], md->apexres.a[1][ind]), ind);
            }
        }
    }

    if(event->button() == Qt::RightButton)
    {
        renderer->camera.mouseIsPressed = true;
        oldMouse = event->pos();
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
    {
        renderer->camera.mouseIsPressed = false;
    }
}

void Widget::wheelEvent(QWheelEvent *event)
{
    QPointF angle = event->angleDelta();
    renderer->camera.scale(event->pos(), angle.y() > 0 ? 105./100. : 100./105.);
    this->update();
}
