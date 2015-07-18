#ifndef SHOWINFOWINDOW_H
#define SHOWINFOWINDOW_H

#include "reguserdb.h"
#include <QWidget>
#include <QDebug>
#include <QString>

namespace Ui {
class ShowInfoWindow;
}

class ShowInfoWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ShowInfoWindow(QWidget *parent = 0);
    explicit ShowInfoWindow(RegUserDB&, QWidget *parent = 0);
    ~ShowInfoWindow();

signals:
    void showlw();

private slots:
    void on_pbLogout_clicked();
    void on_showsw(QString&, QString&, int&);

private:
    Ui::ShowInfoWindow *ui;
    RegUserDB rudb;
    QString username;
    QString name;
    int age;
};

#endif // SHOWINFOWINDOW_H
