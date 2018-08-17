#include "Sort.h"
#include <ctime>
#include <iostream>
#include <random>

using namespace std;
using namespace Sort;

int main(int argc, char const *argv[]) {
//Random Device
  std::mt19937 rng;
  rng.seed(std::random_device()());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(0,99999);

//Testcases
  char arr[10];

  //Awkward
  arr[0] = 'a';
  arr[1] = 'Z';
  arr[2] = 'y';
  arr[3] = 'c';
  arr[4] = 'B';
  arr[5] = 'A';
  arr[6] = 'b';
  arr[7] = 'h';
  arr[8] = 'd';
  arr[9] = 'x';
  //Awkward

  selection<char>(arr, 10);

  for(int i = 0; i < 10; i++){
    cout << arr[i] << endl;
  }

  return 0;
}
