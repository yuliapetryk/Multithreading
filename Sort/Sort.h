#ifndef SORT_H
#define SORT_H

template <class T>
/// Class implements Sort.
class Sort {
public:

    /// Virtual method for sort arrays
    /// @param array is array we want to sort
    /// @param size is the size ot this array
    virtual void sort(T* array, int size) = 0;
    
protected:

    ///The function checks whether the elements are consistent with the direction
       /// @param array Array we want to sort
       /// @param left  The first element 
       /// @param right The second element 
       /// @param dir indicates the sorting direction, ASCENDING or DESCENDING;
    void compAndSwap(T* array, int left, int right, int dir)
    {
        if (dir == (array[left] > array[right]))
            Sort<T>::swap(&array[left], &array[right]);

    }

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

    /// This function  compares two objects of type T. 
    /// @returns If the objects are equal, the function returns 0, and if the first object is greater than the second, it returns 1, otherwise -1.
    int compare(T& a, T& b) {
        if (a == b) return 0;
        else return a > b;
    }

};

#endif
