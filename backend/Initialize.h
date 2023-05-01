#ifndef Initialize_H
#define Initialize_H

#include "collection.h"
#include "User.h"

struct Database{
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
};
#endif