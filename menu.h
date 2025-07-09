#include <iostream>
#include <windows.h>
#include "item.h"
#include "stock.h"
#include "create.h"
#include "delete.h"
#include "modifier.h"
#include "reader.h"
#include "Search.h"
#include "createFile.h"
#include "fileHeader.h"
#include "export.h"
#include <limits>     
#include <algorithm>
using namespace std;

void setColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void menu() {
    List* stocklist = initList();

    loadFromCSV(CURRENT_FILE, stocklist);

    while (true) {
        cout << "==============================" << endl;
        cout << "       STOCK MANAGEMENT       " << endl;
        cout << "==============================" << endl;

        int choice;
        setColor(10);
        cout << "------------ Menu ------------" << endl;
        cout << "| 1. Create                   |" << endl;
        cout << "| 2. Read                     |" << endl;
        cout << "| 3. Update                   |" << endl;
        cout << "| 4. Delete                   |" << endl;
        cout << "| 5. Search                   |" << endl;
        cout << "| 6. Export                   |" << endl;
        cout << "| 0. Exit the program         |" << endl;
        cout << "===============================" << endl;

        setColor(1);
        cout << "Enter your choice (0 to 6): ";

        setColor(12);
        cin >> choice;

        switch (choice) {
         
            case 1: {
			    setColor(15);
			    Item item;
			    cout << "Add new product to stock:\n";
			    cout << "Enter your product information:\n";
			
			    while (true) {
			        cout << "ID: ";
			        if (cin >> item.id) break;
			        cout << "? Invalid ID. Please enter a number.\n";
			        cin.clear();
			        cin.ignore(numeric_limits<streamsize>::max(), '\n');
			    }
			
			    cout << "Name: ";
			    cin >> item.name;
			
			    cout << "Category: ";
			    cin >> item.category;
			
			    while (true) {
			        cout << "Unit: ";
			        if (cin >> item.units) break;
			        cout << "Invalid unit amount. Please enter a number.\n";
			        cin.clear(); 
					cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
			    }
			
			    while (true) {
			        cout << "Unit price : ";
			        if (cin >> item.unitPrice) break;
			        cout << "Invalid price. Please enter a numeric value.\n";
			        cin.clear();
			        cin.ignore(numeric_limits<streamsize>::max(), '\n');
			    }
			
			    addEnd(stocklist, item);
			    break;
			}
            case 2: {
			    setColor(15);
			    displayFromFile();
			    break;
			}
            case 3: {
                setColor(15);
                Item oldData, newData;
                cout << "Update product:\n";
                cout << "Enter ID to modify: ";
                cin >> oldData.id;

                cout << "Enter new name: "; cin >> newData.name;
                cout << "Enter new category: "; cin >> newData.category;
                cout << "Enter new units: "; cin >> newData.units;
                cout << "Enter new price: "; cin >> newData.unitPrice;
                newData.id = oldData.id;
                modifyViaID(stocklist, oldData, newData);
                break;
            }
            case 4: {
                setColor(15);
                int pos;
                cout << "Delete product from stock\n";
                cout << "Enter the position to delete: ";
                cin >> pos;
                deleteAtPos(stocklist, pos);
                break;
            }
            case 5: {
                setColor(15);
                int id;
                cout << "Search product by ID:\n";
                cout << "Enter the product ID: ";
                cin >> id;
                searchByID(stocklist, id);
                break;
            }
            case 6: {
			    setColor(15);
			    exportByID(stocklist);
			    break;
			}
            case 0: {
                cout << "Exiting program...\n";
                return;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
            }
        }

        setColor(7);
    }
}
