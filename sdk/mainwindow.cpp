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

    vLayout->addWidget(canvas);

    vehicleSpeed = new QLabel("Vehicle Speed: ", this);
    vLayout->addWidget(vehicleSpeed);

    button = new QPushButton("Reverse", this);
    connect(button, SIGNAL(pressed()), this, SIGNAL(start()));
    vLayout->addWidget(button);

    hLayout = new QHBoxLayout(this);

    username = new QFormLayout(this);
    usernameEdit = new QLineEdit(this);
    username->addRow(tr("&Username: "), usernameEdit);

    connect(usernameEdit, SIGNAL(editingFinished()), this, SLOT(userInfoEntered()));

    password = new QFormLayout(this);
    passwordEdit = new QLineEdit(this);
    passwordEdit->setEchoMode(QLineEdit::Password);
    password->addRow(tr("&Password: "), passwordEdit);

    connect(passwordEdit, SIGNAL(editingFinished()), this, SLOT(userInfoEntered()));

    hLayout->addLayout(username);
    hLayout->addLayout(password);

    vLayout->addLayout(hLayout);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    event->accept();

    if (event->key() == Qt::Key_Up) emit accelerate(true);
    else if (event->key() == Qt::Key_Down) emit accelerate(false);
}

void MainWindow::userInfoEntered()
{
    if (usernameEdit->text().isEmpty() || passwordEdit->text().isEmpty()) return;

    emit newUserInfo(usernameEdit->text(), passwordEdit->text());
}
