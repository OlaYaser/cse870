#include "detection.h"
#include "Monitor.h"
#include <math.h>

actionCode_t Detection::Detect(QList<Object> objects, int &index)
{
   m_actionCode = NOTHING;
   index = -1;

   for(int i = 0; i < objects.count(); i++ )
   {
      Object object = objects[i];
      if ( object.position().y() > 350 ) continue;
      double distance = sqrt(pow(object.position().x()-250, 2.0) + pow(object.position().y()-350, 2.0));
      if (!Detected(distance)) {
          index = i;
          break;
      }
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

void Detection::RequestAlarm( )
{ 
   Monitor::GetInstance().InitiateAlarm(); 
}

void Detection::RequestRecommendation()
{ 
   Monitor::GetInstance().InitiateRecommendation(); 
}

void Detection::RequestPrevention()
{ 
   Monitor::GetInstance().InitiatePrevention(); 
}
