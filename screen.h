#ifndef SCREEN_H
#define SCREEN_H

#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QMainWindow>
#include "button.h"

class Screen: public QObject
{
    Q_OBJECT
public:
    Screen(QString bg = "");
    void setBackground(QGraphicsScene * scene);
    string* buttonNames;
    void InitBackground(QGraphicsScene * scene);
    QGraphicsPixmapItem *background;
    QTimer *timer;      // Timer for turning images into QPixmap

private:
    QString BackgroundPic;
    bool gradiantIncreasing;
    float backgroundImageCounter;
   // QList<Button> theButtonList;
    void inputHap();

public slots:
    void transitionBackground();

};

#endif // SCREEN_H
