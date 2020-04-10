#ifndef HITBOXMAINBUG_H
#define HITBOXMAINBUG_H


#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class HitBoxMainBug: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    HitBoxMainBug(QGraphicsItem * parent=0);
    bool collision;
public slots:
    void move();
};

#endif // HITBOXMAINBUG_H
