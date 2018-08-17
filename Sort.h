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

//Selection Sort
  template <typename T> //Define as DataType, not DataType*
  void selection(T * array, int size){ //Array of T Data, and int Size
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


};


#endif // _Sort
