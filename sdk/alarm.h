#pragma once
class Alarm
{
public:
   Alarm();
   ~Alarm();

   void InitiateAlarm(double distance);

private:
   void GenerateSoundAlarm();
   void GenerateBlinkingAlarm();
};