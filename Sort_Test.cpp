#include <fstream>
#include "Sort.h"
#include <ctime>
#include <iostream>
#include <random>

using namespace std;
using namespace Sort;

int * getRandom(int i)
{
	//Random Device Generation
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0,99999);
	int * array; //Array
	array = new int[i];
	for(int j = 0; j < i; j++)
	{
			array[j] = dist6(rng); //Random Array of i length
	}
	return array;
}

bool isCorrect(int * array, int length)
{
	//read array length
	for (int i = 1; i < length; i++)
	{
		if(array[i - 1] > array[i])
		{
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	ofstream nfile(argv[1]);
	std::clock_t start;
	 double duration;

	 for(int k = 0; k < 3; k++)
	 {
		 switch (i) {
			 case 0:
				 nfile << "Testing Insertion Sort: " << endl;
				 break;
			 case 1:
				 nfile << "Testing Selection Sort: " << endl;
				 break;
			 case 2:
				 nfile << "Testing Merge Sort: " << endl;
				 break;

		 for(int i = 0; i < 4; i ++)
		 {
				int size;
				switch (i) {
					case 0:
						size = 50000;
						break;
					case 1:
						size = 100000;
						break;
					case 2:
						size = 200000;
						break;
					case 3:
						size = 400000;
						break;
				}
				for(int j = 0; j < 5; j++){
					int * array = getRandom(size);
					nfile << "Test " << j << " on " << size << " elements" << endl;

					start = std::clock();
					switch (i) {
						case 0:
							start = std::clock();
							insertionSort(array, size);
							duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
							break;
						case 1:
							start = std::clock();
							selectionSort(array, size);
							duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
							break;
						/*case 2:
							start = std::clock();
							mergeSort(array, size);
							duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
							break;
							*/
					nfile << "Approved: " << isCorrect(array, size) << endl;
					nfile << "Test time: " << duration << " seconds" << endl;
					delete array;
				}
				nfile << endl << endl;
			}
			nfile << endl << endl << endl << endl;
		}

  return 0;
}
