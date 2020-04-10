#ifndef GAME_H
#define GAME_H
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QWidget>
#include "hitboxleftbug.h"
#include "hitboxrightbug.h"
#include "hitboxmainbug.h"
#include "floorblockspawner.h"
#include "player.h"
#include "startscreen.h"
#include "optionsmenu.h"
#include "hitboxx.h"
#include "hitboxy.h"
#include "hitboxp.h"
#include <QMediaPlayer>
#include "enemyFile.h"
#include "enemyBug.h"
#include "hitboxfile.h"
#include "hitboxextraxp.h"
#include "hitboxspike.h"
#include "spike.h"




class Game: public QGraphicsView
{
    Q_OBJECT
public:
    Game(QWidget* parent=NULL);
    static Game *game;
    static StartScreen* sc;
    static OptionsMenu* oc;
    static floorBlockSpawner *spawner;
    static QMediaPlayer * music;
    static Screen *background;
    int cScore;
    int health;
    void gameOver();
    void displayMainMenu();
    void displayGameOver();
    void displayControlMenu();
    void displayOptionsMenu();
    void updateScore(int);
    void updateHealth();
    QGraphicsScene* scene;
    Player *player;
    HitBoxX *hitBoxX;
    HitBoxY *hitBoxY;
    HitBoxP *hitBoxP;
    enemyFile *file1;
    enemyBug *bug1;
    Spike *spike1;
    HitBoxSpike *hitBoxSpike;
    HitBoxLeftBug* hitBoxLeftBug;
    HitBoxRightBug* hitBoxRightBug;
    HitBoxMainBug* hitBoxMainBug;
    HitBoxExtraP *HitBoxExtrap;
    HitBoxFile *hitBoxFile;
    int replayMusic = 0;
    QGraphicsTextItem *scoreDisplay;
    QGraphicsTextItem *healthDisplay;





public slots:
    void start();
    void restartGame();


private:
    void drawGUI();

};

#endif // GAME_H
