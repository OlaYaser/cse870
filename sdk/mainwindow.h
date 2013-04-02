#ifndef __MAINWINDOW_H
#define __MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QLabel>

#include "canvas.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Canvas *canvas;
    QWidget *centralWidget;
    QHBoxLayout *hLayout;

public:
    explicit MainWindow(QWidget *parent = 0);

public slots:

protected slots:
    void keyPressEvent(QKeyEvent *event);

signals:
    void draw(QList<QPoint>);
    void newObject(QPoint);

};

#endif
