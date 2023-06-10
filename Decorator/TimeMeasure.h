#ifndef TIMINGSORTDECORATOR_H
#define TIMINGSORTDECORATOR_H
#include <chrono>
#include <iostream>
#include "SortDecorator.h"
#include <fstream>

template<class T>

/// The class implements the measurement of the running time of the algorithm
class TimeMeasure : public SortDecorator<T>
{
public:

    ///The function returns the name of the sort type
    std::string sortName() {
        return "";
    }

    ///Constructor
    TimeMeasure(Sort<T>* sortType) : SortDecorator<T>(sortType) {};

  
     /// The function calls the sort function, measures the time it took to sort, and writes the result to a file
     /// @param array is array we want to sort
     /// @param size is the size ot this array
    void sort(T* array, int size) override {
        auto startTime = std::chrono::steady_clock::now();
        SortDecorator<T>::sort(array, size);
        auto endTime = std::chrono::steady_clock::now();
        auto elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count();

        std::ofstream outputFile("result.txt", std::ios::app);
        if (outputFile.is_open()) {
            outputFile << SortDecorator<T>::sortType->sortName();
            outputFile << " time: " << elapsedTime << "ms" << std::endl;
            outputFile << std::endl;
            outputFile.close();
        }
        else {
            std::cout << "Failed to open the output file!" << std::endl;
        }
    }

};

#endif // TIMINGSORTDECORATOR_H