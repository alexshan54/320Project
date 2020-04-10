#ifndef FLOOR_H
#define FLOOR_H
#include "object.h"
#include <QTimer>
#include <QGraphicsItem>
#include <QObject>
#include <QGraphicsPixmapItem>


class FloorBlock: public Object, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    FloorBlock(QGraphicsPixmapItem *parent, QString screen = "Game");
    FloorBlock(QGraphicsPixmapItem *parent, int x, int y, QString screen = "Game");

public slots:
    void moveinGame();
    void moveinMenu();

};

#endif // FLOORBLOCK_H
