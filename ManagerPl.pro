#-------------------------------------------------
#
# Project created by QtCreator 2016-10-13T16:46:26
#
#-------------------------------------------------

QT       += core gui\
            multimedia\
            uitools

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ManagerPl
TEMPLATE = app


SOURCES += main.cpp\
        mainmenu.cpp \
    gamewindow.cpp \
    table.cpp \
    team.cpp \
    choseteam.cpp \
    showsquads.cpp \
    match.cpp \
    league.cpp \
    matchinterface.cpp \
    player.cpp \
    options.cpp \
    edit.cpp \
    editchooseteam.cpp \
    addplayer.cpp \
    serialization.cpp \
    removeplayer.cpp \
    editplayer.cpp \
    stats.cpp \
    container.cpp \
    fixture.cpp \
    gamedialog.cpp \
    usersquad.cpp \
    selectshowsquad.cpp \
    livematch.cpp \
    musicplayer.cpp \
    topscorer.cpp \
    data.cpp \
    contextmenu.cpp \
    functions.cpp \
    matchsimulation.cpp \
    intro.cpp \
    tablesandstats.cpp \
    myexception.cpp \
    versus.cpp \
    showteamstats.cpp \
    showplayerstats.cpp \
    userdata.cpp \
    userdatadialog.cpp \
    artificialintelligence.cpp \
    matchalgorithms.cpp \
    playersupportfunction.cpp \
    formations.cpp \
    setmultimedia.cpp \
    stadium.cpp \
    abaut.cpp

HEADERS  += mainmenu.h \
    gamewindow.h \
    table.h \
    team.h \
    choseteam.h \
    showsquads.h \
    match.h \
    league.h \
    matchinterface.h \
    player.h \
    options.h \
    edit.h \
    editchooseteam.h \
    addplayer.h \
    serialization.h \
    removeplayer.h \
    editplayer.h \
    stats.h \
    container.h \
    fixture.h \
    tablesandstats.h \
    gamedialog.h \
    usersquad.h \
    selectshowsquad.h \
    livematch.h \
    musicplayer.h \
    topscorer.h \
    data.h \
    contextmenu.h \
    functions.h \
    matchsimulation.h \
    intro.h \
    myexception.h \
    versus.h \
    showteamstats.h \
    showplayerstats.h \
    userdata.h \
    userdatadialog.h \
    artificialintelligence.h \
    matchalgorithms.h \
    playersupportfunction.h \
    formations.h \
    setmultimedia.h \
    stadium.h \
    abaut.h

FORMS    += mainmenu.ui \
    gamewindow.ui \
    table.ui \
    choseteam.ui \
    showsquads.ui \
    match.ui \
    matchinterface.ui \
    options.ui \
    edit.ui \
    editchooseteam.ui \
    addplayer.ui \
    removeplayer.ui \
    editplayer.ui \
    stats.ui \
    fixture.ui \
    gamedialog.ui \
    usersquad.ui \
    selectshowsquad.ui \
    livematch.ui \
    topscorer.ui \
    data.ui \
    contextmenu.ui \
    intro.ui \
    tablesandstats.ui \
    showteamstats.ui \
    showplayerstats.ui \
    userdatadialog.ui \
    abaut.ui

RESOURCES += \
    resource.qrc


win32: RC_ICONS = ball.ico
