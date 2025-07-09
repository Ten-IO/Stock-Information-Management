#include <iostream>
#include <fstream>
#include <vector>
#include "stock.h"
#include "createFile.h"

using namespace std;

void deleteAtPos(List *ls, int pos)
{
    if (ls->n == 0 || pos < 0 || pos >= ls->n)
    {
        std::cout << "Invalid pos for stock\n";
        return;
    }
    Item deletedItem;
    if (pos == 0)
    {
        Stock *tmp = ls->head;
        deletedItem = tmp->item;
        ls->head = tmp->next;
        delete tmp;
        if (ls->n == 1) 
            ls->tail = nullptr;
    }
    else
    {
        Stock *current = ls->head;
        for (int i = 0; i < pos - 1; i++)
        {
            current = current->next;
        }
        Stock *tmp = current->next;
        deletedItem = tmp->item;
        current->next = tmp->next;
        if (tmp == ls->tail)
            ls->tail = current;

        delete tmp;
    }
     ls->n--;
   
    
    createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, ls);
}
// void delete_id(List* ls, Item data, int id){
//     if (ls -> n == 0 ){
//         std::cout <<  "The list is empty.\n";
//         return;
//     }
//     Stock* current = ls -> head;
//     Stock* prev = nullptr;
//     while (current != nullptr){
//         if (current ->data.id == id){
//             if (prev == nullptr){
//                 ls->head = current->next;
//             }else{
//                 prev -> next = current -> next;
//             }
//             if ()
            
//         delete tmp;
//         ls -> n--;
//         cout << "Item with ID "<<id<< " deleted."<<endl;
//         }
//         tmp = tmp -> next;
//     }

// }

