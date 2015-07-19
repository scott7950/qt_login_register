#ifndef REGUSERDB_H
#define REGUSERDB_H

#include <QtSql>
#include <QString>

#include "dbDefine.h"
#include "userds.h"

class RegUserDB
{
public:
    RegUserDB();

    bool connDB();
    void disconnDB();
    bool searchUserByUsername(UserDS& user);
    bool addUser(UserDS& user);
    bool authUser(UserDS& user);
    bool searchUserByUsernameAndPassword(UserDS& user);

private:
    QString dbName;
    QSqlDatabase sdb;
};

#endif // REGUSERDB_H
