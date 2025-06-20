#ifndef HEADER_H
#define HEADER_H
#include <stock.h>

using namespace std;

List* create();
void menu();  // Declaration so other files know about it
void setColor(int color);
void deleteAtPos(List *ls, int pos);
void addEnd(List *ls, Item data);
void display(List *ls);

#endif
