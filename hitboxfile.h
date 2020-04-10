#ifndef HITBOXFILE_H
#define HITBOXFILE_H


#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>

class HitBoxFile: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    HitBoxFile(QGraphicsItem * parent=0);
    bool collision;
public slots:
    void move();
};

#endif // HITBOXFILE_H
