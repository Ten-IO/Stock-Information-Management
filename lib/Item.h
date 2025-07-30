#pragma once
#include <string>

/**
 * @struct Item
 * @brief represent details of product in stock 
 * contains order of id, quantity, product name, class category, and price.
 * */
struct Item
{
    // indentify `id` value and `units`amount
    int id, units;
    // `name` of product and `category` it is in
    std::string name, category;
    // `unitPrice` cash values
    double unitPrice;
};