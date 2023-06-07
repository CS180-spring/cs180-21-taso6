#ifndef USER_H
#define USER_H
#include<iostream>
#include<vector>
#include<string>
//#include "collection.h"

using namespace std;

class User{
    private:
    string username;
    string password;
    int admin_level;

    public:
    User(string username, string password, int admin_level);
    User(User const &cpyuser);
    bool userLogin(string name, string password);
    vector<string> lastSightings();
    string getUsername(){return username;}
    string getPassword(){return password;}



};
#endif