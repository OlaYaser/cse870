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
      Detected(distance);
   }
   return m_actionCode;
}

void Detection::Detected(double distance)
{
   if ( distance < 80 && distance > 50 )
   {
      RequestAlarm();
      RequestRecommendation();
      if ( m_actionCode != STOP ) m_actionCode = RECOMMENDATION;
   }
   else if ( distance < 50 )
   {
      RequestPrevention();
      m_actionCode = STOP;
   }
}

void RequestAlarm( ) 
{ 
   Monitor::GetInstance()->InitiateAlarm(); 
}

void RequestRecommendation() 
{ 
   Monitor::GetInstance()->InitiateRecommendation(); 
}

void RequestPrevention() 
{ 
   Monitor::GetInstance()->InitiatePrevention(); 
}