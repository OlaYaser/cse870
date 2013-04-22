#ifndef __MAINWINDOW_H
#define __MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFormLayout>
#include <QLineEdit>

#include "canvas.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Canvas *canvas;
    QWidget *centralWidget;
    QLabel *vehicleSpeed;

    QVBoxLayout *vLayout;
    QHBoxLayout *infoLayout;
    QHBoxLayout *buttonLayout;

    QPushButton *resumeButton;
    QPushButton *pauseButton;

    QFormLayout *username;
    QFormLayout *password;
    QLineEdit *usernameEdit;
    QLineEdit *passwordEdit;

public:
    explicit MainWindow(QWidget *parent = 0);

public slots:

    void displaySpeed(QPoint speed) { vehicleSpeed->setText(QString("Vehicle Y Velocity: %1 mph \tVehicle X Velocity: %2 mph").arg(speed.y()).arg(speed.x())); }

protected slots:
    void keyPressEvent(QKeyEvent *event);
    void userInfoEntered();

signals:
    void draw(QList<QPoint>);
    void newObject(QPoint);
    void accelerate(bool);
    void left();
    void right();

    void setAction(actionCode_t);
    void setAccess(accessCode_t);

    void resume();
    void pause();
    void newUserInfo(QString, QString);
};

#endif
