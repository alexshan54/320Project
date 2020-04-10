#include "object.h"
#include <string>
#include <QPaintEvent>
#include <QPixmap>
#include <QPainter>


Object::Object():QObject(){}
//Main Constructor
Object::Object(string spr,int xV, int yV,int loc[2]) :sprite(spr), xVelocity(xV), yVelocity(yV) {
    this->location[0] = loc[0];
    this->location[1] = loc[1];

}

//Advance the object
void Object::Advance(){
    location[0] = location[0] + xVelocity;
    location[1] = location[1] + yVelocity;
}

void Object::Paint(){

}

void Object::Delete(){
    //Deletes the object
}

