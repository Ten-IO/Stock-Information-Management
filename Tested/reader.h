#include "stock.h"
#include <iostream>

/**
 * @brief extract out of list
 * @param List* point to LinkedList
 * @return void
 */
void display(List *ls)
{
    Stock *s = ls->head;
    while (s != nullptr)
    {
        std::cout << s->item.id << " " << s->item.name << " " << s->item.category << " " << s->item.units << " " << s->item.unitPrice << "\n";
        s = s->next;
    }
}

//display from file
void displayFromFile(const std::string &filename){
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: "<<filename << std::endl;
        return ;
    }
    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
    file.close();
}

