#ifndef ENEMYBUG_H
#define ENEMYBUG_H


#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class enemyBug:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:

    enemyBug(QGraphicsPixmapItem * parent=0, int y = 200);
    int counter;
    bool hLeft;
    bool hRight;
    int xspeed;
    bool hitwall;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QPixmap *spriteImage;   // In this QPixmap object will be placed sprite
    QPixmap *invertedImage;
    QPixmap *regularImage;
    QPixmap tmp;
    int currentFrame;   // Coordinates X, which starts the next frame of the sprite

public slots:
    void move();
    void nextFrame();   // Slot for turning images into QPixmap

};

#endif // ENEMYBUG_H
