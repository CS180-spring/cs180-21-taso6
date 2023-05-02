#ifndef collection_H
#define collection_H
#include <map>
#include "User.h"
#include <string>

using namespace std;

class Collection{
    private:
    map<string, string>Users;

    public:
    string lookUp(string name){
        return Users[name];
    }
    void moreMap(string name, string password){
        Users[name] = password;
    }
};
#endif