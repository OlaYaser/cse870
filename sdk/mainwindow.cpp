#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    vLayout = new QVBoxLayout(centralWidget);

    canvas = new Canvas(centralWidget);
    connect(canvas, SIGNAL(newPoint(QPoint)), this, SIGNAL(newObject(QPoint)));
    connect(this, SIGNAL(draw(QList<QPoint>)), canvas, SLOT(setPoints(QList<QPoint>)));
    connect(this, SIGNAL(setAction(actionCode_t)), canvas, SLOT(setAction(actionCode_t)));
    connect(this, SIGNAL(setAccess(accessCode_t)), canvas, SLOT(setAccess(accessCode_t)));

    vLayout->addWidget(canvas);

    vehicleSpeed = new QLabel("Vehicle Y Velocity: \tVehicle X Velocity: ", this);
    vLayout->addWidget(vehicleSpeed);

    buttonLayout = new QHBoxLayout();

    resumeButton = new QPushButton("Reverse", this);
    connect(resumeButton, SIGNAL(pressed()), this, SIGNAL(resume()));

    buttonLayout->addWidget(resumeButton);

    pauseButton = new QPushButton("Pause", this);
    connect(pauseButton, SIGNAL(pressed()), this, SIGNAL(pause()));

    buttonLayout->addWidget(pauseButton);

    infoLayout = new QHBoxLayout();

    username = new QFormLayout(this);
    usernameEdit = new QLineEdit(this);
    username->addRow(tr("&Username: "), usernameEdit);

    connect(usernameEdit, SIGNAL(editingFinished()), this, SLOT(userInfoEntered()));

    password = new QFormLayout(this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);
    password->addRow(tr("&Password: "), passwordEdit);

    connect(passwordEdit, SIGNAL(editingFinished()), this, SLOT(userInfoEntered()));

    infoLayout->addLayout(username);
    infoLayout->addLayout(password);

    vLayout->addLayout(infoLayout);
    vLayout->addLayout(buttonLayout);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    event->accept();

    if (event->key() == Qt::Key_Up) emit accelerate(true);
    else if (event->key() == Qt::Key_Down) emit accelerate(false);
    if (event->key() == Qt::Key_Left) emit left();
    else if (event->key() == Qt::Key_Right) emit right();
}

void MainWindow::userInfoEntered()
{
    if (usernameEdit->text().isEmpty() || passwordEdit->text().isEmpty()) return;

    emit newUserInfo(usernameEdit->text(), passwordEdit->text());
}
