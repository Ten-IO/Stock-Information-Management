#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "StockList.h"
#include "DisplayManager.h"

/**
 * @brief tableList cleaner for live fuzzy search
 * @param row are amount of rows to move up and clean
 * @return to initial point above the starting point of table
 */
void clearSearchTable(const int &row);

/**
 * @brief minimal numeric finder
 * @param a first number, @param b second number
 * @retval smallest value
 */
int min(int a, int b);

/**
 * @brief List - Algorithm connector, allow using string and List database to look up for max amount of closeness text
 * @param input value to search @param ls Linked List to search @param numLook amount of return to find 
 * @retval List of finding value from LinkedList amount to numLook
 */
List *levenshtein_search(std::string input, List *ls, const int &numLook);

/**
 * @brief approximate search algorithm via editing cost: using compare substitution, replacement, deletion (BETA)
 * @param usrText target @param dbText source @param verbose show its matrix value
 * @retval cost distance between the two text
 */
int levenshtein_distance(std::string usrTxt, std::string dbTxt, bool verbose);

/**
 * @brief a `display` function construct to update with each key input
 * @param List LinkedList to search in @param maxLook size to search for
 */
void fuzzyShow(List *ls, const int &maxLook);

int min(int a, int b)
{
    return a < b ? a : b;
}

int levenshtein_distance(std::string usrTxt, std::string dbTxt, bool verbose)
{
    int m = usrTxt.length(), n = dbTxt.length(), cost = 0;
    int d[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
        d[i][0] = i;
    for (int i = 0; i <= n; i++)
        d[0][i] = i;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cost = usrTxt.at(i - 1) != dbTxt.at(j - 1) ? 1 : 0;
            d[i][j] = min(d[i - 1][j - 1] + cost, d[i][j - 1] + 1);
            d[i][j] = min(d[i][j], d[i - 1][j] + 1);
        }
    }
    if (verbose)
    {
        for (int x = 0; x < m; x++)
        {
            std::cout << '\n';
            for (int y = 0; y < n; y++)
                std::cout << d[x][y] << " ";
        }
        std::cout << '\n';
    }

    return d[m][n];
}

List *levenshtein_search(std::string input, List *ls, const int &numLook)
{
    if (!ls || ls->n == 0)
        return nullptr;

    List *collection = new List;

    Stock *curr = new Stock;
    curr = ls->head;
    Stock *topLook[numLook] = {};
    int score, topScore[numLook];

    for (int i=0;i<numLook;i++){
        topScore[i]=1000;
    }

    while (curr != nullptr)
    {
        score = levenshtein_distance(input, curr->item.name, 0);
        for (int i = 0; i < numLook; i++)
        {
            if (topScore[i] > score)
            {
                for (int j = numLook - 1; j > i; --j)
                {
                    topScore[j] = topScore[j - 1];
                    topLook[j] = topLook[j - 1];
                }

                topScore[i] = score;
                topLook[i] = curr;
                break;
            }
        }
        curr = curr->next;
    }
    for (int i = 0; i < numLook; i++)
    {
        collection->addItem(topLook[i]->item);
    }
    return collection;
}

void fuzzyShow(List *ls, const int &maxLook)
{
    std::string input{};
    bool isEnter = false;
    
    while (!isEnter)
    {
        List *suggest = levenshtein_search(input, ls, maxLook);
        if (suggest!=nullptr && suggest->n > 0)
        tableList(suggest);
        else
        std::cout << "No feedback! - Please use precise search instead [Enter] to leave\n";
        
        delete suggest;
        readChar("Search: ", input, isEnter);
        if(!isEnter)
        clearSearchTable(maxLook+7); // +8 because counting what we print: box(3)+table(4)+readChar(1) add-on line

    }
    std::cout << "\n[+] Search stopped..\n";
}

void clearSearchTable(const int &row){
    for (int i=0;i<row;i++){
        std::cout <<"\033[2K";
        std::cout <<"\033[A";
    }

}