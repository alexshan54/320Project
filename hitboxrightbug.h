#ifndef HITBOXRIGHTBUG_H
#define HITBOXRIGHTBUG_H


#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class HitBoxRightBug: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    HitBoxRightBug(QGraphicsItem * parent=0);
    bool collision;
public slots:
    void move();
};

#endif // HITBOXRIGHTBUG_H
