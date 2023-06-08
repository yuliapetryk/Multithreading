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

    /// This function  compares two objects of type T. 
    /// @returns If the objects are equal, the function returns 0, and if the first object is greater than the second, it returns 1, otherwise -1.
    int compare(T& a, T& b) {
        if (a == b) return 0;
        else return a > b;
    }

};

#endif
