#ifndef MULTMERGESORT_H
#define MULTMERGESORT_H

#include "../Sort/Sort.h"
#include <thread>
#include <iostream>
template<class T>
///Class implements sorting by Multithreading Merge sort.
class MultMergeSort : public Sort<T> {
private:

    ///The function performs sorting in two different threads
    /// @param array Array we want to sort
    /// @param left  The position of the leftmost element of the array
    /// @param right The position of the rightmost element of the array
    void multMergeSort(T* array, int left, int right) {
        if (left < right) {
            if (right - left < 10000) {
                mergeSort(array, left, right);
            }
            else {
                int middle = left + (right - left) / 2;
                std::thread leftThread(&MultMergeSort<T>::multMergeSort, this, std::ref(array), left, middle);
                std::thread rightThread(&MultMergeSort<T>::multMergeSort, this, std::ref(array), middle + 1, right);

                leftThread.join();
                rightThread.join();

                Sort<T>::merge(array, left, middle, right);
            }
        }
    }

    ///The function performs a partial sort, ordering its elements from left to right
    /// @param array Array we want to sort
    /// @param left  The position of the leftmost element of the array
    /// @param right The position of the rightmost element of the array
    void mergeSort(T* array, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2;
            mergeSort(array, left, mid);
            mergeSort(array, mid + 1, right);
            Sort<T>::merge(array, left, mid, right);
        }
    }

public:
    /// A method for sorting arrays by Merge sort
      /// @param array is array we want to sort
      /// @param size is the size ot this array
      /// @warning The function will not work if the list is empty
    void sort(T* array, int size) override {
        
        multMergeSort(array, 0, size - 1);
    }
};


#endif