#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QWidget>
#include <QString>
#include <QMessageBox>

#include "reguserdb.h"

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWindow(QSharedPointer<RegUserDB>&, QSharedPointer<UserDS>&, QWidget *parent = 0);
    ~RegisterWindow();

signals:
    void showsw();
    void showlw();

private slots:
    void on_pbRegister_clicked();

    void on_clbLogin_clicked();

private:
    Ui::RegisterWindow *ui;
    QSharedPointer<RegUserDB> rudb;
    QSharedPointer<UserDS> SessionUser;
};

#endif // REGISTERWINDOW_H
