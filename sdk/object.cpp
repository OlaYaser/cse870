#include "object.h"

Object::Object(QPoint speed, QPoint position)
{
    m_speed = speed;
    m_position = position;
}

QPoint Object::move(QPoint relativeSpeed)
{
    m_position.setY(m_position.y()+m_speed.y()+relativeSpeed.y());
    m_position.setX(m_position.x()+m_speed.x()+relativeSpeed.x());

    return m_position;
}

void Object::accelerate(bool positive)
{
    if (positive) m_speed.setY(m_speed.y()+1);
    else if (m_speed.y() > 0) m_speed.setY(m_speed.y()-1);
}

QDebug operator<<(QDebug d, const Object &object)
{
    return d.nospace() << qPrintable(object.properties());
}
