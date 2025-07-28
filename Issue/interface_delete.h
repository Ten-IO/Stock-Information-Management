#ifndef INTERFACE_DELETE_H
#define INTERFACE_DELETE_H
#include <iostream>
#include "stock.h"
#include "delete.h"
#include "search1.h"
#include "createFile.h"
#include "item.h"
using namespace std;

Stock* searchByID (List* ls, int id);
Stock* searchByName (List* ls, const std::string& name);

void interface_delete(List* ls, const User& currentUser) {

    if (currentUser.role != ADMIN) {
    std::cout << "Access denied! Admin privileges required.\n";
    return;
    }
    while(true){

    cout << "==================================" << endl;
    cout << "           DELETE PRODUCT         " << endl;
    cout << "==================================" << endl;
    cout << "---------------Menu---------------" << endl;
    cout << "| 1. Delete by ID                |" << endl;
    cout << "| 2. Delete by Name              |" << endl;
    cout << "----------------------------------" << endl;
    cout << "Enter your choice: ";
    int choice ;
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cerr << "Invalid input. Please enter a number.\n";
        continue;
    }

    switch (choice){
        // case 1: {
        //     cout << "Delete product by ID"<<endl;
        //     cout << "Enter the product ID: ";
        //     int id;
        //     if (!(std::cin >> id)) {
        //         std::cin.clear();
        //         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //         std::cerr << "Invalid ID. Please enter a number.\n";
        //         break;
        //     }
        //     searchByID(ls, id);
        //     cout << "Are you sure you want to delete this product?(y/n) ";
        //     string ans;
        //     cin >> ans;
        //     if (ans == "yes" || ans == "Yes" || ans == "y" || ans == "Y"){
        //         // User user;
        //         // Item item;
        //         delete_id(ls, id);
        //         //wrtieLog(user.username, item.id, item.name, "Delete", item.units);
        //     }else {
        //         break;
        //     }
        //     break;
        // }
        case 1: {  // Delete by ID
                std::cout << "\nDelete product by ID\n";
                std::cout << "Enter the product ID: ";
                int id;
                if (!(std::cin >> id)) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cerr << "Invalid ID. Please enter a number.\n";
                    break;
                }

                Stock* foundItem = searchByID(ls, id);
                if (!foundItem) {
                    std::cerr << "Product with ID " << id << " not found.\n";
                    break;
                }

                std::cout << "Are you sure you want to delete this product? (y/n): ";
                char ans;
                std::cin >> ans;
                ans = toupper(ans);

                if (ans == 'Y') {
                    if (delete_id(ls, id, currentUser)) {
                        // Log the deletion
                        // writeLog(currentUser.username, foundItem->item.id, 
                        //         foundItem->item.name, "Delete", foundItem->item.units);
                    }
                } else {
                    std::cout << "Deletion cancelled.\n";
                }
                break;
            }
        // case 2: {
        //     cout << "Delete product by name"<<endl;
        //     cout << "Enter the product name : ";
        //     string name;
        //     cin >> name;
        //     searchByName(ls, name);
        //     cout << "Are you sure you want to delete this product?(y/n) ";
        //     string ans;      
        //     cin >> ans;
        //     if (ans == "yes" || ans == "Yes" || ans == "y" || ans == "Y"){
        //         delete_Name(ls, name);
        //         //wrtieLog(user.username, item.id, item.name, "Delete", item.units);
        //     }else {
        //         break;
        //     }
        //     break;
        // }

                case 2: {  // Delete by Name
                std::cout << "\nDelete product by name\n";
                std::cout << "Enter the product name: ";
                std::string name;
                std::cin.ignore();  // Clear the input buffer
                std::getline(std::cin, name);

                Stock* foundItem = searchByName(ls, name);
                if (!foundItem) {
                    std::cerr << "Product '" << name << "' not found.\n";
                    break;
                }

                std::cout << "Are you sure you want to delete this product? (y/n): ";
                char ans;
                std::cin >> ans;
                ans = toupper(ans);

                if (ans == 'Y') {
                    if (delete_Name(ls, name, currentUser)) {
                        // Log the deletion
                        // writeLog(currentUser.username, foundItem->item.id, 
                        //         foundItem->item.name, "Delete", foundItem->item.units);
                    }
                } else {
                    std::cout << "Deletion cancelled.\n";
                }
                break;
            }
         case 0:  // Exit
                std::cout << "Returning to main menu...\n";
                return;
        default: cout << "Invalid choice, Please try again."<<endl; break;
    }
}
    
}
#endif
