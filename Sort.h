/*
**  Started: 15/8/18
**  luiscarlosquesada@gmail.com
**  last edition: 16/8/18
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
  void insertionSort(T* array, int size){
    //Code
  }


  //Merge Sort
  template <typename T>
  void mergeSort(T* array, int size){
    //Code
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
