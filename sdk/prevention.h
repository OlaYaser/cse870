#pragma once
class Prevention
{
public:
   Prevention();
   ~Prevention();

   void InitiatePrevention(double distance);

private:
   void Steer(double angle);
   void Brake(double force);

};