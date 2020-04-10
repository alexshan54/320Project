#ifndef HITBOXSPIKE_H
#define HITBOXSPIKE_H


#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class HitBoxSpike: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    HitBoxSpike(QGraphicsItem * parent=0);
    bool collision;
public slots:
    void move();
};

#endif // HITBOXSPIKE_H
