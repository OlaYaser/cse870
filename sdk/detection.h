#pragma once
#include "monitor.h"

class Detection
{
public:
   void Detect();
   void Detected(double distance);

   void RequestAlarm(double distance) { Monitor::GetInstance()->InitiateAlarm(distance); }
   void RequestRecommendation(double distance) { Monitor::GetInstance()->InitiateRecommendation(distance); }
   void RequestPrevention(double distance) { Monitor::GetInstance()->InitiatePrevention(distance); }

private:
   void CalculateDistance();
};