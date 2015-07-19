#ifndef USERDS_H
#define USERDS_H

#include <QString>
#include <QRegularExpression>

class UserDS
{
public:
    UserDS();
    UserDS(int userType);
    UserDS(QString username, QString password);
    UserDS(QString username, QString password, QString name, int age);
    UserDS(QString username, QString password, QString name, int age, int userType);

    void setUserType(int userType);
    void setUsername(QString username);
    void setPassword(QString password);
    void setName(QString name);
    void setAge(int age);

    int getUserType();
    QString getUsername();
    QString getPassword();
    QString getName();
    int getAge();

    void update(UserDS user);
    void update(QString username, QString password, QString name, int age);
    void update(QString username, QString password, QString name, int age, int userType);

    void clear();

    bool isValidUsernamePattern();
    bool isValidPasswordPattern();
    bool isValidNamePattern();

    bool isValidUsernamePattern(QString username);
    bool isValidPasswordPattern(QString password);
    bool isValidNamePattern(QString name);
    bool isValidAgePattern(QString age);

private:
    int userType;
    QString username;
    QString password;
    QString name;
    int age;
};

#endif // USERDS_H
