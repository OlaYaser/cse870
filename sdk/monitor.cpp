#include "monitor.h"
#include <limits>

Monitor::Monitor()
{
    m_ala = new Alarm();
    m_rec = new Recommendation();
    m_pre = new Prevention();
    m_det = new Detection();
}

Monitor& Monitor::GetInstance()
{
   static Monitor instance;
   return instance;
}

actionCode_t Monitor::newObjects(QList<Object> objects, int &index)
{
    double angle = -std::numeric_limits<double>::max();

    actionCode_t action = m_det->Detect(objects, angle, index);

    m_ala->AlarmSecurity(angle, action);

    return action;
}
