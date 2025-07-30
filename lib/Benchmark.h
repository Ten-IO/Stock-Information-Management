#pragma once
#include <chrono>
#include <iostream>

/**
 * @brief note/start timing for test case speed
 */
class Timer
{
public:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start, m_stop;
    bool status;
    Timer()
    {
        flickStart();
    }
    ~Timer()
    {
        flickStop();
    }
    void flickStart()
    {
        m_start = std::chrono::high_resolution_clock::now();
        status = true;
    }
    void flickStop()
    {
        if (status)
        {
            status = false;
            m_stop = std::chrono::high_resolution_clock::now();
            std::chrono::nanoseconds elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(m_stop - m_start);
            std::cout << "\nTimed: " << elapsed.count() / 1e6 << "ms <-> " << elapsed.count() << "ns\n";
        }
        else
        {
            std::cerr << "[!] Timer has not yet start";
        }
    }
};