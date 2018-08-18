#include "Sort.h"
#include <ctime>
#include <iostream>
#include <random>
#define size 100000 //Set size of Testcases
#define test "insertionSort" //Set test name

using namespace std;
using namespace Sort;

int main(int argc, char const *argv[]) {
//Random Device
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(0,99999);

//Testcases
  int array[size];
  int passed[size];
  for(int i = 0; i < size; i++){
    array[i] = passed[i] =  dist6(rng);
  }

  selectionSort <int> (passed, size);

//Test Begin
  cout << "Test Begin: " << test << endl << endl;

//Algorythms
  insertionSort <int> (array, size);

//Test
  bool allTests = true;
  for(int i = 0; i < size; i++){
      if(array[i] == passed[i]){
        cout << "Testcase: " << i << " Passed" << endl;
      }
      else{
        allTests = false;
        cout << "Testcase: " << i << " Failed" << endl;
      }
  }
  cout << endl << endl;
  if (!allTests) {
    cout << "Test Failed" << endl;
  }
  else{
    cout << "All test cases passed" << endl;
  }

//Test end
  cout << endl << endl << "End of test" << endl;

  return 0;
}
