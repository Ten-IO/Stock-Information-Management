// #ifndef SEARCH1_H
// #define SEARCH1_H

// #include "stock.h"
// #include <vector> 
// #include <iostream>

// struct Stock;
// struct Item;

// void displayProduct(const Item& item);

// // Programmatic search functions
// Stock* searchByID(List* ls, int id);
// std::vector<Stock*> searchByIDRange(List* ls, int a, int b);
// Stock* searchByName(List* ls, const std::string& name);
// std::vector<Stock*> searchByCategory(List* ls, const std::string& category);
// std::vector<Stock*> searchByUnit(List* ls, int units);
// std::vector<Stock*> searchByUnitRange(List* ls, int a, int b);
// std::vector<Stock*> searchByUnitPrice(List* ls, int unitPrice);
// std::vector<Stock*> searchByUnitPriceRange(List* ls, int a, int b);

// // Display functions
// void displaySearchByID(List* ls, int id);
// void displaySearchByIDRange(List* ls, int a, int b);

// #endif

#ifndef SEARCH_H
#define SEARCH_H

#include "item.h"
#include "stock.h"
#include <vector>
#include <iostream>

// Search functions that return nodes (for programmatic use)
Stock* searchByID(List* ls, int id);
std::vector<Stock*> searchByIDRange(List* ls, int a, int b);
Stock* searchByName(List* ls, const std::string& name);
std::vector<Stock*> searchByCategory(List* ls, const std::string& category);
std::vector<Stock*> searchByUnit(List* ls, int units);
std::vector<Stock*> searchByUnitRange(List* ls, int a, int b);
std::vector<Stock*> searchByUnitPrice(List* ls, int unitPrice);
std::vector<Stock*> searchByUnitPriceRange(List* ls, int a, int b);

// Display functions (for user interface)
void displaySearchByID(List* ls, int id);
void displaySearchByIDRange(List* ls, int a, int b);
void displaySearchByName(List* ls, const std::string& name);
void displaySearchByCategory(List* ls, const std::string& category);
void displaySearchByUnit(List* ls, int units);
void displaySearchByUnitRange(List* ls, int a, int b);
void displaySearchByUnitPrice(List* ls, int unitPrice);
void displaySearchByUnitPriceRange(List* ls, int a, int b);

// Helper function
void displayProduct(const Item& item);

#endif
// void displayProduct(const Item& item) {
//     std::cout << "ID: " << item.id << "\n"
//               << "Name: " << item.name << "\n"
//               << "Category: " << item.category << "\n"
//               << "Units: " << item.units << "\n"
//               << "Unit Price: " << item.unitPrice << "\n" << std::endl;
// }

// // Programmatic search functions
// Stock* searchByID(List* ls, int id) {
//     Stock* e = ls->head;
//     while(e != nullptr) {
//         if(e->item.id == id) {
//             return e;
//         }
//         e = e->next;
//     }
//     return nullptr;
// }

// std::vector<Stock*> searchByIDRange(List* ls, int a, int b) {
//     std::vector<Stock*> results;
//     Stock* e = ls->head;
//     while(e != nullptr) {
//         if(e->item.id >= a && e->item.id <= b) {
//             results.push_back(e);
//         }
//         e = e->next;
//     }
//     return results;
// }

// Stock* searchByName(List* ls, const std::string& name) {
//     Stock* e = ls->head;
//     while(e != nullptr) {
//         if(e->item.name == name) {
//             return e;
//         }
//         e = e->next;
//     }
//     return nullptr;
// }

// std::vector<Stock*> searchByCategory(List* ls, const std::string& category) {
//     std::vector<Stock*> results;
//     Stock* e = ls->head;
//     while(e != nullptr) {
//         if(e->item.category == category) {
//             results.push_back(e);
//         }
//         e = e->next;
//     }
//     return results;
// }

// std::vector<Stock*> searchByUnit(List* ls, int units) {
//     std::vector<Stock*> results;
//     Stock* e = ls->head;
//     while(e != nullptr) {
//         if(e->item.units == units) {
//             results.push_back(e);
//         }
//         e = e->next;
//     }
//     return results;
// }

// std::vector<Stock*> searchByUnitRange(List* ls, int a, int b) {
//     std::vector<Stock*> results;
//     Stock* e = ls->head;
//     while(e != nullptr) {
//         if(e->item.units >= a && e->item.units <= b) {
//             results.push_back(e);
//         }
//         e = e->next;
//     }
//     return results;
// }

// std::vector<Stock*> searchByUnitPrice(List* ls, int unitPrice) {
//     std::vector<Stock*> results;
//     Stock* e = ls->head;
//     while(e != nullptr) {
//         if(e->item.unitPrice == unitPrice) {
//             results.push_back(e);
//         }
//         e = e->next;
//     }
//     return results;
// }

// std::vector<Stock*> searchByUnitPriceRange(List* ls, int a, int b) {
//     std::vector<Stock*> results;
//     Stock* e = ls->head;
//     while(e != nullptr) {
//         if(e->item.unitPrice >= a && e->item.unitPrice <= b) {
//             results.push_back(e);
//         }
//         e = e->next;
//     }
//     return results;
// }

// // Display functions
// void displaySearchByID(List* ls, int id) {
//     Stock* result = searchByID(ls, id);
//     if(result) {
//         displayProduct(result->item);
//     } else {
//         std::cerr << "ID: " << id << " not found" << std::endl;
//     }
// }

// void displaySearchByIDRange(List* ls, int a, int b) {
//     auto results = searchByIDRange(ls, a, b);
//     if(!results.empty()) {
//         std::cout << "Found " << results.size() << " products:" << std::endl;
//         for(auto* item : results) {
//             displayProduct(item->item);
//         }
//     } else {
//         std::cerr << "No products found in range " << a << " to " << b << std::endl;
//     }
// }
// // void searchUsername(Loglist* log, string username){
// //     Log* e = log -> head;
// //     while(e != nullptr){
// //         if(e -> user.username == username){
// //             std::cout <<"Username "<< username << " is found."<<std::endl;
// //             std::cout << "Username: "<< e -> user.username<< std::endl;
// //             std::cout << "Action type: "<< e -> user.action_type <<std::endl;
// //             std::cout << "Item_id: "<< e -> user.item_id << std::endl;
// //             std::cout << "Date: " << e -> user.date << std::endl;
// //             return;
// //         }
// //         e = e -> next;
// //         }
// //     std::cerr << "Username: "<<username << " is not found."<<std::endl;
// // }
// // void searchAction_type(Loglist* log, string action_type){
// //     Log* e = log -> head;
// //     while(e != nullptr){
// //         if(e -> user.action_type == action_type){
// //             std::cout <<"Action type "<< action_type << " is found."<<std::endl;
// //             std::cout << "Username: "<< e -> user.username<< std::endl;
// //             std::cout << "Action type: "<< e -> user.action_type << std::endl;
// //             std::cout << "Item_id: "<< e -> user.item_id << std::endl;
// //             std::cout << "Date: " << e -> user.date << std::endl;
// //             return; 
// //         }
// //         e = e -> next;
// //     }
// //     std::cerr << "Activity: " << action_type << " is not found. " << std::endl;
// // }
// // void searchDate(Loglist* log, string date){
// //     Log* e = log -> head;
// //     while(e != nullptr){
// //         if (e-> user.date == date){
// //             std::cout << "Date: "<< date<< " is found. "<< std::endl;
// //             std::cout << "Username: "<< e -> user.username<< std::endl;
// //             std::cout << "Action type: "<< e -> user.action_type << std::endl;
// //             std::cout << "Item_id: "<< e -> user.item_id << std::endl;
// //             std::cout << "Date: " << e -> user.date << std::endl;
// //             return; 
// //         }
// //         e = e -> next;
// //     }
// //     std::cerr << "Date: " << date << " is not found. " << std::endl;
// // }
// // void searchDateRange(Loglist* log, string a, string b){
// //     Log* e = log -> head;
// //     while(e != nullptr){
// //         if (e -> user.date >= a && e -> user.date <= b){
// //             std::cout << "Date from "<< a << " to "<< b << " is found. "<< std::endl;
// //             std::cout << "Username: "<< e -> user.username<< std::endl;
// //             std::cout << "Action type: "<< e -> user.action_type << std::endl;
// //             std::cout << "Item_id: "<< e -> user.item_id << std::endl;
// //             std::cout << "Date: " << e -> user.date << std::endl;
// //             return; 
// //         }
// //         e = e -> next;
// //     }
// //     std::cerr << "Error! Invalid input, check your input again."<< std::endl;
// // }


// #endif