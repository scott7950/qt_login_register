#include "registerwindow.h"
#include "ui_registerwindow.h"
#include <QString>

RegisterWindow::RegisterWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::RegisterWindow(RegUserDB& rudb, QWidget *parent) :
    rudb(rudb), QWidget(parent),
    ui(new Ui::RegisterWindow)
{
ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_pbRegister_clicked()
{
    hide();

    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();
    QString name = ui->leName->text();
    int age = ui->leAge->text().toInt();

    bool isValid = false;
    if(username == "") {
        isValid = false;
    } else {
        isValid = true;
    }

    if(password == "") {
        isValid = false;
    } else {
        isValid = true;
    }

    if(name == "") {
        name = "FakeName";
    }

    if(age == 0) {
        age = -1;
    }

    if(isValid) {
        if(rudb.addUser(username, password, name, age) == 1) {
            emit showsw(username, name, age);
        } else {
            emit show();
        }
    } else {
        emit show();
    }

}

void RegisterWindow::on_clbLogin_clicked()
{
    emit hide();
    emit showlw();
}
