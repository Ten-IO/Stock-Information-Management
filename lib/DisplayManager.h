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
 * @brief cin for double, evaluate type double
 * @param prompt prompt before input
 * @return double
 */
double readDouble(const std::string &);

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
 * @brief read password and mask it
 * @param prompt message before the input
 * @retval password 
 */
std::string readPasswd(const std::string &prompt);

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

/**
 * @struct 
 * @brief structure - container for Item table character length
 * @param idL @param nameL @param catgL @param unitL @param priceL
 */
struct ColumnLength
{
    int idL = 3, nameL = 10, catgL = 8, unitL = 5, priceL = 8;
};

/**
 * @brief method for looping target LinkedList to get max width table for each col
 * @param List linkedlist to scan for
 * @retval ColumnLength - structure of table length
 */
ColumnLength maxCoLen(List *ls);