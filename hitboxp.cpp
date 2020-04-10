#include "hitboxp.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
//#include "Enemy.h"
#include "game.h"
#include "floorBlock.h"
#include <QDebug>
#include<QPainter>
#include <QBrush>


HitBoxP::HitBoxP(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){
    // drew the HitBoxX (a rectangle)
    setRect(0,0,30,130);
    //    QColor color = Qt::red;
    //    QBrush brush = Qt::SolidPattern;
    //    brush.setColor(color);
    setOpacity(0);

    update();



    // make/connect a timer to move() the HitBoxX every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    ImInvincibleBaby = 0;
    // start the timer
    timer->start(30);



}

void HitBoxP::move(){
    setPos(Game::game->player->x()+75,Game::game->player->y()-30);
    // get a list of all the items currently colliding with this HitBoxX
    QList<QGraphicsItem *> colliding_items = collidingItems();
    Game::game->player->xCollision = 0;
    // if one of the colliding items is an Enemy, destroy both the HitBoxX and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(FloorBlock)){
            Game::game->player->xCollision = 1;

        }
        if (typeid(*(colliding_items[i])) == typeid(HitBoxMainBug)){
            if(ImInvincibleBaby<=0){
                qDebug()<< "Colliding with bug!";
                qDebug()<< ImInvincibleBaby;
                Game::game->health--;
                Game::game->updateHealth();
                QMediaPlayer * hit;
                hit = new QMediaPlayer;
                hit->setMedia(QUrl("qrc:/music/assets/bug.mp3"));
                hit->play();
                }
                qDebug()<< "Colliding with player";
                ImInvincibleBaby = 90;
                // Game::game->player->setPos(Game::game->player->x()-30, Game::game->player->y()-30);

            }
            if (typeid(*(colliding_items[i])) == typeid(HitBoxFile)){
                if(ImInvincibleBaby<=0){
                    qDebug()<< "Colliding with File!";
                    qDebug()<< ImInvincibleBaby;
                    Game::game->health--;
                    Game::game->updateHealth();
                    QMediaPlayer * hit;
                    hit = new QMediaPlayer;
                    hit->setMedia(QUrl("qrc:/music/assets/bug.mp3"));
                    hit->play();
                    }
                    qDebug()<< "Colliding with player";
                    ImInvincibleBaby = 90;

                    // Game::game->player->setPos(Game::game->player->x()-30, Game::game->player->y()-30);

                }
            if (typeid(*(colliding_items[i])) == typeid(HitBoxSpike)){
                if(ImInvincibleBaby<=0){
                    qDebug()<< "Colliding with Spike!";
                    qDebug()<< ImInvincibleBaby;
                    Game::game->health--;
                    Game::game->updateHealth();
                    QMediaPlayer * hit;
                    hit = new QMediaPlayer;
                    hit->setMedia(QUrl("qrc:/music/assets/bug.mp3"));
                    hit->play();
                    }
                    qDebug()<< "Colliding with player";
                    ImInvincibleBaby = 90;

                    // Game::game->player->setPos(Game::game->player->x()-30, Game::game->player->y()-30);

                }

            }
            if(ImInvincibleBaby > 0){
                ImInvincibleBaby--;
                setPos(10,-211);
            }

        }
