#include "detection.h"
#include "Monitor.h"

actionCode_t Detection::Detect(QList<Object> objects)
{
   m_actionCode = NOTHING;
   for(int i = 0; i < objects.count(); i++ )
   {
      Object object = objects[i];
      if ( object.position().y() > 350 ) continue;
      double distance = sqrt(pow(object.position().x()-250, 2.0) + pow(object.position().y()-350, 2.0));
      if (!Detected(distance)) break;
   }
   return m_actionCode;
}

bool Detection::Detected(double distance)
{
   if ( distance < 80 && distance > 50 )
   {
      RequestAlarm();
      RequestRecommendation();
      m_actionCode = RECOMMENDATION;
   }
   else if ( distance < 50 )
   {
      RequestPrevention();
      m_actionCode = PREVENTION;
      return false;
   }
   return true;
}

void RequestAlarm( ) 
{ 
   Monitor::GetInstance().InitiateAlarm(); 
}

void RequestRecommendation() 
{ 
   Monitor::GetInstance().InitiateRecommendation(); 
}

void RequestPrevention() 
{ 
   Monitor::GetInstance().InitiatePrevention(); 
}