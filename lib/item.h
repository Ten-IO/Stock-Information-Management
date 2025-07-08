#include <string>
using std::string;

/**
 * @struct Item
 * @brief represent details of product in stock 
 * contains id, class item, price, along with quantity.
 * */
struct Item
{
    // indentify `id` value and `units`amount
    int id, units;
    // `name` of product and `category` it is in
    string name, category;
    // `unitPrice` cash values
    double unitPrice;
};