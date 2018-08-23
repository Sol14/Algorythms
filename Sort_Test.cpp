#include <fstream>
#include "Sort.h"
#include <ctime>
#include <iostream>
#include <random>

using namespace std;
using namespace Sort;

int main(int argc, char const *argv[]) {
  char* test;
  int algNumber;
  char* name = new char[250];
  int size;

  cout << "File name and extension" << endl;
  cin >> name;
  cout << "How many Test elements?" << endl;
  cin >> size;

  ofstream file (name);
  file << "Sort Test File" << endl;
  file << "Number of elements: " << size << endl;

  do{
  cout
  << "Test?: " << endl
  << "1)  BubbleSort"  << endl
  << "2)  SelectionSort" << endl
  << "3)  InsertionSort" << endl
  << "4)  MergeSort" << endl
  << "5)  HeapSort" << endl
  << "6)  RadixSort" << endl
  << "7)  QuickSort" << endl;
  cin >> algNumber;
} while (algNumber > 7 || algNumber < 1);

//Random Device
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(0,99999);

//Testcases
  cout << "Creating " << size << " random int values" << endl;
  int array[size];
  int passed[size];
  for(int i = 0; i < size; i++){
    array[i] = passed[i] =  dist6(rng);
  }

//Benchmark
  clock_t start;
  double duration;
  start = clock();
  //Case Selection
  switch (algNumber) {
    case 1:
      cout << "Sorting by BubbleSort" << endl;
      file << "Sorted by BubbleSort" << endl;
      bubbleSort <int> (array, size);
      break;
    case 2:
      cout << "Sorting by SelectionSort" << endl;
      file << "Sorted by SelectionSort" << endl;
      selectionSort <int> (array, size);
      break;
    case 3:
      cout << "Sorting by InsertionSort" << endl;
      file << "Sorted by InsertionSort" << endl;
      insertionSort <int> (array, size);
      break;
    case 4:
      cout << "Sorting by MergeSort" << endl;
      file << "Sorted by MergeSort" << endl;
      mergeSort <int> (array, size);
      break;
    case 5:
      cout << "Sorting by HeapSort" << endl;
      file << "Sorted by HeapSort" << endl;
      heapSort <int> (array, size);
      break;
    case 6:
      cout << "Sorting by RadixSort" << endl;
      file << "Sorted by RadixSort" << endl;
      radixSort <int> (array, size);
      break;
    case 7:
      cout << "Sorting by QuickSort" << endl;
      file << "Sorted by QuickSort" << endl;
      QuickSort <int> (array, size);
      break;
    default:
      cout << "End of test" << endl;
      break;
  }
  duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
  cout << "Test time: " << duration << " seconds" << endl;
  file << "Test time: " << duration << " seconds" << endl;
  //End of Benchmark

  //Test compare
  cout << "Testing correct answer" << endl;
  selectionSort(passed, size);
  bool allpass = true;
  for(int i = 0; i < size; i++){
    if(array[i] != passed[i]){
      allpass = false;
    }
  }

  if(allpass){
    cout << "Status: Passed" << endl;
    file << "Status: Passed" << endl;
  }
  else{
    cout << "Status: Failed" << endl;
    file << "Status: Failed" << endl;
  }


//Fill file of test elements
  cout << "Array: " << endl;
  file << "Array: " << endl;
  for(int i = 0; i < size; i++){
    if(i % 20 == 0 && i != 0){
      cout << array[i] << '\n';
      file << array[i] << '\n';
    }
    else{
      cout << array[i] << ',';
      file << array[i] << ',';
    }
  }
  return 0;
}
