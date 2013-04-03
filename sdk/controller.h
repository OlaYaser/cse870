#ifndef __CONTROLLER_H
#define __CONTROLLER_H

#include <QObject>
#include <QPoint>
#include <QTimer>
#include <QDebug>

#include "object.h"
#include "mainWindow.h"

class Controller : public QObject
{
    Q_OBJECT

    MainWindow *mainWindow;
    QList<Object> objects;
    QTimer *timer;
    Object *car;

public:
    explicit Controller(MainWindow *mainWindow, QObject *parent = 0);
    ~Controller();

public slots:

    void addObject(const QPoint &position);

    void incrementTime();

    void accelerateCar(bool positive);

    void start(int count) { timer->start(count); }
    void finish() { timer->stop(); }

signals:
    void drawObjects(QList<QPoint>);
    void newSpeed(int);

};

#endif
