#ifndef ENEMYFILE_H
#define ENEMYFILE_H


#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>

class enemyFile:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:

    enemyFile(QGraphicsPixmapItem * parent=0, int y = 200);
    int counter;
    int flyLikeABird;
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    QPixmap *spriteImage;   // In this QPixmap object will be placed sprite
    int currentFrame;   // Coordinates X, which starts the next frame of the sprite


public slots:
    void move();
    void nextFrame();   // Slot for turning images into QPixmap

};

#endif // ENEMYFILE_H
