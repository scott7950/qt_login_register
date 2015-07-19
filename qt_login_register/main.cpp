#include <QApplication>
#include <QString>
#include <QSharedData>

#include "mainwindow.h"
#include "registerwindow.h"
#include "showinfowindow.h"
#include "reguserdb.h"
#include "userds.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSharedPointer<RegUserDB> rudb = QSharedPointer<RegUserDB>(new RegUserDB);
    QSharedPointer<UserDS> SessionUser = QSharedPointer<UserDS>(new UserDS);

    MainWindow lw(rudb, SessionUser);
    RegisterWindow rw(rudb, SessionUser);
    ShowInfoWindow sw(rudb, SessionUser);

    QObject::connect(&lw, SIGNAL(showsw()), &sw, SLOT(on_showsw()));
    QObject::connect(&lw, SIGNAL(showrw()), &rw, SLOT(show()));

    QObject::connect(&rw, SIGNAL(showlw()), &lw, SLOT(show()));
    QObject::connect(&rw, SIGNAL(showsw()), &sw, SLOT(on_showsw()));

    QObject::connect(&sw, SIGNAL(showlw()), &lw, SLOT(show()));

    lw.show();

    return a.exec();
}
