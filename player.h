#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsPixmapItem * parent = 0);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent *event);
    int vspeed;
    int xspeed;
    int grav;
    float jumping;
    float flashing;
    bool flash;
    bool canjump;
    bool collider;
    bool yCollision;
    bool xCollision;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QPixmap *spriteImage;   // In this QPixmap object will be placed sprite
    int currentFrame;   // Coordinates X, which starts the next frame of the sprite
    QPixmap *runningSprite;
    QPixmap *jumpSprite;
    QPixmap *idleSprite;

public slots:
    //void spawn();
    void move();
    void nextFrame();   // Slot for turning images into QPixmap


};

#endif // PLAYER_H
