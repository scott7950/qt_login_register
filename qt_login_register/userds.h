#ifndef USERDS_H
#define USERDS_H

#include <QString>
#include <QRegularExpression>
#include <QMetaEnum>

class UserDS
{
public:
    enum userDataType {
        Invalid,
        Valid,
        ErrOpenDB,
        ErrSqlExec,
        ErrNoData,
        ErrMultiData,
        ErrExistData
    };

    UserDS();
    UserDS(userDataType userType);
    UserDS(QString username, QString password);
    UserDS(QString username, QString password, QString name, int age);
    UserDS(QString username, QString password, QString name, int age, userDataType userType);

    void setUserType(userDataType userType);
    void setUsername(QString username);
    void setPassword(QString password);
    void setName(QString name);
    void setAge(int age);

    userDataType getUserType();
    QString getUsername();
    QString getPassword();
    QString getName();
    int getAge();

    void update(UserDS user);
    void update(QString username, QString password, QString name, int age);
    void update(QString username, QString password, QString name, int age, userDataType userType);

    void clear();

    bool isValidUsernamePattern();
    bool isValidPasswordPattern();
    bool isValidNamePattern();

    bool isValidUsernamePattern(QString username);
    bool isValidPasswordPattern(QString password);
    bool isValidNamePattern(QString name);
    bool isValidAgePattern(QString age);

    QString userDataTypeStr(userDataType);

private:
    userDataType userType;
    QString username;
    QString password;
    QString name;
    int age;
};

#endif // USERDS_H
