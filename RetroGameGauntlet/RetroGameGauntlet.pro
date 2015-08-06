TEMPLATE = app

QT += multimedia qml quick widgets
SOURCES += main.cpp \
    Controller.cpp \
#    Game.cpp \
    Model.cpp \
    RetroGameGauntlet.cpp
#    Season.cpp \
#    Stopwatch.cpp \
#   QTableModel.cpp

CONFIG += c++11
RESOURCES += qml.qrc


# Additional import path used to resolve QML modules in Qt Creator's code model
QML2_IMPORT_PATH = D:\Programming\IDE\Qt 5.3\5.5\mingw492_32\imports

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    Controller.h \
    Model.h \
    RetroGameGauntlet.h
#    Season.h \
#    Stopwatch.h \
#    QTableModel.h \
#    Game.h \
#    GAME_STATE.h


#win32:QMAKE_LFLAGS += -shared
RC_FILE = icon.rc
