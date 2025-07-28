#include <iostream>
#include <windows.h>
#include "stock.h"
#include "createFile.h"
#include "filename.h"
#include "userRole.h"
#include "interface_create.h"
#include "interface_read.h"
#include "interface_delete.h"
#include "interface_search.h"
#include "interface_edit1.h"
using namespace std;

// 
extern List *stocklist;
extern Loglist *loglist;

void setColor(int color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void menu(const User& currentUser) { 
    
    stocklist = initList();
    loglist = initLogList(); 
    // User currentUser = (); // Assuming this function retrieves the current user
    createCSV(CURRENT_FILE, CSV_HEADER, CSV_HEADER_SIZE, stocklist, false);  

    while(true){
        	std::cout << SetConsoleOutputCP(CP_UTF8);

    #ifdef _WIN32
    std::cout << R"( 
    ████████ █████████  ████████ ████████ ██   ███        ████████ ███     ██ ██████ ████████
    ███          █      ██    ██ ██       ██ ██              ██    ████    ██ ██     ██    ██
    ████████     █      ██    ██ ██       ███                ██    ██  █   ██ ████   ██    ██
         ███     █      ██    ██ ██       ██ ██      ███     ██    ██   █  ██ ██     ██    ██
    ████████     █      ████████ ████████ ██   ███  ██ ██ ████████ ██    ████ ██     ████████
	                                                                                         
             ████████  ███    ███ ████████ ████████   ████████ ██      ██                
             ███        ██    ██  ███         ██      ███      ████  ████                
             ████████    ██ ██    ████████    ██      ████████ ██  ██  ██                
                  ███     ██           ███    ██      ███      ██      ██                
             ████████     ██      ████████    ██      ████████ ██      ██   
    )";
    cout <<endl;
    #else
    cout << R"DELIM(
                 ____  _             _                                        
                / ___|| |_ ___   ___| | __                                    
                \___ \| __/ _ \ / __| |/ /                                    
                 ___) | || (_) | (__|   <                                     
                |____/_\__\___/ \___|_|\_\                                _   
                |  \/  | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_ 
                | |\/| |/ _` | '_ \ / _` |/ _` |/ _ \ '_ ` _ \ / _ \ '_ \| __|
                | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_ 
                |_|__|_|\__,_|_| |_|\__,_|\__, |\___|_| |_| |_|\___|_| |_|\__|
                / ___| _   _ ___| |_ ___ _|___/__                             
                \___ \| | | / __| __/ _ \_'_ ` _ "\"                           
                 ___) | |_| \__ \ ||  __/ | | | | |                           
                |____/ \__, |___/\__\___|_| |_| |_|                           
                       |___/                                                  
    )DELIM";
    #endif
        int choice;
        setColor(10);
        cout << "------------ Menu ------------"<<endl;
        cout << "| 1. Create                   |"<<endl;
        cout << "| 2. Read                     |"<<endl;
        cout << "| 3. Edit                     |"<<endl;
        cout << "| 4. Search                   |"<<endl;

        if (currentUser.role == ADMIN){
            cout << "| 5. Delete                   |"<<endl;
        }
        cout << "| 0. Exit the program         |"<<endl;
        cout << "==============================="<<endl;

        setColor(1);
        cout << "Enter your choice(0-5): ";
        while (!(cin >> choice) || choice < 0 || choice > (currentUser.role == ADMIN ? 5 : 4)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 0 and " 
                << (currentUser.role == ADMIN ? 5 : 4) << ": ";
        }
        setColor(12);
        cin >> choice;
        switch (choice){
            // Create
            case 1: {
                interface_create(stocklist);
                system("cls");
                break;
            }
            //Read
            case 2: {
                if(currentUser.role == ADMIN){
                    interface_read_admin();
                }else{
                    interface_read_user(stocklist);
                }
                system("cls");
                break;
            }
            // Edit
            case 3: {
                setColor(15);
                interface_edit(stocklist);
                system("cls");
                break;
            }
            // Search
            case 4: {
                if(currentUser.role == ADMIN){
                    setColor(15);
                    interface_read_admin();
                }else{
                    setColor(15);
                    interface_searchDataList(stocklist);
                }
            
                system("cls");
                break;
            }
            // Delete
            case 5: {
                if(currentUser.role != ADMIN) {
                    setColor(15);
                    interface_delete(stocklist, currentUser);
                    break;
                }else{
                    cout << "Access denied! Admin privileges required." << endl;
                }
                system("cls");
                break;
            }
   
            case 0: {
                cout << "Exit program";
                // Add cleanup code here
                delete stocklist;
                delete loglist; 
                return;
            }
            default:{ 
                cout << "Invalid choice, Please try again."<<endl;
                system("cls");
                break;
            }
        }
    }
}

