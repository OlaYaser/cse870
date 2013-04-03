#include "monitor.h"

Monitor& Monitor::GetInstance()
{
   static Monitor instance;
   return instance;
}
