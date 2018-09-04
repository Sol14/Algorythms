#include <fstream>
#include "Ordenador.h"
#include <ctime>
#include <iostream>
#include <random>

using namespace std;

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
	Ordenador ord;
	ofstream nfile(argv[1]);
	std::clock_t start;
	 double duration;

	 for(int k = 0; k < 3; k++)
	 {
		 switch (k) {
			 case 0:
				 nfile << "Testing Insertion Sort: " << endl;
				 break;
			 case 1:
				 nfile << "Testing Selection Sort: " << endl;
				 break;
			 case 2:
				 nfile << "Testing Merge Sort: " << endl;
				 break;
			 }

		 for(int i = 0; i < 4; i ++)
		 {
				int size;
				switch (i) {
					case 0:
						size = 200000;
						break;
					case 1:
						size = 400000;
						break;
					case 2:
						size = 800000;
						break;
					case 3:
						size = 1200000;
						break;
				}
				for(int j = 0; j < 5; j++){
					int * array = getRandom(size);
					nfile << "Test " << j << " on " << size << " elements" << endl;
					switch (k) {
						case 0:
							start = std::clock();
							ord.insercion(array, size);
							duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
							break;
						case 1:
							start = std::clock();
							ord.seleccion(array, size);
							duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
							break;
						case 2:
							start = std::clock();
							ord.mergesort(array, size);
							duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
							break;
						}
					nfile << "Approved: " << isCorrect(array, size) << endl;
					nfile << "Test time: " << duration << " seconds" << endl;
					delete array;
					nfile << endl;
				}
				nfile << endl << endl;
			}
			nfile << endl << endl << endl << endl;
		}

  return 0;
}
