#include <iostream>
using std::string, std::endl;

int foo(const string (&arr)[])
{
    return sizeof(*arr) / sizeof(string);
}
int main()
{
    string __name[] = {"sad", "happy", "amuse", "content"};

    std::cout << "__name: " << (&__name) << endl;
    std::cout << "__name: " << *(__name) << endl;
    std::cout << "char size: " << __name->size() << endl; // size of c.char in string
    std::cout << "actual size: " << sizeof(__name) / sizeof(std::string) << endl;

    std::cout << "\n\nCHECK IN FUNCTION\n";
    std::cout << foo(__name) << endl;
    std::cerr << "What if this is err";
    return 1;
}