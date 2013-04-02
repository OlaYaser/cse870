#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    hLayout = new QHBoxLayout(centralWidget);

    canvas = new Canvas(centralWidget);
    connect(canvas, SIGNAL(newPoint(QPoint)), this, SIGNAL(newObject(QPoint)));
    connect(this, SIGNAL(draw(QList<QPoint>)), canvas, SLOT(setPoints(QList<QPoint>)));
    hLayout->addWidget(canvas);

    setLayout(hLayout);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    event->accept();

    if (event->key() == Qt::Key_Up) qDebug() << "Faster!";
    else if (event->key() == Qt::Key_Down) qDebug() << "Slower!";
}
