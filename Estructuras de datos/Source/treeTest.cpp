#include <iostream>
#include <fstream>
#include <ctime>
#include "bstree.h"
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
	tree<int> arbol;
	tree<int> arbol2;
	clock_t inicio;
	double duracion;
	int busquedas = 0;
	int exitosas = 0;
	int fallidas = 0;
	node<int> *temp;
	
	
	//Llenado de lista random
	for(int i = 0; i < SIZE; i++){
		node<int> *n = new node<int>(getRandom(rng, 0, 2 * SIZE));
		arbol2.treeInsert(n);
	}

	inicio = clock();
	duracion = 0;
	while(duracion < 10){
		temp = arbol2.treeSearch(getRandom(rng, 0, 2 * SIZE));
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
	cout << "Tiempo: " << duracion << "s" << endl;
	
	//Inicializacion de lista lineal
	arbol.treeInsert(new node<int>(0));
	node<int> *p = arbol.getRoot();
	for(int i = 1; i < SIZE; i++){
		node<int> *n = new node<int>(i);
		arbol.quickInser(p, n);
		p = n;
	}
	//Iniciodel timer 10 sec
	inicio = clock();
	exitosas = 0;
	fallidas = 0;
	duracion = 0;
	busquedas = 0;
	while(duracion < 10){
		temp = arbol.iterativeTreeSearch(getRandom(rng, 0, 2 * SIZE));
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
	cout << "Tiempo: " << duracion << "s" << endl;
	return 0;
}