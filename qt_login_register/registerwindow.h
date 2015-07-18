#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include "reguserdb.h"
#include <QWidget>
#include <QString>

namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = 0);
    explicit RegisterWindow(RegUserDB&, QWidget *parent = 0);
    ~RegisterWindow();

signals:
    void showsw(QString&, QString&, int&);
    void showlw();

private slots:
    void on_pbRegister_clicked();

    void on_clbLogin_clicked();

private:
    Ui::RegisterWindow *ui;
    RegUserDB rudb;
};

#endif // REGISTERWINDOW_H
