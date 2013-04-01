#include "mainwindow.h"

MainWindow::MainWindow(Controller *c, QWidget *parent) : QMainWindow(parent)
{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    controller = c;

    hLayout = new QHBoxLayout(centralWidget);

    canvas = new Canvas(centralWidget);
    connect(canvas, SIGNAL(newObject(QPoint)), controller, SLOT(addObject(QPoint)));
    hLayout->addWidget(canvas);

    setLayout(hLayout);
}
