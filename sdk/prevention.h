#pragma once
class Prevention
{
public:
   Prevention();
   ~Prevention();

   void InitiatePrevention();

private:
   void Steer(double angle);
   void Brake(double force);

};