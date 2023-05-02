#ifndef Initialize_H
#define Initialize_H

#include "collection.h"
#include "User.h"
#include <string>

class Database{
public:
    string dbName;
    Collection *left = new Collection;
    User *right;
    string get_dbName(){
        return dbName;
    }

    void set_name(string name){
        dbName = name;
        return;
    }

    void readFile(string file);
};

#endif