#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "DisplayManager.h"

// Role for user access
enum class Role
{
    ADMIN,
    USER
};

/**
 * @class user and access control
 * @brief managing user, register, login, verifying
 */
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
            std::cout << "\n\n[+] New Program - No file/user detected\n";
            writeFile.close();
            role = Role::ADMIN;
            regAcc();
        }
    }

    std::string getName()
    {
        return usr;
    }

    std::string getRole()
    {
        if (convertRole(role) == convertRole(Role::ADMIN))
            return "admin";
        else if (convertRole(role) == convertRole(Role::USER))
            return "user";
        else
            return "unknown";
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
                if (hashInput(usr) == tmpUsr && hashInput(passwd) == tmpPasswd && convertRole(role) == tmpRole)
                {
                    file.close();
                    return true;
                }

        file.close();
        return false;
    }

    void regAcc()
    {
        std::cout << "\n      == Register Mode ==\n";
        inputBox(1);
        std::cout << "\033[6CUsername: ";
        std::getline(std::cin, usr);
        inputBox(1);
        std::cout << "\033[6CPassword: ";
        std::getline(std::cin, passwd);

        /* Restricted one admin */
        // inputBox(1);
        // std::string roleInput;
        // std::cout << "\033[6CSelect role (admin/user): ";
        // std::cin >> roleInput;
        // if (roleInput == "admin")
        //     role = Role::ADMIN;
        // else
        //     role = Role::USER;

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
        std::getline(std::cin, usr);
        passwd = readPasswd("Password: ");

        isConfirm = check(usr, passwd, role);
        if (isConfirm)
        {
            std::cout << "\n[+] Login successful!\n";
            clearScreen();
            return true;
        }
        std::cout << "\n[!] Error! login unsuccessful, please check your information again, Sir/Madame Admin\n";
        return false;
    }
    bool loginNormal()
    {
        std::cout << "\n      == Login as Normal user ==\n";
        role = Role::USER;
        inputBox(1);
        std::cout << "\033[6CUsername: ";
        std::getline(std::cin, usr);
        passwd = readPasswd("Password: ");

        isConfirm = check(usr, passwd, role);
        if (isConfirm)
        {
            std::cout << "\n[+] Login successful!\n";
            clearScreen();
            return true;
        }
        std::cout << "\n[!] Error! login unsuccessful, USER credential is incorrect.\n";
        return false;
    }
};