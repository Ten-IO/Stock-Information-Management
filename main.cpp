#include <iostream>
#include <exception>
#include "StockList.h"
#include "lib/FileManager.h"
#include "lib/SystemLog.h"
#include "lib/label.h"
#include "lib/benchmark.h"
#include "lib/displayManager.h"
void acceptingInput(Item &);

int main()
{
    std::string dbname = "item.db", header[] = {"id","name","category","unit","unit price"};
    int hdSz = sizeof(header)/sizeof(std::string) ;
    Timer time;
    List *stock = new List;
    Item item{};
    int choice;
    
    FileManager f = FileManager(dbname);
    if (!f.CsvToList(header, hdSz, stock))
        std::cerr << "[!] Starting with clean csv.\n";
    else
        std::cout << "[+] Populating list completed.\n";

            while (true)
        {
            std::cout << "";
            std::cout << smallStart();
            std::cout << "\n   ----------------------------------- Menu -----------------------------------\n";
            std::cout << "      1. Create            : add item\n";
            std::cout << "      2. Read              : table display\n";
            std::cout << "      3. Update            : use item id\n";
            std::cout << "      4. Delete            : use item position\n";
            std::cout << "      5. Search            : look for specific item type\n";
            std::cout << "      0. Exit the program  : saving log and document\n";
            std::cout << "   =============================================================================\n";
            inputBox(1);
            choice = readInt("  ");
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
            case 0:
            {
                if(f.ListToCsv(header, hdSz, stock))
                std::cout<< "[+] Write success!\n";
                else std::cerr<< "[!] Error happening\n";
                std::cout << "Exit program\n";
                return 0;
                break;
            }

            default:
                std::cout << "Input is not define, please check from the choice.\n";
                break;
            }
        }
}

void acceptingInput(Item &item)
{
    inputBox(1);
    item.id = readInt("ID: ");
    inputBox(1);
    item.name = readStr("Name: ");
    inputBox(1);
    item.category = readStr("Category: ");
    inputBox(1);
    item.units = readInt("Unit(s): ");
    inputBox(1);
    item.unitPrice = readFloat("Unit price: ");
}