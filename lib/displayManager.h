#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H
#include <stock.h>
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <locale>

void setCharCode();
void boxInterface();

void displayList(List *ls);
void displayPickList(List *ls, std::string headers[]);

void setCharCode()
{
    SetConsoleOutputCP(CP_UTF8);
}
void boxInterface(int state)
{
    if (state == 1)
    {
        // setCharCode();
        std::cout << "\n";
        std::cout << " ▏                            ▏\n";
        std::cout << "\n";
    }
    else
    {
        std::cout << "_______________________________\n";
        std::cout << "| >                           |\n";
        std::cout << "|_____________________________|\n";
    }
}

void moveCursor(int row, int col)
{
    std::cout << "\033[" << row << ";" << col << "H";
}
void displayList(List *ls)
{
    std::cout << "";
}
#endif