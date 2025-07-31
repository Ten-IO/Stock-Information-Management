#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "DisplayManager.h"
enum class Role
{
    ADMIN,
    USER
};

class User
{
public:
    std::string usr, passwd, __fileName;
    Role role;
    bool isConfirm = false;

    User(const std::string fileName)
    {
        __fileName = fileName;
        if (!fileExist(fileName))
        {
            std::ofstream writeFile(fileName, std::ios::app);
            std::cout << "\n[+] New Program - No file/user detected\n";
            writeFile.close();
            regAcc();
        }
    }

    std::string getName()
    {
        return usr;
    }

    std::string getRole()
    {
        return convertRole(role);
    }

    bool fileExist(const std::string &fileName)
    {
        std::ifstream readFile(fileName);
        if (!readFile.is_open())
        {
            readFile.close();
            return false;
        }
        readFile.close();
        return true;
    }

    std::string hashInput(const std::string &input)
    {
        unsigned long long hash = 0;
        const int prime = 31;

        for (size_t i = 0; i < input.length(); ++i)
            hash = hash * prime + static_cast<unsigned char>(input[i]);

        std::string hex = "";
        const char *hexChars = "0123456789ABCDEF";
        while (hash > 0)
        {
            hex = hexChars[hash % 16] + hex;
            hash /= 16;
        }

        return hex.empty() ? "0" : hex;
    }

    std::string convertRole(Role role)
    {
        switch (role)
        {
        case Role::ADMIN:
            return hashInput("admin");
        case Role::USER:
            return hashInput("user");
        default:
            return hashInput("unknown");
        }
    }

    bool check(const std::string &usr, const std::string &passwd, Role role)
    {
        std::string tmpUsr, tmpPasswd, tmpRole;
        std::ifstream file(__fileName);
        if (file.is_open())
            while (std::getline(file, tmpUsr, ',') && std::getline(file, tmpPasswd, ',') && std::getline(file, tmpRole, '\n'))
            {
                tmpRole=tmpRole; // clear \n and carriage \r
                if (hashInput(usr) == tmpUsr && hashInput(passwd) == tmpPasswd && convertRole(role) == tmpRole)
                    return true;
            }
        return false;
    }

    void regAcc()
    {
        std::cout << "\n      == Register Mode ==\n";
        inputBox(1);
        std::cout << "\033[6CUsername: ";
        std::cin >> usr;
        inputBox(1);
        std::cout << "\033[6CPassword: ";
        std::cin >> passwd;
        inputBox(1);
        std::string roleInput;
        std::cout << "\033[6CSelect role (admin/user): ";
        std::cin >> roleInput;
        if (roleInput == "admin")
            role = Role::ADMIN;
        else
            role = Role::USER;

        std::ofstream fileReg(__fileName, std::ios::app);
        fileReg << hashInput(usr) << ',' << hashInput(passwd) << ',' << convertRole(role) << "\n";
        fileReg.close();
    }

    bool loginAdmin()
    {
        std::cout << "\n      == Login as Admin user ==\n";
        role = Role::ADMIN;
        inputBox(1);
        std::cout << "\033[6CUsername: ";
        std::cin >> usr;
        inputBox(1);
        std::cout << "\033[6CPassword: ";
        char ch;
        while (true)
        {
            ch = _getch();
            if (ch == 13)
            { // ASCII 13 = Enter key
                break;
            }
            else if (ch == 8)
            { // ASCII 8 = Backspace
                if (!passwd.empty())
                {
                    passwd.pop_back();
                    std::cout << "\b \b";
                }
            }
            else
            {
                passwd.push_back(ch);
                std::cout << '*';
            }
        }
        isConfirm = check(usr, passwd, role);
        if (isConfirm)
        {
            std::cout << "\n[+] Login successful!\n";
            clearScreen();
            return true;
        }
        std::cout << "\n[!] Error! login unsuccessful, please check your information again.\n";
        return false;
    }
    bool loginNormal()
    {
        std::cout << "\n      == Login as Normal user ==\n";
        role = Role::USER;
        inputBox(1);
        std::cout << "\033[6CUsername: ";
        std::cin >> usr;
        inputBox(1);
        std::cout << "\033[6CPassword: ";
        char ch;
        while (true)
        {
            ch = _getch();
            if (ch == 13)
            { // ASCII 13 = Enter key
                break;
            }
            else if (ch == 8)
            { // ASCII 8 = Backspace
                if (!passwd.empty())
                {
                    passwd.pop_back();
                    std::cout << "\b \b";
                }
            }
            else
            {
                passwd.push_back(ch);
                std::cout << '*';
            }
        }
        isConfirm = check(usr, passwd, role);
        if (isConfirm)
        {
            std::cout << "\n[+] Login successful!\n";
            clearScreen();
            return true;
        }
        std::cout << "\n[!] Error! login unsuccessful, please check your password again.\n";
        return false;
    }
};