#include "reguserdb.h"
#include "userStruct.h"
#include "dbDefine.h"

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

bool RegUserDB::searchUser(QString username) {
    bool result;

    connDB();

    QSqlQuery myQuery;
    myQuery.prepare("SELECT * FROM user WHERE username = ?;");
    myQuery.addBindValue(username);

    if(!myQuery.exec()) {
        qDebug() << "Error in execute query!";
    }

    result = myQuery.last();
    myQuery.clear();
    disconnDB();

    return result;
}

int RegUserDB::authUser(QString username, QString password) {
    int result = 0;

    connDB();

    QSqlQuery myQuery;
    myQuery.prepare(
        QString("SELECT * FROM user WHERE username = '%1';")
                .arg(username)
    );

    if(!myQuery.exec()) {
        qDebug() << "Error in execute query!";
    }

    if(myQuery.last()) {
        myQuery.prepare(
            QString("SELECT * FROM user WHERE username = '%1' and password = '%2';")
                    .arg(username).arg(password)
        );

        if(!myQuery.exec()) {
            qDebug() << "Error in execute query!";
        }

        if(myQuery.last()) {
            result = 1;
        } else {
            result = -1;
        }
    } else {
        result = 0;
    }

    myQuery.clear();
    disconnDB();

    return result;

}

struct userStruct RegUserDB::searchUserAndReturnResult(QString username, QString password) {
    struct userStruct user;

    user.resultType = 0;

    connDB();

    QSqlQuery myQuery;
    myQuery.prepare(
        QString("SELECT * FROM user WHERE username = '%1' and password = '%2';")
                .arg(username).arg(password)
    );

    if(!myQuery.exec()) {
        user.resultType = -1;
    }

    int i = 0;
    while(myQuery.next()) {
        user.username = myQuery.value(1).toString();
        user.password = myQuery.value(2).toString();
        user.name = myQuery.value(3).toString();
        user.age = myQuery.value(4).toInt();

        if(i == 0) {
            user.resultType = 1;
        } else {
            user.resultType = -2;
        }
        i++;
    }

    myQuery.clear();
    disconnDB();

    return user;

}

int RegUserDB::addUser(QString username, QString password, QString name, int age) {
    int result = 0;

    if(searchUser(username)) {
        result = -1;
    } else {

        connDB();

        QSqlQuery myQuery;
        myQuery.prepare(
            QString("insert into user (username, password, name, age) values ('%1', '%2', '%3', %4);")
                    .arg(username).arg(password).arg(name).arg(age)

        );

        if(myQuery.exec()) {
            result = 1;
        } else {
            result = 0;
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
