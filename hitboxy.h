#ifndef HITBOXY_H
#define HITBOXY_H


#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class HitBoxY: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    HitBoxY(QGraphicsItem * parent=0);
    bool collision;
public slots:
    void move();
};

#endif // HITBOXY_H
