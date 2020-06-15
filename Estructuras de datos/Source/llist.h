#ifndef LINKED_LIST_llist
#define LINKED_LIST_llist
#include <iostream>

// Nodos de la lista:
template <typename T>
class llnode{
   public:
		// Esta clase es para ser usada por otras clases.
		// Por eficiencia los atributos se dejan publicos.
		T key;
		llnode<T> *prev, *next;
		//enum colors color;

		// Constructor por omision.
		llnode(){
		};

      // Inicializacion de los datos miembro.
		llnode (const T& k, llnode<T> *w = NULL, llnode<T> *y = NULL):key(k), prev(w), next(y) {};

		~llnode(){
		}
};

// Lista enlazada con nodo centinela:
template <typename T>
class llist{
	public:
		llist(){
      nil = new llnode<T>(NULL);
      nil->prev = nil;
      nil->next = nil;
    };
			// Constructor (crea una lista vacia)

		llist(const llist<T>& obj){
      nil = new llnode<T>(obj.getNil()->key);
      nil->next = nil;
      nil->prev = nil;
      llnode<T> *p = obj.getNil()->prev;
      while(p != obj.getNil()){
        listInsert(new llnode<T>(p->key));
        p = p->prev;
      }
		};
			// Constructor copia

		~llist(){
      llnode<T> *p = nil->next;
      while(p != nil){
        llnode<T> *q = p->next;
        delete p;
        p = q;
      }
		};
			// Destructor (borra la lista)

		llnode<T>* listSearch(const T& k){
      llnode<T> *p;
      p = nil->next;
      while(p != nil && p->key != k){
        p = p->next;
      }
      p = p == nil ? NULL : p;
      return p;
		};
			// Busca la llave iterativamente. Si la encuentra, devuelve un
      // apuntador al nodo que la contiene; sino devuelve NULL.

		void listInsert(llnode<T>* x){
      if(nil->next == nil){
        nil->prev = x;
      }
      nil->next->prev = x;
      x->next = nil->next;
      x->prev = nil;
      nil->next = x;
    }
			// Inserta el nodo x en la lista.

		llnode<T>* listDelete(llnode<T>* x){
      x->prev->next = x->next;
      x->next->prev = x->prev;
      return x;
		};
			// Saca de la lista la llave contenida en el nodo apuntado por x.
			// Devuelve la direccion del nodo eliminado para que se pueda
			// disponer de el.

		llnode<T> * getNil() const{
			return this->nil;
		};
		// Devuelve el nodo centinela. (Para efectos de revision de la tarea).

    void print(){
      llnode<T> * P = nil->prev;
      while(P!= nil){
        std::cout << P->key << std::endl;
        P = P->prev;
      }
    }

		private:

		llnode<T> *nil;	    // nodo centinela
};

#endif	// LINKED_LIST_llist
