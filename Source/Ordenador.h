#ifndef _CLASE_ORDENADOR
#define _CLASE_ORDENADOR
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "time.h"
using namespace std;

class Ordenador{
	private:
		void merge(int * arreglo, int l, int m, int r);
		void rmergesort(int * arreglo, int l, int r);

	public:

	Ordenador(){};
	~Ordenador(){};

	//Si piensa no implementar algunos de los m�todos de ordenamiento, no los borre,
	//simplemente d�jelos con el cuerpo vac�o para evitar errores de compilaci�n, ya
	//que se va a ejecutar el mismo �main� para todas las tareas.
	void seleccion(int * arreglo, int tamano);
	void insercion(int * arreglo, int tamano);
	void mergesort(int * arreglo, int tamano);
	void heapsort(int * arreglo, int tamano);
	void quicksort(int * arreglo, int tamano);
	void radixsort(int * arreglo, int tamano);
	int mediana(int * arreglo, int tamano);
};
#endif
