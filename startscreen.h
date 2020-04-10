#ifndef STARTSCREEN_H
#define STARTSCREEN_H
#include "screen.h"
#include "button.h"
#include <string>
#include "floorblockspawner.h"
#include "player.h"

using namespace std;

class StartScreen : public Screen
{
public:
    StartScreen(QString bg);
    void setBackground(QGraphicsScene * scene);
    QGraphicsTextItem **iArr;
    void changeHigh(int); // mod is either 1 or -1
    int getPos();
    void resetPos();
    static floorBlockSpawner *spawner;
    static Player *player;

    static int pos;
};

#endif // STARTSCREEN_H
