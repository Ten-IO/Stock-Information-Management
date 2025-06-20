#include <iostream>
#include <windows.h>
#include <header.h>
using namespace std;

void setColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void menu() {
    while(true){
        cout << "=============================="<<endl;
        cout << "       STOCK MANAGEMENT       "<<endl;
        cout << "=============================="<<endl;
        int choice;
        setColor(10);
        cout << "------------ Menu ------------"<<endl;
        cout << "| 1. Create                   |"<<endl;
        cout << "| 2. Read                     |"<<endl;
        cout << "| 3. Update                   |"<<endl;
        cout << "| 4. Delete                   |"<<endl;
        cout << "| 5. Save                     |"<<endl;
        cout << "| 0. Exit the program         |"<<endl;
        cout << "==============================="<<endl;

        setColor(1);
        cout << "Enter your choice(0-5): ";
        
        setColor(12);
        cin >> choice;
        switch (choice){
            case 1:
               
                break;
            case 2:
                
                break;
            case 3: 
                
                break;
            case 4:
                 
                break;
            case 5:
                break;
            case 0: 
                return;
            default: 
                cout << "Invalid choice, Please try again."<<endl;
        }
        setColor(7);
    }
}
