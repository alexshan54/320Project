#include <QtWidgets>
#include <QObject>
#include <QTimer>
#include <QDebug>

#include "screen.h"
#include "system.h"

Screen::Screen(QString bg): QObject()

{
    backgroundImageCounter = 0;
    gradiantIncreasing = false;
    BackgroundPic = bg;
    QTimer * timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(transitionBackground()));
    timer->start(80);
    background = new QGraphicsPixmapItem();
    background->setPixmap(QPixmap(":/assets/background.png"));
    background->setScale(5);

}

void Screen::setBackground(QGraphicsScene * scene)
{

}

void inputHap()
{

}

void Screen::InitBackground(QGraphicsScene * scene){

    scene->addItem(background);
}

void Screen::transitionBackground(){
    if (gradiantIncreasing == false){
        backgroundImageCounter+=0.007;
        if (backgroundImageCounter>=0.18) {
            gradiantIncreasing = true;
            qDebug() << "Resetting  to max";
        }
    }else {
        backgroundImageCounter-=0.01;
        if (backgroundImageCounter<=0) {
            gradiantIncreasing = false;
            qDebug() << "Resetting  to Low";
        }
    }

    background->setOpacity(backgroundImageCounter);
    //background->update();

}
