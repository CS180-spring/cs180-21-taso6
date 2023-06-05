#include "User.h"

using namespace std;

User::User(string username, string password, int admin_level){
        this->username = username;
        this->password = password;
        this->admin_level = admin_level;
}

bool User::userLogin(string name, string password){
    if(name == username && password == password){
        return true;
    }
    return false;
}

User::User(User const &cpyuser) {
    username = cpyuser.username;
    password = cpyuser.password;
    admin_level = cpyuser.admin_level;
};
