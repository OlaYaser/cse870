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

    Alarm* alarm = new Alarm();
    Monitor::GetInstance().SetAlarm(alarm);

    Recommendation* rec = new Recommendation();
    Monitor::GetInstance().SetRecommendation(rec);

    Prevention* prev = new Prevention();
    Monitor::GetInstance().SetPrevention(prev);

    Detection* det = new Detection();
    Monitor::GetInstance().SetDetection(det);

    mainWindow.show();

    int result = app.exec();

    return result;
}
