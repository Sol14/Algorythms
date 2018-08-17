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
  return 0;
}
