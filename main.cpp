#include <iostream>
#include <exception>
#include "StockList.h"
#include "FileManager.h"
#include "SystemLog.h"
#include "label.h"
#include "Benchmark.h"
#include "DisplayManager.h"
#include "Search.h"
#include "modifier.h"
#include "SortHelper.h"
#include "systemLog.h"

void acceptingInput(Item &);
void __createCase();
void __readCase();
void __updateCase();
void __deleteCase();
void __searchCase();
void __exportCase();
void __arrangeCase();

const bool state = 1;
List *ls = new List;
int choice;
std::string user = "Admin";
FileLog PRODUCTLOG = FileLog("product.csv");

int main()
{
    std::string DATABASE = "item.csv";

    Timer time;
    FileManager f = FileManager(DATABASE);
    if (!f.CsvToList(ls))
        std::cerr << "[!] Starting with clean csv.\n";
    else
        std::cout << "[+] Populating list completed.\n";
    time.flickStop();

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
        std::cout << "      6. Export            : log and record changes of item sales\n";
        std::cout << "      7. Arrange           : clean, sort\n";
        std::cout << "      8. Clear             : clean screen\n";
        std::cout << "      0. Exit the program  : saving log and document\n";
        std::cout << "   =============================================================================\n";
        inputBox(state);
        choice = readInt("  ");
        std::cout << '\n';
        switch (choice)
        {
        case 1:
            __createCase();
            break;
        case 2:
            __readCase();
            break;
        case 3:
            __updateCase();
            break;
        case 4:
            __deleteCase();
            break;
        case 5:
            __searchCase();
            break;
        case 6:
            __exportCase();
            break;
        case 7:
            __arrangeCase();
        case 8:
        clearScreen();
            break;
        case 0:
            if (f.ListToCsv(ls))
                std::cout << "[+] Write success!\n";
            else
                std::cerr << "[!] Error happening\n";
            std::cout << "Exit program\n";
            return 0;
            break;

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
    std::cout << "\n      == Add new product - Products information ==\n";
    Item item;
    acceptingInput(item);
    ls->addItem(item);
    PRODUCTLOG.writeLog(item.id, item.name, item.units, user, FileLog::IMPORT);
}

void __readCase()
{
    tableList(ls);
}

void __updateCase()
{
    std::cout << "\n   ----------------------------------- Menu -----------------------------------\n";
    std::cout << "      1. By ID             : product ID\n";
    std::cout << "      0. Exit feature      : go back to main menu\n";
    std::cout << "   =============================================================================\n";
    inputBox(state);
    choice = readInt("Update Feature: ");
    switch (choice)
    {
    case 1:
    {
        std::cout << "\n      == Update product - ProductID ==\n";
        inputBox(state);
        int id = readInt("Enter ID to modify: ");

        if (ls->deleteByID(id))
        {
            std::cout << "\n[+] found\n";
            Item item;
            acceptingInput(item);
            ls->addItem(item);
            std::cout << "\n[=] Modified\n";
        }
        else
            std::cout << "\nNot found\n";
        break;
    }
    default:
        break;
    }
}

void __deleteCase()
{
    std::cout << "\n   ----------------------------------- Menu -----------------------------------\n";
    std::cout << "      1. By position       : specific position in table\n";
    std::cout << "      2. By ID             : product ID\n";
    std::cout << "      0. Exit feature      : go back to main menu\n";
    std::cout << "   =============================================================================\n";
    inputBox(state);
    choice = readInt("Delete Feature: ");
    switch (choice)
    {
    case 1:
    {
        int pos;
        std::cout << "\n      == Delete a products from Stock ==\n";
        pos = readInt("Enter product's position: ") - 1;

        if (!ls->deleteByPos(pos))
            std::cout << "[!] Not found - current index " << ls->n << "\n";
        else
            std::cout << "[-] Product deleted\n";
        break;
    }
    case 2:
    {
        std::cout << "\n      == Delete a products from Stock ==\n";
        int id = readInt("Enter product's id: ");

        if (ls->deleteByID(id))
            std::cout << "[-] Deleted found\n";
        else
            std::cout << "[!] Not found\n";
        break;
    }
    default:
        break;
    }
}

void __searchCase()
{
    std::cout << "\n   ----------------------------------- Menu -----------------------------------\n";
    std::cout << "      1. Match Search      : specific item search\n";
    std::cout << "      2. Fuzzy Search (EXP): proximate surf for product name\n";
    std::cout << "      0. Exit feature      : go back to main menu\n";
    std::cout << "   =============================================================================\n";
    inputBox(state);
    choice = readInt("Search Feature: ");
    switch (choice)
    {

    case 1:
    {
        int id;
        std::cout << "\n      == Search product ID ==\n";
        id = readInt("Enter product ID: ");
        List *tmpList = ls->searchByID(id);

        if (tmpList->head != nullptr)
            tableList(tmpList);
        delete tmpList;
        break;
    }

    case 2:
    {
        std::cout << "\n      == Fuzzy Product Name (BETA)==";
        const int maxLookup = (ls->n < 10) ? ls->n : 10;
        fuzzyShow(ls, maxLookup);
        break;
    }

    default:
        break;
    }
}

void __exportCase()
{
    std::cout << "\n   ----------------------------------- Menu -----------------------------------\n";
    std::cout << "      1. By ID             : specific item id\n";
    std::cout << "      0. Exit feature      : go back to main menu\n";
    std::cout << "   =============================================================================\n";
    inputBox(state);
    choice = readInt("Export Feature: ");
    switch (choice)
    {
    case 1:
    {
        int id, units;
        std::string name;
        std::cout << "\n      == Export a product ==\n";
        inputBox(state);
        id = readInt("Enter ID: ");
        if (exportByID(ls, id, name, units))
        {
            PRODUCTLOG.writeLog(id, name, units, user, FileLog::EXPORT);
            std::cout << "[+] Update userlog\n";
        }
        else
            std::cout << "[!] Please retry ..\n";
    }

    default:
        break;
    }
}

void __arrangeCase()
{
    std::cout << "\n   ----------------------------------- Menu -----------------------------------\n";
    std::cout << "      1. Descend           : specific item id\n";
    std::cout << "      0. Exit feature      : go back to main menu\n";
    std::cout << "   =============================================================================\n";
    inputBox(state);
    choice = readInt("Sort Feature: ");
    switch (choice)
    {
    case 1:
        mergeSortList(&ls, 0, ls->n-1);
        break;

    default:
        break;
    }
}