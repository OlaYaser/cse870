#include "monitor.h"

Monitor* Monitor::GetInstance()
{
   if ( !m_instance )
   {
      m_instance = new Monitor();
   }
   return m_instance;
}

Monitor::~Monitor()
{
   if ( m_instance )
   {
      delete m_instance;
   }
}
   
void Monitor::InitiatePrevention(double distance)
{

}

void Monitor::InitiateRecommendation(double distance)
{

}

void Monitor::InitiateAlarm(double distance)
{

}
