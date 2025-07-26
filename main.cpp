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
    item.id = readInt("ID: ");
    topBox(1);
    std::cout << "\033[A\033[6C";
    item.name = readStr("Name: ");
    topBox(1);
    std::cout << "\033[A\033[6C";
    item.category = readStr("Category: ");
    topBox(1);
    std::cout << "\033[A\033[6C";
    item.units = readInt("Unit(s): ");
    topBox(1);
    std::cout << "\033[A\033[6C";
    item.unitPrice = readFloat("Unit price: ");
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
        choice = readInt(" ");
        std::cout << '\n';
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
            oldData.id = readInt("Enter ID to modify");

            acceptingInput(newData);
            int result = stock->modifyViaID(oldData.id, newData);
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
            pos = readInt("Enter product's position: ");
            stock->deleteAtPos(pos);
            break;
        }
        case 5:
        {
            int id;
            std::cout << "Search for the product by its ID\n";
            id = readInt("Enter product ID: ");
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