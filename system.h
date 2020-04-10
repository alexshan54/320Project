#ifndef SYSTEM_H
#define SYSTEM_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsRectItem>
#include <QKeyEvent>
#include <QObject>

QT_BEGIN_NAMESPACE
namespace Ui { class System; }
QT_END_NAMESPACE

class System{

public:
    System();
    ~System();   

    static bool showOptionsScreen;
    static bool showMenuScreen;
    static bool showGameOverScreen;
    static bool showControlsScreen;
    static bool showGameScreen;
    static bool playMusic;

    void Save();
    void Load();
    Ui::System *ui;
};
#endif // SYSTEM_H
