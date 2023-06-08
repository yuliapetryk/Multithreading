#ifndef SORTDECORATOR_H
#define SORTDECORATOR_H
#include "../Sort/Sort.h"
template<class T>
class SortDecorator : public Sort<T>
{
protected:
    Sort<T>* sortType;

public:
    SortDecorator(Sort<T>* sortType) : sortType(sortType) {}
    void sort(T* array, int size) override {
            sortType->sort(array, size);
    };

};

#endif // SORTDECORATOR_H
