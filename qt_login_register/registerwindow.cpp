#include "registerwindow.h"
#include "ui_registerwindow.h"

RegisterWindow::RegisterWindow(QSharedPointer<RegUserDB>& rudb, QSharedPointer<UserDS>& SessionUser, QWidget *parent) :
    rudb(rudb), SessionUser(SessionUser), QWidget(parent),
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

    bool isValid = true;
    UserDS user;

    QString username = ui->leUsername->text();
    QString password = ui->lePassword->text();
    QString name = ui->leName->text();
    QString ageStr = ui->leAge->text();
    int age = -1;

    if((!user.isValidUsernamePattern(username)) || (!user.isValidPasswordPattern(password)) || (!user.isValidNamePattern(name))) {
        isValid = false;
    }

    if(user.isValidAgePattern(ageStr)) {
        age = ageStr.toInt();
    } else {
        isValid = false;
    }

    if(isValid) {
        user.update(username, password, name, age);
        if(rudb->addUser(user)) {
            ui->leUsername->setText("");
            ui->lePassword->setText("");
            ui->leName->setText("");
            ui->leAge->setText("");

            SessionUser->update(user);
            emit showsw();
        } else {
            QMessageBox msgBox;
            msgBox.setText("[Error] " + user.userDataTypeStr(user.getUserType()));
            msgBox.exec();

            emit show();
        }
    } else {
        QMessageBox msgBox;
        msgBox.setText("Username should be 5~10 characters.\nPassword should be 6~10 characters.\nName should be 1~20 characters.\nAge should be 1~3 digits.");
        msgBox.exec();

        emit show();
    }
}

void RegisterWindow::on_clbLogin_clicked()
{
    hide();
    emit showlw();
}
