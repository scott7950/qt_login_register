#include "reguserdb.h"

RegUserDB::RegUserDB()
{
    dbName = dbPath;
}

bool RegUserDB::connDB() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbName);

    if (!db.open()) {
        QSqlDatabase::removeDatabase("QSQLITE");

        QMessageBox msgBox;
        msgBox.setText(db.lastError().text());
        msgBox.exec();

        return false;
    }

    return true;
}

bool RegUserDB::searchUserByUsername(UserDS& user) {
    bool result = false;

    if(!connDB()) {
        user.setUserType(UserDS::ErrOpenDB);
        return false;
    }

    QSqlQuery myQuery;
    myQuery.prepare("SELECT * FROM user WHERE username = ?;");
    myQuery.addBindValue(user.getUsername());

    if(!myQuery.exec()) {
        user.setUserType(UserDS::ErrSqlExec);
    } else {
        result = myQuery.last();
        if(!result) {
            user.setUserType(UserDS::ErrNoData);
        }
    }

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

        if(!connDB()) {
            user.setUserType(UserDS::ErrOpenDB);
            return false;
        }

        QSqlQuery myQuery;
        myQuery.prepare(
                QString("SELECT * FROM user WHERE username = '%1' and password = '%2';")
                .arg(user.getUsername()).arg(user.getPassword())
                );

        if(!myQuery.exec()) {
            user.setUserType(UserDS::ErrSqlExec);
        } else {
            int i = 0;

            while(myQuery.next()) {
                user.update(myQuery.value(1).toString(), myQuery.value(2).toString(), myQuery.value(3).toString(), myQuery.value(4).toInt());

                if(i == 0) {
                    result = true;
                    user.setUserType(UserDS::Valid);
                } else {
                    result = false;
                    user.setUserType(UserDS::ErrMultiData);
                }
                i++;
            }

            if(i==0) {
                user.setUserType(UserDS::ErrNoData);
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
        user.setUserType(UserDS::ErrExistData);
        result = false;
    } else {

        if(!connDB()) {
            user.setUserType(UserDS::ErrOpenDB);
            return false;
        }

        QSqlQuery myQuery;
        myQuery.prepare(
            QString("insert into user (username, password, name, age) values ('%1', '%2', '%3', %4);")
                    .arg(user.getUsername()).arg(user.getPassword()).arg(user.getName()).arg(user.getAge())

        );

        if(myQuery.exec()) {
            user.setUserType(UserDS::Valid);
            result = true;
        } else {
            user.setUserType(UserDS::ErrSqlExec);
            result = false;
        }

        myQuery.clear();
        disconnDB();
    }

    return result;

}

void RegUserDB::disconnDB() {
    if(db.isOpen()) {
        db.close();
    }
    QSqlDatabase::removeDatabase("QSQLITE");
}
