#include <QApplication>
#include <QTimer>

#include "mainwindow.h"
#include "controller.h"
#include "prevention.h"
#include "detection.h"
#include "monitor.h"
#include "alarm.h"
#include "recommendation.h"

using namespace std;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow mainWindow;

    Controller controller(&mainWindow);
    controller.start(100);

    /*
    Monitor* monitor = Monitor::GetInstance();

    Alarm* alarm = new Alarm();
    monitor->SetAlarm(alarm);

    Recommendation* rec = new Recommendation();
    monitor->SetRecommendation(rec);

    Prevention* prev = new Prevention();
    monitor->SetPrevention(prev);

    Detection* det = new Detection();
    monitor->SetDetection(det);
    */

    mainWindow.show();

    int result = app.exec();

    return result;
}
