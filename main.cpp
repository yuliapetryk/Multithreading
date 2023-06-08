#include "Sort/BubbleSort.h"
#include "Sort/MergeSort.h"
#include "Sort/QuickSort.h"
#include "Sort/BitonicSort.h"
#include "Sort/InsertionSort.h"
#include "MultithreadingSort/MultQuickSort.h"
#include "MultithreadingSort/MultMergeSort.h"
#include "Decorator/TimeMeasure.h"
#include "List/ArrayList.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
void runSort(int type, int randomDigits[], int n) {
    
    using T = long long int;
    List<T>* list;
    list = new ArrayList<T>;


    // «аповненн€ масиву випадковими числами
    for (T i = 0; i < n; ++i) {
        list->add(randomDigits[i]);

    }
    Sort<T>* sort;
  
    switch (type) {
    case 1:
        sort = new BubbleSort<T>;
        std::cout << "Bubble Sort->";
        break;
    case 2:
        sort = new InsertionSort<T>;
        std::cout << "Insertion Sort->";
        break;
    case 3:
        sort = new QuickSort<T>;
        std::cout << "Quick Sort->";
        break;
    case 4:
        sort = new MultQuickSort<T>;
        std::cout << "Multithreading Quick Sort->";
        break;
    case 5:
        sort = new MergeSort<T>;
        std::cout << "Merge Sort->";
        break;
    case 6:
        sort = new BitonicSort<T>;
        std::cout << "Bitonic Sort->";
        break;
    default:
        sort = new MultMergeSort<T>;
        std::cout << "Multithreading Merge Sort->";
        break;
    }
    
    
    Sort<T>* timingSort = new TimeMeasure<T>(sort);
    list->sort(timingSort);
    list->clear();
 }


 int main(){
     
     long long int n = 250000;
     int randomDigits[250000]{};


     srand(time(NULL));
     for (int i = 0; i < n; i++)
     {
         randomDigits[i] = std::rand() % 101;

     }
     
     for (int i = 3; i <= 7; i++) {
         runSort(i, randomDigits, n);
     }
}



 
