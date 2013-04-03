#include "controller.h"

const QPoint CAR_SPEED(0,5);
const QPoint CAR_POSITION(255,350);

Controller::Controller(MainWindow *window, QObject *parent) : QObject(parent)
{
    mainWindow = window;
    connect(mainWindow, SIGNAL(newObject(QPoint)), this, SLOT(addObject(QPoint)));
    connect(mainWindow, SIGNAL(accelerate(bool)), this, SLOT(accelerateCar(bool)));
    connect(this, SIGNAL(newSpeed(int)), mainWindow, SLOT(displaySpeed(int)));
    connect(this, SIGNAL(drawObjects(QList<QPoint>)), mainWindow, SIGNAL(draw(QList<QPoint>)));

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(incrementTime()));

    car = new Object(CAR_SPEED, CAR_POSITION);

    emit newSpeed(CAR_SPEED.y());
}

Controller::~Controller()
{
    delete car;
}

void Controller::addObject(const QPoint &position)
{
    Object object(QPoint(rand()%10-5,rand()%10-5), position);
    objects.append(object);
}

void Controller::incrementTime()
{
    QList<QPoint> positions;

    for (int i=objects.size()-1; i>=0; i--) {
        QPoint newPosition = objects[i].move(car->speed());
        if (newPosition.x() >= 500 ||
            newPosition.y() >= 500 ||
            newPosition.x() <= 0   ||
            newPosition.y() <= 0 /* outside scope of window */ ) objects.removeAt(i);
        else positions.append(newPosition);
    }

    emit drawObjects(positions);
}

void Controller::accelerateCar(bool positive)
{
    car->accelerate(positive);

    emit newSpeed(car->speed().y());
}
