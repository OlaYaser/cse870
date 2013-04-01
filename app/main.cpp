#include <QApplication>

#include "mainwindow.h"
#include "controller.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Controller controller;

    MainWindow mainWindow(&controller);
    mainWindow.show();

    int result = app.exec();

    return result;
}
