#include <iostream>
#include "item.h"
#include "stock.h"

Stock *searchByID(List* ls, int id){
    Stock* e = ls -> head;
    while(e != nullptr){
        if (e -> item.id == id){
            std::cout << id << "is found."<<std::endl;
            return e;
        }
        e = e -> next;
    }
    std::cout << id << " is not found."<<std::endl;
    return nullptr;
}