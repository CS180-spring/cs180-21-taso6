#include "User.h"

using namespace std;

User::User(string username, string password, int admin_level){
        this->username = username;
        this->password = password;
        this->admin_level = admin_level;
}

bool User::userLogin(string name, string password){
    if(name == this->username && password == this->password){
        return true;
    }
    return false;
}

User::User(User const &cpyuser) {
    this->username = username;
    this->password = password;
    this->admin_level = admin_level;
};
