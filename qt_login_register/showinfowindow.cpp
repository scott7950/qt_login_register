#include "showinfowindow.h"
#include "ui_showinfowindow.h"

ShowInfoWindow::ShowInfoWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShowInfoWindow)
{
    ui->setupUi(this);

}

ShowInfoWindow::ShowInfoWindow(RegUserDB& rudb, QWidget *parent) :
    rudb(rudb), QWidget(parent),
    ui(new Ui::ShowInfoWindow)
{
    ui->setupUi(this);
}

ShowInfoWindow::~ShowInfoWindow()
{
    delete ui;
}

void ShowInfoWindow::on_showsw(QString& username, QString& name, int& age) {
    ui->leUsername->setText(username);
    ui->leName->setText(name);
    ui->leAge->setText(QString::number(age));

    show();
}

void ShowInfoWindow::on_pbLogout_clicked()
{
    hide();
    emit showlw();
}
