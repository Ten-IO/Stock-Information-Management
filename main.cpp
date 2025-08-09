#include <iostream>
#include <exception>
#include "label.h"
#include "User.h"
#include "StockList.h"
#include "modifier.h"
#include "Search.h"
#include "SortHelper.h"
#include "DisplayManager.h"
#include "FileManager.h"
#include "SystemLog.h"
#include "Benchmark.h"

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
User AUTH = User("master.csv");
FileLog PRODUCTLOG = FileLog("product.csv");

int main()
{
    while (!AUTH.isConfirm)
    {
        std::cout << "\n   ---------------------------------- Login -----------------------------------\n";
        std::cout << "      1. Create            : Register user\n";
        std::cout << "      2. Admin             : Access All feature\n";
        std::cout << "      3. User              : Cannot delete item that is in the program\n";
        std::cout << "      0. Exit the program  : Stop\n";
        std::cout << "   =============================================================================\n";
        inputBox(state);
        int choice = readInt(" ");

        switch (choice)
        {
        case 1:
            if (AUTH.loginAdmin())
            {
                AUTH.role = Role::USER;
                AUTH.regAcc();
            }
            break;
        case 2:
            AUTH.loginAdmin();
            break;
        case 3:
            AUTH.loginNormal();
            break;
        case 0:
            std::cout << "\n[+] Exit program ...\n";
            delete ls;
            return 0;
        default:
            break;
        }
    }
    Timer time;
    FileManager DATABASE = FileManager("item.csv");
    if (!DATABASE.CsvToList(ls))
        std::cerr << "\n[!] Starting with clean csv.\n";
    else
        std::cout << "\n[+] Populating list completed.\n";
    time.flickStop();

    while (AUTH.isConfirm)
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
            break;
        case 8:
            clearScreen();
            break;
        case 0:
            if (DATABASE.ListToCsv(ls))
                std::cout << "[+] Write success!";
            else
                std::cerr << "[!] Error happening";
            std::cout << "\n[+] Exit program ...\n";
            delete ls;
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
    item.unitPrice = readDouble("Unit price: ");
}

void __createCase()
{
    std::cout << "\n      == Add new product - Products information ==\n";
    Item item;
    acceptingInput(item);
    ls->addItem(item);
    PRODUCTLOG.writeLog(item.id, item.name, item.units, item.unitPrice, AUTH.usr, FileLog::LogLevel::IMPORT);
}

void __readCase()
{
    tableList(ls);
}

void __updateCase()
{
    std::cout << "\n   ----------------------------------- Menu -----------------------------------\n";
    std::cout << "      1. By ID             : product ID\n";
    std::cout << "      2. By Name           : product name\n";
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
            std::cout << "\n[!] Not found\n";
        break;
    }
    case 2:
    {
        std::cout << "\n      == Update product - Name ==\n";
        inputBox(state);
        std::string name = readStr("Product name to modify: ");

        if (ls->deleteByName(name))
        {
            std::cout << "\n[+] found\n";
            Item item;
            acceptingInput(item);
            ls->addItem(item);
            std::cout << "\n[=] Modified\n";
        }
        else
            std::cout << "\n[!] Not found\n";
        break;
    }
    default:
        break;
    }
}

void __deleteCase()
{
    if (AUTH.role == Role::ADMIN)
    {
        std::cout << "\n   ----------------------------------- Menu -----------------------------------\n";
        std::cout << "      1. By Position       : specific position in table\n";
        std::cout << "      2. By ID             : product ID\n";
        std::cout << "      3. By Name           : product Name\n";
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
            inputBox(state);
            pos = readInt("Enter product's position: ") - 1;

            if (!ls->deleteByPos(pos))
                std::cout << "\n[!] Not found - current index " << ls->n << "\n";
            else
                std::cout << "\n[-] Product deleted\n";
            break;
        }
        case 2:
        {
            std::cout << "\n      == Delete a products from Stock ==\n";
            inputBox(state);
            int id = readInt("Enter product's id: ");

            if (ls->deleteByID(id))
                std::cout << "\n[-] Deleted found\n";
            else
                std::cout << "\n[!] Position out of Bound\n";
            break;
        }
        case 3:
        {
            std::cout << "\n      == Delete a products from Stock ==\n";
            inputBox(state);
            std::string name = readStr("Enter product's name: ");

            if (ls->deleteByName(name))
                std::cout << "\n[-] Deleted found\n";
            else
                std::cout << "\n[!] Product name not found - try search first\n";
            break;
        }
        default:
            break;
        }
    }
    else
        std::cerr << "\n[!] Cannot access DELETE feature, YOU ARE NOT ADMIN!\n";
}

void __searchCase()
{
    std::cout << "\n   ----------------------------------- Menu -----------------------------------\n";
    std::cout << "      1. Match Search      : id range\n";
    std::cout << "      2.                   : Specific item name\n";
    std::cout << "      3.                   : item Category\n";
    std::cout << "      4.                   : Unit range\n";
    std::cout << "      5.                   : Price Range\n";
    std::cout << "      6. Fuzzy Search (EXP): proximate surf for product name\n";
    std::cout << "      0. Exit feature      : go back to main menu\n";
    std::cout << "   =============================================================================\n";
    inputBox(state);
    choice = readInt("Search Feature: ");
    switch (choice)
    {

    case 1:
    {
        int start, end;
        std::cout << "\n      == Search product id [Hint: same fill lead to specific item] ==\n";
        inputBox(state);
        start = readInt("From ID: ");
        inputBox(state);
        end = readInt("To ID: ");
        List *tmpList = ls->searchByIDRange(start, end);

        if (tmpList->head != nullptr)
            tableList(tmpList);
        else
            std::cout << "\n[-] Range not found\n";
        delete tmpList;
        break;
    }
    case 2:
    {
        std::string name;
        std::cout << "\n      == Search product name ==\n";
        inputBox(state);
        name = readStr("Enter name: ");
        List *tmpList = ls->searchByName(name);

        if (tmpList->head != nullptr)
            tableList(tmpList);
        else
            std::cout << "\n[-] Product Name not found - try fuzzy search\n";
        delete tmpList;
        break;
    }
    case 3:
    {
        std::string category;
        std::cout << "\n      == Search product Category ==\n";
        inputBox(state);
        category = readStr("Enter Category: ");
        List *tmpList = ls->searchByCategory(category);

        if (tmpList->head != nullptr)
            tableList(tmpList);
        else
            std::cout << "\n[-] Category not found\n";
        delete tmpList;
        break;
    }
    case 4:
    {
        int start, end;
        std::cout << "\n      == Search Range Units ==\n";
        inputBox(state);
        start = readInt("From Units: ");
        inputBox(state);
        end = readInt("Until Units: ");
        List *tmpList = ls->searchByUnitRange(start, end);

        if (tmpList->head != nullptr)
            tableList(tmpList);
        else
            std::cout << "\n[-] Range not found\n";
        delete tmpList;
        break;
    }
    case 5:
    {
        double start, end;
        std::cout << "\n      == Search Range Price ==\n";
        inputBox(state);
        start = readDouble("Min price: ");
        inputBox(state);
        end = readDouble("Max price: ");
        List *tmpList = ls->searchByUnitPriceRange(start, end);

        if (tmpList->head != nullptr)
            tableList(tmpList);
        else
            std::cout << "\n[-] Range not found\n";
        delete tmpList;
        break;
    }
    case 6:
    {
        std::cout << "\n      == Fuzzy Product Name (BETA)==\n";
        const int maxLookup = (ls->n < 10) ? ls->n : 10;
        if (ls->n > 0)
            fuzzyShow(ls, maxLookup);
        else
            std::cout << "\n[!] There is not sufficient information to check from Stock.\n";
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
    std::cout << "      2. By Name           : specific item name\n";
    std::cout << "      3. Quick Summary     : Check profit\n";
    std::cout << "      0. Exit feature      : go back to main menu\n";
    std::cout << "   =============================================================================\n";
    inputBox(state);
    choice = readInt("Export Feature: ");
    switch (choice)
    {
    case 1:
    {
        int id, units;
        double price;
        std::string name;
        std::cout << "\n      == Export a product ==\n";
        inputBox(state);
        id = readInt("Enter ID: ");
        if (exportByID(ls, id, name, units, price))
        {
            PRODUCTLOG.writeLog(id, name, units, price, AUTH.usr, FileLog::EXPORT);
            std::cout << "\n[+] Update userlog\n";
        }
        else
            std::cout << "\n[!] Please retry ..\n";
        break;
    }

    case 2:
    {
        int id, units;
        double price;
        std::string name;
        std::cout << "\n      == Export a product ==\n";
        inputBox(state);
        name = readStr("Product name: ");
        if (exportByName(ls, id, name, units, price))
        {
            PRODUCTLOG.writeLog(id, name, units, price, AUTH.usr, FileLog::EXPORT);
            std::cout << "\n[+] Update userlog\n";
        }
        else
            std::cout << "\n[!] Please retry ..\n";
        break;
    }

    case 3:
    {
        try
        {
            List *tmpList = new List();
            tmpList = PRODUCTLOG.readLog();
            if (tmpList->head != nullptr)
            {
                std::cout << "\nStarting read..\n";
                tableList(tmpList);
                reportList(tmpList);
                delete tmpList;
            }
            else
                std::cout << "\n[!] List is empty, cannot parse well.\n";
        }
        catch (const std::exception &e)
        {
            std::cerr << "\n[!] Exception: " << e.what() << '\n';
            std::cerr.flush();
        }
        break;
    }
    default:
        break;
    }
}

void __arrangeCase()
{
    std::cout << "\n   ----------------------------------- Menu -----------------------------------\n";
    std::cout << "      1. Ascend            : item id\n";
    std::cout << "      2. Descend           : item id\n";
    std::cout << "      3. Clean ID          : clean by reset id to its position\n";
    std::cout << "      0. Exit feature      : go back to main menu\n";
    std::cout << "   =============================================================================\n";
    inputBox(state);
    choice = readInt("Sort Feature: ");
    switch (choice)
    {
    case 1:
        mergeSortList(&ls, 0, ls->n - 1);
        std::cout << "\n[+] Ascending ID completed.\n";
        break;

    case 2:
        mergeSortList(&ls, 0, ls->n - 1);
        ls->reverse();
        std::cout << "\n[+] Descending ID completed.\n";
        break;

    case 3:
        ls->cleanID();
        std::cout << "\n[+] ID Arrangement completed.\n";
        break;

    default:
        break;
    }
}