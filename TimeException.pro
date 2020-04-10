QT       += core gui \
          multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    button.cpp \
    enemyFile.cpp \
    enemybug.cpp \
    floorBlock.cpp \
    floorblockspawner.cpp \
    game.cpp \
    hitboxextraxp.cpp \
    hitboxfile.cpp \
    hitboxleftbug.cpp \
    hitboxmainbug.cpp \
    hitboxp.cpp \
    hitboxrightbug.cpp \
    hitboxspike.cpp \
    hitboxx.cpp \
    hitboxy.cpp \
    main.cpp \
    object.cpp \
    optionsmenu.cpp \
    player.cpp \
    poweruphealth.cpp \
    screen.cpp \
    spike.cpp \
    sprite.cpp \
    system.cpp \
    startscreen.cpp


HEADERS += \
    button.h \
    enemyBug.h \
    enemyFile.h \
    floorBlock.h \
    floorblockspawner.h \
    game.h \
    hitboxextraxp.h \
    hitboxfile.h \
    hitboxleftbug.h \
    hitboxmainbug.h \
    hitboxp.h \
    hitboxrightbug.h \
    hitboxspike.h \
    hitboxx.h \
    hitboxy.h \
    object.h \
    optionsmenu.h \
    player.h \
    poweruphealth.h \
    screen.h \
    spike.h \
    sprite.h \
    system.h \
    startscreen.h


FORMS += \
    system.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc \
    music.qrc

DISTFILES += \
    ../../../../../../Downloads/Retro Gaming.ttf \
    assets/bug_1.png \
    assets/bug_2.png \
    assets/check.png \
    assets/controls.png \
    assets/controls_menu.png \
    assets/corrupted_file.png \
    assets/corrupted_file_2.png \
    assets/corrupted_file_3.png \
    assets/corrupted_file_4.png \
    assets/exit.png \
    assets/fileblock.png \
    assets/gameover.png \
    assets/menu.png \
    assets/music.png \
    assets/options.png \
    assets/options_menu.png \
    assets/playercharacter_idle1.png \
    assets/playercharacter_idle2.png \
    assets/playercharacter_jump1.png \
    assets/playercharacter_jump2.png \
    assets/playercharacter_run1.png \
    assets/playercharacter_run10.png \
    assets/playercharacter_run2.png \
    assets/playercharacter_run3.png \
    assets/playercharacter_run4.png \
    assets/playercharacter_run5.png \
    assets/playercharacter_run6.png \
    assets/playercharacter_run7.png \
    assets/playercharacter_run8.png \
    assets/playercharacter_run9.png \
    assets/pointer.png \
    assets/soundfx.png \
    assets/spike.png \
    assets/start.png \
    assets/title.png \
    assets/uncheck.png
