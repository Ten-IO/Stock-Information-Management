#ifndef CREATEFILE_H
#define CREATEFILE_H
#include <iostream>
#include <fstream>
#include "stock.h"

// 
/**
 * @brief Create comma seperated values with desired headers.
 * @param filename reference to file itself
 * @param headers params from structure
 * @param ls built structured information
 * @return void
 */
void createCSV(const std::string &filename, const std::string headers[], int headerSize, List *ls)
{
	ofstream file(filename);

	if (!file.is_open())
	{
		cerr << "Can't open file" << endl;
		return;
	}

	// header access
	for (int i = 0; i < headerSize; i++)
	{
		file << headers[i];
		if (i < headerSize - 1)
		{
			file << ",";
		}
	}
	file << "\n";

	// data division
	Stock *current = ls->head;
	while (current != nullptr)
	{
		file << current->item.id << ",";
		file << current->item.name << ",";
		file << current->item.category << ",";
		file << current->item.units << ",";
		file << current->item.unitPrice << "\n";
		current = current->next;
	}

	file.close();
	cout << "File : '" << filename << "' created successfully.\n";
}

#endif