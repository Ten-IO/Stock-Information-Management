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
#include "login.h"
#include "loadCSV.h"
using namespace std;
extern List* stocklist;
void setColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void menu() {
    
	void loadCSV(const string& filename, List* ls);

   // loadFromCSV(CURRENT_FILE, stocklist);

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
			    writeLog(item.id, item.name, item.units, currentAdmin, "Import");
			    break;
			}
            case 2: {
			    setColor(15);
			    List* stocklist = initList();
			    loadCSV("Current.csv", stocklist);
			    displayFromMemory(stocklist);
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
                modifyViaID(stocklist, oldData, newData, currentAdmin);
                break;
            }
            case 4: {
                setColor(15);
                int id;
                cout << "Delete product from stock\n";
                cout << "Enter the position to delete: ";
                cin >> id;
                deleteByID(stocklist, id, currentAdmin);
        
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
			    int id, qty;
				string name;
				if (exportByID(stocklist, id, name, qty)) {
				    writeLog(id, name, qty, currentAdmin, "Export");
				}
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
