#ifndef Initialize_H
#define Initialize_H

#include "collection.h"
#include "User.h"

#include <string>

class Database{
private:
    vector<Collection> collections;
    vector<User> users;
public:
    Database(){}
    void deleteFile();
    void readFile(string file);
    void createCollection(string fileName, string name, string username);
    void parseAllCSV();
};

#endif