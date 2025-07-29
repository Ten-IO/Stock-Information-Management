#include <iostream>
#include <exception>
#include "StockList.h"
#include "lib/FileManager.h"
#include "lib/SystemLog.h"
#include "lib/label.h"
#include "lib/benchmark.h"
#include "lib/DisplayManager.h"
void acceptingInput(Item &);
void __createCase();
void __readCase();
void __updateCase();
void __deleteCase();
void __searchCase();

int choice;
const int state = 1;
List *stock = new List;
Item item{};

int main()
{
    std::string dbname = "item.db", header[] = {"id", "name", "category", "unit", "unit price"};
    int hdSz = sizeof(header) / sizeof(std::string);
    // Timer time;

    FileManager f = FileManager(dbname);
    if (!f.CsvToList(header, hdSz, stock))
        std::cerr << "[!] Starting with clean csv.\n";
    else
        std::cout << "[+] Populating list completed.\n";

    while (true)
    {
        std::cout << "\n\n";
        std::cout << smallStart();
        std::cout << "\n   ----------------------------------- Menu -----------------------------------\n";
        std::cout << "      1. Create            : add item\n";
        std::cout << "      2. Read              : table display\n";
        std::cout << "      3. Update            : use item id\n";
        std::cout << "      4. Delete            : use item position\n";
        std::cout << "      5. Search            : look for specific item type\n";
        std::cout << "      0. Exit the program  : saving log and document\n";
        std::cout << "   =============================================================================\n";
        inputBox(state);
        choice = readInt("  ");
        std::cout << '\n';
        switch (choice)
        {
        case 1:
        {
            __createCase();
            break;
        }
        case 2:
            __readCase();
            break;
        case 3:
        {
            __updateCase();
            break;
        }
        case 4:
        {
            __deleteCase();
            break;
        }
        case 5:
        {
            __searchCase();
            break;
        }
        case 0:
        {
            if (f.ListToCsv(header, hdSz, stock))
                std::cout << "[+] Write success!\n";
            else
                std::cerr << "[!] Error happening\n";
            std::cout << "Exit program\n";
            return 0;
            break;
        }

        default:
            std::cout << "[!] Input is not define, please check from the choice.\n";
            break;
        }
    }
}

void acceptingInput(Item &item)
{
    inputBox(state);
    item.id = readInt("ID: ");
    inputBox(state);
    item.name = readStr("Name: ");
    inputBox(state);
    item.category = readStr("Category: ");
    inputBox(state);
    item.units = readInt("Unit(s): ");
    inputBox(state);
    item.unitPrice = readFloat("Unit price: ");
}

void __createCase()
{
    std::cout << "      == Add new product to stock - Products information ==\n";
    acceptingInput(item);
    stock->addItem(item);
}

void __readCase()
{
    tableList(stock);
}

void __updateCase()
{
    Item oldData, newData;
    std::cout << "      == Update the products - ProductID ==\n";
    inputBox(state);
    oldData.id = readInt("Enter ID to modify: ");

    acceptingInput(newData);
    int result = stock->modifyViaID(oldData.id, newData);
    if (result < -1)
        std::cout << "Not found\n";
    else
        std::cout << result << " updated\n";
}

void __deleteCase()
{
    int pos;
    std::cout << "      == Delete a products from the stock ==\n";
    pos = readInt("Enter product's position: ")-1;
    if (!stock->deleteAtPos(pos))
        std::cout << "[!] Not found - current index " << stock->n << "\n";
}

void __searchCase()
{
    int id;
    std::cout << "      == Search for the product ==\n";
    id = readInt("Enter product ID: ");
    stock->showItem();
}