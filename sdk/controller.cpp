#include "controller.h"
#include "monitor.h"

const QPoint CAR_SPEED(0,5);
const QPoint CAR_POSITION(250,350);

Controller::Controller(MainWindow *window, QObject *parent) : QObject(parent)
{
    mainWindow = window;
    connect(mainWindow, SIGNAL(newObject(QPoint)), this, SLOT(addObject(QPoint)));
    connect(mainWindow, SIGNAL(accelerate(bool)), this, SLOT(accelerateCar(bool)));
    connect(mainWindow, SIGNAL(start()), this, SLOT(start()));
    connect(mainWindow, SIGNAL(newUserInfo(QString, QString)), SLOT(setUserInfo(QString,QString)));

    connect(this, SIGNAL(newSpeed(int)), mainWindow, SLOT(displaySpeed(int)));
    connect(this, SIGNAL(drawObjects(QList<QPoint>)), mainWindow, SIGNAL(draw(QList<QPoint>)));
    connect(this, SIGNAL(newAction(actionCode_t)), mainWindow, SIGNAL(setAction(actionCode_t)));

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
    int index;
    accessCode_t access;
    m_sap->access(m_username, m_password, access, objects, index);

    if (access != ROOT) return;

    Object object(QPoint(rand()%10-5,rand()%10-5), position);
    objects.append(object);

    QList<QPoint> positions;

    for (int i=objects.size()-1; i>=0; i--) {
        positions.append(objects[i].position());
    }

    emit drawObjects(positions);
}

void Controller::incrementTime()
{
    int index;
    accessCode_t access;
    actionCode_t action = m_sap->access(m_username, m_password, access, objects, index);

    if (access != INTRUDER) {
        QList<QPoint> positions;

        for (int i=objects.size()-1; i>=0; i--) {
            QPoint newPosition = objects[i].move(car->speed());
            if (newPosition.x() >= 500 ||
                    newPosition.y() >= 500 ||
                    newPosition.x() <= 0   ||
                    newPosition.y() <= 0 /* outside scope of window */ ) objects.removeAt(i);
            else positions.append(newPosition);
        }

        emit newAction(action);

        emit drawObjects(positions);

        if (action == PREVENTION) {
            objects.removeAt(index);
            car->setSpeed(QPoint(0,0));
            emit newSpeed(car->speed().y());
            finish();
        }
    }
}

void Controller::accelerateCar(bool positive)
{
    int index;
    accessCode_t accessCode;

    m_sap->access(m_username, m_password, accessCode, objects, index);

    if (accessCode == INTRUDER) return;

    car->accelerate(positive);

    emit newSpeed(car->speed().y());
}

void Controller::setUserInfo(const QString &username, const QString &password)
{
    m_username = username;
    m_password = password;
}
