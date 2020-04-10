#ifndef FLOORBLOCKSPAWNER_H
#define FLOORBLOCKSPAWNER_H
#include <QTimer>
#include <floorBlock.h>

class floorBlockSpawner: public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    floorBlockSpawner(QGraphicsItem * parent = 0);
    ~floorBlockSpawner();
    void InitBlock();
    void InitBlockforMenu();
    int height;
    int counter;
    int newHeight;
    int fileCounter;
    int enemyCounter;
    int difficulty;
    int bugCounter;
    int curSeq;
    bool fileEnemyInUse;
    bool bugEnemyInUse;
    int hpcounter;
    bool spikeInUse;
    int spikeCounter;
public slots:
    void spawn();
    void spawnforMenu();
};

#endif // FLOORBLOCKSPAWNER_H
