#include "system.h"
#include "screen.h"
#include "startscreen.h"
#include "ui_system.h"
#include "game.h"
#include <QApplication>
#include <QGraphicsScene>

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

#include <QGraphicsView>

//System::static
bool System::showOptionsScreen;
bool System::showMenuScreen;
bool System::showGameOverScreen;
bool System::showControlsScreen;
bool System::showGameScreen;
bool System::playMusic;

System::System()
{

//    QGraphicsScene * scene = new QGraphicsScene();

//   StartScreen * screen = new StartScreen("");
//    screen->setBackground(scene);
//    QGraphicsView * view = new QGraphicsView(scene);
//    view->show();


}

System::~System()
{
}

void System::Save()
{

}

void System::Load()
{

}

