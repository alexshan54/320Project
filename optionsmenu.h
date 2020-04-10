#ifndef OPTIONSMENU_H
#define OPTIONSMENU_H
#include "screen.h"
#include "button.h"
#include <string>

using namespace std;

class OptionsMenu : public Screen
{
public:
    OptionsMenu(QString bg);
    void setBackground(QGraphicsScene * scene);
    QGraphicsTextItem **iArr;
    void changeHigh(int); // mod is either 1 or -1
    int getPos();
    void resetPos();
    void setCheck();
    QGraphicsPixmapItem *musicCheck;
    static int pos;

};

#endif // OPTIONSMENU_H
