#include "detection.h"

void Detection::Detect()
{
   // Repeatedly loop through list of objects and determine distance
   // Very hard to cheese without knowing how to get the list
   // or how the distance works
   // If an object is within sensor range call Detected
}

void Detection::Detected(double distance)
{
   if ( distance < 3 && distance > 1.5 )
   {
      RequestAlarm(distance);
      RequestRecommendation(distance);
   }
   else if ( distance < 1.5 )
   {
      RequestPrevention(distance);
   }
}