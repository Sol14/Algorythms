#ifndef HASH_CLASS
#define HASH_CLASS
#include <list>
#include <vector>
#include <iostream>

template <typename T>

class hasht{
	public:
		hasht(int nEntradas){
			tabla.resize(nEntradas);
			numEntradas = nEntradas;
		};
			// Constructor que especifica el numero de cubetas (entradas) 
			// en la tabla
			
		hasht(const hasht<T>& obj){ 
		};
			// Constructor copia

		~hasht(){
			//No se ha creado espacio para nueva memoria manualmente
		};
			// Destructor (borra la tabla)

		T* search(const T& item){
			int pos = item % numEntradas;
			auto p = tabla[pos].begin();
			while(p !=  tabla[pos].end() && *p != item){
				++p;
			}
			T* q = *p == item ? &(*p) : NULL;
			return q;
		};
			// Retorna un puntero a la llave o NULL si no se encuentra
			//El borrado del puntero extra es responsabilidad del usuario

		void insert(const T& item){
			tabla[item % numEntradas].push_back(item); 
		};
			// Inserta el elemento en la tabla

		void print(){
			std::cout << "====================================" << std::endl;
			for(int i = 0; i < numEntradas; i++){
				auto p = tabla[i].begin();
				while(p != tabla[i].end()){
					std::cout << *p << " ";
					p++;
				}
				std::cout << std::endl;
				std::cout << "====================================" << std::endl;
			}
		}
		//Prueba de llenado

	private:
		int numEntradas;
			// Nœmero de entradas en la tabla
		std::vector<std::list<T> > tabla;
			// La tabla es un vector de listas de STL
};
#endif
