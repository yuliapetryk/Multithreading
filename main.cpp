#include "Sort/BubbleSort.h"
#include "Sort/MergeSort.h"
#include "Sort/QuickSort.h"
#include "Sort/BitonicSort.h"
#include "Sort/InsertionSort.h"
#include "MultithreadingSort/MultQuickSort.h"
#include "MultithreadingSort/MultMergeSort.h"
#include "MultithreadingSort/MultBitonicSort.h"
#include "Decorator/TimeMeasure.h"
#include "List/ArrayList.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Tests/doctest.h"

//namespace lab {
    //int doctest() {
   //    doctest::Context context;
   //    return context.run();
   // }


    void runSort(int type, int randomDigits[], int n) {

        using T = long long int;
        List<T>* list;
        list = new ArrayList<T>;

        for (T i = 0; i < n; ++i) {
            list->add(randomDigits[i]);

        }
        Sort<T>* sort;

        switch (type) {
        case 1:
            sort = new BubbleSort<T>;
            break;
        case 2:
            sort = new InsertionSort<T>;
            break;
        case 3:
            sort = new QuickSort<T>;
            break;
        case 4:
            sort = new MultQuickSort<T>;
            break;
        case 5:
            sort = new BitonicSort<T>;
            break;
        case 6:
            sort = new MultBitonicSort<T>;
            break;
        case 7:
            sort = new MergeSort<T>;
            break;
        default:
            sort = new MultMergeSort<T>;
            break;
        }


        Sort<T>* timingSort = new TimeMeasure<T>(sort);
        list->sort(timingSort);
        list->clear();
    }


    int main() {
       doctest();
        long long int n = 250000;
        int randomDigits[250000]{};


        srand(time(NULL));
        for (int i = 0; i < n; i++)
        {
            randomDigits[i] = std::rand() % 101;
        }

        for (int i = 3; i <= 8; i++) {
            runSort(i, randomDigits, n);
        }
        return 0;
    }
//}


 
