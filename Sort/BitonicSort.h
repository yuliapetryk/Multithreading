#ifndef BITONICSORT_H
#define BITONICSORT_H
#include <thread>
#include "Sort.h"

template<class T>
///Class implements sorting by  Bitonic sort.
class BitonicSort : public Sort<T> 
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
            for (int i = left; i < left + mid ; i++)
                compAndSwap(array, i, i + mid, dir);
            bitonicMerge(array, left, mid, dir);
            bitonicMerge(array, left + mid, mid, dir);
        }
    }
 
    void bitonicSort(T* array, int left, int middle, int dir)
    {
        if (middle > 1)
        {
            int mid= middle / 2;

            bitonicSort(array, left, mid, 1);
            bitonicSort(array, left + mid, mid, 0);
            bitonicMerge(array, left, middle, dir);
        }
    }
public:
   
    void sort(T* array, int size) override {
        bitonicSort(array, 0, size-1, 1);
    }

};

#endif