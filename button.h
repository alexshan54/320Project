#ifndef BUTTON_H
#define BUTTON_H

#pragma once
#include <QWidget>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>
#include <QMediaPlayer>
using namespace std;

class Button : public QGraphicsRectItem {
    //Q_OBJECT
public:
    Button();
    void keyPressEvent(QKeyEvent *event);
    //QRectF boundingRect() const override;
   // void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void Highlight();

    //Q_DISABLE_COPY(Button);
private:
    QMediaPlayer * music;
};

class Cursor {
public:
    Cursor();

private:
    void clickevent();





};




#endif // BUTTON_H
