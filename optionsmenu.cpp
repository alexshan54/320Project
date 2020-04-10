#include "optionsmenu.h"
#include "QGraphicsPixmapItem"
#include "system.h"
#include "game.h"

#include <QtWidgets>
#include <QObject>
#include <QTimer>
#include <QDebug>

#include "screen.h"
#include "ui_system.h"
#include "stdio.h"

using namespace std;
int OptionsMenu::pos;
OptionsMenu::OptionsMenu(QString bg):Screen(bg)
{
    pos = 0;
    buttonNames = new string[2];
    buttonNames[0] = "Music";
    buttonNames[1] = "Back";
}

void OptionsMenu::setBackground(QGraphicsScene * scene)
{
    scene->clear();
        scene->setBackgroundBrush(Qt::black);
        QGraphicsPixmapItem *background = new QGraphicsPixmapItem();
        background->setScale(5);
        scene->addItem(background);
        musicCheck = new QGraphicsPixmapItem();
        if(System::playMusic){
            musicCheck->setPixmap(QPixmap(":/assets/check.png"));
        }
        else{
            musicCheck->setPixmap(QPixmap(":/assets/uncheck.png"));
        }
        musicCheck->setScale(4);
        musicCheck->setPos(630,140);
        scene->addItem(musicCheck);

        QFont titleFont("Retro Gaming", 40, QFont::Normal);
        QFont optionFont("Retro Gaming", 32, QFont::Normal);

    //Set Title
        QGraphicsTextItem * title = new QGraphicsTextItem; //title
        title->setPos(0,-15);
        title->setPlainText("runtime_exception");
        title->setDefaultTextColor(Qt::green);
        title->setFont(titleFont);
        scene->addItem(title);

        iArr = new QGraphicsTextItem*[2];


        //QGraphicsTextItem * start = new QGraphicsTextItem; //Start
        iArr[0] = new QGraphicsTextItem;
        iArr[0]->setPos(450,120);
        iArr[0]->setPlainText((">" + buttonNames[0]).c_str());
        iArr[0]->setDefaultTextColor(Qt::green);
        iArr[0]->setFont(optionFont);
        scene->addItem(iArr[0]);
        iArr[1] = new QGraphicsTextItem; //Options
        iArr[1]->setPos(450,180);
        iArr[1]->setPlainText(buttonNames[1].c_str());
        iArr[1]->setDefaultTextColor(Qt::darkGreen);
        iArr[1]->setFont(optionFont);
        scene->addItem(iArr[1]);
}
void OptionsMenu::changeHigh(int mod){
    iArr[pos]->setPlainText(buttonNames[pos].c_str());
    iArr[pos+ mod]->setPlainText((">" + buttonNames[pos + mod]).c_str());
    iArr[pos]->setDefaultTextColor(Qt::darkGreen);
    iArr[pos+ mod]->setDefaultTextColor(Qt::green);
    pos = pos + mod;
}
int OptionsMenu::getPos(){
    return pos;
}
void OptionsMenu::resetPos(){
    pos = 0;
}
void OptionsMenu::setCheck(){
    if(System::playMusic){
        musicCheck->setPixmap(QPixmap(":/assets/check.png"));
    }
    else{
        musicCheck->setPixmap(QPixmap(":/assets/uncheck.png"));
    }
}

