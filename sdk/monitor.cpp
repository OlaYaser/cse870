#include "monitor.h"

Monitor::Monitor()
{
    alarm = new Alarm();
    Monitor::GetInstance().SetAlarm(alarm);

    rec = new Recommendation();
    Monitor::GetInstance().SetRecommendation(rec);

    prev = new Prevention();
    Monitor::GetInstance().SetPrevention(prev);

    det = new Detection();
    Monitor::GetInstance().SetDetection(det);
}

Monitor& Monitor::GetInstance()
{
   static Monitor instance;
   return instance;
}
