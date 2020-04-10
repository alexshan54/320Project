#include "enemyBug.h"
#include<QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include "game.h"
enemyBug::enemyBug(QGraphicsPixmapItem * parent, int y): QGraphicsPixmapItem(parent)
{
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    // start the timer
    setPixmap(QPixmap(":/assets/bug_1.png"));
    setScale(3);
    setOffset(0,-20);
    timer->start(50);
    setPos(796, y);
    counter = 0;
    hLeft = 1;
    hRight = 1;
    xspeed = 0;
    hitwall = 0;

    QTimer * timerSprite = new QTimer(this);
    connect(timerSprite,SIGNAL(timeout()),this,SLOT(nextFrame()));
    timerSprite->start(75);
    currentFrame = 0;   // Sets the coordinates of the current frame of the sprite
    spriteImage = new QPixmap(":/assets/bugspritesheet.png");

    regularImage = new QPixmap(":/assets/backwardsbugspritesheet.png");
    invertedImage = new QPixmap(":/assets/bugspritesheet.png");

}

void enemyBug::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /* In the graphic renderer we draw the sprite
     * The first two arguments - is the X and Y coordinates of where to put QPixmap
     * The third argument - a pointer to QPixmap
     * 4 and 5 of the arguments - The coordinates in the image QPixmap, where the image is displayed
     * By setting the X coordinate with the variable currentFrame we would like to move the camera on the sprite
     * and the last two arguments - the width and height of the displayed area, that is, the frame
     * */
    painter->drawPixmap(0,-20, *spriteImage, currentFrame, 0, 24, 16);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
QRectF enemyBug::boundingRect() const
{
    return QRectF(0,-20,24,16);
}

void enemyBug::nextFrame()
{
    /* At a signal from the timer 20 to move the point of rendering pixels
     * If currentFrame = 300 then zero out it as sprite sheet size of 300 pixels by 20
     * */

        if (xspeed<0){
            spriteImage=invertedImage;
        }
        else{
            spriteImage=regularImage;
        }
        currentFrame += 24;
        if (currentFrame >= 48) currentFrame = 0;
        this->update(0,-20,24, 16);

}
void enemyBug::move(){
    if(x() > 0){
        if(hLeft && hRight){
            xspeed = xspeed;
        }else if(hLeft && !hRight){
            xspeed = -18;
        }else if(!hLeft && hRight){
            xspeed = 2;
        }
    }
    if(hitwall){
        if(xspeed == -18){
            xspeed = 2;
            setPos(x()+8,y());

        }else{
            xspeed = -18;
            setPos(x()-8,y());

        }
    }

    setPos(x()+xspeed,y());


    if(x()< -120){
        Game::game->spawner->bugEnemyInUse = 0;
    }
}
