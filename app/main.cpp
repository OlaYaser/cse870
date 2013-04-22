#include <QApplication>
#include <QTimer>

#include "mainwindow.h"
#include "controller.h"
#include "prevention.h"
#include "detection.h"
#include "monitor.h"
#include "alarm.h"
#include "recommendation.h"
#include "checkpoint.h"
#include <string.h>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;

    Controller controller(&mainWindow);

    Checkpoint checkpoint;

    SingleAccessPoint sap(&checkpoint);

    controller.setSingleAccessPoint(&sap);

    mainWindow.show();

    int result = app.exec();

    return result;
}
