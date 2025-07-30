#include <iostream>
#include "DisplayManager.h"

int main(){
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    DWORD mode = 0;

    std::cout << GetConsoleMode(hOut, &dwMode);
    SetConsoleMode(hOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
    std::cout << GetConsoleMode(hOut, &mode);
    std::cout << "\033[2B";
}