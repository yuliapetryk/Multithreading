
#ifndef ARRAYLIST_H
#define ARRAYLIST_H


#include "List.h"

template<class T>
///The class implements work with a array list
class ArrayList : public List<T> {
private:
    int size = 0;          ///< Value for saving count of elements in ArrayList.
    int array_size = 2;      ///< Value for saving size of array in ArrayList.
    T* array = new T[16];    ///< Array with elements.  

   /// A method to change the size of an array 
    /// @param new_size The new array will have size new_size
    void change_array_size(int new_size) {
        while (new_size <= size) new_size *= 2;

        T* temp = new T[new_size];
        for (int i = 0; i < array_size; i++) {
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;
        array_size = new_size;
    }


public:
    ///Destructor of ArrayList. 
    /// 
    ///Deletes the main dynamic array.
    ~ArrayList() {
        delete[] array;
    }

    /// Adds element to Array list.
    ///
    ///Adds an element and puts it in a certain position.
    /// 
    /// If an item is not added to the end of the list, the item that belonged to that index(and all after it) moves forward.
    /// @note If the index is not specified or less than zero - adds an item to the end of the list.
    /// @param   obj     The element which we want to add to list.
    /// @param   index   The index on which we want to place the element.
    /// @warning If index is bigger or equals to the size, than method must throw std::out_of_range.
    void add(T obj, int index = -1) override {
        if (index < 0)
            index = size;
        else if (index > size)
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size");

        if (size == array_size)
            change_array_size(array_size / 2 * 3 + 2);

        T temp1 = obj;
        T temp2;
        while (index <= size) {
            temp2 = array[index];
            array[index] = temp1;
            std::swap(temp1, temp2);
            index++;
        }
        size++;
    }
    /// Gets element by index from list.
   /// @note If index is less than 0, removed last element from the list.
   /// @warning If index is bigger or equals to the size, than method must throw std::out_of_range exeption.
   /// @param   index   The index of the element in the list we want to get.
   /// @return  The element from list by index.
    T& get(int index) override {
        if (index >= size || (index < 0 && size == 0))
            throw std::out_of_range("index " + std::to_string(index) + " is greater then the size-1");
        else if (index < 0)
            index = size - 1;

        return array[index];
    }

    /// Removes all elements of the list.  
    void clear() override {
        delete[] array;
        size = 0;
        array_size = 16;
        array = new T[array_size];
    }

    /// Sorts the list by certain sort.
    /// @param   sort  The pointer on Sort object which have one method - 'sort'. It sort list by certain type.
    void sort(Sort<T>* sort) override {
        sort->sort(array, size);

    }

    /// Returns the size of list.
    /// @return  size of list.
    int get_size() override {
        return size;
    }

    /// Writes the list as a string
    /// @retutn The string of this List.
    std::string to_string() override {
        std::stringstream ss;
        ss << '[';
        if (size != 0) {
            for (int i = 0; i < size - 1; i++) {
                ss << array[i] << ", ";
            }
            ss << array[size - 1];
        }
        ss << ']';

        return ss.str();
    }
};

#endif
