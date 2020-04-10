#include "enemyFile.h"
#include<QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include "game.h"
enemyFile::enemyFile(QGraphicsPixmapItem * parent, int y): QGraphicsPixmapItem(parent)
{
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    // start the timer
    setPixmap(QPixmap(":/assets/corrupted_file.png"));
    setScale(3);
    setOffset(0,-20);
    timer->start(50);
    setPos(800, y);

    QTimer * timerSprite = new QTimer(this);
    connect(timerSprite,SIGNAL(timeout()),this,SLOT(nextFrame()));
    timerSprite->start(100);
    currentFrame = 0;   // Sets the coordinates of the current frame of the sprite
    spriteImage = new QPixmap(":/assets/filespritesheet.png");

    counter = 0;
    flyLikeABird = 0;
}
void enemyFile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    /* In the graphic renderer we draw the sprite
     * The first two arguments - is the X and Y coordinates of where to put QPixmap
     * The third argument - a pointer to QPixmap
     * 4 and 5 of the arguments - The coordinates in the image QPixmap, where the image is displayed
     * By setting the X coordinate with the variable currentFrame we would like to move the camera on the sprite
     * and the last two arguments - the width and height of the displayed area, that is, the frame
     * */
    painter->drawPixmap(-4,-20, *spriteImage, currentFrame, 0, 36, 19);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
QRectF enemyFile::boundingRect() const
{
    return QRectF(-4,-20,36,19);
}

void enemyFile::nextFrame()
{
    /* At a signal from the timer 20 to move the point of rendering pixels
     * If currentFrame = 300 then zero out it as sprite sheet size of 300 pixels by 20
     * */

        currentFrame += 36;
        if (currentFrame >= 144) currentFrame = 0;
        this->update(-4,-20,36,19);

}

void enemyFile::move(){

    if(x() > -120){
        if(flyLikeABird == 0){
            if(counter < 5){
                counter++;
                setPos(x()-10, y()+11);
            }
            else{
                setPos(x()-10, y()-10);
                counter++;
                if(counter >10){
                    counter = 0;
                }
            }

        }
        else if(flyLikeABird ==1){
            if(counter < 5){
                counter++;
                setPos(x()-13, y()+11);
            }
            else{
                setPos(x()-13, y()-10);
                counter++;
                if(counter >10){
                    counter = 0;
                }
            }
        }
        else{
            if(counter < 5){
                counter++;
                setPos(x()+3, y()+11);
            }
            else{
                setPos(x()+3, y()-9);
                counter++;
                if(counter >10){
                    counter = 0;
                }
            }
            if(x()< -120){
                delete this;
            }
        }
        flyLikeABird ++;
        if(flyLikeABird == 3){
            flyLikeABird = 0;
        }
    }
    else{
        Game::game->spawner->fileEnemyInUse = 0;
    }



}
