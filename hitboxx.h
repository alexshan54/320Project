#ifndef HITBOXX_H
#define HITBOXX_H
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class HitBoxX: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    HitBoxX(QGraphicsItem * parent=0);
    bool collision;
public slots:
    void move();
};

#endif // HITBOXX_H
