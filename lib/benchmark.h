#ifndef BENCHMARK_H
#define BENCHMARK_H
#include <chrono>

class Timer
{
public:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_start, m_stop;
    Timer();
    ~Timer();
    void flickStart();
    void flickStop();
};
#endif