#include "Ordenador.h"
void Ordenador::seleccion(int * arreglo, int tamano){
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


void Ordenador::insercion(int * arreglo, int tamano){
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
};


void Ordenador::mergesort(int * arreglo, int tamano){
  rmergesort(arreglo, 0, tamano);
}


void Ordenador::heapsort(int * arreglo, int tamano){
  for(int i = tamano/2 - 1; i >= 0; i--){
    heap(arreglo, tamano, i);
  }

  for(int i = tamano-1; i >= 0; i--){
    swap(arreglo[0], arreglo[i]);
    heap(arreglo, i, 0);
  }
}


void Ordenador::quicksort(int * arreglo, int tamano){
  rquicksort(arreglo, 0, tamano - 1);
}


void Ordenador::radixsort(int * arreglo, int tamano){

}


int Ordenador::mediana(int * arreglo, int tamano){
  int mediana = floor((tamano - 1) / 2);
  return rmediana(arreglo, 0, tamano - 1, mediana);
}


int Ordenador::rmediana(int * arreglo, int menor, int mayor, int ind){
  int pivote = particion(arreglo, menor, mayor);
  if(ind == pivote){
    return arreglo[pivote];
  }
  if(menor < mayor){
      if(pivote > ind){
        return rmediana(arreglo, menor, pivote - 1, ind);
      }
      else{
        return rmediana(arreglo, pivote + 1, mayor, ind);
      }
  }
  else{
    return -1; //A veces se va por acá, revisar mañana despues del café
  }
}


void Ordenador::merge(int * arreglo, int l, int m, int r){
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


void Ordenador::rmergesort(int * arreglo, int l, int r){	//limite left, limite rigth
  if(l < r){
    int m = l+(r-l)/2; //Resulta el medio de l y r
    rmergesort(arreglo, l, m);
    rmergesort(arreglo, m+1, r);
    merge(arreglo, l, m, r);
  }
}


void Ordenador::rquicksort(int * arreglo, int menor, int mayor){
  if(menor < mayor){
    int pivote = particion(arreglo, menor, mayor);
    rquicksort(arreglo, menor, pivote - 1);
    rquicksort(arreglo, pivote + 1, mayor);
  }
}


int Ordenador::particion(int* arreglo, int menor, int mayor){
  int swap;
  int pivote = arreglo[mayor];
  int i = menor - 1;
  for(int j = menor; j < mayor; j++){
    if(arreglo[j] <= pivote){
      i++;
      swap = arreglo[i];
      arreglo[i] = arreglo[j];
      arreglo[j] = swap;
    }
  }

  swap = arreglo[i+1];
  arreglo[i+1] = arreglo[mayor];
  arreglo[mayor] = swap;
  return i+1;
}


void Ordenador::heap(int * arreglo, int n, int i){
  int mayor = i;
  int izq = 2 * i + 1;
  int der = 2 * i + 2;
  if (izq < n && arreglo[izq] > arreglo[mayor]) {
    mayor = izq;
  }
  if (der < n && arreglo[der] > arreglo[mayor]) {
    mayor = der;
  }
  if(mayor != i){
    swap(arreglo[i], arreglo[mayor]);
    heap(arreglo, n, mayor);
  }
}


void Ordenador::swap(int& i, int& j){
	int swap;
	swap = i;
	i = j;
	j = swap;
}
