#ifndef BITONICSORT_H
#define BITONICSORT_H

#include <thread>
#include "Sort.h"

template<class T>
///Class implements sorting by Bitonic sort.
class BitonicSort : public Sort<T> 
{
private:
    
     ///The function recursively sorts a bitonic sequence in ascending order, if dir = 1, and in descending order otherwise
        /// @param array Array we want to sort
        /// @param left  The position of the leftmost element of the array
        /// @param number The number of elements to be sorted
        /// @param dir indicates the sorting direction, ASCENDING or DESCENDING;
    void bitonicMerge(T* array, int left, int number, int dir)
    {
        if (number > 1)
        {
            int mid = number / 2;
            for (int i = left; i < left + mid ; i++)
                Sort<T>::compAndSwap(array, i, i + mid, dir);
            bitonicMerge(array, left, mid, dir);
            bitonicMerge(array, left + mid, mid, dir);
        }
    }
    
    ///The function produces a bitonic sequence recursively
       /// @param array Array we want to sort
       /// @param left  The position of the leftmost element of the array
       /// @param number The number of elements to be sorted
       /// @param dir indicates the sorting direction, ASCENDING or DESCENDING;
    void bitonicSort(T* array, int left, int number, int dir)
    {
        if (number > 1)
        {
            int mid= number / 2;

            bitonicSort(array, left, mid, 1);
            bitonicSort(array, left + mid, mid, 0);
            bitonicMerge(array, left, number, dir);
        }
    }
public:
    /// A method for sorting arrays by Bitonic sort
      /// @param array is array we want to sort
      /// @param size is the size ot this array
    void sort(T* array, int size) override {
        bitonicSort(array, 0, size-1, 1);
    }

};

#endif