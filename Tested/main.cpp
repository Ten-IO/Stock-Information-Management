#include <iostream>
#include "stock.h"
#include "userRole.h"
#include "filename.h"
#include "login.h"
using namespace std;

// declare as global variables
List* stocklist = nullptr;
Loglist* loglist = nullptr;

const std::string CURRENT_FILE = "Current.csv";
int main (){
    login();
    return 0;
}

