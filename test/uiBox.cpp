#include <displayManager.h>

int main() {

    inputBox(0);
    char input[10];
    std::cin.getline(input, 10);
    
    postAdjust();
    std::cout<< input;
    return 0; 
}