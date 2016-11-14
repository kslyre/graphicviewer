#ifndef WINDOW_H
#define WINDOW_H

#include "renderer.h"
#include <QPushButton>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QWidget>
#include <QCheckBox>
#include <QGridLayout>
#include <QLabel>
#include <QSignalMapper>
#include <QTimer>
#include "affineparams.h"
#include "chosenpoint.h"
#include "typeEnums.h"

class Window : public QWidget
{
    Q_OBJECT

public:
    Window();

protected:


private:
    Renderer renderer;

    QPushButton* createButton(QString);
};

#endif // WINDOW_H
