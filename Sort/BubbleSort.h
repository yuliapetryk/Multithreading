#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include "Sort.h"

template<class T>
///Class implements sorting by Bubble sort.
class BubbleSort : public Sort<T> {

public:

    ///The function returns the name of the sort type
    std::string sortName() {
        return "Bubble Sort";
    }

    /// A method for sorting arrays by Bubble sort
     /// @param array is array we want to sort
     /// @param size is the size ot this array
     /// @warning The function will not work if the list is empty
    void sort(T* array, int size) {
            T temp;
            for (int i = 1; i < size; i++) {
                for (int j = 0; j < size - i; j++) {
                    if (Sort<T>::compare(array[j], array[j + 1]) == 1) {
                        temp = array[j + 1];
                        array[j + 1] = array[j];
                        array[j] = temp;
                    }
                }
            }
    }
};


#endif
