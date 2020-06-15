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
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0,25);
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
	int * array;
	array = getRandom(15);
	for(int i = 0; i < 15; i++){
		cout << array[i] << endl;
	}
	cout << endl;
	ord.heapsort(array, 15);
	for(int i = 0; i < 15; i++){
		cout << array[i] << endl;
	}
}
