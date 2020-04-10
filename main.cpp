#include "system.h"
#include "game.h"
#include "floorblockspawner.h"
#include <QApplication>
Game* game;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game::game = new Game();
    Game::game->displayMainMenu();
    Game::game->show();
    qApp->setOverrideCursor(QCursor(Qt::BlankCursor));
    return a.exec();
}
