#ifndef RED_BLACK_rbtree
#define RED_BLACK_rbtree
#include <stack>

enum colors {RED, BLACK};

// Nodos del arbol:
template <typename T>
class rbnode{
   public:
		// Esta clase es para ser usada por otras clases.
		// Por eficiencia se hacen los atributos publicos.
		T key;
		rbnode<T> *p, *left, *right;
		enum colors color;

		// Constructor por omision.
		rbnode(){
		};
		
		// Constructor por copia del nodo.
		rbnode(const rbnode<T> * obj, const rbnode<T> * objNil, rbnode<T> * parent, rbnode<T> * nilPtr){
		}

      // Inicializacion de datos miembro.
		rbnode (const T& k, rbnode<T> *w = NULL, rbnode<T> *y = NULL, 
				 rbnode<T> *z = NULL, enum colors c = RED):
					key(k), p(w), left(y), right(z), color(c)
		{};
		
		~rbnode(){
		}
};

// Arbol:
template <typename T>
class rbtree{
	public:
		rbtree(){
			this->root = this->nil = new rbnode<T>(NULL, NULL, NULL, NULL, BLACK);
		};
			// Constructor (crea un arbol vacio)
			//Se usa un padre vacío, pues es hijo en comun de todas las "pre-hojas"

		rbtree(const rbtree<T>& obj){ 
		};
			// Constructor copia

		~rbtree(){
			destroy(root);
			delete nil;
		};
			// Destructor (borra el arbol)
			
		void inorderTreeWalk(rbnode<T>* x, std::stack<T> & pila){
			if(x->left && x->left != nil) inorderTreeWalk(x->left, pila);
      		pila.push(x->key);
      		pila.push(x->color);
      		if(x->right && x->right != nil) inorderTreeWalk(x->right, pila);
		};
            // Efectua un recorrido en orden del subarbol cuya ra’z es apuntada
            // por x. En cada visita apila la llave de cada nodo y su color.
            // Es decir, cada vez que se llega a un nodo se ejecutan las 
            // instrucciones pila.push(x->key); y luego pila.push(colorDeX).
            // Para efectos de la tarea, si el color del nodo es rojo, 
            // ponga en la pila un 0, y si es negro, ponga un 1.
            // Si se hace correctamente, al finalizar el mŽtodo la pila deber’a 
            // contener las llaves de los nodos del sub‡rbol (y su color) 
            // ordenadas de mayor a menor.
		
		rbnode<T>* treeSearch(const T& k){
			return recursiveSearch(root, k);
		};
			// Busca la llave recursivamente, si la encuentra devuelve un 
            // puntero al nodo que la contiene, sino devuelve NULL.

		rbnode<T>* iterativeTreeSearch(const T& k){
			rbnode<T> *p = root;
			while(p && p->key != k){
				p = k < p->key ? p->left : p->right;
			}
			return p;
		};
			// Igual que en el anterior pero usa un procedimiento iterativo.
			
		rbnode<T>* treeMinimum(){
			rbnode<T> *p = root;
			while(p->left && p->left != nil){
				p = p->left;
			}
			return p;
		};
			// Devuelve el nodo con la llave menor.
            // Si el arbol esta vacio devuelve NULL.

		rbnode<T>* treeMaximum(){
			rbnode<T> *p = root;
			while(p->right && p->right != nil){
				p = p->right;
			}
			return p;
		};
			// Devuelve el nodo con la llave mayor.
            // Si el arbol esta vacio devuelve NULL.

		rbnode<T>* treeSuccessor(const rbnode<T>* x){
	      if(x->right != nil) return minimal(x->right);
      	  rbnode<T> *p = x->p;
      	  while(p && x == p->right){
      	  	x = p;
      	  	p = p->p;
      	  }
      	  return p;
      	}
			// Devuelve el nodo cuya llave es la siguiente mas grande que 
            // la del nodo x. Si no existe tal nodo devuelve NULL.

		void treeInsert(rbnode<T>* z){ //aux es y, actual es x.
			rbnode<T>* y = nil;
			rbnode<T>* x = root;
			int c = 0;
			while(x != nil){
				y = x;
				x = z->key < x->key ? x->left : x->right;
			}
			z->p = y;
			if(y == nil) root = z;
			else if(z->key < y->key){
				y->left = z;
			}
			else{
				y->right = z;
			}
			z->left = z->right = nil;			
			insertFix(z);
		}
			// Inserta el nodo z en la posicion que le corresponde en el arbol.

			
		rbnode<T>* treeDelete(rbnode<T>* z){
		};
			// Saca del arbol la llave contenida en el nodo apuntado por z.
			// Devuelve la direccion del nodo eliminado para que se pueda 
			// disponer de el.

	
		rbnode<T> * getRoot() const{
			return this->root;
		};
		
		// Devuelve la raiz del arbol. (Para efectos de revision de la tarea).

		
		rbnode<T> * getNil() const{
			return this->nil;
		};
		// Devuelve T.nil. (Para efectos de revision de la tarea).
			
		private:
	
		rbnode<T> *root;	// raiz del arbol
		rbnode<T> *nil;	    // nodo nil (hoja) del arbol


		rbnode<T>* recursiveSearch(rbnode<T> *p, const T& k){
			if(!p || k == p->key) return p;
      		else if(k < p->key) return recursiveSearch(p->left, k);
      		else return recursiveSearch(p->right, k);
		}


	    void destroy(rbnode<T> *p){
      		if(p){
        		if(p->left && p->left != nil){
          			destroy(p->left);
        		}
        		if(p->right && p->right != nil){
          			destroy(p->right);
        		}
       		delete p;
      		}
  		}	


  		//Rotaciones
  		void leftRotation(rbnode <T> * x){
  			rbnode<T> * y = x->right;
  			x->right = y->left;
  			if(y->left != nil) y->left->p = x;
  			y->p = x->p;
  			if(x->p == nil) root = y;
  			else if(x == x->p->left) x->p->left = y;
  			else x->p->right = y;
  			y->left = x;
  			x->p = y;
  		}

   		
   		void rightRotation(rbnode <T> * x){
  			rbnode<T> * y = x->left;
  			x->left = y->right;
  			if(y->right != nil) y->right->p = x;
  			y->p = x->p;
  			if(x->p == nil) root = y;
  			else if( x == x->p->right) x->p->right = y;
  			else x->p->left = y;
  			y->right = x;
  			x->p = y;
  		} 

  		void insertFix(rbnode<T>* z){
  			rbnode<T>* y;
  			while(z->p != nil && z->p->color == RED){
  				if(z->p == z->p->p->left){
  					y = z->p->p->right;
  					if(y->color == RED){
  						z->p->color = BLACK;
  						y->color = BLACK;
  						z->p->p->color = RED;
  						z = z->p->p;
  					}
  					else{
  						if(z == z->p->right){
  							z = z->p;
  							leftRotation(z);
  						}
  						z->p->color = BLACK;
  						z->p->p->color = RED;
  						rightRotation(z->p->p);
  					}
  				}
  				else{
  					y = z->p->p->left;
  					if(y->color == RED){
  						z->p->color = BLACK;
  						y->color = BLACK;
  						z->p->p->color = RED;
  						z = z->p->p;
  					}
  					else{
  						if(z == z->p->left){
  							z = z->p;
  							rightRotation(z);
  						}
  						z->p->color = BLACK;
  						z->p->p->color = RED;
  						leftRotation(z->p->p);
  					}
  				}
  			} 
  			root->color = BLACK;
  		}

  	rbnode<T>* minimal(rbnode<T> *z){
      	rbnode<T> *n = z;
      	while(n->left && n->left != nil) n = n->left;
      	return n;
    }
};

#endif	// RED_BLACK_rbtree
