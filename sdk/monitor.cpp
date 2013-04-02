#include "monitor.h"

Monitor* Monitor::GetInstance()
{
   if ( m_instance == nullptr )
   {
      m_instance = new Monitor();
   }
   return m_instance;
}

Monitor::~Monitor()
{
   if ( m_instance != nullptr )
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