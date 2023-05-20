//#include "backend/Initialize.h"
//#include "UI/accountSystem.h"
#include "UI/accountMenu.h"
#include "backend/collection.h"

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
    Collection coll("assets/eBird_1k.csv", "e_Bird", "admin");
    userView();
    coll.load();
    coll.show();
    return 0;
};
