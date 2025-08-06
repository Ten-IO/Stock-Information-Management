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