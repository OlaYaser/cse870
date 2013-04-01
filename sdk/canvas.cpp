#include "canvas.h"
#include <QDebug>
#include <QPainter>

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

    qDebug() << "Create new object at: " << event->pos();
    emit newObject(event->pos());

    update();
}


void Canvas::paintEvent(QPaintEvent *event)
{
    static const QColor normal(0, 0, 0, 192);

    QLabel::paintEvent(event);

    event->accept();

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    if (!points.isEmpty()) {
        painter.setPen(QPen(normal));
        foreach(const QPoint &point, points) painter.drawEllipse(point,5,5);
    }
}
