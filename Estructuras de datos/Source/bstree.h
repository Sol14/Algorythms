#ifndef BINARY_SEARCH_Tree
#define BINARY_SEARCH_Tree
#include <iostream>
#include <stack>
using namespace std;
// Nodos del arbol:
template <typename T>
class node{
   public:
		// Esta clase es usada por otras clases.
		// Para mayor eficiencia, los atributos se hacen publicos.
		T key;
		node<T> *p, *left, *right;

		// Constructor por omision
		node(){
		}

		// Constructor por copia. Copia el nodo y sus hijos.
		node(const node<T> * obj, node<T> * padre){
      key = obj->key;
      p = padre;
      left = obj->left;
      right = obj->right;
		}

        // Inicializacion de datos miembro
		node(const T& k, node<T> *w = NULL, node<T> *y = NULL, node<T> *z = NULL):key(k), p(w), left(y), right(z){};

		~node(){
		}
};

// Arbol:
template <typename T>
class tree{
	public:

		tree(){
      root = NULL;
		}
			// Constructor. Crea un arbol vacio

		tree(const tree<T>& obj){
      root = NULL;
      rCopy(obj.getRoot(), NULL);
		}
			// Constructor copia

		~tree(){
      destroy(root);
		}
			// Destructor (borra el arbol)

		void inorderTreeWalk(node<T>* x, stack<T> & pila){
      if(x->left){
        inorderTreeWalk(x->left, pila);
      }
      pila.push(x->key);
      if(x->right){
        inorderTreeWalk(x->right, pila);
      }
		}

            // Efectua un recorrido en orden del sub�rbol cuya raiz es apuntada
            // por x, guardando en cada visita la llave de cada nodo en la pila.
            // Es decir, cada vez que se llega a un nodo se hace
            // pila.push(x->key). Si se hace correctamente, al finalizar el
            // metodo la pila debe contener las llaves de los nodos del
            // subarbol ordenadas de mayor a menor.


		node<T>* treeSearch(const T& k){
      return rsearch(root, k);
		}
			// Busca la llave recursivamente; si la encuentra, devuelve un
      // apuntador al nodo que la contiene, sino devuelve NULL

		node<T>* iterativeTreeSearch(const T& k){
      node<T> *n = root;
      while(n && (n->key != k)){
        if(k < n->key){
          n = n->left;
        }
        else{
          n = n->right;
        }
      }
      return n;
		}
			// Lo mismo que en el anterior pero usando un procedimiento
			// iterativo

		node<T>* treeMinimum(){
      node<T>* n = root;
      while(n->left){
        n = n->left;
      }
      return n;
		}
			// Devuelve el nodo que tiene la llave menor.
      // Si el arbol est� vacio devuelve NULL.

		node<T>* treeMaximum(){
      node<T>* n = root;
      while(n->right){
        n = n->right;
      }
      return n;
		}
			// Devuelve el nodo que tiene la llave mayor.
      // Si el arbol esta vacio devuelve NULL.

		node<T>* treeSuccessor(const node<T>* x){
      if(x->right){
        return minimal(x->right);
      }
      else{
        bool e = true;
        node<T> *q = new node<T>(x, x->p);
        node<T> *p = q->p;
        while (e && p) {
          if(p->left == q){
            e = false;
          }
          else{
            q = p;
            p = p->p;
          }
        }
        return p;
      }
		}
			// Devuelve el nodo cuya llave es la que le sigue a la
      // del nodo x. Si no existe tal nodo devuelve NULL.

		void treeInsert(node<T>* z){
      node<T> *y = NULL;
      node<T> *x = root;
      while (x != NULL){
        y = x;
        x = z->key < x->key ? x->left : x->right;
      }
      z->p = y;
      if(!y){
        root = z;
      }
      else if(z->key < y->key) y->left = z;
      else y->right = z;
    }
		// Inserta el nodo z en la posicion que le corresponde en el arbol.

		node<T>* treeDelete(node<T>* z){
      if(!z->left) transplant(z, z->right);
      else if(!z->right) transplant(z, z->left);
      else{ 
        node<T> *y = minimal(z->right);
        if(y->p != z){
          transplant(y, y->right);
          y->right = z->right;
          y->right->p = y;
        }
        transplant(z, y);
        y->left = z->left;
        y->left->p = y;
      }
      return z;
    }
			// Saca del arbol la llave contenida en el nodo apuntado por z.
			// Devuelve la direccion del nodo eliminado para que se pueda
			// disponer de ella.

		node<T> * getRoot() const{
			return this->root;
		}
		// Devuelve la raiz del arbol. (Para efectos de revisi�n de la tarea).

    void print(){
      rprint(root);
    }

    //Metodo de insercion rapida, creado para un test, no se supone que se use
    void quickInser(node<T> *p, node<T> *h){
      h->p = p;
      p->right = h;
    }

  private:
		node<T> *root;	// root of the Tree

    void destroy(node<T> *p){
      if(p){
        if(p->left){
          destroy(p->left);
        }
        if(p->right){
          destroy(p->right);
        }
        delete p;
      }
    }

    void transplant(node<T> *u, node<T> *v){
      if(!u->p) root = v;
      else if(u == u->p->left) u->p->left = v;
      else u->p->right = v;
      if(v) v->p = u->p;
    }

    void rprint(node<T>* n){
      if(n->left){
        rprint(n->left);
      }
      std::cout << n->key << std::endl;
      if(n->right){
        rprint(n->right);
      }
    }

    node<T>* rsearch(node<T> *n, const T& k){
      if(!n || k == n->key){
        return n;
      }
      else if(k < n->key){
        return rsearch(n->left, k);
      }
      else {
        return rsearch(n->right, k);
      }
    }

    node<T>* minimal(node<T> *z){
      node<T> *n = z;
      while(n->left){
        n = n->left;
      }
      return n;
    }

    void rCopy(node<T> *n, node<T> *m){
      node<T> *z = new node<T>(n->key, m);
      treeInsert(z);
      if(n->left){
        rCopy(n->left, m);
      }
      if(n->right){
        rCopy(n->right, m);
      }
    }
  
  };
#endif	// BINARY_SEARCH_Tree
