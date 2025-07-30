#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "StockList.h"
#include "DisplayManager.h"

void clearSearchTable(const int &);
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
        clearSearchTable(maxLook+7); // +7 because counting what we print: box(3)+table(4)

    }
    std::cout << "\n[+] Search stopped..\n";
}

void clearSearchTable(const int &row){
    for (int i=0;i<row;i++){
        std::cout <<"\033[2K";
        std::cout <<"\033[A";
    }

}