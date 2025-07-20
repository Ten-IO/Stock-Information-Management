#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H
#include "StockList.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <iomanip>
#include <locale>

/**
 * @brief change terminal charcode to UTF-8 - standard 4 bytes
 * @return void
 */
void setCharCode();

/**
 * @brief Create a cool space for input
 * @return void
 */
void inputBox(int);

/**
 * @brief dynamic table that utilized list structure
 * @param ls point to address of List input
 * @return void
 */
void tableList(List *);
void displayList(List *ls);
void displayPickList(List *ls, std::string headers[]);

void setFRGB(int r,int g, int b){
    printf("\033[38;2;%d;%d;%dm",r,g,b);
}
void setBRGB(int r,int g, int b){
    printf("\033[48;2;%d;%d;%dm",r,g,b);
}
void resetTerm(){
    std::cout << "\033[0m";
    // std::cout << "\033[39m";
    // std::cout << "\033[49m";
}
void setCharCode()
{
    SetConsoleOutputCP(CP_UTF8);
    std::setlocale(LC_ALL, ".UTF8");
}
void inputBox(int state)
{
    if (state == 1)
    {
        // setCharCode();
        std::cout << "\n";
        std::cout << " ▏                            ▏\n";
        std::cout << "\n";
        std::cout << "\033[2A";
    }
    else
    {
        std::cout << "_______________________________\n";
        std::cout << "| >                           |\n";
        std::cout << "|_____________________________|\n";
    }
    std::cout << "\033[2A\033[4C";
}

void postAdjust()
{
    std::cout << "\033[2B";
}
void max(int &a, int b)
{
    if (a < b)
        a = b;
}

// Covering table list
void topCover(std::string sc, char mc, int count)
{
    std::cout << sc;
    for (int i = 0; i < count; i++)
        std::cout << mc;
}

// Completing table list
void botCover(char c, int idL, int nameL, int catgL, int unitL, int priceL)
{
    topCover("| ", c, idL);
    topCover(" | ", c, nameL);
    topCover(" | ", c, catgL);
    topCover(" | ", c, unitL);
    topCover(" | ", c, priceL);
    std::cout << " |\n";
}

void tableList(List *ls)
{
    int idL = 3, nameL = 10, catgL = 8, unitL = 5, priceL = 8;
    Stock *s = ls->head;
    while (s != nullptr)
    {
        max(idL, static_cast<int>(std::to_string(s->item.id).length()));
        max(nameL, static_cast<int>(s->item.name.length()));
        max(catgL, static_cast<int>(s->item.category.length()));
        max(unitL, static_cast<int>(std::to_string(s->item.units).length()));
        max(priceL, static_cast<int>(std::to_string(s->item.unitPrice).length()));

        s = s->next;
    }
    s = ls->head;

    topCover(" ", '_', idL + nameL + catgL + unitL + priceL + 14);
    std::cout << std::endl;
    std::cout << "| " << std::setw(idL) << "ID"
              << " | " << std::setw(nameL) << "Name"
              << " | " << std::setw(catgL) << "Category"
              << " | " << std::setw(unitL) << "Units"
              << " | " << std::setw(priceL) << "Price" << " |\n";
    botCover('_', idL, nameL, catgL, unitL, priceL);

    while (s != nullptr)
    {
        std::cout << "| " << std::setw(idL) << s->item.id
                  << " | " << std::setw(nameL) << s->item.name
                  << " | " << std::setw(catgL) << s->item.category
                  << " | " << std::setw(unitL) << s->item.units
                  << " | " << std::setw(priceL) << s->item.unitPrice << " |\n";
        s = s->next;
    }
    botCover('_', idL, nameL, catgL, unitL, priceL);
}

int getConsoleWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csBuff;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csBuff))
        return csBuff.srWindow.Right - csBuff.srWindow.Left + 1;
    return -1;
}
#endif