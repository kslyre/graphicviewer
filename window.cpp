#include "widget.h"
#include "window.h"

#include <QGridLayout>
#include <QLabel>
#include <QSignalMapper>
#include <QTimer>

Window::Window()
{
    setWindowTitle(tr("2D graph"));

    Widget *drawidg = new Widget(&renderer, this);
    QPushButton *bgr1 = createButton("100sin()-30cos()");
    QPushButton *bgr2 = createButton("f(a)");

    QLabel *affineLabel = new QLabel(tr("Affine transformations:"));
    QPushButton *ba3 = createButton("- Reset- ");
    QPushButton *ba4 = createButton("T");
    QPushButton *ba5 = createButton("R");
    QPushButton *ba6 = createButton("M");
    QPushButton *ba7 = createButton("S");
    QPushButton *ba8 = createButton("Custom");
    QPushButton *ba10 = createButton("Apply");


    QSignalMapper* signalMapper = new QSignalMapper (this) ;
    connect(bgr1, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
    connect(bgr2, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
    connect(ba3, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
    connect(ba4, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
    connect(ba5, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
    connect(ba6, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
    connect(ba7, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
    connect(ba8, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
    connect(ba10, SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
    signalMapper -> setMapping (bgr1, 1) ;
    signalMapper -> setMapping (bgr2, 2) ;
    signalMapper -> setMapping (ba3, 3) ;
    signalMapper -> setMapping (ba4, 4) ;
    signalMapper -> setMapping (ba5, 5) ;
    signalMapper -> setMapping (ba6, 6) ;
    signalMapper -> setMapping (ba7, 7) ;
    signalMapper -> setMapping (ba8, 8) ;
    signalMapper -> setMapping (ba10, 10) ;

    connect (signalMapper, SIGNAL(mapped(int)), drawidg, SLOT(setGraphFunc(int))) ;



    QGridLayout *layout = new QGridLayout;
    layout->addWidget(drawidg, 0, 0, 30, 1);
    layout->addWidget(bgr1,0,1);
    layout->addWidget(bgr2,1,1);
    layout->addWidget(affineLabel, 2,1, Qt::AlignTop | Qt::AlignRight);
    layout->addWidget(ba3, 3,1, Qt::AlignTop | Qt::AlignRight);
    layout->addWidget(ba4, 5,1, Qt::AlignTop | Qt::AlignRight);
    layout->addWidget(ba5, 6,1, Qt::AlignTop | Qt::AlignRight);
    layout->addWidget(ba6, 7,1, Qt::AlignTop | Qt::AlignRight);
    layout->addWidget(ba7, 8,1, Qt::AlignTop | Qt::AlignRight);
    layout->addWidget(ba8, 9,1, Qt::AlignTop | Qt::AlignRight);
    layout->addWidget(ba10, 11,1, Qt::AlignTop | Qt::AlignRight);

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
    b->setMinimumSize(140,40);

    return b;
}
