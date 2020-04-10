#include "spike.h"
#include "enemyFile.h"
#include<QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include "game.h"
Spike::Spike(QGraphicsPixmapItem * parent, int y)
{
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    // start the timer
    setPixmap(QPixmap(":/assets/spike.png"));
    setScale(3);
    setOffset(0,-20);
    timer->start(50);
    setPos(800, y);
    counter = 0;

}


void Spike::move(){
    if(x() > -120){
        setPos(x()-10,y());
    }
    else{
        Game::game->spawner->spikeInUse = 0;
    }

}
