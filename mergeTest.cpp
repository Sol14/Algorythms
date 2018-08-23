#include "Sort.h"

using namespace Sort;

int main(int argc, char const *argv[]) {
  int array[] = {1, 2, 7, 5, 8, 2, 4, 9, 0};
  mergeSort<int>(array, 9);
  return 0;
}
