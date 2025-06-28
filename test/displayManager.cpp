#include <windows.h>
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <cstdlib>

std::atomic<bool> stopFlag(false);

int getConsoleWidth()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        return csbi.srWindow.Right - csbi.srWindow.Left + 1;
    }
    return -1;
}

void trackConsoleWidthChanges()
{
    int lastWidth = getConsoleWidth();

    std::cout << "init console width: " << lastWidth << std::endl;

    while (!stopFlag.load())
    {
        int currentWidth = getConsoleWidth();
        if (currentWidth != lastWidth)
        {
            std::cout << "+ width changed: " << currentWidth << std::endl;
            lastWidth = currentWidth;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
    std::cout << "Stopped tracking console width changes.\n";
}

int main()
{
    std::thread tracker(trackConsoleWidthChanges);

    std::this_thread::sleep_for(std::chrono::seconds(5));
    stopFlag = true;

    tracker.join();
    std::cout << "Tracker thread finished.\n";
    system("powershell -Command \"$host.ui.rawui.windowsize\"");

    return 0;
}
