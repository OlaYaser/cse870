#include <QApplication>
#include <QTimer>

#include "mainwindow.h"
#include "controller.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;

    Controller controller(&mainWindow);
    controller.start(100);

    mainWindow.show();

    int result = app.exec();

    return result;
}
