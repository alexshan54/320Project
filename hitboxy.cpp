#include "hitboxy.h"

#include "hitboxy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
//#include "Enemy.h"
#include "game.h"
#include "floorBlock.h"
#include <QDebug>



HitBoxY::HitBoxY(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){
    // drew the bullet (a rectangle)
    setRect(0,0,40,15);

    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(30);
//    setBrush(Qt::white);
    setOpacity(0);
    update();
}

void HitBoxY::move(){
    setPos(Game::game->player->x()+70,Game::game->player->y()+110);
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();
    Game::game->player->yCollision = 0;
    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(FloorBlock)){
            //qDebug()<< "we have collided in the y";
            Game::game->player->yCollision = 1;

        }
        if (typeid(*(colliding_items[i])) == typeid(enemyBug)){
            if(Game::game->player->vspeed<0){
                Game::game->updateScore(40);
                Game::game->bug1->setPos(-160,300);
                Game::game->bug1->xspeed = 0;
                Game::game->player->vspeed = 20;
                Game::game->updateScore(30);
                QMediaPlayer * hit2;
                hit2 = new QMediaPlayer;
                hit2->setMedia(QUrl("qrc:/music/assets/bug2.mp3"));
                hit2->play();
            }


        }

    }

}
