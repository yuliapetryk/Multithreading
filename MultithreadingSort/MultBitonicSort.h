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


    void compAndSwap(T* array, int left, int right, int dir)
    {
        if (dir == (array[left] > array[right]))
            Sort<T>::swap(&array[left], &array[right]);

    }

    void bitonicMerge(T* array, int left, int middle, int dir)
    {
        if (middle > 1)
        {
            int mid = middle / 2;
            for (int i = left; i < left + mid; i++)
                compAndSwap(array, i, i + mid, dir);
            bitonicMerge(array, left, mid, dir);
            bitonicMerge(array, left + mid, mid, dir);
        }
    }

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

    void sort(T* array, int size) override {
        multBitonicSort(array, 0, size - 1, 1);
    }

};

#endif