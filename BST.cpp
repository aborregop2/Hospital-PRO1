#include "BST.hpp"

//--------------------------
// Mètodes privats auxiliars
//--------------------------

/* Pre: cert */
/* Post: el primer component del resultat indica
   si el paràmetre implícit conté un element amb
   el valor rebut per paràmetre; en cas afirmatiu,
   el segon component conté l'element del paràmetre
   implícit amb aquest valor, altrament conté un
   element buit */
template <typename T>
 typename BST<T>::Item*  BST<T>::find_aux(Item *t, const T &value) const {
     if (t != NULL) {  // si l'arbre no està buit, comprovem el node
         if (t->data == value){
             return t;
         }
         else {
             if (value > t->data)
                 return find_aux(t->right, value);
				 /*H.I.: Al final el que queda a t es el punter que apunta
				         a el node que conté el pacient que es cerca o, en cas
						 de no trobar-ho serà NULL*/
				 /*Fita: La mida de l'arbre*/
             else
                 return find_aux(t->left, value);
				 /*H.I.: Al final el que queda a t es el punter que apunta
				         a el node que conté el pacient que es cerca o, en cas
						 de no trobar-ho serà NULL*/
				 /*Fita: La mida de l'arbre*/
         }
     }
     else return NULL;  // si està buit, tornem NULL
 }


/* Pre: cert */
/* Post: no fa res si item és NULL, sinó allibera
   espai de la jerarquia de nodes apuntada per item */
template <typename T>
void BST<T>::clear(Item *node) {
	if (node != NULL) {
		clear(node->left);
		clear(node->right);
		delete node;
	}
}


/* Pre: cert */
/* Post: afegeix un node amb el valor rebut 
   per paràmetre a la jerarquia de nodes apuntada
   per item, mantenint les propietats de BST */
template <typename T>
typename BST<T>::Item* BST<T>::insert(Item *node, const T& d) {
	if (node == NULL) {
		node = new Item(d, NULL, NULL);
	} else if (d < node->data) {
		node->left = insert(node->left, d);
	} else {
		node->right = insert(node->right, d);
	} 
	return node;
}


/* Pre: cert */
/* Post: esborra el node amb el valor rebut 
   per paràmetre de la jerarquia de nodes apuntada
   per item, mantenint les propietats de BST */	
template <typename T>
typename BST<T>::Item* BST<T>::remove(Item *node, const T& d) {
	if (node == NULL) {
		return NULL;
	} else if (d > node->data) {
		node->right = remove(node->right, d);
	} else if (d < node->data) {
		node->left = remove(node->left, d);
	} else if (node->left != NULL and node->right != NULL) {
		// Node has two children
		Item *tmp = node->right;
		while (tmp->left != NULL) {
			tmp = tmp->left;
		}
		node->data = tmp->data;
		node->right = remove(node->right, node->data);
	} else {
		// Node has at most one child
		Item *tmp = node;
		if (node->left == NULL) {
			node = node->right;
		} else if (node->right == NULL) {
			node = node->left;
		}
		delete tmp;
	}
	return node;
}

/* Pre: la jerarquia de nodes apuntada per item
	conté un node amb el primer valor rebut per
    paràmetre (d) */
/* Post: s'ha modificat el valor del node amb el
   segon valor rebut per paràmetre (newData), de
   la jerarquia de nodes apuntada per item */
template <typename T>
void BST<T>::setValue(Item *node, const T& d, const T& value) {
	Item *temp = find_aux(node, d);
	if (temp != NULL) {
		temp->data = value;
	} else {
		cerr << "Error: Node not found!" << endl;
	}
}


//-------------
// Constructors
//-------------

/* Pre: cert */
/* Post: el resultat és un bst sense cap element */	
template <typename T>
BST<T>::BST() {
	root = NULL;
}


//-------------
// Destructor
//-------------

/* esborra automàticament els objectes locals
	   en sortir d'un àmbit de visibilitat */
template <typename T>
BST<T>::~BST() { 
	clear(root); 
}


//-------------
// Modificadors
//-------------

/* Pre: cert */
/* Post: afegeix un element, amb el valor rebut
   per paràmetre, al paràmetre implícit */
template <typename T>
void BST<T>::insert(const T& d) { 
	root = insert(root, d); 
}

/* Pre: cert */
/* Post: esborra l'element, que té el valor rebut
   per paràmetre, del paràmetre implícit */
template <typename T>
void BST<T>::remove(const T& d) { 
	root = remove(root, d); 
}

/* Pre: el paràmetre implícit conté un element amb
	el primer valor rebut per paràmetre (d) */
/* Post: s'ha modificat el valor de l'element amb
   el segon valor rebut per paràmetre (newData), del
   paràmetre implícit */
template <typename T>
void BST<T>::setValue(const T& d, const T& value) { 
	setValue(root, d, value); 
}


//-----------
// Consultors
//-----------




/* Pre: cert */
/* Post: el primer component del resultat indica
   si el paràmetre implícit conté un element amb
   el valor rebut per paràmetre; en cas afirmatiu,
   el segon component conté l'element del paràmetre
   implícit amb aquest valor, altrament conté un
   element buit */
template <typename T>
pair<bool, T> BST<T>::find(const T& d) const { 
	pair<bool, T> par;
	
	if (this->root == NULL){

		par.first = false;
		par.second = d;
		
	}
	else{
		
		Item *pitem = this->root;
		
		
		Item *pitem2 = find_aux(pitem, d);
		
		
		
		if (pitem2 == NULL){

			par.first = false;
			par.second = d;

		}

		else{
			par.first = true;
			par.second = pitem2->data;
		} 
	}
	

	return par;

	
}
