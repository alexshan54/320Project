#include "startscreen.h"
#include "QGraphicsPixmapItem"
#include "system.h"
#include "game.h"
#include "hitboxp.h"
#include "hitboxx.h"
#include "hitboxy.h"
#include "sprite.h"


#include <QtWidgets>
#include <QObject>
#include <QTimer>
#include <QDebug>

#include "screen.h"
#include "ui_system.h"
#include "stdio.h"

#include <stdio.h>

using namespace std;
int StartScreen::pos;
floorBlockSpawner *StartScreen::spawner;
Player *StartScreen::player;


StartScreen::StartScreen(QString bg):Screen(bg)
{
    pos = 0;
    buttonNames = new string[4];
    buttonNames[0] = "Play";
    buttonNames[1] = "Options";
    buttonNames[2] = "Controls";
    buttonNames[3] = "Exit";

    // add the player to the scene
    StartScreen::spawner = new floorBlockSpawner();

}

void StartScreen::setBackground(QGraphicsScene * scene)
{
    scene->clear();
    InitBackground(scene); //Transient wires in background
    scene->setBackgroundBrush(Qt::black);
    QFontDatabase::addApplicationFont(":/assets/Retro Gaming.ttf");

    char buffer[10];
    string score;
    FILE * data;
    data = fopen("Data.txt", "r");
    if (data!=NULL)
    {
        fscanf(data,"%s",buffer);
        score = buffer;
        fclose (data);
    }
    else{
        fclose (data);
        data = fopen("Data.txt","w");
        score = "0";
        fputs(score.c_str(),data);
        fclose (data);
    }
    QGraphicsTextItem * hScore = new QGraphicsTextItem; //title
    hScore->setPos(5,65);
    hScore->setPlainText(("High Score: " + score).c_str());
    hScore->setDefaultTextColor(Qt::darkGreen);
    hScore->setFont(QFont("Retro Gaming", 20, QFont::Normal));
    scene->addItem(hScore);

    //Set Title
    QGraphicsTextItem * title = new QGraphicsTextItem; //title
    title->setPos(0,0);
    title->setPlainText("runtime_exception");
    title->setDefaultTextColor(Qt::green);
    QFont titleFont("Retro Gaming", 40, QFont::Normal);
    title->setFont(titleFont);
    scene->addItem(title);

    iArr = new QGraphicsTextItem*[4];


    //QGraphicsTextItem * start = new QGraphicsTextItem; //Start
    QFont optionFont("Retro Gaming", 32, QFont::Normal);

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

    iArr[2] = new QGraphicsTextItem; //Controls
    iArr[2]->setPos(450,240);
    iArr[2]->setPlainText(buttonNames[2].c_str());
    iArr[2]->setDefaultTextColor(Qt::darkGreen);
    iArr[2]->setFont(optionFont);
    scene->addItem(iArr[2]);

    iArr[3] = new QGraphicsTextItem; //Exit
    iArr[3]->setPos(450,300);
    iArr[3]->setPlainText(buttonNames[3].c_str());
    iArr[3]->setDefaultTextColor(Qt::darkGreen);
    iArr[3]->setFont(optionFont);
    scene->addItem(iArr[3]);

    //        QGraphicsPixmapItem *player = new QGraphicsPixmapItem();
    //        player->setPixmap(QPixmap(":/assets/playercharacter_idle1.png"));
    //        player->setScale(3);
    //        player->setPos(150,270);
    //        scene->addItem(player);

    Sprite *  playerSprite= new Sprite();
    scene->addItem(playerSprite);
    playerSprite->setScale(3.5);


}


void StartScreen::changeHigh(int mod){
    iArr[pos]->setPlainText(buttonNames[pos].c_str());
    iArr[pos+ mod]->setPlainText((">" + buttonNames[pos + mod]).c_str());
    iArr[pos]->setDefaultTextColor(Qt::darkGreen);
    iArr[pos+ mod]->setDefaultTextColor(Qt::green);

    pos = pos + mod;
}
int StartScreen::getPos(){
    return pos;
}
void StartScreen::resetPos(){
    pos = 0;
}
