#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#include "Sort.h"

template<class T>
///Class implements sorting by Insertion sort.
class InsertionSort : public Sort<T> {
public:

    ///The function returns the name of the sort type
    std::string sortName() {
        return "Insertion Sort";
    }

    /// A method for sorting arrays by Insertion sort
     /// @param array is array we want to sort
     /// @param size is the size ot this array
     /// @warning The function will not work if the list is empty
    void sort(T* array, int size) override
    { 
        T key;
        int i, j;
        for (i = 1; i < size; i++)
        {
            key = array[i];
            j = i - 1;
            while (j >= 0 && array[j] > key)
            {
                array[j + 1] = array[j];
                j = j - 1;
            }
            array[j + 1] = key;
        }
    }

};

#endif


