#include "Sorting.h"

void Sort::selection(int * array, int size){
  int pivot, min;
  for (int i = 0; i < size; i++){
    min = i;
    for(int j = i + 1; j < size; j++){
      if(array[min] >= array[j]){
        min = j;
      }
    }
    pivot = array[i];
    array[i] = array[min];
    array[min] = pivot;
  }
}
