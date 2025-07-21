#include <iostream>
// #include "StockList.h"
#include "FileManager.h"
// #include "SystemLog.h"
#include "label.h"
#include "benchmark.h"
#include "displayManager.h"
void acceptingInput(Item &item)
{
    topBox(1);
    std::cout << "\033[A\033[6C";
    std::cout << "ID: ";
    std::cin >> item.id;
    topBox(1);
    std::cout << "\033[A\033[6C";
    std::cout << "Name: ";
    std::cin >> item.name;
    topBox(1);
    std::cout << "\033[A\033[6C";
    std::cout << "Category: ";
    std::cin >> item.category;
    topBox(1);
    std::cout << "\033[A\033[6C";
    std::cout << "Unit: ";
    std::cin >> item.units;
    topBox(1);
    std::cout << "\033[A\033[6C";
    std::cout << "Unit price: ";
    std::cin >> item.unitPrice;
    botBox(1);
}
int main()
{
    Timer time;
    List *stock = new List;
    // FileManager f = FileManager("item.db");
    int choice;
    Item item{};

    while (true)
    {
        std::cout << "";
        std::cout << smallStart();
        std::cout << "\n------------ Menu ------------\n";
        std::cout << "| 1. Create                   |\n";
        std::cout << "| 2. Read                     |\n";
        std::cout << "| 3. Update                   |\n";
        std::cout << "| 4. Delete                   |\n";
        std::cout << "| 5. Search                   |\n";
        std::cout << "| 0. Exit the program         |\n";
        std::cout << "===============================\n";
        inputBox(1);
        std::cin >> choice;
        std::cout << '\n';
        checkInput();

        switch (choice)
        {
        case 1:
        {
            std::cout << "== Add new product to stock - Products information ==\n";
            acceptingInput(item);
            stock->addItem(item);
            break;
        }
        case 2:
            tableList(stock);
            break;
        case 3:
        {
            Item oldData, newData;
            std::cout << "Update the products - ProductID \n";
            inputBox(1);
            std::cout << "Enter ID to modify: ";
            std::cin >> oldData.id;

            acceptingInput(newData);
            int result = stock->modifyViaID(oldData, newData);
            if (result < -1)
                std::cout << "Not found\n";
            else
                std::cout << result << " updated\n";
            break;
        }
        case 4:
        {
            int pos;
            std::cout << "Delete a products from the stock\n";
            std::cout << "Enter the position of the products you want to delete: ";
            std::cin >> pos;
            stock->deleteAtPos(pos);
            break;
        }
        case 5:
        {
            int id;
            std::cout << "Search for the product by its ID\n";
            std::cout << "Enter the product ID: ";
            std::cin >> id;
            stock->showID(id);
            break;
        }
        case -1:
        {
            std::cout << "Exit program";
            return 0;
            break;
        }

        default:
            std::cout << "Input is not define, please check from the choice.\n";
            break;
        }
    }
}