#include <iostream>
#include <fstream>
#include <string.h>
#include "main.h"
#include "accountSystem.h"
using namespace std;

void login() {
    //login function
}
void registration() {
    string username;
    string password;
    string id;
    string pass;

    cout << "Enter a Username" << endl;
    cout << endl;
    cin >> username;
    cout << "Enter a Password" << endl;
    cin >> password;

    ofstream f1("records.txt", ios::app);
    f1 << id << ' '<< pass << endl;
    system("cls");
    cout << "Your account has been created!" << endl;
    main();
}
void forgot() {
    //forgot password function
}