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

    std::cout <<"1- "<< prod1.id <<"\n2-"<< prod1.unitPrice << "\n3- " << prod1.units << "\n4- " << prod1.category;  
    std::cout <<"1- "<< prod2->id <<"\n2-"<< prod2->unitPrice << "\n3- " << (*prod2).units << "\n4- " << (*prod2).category;  
    std::cout <<"1- "<< prod3.id <<"\n2-"<< (&prod3.unitPrice) << "\n3- " << prod3.units << "\n4- " << prod3.category;  
}