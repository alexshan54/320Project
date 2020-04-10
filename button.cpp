
#include "system.h"
#include "stdio.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include "button.h"
#include "game.h"
#include "startscreen.h"


#include <QDebug>
using namespace std;



Button::Button() : QGraphicsRectItem(){}


void Button::keyPressEvent(QKeyEvent *event) {
    qDebug()<<"We know that u pressed" << event->key();
    if(System::showMenuScreen){
        qDebug()<<"You are in menu screen";
        if(event->key()==Qt::Key_Up && Game::sc->getPos() > 0){
            Game::sc->changeHigh(-1);
         }
        if(event->key()==Qt::Key_Down && Game::sc->getPos() < 3){//Closes the game
            Game::sc->changeHigh(1);
         }
        if(event->key()==Qt::Key_Return){//Takes to game over
           qDebug()<<"Selecting";
           if(Game::sc->getPos() == 0){
                //Play the game
               Game::game->start();
               System::showMenuScreen = false;
               System::showGameScreen = true;
               Game::sc->resetPos();
           }
           else if(Game::sc->getPos() == 1){
               Game::game->displayOptionsMenu();
               System::showMenuScreen = false;
               System::showOptionsScreen = true;
               Game::sc->resetPos();

           }
           else if(Game::sc->getPos() == 2){
               Game::game->displayControlMenu();
               System::showMenuScreen = false;
               System::showControlsScreen = true;
               Game::sc->resetPos();

           }
           else if(Game::sc->getPos() == 3){
                Game::game->close();
           }


        }
    }
    else if(System::showOptionsScreen){
        if(event->key()==Qt::Key_Up && Game::oc->getPos() > 0){
            Game::oc->changeHigh(-1);
         }
        else if(event->key()==Qt::Key_Down && Game::oc->getPos() < 1){
            Game::oc->changeHigh(1);
         }
        else if(event->key()==Qt::Key_Return){
            if(Game::oc->getPos() == 0){
                //Toggle Music
                if(System::playMusic){
                    Game::music->stop();
                    System::playMusic = false;
                }
                else{
                    Game::music->play();
                    System::playMusic = true;
                }
                Game::oc->setCheck();
            }
            else if(Game::oc->getPos() == 1){
                Game::game->displayMainMenu();
                Game::oc->resetPos();
                System::showOptionsScreen = false;
                System::showMenuScreen = true;
            }

        }
    }
    else if(System::showControlsScreen){
        if(event->key()==Qt::Key_Return){//Takes to Main Menu
            Game::game->displayMainMenu();
            System::showControlsScreen = false;
            System::showMenuScreen = true;

        }
    }
    else if(System::showGameScreen){
        if(event->key()==Qt::Key_Space){
        }
    }
    else if(System::showGameOverScreen){
        qDebug()<<"You are in game over screen";
        if(event->key()==Qt::Key_Space){
            Game::game->displayMainMenu();
            System::showMenuScreen = true;
            System::showGameOverScreen = false;
        }
    }
}



void Button::Highlight() {

}


