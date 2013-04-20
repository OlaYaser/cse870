#pragma once
#include <QList>
#include "object.h"
#include "common.h"
class Monitor;

class Detection
{
public:
   actionCode_t Detect(QList<Object> objects, double &angle, int &index);
   bool Detected(double distance);

private:
   actionCode_t m_actionCode;

};
