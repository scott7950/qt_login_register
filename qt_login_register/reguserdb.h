#ifndef REGUSERDB_H
#define REGUSERDB_H

#include <QtSql>
#include <QString>

class RegUserDB
{
public:
    RegUserDB();

    bool connDB();
    void disconnDB();
    bool searchUser(QString);
    int addUser(QString, QString, QString, int);
    int authUser(QString, QString);
    struct userStruct searchUserAndReturnResult(QString, QString);

private:
    QString dbName;
    QSqlDatabase sdb;
};

#endif // REGUSERDB_H
