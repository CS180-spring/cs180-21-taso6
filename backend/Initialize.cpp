#include "Initialize.h"
#include "parse.h"
//#include "collection.h"

/*Database initialize_DB(){
    Database ourData;
    ourData.left = new Collection;
    return ourData;
}*/

void Database::readFile(string file){
    std::vector<string> usernames = parseAllCSV(file, "Username");
    std::vector<string> passwords = parseAllCSV(file, "Password");
    for(int i=0; i<usernames.size(); i++){
        left->moreMap(usernames.at(i), passwords.at(i));
    }
}