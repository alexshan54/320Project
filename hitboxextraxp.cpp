#include "hitboxextraxp.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
//#include "Enemy.h"
#include "game.h"
#include "floorBlock.h"
#include <QDebug>
#include<QPainter>
#include <QBrush>


HitBoxExtraP::HitBoxExtraP(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){
    // drew the HitBoxX (a rectangle)
    setRect(0,0,30,130);
//    QColor color = Qt::red;
//    QBrush brush = Qt::SolidPattern;
//    brush.setColor(color);
    setBrush(Qt::blue);
    setOpacity(0);
    update();



    // make/connect a timer to move() the HitBoxX every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    // start the timer
    timer->start(30);



}

void HitBoxExtraP::move(){
    setPos(Game::game->player->x()+75,Game::game->player->y()-25);
    QList<QGraphicsItem *> colliding_items = collidingItems();


    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(FloorBlock)){


        }

    }


}
