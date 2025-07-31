#pragma once

#include <iostream>
#include "StockList.h"
#include "DisplayManager.h"

bool exportByID(List *ls, int &id, std::string &nameOut, int &qtyOut)
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

    nameOut = exportedItem.name;
    qtyOut = exportQty;

    std::cout << "\n[-] Exported " << exportQty << " unit(s) of item ID " << id << ".\n";
    return true;
}

bool exportByName(List *ls, int &id, std::string &name, int &qtyOut)
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

    name = exportedItem.name;
    qtyOut = exportQty;

    std::cout << "\n[-] Exported " << exportQty << " unit(s) of item name " << name << ".\n";
    return true;
}
