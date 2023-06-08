#ifndef MULTQUICKSORT_H
#define MULTQUICKSORT_H
#include <thread>
#include <algorithm>
#include "../Sort/Sort.h"

template<class T>
///Class implements sorting by Multithreading Quick sort.
class MultQuickSort : public Sort<T> {
private:

    ///The function performs sorting in two different threads
    /// @param array Array we want to sort
    /// @param left  The position of the leftmost element of the array
    /// @param right The position of the rightmost element of the array
    void multQuickSort(T* array, int left, int right) {
        if (left < right) {
            if (right - left < 10000) {
                quickSort(array, left, right);
            }
            else {
                int pi = Sort<T>::partition(array, left, right);
                std::thread leftThread(&MultQuickSort<T>::multQuickSort, this, std::ref(array), left ,pi-1);
                std::thread rightThread(&MultQuickSort<T>::multQuickSort, this, std::ref(array), pi + 1, right);

                leftThread.join();
                rightThread.join();

                
            }
        }
    }

    ///The function performs partial sorting of the array low to high index
     ///@param array Array we want to sort
     ///@param low The starting element of the subarray
     ///@param high The final element of the subarray
    void quickSort(T* array, int const low, int const high)
    {
        if (low < high) {
            int pi = Sort<T>::partition(array, low, high);
            quickSort(array, low, pi - 1);
            quickSort(array, pi + 1, high);
        }
    }

public:
    /// A method for sorting arrays by Quick sort
     /// @param array is array we want to sort
     /// @param size is the size ot this array
     /// @warning The function will not work if the list is empty
    void sort(T* array, int size) override {

        multQuickSort(array, 0, size - 1);
    }
};


#endif

