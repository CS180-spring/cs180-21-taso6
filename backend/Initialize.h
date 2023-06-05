#ifndef Initialize_H
#define Initialize_H

#include "collection.h"
#include "User.h"

#include <string>

class Database{
private:
    vector<Collection> collections;
    vector<User> users;
    User* currentUser = nullptr;
public:
    Database();
    void deleteFile();
    void readFile(string file);
    void createCollection(string fileName, string name, string username);
    void addCollection(Collection collection);
    bool canLogin(string username, string password);
    void login(string username, string password);
    void logout();
    bool isLoggedIn();
};

#endif