// #include <iostream>
// #include "item.h"
// #include "stock.h"
// #include "modifier.h"
// #include "createFile.h"
// #include "search1.h"
// using namespace std;

// void interface_edit(List* ls){
//     while(true){
//         cout << "==================================" << endl;
//         cout << "            EDIT PRODUCT          " << endl;
//         cout << "==================================" << endl;

//         cout << "Enter the product ID you want to edit: ";
//         int idnumber;
//         cin >> idnumber;

//         //Exit condition
//         if (idnumber == 0){
//             system ("cls");
//             return;
//         }

//         // Stock* searchByID(List* ls, int& idn);
//         Stock* foundNode = searchByID(ls, idnumber);
//         if(foundNode == nullptr){
//             cout << "Product not found!" << endl;
//             continue; // Go back to start of loop
//         }

//         Item oldData = foundNode -> item; // copy the old data to a new one
//         Item newData;


//         while(true){
//         cout << "---------------Menu---------------" << endl;
//         cout << "| 1. Edit ID                     |" << endl;
//         cout << "| 2. Edit name                   |" << endl;
//         cout << "| 3. Edit category               |" << endl;
//         cout << "| 4. Edit unit                   |" << endl;
//         cout << "| 5. Edit unit price             |" << endl;
//         cout << "| 0. Exit                        |" << endl;
//         cout << "----------------------------------" << endl;
//         cout << "Enter your choice: ";

//         int choice;
//         if(!(cin >> choice)) {  // Handle non-integer input
//             cin.clear();
//             cin.ignore(numeric_limits<streamsize>::max(), '\n');
//             cout << "Invalid input. Please enter a number." << endl;
//             continue;
//         }

//         switch (choice){
//             case 1: {
//                 cout << "Current ID: "<< newData.id << endl;
//                 cout << "Enter new ID: ";
//                 if(!(cin >> newData.id)){
//                      // Handle invalid input
//                         cin.clear();
//                         cin.ignore(numeric_limits<streamsize>::max(), '\n');
//                         cout << "Invalid ID. Please try again." << endl;
//                         break;
//                     }
//                     break;
//                 }
//                 cin >> newData.id;
//                 modifyViaID(ls, oldData, newData); 
//                 createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, ls, false);
//                 //wrtieLog(user.username, item.id, item.name, "Update ID", item.units);
//                 break;
//             }
//             case 2: {
//                 cout << "Edit the product name: "<<endl;
//                 cout << "Enter product new name: ";
//                 cin >> newData.name;
//                 modifyViaID(ls, oldData, newData);
//                 createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, ls, false);
//                 //wrtieLog(user.username, item.id, item.name, "Update name", item.units);
//                 break;
//             }
//             case 3:{
//                 cout << "Edit the product category"<<endl;
//                 cout << "Enter product new category: ";
//                 cin >> newData.category;
//                 modifyViaID(ls, oldData, newData);
//                 createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, ls, false);
//                 //wrtieLog(user.username, item.id, item.name, "Update catagory", item.units);
//                 break;
//             }
//             case 4: {
//                 cout << "Edit the product unit"<<endl;
//                 cout << "Enter product new unit: ";
//                 cin >> newData.units;
//                 modifyViaID(ls, oldData, newData);
//                 createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, ls, false);
//                 // if (oldData.units < newData.units){
//                 //     //wrtieLog(user.username, item.id, item.name, "Import", item.units);
//                 // }else if (oldData.units > newData.units){
//                 //     //wrtieLog(user.username, item.id, item.name, "Export", item.units);
//                 // }
//                 break;
//             }
//             case 5: {
//                 cout << "Edit the product unit price"<<endl;
//                 cout << "Enter product new unit price: ";
//                 cin >> newData.unitPrice;
//                 modifyViaID(ls, oldData, newData);
//                 createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, ls, false);
//                 //wrtieLog(user.username, item.id, item.name, "Update unit price", item.units); 
//                 break;
//             }
//             case 0: {
//                 cout << "Exit program"<<endl;
//                 system("cls");
//                 return;
//             }
//             default: cout << "Invalid choice, Please try again."<<endl;
//                 system("cls");
//             }
//         }
//     }
// }