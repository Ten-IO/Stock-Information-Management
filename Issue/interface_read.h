#include <iostream>
#include "reader.h"
#include "createFile.h"
#include "sorter.h"
#include "stock.h"
#include "userRole.h"
#include "interface_search.h"
using namespace std;

extern List *stocklist;
extern Loglist *loglist;

void interface_read_user(List* ls){
        while(true){
        cout << "==================================" << endl;
        cout << "          DISPLAY PRODUCT         " << endl;
        cout << "==================================" << endl;
        cout << "Current stock list"<<endl;
        displayFromFile(CURRENT_FILE);

        cout << "Do you want to sort the list?(y/n)";
        string ans;
        cin >> ans;

        if (ans == "yes" || ans == "Yes" || ans == "Y"|| ans == "y" ){
            Item* arr = ListToArr(ls, ls ->n);
            cout << "Sort product "<<endl;
            cout << "1. Sort by ID " << endl;
            cout << "2. Sort by name " << endl;
            cout << "3. Sort by unit " << endl;
            cout << "4. Sort by unit price " << endl;
            int answer;
            cin >> answer;
            SortField field;
            switch(answer){
                case 1:{
                    field = By_ID;
                    break;
                }
                case 2: {
                    field = By_Name;
                    break;
                }
                case 3: {
                    field = By_Unit;
                    break;
                }
                case 4: {
                    field = By_UnitPrice;
                    break;
                }
                default: {
                    cout << "Invalid choice. Please try again"<<endl;
                }  
            }
            mergeSortArr(arr, 0, ls -> n, field, ASCENDING);
            List* sortedList = ArrToList(arr, ls ->n);
            *stocklist = *sortedList;
            delete[] arr;
            displayFromFile(CURRENT_FILE);
            cout << endl;
            cout << "Do yo want to sort it descending?(y/n)";
            string a;
            cin >> a;
            if (a == "yes" || a == "Yes" || a == "Y" || a == "y"){
                mergeSortArr(arr, 0, ls -> n, field, DESCENDING);
                List* sortedList = ArrToList(arr, ls->n);
                *stocklist = *sortedList;
                delete[] arr;
                displayFromFile(CURRENT_FILE);
                break;
            }else{
                break;
            }
            cout << "Do you want to search any specific product?(y/n)";
            string ans;
            cin >> ans;
            if (ans == "yes" || ans == "Yes" || ans == "Y" || ans == "y"){
                interface_searchDataList(ls);
                break;
            }else{
                break;
            }
        }
    }
        //writeLog(user.username, NULL, NULL, "Read the list", NULL);
        cout << "Press enter to continue..."<<endl;
        cin.ignore();
        cin.get(); // Wait for user input
        system("cls");
        return; 
}
void interface_read_admin(){
    while(true){
        cout << "==================================" << endl;
        cout << "          DISPLAY PRODUCT         " << endl;
        cout << "==================================" << endl;
        cout << "---------------Menu---------------" <<endl;
        cout<<  "| 1. Display current stock list. |" <<endl;
        cout<<  "| 2. Display log activity list.  |" <<endl; 
        cout << "----------------------------------" <<endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice){
            case 1: {
                cout << "Current stock list"<<endl;
                displayFromFile(CURRENT_FILE);

                cout << "Do you want to sort the list?(y/n)";
                string ans;
                cin >> ans;

                if (ans == "yes" || ans == "Yes" || ans == "Y" || ans == "y" ){
                    Item* arr = ListToArr(stocklist, stocklist -> n);
                    cout << "Sort product "<<endl;
                    cout << "1. Sort by ID " << endl;
                    cout << "2. Sort by name " << endl;
                    cout << "3. Sort by unit " << endl;
                    cout << "4. Sort by unit price " << endl;
                    int answer;
                    cin >> answer;
                    SortField field;
                    switch(answer){
                        case 1:{
                            field = By_ID;
                            break;
                        }
                        case 2: {
                            field = By_Name;
                            break;
                        }
                        case 3: {
                            field = By_Unit;
                            break;
                        }
                        case 4: {
                            field = By_UnitPrice;
                            break;
                        }
                        default: {
                            cout << "Invalid choice. Please try again"<<endl;
                        }  
                    }
                    mergeSortArr(arr, 0, stocklist -> n, field, ASCENDING);
                    List* sortedList = ArrToList(arr, stocklist->n);
                    *stocklist = *sortedList;
                    delete[] arr;
                    displayFromFile(CURRENT_FILE);
                    cout << endl;
                    cout << "Do yo want to sort it descending?(y/n)";
                    string a;
                    cin >> a;
                    if (a == "yes" || a == "Yes" || a == "y" || a == "Y"){
                        mergeSortArr(arr, 0, stocklist -> n-1, field, DESCENDING);
                        List* sortedList = ArrToList(arr, stocklist->n);
                        *stocklist = *sortedList;
                        delete[] arr;
                        displayFromFile(CURRENT_FILE);
                        break;
                    }else{
                        break;
                    }
                    cout << "Do you want to search any specific product?(y/n)";
                    string ans;
                    cin >> ans;
                    if (ans == "yes" || ans == "Yes" || ans == "y" || ans == "Y"){
                        interface_searchDataList(stocklist);
                        break;
                    }else{
                        break;
                    }
                    break;
                }
                break;
            }
            case 2: {
                cout << "Log activity list"<<endl;
                displayFromFile(LOG_FILE);

                cout << "Do you want to sort the list?(y/n)";
                string ans;
                cin >> ans;

                if (ans == "yes" || ans == "Yes" || ans == "Y" || ans == "y" ){
                    LogItem* arr = LogListToArr(loglist, loglist->n);
                    cout << "Sort product "<<endl; 
                    cout << "1. Sort by username" << endl;
                    cout << "2. Sort by item_id " << endl;
                    cout << "3. Sort by timestamp"<< endl;
                    int answer;
                    cin >> answer;
                    LogField Logfield;
            
                    switch(answer){
                        case 1: {
                            Logfield = By_Username;
                            break;
                        }
                        case 2: {
                            Logfield = By_Date;
                            break;
                        }
                        default: {
                            cout << "Invalid choice. Please try again"<<endl;
                        }  
                    }
                    mergeSortArrLog(arr, 0, loglist -> n-1 , Logfield, ASCENDING);
                    Loglist* sortedList = LogArrToList(arr, loglist->n);
                    *loglist = *sortedList;
                    delete[] arr;
                    displayFromFile(LOG_FILE);
                    cout << endl;
                    cout << "Do yo want to sort it descending?(y/n)";
                    string a;
                    cin >> a;
                    if (a == "yes" || a == "Yes" || a == "Y" || a == "y"){
                        mergeSortArrLog(arr, 0, loglist -> n-1, Logfield, DESCENDING);
                        Loglist* sortedList = LogArrToList(arr, loglist->n);
                        *loglist = *sortedList;
                        delete[] arr;
                        displayFromFile(LOG_FILE);
                    }else{
                        break;
                    }
                    cout << "Do you want to search any specific product?(y/n)";
                    string ans;
                    cin >> ans;
                    if (ans == "yes" || ans == "Yes" || ans == "Y" || ans == "y"){
                        interface_searchLogList(loglist);
                    }else{
                        break;
                    }
                }
                break;
            }
            default: {
                cout << "Invalid choice. Please try again"<<endl;
            }
        writeLog(user.username, NULL, NULL, "Read the list", NULL);  
        cout << "Press enter to continue..."<<endl;
        cin.ignore();
        cin.get(); // Wait for user input
        }
        }
    }
}