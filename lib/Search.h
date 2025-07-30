#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "StockList.h"
#include "DisplayManager.h"
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
    Stock *topLook[3] = {};
    int score, topScore[3] = {999, 999, 999};

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

void searchShow(List *ls)
{
    std::string input{};
    char clck;
    bool isEnter = false;

    while (!isEnter)
    {
        system("cls");
        std::cout << "Search: " << input << '\n';

        List *suggest = levenshtein_search(input, ls, 3);
        if (suggest && suggest->n > 0)
        {
            Stock *curr = suggest->head;
            while (curr != nullptr)
            {
                std::cout << "+ " << curr->item.name << '\n';
                curr = curr->next;
            }
        }
        else
            std::cout << "No feedback!\n";

        clck = _getch();
        if (clck == 13)
            isEnter = true;
        else if (clck == 8)
        {
            if (!input.empty())
                input.pop_back();
        }
        else
            input += clck;

        delete suggest;
    }
    std::cout << "\nfinal input: " << input << "\n";
}