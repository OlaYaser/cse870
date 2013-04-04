#pragma once
class Alarm
{
public:
   Alarm();
   ~Alarm();

   void InitiateAlarm();

private:
   void GenerateSoundAlarm();
   void GenerateBlinkingAlarm();
};