#ifndef __CANVAS_H
#define __CANVAS_H

#include <QLabel>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QList>

class Canvas : public QLabel
{
    Q_OBJECT
    QList<QPoint> points;

protected slots:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

public:
    explicit Canvas(QWidget *parent = 0);

signals:
    void newObject(QPoint);

};

#endif
