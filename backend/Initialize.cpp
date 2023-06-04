#include "Initialize.h"
#include <stdio.h>
#include <fstream>
#include <cstdio>
//#include "parse.h"
//#include "collection.h"

/*Database initialize_DB(){
    Database ourData;
    ourData.left = new Collection;
    return ourData;
}*/

void Database::readFile(string file){
//    std::vector<string> usernames = parseAllCSV(file, "Username");
//    std::vector<string> passwords = parseAllCSV(file, "Password");
//    for(int i=0; i<usernames.size(); i++){
//        left->moreMap(usernames.at(i), passwords.at(i));
//    }
}

void Database::createCollection(string fileName, string name, string username) {
    Collection collection(fileName, name, username);
    collections.push_back(collection);
}

void Database::addCollection(Collection collection){
    collections.push_back(collection);
}
/*void Database::deleteFile(char fileName[20]) {

}*/

Database::Database(){
    vector<string> temp = parseCSVforUsers("assets/records.csv");
    for(int i=0; i<temp.size(); i++){
        string username = parseCSV("assets/records.csv", "Username", i+1);
        string password = parseCSV("assets/records.csv", "Password", i+1);
        string admin_level = parseCSV("assets/records.csv", "AdminLevel", i+1);
        User tempUser(username, password, stoi(admin_level, 0, 10));
//        cout << username << " " << password << " " << admin_level << endl;
        users.push_back(tempUser);
    }
//    cout << users.size() << endl;
}

bool Database::canLogin(string username, string password){
   //cout << "we are in canLogin" << endl;
    for(int i=0; i<users.size(); i++){
     //   cout << i << endl;
        if(users[i].userLogin(username, password)){
            return true;
        }
    }
    return false;
}

void Database::login(string username, string password){
   // cout << "we are in Login" << endl;
    for(int i=0; i<users.size(); i++){
     //   cout << i << endl;
        if(users[i].userLogin(username, password)){
            currentUser = &users[i];
            return;
        }
    }
}
