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
