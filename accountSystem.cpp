#include <iostream>
#include <fstream>
#include <string.h>
#include "main.h"
#include "accountSystem.h"
using namespace std;

void login() {
    int count;
    string userID, password, id, pass;
    system("cls");
    cout << "\t\t\t Please enter the username and password: " << endl;
    cout << "\t\t\t USERNAME: ";
    cin >> userID;
    cout << "\t\t\t PASSWORD: ";
    cin >> password;

    ifstream input("records.txt");

    while(input >> id >> pass) {
        if(id==userID && pass==password) {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if(count==1) {
        cout << userID << "\n Your login is successful. \n";
        main();
    }
    else {
        cout << "\n Login Error. \n Please try again. \n";
        main();
    }
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
    int option;
    system("cls");
    cout << "\t\t\t Forgot password? \n";
    cout << "Press 1 to search you id by username " << endl;
    cout << "Press 2 to go back to the main menu " << endl;
    cout << "\t\t\t Enter 1 or 2: ";
    cin >> option;
    switch(option) {
        case 1: {
            int count = 0;
            string suserId, sId, spass;
            cout << "\n\t\t\t Enter your username: ";
            cin >> suserId;

            ifstream f2("records.txt");
            while(f2 >> sId >> spass) {
                if(sId == suserId) {
                    count = 1;
                }
            }
            f2.close();
            if(count==1) {
                cout << "\n\n You account has been found. \n";
                cout << "\n\n Your password is: " << spass;
                main();
            }
            else {
                cout << "\n\t Sorry, we cannot find your account. \n";
                main();
            }
            break;
        }
        case 2: {
            main();
        }
            default:
                cout << "\t\t\t Please try again." << endl;
                forgot();
    }
}
