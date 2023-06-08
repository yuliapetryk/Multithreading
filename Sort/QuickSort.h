#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <algorithm>
#include "Sort.h"

template<class T>
///Class implements sorting by Quick sort.
class QuickSort : public Sort<T> {
private:

    /// The function swaps elements
    void swap(T* a, T* b)
    {
        T t = *a;
        *a = *b;
        *b = t;
    }

    /// The Partition function returns an index with a supporting element dividing the array into two parts; the left - the elements of which are smaller than the supporting element, and the right - the elements of which are larger than the supporting element
    /// @param array Array we want to sort
    /// @param low The starting element of the subarray
    /// @param high The final element of the subarray
    /// @returns An index with a supporting element
    int partition(T* array, int low, int high)
    {
        T pivot = array[high];
        int i = (low - 1);

        for (T j = low; j <= high - 1; j++) {
            if (array[j] < pivot) {
                i++;
                swap(&array[i], &array[j]);
            }
        }
        swap(&array[i + 1], &array[high]);
        return (i + 1);
    }

    ///The function performs partial sorting of the array low to high index
     ///@param array Array we want to sort
     ///@param low The starting element of the subarray
     ///@param high The final element of the subarray
    void quickSort(T* array, int const low, int const high)
    {
        if (low < high) {
            int pi = partition(array, low, high);
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


