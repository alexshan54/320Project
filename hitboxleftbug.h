#ifndef HITBOXLEFTBUG_H
#define HITBOXLEFTBUG_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class HitBoxLeftBug: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    HitBoxLeftBug(QGraphicsItem * parent=0);
    bool collision;
public slots:
    void move();
};

#endif // HITBOXLEFTBUG_H
