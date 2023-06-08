#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <algorithm>
#include "Sort.h"

template<class T>
///Class implements sorting by Quick sort.
class QuickSort : public Sort<T> {
private:

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

        quickSort(array, 0, size - 1);
    }
};


#endif


