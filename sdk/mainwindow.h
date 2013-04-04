#ifndef __MAINWINDOW_H
#define __MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

#include "canvas.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Canvas *canvas;
    QWidget *centralWidget;
    QLabel *vehicleSpeed;
    QVBoxLayout *vLayout;
    QPushButton *button;

public:
    explicit MainWindow(QWidget *parent = 0);

public slots:

    void soundAlarm() {  }
    void displaySpeed(int speed) { vehicleSpeed->setText(QString("Vehicle Speed: %1").arg(speed)); }

protected slots:
    void keyPressEvent(QKeyEvent *event);

signals:
    void draw(QList<QPoint>);
    void newObject(QPoint);
    void accelerate(bool);
    void setAction(actionCode_t);
    void start();

};

#endif
