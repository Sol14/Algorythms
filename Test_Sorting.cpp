#include "Sorting.h"
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

int main(int argc, char const *argv[]) {
  Sort a;

//Random Device
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(0,99999);

//Testcases
  int arr[10000];
  for(int i = 9999; i >= 0; i--){
    arr[i] = dist6(rng);
  }

//Beenchmark
  std::clock_t start;
   double duration;
   start = std::clock();

//Sort algorythms
  a.selection(arr, 10000); //Algorimto

//Prueba
  for(int i = 0; i < 10000; i++){
    cout << arr[i] << endl;
  }

  duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
   std::cout<<"Benchmark selection sort 10000 elements: "<< duration << " seconds"<< endl;
//end of Benchmark
  return 0;
}
