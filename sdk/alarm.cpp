#include "alarm.h"
#include <limits>

Alarm::Alarm()
{

}

void Alarm::AlarmSecurity(const double angle, actionCode_t &action)
{
    if (angle == -std::numeric_limits<double>::max()) return;
    else if (angle > -30.0 || angle < -150.0) action = FALSE_ALARM;
}
