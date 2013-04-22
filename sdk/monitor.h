#pragma once
#include "recommendation.h"
#include "prevention.h"
#include "detection.h"
#include "alarm.h"
#include "singleaccesspoint.h"

class Monitor
{
    friend class SingleAccessPoint;

    Alarm *alarm;
    Recommendation *rec;
    Prevention *prev;
    Detection *det;

public:
   ~Monitor() {}

   actionCode_t newObjects(QList<Object> objects, int& index);

   void SetRecommendation(Recommendation* rec) { m_rec = rec; }
   void SetPrevention(Prevention* pre) { m_pre = pre; }
   void SetDetection(Detection* det) { m_det = det; }
   void SetAlarm(Alarm* ala) { m_ala = ala; }

private:
   static Monitor& GetInstance();

   Monitor();

   Recommendation *m_rec;
   Prevention     *m_pre;
   Detection      *m_det;
   Alarm          *m_ala;
};
