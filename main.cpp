#include <iostream>
#include "main.h"
#include "accountSystem.cpp"

using namespace std;

int main() {
  int input;
  cout << "_______________________________________________________________" << endl;
  cout << "_____________________Account Creation Test_____________________" << endl;
  cout << "______________________________Menu_____________________________" << endl;
  cout << "_______________________________________________________________" << endl;
  cout << "" << endl;
  cout << "| 1. Login                    |" << endl;
  cout << "| 2. Register                 |" << endl;
  cout << "| 3. Forgot Password          |" << endl;
  cout << "| 4. Exit                     |" << endl;
  cout << "" << endl;
  cin >> input;
  cout << endl;

  switch(input) {
    case 1:
      login();
      break;
    case 2:
      registration();
      break;
    case 3:
      forgot();
      break;
    case 4:
      cout << "Theres no exit function yet lol" << endl;
      break;
    default:
      system("cls");
      cout << "Not a valid response, please try again." << endl;
      main();
  }


  return 0;
}