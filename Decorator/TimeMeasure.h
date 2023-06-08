#ifndef TIMINGSORTDECORATOR_H
#define TIMINGSORTDECORATOR_H
#include <chrono>
#include <iostream>
#include "SortDecorator.h"
template<class T>
class TimeMeasure : public SortDecorator<T>
{
public:
    TimeMeasure(Sort<T>* sort) : SortDecorator<T>(sort) {}
    void sort(T* array, int size) override {
        
            auto startTime = std::chrono::steady_clock::now();
            SortDecorator<T>::sort(array, size);
            auto endTime = std::chrono::steady_clock::now();
            auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();
            std::cout << "Time:"<< elapsedTime <<"ms" << std::endl;
    };

};

#endif // TIMINGSORTDECORATOR_H