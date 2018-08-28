#include <iostream>

/*
Started: 15/8/18
**  luiscarlosquesada@gmail.com
**  last edition: 23/8/18
*/

#ifndef _Sort
#define _Sort

/*
**  Declaring a Sort namespace, containing multiple sort algorythms
**  Array usually has <= overriden, so it should work... kinda
**  its suppossed to be a static library at the end, so it wont need a class
**  or some weird sintax
*/
namespace Sort{

  //Bubble Sort
  template <typename T>
  void bubbleSort(T* array, int size){
    //Code
  }

  //Selection Sort
  template <typename T> //Define as DataType, not DataType*
  void selectionSort(T* array, int size){ //Array of T Data, and int Size
    T pivot, min;
    for (int i = 0; i < size; i++){ //Iterates trough the full array
      min = i;
      for(int j = i + 1; j < size; j++){ //Iterates trough the unsorted array
        if(array[min] >= array[j]){
          min = j; //Selects the min element in the unsorted array
        }
      }
      pivot = array[i];
      array[i] = array[min]; //Sorts the min element
      array[min] = pivot;
    }
  }


  //Insertion Sort
  template <typename T>
  void insertionSort(T* array,  int size){
    T key;  //Sets a Pivot or "key"
    for(int i = 1;  i < size; i++){ //Go trough the array
      key = array[i];
      int j = i - 1;  //Start point at the end of sorted array
      while(j >=  0 &&  array[j]  > key){ //Moves the sorted array to "insertion" point
        array[j + 1]  = array[j];
        j--;
      }
      array[j + 1]  =  key; //Insertion
    }
  }


  //Heap Sort
  template <typename T>
  void heapSort(T* array, int size){
    //Code
  }


  //Radix Sort
  template <typename T>
  void radixSort(T* array, int size){
    //Code
  }

  //Quick Sort
  template <typename T>
  void QuickSort(T* array, int size){
    //Code
  }
};

#endif // _Sort
