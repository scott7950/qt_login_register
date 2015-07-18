#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "reguserdb.h"
#include <QMainWindow>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(RegUserDB&, QWidget *parent = 0);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void showrw();
    void showsw(QString&, QString&, int&);

private slots:
    void on_pbLogin_clicked();

    void on_clbRegister_clicked();
    void on_showrw() {emit showrw(); qDebug() << "hello";}

private:
    Ui::MainWindow *ui;
    RegUserDB rudb;
};

#endif // MAINWINDOW_H
