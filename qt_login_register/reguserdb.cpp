#include "reguserdb.h"

RegUserDB::RegUserDB()
{
    dbName = dbPath;
}

bool RegUserDB::connDB() {
    sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName(dbName);

    if (!sdb.open()) {
          qDebug() << sdb.lastError().text();
          return false;
    }


    return true;
}

bool RegUserDB::searchUserByUsername(UserDS& user) {
    bool result;

    connDB();

    QSqlQuery myQuery;
    myQuery.prepare("SELECT * FROM user WHERE username = ?;");
    myQuery.addBindValue(user.getUsername());

    if(!myQuery.exec()) {
        qDebug() << "Error in execute query!";
    }

    result = myQuery.last();
    myQuery.clear();
    disconnDB();

    return result;
}

bool RegUserDB::authUser(UserDS& user) {
    return searchUserByUsernameAndPassword(user);
}

bool RegUserDB::searchUserByUsernameAndPassword(UserDS& user) {
    bool result = false;

    if(!searchUserByUsername(user)) {
        result = false;
    } else {

        connDB();

        QSqlQuery myQuery;
        myQuery.prepare(
                QString("SELECT * FROM user WHERE username = '%1' and password = '%2';")
                .arg(user.getUsername()).arg(user.getPassword())
                );

        if(!myQuery.exec()) {
            user.setUserType(-1);
        } else {
            int i = 0;
            while(myQuery.next()) {
                user.update(myQuery.value(1).toString(), myQuery.value(2).toString(), myQuery.value(3).toString(), myQuery.value(4).toInt());

                if(i == 0) {
                    result = true;
                    user.setUserType(1);
                } else {
                    result = false;
                    user.setUserType(-2);
                }
                i++;
            }
        }

        myQuery.clear();
        disconnDB();
    }

    return result;
}

bool RegUserDB::addUser(UserDS& user) {
    bool result = false;

    if(searchUserByUsername(user)) {
        user.setUserType(-1);
        result = false;
    } else {

        connDB();

        QSqlQuery myQuery;
        myQuery.prepare(
            QString("insert into user (username, password, name, age) values ('%1', '%2', '%3', %4);")
                    .arg(user.getUsername()).arg(user.getPassword()).arg(user.getName()).arg(user.getAge())

        );

        if(myQuery.exec()) {
            user.setUserType(1);
            result = true;
        } else {
            user.setUserType(-2);
            result = false;
        }

        myQuery.clear();
        disconnDB();
    }

    return result;

}

void RegUserDB::disconnDB() {
    if(sdb.isOpen()) {
        sdb.close();
    }
    QSqlDatabase::removeDatabase("QSQLITE");
}

