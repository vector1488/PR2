#include <iostream>
#include "ferma.h"
#include "extevklid.h"
#include "modules.h"
#include "shamir.h"
#include "fraction.h"
//#include "exercise6.h"

using namespace std;

void showUsage(){
    cout << "Practice 2. Main menu\n " <<
    "1 - Run Exercise 1\n" <<
    "2 - Run Exercise 2\n" <<
    "3 - Run Exercise 3\n" <<
    "4 - Run Exercise 4\n" <<
    "5 - Run Exercise 5\n" << endl;
}

int main(int argc, char* argv[]){
    char choice;
    do {
        showUsage();
        cin >> choice;
        cout << choice << endl;
        switch(choice){
            case '1':
                ferma();
                break;
            case '2':
                extevklid();
                break;
            case '3':
                modules();
                break;
            case '4':
                shamir();
                break;
            case '5':
                fraction();
                break;
            /*case '6':
                exercise6();
                break;*/
            case 'q':
                cout << "Leaving the programm... " << endl;
                break;
            case 'Q':
                cout << "Leaving the programm... " << endl;
                break;
            default:
                cout << "Wrong choice!" << endl;
                break;
          } 
      } while (choice != 'q' || choice != 'Q');
      return 0;
}
    
