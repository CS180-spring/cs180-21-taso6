#include <iostream>
//#include "backend/Initialize.h"
//#include "UI/accountSystem.h"
#include "UI/accountMenu.h"

using namespace std;

/*struct Database{
    string dbName;
    Collection *left;
    User *right;

    string get_dbName(){
        return dbName;
    }
    void set_name(string name){
        dbName = name;
        return;
    }
};

Database initialize_DB(){
    Database ourData;
    ourData.left = new Collection;
    return ourData;
}*/

int main() {
  userView();
  return 0;
};