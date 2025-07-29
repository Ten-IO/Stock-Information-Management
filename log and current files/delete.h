#include <iostream>
#include <fstream>
#include <vector>
#include "stock.h"
#include "createFile.h"

using namespace std;

//void deleteAtPos(List *ls, int pos)
//{
//    if (ls->n == 0 || pos < 0 || pos >= ls->n)
//    {
//        std::cout << "Invalid pos for stock\n";
//        return;
//    }
//    Item deletedItem;
//    if (pos == 0)
//    {
//        Stock *tmp = ls->head;
//        deletedItem = tmp->item;
//        ls->head = tmp->next;
//        delete tmp;
//        if (ls->n == 1) 
//            ls->tail = nullptr;
//    }
//    else
//    {
//        Stock *current = ls->head;
//        for (int i = 0; i < pos - 1; i++)
//        {
//            current = current->next;
//        }
//        Stock *tmp = current->next;
//        deletedItem = tmp->item;
//        current->next = tmp->next;
//        if (tmp == ls->tail)
//            ls->tail = current;
//
//        delete tmp;
//    }
//     ls->n--;
   
//}

void deleteByID(List* ls, int targetID, const string& username) {
    if (ls->head == nullptr) {
        cout << "Stock list is empty.\n";
        return;
    }

    Stock* current = ls->head;
    Stock* prev = nullptr;

    while (current != nullptr) {
        if (current->item.id == targetID) {
            Item deletedItem = current->item;

            if (prev == nullptr) {
                ls->head = current->next;
                if (current == ls->tail) ls->tail = nullptr;
            } else {
                prev->next = current->next;
                if (current == ls->tail) ls->tail = prev;
            }

            delete current;
            ls->n--;
            
            createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, ls);

            writeLog(deletedItem.id, deletedItem.name, deletedItem.units, username, "Delete");

            cout << "Deleted item ID " << deletedItem.id << " successfully.\n";
            return;
        }

        prev = current;
        current = current->next;
    }

    cout << "Item with ID " << targetID << " not found.\n";
}

