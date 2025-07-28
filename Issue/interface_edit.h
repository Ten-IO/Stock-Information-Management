#ifndef INTERFACE_EDIT1_H
#define INTERFACE_EDIT1_H

#include <iostream>
#include <limits>
#include <cstring> // for memcmp
#include "modifier.h"
#include "createFile.h"
#include "search1.h"
using namespace std;

void displayProduct(const Item& item);  // Add declaration if not already present

void interface_edit(List* ls) {
    while(true) {
        cout << "==================================" << endl;
        cout << "            EDIT PRODUCT          " << endl;
        cout << "==================================" << endl;

        cout << "Enter the product ID you want to edit (0 to exit): ";
        int idnumber;
        cin >> idnumber;
        
        // Exit condition
        if(idnumber == 0) {
            system("cls");
            return;
        }

        Stock* foundNode = searchByID(ls, idnumber);
        if(foundNode == nullptr) {
            cout << "Product not found!" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;  // Go back to start of loop
        }

        Item oldData = foundNode->item;
        Item newData = oldData;

        while(true) {
            cout << "/nCurrent product values: "<<endl;
            displayProduct(oldData);
            
            cout << "---------------Menu---------------" << endl;
            cout << "| 1. Edit ID                     |" << endl;
            cout << "| 2. Edit name                   |" << endl;
            cout << "| 3. Edit category               |" << endl;
            cout << "| 4. Edit unit                   |" << endl;
            cout << "| 5. Edit unit price             |" << endl;
            cout << "| 0. Exit                        |" << endl;
            cout << "----------------------------------" << endl;
            cout << "Enter your choice: ";
            
            int choice;
            if(!(cin >> choice)) {  // Handle non-integer input
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Please enter a number." << endl;
                continue;
            }

            switch(choice) {
                case 1: {
                    cout << "Current ID: " << newData.id << endl;
                    cout << "Enter new ID: ";
                    if(!(cin >> newData.id)) {
                        // Handle invalid input
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid ID. Please try again." << endl;
                        break;
                    }
                    break;
                }
                case 2: {
                    cout << "Current name: " << newData.name << endl;
                    cout << "Enter new name: ";
                    cin.ignore();  // Clear newline from buffer
                    getline(cin, newData.name);
                    break;
                }
                case 3: {
                    cout << "Current category: " << newData.category << endl;
                    cout << "Enter new category: ";
                    cin.ignore();
                    getline(cin, newData.category);
                    break;
                }
                case 4: {
                    cout << "Current units: " << newData.units << endl;
                    cout << "Enter new unit quantity: ";
                    if(!(cin >> newData.units) || newData.units < 0) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid quantity. Please try again." << endl;
                        break;
                    }
                    break;
                }
                case 5: {
                    cout << "Current unit price: " << newData.unitPrice << endl;
                    cout << "Enter new unit price: ";
                    if(!(cin >> newData.unitPrice) || newData.unitPrice < 0) {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Invalid price. Please try again." << endl;
                        break;
                    }
                    break;
                }
                case 0: {
                    // Only update CSV if changes were made
                    if(memcmp(&oldData, &newData, sizeof(Item)) != 0) {  // Fixed syntax
                        modifyViaID(ls, oldData, newData);
                        // if(!createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, ls, false)) {
                        //     cout << "Error saving changes to file!" << endl;
                        // }
                    }
                    #ifdef _WIN32
                    system("cls");
                    #else
                    system("clear");
                    #endif
                    return;
                }
                default: {
                    cout << "Invalid choice, Please try again." << endl;
                    break;
                }
            }
        }
    }
}
#endif // INTERFACE_EDIT1_H
