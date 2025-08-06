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