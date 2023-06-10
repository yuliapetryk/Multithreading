#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../Sort/BubbleSort.h"
#include "../Sort/MergeSort.h"
#include "../Sort/BitonicSort.h"
#include "../MultithreadingSort/MultBitonicSort.h"
#include "../MultithreadingSort/MultMergeSort.h"
#include "../MultithreadingSort/MultQuickSort.h"
#include "../Sort/InsertionSort.h"
#include"../Sort/QuickSort.h"
#include "../List/ArrayList.h"
#include <stdlib.h>


template <class T>
std::string to_list_string(T* a,
    T* b = nullptr,
    T* c = nullptr,
    T* d = nullptr,
    T* e = nullptr,
    T* f = nullptr) {
    std::stringstream ss;
    ss << '[' << *a;
    if (b != 0) ss << ", " << *b;
    if (c != 0) ss << ", " << *c;
    if (d != 0) ss << ", " << *d;
    if (e != 0) ss << ", " << *e;
    if (f != 0) ss << ", " << *f;
    ss << ']';
    return ss.str();
}




TEST_CASE("Tests for int") {
    int a = 1, b = 2, c = 3, d = 4;
    //create Array list
    List<int>* array_list;
    array_list = new ArrayList<int>;
    //Add function  works, so we can fill our lists
    array_list->add(c);
    array_list->add(b);
    array_list->add(a);
    array_list->add(d);

    //testing Bubble sort
    SUBCASE("Testing Bubble Sort") {
        Sort<int>* sort_bubble;
        sort_bubble = new BubbleSort<int>;
        array_list->sort(sort_bubble);
        for (int i = 0; i < 3; i++) {
            CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
        }   
    }


    array_list->clear();
    array_list->add(c);
    array_list->add(b);
    array_list->add(a);
    array_list->add(d);
    //testing Merge Sort
    SUBCASE("Testing Merge Sort") {
        Sort<int>* sort_merge;
        sort_merge = new MergeSort<int>;
        array_list->sort(sort_merge);
        for (int i = 0; i < 3; i++) {
            CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
        } 
    }


    array_list->clear();
    array_list->add(c);
    array_list->add(b);
    array_list->add(a);
    array_list->add(d);
    //testing Quick Sort
    SUBCASE("Testing Quick Sort") {
        Sort<int>* sort_quick;
        sort_quick = new QuickSort<int>;
        array_list->sort(sort_quick);
        for (int i = 0; i < 3; i++) {
            CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
    }

    array_list->clear();
    array_list->add(c);
    array_list->add(b);
    array_list->add(a);
    array_list->add(d);
    //testing Insertion Sort
    SUBCASE("Testing Insertion Sort") {
        Sort<int>* sort_insertion;
        sort_insertion = new InsertionSort<int>;
        array_list->sort(sort_insertion);
        for (int i = 0; i < 3; i++) {
            CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
    }
    array_list->clear();
    array_list->add(c);
    array_list->add(b);
    array_list->add(a);
    array_list->add(d);
    //testing Bitonic Sort
    SUBCASE("Testing  Bitonic Sort") {
        Sort<int>* sort_bitonic;
        sort_bitonic = new  BitonicSort<int>;
        array_list->sort(sort_bitonic);
        for (int i = 0; i < 3; i++) {
            CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
    }

   
}

TEST_CASE("Tests for string") {
    std::string a = "apple", b = "banana", c = "cocktail", d = "dish";
    //create Array list
    List<std::string>* array_list;
    array_list = new ArrayList<std::string>;

    //Add function  works, so we can fill our lists
    array_list->add(c);
    array_list->add(b);
    array_list->add(a);
    array_list->add(d);
    //testing Bubble sort
    SUBCASE("Testing Bubble Sort") {
        Sort<std::string>* sort_bubble;
        sort_bubble = new BubbleSort<std::string>;      
        array_list->sort(sort_bubble);       
        for (int i = 0; i < 3; i++) {
            CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
    }


    array_list->clear();
    array_list->add(c);
    array_list->add(b);
    array_list->add(a);
    array_list->add(d);
    //testing Merge Sort
    SUBCASE("Testing Merge Sort") {
        Sort<std::string>* sort_merge;
        sort_merge = new MergeSort<std::string>;        
        array_list->sort(sort_merge);        
        for (int i = 0; i < 3; i++) {
            CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
    }


    array_list->clear();
    array_list->add(c);
    array_list->add(b);
    array_list->add(a);
    array_list->add(d);
    //testing Quick Sort
    SUBCASE("Testing Quick Sort") {
        Sort<std::string>* sort_quick;
        sort_quick = new QuickSort<std::string>;       
        array_list->sort(sort_quick);       
        for (int i = 0; i < 3; i++) {
            CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
    }


    array_list->clear();
    array_list->add(c);
    array_list->add(b);
    array_list->add(a);
    array_list->add(d);
    //testing Insertion Sort
    SUBCASE("Testing Insertion Sort") {
        Sort<std::string>* sort_insertion;
        sort_insertion = new InsertionSort<std::string>;
        array_list->sort(sort_insertion);
        for (int i = 0; i < 3; i++) {
            CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
    }

    array_list->clear();
    array_list->add(c);
    array_list->add(b);
    array_list->add(a);
    array_list->add(d);
    //testing Bitonic Sort
    SUBCASE("Testing  Bitonic Sort") {
        Sort<std::string>* sort_bitonic;
        sort_bitonic = new  BitonicSort<std::string>;
        array_list->sort(sort_bitonic);
        for (int i = 0; i < 3; i++) {
            CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
    }

}



TEST_CASE("Tests Multithreading Algorithms for int") {
    int a = 1, b = 2, c = 3, d = 4;
    //create Array list
    List<int>* array_list;
    array_list = new ArrayList<int>;
    //Add function  works, so we can fill our lists
    array_list->add(c);
    array_list->add(b);
    array_list->add(a);
    array_list->add(d);


    //testing Multithreading Bitonic Sort
    SUBCASE("Testing  Multithreading  Bitonic Sort") {
        Sort<int>* sort_bitonic_mult;
        sort_bitonic_mult = new  MultBitonicSort<int>;
        array_list->sort(sort_bitonic_mult);
        for (int i = 0; i < 3; i++) {
            CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
    }

    array_list->clear();
    array_list->add(c);
    array_list->add(b);
    array_list->add(a);
    array_list->add(d);
    //testing Multithreading Merge Sort
    SUBCASE("Testing  Multithreading  Merge  Sort") {
        Sort<int>* sort_merge_mult;
        sort_merge_mult = new  MultMergeSort<int>;
        array_list->sort(sort_merge_mult);
        for (int i = 0; i < 3; i++) {
            CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
    }

    array_list->clear();
    array_list->add(c);
    array_list->add(b);
    array_list->add(a);
    array_list->add(d);
    //testing Multithreading Quick  Sort
    SUBCASE("Testing  Multithreading  Quick Sort") {
        Sort<int>* sort_quick_mult;
        sort_quick_mult = new  MultQuickSort<int>;
        array_list->sort(sort_quick_mult);
        for (int i = 0; i < 3; i++) {
            CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
    }
}

TEST_CASE("Tests Multithreading Algorithms for string") {
    std::string a = "apple", b = "banana", c = "cocktail", d = "dish";
    //create Array list
    List<std::string>* array_list;
    array_list = new ArrayList<std::string>;

    //Add function  works, so we can fill our lists
    array_list->add(c);
    array_list->add(b);
    array_list->add(a);
    array_list->add(d);


    //testing Multithreading Bitonic Sort
    SUBCASE("Testing  Multithreading  Bitonic Sort") {
        Sort<std::string>* sort_bitonic_mult;
        sort_bitonic_mult = new  MultBitonicSort<std::string>;
        array_list->sort(sort_bitonic_mult);
        for (int i = 0; i < 3; i++) {
            CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
    }

    array_list->clear();
    array_list->add(c);
    array_list->add(b);
    array_list->add(a);
    array_list->add(d);
    //testing Multithreading Merge Sort
    SUBCASE("Testing  Multithreading  Merge  Sort") {
        Sort<std::string>* sort_merge_mult;
        sort_merge_mult = new  MultMergeSort<std::string>;
        array_list->sort(sort_merge_mult);
        for (int i = 0; i < 3; i++) {
            CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
    }

    array_list->clear();
    array_list->add(c);
    array_list->add(b);
    array_list->add(a);
    array_list->add(d);
    //testing Multithreading Quick  Sort
    SUBCASE("Testing  Multithreading  Quick Sort") {
        Sort<std::string>* sort_quick_mult;
        sort_quick_mult = new  MultQuickSort<std::string>;
        array_list->sort(sort_quick_mult);
        for (int i = 0; i < 3; i++) {
            CHECK(array_list->to_string() == to_list_string(&a, &b, &c, &d));
        }
    }

}



