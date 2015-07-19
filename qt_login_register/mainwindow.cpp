#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QSharedPointer<RegUserDB>& rudb, QSharedPointer<UserDS>& SessionUser, QWidget *parent) :
    rudb(rudb), SessionUser(SessionUser), QMainWindow(parent),
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
    hide();

    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();
    UserDS user(username, password);

    if(user.isValidUsernamePattern() && user.isValidPasswordPattern()) {
        if(rudb->authUser(user)) {
            ui->leUsername->setText("");
            ui->lePassword->setText("");

            SessionUser->update(user);

            emit showsw();
        } else {
            emit show();
        }
    } else {
        emit show();
    }
}

void MainWindow::on_clbRegister_clicked()
{
    hide();
    emit showrw();
}
