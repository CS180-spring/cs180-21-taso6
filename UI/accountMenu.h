#ifndef ACCOUNTMENU_H
#define ACCOUNTMENU_H
#include <iostream>
#include "../backend/Initialize.h"
#include "accountSystem.h"

using namespace std;

void userView(){
    Database curData;
    curData.readFile("assets/records.csv");

    int input=0;
    while(input != 4){
      cout << "_______________________________________________________________" << endl;
      cout << "_____________________Account Creation Test_____________________" << endl;
      cout << "______________________________Menu_____________________________" << endl;
      cout << "_______________________________________________________________" << endl;
      cout << "" << endl;
      cout << "| 1. Login                    |" << endl;
      cout << "| 2. Register                 |" << endl;
      cout << "| 3. Forgot Password          |" << endl;
      cout << "| 4. Show records             |" << endl;
      cout << "" << endl;
      cin >> input;
      cout << endl;

      switch(input) {
          case 1:
              login(curData);
              break;
          case 2:
              registration(curData);
              break;
          case 3:
              forgot();
              break;
          case 4:
              cout << "X | Y | COMMON NAME | SCIENTIFIC NAME | STATE | COUNTY | LOCALITY | OBSERVATION DATE" << endl;
            break;
          case 5:
              delete_file(curData);
              break;
          case 6:
              create_file(curData);
              break;

        default:
          system("cls");
          cout << "Not a valid response, please try again." << endl;

      }
    }
}

#endif