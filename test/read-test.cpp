#include <iostream>
#include <limits>
using std::cin, std::cout, std::string, std::endl;

string readStr(std::string prompt)
{
    string tmp;
    bool hasPunc=false;
    while (1)
    {
        hasPunc=false;
        std::cout << prompt;
        std::getline(cin, tmp);
        for (char c : tmp)
        {
            if (ispunct(c))
            {
                std::cout << "\033[A";
                std::cout << "\033[2K";
                hasPunc=true;
                break;
            }
        }
        if (!hasPunc)
            return tmp;
    }
}
int main()
{
    std::string prompt("Put in your stuff: ");
    cout << "== Phase 1 ==\n";
    cout << readStr(prompt) << endl;
    cout << "== Phase 2 ==\n";
    cout << readStr(prompt) << endl;
    cout << "== Phase 3 ==\n";
    cout << readStr(prompt) << endl;
}
