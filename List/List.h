#ifndef LIST_H
#define LIST_H

#include "sstream"
#include "Sort.h"


template<class T>
///Interface for working with dynamic arrays(lists).
class List {
public:
    /// Adds element to list.
   ///
   ///Adds an element and puts it in a certain position.
   /// 
   /// If an item is not added to the end of the list, the item that belonged to that index(and all after it) moves forward.
   /// @note If the index is not specified or less than zero - adds an item to the end of the list.
   /// @param   obj     The element which we want to add to list.
   /// @param   index   The index on which we want to place the element.
   /// @warning If index is bigger or equals to the size, than method must throw std::out_of_range.
    virtual void add(T obj, int index = -1) = 0;

    /// Gets element by index from list.
    /// @note If index is less than 0, removed last element from the list.
    /// @warning If index is bigger or equals to the size, than method must throw std::out_of_range exeption.
    /// @param   index   The index of the element in the list we want to get.
    /// @return  The element from list by index.
    virtual T& get(int index) = 0;

    /// Sorts the list by certain sort.
    /// @param   sort  The pointer on Sort object which have one method - 'sort'. It sort list by certain type.
    virtual void sort(Sort<T>* sort) = 0;

    /// Returns the size of list.
    /// @return  size of list.
    virtual int get_size() = 0;

    /// Removes all elements of the list.  
    virtual void clear() = 0;

    /// Writes the list as a string
    /// @return The string of this List.
    virtual std::string to_string() = 0;


    /// Override operator << of ostream.
    friend std::ostream& operator<<(std::ostream& stream, List<T>& list) {
        stream << list.to_string();
        return stream;
    };


    /// Equality operator.
    /// @param array The second array with which we compare
    /// @return True - if sizes and objects in lists are the same, False - othewise
    bool operator==(List& array) {
        if (get_size() != array.get_size()) return false;
        for (int i = 0; i < get_size(); i++) {
            if (get(i) != array.get(i)) return false;
        }
        return true;
    }

    /// Inequality operator.
     /// @param array The second array with which we compare
     /// @return True - if sizes or objects in lists are not the same, False - othewise
    bool operator!=(List& array) {
        return !(array == *this);
    }


    /// Operator 'less than'
    /// @param array The second array with which we compare
    /// @return True - If the size or element of our array is smaller than the size or corresponding element of this array, False - othewise
    bool operator<(List& array) {
        if (get_size() == array.get_size()) {
            for (int i = 0; i < get_size(); i++) {
                if (get(i) < array.get(i)) return true;
            }
            return false;
        }
        return get_size() < array.get_size();
    }

    /// Operator 'more then '
     /// @param array The second array with which we compare
     /// @return True - If the size or element of our array is bigger than the size or corresponding element of this array, False - othewise
    bool operator>(List& array) {
        return array < *this;
    }

    /// Operator 'less or equals'
    /// @param array The second array with which we compare
    /// @return True - If the size or element of our array is smaller or equals than the size or corresponding element of this array, False - othewise
    bool operator<=(List& array) {
        return !(array < *this);
    }

    /// Operator 'more or equals '
    /// @param array The second array with which we compare
    /// @return True - If the size or element of our array is bigger or equals than the size or corresponding element of this array, False - othewise
    bool operator>=(List& array) {
        return !(*this < array);
    }
};


#endif
