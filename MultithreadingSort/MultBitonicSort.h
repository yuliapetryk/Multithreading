#ifndef MULTBITONICSORT_H
#define MULTBITONICSORT_H

#include <thread>
#include "../Sort/Sort.h"
#include <iostream>

template<class T>
///Class implements sorting by  Bitonic sort.
class MultBitonicSort : public Sort<T>
{
private:

    ///The function recursively sorts a bitonic sequence in ascending order, if dir = 1, and in descending order otherwise
       /// @param array Array we want to sort
       /// @param left  The position of the leftmost element of the array
       /// @param number The number of elements to be sorted
       /// @param dir indicates the sorting direction, ASCENDING or DESCENDING;
    void bitonicMerge(T* array, int left, int middle, int dir)
    {
        if (middle > 1)
        {
            int mid = middle / 2;
            for (int i = left; i < left + mid; i++)
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
    void bitonicSort(T* array, int left, int middle, int dir)
    {
        if (middle > 1)
        {
            int mid = middle / 2;

            bitonicSort(array, left, mid, 1);
            bitonicSort(array, left + mid, mid, 0);
            bitonicMerge(array, left, middle, dir);
        }
    }
   
    ///The function produces a bitonic sequence recursively in different threads
      /// @param array Array we want to sort
      /// @param left  The position of the leftmost element of the array
      /// @param number The number of elements to be sorted
      /// @param dir indicates the sorting direction, ASCENDING or DESCENDING;
    void multBitonicSort(T* array, int left, int middle, int dir)
    {
        if (middle > 1)
        {
            if (middle - left  < 10000) {
               
                bitonicSort(array, left,  middle,  dir);
            }
            else {
                int mid = middle / 2;
                std::thread leftThread(&MultBitonicSort<T>::multBitonicSort, this, array, left, mid, 1);
                std::thread rightThread(&MultBitonicSort<T>::multBitonicSort, this, array, left + mid, mid, 0);
     
                leftThread.join();
                rightThread.join();
               
                bitonicMerge(array, left, middle, dir);
            }
        }
    }
public:
    /// A method for sorting arrays by Bitonic sort
      /// @param array is array we want to sort
      /// @param size is the size ot this array
    void sort(T* array, int size) override {
        multBitonicSort(array, 0, size - 1, 1);
    }

};

#endif