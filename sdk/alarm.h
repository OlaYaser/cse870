#pragma once

#include "common.h"

class Alarm
{
public:
   Alarm();
   ~Alarm();

   void AlarmSecurity(const double angle, actionCode_t &action);

private:
   void GenerateSoundAlarm();
   void GenerateBlinkingAlarm();
};
