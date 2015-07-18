#include "mainwindow.h"
#include "registerwindow.h"
#include "showinfowindow.h"
#include "reguserdb.h"
#include <QApplication>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RegUserDB rudb;

    MainWindow lw(rudb);
    RegisterWindow rw(rudb);
    ShowInfoWindow sw(rudb);

    QObject::connect(&lw, SIGNAL(showsw(QString&, QString&, int&)), &sw, SLOT(on_showsw(QString&, QString&, int&)));
    QObject::connect(&lw, SIGNAL(showrw()), &rw, SLOT(show()));

    QObject::connect(&rw, SIGNAL(showlw()), &lw, SLOT(show()));
    QObject::connect(&rw, SIGNAL(showsw(QString&, QString&, int&)), &sw, SLOT(on_showsw(QString&, QString&, int&)));

    QObject::connect(&sw, SIGNAL(showlw()), &lw, SLOT(show()));


    rudb.connDB();
    rudb.disconnDB();

    lw.show();

    return a.exec();
}
