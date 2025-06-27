#include <displayManager.h>

int main() {
    boxInterface(0);
    char input[10];
    moveCursor(5,5);
    std::cin.getline(input, 10);
    std::cout<< input;
    return 0; 
}