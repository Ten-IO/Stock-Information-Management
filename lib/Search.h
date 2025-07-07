#include <iostream>
#include "item.h"
#include "stock.h"

/**
 * @brief Use ID to search data
 * @param ls point to LinkedList
 * @param id match to item
 * @return void
 */
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