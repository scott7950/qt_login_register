#include "mainwindow.h"
#include "showinfowindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include "userStruct.h"
#include <QDebug>
#include <QString>

MainWindow::MainWindow(RegUserDB& rudb, QWidget *parent) :
    rudb(rudb), QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbLogin_clicked()
{
    emit hide();

    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();

    int age = 12;
    QString name = "test";
    int result = rudb.authUser(username, password);
    if(result == 1) {
        struct userStruct user;
        user = rudb.searchUserAndReturnResult(username, password);
        if(user.resultType == 1) {
            emit showsw(user.username, user.name, user.age);
        } else {
            emit show();
        }
    } else {
        emit show();
    }
}

void MainWindow::on_clbRegister_clicked()
{
    emit hide();
    emit showrw();
}
