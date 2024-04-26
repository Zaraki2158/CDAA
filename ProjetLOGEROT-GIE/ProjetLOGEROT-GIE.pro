QT       += core gui
QT +=core
QT += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ajoutercontact.cpp \
    contact.cpp \
    gestioncontact.cpp \
    historique.cpp \
    interaction.cpp \
    interactionstodo.cpp \
    main.cpp \
    mainwindow.cpp \
    modifiercontact.cpp \
    sql.cpp \
    supprimer.cpp \
    todo.cpp

HEADERS += \
    ajoutercontact.h \
    contact.h \
    date.h \
    gestioncontact.h \
    historique.h \
    interaction.h \
    interactionstodo.h \
    mainwindow.h \
    modifiercontact.h \
    supprimer.h \
    todo.h

FORMS += \
    ajoutercontact.ui \
    interactionstodo.ui \
    mainwindow.ui \
    modifiercontact.ui \
    supprimer.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
