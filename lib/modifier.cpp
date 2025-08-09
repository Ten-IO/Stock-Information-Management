#include "modifier.h"

bool exportByID(List *ls, int &id, std::string &name, int &qtyOut, double &price)
{

    if (ls == nullptr || ls->head == nullptr)
    {
        std::cout << "\n[!] No stock available.\n";
        return false;
    }

    Stock *current = ls->head;
    Stock *prev = nullptr;

    while (current != nullptr && current->item.id != id)
    {
        prev = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        std::cout << "\n[!] Item with ID " << id << " not found.\n";
        return false;
    }

    int availableUnits = current->item.units;
    std::cout << "\n[=] Available units: " << availableUnits << "\n";
    inputBox(1);
    int exportQty = readInt("Quantity to export: ");

    if (exportQty <= 0)
    {
        std::cout << "\n[!] Invalid export quantity.\n";
        return false;
    }

    if (exportQty > availableUnits)
    {
        std::cout << "\n[!] Not enough stock to export " << exportQty << " units.\n";
        return false;
    }

    inputBox(1);
    price = readDouble("Export Price Per Unit: ");

    Item ExportItem = current->item;
    ExportItem.units = exportQty;

    current->item.units -= exportQty;

    if (current->item.units == 0)
    {
        if (prev == nullptr)
        {
            ls->head = current->next;
            if (current == ls->tail)
                ls->tail = nullptr;
        }
        else
        {
            prev->next = current->next;
            if (current == ls->tail)
                ls->tail = prev;
        }
        delete current;
        ls->n--;
    }

    name = ExportItem.name;
    qtyOut = exportQty;

    std::cout << "\n[-] Exported " << exportQty << " unit(s) of item [" << id << " - " << name << "].\n";
    return true;
}

bool exportByName(List *ls, int &id, std::string &name, int &qtyOut, double &price)
{

    if (ls == nullptr || ls->head == nullptr)
    {
        std::cout << "\n[!] No stock available.\n";
        return false;
    }

    Stock *current = ls->head;
    Stock *prev = nullptr;

    while (current != nullptr && current->item.name != name)
    {
        prev = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        std::cout << "\n[!] Item with name " << name << " not found.\n";
        return false;
    }

    int availableUnits = current->item.units;
    std::cout << "\n[=] Available units: " << availableUnits << "\n";
    inputBox(1);
    int exportQty = readInt("Quantity to export: ");

    if (exportQty <= 0)
    {
        std::cout << "\n[!] Invalid export quantity.\n";
        return false;
    }

    if (exportQty > availableUnits)
    {
        std::cout << "\n[!] Not enough stock to export " << exportQty << " units.\n";
        return false;
    }

    inputBox(1);
    price = readDouble("Export Price Per Unit: ");

    Item exportedItem = current->item;
    exportedItem.units = exportQty;

    current->item.units -= exportQty;

    if (current->item.units == 0)
    {
        if (prev == nullptr)
        {
            ls->head = current->next;
            if (current == ls->tail)
                ls->tail = nullptr;
        }
        else
        {
            prev->next = current->next;
            if (current == ls->tail)
                ls->tail = prev;
        }
        delete current;
        ls->n--;
    }

    id = exportedItem.id;
    qtyOut = exportQty;

    std::cout << "\n[-] Exported " << exportQty << " unit(s) of item [" << id << " - " << name << "].\n";
    return true;
}

void reportList(List *ls)
{
    if (ls == nullptr)
    {
        std::cerr << "\n[!] Empty Report..\n";
        return;
    }

    Stock *s = ls->head;
    std::string tmpType;
    double revenue{}, cost{}, profit{};
    while (s != nullptr)
    {
        tmpType.clear();
        for (char c : s->item.category)
        {
            if (c == ' ')
                break;
            else
                tmpType += c;
        }
        if (tmpType == "export")
            revenue += s->item.unitPrice * s->item.units;
        else if (tmpType == "import")
            cost += s->item.unitPrice * s->item.units;

        s = s->next;
    }
    s = ls->head;
    profit = revenue - cost;
    ColumnLength len = maxCoLen(ls);
    int lenRev = len.idL + len.nameL / 2 - 8, lenCost = len.nameL % 2 + len.nameL / 2 + len.catgL - 6, lenProf = len.priceL + len.unitL - 6;
    std::cout << "| Revenue: $" << std::setw(lenRev) << std::setprecision(2) << revenue << " | Cost: $" << std::setw(lenCost) << cost << " | Profit: $" << std::setw(lenProf) << profit << " |\n";
    std::cout << "|";
    // topCover(" ", '_', lenRev + 10);
    // std::cout << " |";
    // topCover(" ", '_', lenCost + 8);
    // std::cout << " |";
    // topCover(" ", '_', lenProf + 8);
    topCover(" ", '_', lenRev + lenCost + lenProf + 32);
    std::cout << " |";
}
