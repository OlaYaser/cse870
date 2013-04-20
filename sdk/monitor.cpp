#include "monitor.h"

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
    double angle;

    actionCode_t = m_det->Detect(objects, angle, index);

    //
    m_ala->
}
