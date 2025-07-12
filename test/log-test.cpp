#include <systemLogger.h>
#include <iostream>

#define FILE "potato.log"
int main()
{
    try
    {
        int num;
            std::cout << "+ Numeric input: ";
            std::cin >> num;
            std::cout << "Result: " << num << " " << typeid(num).name() << std::endl;
            throw num;
    }
    catch (std::exception &e)
    {
        std::cerr << "Error: occured, see " << FILE;
        logHere(FILE, ERROR, e.what());
    }
    catch (...)
    {
        std::string prompt="Exception caught: Not knowing what is happening";
        std::cerr << prompt;
        logHere(FILE, ERROR, prompt);
    }
}