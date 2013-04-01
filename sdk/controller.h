#ifndef __CONTROLLER_H
#define __CONTROLLER_H

#include <QObject>
#include <QPoint>
#include <QDebug>

class Controller : public QObject
{
    Q_OBJECT

    QList<QPoint> objects/* TODO change to object class */;

    // Set controller to own mainwindow and objects
    // When mainwindow emits signal catch it, when controller emits moveObjects catch it in main window

public:
    void incrementTime() { qDebug() << "incrementing"; }

public slots:

    void addObject(const QPoint &object) { objects.append(object); }

};

#endif
