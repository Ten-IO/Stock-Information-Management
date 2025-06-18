#include <iostream>
#include <item.h>

int main() {
    Item prod1 = Item{01,22,"string 1","category", 1.1}; 
    Item *prod2 = new Item{02,23, "string 2", "cat2", -1.2};
    // c-20
    Item prod3 = {
    .id = 1,
    .units = 22,
    .name = "Widget",
    .category = "Gadgets",
    .unitPrice = 10.0,
};
    // double ptr = &prod3.unitPrice; // pointer is one data type for addr

    std::cout <<"1- "<< prod1.id <<" "<< prod1.unitPrice << " "<<prod1.units << " "<<prod1.category << "\n";
    std::cout <<"2- "<< prod2->id << " "<<prod2->unitPrice <<" "<< (*prod2).units << " "<<(*prod2).category << "\n";  
    std::cout <<"3- "<< prod3.id <<" "<< (&prod3.unitPrice) <<" "<< prod3.units << " "<<prod3.category << "\n";  
}