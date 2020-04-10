#include "game.h"
#include "button.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include "system.h"
#include <QDebug>
#include "floorblockspawner.h"
#include "startscreen.h"
#include "player.h"
#include "enemyFile.h"
#include "enemyBug.h"
#include <QMediaPlayer>
#include <stdio.h>
#include <sstream>
#include "hitboxleftbug.h"
#include "hitboxrightbug.h"


Game *Game::game;
StartScreen *Game::sc;
floorBlockSpawner *Game::spawner;
OptionsMenu *Game::oc;
QMediaPlayer *Game::music;
Screen *Game::background;

Game::Game(QWidget *parent)
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(750, 500);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,750,500);
    setScene(scene);
    Game::spawner = new floorBlockSpawner();
    Game::sc = new StartScreen("StartScreen");
    Game::oc = new OptionsMenu("Options Menu");
    Game::background = new Screen();
    System::showMenuScreen = true;
    System::playMusic = true;
    music = new QMediaPlayer;
    music->setMedia(QUrl("qrc:/music/assets/runtimeexception_music2.mp3"));
    music->play();
    cScore = 0;
    health = 3;
}

void Game::start(){
    // initialize

    // clear the screen
    qDebug()<<"in start function";

    scene->removeItem(StartScreen::spawner);
    scene->removeItem(sc->background);

   // sc->timer->stop();

    scene->clear();

    drawGUI();

}

void Game::restartGame(){
    scene->clear();
    start();
}


void Game::drawGUI(){

    Game::background->InitBackground(scene);
    scene->addItem(Game::spawner);
    qDebug() << "Added spawner to scene";

    Game::spawner->InitBlock();
    player = new Player();
    // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(150,300); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);
    player->setScale(3);

    file1 = new enemyFile();
    file1->setPos(-120,250);
    scene->addItem(file1);

    HitBoxExtrap = new HitBoxExtraP();
    scene->addItem(HitBoxExtrap);
    bug1 = new enemyBug();
    bug1->setPos(-160,300);
    scene->addItem(bug1);
    hitBoxLeftBug = new HitBoxLeftBug();
    scene->addItem(hitBoxLeftBug);
    hitBoxRightBug = new HitBoxRightBug();
    scene->addItem(hitBoxRightBug);
    hitBoxMainBug = new HitBoxMainBug();
    scene->addItem(hitBoxMainBug);
    spike1 = new Spike();
    spike1->setPos(-160,300);
    scene->addItem(spike1);
    hitBoxSpike = new HitBoxSpike();
    scene->addItem(hitBoxSpike);
    hitBoxX = new HitBoxX();
    scene->addItem(hitBoxX);
    hitBoxY = new HitBoxY();
    scene->addItem(hitBoxY);
    hitBoxP = new HitBoxP();
    scene->addItem(hitBoxP);
    hitBoxFile = new HitBoxFile();
    scene->addItem(hitBoxFile);
    Game::scoreDisplay = new QGraphicsTextItem;
    Game::scoreDisplay->setPos(5,0);
    Game::scoreDisplay->setPlainText("Score: 0");
    Game::scoreDisplay->setDefaultTextColor(Qt::darkGreen);
    Game::scoreDisplay->setFont(QFont("Retro Gaming", 20, QFont::Normal));
    scene->addItem(Game::scoreDisplay);
    health = 3;
    Game::healthDisplay = new QGraphicsTextItem;
    Game::healthDisplay->setPos(5,35);
    Game::healthDisplay->setPlainText(("Health: " + to_string(health)).c_str());
    Game::healthDisplay->setDefaultTextColor(Qt::darkGreen);
    Game::healthDisplay->setFont(QFont("Retro Gaming", 20, QFont::Normal));
    scene->addItem(Game::Game::healthDisplay);


}

void Game::displayMainMenu(){
    if ((replayMusic == 1) && (System::playMusic)){
        music->play();
    }


    sc->setBackground(scene);

    Button *button = new Button();
    button->setRect(0,0,750,500);
    scene->addItem(button);

    button->setFlag(QGraphicsItem::ItemIsFocusable);
    button->show();
    button->setFocus();
    qDebug() << "focus?:" << scene->hasFocus();

    scene->addItem(StartScreen::spawner);
    StartScreen::spawner->InitBlockforMenu();
    System::showMenuScreen = true;
}


void Game::displayGameOver(){

    char buffer[10];
    string score;
    FILE * data;
    data = fopen("Data.txt","r");
    if (data!=NULL)
    {
        fscanf(data,"%s",buffer);
        score = buffer;
        fclose (data);
    }
    int hScore;
    std::istringstream(score) >> hScore;
    if(cScore > hScore){
        score = to_string(cScore);
    }

    data = fopen("Data.txt","w");
    fputs(score.c_str(),data);
    fclose(data);
    cScore = 0;

    // disable all scene items
    System::showGameScreen = false;
    scene->removeItem(background->background);
    scene->clear();

    QGraphicsPixmapItem *pic = new QGraphicsPixmapItem();
    pic->setPixmap(QPixmap(":/assets/gameover.png"));
    pic->setScale(5);
    scene->addItem(pic);
    Button *button = new Button();
    button->setRect(0,0,750,500);
    scene->addItem(button);
    button->setFlag(QGraphicsItem::ItemIsFocusable);
    button->show();
    button->setFocus();
    System::showGameOverScreen = true;
    QMediaPlayer * death;
    death = new QMediaPlayer;
    death->setMedia(QUrl("qrc:/music/assets/death.mp3"));
    death->play();
    music->stop();
    replayMusic = 1;

}

void Game::displayControlMenu(){
    scene->removeItem(StartScreen::spawner);
    scene->removeItem(sc->background);
    //sc->timer->stop();
    scene->clear();
    scene->setBackgroundBrush(Qt::black);
    QGraphicsPixmapItem *background = new QGraphicsPixmapItem();
    background->setPixmap(QPixmap(":/assets/controls.png"));
    background->setScale(3);
    scene->addItem(background);
    /*QGraphicsPixmapItem *startButton = new QGraphicsPixmapItem();
    startButton->setPixmap(QPixmap(":/assets/start.png"));
    startButton->setScale(5);
    startButton->setPos(270,400);
    scene->addItem(startButton);*/

    QGraphicsTextItem * title2 = new QGraphicsTextItem; //title
    title2->setPos(280,400);
    title2->setPlainText(">back");
    title2->setDefaultTextColor(Qt::green);
    QFont optionFont("Retro Gaming", 32, QFont::Normal);
    title2->setFont(optionFont);
    scene->addItem(title2);
    Button *button = new Button();
    button->setRect(0,0,750,500);
    scene->addItem(button);

    button->setFlag(QGraphicsItem::ItemIsFocusable);
    button->show();
    button->setFocus();
    qDebug() << "focus?:" << scene->hasFocus();


    System::showMenuScreen = true;
}
void Game::displayOptionsMenu(){
    scene->removeItem(StartScreen::spawner);
    scene->removeItem(sc->background);
    //sc->timer->stop();
    scene->clear();
    oc->setBackground(scene);

    Button *button = new Button();
    button->setRect(0,0,750,500);
    scene->addItem(button);

    button->setFlag(QGraphicsItem::ItemIsFocusable);
    button->show();
    button->setFocus();
    qDebug() << "focus?:" << scene->hasFocus();
    replayMusic = 0;
    System::showOptionsScreen = true;
}

void Game::updateScore(int inc){
    cScore = cScore + inc;
    Game::scoreDisplay->setPlainText(("Score: " + to_string(cScore)).c_str());

}

void Game::updateHealth(){
    Game::healthDisplay->setPlainText(("Health: " + to_string(health)).c_str());
    if(health <= 0){
        health = 3;
        Game::game->spawner->enemyCounter = 30;
        Game::game->scene->removeItem(Game::spawner);
        Game::game->scene->removeItem(Game::game->bug1);
        Game::game->scene->removeItem(Game::game->spike1);
        Game::game->scene->removeItem(Game::game->file1);
        Game::game->displayGameOver();
    }
}

