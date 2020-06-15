#include <iostream>
#include <fstream>
#include <ctime>
#include "llist.h"
#include <random>

#define Seconds 10
#define SIZE 1000000

using namespace std;

int getRandom(mt19937 rng, int min, int max){
    rng.seed(std::random_device()());
    uniform_int_distribution<mt19937::result_type> dist6(min,max);
    return dist6(rng);
}


int main(int argc, char const *argv[]){
	//Inicializacion de la prueba
	mt19937 rng;
	llist<int> lista;
	llist<int> lista2;
	clock_t inicio;
	double duracion;
	int busquedas = 0;
	int exitosas = 0;
	int fallidas = 0;
	llnode<int> *temp;
	//Llenado de lista random
	for(int i = 0; i < SIZE; i++){
		llnode<int> *n = new llnode<int>(getRandom(rng, 0, 2 * SIZE));
		lista2.listInsert(n);
	}

	inicio = clock();
	cout << "Inicio: " << duracion << endl;
	while(duracion < 10){
		temp = lista2.listSearch(getRandom(rng, 0, 2 * SIZE));
		busquedas++;
		if(temp != NULL){
			exitosas++;
		}
		else{
			fallidas++;
		}
		duracion = (clock() - inicio) / (double) CLOCKS_PER_SEC;
	}
	cout << "cantidad de busquedas random: " << busquedas << endl;
	cout << "cantidad de busquedas exitosas: " << exitosas << endl;
	cout << "cantidad de busquedas fallidas: " << fallidas << endl;
	cout << "Tiempo: " << duracion << endl;

	//Inicializacion de lista lineal
	for(int i = 0; i < SIZE; i++){
		llnode<int> *n = new llnode<int>(i);
		lista.listInsert(n);
	}

	//Iniciodel timer 10 sec
	inicio = clock();
	exitosas = 0;
	fallidas = 0;
	duracion = 0;
	busquedas = 0;
	cout << "Inicio: " << duracion << endl;
	while(duracion < 10){
		temp = lista.listSearch(getRandom(rng, 0, 2 * SIZE));
		busquedas++;
		if(temp != NULL){
			exitosas++;
		}
		else{
			fallidas++;
		}
		duracion = (clock() - inicio) / (double) CLOCKS_PER_SEC;
	}
	cout << "cantidad de busquedas random: " << busquedas << endl;
	cout << "cantidad de busquedas exitosas: " << exitosas << endl;
	cout << "cantidad de busquedas fallidas: " << fallidas << endl;
	cout << "Tiempo: " << duracion << endl;
	return 0;
}