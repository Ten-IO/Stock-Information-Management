#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include "DisplayManager.h"

/** @enum
 * Integral Role for user access
 */
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

    /**
     * @brief constructor for User file creator
     * @return if User File not found, create new file and registering administration user
     */
    User(const std::string fileName);

    /**
     * @brief get username
     * @retval name of user
     */
    std::string getName();

    /**
     * @brief translate role in text
     * @retval role as text
     */
    std::string getRole();

    /**
     * @brief check file existence
     * @retval `true` exist @retval @retval `false` not exist
     */
    bool fileExist(const std::string &fileName);

    /**
     * @brief hash digest to return hex
     * @retval hashtext
     */
    std::string hashInput(const std::string &input);

    /**
     * @brief convert role to text
     * @param enum
     */
    std::string convertRole(Role role);

    /**
     * @brief user verifier - hash compare
     * @param usr account name used for login @param passwd account password used for login @param role account role during login
     * @retval `true` username, password, role correct @retval `false` username, password, role incorrect
     */
    bool check(const std::string &usr, const std::string &passwd, Role role);

    /**
     * @brief registering mode for putting user into system known list
     * @return account store in defined fileName for User
     */
    void regAcc();

    /**
     * @brief login for administrator/master account
     * @retval `true` login success @retval `false` login failed
     */
    bool loginAdmin();

    /**
     * @brief login checker for normal user
     * @retval `true` login success @retval `false` login failed
     */
    bool loginNormal();
};
