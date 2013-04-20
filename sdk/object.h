#ifndef __OBJECT_H
#define __OBJECT_H

#include <QDebug>
#include <QPoint>

class Object
{
    QPoint m_speed; // Note that we represent speed as a point for simplicity
                    // m_speed.x() is speed in the horizonal direction
                    // m_speed.y() is speed in the vertical direction
    QPoint m_position;

public:

    Object(QPoint speed, QPoint position);

    QString properties() const { return QString("Speed Horizontal: %1 Speed Vertical: %2 Position: (%3,%4)").arg(m_speed.x()).arg(m_speed.y()).arg(m_position.x()).arg(m_position.y()); }

    QPoint position() { return m_position; }
    QPoint speed() { return m_speed; }
    void setSpeed(const QPoint& speed) { m_speed = speed; }

    void accelerate(bool positive);
    QPoint move(QPoint relativeSpeed = QPoint(0,0));
    
};

QDebug operator<<(QDebug d, const Object &object);

#endif // OBJECT_H
