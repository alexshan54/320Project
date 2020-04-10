#include "floorblockspawner.h"
#include "floorBlock.h"
#include "game.h"
#include <QTimer>
#include <QList>
#include "stdlib.h"
#include "enemyFile.h"
#include "enemyBug.h"
#include "poweruphealth.h"
QRectF floorBlockSpawner::boundingRect() const{
          qreal penWidth = 1;
          return QRectF(-10 - penWidth / 2, -10 - penWidth / 2,
                        20 + penWidth, 20 + penWidth);
      }
void floorBlockSpawner::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                 QWidget *widget)
      {
          painter->drawRoundedRect(-10, -10, 20, 20, 5, 5);
      }

floorBlockSpawner::floorBlockSpawner(QGraphicsItem *parent):QObject(),QGraphicsItem()
{
    srand(time(NULL));
    counter = 1;
    height = 1;
    newHeight = 1;
    fileCounter = 0;
    bugCounter = 0;
    enemyCounter= 0;
    spikeCounter = 0;
    difficulty = 1;
    curSeq = 0;
    fileEnemyInUse = 0;
    bugEnemyInUse = 0;
    spikeInUse = 0;
    hpcounter = 40;
//    int random_number = rand() % 700;
//    setPos(random_number,0);
//    QTimer * timer = new QTimer(this);
//    connect(timer,SIGNAL(timeout()),this,SLOT(spawn()));
//    timer->start(370);

}

void floorBlockSpawner::InitBlock(){
    QList<FloorBlock *> blockList;

        for(int i = 0; i< 16; i++){
            FloorBlock *floorBlocks = new FloorBlock(0,-151+60*i,436);
            blockList.append(floorBlocks);
            scene()->addItem(blockList[i]);
        }

        QList<FloorBlock *> blockList2;
        for(int i = 0; i< 16; i++){
            FloorBlock *floorBlocks = new FloorBlock(0,-151+60*i,600);
            blockList2.append(floorBlocks);
            scene()->addItem(blockList2[i]);
        }
}
void floorBlockSpawner::InitBlockforMenu(){
    QList<FloorBlock *> blockList;

    for(int i = 0; i< 16; i++){
        FloorBlock *floorBlocks = new FloorBlock(0,-151+60*i,436, "Menu");
        blockList.append(floorBlocks);
        scene()->addItem(blockList[i]);
    }

}
floorBlockSpawner::~floorBlockSpawner(){
    delete this;
}

void floorBlockSpawner::spawn(){
    Game::game->updateScore(1);
    if(counter == 0){
        counter = rand() %2 +1;
        curSeq = counter;
        if(height == 0){
            counter =2;
            newHeight = 1;
        }
        else if(height == 1){
            int randInt = rand() %6;
            if(randInt == 0 || randInt == 3){
                newHeight = height;

            }
            else if(randInt == 1 || randInt == 4){
               newHeight = height +1;
            }
            else if(randInt == 2){
                newHeight = 0;
            }
        }
        else if(height == 3){
            int randInt = rand() % 3;
            if(randInt == 0){
                newHeight = height;
            }
            else if(randInt == 2){
                newHeight = height -1;
            }
            else if(randInt == 1){
                newHeight = 1;
            }
        }
        else{
            int randInt = rand() % 3;
            if(randInt == 0){
                newHeight = height;
            }
            else if(randInt == 1){
                newHeight = height+1;
            }
            else if(randInt == 2){
                newHeight = height -1;
            }
        }
    }
    else{
        counter --;
    }

    switch(newHeight){
    case 0:{
        if(enemyCounter < 2){
            enemyCounter = 5;
        }
        break;
    }
    case 1:{
        FloorBlock *floorBlocks = new FloorBlock(0);
        scene()->addItem(floorBlocks);

        if(height == newHeight && bugEnemyInUse == 0){
            if(bugCounter < 0 && enemyCounter < 0 && curSeq == 2){
                Game::game->bug1->setPos(800,454);
                bugEnemyInUse = 1;
                bugCounter = 20;
                enemyCounter = 20-difficulty;
            }
        }

        if(height == newHeight && spikeInUse == 0){

            if(fileCounter < 0 && enemyCounter < 0){
                Game::game->spike1->setPos(800,454);
                spikeInUse = 1;
                spikeCounter = 30;
                enemyCounter = 20-difficulty;
            }
        }

        if(height != 3 && height != 2 && fileEnemyInUse == 0){

            if(fileCounter < 0 && enemyCounter < 0){
                Game::game->file1->setPos(800,150);
                fileEnemyInUse = 1;
                fileCounter = 20;
                enemyCounter = 20-difficulty;
            }
        }


        if(hpcounter < 0){
            powerupHealth *poweruphealth = new powerupHealth(0,400);
            scene()->addItem(poweruphealth);
            hpcounter = 50;
        }




        break;
    }

    case 2:{
        FloorBlock *floorBlocks2 = new FloorBlock(0);
        FloorBlock *floorBlocks1 = new FloorBlock(0,796,372);
        scene()->addItem(floorBlocks1);
        scene()->addItem(floorBlocks2);



        if(height == newHeight && bugEnemyInUse == 0){
            if(bugCounter < 0 && enemyCounter < 0 && curSeq == 2){
                Game::game->bug1->setPos(800,390);
                bugEnemyInUse = 1;
                bugCounter = 20;
                enemyCounter = 20-difficulty;
            }
        }



        if(height != 3){
            if(fileCounter < 0 && enemyCounter < 0 && fileEnemyInUse == 0){
                Game::game->file1->setPos(800,150);
                fileEnemyInUse = 1;
                fileCounter = 20;
                enemyCounter = 20-difficulty;
            }
        }

        if(hpcounter < 0){
            powerupHealth *poweruphealth = new powerupHealth(0,320);
            scene()->addItem(poweruphealth);
            hpcounter = 50;
        }

        break;
    }
    case 3:{
        FloorBlock *floorBlocks2 = new FloorBlock(0);
        FloorBlock *floorBlocks1 = new FloorBlock(0,796,372);
        scene()->addItem(floorBlocks1);
        scene()->addItem(floorBlocks2);
        FloorBlock *floorBlocks3 = new FloorBlock(0,796,308);
        scene()->addItem(floorBlocks3);
        newHeight = 3;
        if(height == newHeight && bugEnemyInUse == 0){
            if(bugCounter < 0 && enemyCounter < 0 && curSeq == 2){
                Game::game->bug1->setPos(800,328);
                bugEnemyInUse = 1;
                bugCounter = 20;
                enemyCounter = 20-difficulty;
            }
        }

        if(hpcounter < 0){
            powerupHealth *poweruphealth = new powerupHealth(0,260);
            scene()->addItem(poweruphealth);
            hpcounter = 50;
            enemyCounter +=5;
        }

        break;
    }
    default:{
        FloorBlock *floorBlocks2 = new FloorBlock(0);
        FloorBlock *floorBlocks1 = new FloorBlock(0,796,372);
        scene()->addItem(floorBlocks1);
        scene()->addItem(floorBlocks2);
        FloorBlock *floorBlocks3 = new FloorBlock(0,796,308);
        scene()->addItem(floorBlocks3);
        newHeight = 2;
        break;
    }

    }
    height = newHeight;
    FloorBlock *bedRock = new FloorBlock(0,796, 1500);
    scene()->addItem(bedRock);
    int subRand = rand()% 3;
    int subRand2 = rand()% 3;
    fileCounter -= subRand;
    enemyCounter -= subRand;
    bugCounter -= subRand2;
    hpcounter--;
    spikeCounter-=subRand;
    if (Game::game->cScore > 50){
        difficulty = 5;
    }
}

void floorBlockSpawner::spawnforMenu(){
    FloorBlock *floorBlocks = new FloorBlock(0,796,436, "Menu");
    scene()->addItem(floorBlocks);
    //qDebug()<<"Respawed a block";
}




