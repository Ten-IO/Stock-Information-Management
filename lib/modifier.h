#pragma once

#include <iostream>
#include <iomanip>
#include "StockList.h"
#include "DisplayManager.h"

/**
 * @brief using ID to export info of an item in Stock
 * @param List LinkedList of main data from FileManager @param name product name/brand @param qtyOut quantity export @param price export/retail price
 * @retval `true` - found/able to export
 * @retval `false` - not found, quantity overload/underload,
 */
bool exportByID(List *ls, int &id, std::string &name, int &qtyOut, double &price);

/**
 * @brief using product name to export info of item
 * @param List LinkedList of main data from FileManager @param name product name/brand @param qtyOut quantity export @param price export/retail price
 * @retval `true` - found/able to export
 * @retval `false` - not found, quantity overload/underload,
 */
bool exportByName(List *ls, int &id, std::string &name, int &qtyOut, double &price);

/**
 * @brief using ID to export info of item
 * @param List LinkedList of data from SystemLog of product info
 * @return table displaying Import & Export + Summary
 */
void reportList(List *ls);