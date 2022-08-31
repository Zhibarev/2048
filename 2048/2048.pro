QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14


SOURCES += \
    Controller.cpp \
    GameEventsEmitter.cpp \
    widgets/gameinfo/GameInfoWidget.cpp \
    widgets/gameinfo/ScoreWidget.cpp \
    widgets/gameinfo/TimeWidget.cpp \
    widgets/gameinfo/namednumber/NamedNumberWidget.cpp \
    widgets/gameview/FieldRenderer.cpp \
    widgets/gameview/GameView.cpp \
    widgets/InstructionBox.cpp \
    widgets/leaderboard/Leaderboard.cpp \
    widgets/leaderboard/LeaderboardWidget.cpp \
    widgets/leaderboard/ScoreInfo.cpp \
    Main.cpp \
    MainWindow.cpp \
    widgets/gameview/model/GameBoard.cpp \
    widgets/gameview/model/NumberTile.cpp \
    widgets/gameview/provider/graphicaltileprovider/FigureTileProvider.cpp \
    widgets/gameview/provider/graphicaltileprovider/GraphicalTileProvider.cpp \
    widgets/gameview/provider/graphicaltileprovider/NumberTileProvider.cpp \
    widgets/gameview/provider/TileColorProvider.cpp \
    widgets/gameview/provider/graphicaltileprovider/TilePixmapProvider.cpp \
    widgets/settings/IncorrectSettingsException.cpp \
    widgets/settings/Settings.cpp \
    widgets/settings/SettingsWidget.cpp \
    translator/Translator.cpp \
    widgets/gamestate/GameStateWidget.cpp

HEADERS += \
    Controller.hh \
    GameEventsEmitter.hh \
    translator/Language.hh \
    widgets/gameinfo/GameInfoWidget.hh \
    widgets/gameinfo/ScoreWidget.hh \
    widgets/gameinfo/TimeWidget.hh \
    widgets/gameinfo/namednumber/NamedNumberWidget.hh \
    widgets/gameview/FieldRenderer.hh \
    widgets/gameview/GameView.hh \
    widgets/InstructionBox.hh \
    widgets/leaderboard/Leaderboard.hh \
    widgets/leaderboard/LeaderboardWidget.hh \
    widgets/leaderboard/ScoreInfo.hh \
    MainWindow.hh \
    widgets/gameview/model/GameBoard.hh \
    widgets/gameview/model/NumberTile.hh \
    widgets/gameview/provider/graphicaltileprovider/FigureTileProvider.hh \
    widgets/gameview/provider/graphicalTileprovider/GraphicalTileProvider.hh \
    widgets/gameview/provider/graphicaltileprovider/NumberTileProvider.hh \
    widgets/gameview/provider/TileColorProvider.hh \
    widgets/gameview/provider/GraphicalTileProvider/TilePixmapProvider.hh \
    widgets/settings/IncorrectSettingsException.hh \
    widgets/settings/Settings.hh \
    widgets/settings/SettingsWidget.hh \
    translator/Translator.hh \
    widgets/gamestate/GameStateWidget.hh

FORMS += \
    Mainwindow.ui \
    widgets/gameinfo/GameInfoWidget.ui \
    widgets/gameinfo/namednumber/NamedNumberWidget.ui \
    widgets/leaderboard/LeaderboardWidget.ui \
    widgets/settings/SettingsWidget.ui \
    widgets/gamestate/GameStateWidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

TRANSLATIONS += \
    QtLanguage_fi.ts \
    QtLanguage_en.ts

CODECFORSRC = UTF-8
