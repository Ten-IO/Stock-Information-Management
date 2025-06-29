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
#include "filename.h"

using namespace std;

void setColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void menu() {
    List* stocklist = initList();
    List* emptyList = initList(); 

    vector<string> header = {"ID", "Name", "Category", "Unit", "Unit price"};
    createCSV(CURRENT_FILE, header, stocklist);  
    createCSV(IMPORT_FILE, header, emptyList);    
    createCSV(EXPORT_FILE, header, emptyList); 

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
        cout << "| 5. Search                   |"<<endl;
        cout << "| 0. Exit the program         |"<<endl;
        cout << "==============================="<<endl;

        setColor(1);
        cout << "Enter your choice(0-5): ";
        
        setColor(12);
        cin >> choice;
        switch (choice){
            case 1: {
                setColor(15);
                Item item;
                cout << "Add new product to stock: "<<endl;
                cout << "Enter your products information: "<<endl;
                
                cout << "ID: ";
                cin >> item.id;
                cout << "Name: ";
                cin >> item.name;
                cout << "Category: ";
                cin >> item.category;
                cout << "Unit: ";
                cin >> item.units;
                cout << "Unit price: ";
                cin >> item.unitPrice;
                addEnd(stocklist, item);
                break;
            }
            case 2: {
                setColor(15);
                display(stocklist);
                break;
            }
            case 3: {
                setColor(15);
                Item oldData, newData;
                cout << "Update the products"<<endl;
                cout << "Enter ID to modify: ";
                cin >> oldData.id;

                cout << "Enter new item name: ";
                cin >> newData.name;
                cout << "Enter new category: ";
                cin >> newData.category;
                cout << "Enter new units: ";
                cin >> newData.units;
                cout << "Enter new price: ";
                cin >> newData.unitPrice;
                modifyViaID(stocklist, oldData, newData);
                break;
            }
            case 4: {
                setColor(15);
                int pos;
                cout << "Delete a products from the stock"<<endl;
                cout << "Enter the position of the products you want to delete: ";
                cin >> pos;
                deleteAtPos(stocklist, pos);
                break;
            }
            case 5: {
                setColor(15);
                int id;
                cout << "Search for the product by its ID"<<endl;
                cout << "Enter the product ID: ";
                cin >> id;
                searchByID(stocklist, id);
                break;
            }
            case 0: {
                cout << "Exit program"; 
                return;
            }
            default:{ 
                cout << "Invalid choice, Please try again."<<endl;
            }
        }
        setColor(7);
    }
}

