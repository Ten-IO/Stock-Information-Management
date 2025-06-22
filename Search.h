#include <iostream>
#include "item.h"
#include "stock.h"
using namespace std;

void searchByID(List* ls, int id){
    Stock* e = ls -> head;
    while(e != nullptr){
        if (e -> item.id == id){
            cout << id << "is found."<<endl;
            cout << "The product info: "<<endl;
            cout << "ID: "<< e -> item.id;
            cout << "Name: "<< e -> item.name;
            cout << "Category: "<< e -> item.category;
            cout << "Unit: "<< e -> item.units;
            cout << "Unit price: "<< e -> item.unitPrice;
            return;
        }
        e = e -> next;
    }
    cout << id << "is not found."<<endl;
}