#include <iostream>
#include "stock.h"
#include "create.h"
#include "createFile.h"
using namespace std;

void interface_create(List *ls) {
    cout << "==============================" << endl;
    cout << "       CREATE PRODUCT         " << endl;
    cout << "==============================" << endl;
    cout << "Add new product to stock: " << endl;
    Item item;
    cout << "Product ID: ";
    cin >> item.id;
    cout << "Product name: ";
    cin >> item.name;
    cout << "Product category: ";
    cin >> item.category;
    cout << "Product unit: ";
    cin >> item.units;
    cout << "Product unit price: ";
    cin >> item.unitPrice;
    addEnd(ls, item);
    cout << "Product created successfully!" << endl;
    User user;
    //writeLog(user.username, item.id, item.name, "Create Product", item.units);
    cout << "Press enter to continue..."<<endl;
    cin.ignore();
    cin.get(); // Wait for user input
}

