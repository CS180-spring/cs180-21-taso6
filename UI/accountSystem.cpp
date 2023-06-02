#include <iostream>
#include <fstream>
#include "accountSystem.h"
#include <cstring>;

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

void registration(Database curData, string username, string password) {
    string user = username;
    string pass = password;

    ofstream test;
    test.open("assets/records.csv", std::ios_base::app);

//    cout << "Enter a Username" << endl;
//    cout << endl;
//    cin >> username;
////    while(curData.left->lookUp(username) != ""){
//        cout << "Username is taken, please choose another" << endl;
//        cin >> username;
////    }
//    cout << endl;
//    cout << "Enter a Password" << endl;
//    cin >> password;

    test << endl << username << "," << password << ",0";
    test.close();

//    curData.left->moreMap(username, password);

//    system("clear");
// cout << "Your account has been created!" << endl;
}
void forgot() {
    //forgot password function
}
void delete_file(Database curData){
    //char fileName[30] = "../assets/";

    string directory = "assets/";
    string extend = ".csv";
    string userInput;
    cout << "Enter a file you would like to delete" << endl;
    cin.ignore();
    getline(cin,userInput);

    string result;
    result = directory + userInput + extend;

    const int length = result.length();
    char* input = new char[length + 1];
    std::strcpy(input, result.c_str());

    if(remove(input) != 0) {
        ::perror("Error Deleting File");
        delete[] input;
        return;
    }
    else
        ::puts(("File Successfuly Deleted"));
        delete[] input;
        return;
}
void create_file(Database curData){
    string directory = "assets/";
    string extend = ".csv";
    string userInput;
    cout << "Enter a file you would like to create" << endl;
    cin.ignore();
    getline(cin,userInput);

    string result;
    result = directory + userInput + extend;
    cout << result << endl;
    fstream file;
    //ofstream record;

    file.open(result, ios::out);

    if(!file){
        cout << "Error in file Creation! at File" << endl;
        return;
    }
    else{
        cout << "File Creation successful." <<endl;
    }

    /*if(!record){
        cout << "Error in file Creation!" << endl;
        return;
    }
    else{
        cout << "File Creation successful." <<endl;
    }
    record.open("../assets/allCSV.txt", std::ios_base::app);
    record << "\n" << userInput << ".csv";
    record.close();
*/
    file.close();
}
