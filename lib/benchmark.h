#include <iostream>
#include <chrono>

class Timer{
    public:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_startPoint;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_stopPoint;
    Timer(){
        m_startPoint= std::chrono::high_resolution_clock::now();
    }
    ~Timer(){
        stop();
    }
    void stop(){
        m_stopPoint=std::chrono::high_resolution_clock::now();
        std::chrono::nanoseconds elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(m_stopPoint-m_startPoint);
        std::cout<< "\nTimed: "<<elapsed.count()/1e6<<" ms ... "<< elapsed.count() << " ns\n";
    }
};