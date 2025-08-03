#pragma once
#include <chrono>
#include <iostream>

/**
 * @brief note/start timing for test case speed
 * @param status state of being record @param m_start time tick in high resolution state
 */
class Timer
{
public:
    // @brief constructor for Timer, initialize clock, set status active
    Timer();
    // @brief destructor to clean report clock before exit state
    ~Timer();
    // clock starter method
    void flickStart();
    // clock period report method
    void flickStop();

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start, m_stop;
    bool status;
};

Timer::Timer()
{
    flickStart();
}
Timer::~Timer()
{
    flickStop();
}
void Timer::flickStart()
{
    m_start = std::chrono::high_resolution_clock::now();
    status = true;
}
void Timer::flickStop()
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