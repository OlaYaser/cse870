#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    vLayout = new QVBoxLayout(centralWidget);

    canvas = new Canvas(centralWidget);
    connect(canvas, SIGNAL(newPoint(QPoint)), this, SIGNAL(newObject(QPoint)));
    connect(this, SIGNAL(draw(QList<QPoint>)), canvas, SLOT(setPoints(QList<QPoint>)));
    vLayout->addWidget(canvas);

    vehicleSpeed = new QLabel("Vehicle Speed: ", this);
    vLayout->addWidget(vehicleSpeed);

    setLayout(vLayout);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    event->accept();

    if (event->key() == Qt::Key_Up) emit accelerate(true);
    else if (event->key() == Qt::Key_Down) emit accelerate(false);
}
