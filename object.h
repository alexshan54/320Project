#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <QPaintEvent>
#include <QPixmap>
#include <QPainter>
#include <QObject>

using namespace std;
class Object: public QObject
{
public:
    Object();
    Object(string, int, int,  int[]);
    void onHit();
    void Delete();
    void Paint();

    static Object visibleObjects;

    string sprite;
    int xVelocity;
    int yVelocity;
    int location[2];
private:


protected:
    void Advance();
};

#endif // OBJECT_H
