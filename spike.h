#ifndef SPIKE_H
#define SPIKE_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Spike:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:

    Spike(QGraphicsPixmapItem * parent=0, int y = 200);
    int counter;

public slots:
    void move();
};

#endif // SPIKE_H
