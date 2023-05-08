#include <iostream>
#include <fstream>
#include "accountSystem.h"

using namespace std;

void login(Database curData) {
    //login function
    string username;
    string password;


    cout << "_______________________________________________________________" << endl;
    cout << "_____________________________Login______________________________" << endl;
    cout << "________________________________________________________________" << endl;
    cout << "Enter a Username" << endl;
    cout << endl;
    cin >> username;
    cout << endl;
    cout << "Enter a Password" << endl;
    cin >> password;

//    if(password != curData.left->lookUp(username)){
        cout << "too bad" << endl;
//    }
//    else{
        cout << "cool" << endl;
//    }
}

void registration(Database curData) {
    string username;
    string password;

    ofstream test;
    test.open("assets/records.csv", std::ios_base::app);

    cout << "Enter a Username" << endl;
    cout << endl;
    cin >> username;
//    while(curData.left->lookUp(username) != ""){
        cout << "Username is taken, please choose another" << endl;
        cin >> username;
//    }
    cout << endl;
    cout << "Enter a Password" << endl;
    cin >> password;

    test << endl << username << "," << password << ",0";
    test.close();

//    curData.left->moreMap(username, password);

//    system("clear");
    cout << "Your account has been created!" << endl;
}
void forgot() {
    //forgot password function
}
