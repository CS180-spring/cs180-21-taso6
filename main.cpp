#include <iostream>
/*#include "backend/Initialize.h"
#include "UI/accountSystem.h"
#include "UI/accountMenu.h"*/
//#include "backend/collection.h"
#include "backend/crow_all.h"
#include "backend/parse.h"


using namespace std;

int main() {
//    Collection coll("assets/eBird_1k.csv", "e_Bird", "admin");
//    userView();
//    coll.load();
//    coll.show();
    crow::SimpleApp app; //define your crow application

    CROW_ROUTE(app, "/")([](){
        vector<string> test = parseCSVforDB("assets/eBird_1k.csv");
        string res;
        //define your endpoint at the root directory
        for(int i = 0; i <= 1000; i++){
            res = res + "\n" + test[i];
        }
        return res;
    });


    //set the port, set the app to run on multiple threads, and run the app
    app.port(18080).multithreaded().run();
    return 0;
};
