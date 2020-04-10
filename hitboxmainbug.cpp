#include "hitboxmainbug.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
//#include "Enemy.h"
#include "game.h"
#include "floorBlock.h"
#include <QDebug>
#include<QPainter>
#include <QBrush>


HitBoxMainBug::HitBoxMainBug(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){
    // drew the HitBoxX (a rectangle)
    setRect(0,0,54,30);
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

void HitBoxMainBug::move(){
    setPos(Game::game->bug1->x()+5,Game::game->bug1->y()-55);
    // get a list of all the items currently colliding with this HitBoxX
    QList<QGraphicsItem *> colliding_items = collidingItems();

    Game::game->bug1->hitwall = 0;

    // if one of the colliding items is an Enemy, destroy both the HitBoxX and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(FloorBlock)){

            Game::game->bug1->hitwall = 1;


            //Game::game->bug1->goLeft = !Game::game->bug1->goLeft;
           // Game::game->bug1->goRight = !Game::game->bug1->goRight;

        }else{

        }
    }
}
