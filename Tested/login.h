#include <iostream>
#include <conio.h>
#include <windows.h> 
#include "menu.h"
#include "userRole.h"
#include "createFile.h"
// #include "displayManager.h"

using namespace std;
void login(){
    while(true){
        	std::cout << SetConsoleOutputCP(CP_UTF8);

    std::cout << R"(
                                                            
██     ██ ███████ ██       ██████  ██████  ███    ███ ███████     ████████  ██████      
██     ██ ██      ██      ██      ██    ██ ████  ████ ██             ██    ██    ██     
██  █  ██ █████   ██      ██      ██    ██ ██ ████ ██ █████          ██    ██    ██     
██ ███ ██ ██      ██      ██      ██    ██ ██  ██  ██ ██             ██    ██    ██     
 ███ ███  ███████ ███████  ██████  ██████  ██      ██ ███████        ██     ██████      
                                                                                                                                                                                                                                                                                       
███████ ████████  ██████   ██████ ██   ██     ███    ███  █████  ███    ██  █████   ██████  ███████ ███    ███ ███████ ███    ██ ████████     ███████ ██    ██ ███████ ████████ ███████ ███    ███ 
██         ██    ██    ██ ██      ██  ██      ████  ████ ██   ██ ████   ██ ██   ██ ██       ██      ████  ████ ██      ████   ██    ██        ██       ██  ██  ██         ██    ██      ████  ████ 
███████    ██    ██    ██ ██      █████       ██ ████ ██ ███████ ██ ██  ██ ███████ ██   ███ █████   ██ ████ ██ █████   ██ ██  ██    ██        ███████   ████   ███████    ██    █████   ██ ████ ██ 
     ██    ██    ██    ██ ██      ██  ██      ██  ██  ██ ██   ██ ██  ██ ██ ██   ██ ██    ██ ██      ██  ██  ██ ██      ██  ██ ██    ██             ██    ██         ██    ██    ██      ██  ██  ██ 
███████    ██     ██████   ██████ ██   ██     ██      ██ ██   ██ ██   ████ ██   ██  ██████  ███████ ██      ██ ███████ ██   ████    ██        ███████    ██    ███████    ██    ███████ ██      ██ 
                                                                                                                                                                                                                     
           
  ____    _                                 _                   _           
 |  _ \  | |   ___    __ _   ___    ___    | |   ___     __ _  (_)  _ __    
 | |_) | | |  / _ "\"  / _` | / __|  / _ "\"   | |  / _ "\"   / _` | | | | '_ "\";   
 |  __/  | | |  __/ | (_| | \__ \ |  __/   | | | (_) | | (_| | | | | | | |  
 |_|     |_|  \___|  \__,_| |___/  \___|   |_|  \___/   \__, | |_| |_| |_|  
                                                        |___/                                                                      
                                                                                                
    )"; 

    std::cout << "User type" << endl;
    std::cout << "1. Admin user" << endl;
    std::cout << "2. Normal user" << endl;
    std::cout << "Enter your choice: ";
    int choice;
    std::cin >> choice;
    string username, password;
    switch(choice){
        case 1: {
            while(true){
            std::cout << "Admin user" << endl;
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            char ch;
            while (true) {
                ch = _getch();
                if (ch == 13) { // ASCII 13 = Enter key 
                    break;
                } else if (ch == 8) { // ASCII 8 = Backspace
                    if (!password.empty()) {
                        password.pop_back();
                        cout << "\b \b";
                    }
                } else {
                    password.push_back(ch);
                    cout << '*';
                }
            }
            if (password == "12345678"){
                cout << "Login successful!"<<endl;
                User adminUser = {ADMIN, username,0, "Active", ""};
                // writeLog(username, NULL, NULL, "Login successful", NULL);
                // menu(adminUser);
                break;
            }else{
                cout << "Error! login unsuccessful, please check your password again."<<endl;
                // writeLog(username, NULL, NULL, "Login fail", NULL);
                break;
            }
            }
            system("cls");
            break;
        }
        case 2: {
            cout << "Normal user" << endl;
            cout << "Username: ";
            cin >> username;
            cout << "Login successful!"<<endl;            
            User normalUser = {USER, username, 0, "Active", ""};
            // writeLog(username, NULL, NULL, "Login successful", NULL);
            // menu(normalUser);
            system("cls");
            break;
        }
        default: cout << "Invalid choice, Please try again."<<endl;
        //writeLog(username, NULL, NULL, "Login fail", NULL);
        system("cls");
    }
    }                                                                                                           

}