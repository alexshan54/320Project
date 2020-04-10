#ifndef HITBOXEXTRAXP_H
#define HITBOXEXTRAXP_H


#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class HitBoxExtraP: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    HitBoxExtraP(QGraphicsItem * parent=0);
public slots:
    void move();
};

#endif // HITBOXEXTRAXP_H
