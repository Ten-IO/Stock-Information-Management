#ifndef BENCHMARK_H
#define BENCHMARK_H
#include <chrono>
#include <iostream>
class Timer
{
public:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start, m_stop;
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
    }
    void flickStop()
    {
        m_stop = std::chrono::high_resolution_clock::now();
        std::chrono::nanoseconds elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(m_stop - m_start);
        std::cout << "\nTimed: " << elapsed.count() / 1e6 << "ms <-> " << elapsed.count() << "ns\n";
    }
};
#endif