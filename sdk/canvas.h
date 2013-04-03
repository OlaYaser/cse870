#ifndef __CANVAS_H
#define __CANVAS_H

#include <QLabel>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QList>
#include "common.h"

class Canvas : public QLabel
{
    Q_OBJECT
    QList<QPoint> m_points;
    actionCode_t actionCode;

protected slots:
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void setAction(actionCode_t code);

public:
    explicit Canvas(QWidget *parent = 0);

public slots:
    void setPoints(QList<QPoint>);

signals:
    void newPoint(QPoint);

};

#endif
