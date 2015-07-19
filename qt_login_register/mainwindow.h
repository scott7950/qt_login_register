#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QString>

#include "showinfowindow.h"
#include "reguserdb.h"
#include "userds.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QSharedPointer<RegUserDB>&, QSharedPointer<UserDS>&, QWidget *parent = 0);
    ~MainWindow();

signals:
    void showrw();
    void showsw();

private slots:
    void on_pbLogin_clicked();

    void on_clbRegister_clicked();
    void on_showrw() {emit showrw(); qDebug() << "hello";}

private:
    Ui::MainWindow *ui;
    QSharedPointer<RegUserDB> rudb;
    QSharedPointer<UserDS> SessionUser;
};

#endif // MAINWINDOW_H
