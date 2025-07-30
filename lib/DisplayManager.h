#pragma once
#include "StockList.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <locale>
#include <limits>

/**
 * @brief set console virtual sequence processing for Command Prompt (CMD) Windows
 * @return void
 */
void setCharCode();

/**
 * @brief change terminal charcode to UTF-8 - standard 4 bytes
 * @return void
 */
void setEnableAnsi();

// save cursor position
void preCursor();
// restore cursor position
void postCursor();
/**
 * @brief Create a cool space for input
 * @param state `1` if unicode working, `2` if char display chaos
 * @return void
 */
void inputBox(const int &);

// check highest value, go with address of a
void max(int &a, int b);
/**
 * @brief dynamic table that utilized list structure & data length
 * @param ls address of heap List
 * @return void
 */
void tableList(List *);
// display input item
void showItem(Item item);
void displayPickList(List *ls, std::string headers[]);
/**
 * @brief cin for integer, evaluate type int
 * @param prompt prompt before input
 * @return integer
 */
int readInt(const std::string &);

/**
 * @brief cin for float, evaluate type float
 * @param prompt prompt before input
 * @return float
 */
float readFloat(const std::string &);

/**
 * @brief cin for string, evaluate for alphabets and numbers
 * @param prompt prompt
 * @return string
 */
std::string readStr(const std::string &);

/**
 * @brief get key click reader, update input agrument to realtime update (design for search and keylog function)
 * @param prompt prompt
 * @param input string address that will track and update
 * @param state for tracking __isEnter__ boolean key
 * @return void
 */
void readChar(const std::string &, std::string &, bool &);

/**
 * @brief start here text/foreground color change
 * @param r red @param g green @param b blue
 * @return void
 */
void setFRGB(int r, int g, int b);

/**
 * @brief start here background color change
 * @param r red @param g green @param b blue
 * @return void
 */
void setBRGB(int r, int g, int b);

// quick reset text&background color & other attributes
void resetTerm();

// clean terminal
void clearScreen();
/**
 * @brief get terminal with by check HANDLER from window.h
 * @retval width
 */
int getConsoleWidth();

// Closing table list
void botCover(char c, int idL, int nameL, int catgL, int unitL, int priceL);
// Covering table list
void topCover(std::string sc, char mc, int count);

// cover input ui
void topBox(int state);
// enclose input ui
void midBox(int state);
// close input ui
void botBox(int state);

void setEnableAnsi()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(console, &mode);
    SetConsoleMode(console, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}
void setCharCode()
{
    SetConsoleOutputCP(CP_UTF8);
    std::setlocale(LC_ALL, ".UTF8");
}

void preCursor()
{
    std::cout << "\033[s";
}
void postCursor()
{
    std::cout << "\033[u";
}

int readInt(const std::string &prompt)
{
    int tmp;
    std::cout << "\033[2C";
    while (1)
    {
        std::cout << prompt;
        std::cin >> tmp;
        if (!std::cin.fail())
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return tmp;
        }
        else
            std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\033[A";
        std::cout << "\033[2K";
        preCursor();
        midBox(1);
        postCursor();
        std::cout << "\033[D\033[8C";
    }
}
float readFloat(const std::string &prompt)
{
    float tmp;
    std::cout << "\033[2C";
    while (1)
    {
        std::cout << prompt;
        std::cin >> tmp;
        if (!std::cin.fail())
        {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return tmp;
        }
        else
            std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\033[A";
        std::cout << "\033[2K";
        preCursor();
        midBox(1);
        postCursor();
        std::cout << "\033[D\033[8C";
    }
}
std::string readStr(const std::string &prompt)
{
    std::string tmp;
    bool hasPunc = false;
    std::cout << "\033[2C";
    while (1)
    {
        hasPunc = false;
        std::cout << prompt;
        std::getline(std::cin, tmp);
        for (char c : tmp)
        {
            if (ispunct(c))
            {
                hasPunc = true;
                break;
            }
        }

        if (!hasPunc)
            return tmp;

        std::cout << "\033[A";
        std::cout << "\033[2K";
        preCursor();
        midBox(1);
        postCursor();
        std::cout << "\033[D\033[8C";
    }
}
void readChar(const std::string &prompt, std::string &input, bool &isEnter)
{
    char clck;
    inputBox(1);
    std::cout << "\033[2C";

    std::cout << prompt << input;
    clck = _getch();
    std::cout <<'\n';
    if (clck == 13)
        isEnter = true;
    else if (clck == 8)
    {
        if (!input.empty())
            input.pop_back();
    }
    else if(isprint(clck))
        input += clck;
}
void setFRGB(int r, int g, int b)
{
    printf("\033[38;2;%d;%d;%dm", r, g, b);
}
void setBRGB(int r, int g, int b)
{
    printf("\033[48;2;%d;%d;%dm", r, g, b);
}
void resetTerm()
{
    std::cout << "\033[0m";
    // std::cout << "\033[39m";
    // std::cout << "\033[49m";
}

void topBox(int state)
{
    if (state == 1)
        std::cout << "  ╭----------------------------------------------------------------------------╮\n";
    else
        std::cout << "   ________________________________________________________\n";
}
void midBox(int state)
{
    if (state == 1)
        std::cout << "  |  →                                                                         |\n";
    else
        std::cout << "  | >                                                      |\n";
}
void botBox(int state)
{
    if (state == 1)
        std::cout << "  ╰----------------------------------------------------------------------------╯\n";
    else
        std::cout << "  |________________________________________________________|\n";
}

void inputBox(const int &state)
{
    if (state == 1)
    {
        std::cout << "  ╭----------------------------------------------------------------------------╮\n";
        std::cout << "  |  →                                                                         |\n";
        std::cout << "  ╰----------------------------------------------------------------------------╯\n";
    }
    else
    {
        std::cout << "   ________________________________________________________\n";
        std::cout << "  | >                                                      |\n";
        std::cout << "  |________________________________________________________|\n";
    }
    std::cout << "\033[2A\033[6C";
}

void max(int &a, int b)
{
    if (a < b)
        a = b;
}
void topCover(std::string sc, char mc, int count)
{
    std::cout << sc;
    for (int i = 0; i < count; i++)
        std::cout << mc;
}
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

    std::cout << std::endl;
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
                  << " | $" << std::setw(priceL - 1) << s->item.unitPrice << " |\n";
        s = s->next;
    }
    botCover('_', idL, nameL, catgL, unitL, priceL);
    delete s;
}

int getConsoleWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csBuff;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csBuff))
        return csBuff.srWindow.Right - csBuff.srWindow.Left + 1;
    return -1;
}

void clearScreen(){
    system("cls");
}

void showItem(Item item)
    {
            std::cout << "   ID: " << item.id << " - " << item.name << '\n'
                      << "Category: " << item.category << '\n'
                      << "unit: " << item.units << '\n'
                      << "Price/unit: " << item.unitPrice << '\n';
    }