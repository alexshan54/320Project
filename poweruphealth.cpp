#include "poweruphealth.h"
#include<QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include "game.h"
#include "hitboxextraxp.h"
powerupHealth::powerupHealth(QGraphicsPixmapItem * parent, int y)
{
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    // start the timer
    setPixmap(QPixmap(":/assets/battery.png"));
    setScale(3);
    setOffset(0,-20);
    timer->start(50);
    setPos(800, y);

}


void powerupHealth::move(){
    setPos(x()-10,y());
    QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(HitBoxExtraP)){
            if(Game::game->health < 3){
                Game::game->health++;
            }
            Game::game->updateHealth();
            QMediaPlayer * powerup;
            powerup = new QMediaPlayer;
            powerup->setMedia(QUrl("qrc:/music/assets/powerup.mp3"));
            powerup->play();
            delete this;
    }
}
}
