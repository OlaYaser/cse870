#include "controller.h"

Controller::Controller(MainWindow *window, QObject *parent) : QObject(parent)
{
    mainWindow = window;
    connect(window, SIGNAL(newObject(QPoint)), this, SLOT(addObject(QPoint)));
    connect(this, SIGNAL(drawObjects(QList<QPoint>)), mainWindow, SIGNAL(draw(QList<QPoint>)));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(incrementTime()));
}

void Controller::addObject(const QPoint &position)
{
    Object object(rand()%9+1, position);
    objects.append(object);
}

void Controller::incrementTime()
{
    QList<QPoint> positions;

    for (int i=objects.size()-1; i>=0; i--) {
        if (objects[i].move().y() >= 500 /* outside scope of window */ ) objects.removeAt(i);
        else positions.append(objects[i].position());
    }

    emit drawObjects(positions);
}
