#include "hitboxspike.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
//#include "Enemy.h"
#include "game.h"
#include "floorBlock.h"
#include <QDebug>
#include<QPainter>
#include <QBrush>


HitBoxSpike::HitBoxSpike(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){
    // drew the HitBoxX (a rectangle)
    setRect(0,0,25,45);

    setBrush(Qt::white);
    setOpacity(0);
    update();




    // make/connect a timer to move() the HitBoxX every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(30);


}
void HitBoxSpike::move(){
    setPos(Game::game->spike1->x()+10,Game::game->spike1->y()-55);
    // get a list of all the items currently colliding with this HitBoxX
    QList<QGraphicsItem *> colliding_items = collidingItems();



    // if one of the colliding items is an Enemy, destroy both the HitBoxX and the enemy
//    for (int i = 0, n = colliding_items.size(); i < n; ++i){
//        if (typeid(*(colliding_items[i])) == typeid(HitBoxP)){


//            //Game::game->bug1->goLeft = !Game::game->bug1->goLeft;
//           // Game::game->bug1->goRight = !Game::game->bug1->goRight;

//        }else{

//        }
//    }
}
