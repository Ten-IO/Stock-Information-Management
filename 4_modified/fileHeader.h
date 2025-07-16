#ifndef CREATEFILEDATA_H
#define CREATEFILEDATA_H
#include <string>


const string CURRENT_FILE = "Current.csv";
//const string IMPORT_FILE = "Import.csv";
//const string EXPORT_FILE = "Export.csv";
const string LOG_FILE = "log.csv";



const std::string CSV_HEADER[] = {"ID", "Name", "Category", "Unit", "Unit price"};
const size_t CSV_HEADER_SIZE = sizeof(CSV_HEADER) / sizeof(CSV_HEADER[0]);

#endif 
