#ifndef SEARCH_H
#define SEARCH_H
#include <string>
#include <iostream>
#include "StockList.h"

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

List levenshtein_search(std::string input, List *ls)
{
    Stock *s = new Stock;
    List *tmp = new List;
    s->next = ls->head;
    int score, prev[3];
    for (int i = 0; i < ls->n; i++)
    {
        score = levenshtein_distance(input, s->item.name, 0);
        for (int i : prev)
        {
            if (prev[i] > score)
            {
                prev[i] = score;
                if (tmp->head == 0)
                {
                    tmp->head = s;
                    tmp->n = ls->n;
                }
                else
                {
                    tmp->tail = s;
                    tmp->n = ls->n;
                }
            }
        }

        s=s->next;
    }
    delete s;
    return tmp;
}

#endif