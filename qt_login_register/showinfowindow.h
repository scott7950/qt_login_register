#ifndef SHOWINFOWINDOW_H
#define SHOWINFOWINDOW_H

#include <QWidget>
#include <QString>

#include "reguserdb.h"

namespace Ui {
class ShowInfoWindow;
}

class ShowInfoWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ShowInfoWindow(QSharedPointer<RegUserDB>&, QSharedPointer<UserDS>&, QWidget *parent = 0);
    ~ShowInfoWindow();

signals:
    void showlw();

private slots:
    void on_pbLogout_clicked();
    void on_showsw();

private:
    Ui::ShowInfoWindow *ui;
    QSharedPointer<RegUserDB> rudb;
    QSharedPointer<UserDS> SessionUser;
};

#endif // SHOWINFOWINDOW_H
