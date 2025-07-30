#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <string>
#include "stock.h"
#include "userRole.h"
using namespace std;

void displayProduct(const Item& item);

// Stock search
Stock* searchByID(List* ls, int id);
Stock* searchByName(List* ls, const string& name);
vector<Stock*> searchByCategory(List* ls, const string& category);
void displaySearchByID(List* ls, int id);

// Log search
void searchUsername(Loglist* log, const string& username);
void searchActionType(Loglist* log, const string& actionType);
void searchDate(Loglist* log, const string& date);
void searchDateRange(Loglist* log, const string& startDate, const string& endDate);

#endif

