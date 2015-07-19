#include "userds.h"

UserDS::UserDS()
{
    userType = Invalid;
}

UserDS::UserDS(userDataType userType) {
    this->userType = userType;
}

UserDS::UserDS(QString username, QString password) {
    this->username = username; this->password = password;
}

UserDS::UserDS(QString username, QString password, QString name, int age) {
    this->username = username;
    this->password = password;
    this->name = name;
    this->age = age;
}

UserDS::UserDS(QString username, QString password, QString name, int age, userDataType userType) {
    this->username = username;
    this->password = password;
    this->name = name;
    this->age = age;
    this->userType = userType;
}

void UserDS::setUserType(userDataType userType) {
    this->userType = userType;
}

void UserDS::setUsername(QString username) {
    this->username = username;
}

void UserDS::setPassword(QString password) {
    this->password = password;
}

void UserDS::setName(QString name) {
    this->name = name;
}

void UserDS::setAge(int age) {
    this->age = age;
}

UserDS::userDataType UserDS::getUserType() {
    return userType;
}

QString UserDS::getUsername() {
    return username;
}

QString UserDS::getPassword() {
    return password;
}

QString UserDS::getName() {
    return name;
}

int UserDS::getAge() {
    return age;
}

void UserDS::update(UserDS user) {
    this->username = user.getUsername();
    this->password = user.getPassword();
    this->name = user.getName();
    this->age = user.getAge();
    this->userType = user.getUserType();
}

void UserDS::update(QString username, QString password, QString name, int age) {
    this->username = username;
    this->password = password;
    this->name = name;
    this->age = age;
}

void UserDS::update(QString username, QString password, QString name, int age, userDataType userType) {
    this->username = username;
    this->password = password;
    this->name = name;
    this->age = age;
    this->userType = userType;
}

void UserDS::clear() {
    update("", "", "", -1, Invalid);
}

bool UserDS::isValidUsernamePattern() {
    return isValidUsernamePattern(this->username);
}

bool UserDS::isValidPasswordPattern() {
    return isValidPasswordPattern(this->password);
}

bool UserDS::isValidNamePattern() {
    return isValidNamePattern(this->name);
}

bool UserDS::isValidUsernamePattern(QString username) {
    QRegularExpression re;
    re.setPattern("\\s");
    QRegularExpressionMatch match = re.match(username);

    if(match.hasMatch()) {
        return false;
    } else {
        re.setPattern("^\\w{5,10}$");
        match = re.match(username);
        if(match.hasMatch()) {
            return true;
        } else {
            return false;
        }
    }
}

bool UserDS::isValidPasswordPattern(QString password) {
    QRegularExpression re;
    re.setPattern("\\s");
    QRegularExpressionMatch match = re.match(password);

    if(match.hasMatch()) {
        return false;
    } else {
        re.setPattern("^\\w{6,10}$");
        match = re.match(password);
        if(match.hasMatch()) {
            return true;
        } else {
            return false;
        }
    }
}

bool UserDS::isValidNamePattern(QString name) {
    QRegularExpression re;

    re.setPattern("^\\s+");
    name.replace(re, "");

    re.setPattern("\\s+$");
    name.replace(re, "");

    re.setPattern("^[\\w\\s]{1,20}$");
    QRegularExpressionMatch match = re.match(name);
    if(match.hasMatch()) {
        return true;
    } else {
        return false;
    }
}

bool UserDS::isValidAgePattern(QString age) {
    QRegularExpression re;
    re.setPattern("\\s");
    QRegularExpressionMatch match = re.match(age);

    if(match.hasMatch()) {
        return false;
    } else {
        re.setPattern("^\\d{1,3}$");
        match = re.match(age);
        if(match.hasMatch()) {
            return true;
        } else {
            return false;
        }
    }
}

QString UserDS::userDataTypeStr(userDataType userType) {
    switch(userType) {
        case Invalid:
            return "Invalid";
            break;
        case Valid:
            return "Valid";
            break;
        case ErrOpenDB:
            return "ErrOpenDB";
            break;
        case ErrSqlExec:
            return "ErrSqlExec";
            break;
        case ErrNoData:
            return "ErrNoData";
            break;
        case ErrMultiData:
            return "ErrMultiData";
            break;
        case ErrExistData:
            return "ErrExistData";
            break;
        default:
            return "Unknown";
    }
}

