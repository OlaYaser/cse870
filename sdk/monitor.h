#pragma once
#include "recommendation.h"
#include "prevention.h"
//#include "detection.h"
#include "alarm.h"

class Monitor
{
public:
   static Monitor* GetInstance();
   ~Monitor();

   void InitiatePrevention(double distance) { m_pre->InitiatePrevention(distance); }
   void InitiateRecommendation(double distance) { m_rec->GetRecommendation(distance); }
   void InitiateAlarm(double distance) { m_ala->InitiateAlarm(distance); }

   void SetRecommendation(Recommendation* rec) { m_rec = rec; }
   void SetPrevention(Prevention* pre) { m_pre = pre; }
   //void SetDetection(Detection* det) { m_det = det; }
   void SetAlarm(Alarm* ala) { m_ala = ala; }

private:
   Monitor();
   static Monitor *m_instance;
   Recommendation *m_rec;
   Prevention     *m_pre;
   //Detection      *m_det;
   Alarm          *m_ala;
};
