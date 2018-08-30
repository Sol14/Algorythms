#ifndef _CLASE_ORDENADOR
#define _CLASE_ORDENADOR
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "time.h"
using namespace std;

class Ordenador{
	private:

	void merge(int * arreglo, int l, int m, int r){
		int i = 0; //indices de insercion
		int j = 0;
		int k = l;
		int	ti = m - l + 1;	//tamaños
		int	td = r - m;
		int L[ti], R[td];
		for(int i = 0;i < ti; i++){ //Copia arreglos
			L[i] = arreglo[l + i];
		}
		for(int i = 0;i < td; i++){
			R[i] = arreglo[m + i + 1];
		}
		//Acá difiere bastante al libro,
		//en el libro no veo la parte donde hace la copia
		//cuando uno de los 2 arreglos se ordena
		while(i < ti && j < td){
			if (L[i] <= R[j])
        {
            arreglo[k] = L[i];
            i++;
        }
        else
        {
            arreglo[k] = R[j];
            j++;
        }
        k++;
		}
		while (i < ti)
    {
        arreglo[k] = L[i];
        i++;
        k++;
    }
		while (j < td)
    {
        arreglo[k] = R[j];
        j++;
        k++;
    }
	}
/*
**	Basicamente es lo que estaba en el libro
**	el codigo es casi igual en todos los lugares
**	de referencia, aunque mi idea inicial era
**	dividir el tamanoarreglo desde el mergesort, no en el merge
**	pero consumía una cantidad de memoria, notablmente
**	más grande
*/
	void rmergesort(int * arreglo, int l, int r){	//limite left, limite rigth
		if(l < r){
			int m = l+(r-l)/2; //Resulta el medio de l y r
			rmergesort(arreglo, l, m);
			rmergesort(arreglo, m+1, r);
			merge(arreglo, l, m, r);
		}
	}

	public:

	Ordenador(){};
	~Ordenador(){};

	void seleccion(int * arreglo, int tamano){
		int pivot, min;	//pivot = temp
    for (int i = 0; i < tamano; i++){
      min = i;
      for(int j = i + 1; j < tamano; j++){
        if(arreglo[min] >= arreglo[j]){
          min = j;
        }
      }	//insercion
      pivot = arreglo[i];
      arreglo[i] = arreglo[min];
      arreglo[min] = pivot;
    }
	};

	void insercion(int * arreglo, int tamano){
		int key;	//elemento a insertar
		int j;
    for(int i = 1;  i < tamano; i++){
      key = arreglo[i];
      j = i - 1;
      while(j >=  0 &&  arreglo[j]  > key){
        arreglo[j + 1]  = arreglo[j];
        j -= 1; //no me gusta como se ve el --;
      }
      arreglo[j + 1]  =  key;	//Insercion
    }
	}

	void mergesort(int * arreglo, int tamano){ //Era mas facil usando 3 parametros, así
		rmergesort(arreglo, 0, tamano);					//"tecnicamente" no estoy modificando el .h
	}


	//Sin definir
	void heapsort(int * arreglo, int tamano){};
	void quicksort(int * arreglo, int tamano){};
	void radixsort(int * arreglo, int tamano){};
	int mediana(int * arreglo, int tamano){};
};
#endif
