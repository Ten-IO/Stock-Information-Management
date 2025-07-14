#ifndef CREATEFILE_H
#define CREATEFILE_H
#include <iostream>
#include <fstream>
#include "stock.h"

/**
 * @brief Create comma seperated values with desired headers.
 * @param filename reference to file itself
 * @param headers params from structure
 * @param ls built structured information
 * @return void
 */
void createCSV(const std::string &filename, const std::string headers[], int headerSize, List *ls)
{
	std::ofstream OutFile(filename, std::ios::app|std::ios::out);

	if (!OutFile.is_open())
	{
		std::cerr << "Can't open file\n";
		return;
	}

	// header access
	for (int i = 0; i < headerSize; i++)
	{
		OutFile << headers[i];
		if (i < headerSize - 1)
		{
			OutFile << ",";
		}
	}
	OutFile << "\n";

	// data division
	Stock *current = ls->head;
	while (current != nullptr)
	{
		OutFile << current->item.id << ",";
		OutFile << current->item.name << ",";
		OutFile << current->item.category << ",";
		OutFile << current->item.units << ",";
		OutFile << current->item.unitPrice << "\n";
		current = current->next;
	}

	OutFile.close();
}

#endif