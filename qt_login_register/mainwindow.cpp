#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QSharedPointer<RegUserDB>& rudb, QSharedPointer<UserDS>& SessionUser, QWidget *parent) :
    rudb(rudb), SessionUser(SessionUser), QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->lePassword->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbLogin_clicked()
{


    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();
    UserDS user(username, password);

    if(user.isValidUsernamePattern() && user.isValidPasswordPattern()) {
        if(rudb->authUser(user)) {
            ui->leUsername->setText("");
            ui->lePassword->setText("");

            SessionUser->update(user);

            hide();
            emit showsw();
        } else {
            QMessageBox msgBox;
            msgBox.setText("[Error] " + user.userDataTypeStr(user.getUserType()));
            msgBox.exec();
        }
    } else {
        QMessageBox msgBox;
        msgBox.setText("Username should be 5~10 characters.\nPassword should be 6~10 characters.");
        msgBox.exec();
    }
}

void MainWindow::on_clbRegister_clicked()
{
    hide();
    emit showrw();
}
