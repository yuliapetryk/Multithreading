#ifndef MERGESORT_H
#define MERGESORT_H


#include "../Sort/Sort.h"
template<class T>
///Class implements sorting by Merge sort.
class MergeSort : public Sort<T> {
private:

    ///Copies data to temp arrays
    /// @param Part The temp array
    /// @param array Array we want to sort
    /// @param size Size of main array
    /// @param position The position of the element in the main array from which we start copying   
    void split_array(T* Part, T* array, int size, int position) {
        for (int i = 0; i < size; i++)
            Part[i] = array[position + i];
    }


    /// Copies the remaining elements, if there are any
    /// @param Part The temp array
    /// @param array Array we want to sort
    /// @param size Size of main array
    /// @param index_array The position of the element in the main array  
    /// @param index_subarray The position of the element in the subarray
    void complete(int index_array, int size, T* Part, int index_subarray, T* array) {
        while (index_subarray < size) {
            array[index_array] = Part[index_subarray];
            index_subarray++;
            index_array++;
        }
    }

    ///An auxiliary function that combines parts of the array A from the l  to the m element and from the m+1th to the r element into one ordered subarray
    /// @param array Array we want to sort
    /// @param left  The position of the leftmost element of the array
    /// @param right The position of the rightmost element of the array
    /// @param mid The position of the middle element of the array
    void merge(T* array, int left, int mid, int right) {
        int  k;
        int left_size = mid - left + 1;
        int right_size = right - mid;
        T* LeftPart = new T[left_size];
        T* RightPart = new T[right_size];

        split_array(LeftPart, array, left_size, left);
        split_array(RightPart, array, right_size, mid + 1);

        int i = 0;
        int j = 0;
        k = left;

        while (i < left_size && j < right_size) {
            if (Sort<T>::compare(LeftPart[i], RightPart[j]) <= 0) {
                array[k] = LeftPart[i];
                i++;
            }
            else {
                array[k] = RightPart[j];
                j++;
            }
            k++;
        }

        complete(k, left_size, LeftPart, i, array);
        complete(k, right_size, RightPart, j, array);


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
            merge(array, left, mid, right);
        }
    }

public:
    /// A method for sorting arrays by Merge sort
      /// @param array is array we want to sort
      /// @param size is the size ot this array
      /// @warning The function will not work if the list is empty
    void sort(T* array, int size) override {
       
        mergeSort(array, 0, size - 1);
    }
};


#endif