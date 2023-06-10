#ifndef SORTDECORATOR_H
#define SORTDECORATOR_H
#include "../Sort/Sort.h"

template<class T>

/// The class implements the creation of auxiliary functionality
class SortDecorator : public Sort<T>
{
protected:
    Sort<T>* sortType;  ///< Value for saving the sort type.

public:

    ///The function returns the name of the sort type
    std::string sortName() {
        return "";
    }

    ///Constructor
    SortDecorator(Sort<T>* sortType) : sortType(sortType) {}

     /// The function calls the sort function in the sort type that is assigned to the variable sortType in the constructor
     /// @param array is array we want to sort
     /// @param size is the size ot this array
     void sort(T* array, int size) override {
         sortType->sort(array, size);
    };

};

#endif // SORTDECORATOR_H
