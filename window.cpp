#include "widget.h"
#include "window.h"


Window::Window()
{
    setWindowTitle(tr("Model Viewer"));

    // === widgets
    Widget *drawidg = new Widget(&renderer, this);
    QPushButton *bgr1 = createButton("100sin()-30cos()");
    QPushButton *bgr2 = createButton("f(a)");

    QLabel *affineLabel = new QLabel(tr("Affine transformations:"));
    QPushButton *ba3 = createButton("- Reset- ");
    QPushButton *ba4 = createButton("T");
    QPushButton *ba5 = createButton("R");
    QPushButton *ba6 = createButton("M");
    QPushButton *ba7 = createButton("S");
    QPushButton *ba8 = createButton("Custom R");
    QPushButton *ba9 = createButton("Custom M");
    QPushButton *ba10 = createButton("Apply");

    QDoubleSpinBox *spinPoint1 = new QDoubleSpinBox;
    spinPoint1->setRange(-1000, 1000);
    spinPoint1->setDecimals(0);
    QDoubleSpinBox *spinPoint2 = new QDoubleSpinBox;
    spinPoint2->setRange(-1000, 1000);
    spinPoint2->setDecimals(0);
    QSpinBox *spinAngle = new QSpinBox;
    spinAngle->setRange(-359, 359);
    QCheckBox *checkX = new QCheckBox;
    checkX->setText("X");
    QCheckBox *checkY = new QCheckBox;
    checkY->setText("Y");
    QDoubleSpinBox *scaleX = new QDoubleSpinBox;
    scaleX->setRange(0.01, 10);
    scaleX->setValue(1);
    scaleX->setSingleStep(0.1);
    QDoubleSpinBox *scaleY = new QDoubleSpinBox;
    scaleY->setRange(0.01, 10);
    scaleY->setValue(1);
    scaleY->setSingleStep(0.1);
    // === END widgets


    // === signal-slots
    // update chosen point
    connect(drawidg->chPoint, &ChosenPoint::pointIsChosen,
            [=](){ spinPoint1->setValue(drawidg->chPoint->getPoint().x());
                   spinPoint2->setValue(drawidg->chPoint->getPoint().y());
                 });

    // setting affine parameters
    AffineParams *affparams = new AffineParams();
    connect(ba4, &QPushButton::clicked, [=](){ affparams->setT(spinPoint1->value(), spinPoint2->value()); });
    connect(ba5, &QPushButton::clicked, [=](){ affparams->setAngle(spinAngle->value()); });
    connect(ba6, &QPushButton::clicked, [=](){ affparams->setM(checkX->isChecked(), checkY->isChecked()); });
    connect(ba7, &QPushButton::clicked, [=](){ affparams->setScale(scaleX->value(), scaleY->value()); });
    connect(ba8, &QPushButton::clicked, [=](){ affparams->setT(spinPoint1->value(), spinPoint2->value());
                                               affparams->setAngle(spinAngle->value());
                                             });
    connect(ba9, &QPushButton::clicked, [=](){ affparams->setT(spinPoint1->value(), spinPoint2->value());
                                               affparams->setAngle(spinAngle->value());
                                               affparams->setM(checkX->isChecked(), checkY->isChecked());
                                             });

    // sending affParams and transformation type
    connect (ba4, &QPushButton::clicked, [=](){ drawidg->setAffine(affparams, TRANSFORM); });
    connect (ba5, &QPushButton::clicked, [=](){ drawidg->setAffine(affparams, ROTATE); });
    connect (ba6, &QPushButton::clicked, [=](){ drawidg->setAffine(affparams, MIRROR); });
    connect (ba7, &QPushButton::clicked, [=](){ drawidg->setAffine(affparams, SCALE); });
    connect (ba8, &QPushButton::clicked, [=](){ drawidg->setAffine(affparams, CUSTOM_R); });
    connect (ba9, &QPushButton::clicked, [=](){ drawidg->setAffine(affparams, CUSTOM_M); });
    connect (ba10, &QPushButton::clicked, [=](){ drawidg->setAffine(affparams, APPLY); });

    // setting models
    QSignalMapper* mapperModels = new QSignalMapper (this) ;
    connect(bgr1, SIGNAL(clicked(bool)), mapperModels, SLOT(map()));
    connect(bgr2, SIGNAL(clicked(bool)), mapperModels, SLOT(map()));
    connect(ba3, SIGNAL(clicked(bool)), mapperModels, SLOT(map()));
    mapperModels -> setMapping (bgr1, SIN_COS) ;
    mapperModels -> setMapping (bgr2, PARAMETRIC_1) ;
    mapperModels -> setMapping (ba3, HOME_MODEL) ;

    connect (mapperModels, SIGNAL(mapped(int)), drawidg, SLOT(setModel(int))) ;
    // === END signal-slots


    // layout for widgets
    QGridLayout *layout = new QGridLayout;
    layout->addWidget(drawidg, 0, 0, 30, 1);
    layout->addWidget(bgr1,0,1, 1,3);
    layout->addWidget(bgr2,1,1, 1,3);
    layout->addWidget(affineLabel, 2,1, 1,3, Qt::AlignCenter);
    layout->addWidget(ba3, 3,1, 1,3);
    layout->addWidget(ba4, 5,1, Qt::AlignTop | Qt::AlignRight);
    layout->addWidget(spinPoint1, 5, 2);
    layout->addWidget(spinPoint2, 5, 3);
    layout->addWidget(ba5, 6,1, Qt::AlignTop | Qt::AlignRight);
    layout->addWidget(spinAngle, 6, 2, 1,2);
    layout->addWidget(ba6, 7,1, Qt::AlignTop | Qt::AlignRight);
    layout->addWidget(checkX, 7, 2);
    layout->addWidget(checkY, 7, 3);
    layout->addWidget(ba7, 8,1, Qt::AlignTop | Qt::AlignRight);
    layout->addWidget(scaleX, 8,2, 1,1);
    layout->addWidget(scaleY, 8,3, 1,1);
    layout->addWidget(ba8,  9,1,  1,3);
    layout->addWidget(ba9,  10,1,  1,3);
    layout->addWidget(ba10, 12,1, 1,3);

    layout->setColumnStretch(0, 70);
    layout->setColumnStretch(1, 1);
    setLayout(layout);

    this->resize(900, 800);

    //QTimer *timer = new QTimer(this);
    //connect(timer, &QTimer::timeout, native, &Widget::animate);
    //timer->start(60);
}

QPushButton* Window::createButton(QString text)
{
    QPushButton* b = new QPushButton;
    b->setText(text);
    b->setMinimumSize(60,40);

    return b;
}

