#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <locale>
#endif

using namespace std;
int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    cout << "Window";
#else
    locale::global(locale("en_US.UTF-8"));
    setlocale(LC_ALL, "en_US.UTF-8")
            cout
        << "Not window";
#endif
    cout << "";
}