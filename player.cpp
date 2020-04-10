#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "hitboxx.h"
//#include "Enemy.h"
#include <QTimer>
#include "floorBlock.h"
#include <QList>
#include "game.h"
#include <QDebug>
#include "hitboxy.h"
#include<QGraphicsPixmapItem>
#include <QMediaPlayer>

extern Game * game; // there is an external global object called game

Player::Player(QGraphicsPixmapItem *parent): QGraphicsPixmapItem(parent){
    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);

    QTimer * timerSprite = new QTimer(this);
    connect(timerSprite,SIGNAL(timeout()),this,SLOT(nextFrame()));
    timerSprite->start(75);

    currentFrame = 0;   // Sets the coordinates of the current frame of the sprite
    spriteImage = new QPixmap(":/assets/runspritesheet.png");
    runningSprite = new QPixmap(":/assets/runspritesheet.png"); // Load the sprite image QPixmap
    idleSprite = new QPixmap(":/assets/idlespritesheet.png");
    jumpSprite = new QPixmap(":/assets/jumpspritesheet.png");
//    setPixmap(QPixmap(":/assets/playercharacter_idle1.png"));
//    setScale(3);
    jumping = 0;
    flashing = 0;
    flash = false;
    vspeed = 0;
    xspeed = 0;
    canjump = 0;
    grav = 0;
    collider = 0;
    yCollision = 0;
    xCollision = 0;

}

QRectF Player::boundingRect() const
{
    return QRectF(-5,-20,60,60);
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /* In the graphic renderer we draw the sprite
     * The first two arguments - is the X and Y coordinates of where to put QPixmap
     * The third argument - a pointer to QPixmap
     * 4 and 5 of the arguments - The coordinates in the image QPixmap, where the image is displayed
     * By setting the X coordinate with the variable currentFrame we would like to move the camera on the sprite
     * and the last two arguments - the width and height of the displayed area, that is, the frame
     * */
    painter->drawPixmap(-5,-20, *spriteImage, currentFrame, 0, 60,60);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player up and down
    if (event->key() == Qt::Key_Space){
        if (canjump){
            vspeed = vspeed + 36;
            QMediaPlayer * jump;
            jump = new QMediaPlayer;
            jump->setMedia(QUrl("qrc:/music/assets/jump.mp3"));
            jump->play();
            jumping = 1;
            nextFrame();
        }
    }
    // shoot with the spacebar
    /*
    else if (event->key() == Qt::Key_Space){
        // create a bullet

        Bullet * bullet = new Bullet();
        bullet->setPos(x(),y());
        scene()->addItem(bullet);
    }*/

}
void Player::keyReleaseEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Space){
        if (canjump && vspeed > 0){

            vspeed = vspeed/2;
            qDebug() << vspeed;
            nextFrame();

        }
//        else if(canjump && vspeed <=0){
//            vspeed = vspeed - 16;
//        }
    }
}



void Player::nextFrame()
{
    /* At a signal from the timer 20 to move the point of rendering pixels
     * If currentFrame = 300 then zero out it as sprite sheet size of 300 pixels by 20
     * */

    if (Game::game->hitBoxP->ImInvincibleBaby > 0){

            flashing+=1;
            //qDebug()<<"Flashing!!!";
            if (flashing>=5) {
                flash = true;
                flashing=0;
            } else {
                flash = false;
            }
            if (flash){
                this->setOpacity(0);
            }
            else{
                this->setOpacity(1);
            }
            this->update(-5, -20,60,60);
    }
    else{
        flashing = 0;
        flash = false;
        this->setOpacity(1);
    }
    if (yCollision != 1){
        spriteImage = jumpSprite;
        if (jumping < 2) {
            jumping+=2;
            currentFrame = 0;
        }
        else{
            currentFrame = 60;
        }
        this->update(-5, -20,60,60);
    }
    else if (yCollision == 1){
        jumping = 0;
        currentFrame += 60;
        spriteImage = runningSprite;
        if (currentFrame >=600) currentFrame = 0;
        this->update(-5, -20,60,60);
    }
    if (xCollision == 1){
        currentFrame += 60;
        spriteImage = idleSprite;
        if (currentFrame >= 120) currentFrame = 0;
        this->update(-5, -20,60,60);
    }



}

void Player::move(){

   // game->ybullet->setPos(x(),y()+101);

    if(vspeed > 36){
        vspeed = 36;
    }
    else if(vspeed < -30){
        vspeed = -30;
    }

    canjump = 0;

    if(xCollision == 1){
        //qDebug()<< "we have collided in the x";
        //setPos(x()-10,y());
        xspeed = -10;
    }
    else if(x()< 150){
        //setPos(x()+2, y());
        xspeed = 2;
    }



    if (yCollision == 1){
        //qDebug()<< "touching";
        //qDebug()<< vspeed;

        canjump = 1;
        if(vspeed <= 0){
            vspeed = 0;
        }
        if(y() > 290 && y() < 340){
            setPos(x(),330);
            if(vspeed == 18){
                vspeed = 0;
            }

        }
        else if(y() > 240 && y() <= 290){
            //qDebug()<<vspeed;
            setPos(x(),266);
            if(vspeed == 18){
                vspeed = 0;
            }

        }
        else if(y()>100 && y()<=240){
            setPos(x(),204);
            if(vspeed == 18){
                vspeed = 0;
            }

        }
    }
    else{
        vspeed = vspeed - 4;
        //qDebug()<< "gravity ahh";
    }

    if(x()<-132 || y()> 700){
        Game::game->spawner->enemyCounter = 30;
        Game::game->scene->removeItem(Game::spawner);
        Game::game->scene->removeItem(Game::game->bug1);
        Game::game->scene->removeItem(Game::game->spike1);
        Game::game->scene->removeItem(Game::game->file1);
        Game::game->displayGameOver();
    }

    setPos(x()+ xspeed,y()-vspeed);
    xspeed = 0;
   // qDebug()<< canjump;
    // get a list of all the items currently colliding with this player
    /*
    QList<QGraphicsItem *> colliding_items = collidingItems();



    if (pos().y() < 390){
    vspeed = vspeed - 6;
    }
    if(vspeed < 0){


    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Block)){

            if(y() - colliding_items[i]->y() > 99){
            // increase the score
            game->score->increase();
            canjump = 1;

            vspeed = 0;
            setPos(x(),400);
            }
            else if(y() - colliding_items[i]->y() <= 99){
                xspeed = 10;

            }

            // return (all code below refers to a non existint bullet)
            return;
        }
    }
    }

  //  vspeed = vspeed - grav;
    setPos(x()+ xspeed,y()-vspeed);
    xspeed = 0;*/

}

