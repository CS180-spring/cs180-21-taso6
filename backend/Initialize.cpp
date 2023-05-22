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
/*void Database::deleteFile(char fileName[20]) {

}*/
