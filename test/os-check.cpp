#include <iostream>
using namespace std;
int main() {
    #ifdef _WIN32
    cout << "window\n";
    #endif

    #ifdef _APPLE_
    cout << "apple\n";
    #endif
    #if _linux_
    cout << "linux\n";
    #else
    cout << "Unknown os\n";
    #endif
}
