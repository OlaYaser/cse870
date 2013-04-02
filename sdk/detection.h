#pragma once
#include "monitor.h"

class Monitor;

class Detection
{
public:
   void SetMonitor(Monitor* monitor) { m_monitor = monitor; }

   void Detect();
   void Detected();

private:
   Monitor* m_monitor;

   void CalculateDistance();
};