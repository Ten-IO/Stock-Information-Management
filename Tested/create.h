#ifndef CREATE_H
#define CREATE_H

#include <iostream>
#include <fstream>
#include <vector>
#include "stock.h"
#include "createFile.h" 
#include "filename.h"

using namespace std;

void addEnd(List *ls, Item item) 
{
    Stock *s = new Stock;
    s->item = item;
    s->next = nullptr;

    if (ls->head == 0)
        ls->head = s;
    else
        ls->tail->next = s;
    ls->tail = s;
    ls->n++;
    
    writeToFile(item, CURRENT_FILE);
}

// void addEndLog(LoglIst *log, User user) 
// {
//     Log *log = new Log;
//     log->user = user;
//     log->next = nullptr;
//     if (log->head == 0)
//         log->head = log;
//     else
//         log->tail->next = log;
//     log->tail = log;
//     log->n++;
//     // writeToLogFile(user, LOG_FILE);
// }
#endif // CREATE_H
