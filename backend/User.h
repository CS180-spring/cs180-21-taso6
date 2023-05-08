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
    vector<User> users;

    public:
    void createInstance(string name, string password);
    void userLogin(string name, string password);
    void createList(string name);
    vector<string> lastSightings();
//    void editData(Collection collection, bird_Record record);
//    void viewLists();
//    void getList(string name);


};
#endif