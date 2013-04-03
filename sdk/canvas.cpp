#include <QDebug>
#include <QPainter>

#include <math.h>

#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QLabel(parent)
{
    QPixmap palette(500,500);
    palette.fill();

    setPixmap(palette);

    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void Canvas::mousePressEvent(QMouseEvent *event)
{
    event->accept();

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
    static const QColor car(0, 0, 0, 192);

    QLabel::paintEvent(event);

    event->accept();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    if (!m_points.isEmpty()) {
        foreach(const QPoint &point, m_points) {
            double distance = sqrt(pow(point.x()-250, 2) + pow(point.y()-350, 2));
            if (distance > 80 || point.y() > 350) painter.setPen(QPen(normal));
            else if (distance > 50) painter.setPen(QPen(close));
            else painter.setPen(QPen(danger));

            painter.drawEllipse(point,5,5);
        }
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
}
