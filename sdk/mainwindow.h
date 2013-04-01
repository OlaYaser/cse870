#ifndef __MAINWINDOW_H
#define __MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QLabel>

#include "controller.h"
#include "canvas.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Canvas *canvas;
    QWidget *centralWidget;
    QHBoxLayout *hLayout;
    Controller *controller;

public:
    explicit MainWindow(Controller *c, QWidget *parent = 0);

};

#endif
