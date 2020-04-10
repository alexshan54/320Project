#ifndef HITBOXP_H
#define HITBOXP_H

#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class HitBoxP: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    HitBoxP(QGraphicsItem * parent=0);
    bool collision;
    int ImInvincibleBaby;
public slots:
    void move();
};

#endif // HITBOXP_H
