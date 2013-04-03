#pragma once
#include <QList>
#include "object.h"
#include "common.h"
class Monitor;

class Detection
{
public:
   actionCode_t Detect(QList<Object> objects);
   void Detected(double distance);

   void RequestAlarm();
   void RequestRecommendation();
   void RequestPrevention();

private:
   actionCode_t m_actionCode;

};
