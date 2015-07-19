#include "showinfowindow.h"
#include "ui_showinfowindow.h"

ShowInfoWindow::ShowInfoWindow(QSharedPointer<RegUserDB>& rudb, QSharedPointer<UserDS>& SessionUser, QWidget *parent) :
    rudb(rudb), SessionUser(SessionUser), QWidget(parent),
    ui(new Ui::ShowInfoWindow)
{
    ui->setupUi(this);
}

ShowInfoWindow::~ShowInfoWindow()
{
    delete ui;
}

void ShowInfoWindow::on_showsw() {
    ui->leUsername->setText(SessionUser->getUsername());
    ui->leName->setText(SessionUser->getName());
    ui->leAge->setText(QString::number(SessionUser->getAge()));

    show();
}

void ShowInfoWindow::on_pbLogout_clicked()
{
    //SessionUser.data()->clear();
    SessionUser->clear();

    hide();
    emit showlw();
}
