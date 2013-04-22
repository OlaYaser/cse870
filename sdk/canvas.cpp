#include <QDebug>
#include <QPainter>

#include <math.h>

#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QLabel(parent)
{
    QPixmap palette(500,500);
    palette.fill();

    setPixmap(palette);

    actionCode = NOTHING;
    accessCode = NOONE;

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    event->accept();

    setFocus();

    emit newPoint(event->pos());

    update();
}

void Canvas::setPoints(QList<QPoint> points)
{
    m_points = points;

    update();
}

void Canvas::paintEvent(QPaintEvent *event)
{
    static const QColor normal(0, 255, 0, 192);
    static const QColor close(255, 153, 51, 192);
    static const QColor danger(255, 0, 0, 192);
    static const QColor error(152, 78, 163, 192);
    static const QColor car(0, 0, 0, 192);

    QLabel::paintEvent(event);

    event->accept();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    if (accessCode == INTRUDER) {
        painter.setPen(danger);
        painter.drawText(QPoint(185,30),"Authentication Failed.");
    }

    painter.setPen(QPen(car));
    painter.drawRoundRect(225,350,50,100);
    painter.drawRoundRect(230,360,40,60);

    QRectF innerSensor(200, 300, 100.0, 100.0);
    QRectF outerSensor(175, 275, 150.0, 150.0);

    int startAngle = 30 * 16;
    int spanAngle = 120 * 16;

    painter.drawPie(innerSensor, startAngle, spanAngle);
    painter.drawPie(outerSensor, startAngle, spanAngle);

    if (!m_points.isEmpty()) {
        foreach(const QPoint &point, m_points) {
            painter.drawEllipse(point,5,5);
        }
    }

    if (actionCode == NOTHING) painter.setBrush(QBrush(normal, Qt::SolidPattern));
    else if (actionCode == RECOMMENDATION) painter.setBrush(QBrush(close, Qt::SolidPattern));
    else if (actionCode == FALSE_ALARM) painter.setBrush(QBrush(error, Qt::SolidPattern));
    else painter.setBrush(QBrush(danger, Qt::SolidPattern));

    painter.drawEllipse(245,375,10,10);
}
