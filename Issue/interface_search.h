#ifndef INTERFACE_SEARCH_H
#define INTERFACE_SEARCH_H

#include <iostream>
#include <limits>
#include <ios> // for std::streamsize
#include <string>
#include <cstdlib> // for system()
#include "search1.h"
#include "item.h"
using namespace std;
// Forward declarations
struct List;
struct Loglist;

//External Variables
extern List* stocklist;
extern Loglist* loglist;


// Helper function to clear invalid input
void cleanInput() {
    cin.clear();
    cin.ignore(10000, '\n');
}

// Helper function to clear screen cross-platform
void clearScreen() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void waitForUserInput() {
    cout << "Press enter to continue...";
    cin.ignore();
    cin.get();
}

void interface_searchLogList(Loglist* log){
    while(true){
        cout << "==================================" << endl;
        cout << "    SEARCH PRODUCT IN LOG LIST    " << endl;
        cout << "==================================" << endl;
        cout << "---------------Menu---------------" << endl;
        cout << "| 1. Username                    |" << endl;
        cout << "| 2. Action type                 |" << endl;
        cout << "| 3. Item ID                     |" << endl;
        cout << "| 4. Date                        |" << endl;
        cout << "| 0. Exit                        |" << endl;
        cout << "----------------------------------" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch(choice){
            case 1: {
                cout << "Search this username "<<endl;
                cout << "Enter username: ";
                string username; 
                cin >> username;
                // searchUsername(log, username);
                break;
            }
            case 2: {
                cout << "Search action type"<<endl;
                cout << "Enter action type: ";
                string action_type;
                cin >> action_type;
                // searchAction_type(log, action_type);
                break;
            }
            case 3: {
                while(true){
                    cout << "Search by ID"<<endl;
                    cout << "1. Specific ID"<<endl;
                    cout << "2. A range of ID "<<endl;
                    cout << "0. Exit"<<endl;
                    cout << "Enter your choice: ";
                    int c; 
                    cin >> c;
                    if (c == 1){
                        cout << "Enter the product ID: ";
                        int id;
                        cin >> id;
                        // searchByID(ls, id);
                        break;
                    }else if (c == 2){
                        cout << "Enter a range of ID"<<endl;
                        cout << "From: ";
                        int start, end;
                        cin >> start ;
                        cout << "To: ";
                        cin >> end;
                        // searchByIDRange(ls, start, end);
                        break;
                    }else if (c == 0){
                        cout << "Exiting the search by ID menu."<<endl;
                        system("cls");
                        break;
                    }else{
                        cout << "Invalid choice, Please try again!"<<endl;
                    }
                }
                break;
            }
            case 4: {
                cout << "Search by date" << endl;
                cout << "1. Specific date"<< endl;
                cout << "2. A range of date"<< endl;
                cout << "0. Exit"<<endl;
                cout << "Enter your choice: ";
                int c; 
                cin >> c;
                if (c == 1){ 
                    cout << "Enter the product date: ";
                    string date;   
                    cin >> date;
                    searchDate(log, date);
                    break;
                }else if(c == 2){   
                    cout << "Enter a range of date: ";
                    cout << "From: ";
                    string start, end;
                    cin >> start ;
                    cout << "To: ";
                    cin >> end;
                    searchDateRange(log, start, end);
                    break;
                }else if (c == 0){
                    cout << "Exiting the search by date menu."<<endl;
                    system("cls");
                    break;  
                }else{
                    cout << "Invalid choice, Please try again!"<<endl;  
                }
                break;
            }
            case 0: {
                cout << "Exiting the search menu."<<endl;
                system("cls");
                return;
            }
            default: cout << "Invalid choice, Please try again."<<endl; break; 
        }
        return;
    }
    cout << "Press enter to continue..."<<endl;
    cin.ignore();
    cin.get(); // Wait for user input
    return;
} 

void interface_searchDataList(List* ls){
    while(true){
        cout << "==================================" << endl;
        cout << "    SEARCH PRODUCT IN DATA LIST   " << endl;
        cout << "==================================" << endl;
        cout << "---------------Menu---------------" << endl;
        cout << "| 1. ID                          |" << endl;
        cout << "| 2. Name                        |" << endl;
        cout << "| 3. Catagory                    |" << endl;
        cout << "| 4. Unit                        |" << endl;
        cout << "| 5. Unit price                  |" << endl;
        cout << "| 0. Exit                        |" << endl;
        cout << "----------------------------------" << endl;
        cout << "Enter your choice: ";
        int choice;
        while(!(cin >> choice)) {
            cleanInput();
            cout << "Invalid input. Please enter a number: ";
        }

        switch(choice){
            case 1: {
                while(true){
                cout << "Search by ID"<<endl;
                cout << "1. Specific ID"<<endl;
                cout << "2. A range of ID "<<endl;
                cout << "0. Exit"<<endl;
                cout << "Enter your choice: ";
                int c; 
                while(!(cin >> c)) {
                    cleanInput();
                    cout << "Invalid input. Please enter 0-2: ";
                }

                if (c == 1){
                    cout << "Enter the product ID: ";
                    int id;
                    while(!(cin >> id)) {
                        cleanInput();
                        cout << "Invalid ID. Please enter a number: ";
                    }
                    searchByID(ls, id);
                    break;
                }else if (c == 2){
                    cout << "Enter a range of ID"<<endl;
                    cout << "From: ";
                    int start, end;
                    while(!(cin >> start)) {
                        cleanInput();
                        cout << "Invalid input. Please enter a number: ";
                    }
                    cout << "To: ";
                    while(!(cin >> end)) {
                        cleanInput();
                        cout << "Invalid input. Please enter a number: ";
                    }
                    searchByIDRange(ls, start, end);
                    break;
                }else if (c == 0){
                    cout << "Exiting the search by ID menu."<<endl;
                    clearScreen();
                    break;
                }else{
                    cout << "Invalid choice, Please try again!"<<endl;
                }
            }
            waitForUserInput();
            break;
        }
            case 2: {
                cout << "Search by Name"<<endl;
                cout << "Enter the product name: ";
                string name;
                cin >> name;
                searchByName(ls, name);
                waitForUserInput();
                break;
            }
            case 3: {
                cout << "Search by Catagory"<<endl;
                cout << "Enter the product catagory: ";
                string catagory;
                cin >> catagory;
                searchByCategory(ls, catagory);
                waitForUserInput();
                break;
            }
            case 4: {
                cout << "Search by Unit"<<endl;
                cout << "1. Specific unit"<<endl;
                cout << "2. A range of unit"<<endl;
                cout << "0. Exit"<<endl;
                cout << "Enter your choice: ";
                int c; 
                while(!(cin >> c)) {
                    cleanInput();
                    cout << "Invalid input. Please enter 0-2: ";
                }
                if (c == 1){
                    cout << "Enter the product unit: ";
                    int units;
                    while(!(cin >> units)) {
                        cleanInput();
                        cout << "Invalid unit. Please enter a number: ";
                    }
                    searchByUnit(ls, units);
                    break;
                }else if(c == 2){
                    cout << "Enter a range of unit"<<endl;
                    cout << "From: ";
                    int start, end;
                    while(!(cin >> start)) {
                        cleanInput();
                        cout << "Invalid input. Please enter a number: ";
                    }
                    cout << "To: ";
                    while (!(cin >> end)) {
                        cleanInput();
                        cout << "Invalid input. Please enter a number: ";
                    }
                    searchByUnitRange(ls, start, end);
                    break;
                }else if (c == 0){
                    cout << "Exiting the search by ID menu."<<endl;
                    clearScreen();
                    break;
                }else{
                    cout << "Invalid choice, Please try again!"<<endl;
                }
                waitForUserInput();
                break;
            }
            case 5: {
                cout << "Search by Unit price"<<endl;
                cout << "1. Specific unit price"<< endl;
                cout << "2. A range of unit price"<< endl;
                cout << "0. Exit"<<endl;
                cout << "Enter your choice: ";
                int c; 
                while(!(cin >> c)) {
                    cleanInput();
                    cout << "Invalid input. Please enter 0-2: ";
                }
                if (c == 1){ 
                cout << "Enter the product unit price: ";
                int unitPrice;
                while(!(cin >> unitPrice)) {
                    cleanInput();
                    cout << "Invalid unit price. Please enter a number: ";
                }
                searchByUnitPrice(ls, unitPrice);
                break;

                }else if(c == 2){
                    cout << "Enter a range of unit price: ";
                    cout << "From: ";
                    int start, end;
                    while(!(cin >> start)) {
                        cleanInput();
                        cout << "Invalid input. Please enter a number: ";
                    }
                    cout << "To: ";
                    while (!(cin >> end)) {
                        cleanInput();
                        cout << "Invalid input. Please enter a number: ";
                    }
                    searchByUnitPriceRange(ls, start, end);
                    break;
                }else if (c == 0){
                    cout << "Exiting the search by ID menu."<<endl;
                    clearScreen();
                    break;
                }else{
                    cout << "Invalid choice, Please try again!"<<endl;
                }
                waitForUserInput();
                break;
            }
            case 0: {
                cout << "Exiting the search menu."<<endl;
                clearScreen();
                return;
            }
            default: cout << "Invalid choice, Please try again."<<endl; 
            waitForUserInput();
            break; 
        }
    }
}
#endif

