#ifndef DELETE_H
#define DELETE_H

#include <iostream>
#include <fstream>
#include "stock.h"
#include "createFile.h"
#include "filename.h"

//delete product base on it ID
// void delete_id(List* ls, int id){ 
//     if (ls -> n == 0 ){
//         std::cout <<  "The list is empty.\n";
//         return;
//     }
//     Stock* current = ls -> head;
//     Stock* prev = nullptr;
//     while (current != nullptr){
//         if (current ->item.id == id){
//             if (prev == nullptr){
//                 ls->head = current->next;
//             }else{
//                 prev -> next = current -> next;
//             }
//         std::cout << "Deleting item with ID: " << id << endl;
//         delete current;
//         ls -> n--;
//         createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, ls, false);
//         std::cout << "Item with ID: "<<id<< " deleted."<<endl;
//         return;
//         }
//         prev = current;
//         current = current -> next;
//     }
//         std::cerr << "Item with ID "<<id << " not found. "<<endl;
    
// }
// bool delete_Name(List* ls, string name, const User& currentUser){
//     // Verify admin privileges
//     if (currentUser.role != ADMIN) {
//         std::cerr << "Error: Admin privileges required to delete items.\n";
//         return false;
//     }

//     if (ls -> n == 0 ){
//         std::cout <<  "The list is empty.\n";
//         return;
//     }
//     Stock* current = ls -> head;
//     Stock* prev = nullptr;
//     bool deleted = false;

//     while (current != nullptr){
//         if (current ->item.name == name){
//             if (prev == nullptr){
//                 ls->head = current->next;
//             }else{
//                 prev -> next = current -> next;
//             }
//         std::cout << "Deleting item with name: " << name << endl;   
//         delete current;
//         ls -> n--;
//         createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, ls, false);
//         std::cout << "Item with name: "<<name<< " deleted."<<endl;
//         return;
//         }
//         prev = current;
//         current = current -> next;
//     }
//         std::cerr << "Item with name "<<name<< " not found. "<<endl;
// }

bool delete_id(List* ls, int id, const User& currentUser) {
    // Verify admin privileges
    if (currentUser.role != ADMIN) {
        std::cerr << "Error: Admin privileges required to delete items.\n";
        return false;
    }

    if (ls == nullptr || ls->n == 0) {
        std::cerr << "Error: The list is empty or invalid.\n";
        return false;
    }

    Stock* current = ls->head;
    Stock* prev = nullptr;
    bool deleted = false;

    while (current != nullptr) {
        if (current->item.id == id) {
            // Update pointers
            if (prev == nullptr) {
                ls->head = current->next;
            } else {
                prev->next = current->next;
            }

            // Handle tail pointer if deleting last item
            if (current == ls->tail) {
                ls->tail = prev;
            }

            // Delete and update count
            Stock* toDelete = current;
            current = current->next;
            delete toDelete;
            ls->n--;
            deleted = true;
            
            // Update CSV
            // if (!createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, ls, false)) {
            //     std::cerr << "Warning: Item deleted but failed to update data file.\n";
            // }
            
            std::cout << "Successfully deleted item with ID: " << id << "\n";
            break;
        }
        prev = current;
        current = current->next;
    }

    if (!deleted) {
        std::cerr << "Item with ID " << id << " not found.\n";
        return false;
    }
    return true;
}
// Delete product based on name with role verification
bool delete_Name(List* ls, const std::string& name, const User& currentUser) {
    // Verify admin privileges
    if (currentUser.role != ADMIN) {
        std::cerr << "Error: Admin privileges required to delete items.\n";
        return false;
    }

    if (ls == nullptr || ls->n == 0) {
        std::cerr << "Error: The list is empty or invalid.\n";
        return false;
    }

    Stock* current = ls->head;
    Stock* prev = nullptr;
    bool deleted = false;

    while (current != nullptr) {
        if (current->item.name == name) {
            // Update pointers
            if (prev == nullptr) {
                ls->head = current->next;
            } else {
                prev->next = current->next;
            }

            // Handle tail pointer if deleting last item
            if (current == ls->tail) {
                ls->tail = prev;
            }

            // Delete and update count
            Stock* toDelete = current;
            current = current->next;
            delete toDelete;
            ls->n--;
            deleted = true;
            
            // // Update CSV
            // if (!createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, ls, false)) {
            //     std::cerr << "Warning: Item deleted but failed to update data file.\n";
            // }
            
            std::cout << "Successfully deleted item with name: " << name << "\n";
            break;
        }
        prev = current;
        current = current->next;
    }

    if (!deleted) {
        std::cerr << "Item with name '" << name << "' not found.\n";
        return false;
    }
    return true;
}

#endif // DELETE_H

