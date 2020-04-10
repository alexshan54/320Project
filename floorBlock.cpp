#include "floorBlock.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include <game.h>
#include "floorblockspawner.h"
FloorBlock::FloorBlock(QGraphicsPixmapItem *parent,QString screen)
{
    int random_number = rand() %700;
    setPos(796,436);
    setPixmap(QPixmap(":/assets/fileblock.png"));
    setScale(4);
    // start the timer
    QTimer * timer = new QTimer(this);
    if (screen == "Menu"){
        connect(timer,SIGNAL(timeout()),this,SLOT(moveinMenu()));
    }
    else{
        connect(timer,SIGNAL(timeout()),this,SLOT(moveinGame()));
    }
    timer->start(50);
    xVelocity = 10;

}


FloorBlock::FloorBlock(QGraphicsPixmapItem *parent, int x, int y, QString screen)
{
    int random_number = rand() %700;
    setPos(x,y);
    setPixmap(QPixmap(":/assets/fileblock.png"));
    setScale(4);
    QTimer * timer = new QTimer(this);
    if (screen == "Menu"){
        connect(timer,SIGNAL(timeout()),this,SLOT(moveinMenu()));
    }
    else{
        connect(timer,SIGNAL(timeout()),this,SLOT(moveinGame()));
    }
       // start the timer
    timer->start(50);
    xVelocity = 10;
}

void FloorBlock::moveinGame(){
    setPos(x()-xVelocity,y());
    if(pos().x()<-150 && pos().y()>=600){

        Game::game->spawner->spawn();
        delete this;
    }
    else if(pos().x()<-150){
        delete this;
    }
}
void FloorBlock::moveinMenu(){
    setPos(x()-xVelocity,y());
    if(pos().x()<-150){

        StartScreen::spawner->spawnforMenu();
        delete this;
    }

}
