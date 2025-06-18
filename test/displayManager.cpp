// // #include <windows.h>
// // #include <winioctl.h>
// // #include <iostream>

// // int main() {
// //     HANDLE hDevice = CreateFileW(
// //         L"\\\\.\\PhysicalDrive0",
// //         0,
// //         FILE_SHARE_READ | FILE_SHARE_WRITE,
// //         NULL,
// //         OPEN_EXISTING,
// //         0,
// //         NULL
// //     );

// //     if (hDevice == INVALID_HANDLE_VALUE) {
// //         std::cerr << "Error opening device: " << GetLastError() << std::endl;
// //         return 1;
// //     }

// //     DISK_GEOMETRY pdg = {};
// //     DWORD bytesReturned;

// //     BOOL result = DeviceIoControl(
// //         hDevice,
// //         IOCTL_DISK_GET_DRIVE_GEOMETRY,
// //         NULL,
// //         0,
// //         &pdg,
// //         sizeof(pdg),
// //         &bytesReturned,
// //         NULL
// //     );

// //     if (result) {
// //         std::cout << "Cylinders: " << pdg.Cylinders.QuadPart << "\n";
// //         std::cout << "Tracks per cylinder: " << pdg.TracksPerCylinder << "\n";
// //         std::cout << "Sectors per track: " << pdg.SectorsPerTrack << "\n";
// //         std::cout << "Bytes per sector: " << pdg.BytesPerSector << "\n";
// //     } else {
// //         std::cerr << "DeviceIoControl failed: " << GetLastError() << std::endl;
// //     }

// //     CloseHandle(hDevice);
// //     return 0;
// // }
// #include <windows.h>
// #include <iostream>

// int getConsoleWidth() {
//     CONSOLE_SCREEN_BUFFER_INFO csbi;
//     if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
//         int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
//         return width;
//     } else {
//         std::cerr << "Failed to get console width." << std::endl;
//         return -1;
//     }
// }

// int main() {
//     int width = getConsoleWidth();
//     if (width != -1) {
//         std::cout << "Console width: " << width << std::endl;
//     }
//     return 0;
// }

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
