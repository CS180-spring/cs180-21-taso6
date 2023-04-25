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

    fstream record("records.csv");

    cout << "Enter a Username" << endl;
    cout << endl;
    cin >> username;
    cout << endl;
    cout << "Enter a Password" << endl;
    cin >> password;

    record << username << ", " << password;


    system("cls");
    cout << "Your account has been created!" << endl;
    main();
}
void forgot() {
    //forgot password function
}
