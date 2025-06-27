#include <windows.h>
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

std::atomic<bool> stopFlag(false);

int getConsoleWidth() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    return -1;
}

void trackConsoleWidthChanges() {
    int lastWidth = getConsoleWidth();

    std::cout << "Initial console width: " << lastWidth << std::endl;

    while (!stopFlag.load()) {
        int currentWidth = getConsoleWidth();
        if (currentWidth != lastWidth) {
            std::cout << "Console width changed: " << currentWidth << std::endl;
            lastWidth = currentWidth;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));  // poll every 200ms
    }
    std::cout << "Stopped tracking console width changes.\n";
}

int main() {
    std::thread tracker(trackConsoleWidthChanges);

    std::this_thread::sleep_for(std::chrono::seconds(20));
    stopFlag = true;

    tracker.join();
    std::cout << "Tracker thread finished.\n";

    return 0;
}
