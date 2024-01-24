#include "PriorityQueue.hpp"
//--------------------------
// Mètodes privats auxiliars
//--------------------------

/* Pre: cert */
/* Post: fa una còpia de la cadena de nodes
   apuntats	per item per permetre assignar cues (=) i
   crear cues fent servir el constructor còpia */
template <typename T>	
void Queue<T>::copyItems(const Item *item, Item *(&first), Item *(&last), int &_size) {
	if (item == NULL) {
		first = NULL;
		last = NULL;
		_size = 0;
		return;
	}
	first = new Item();
	first->value = item->value;
	last = first;
	_size = 1;
	while (item->next != NULL) {
		last->next = new Item();
		last = last->next;
		item = item->next;
		last->value = item->value;
		_size++;
	}
	last->next = NULL;
}

/* Pre: cert */
/* Post: no fa res si item és NULL, sinó allibera
   espai de la cadena de nodes apuntada per item */
template <typename T>
void Queue<T>::deleteItems(Item *item) {
	while (item != NULL) {
		Item *aux = item;
		item = item->next;
		delete aux;
	}
}


//-------------
// Constructors
//-------------

/* Pre: cert */
/* Post: el resultat és una cua amb prioritat sense cap element */
template <typename T>
Queue<T>::Queue() {
	first = last = NULL;
	_size = 0;
}

/* Pre: cert */
/* Post: el resultat és una cua amb prioritat còpia de la
   cua rebuda */
template <typename T>
Queue<T>::Queue(Queue &q) {
	copyItems(q.first, first, last, _size);
}


//-------------
// Destructor
//-------------

/* esborra automàticament els objectes locals
   en sortir d'un àmbit de visibilitat */
template <typename T>
Queue<T>::~Queue() {
	deleteItems(first);
	_size = 0;
}


//-------------
// Modificadors
//-------------

/* Pre: cert */
/* Post: operació d'assignació de cues  */
template <typename T>
Queue<T>& Queue<T>::operator=(const Queue &q) {
	if (this != &q) {
		deleteItems(first);
		copyItems(q.first, first, last, _size);
	}
	return *this;
}

/* Pre: el paràmetre implícit no és buit */
/* Post: elimina el primer element del paràmetre
         implícit	*/
template <typename T>
void Queue<T>::pop() {
	if (first == NULL) {
		cerr << "Error: pop on empty queue" << endl;
		exit(0);
	}
	Item *aux = first;
	first = first-> next;
	delete aux;
	_size--;
	if (first == NULL) last = NULL;
}

/* Pre: cert */
/* Post: afegeix el valor rebut per paràmetre en el
	     paràmetre implícit, tenint en compte la seva prioritat */
template <typename T>
void Queue<T>::push(T value) {
	Item *pitem = new Item();
	pitem->value = value;
	_size++;
	if (first == NULL or value.compare(first->value)) {
		pitem->next = first;
		first = pitem;
		if (last == NULL) last = first;
		return;
	}
	Item *current = first;
	while (current->next != NULL and not (value.compare(current->next->value)))
		current = current->next;
	pitem->next = current->next;
	current->next = pitem;
	if (last == current) last = pitem;
}

/* Pre: el paràmetre implícit no és buit */
/* Post: elimina el valor rebut per paràmetre del
	     paràmetre implícit */
template <typename T>
void Queue<T>::remove(T value) {
	
	Item *pivot = first;
	

	if (pivot->value == value){
		if (pivot->next == NULL){
			first = NULL;
			delete(pivot);
		}
		else{
			first = pivot->next;
			delete(pivot);
		}
	}
	else{
		while (not (pivot->next->value == value) and not (pivot == last)){
			
			pivot = pivot->next;
		}
		
		if (pivot->next->value == value){
		
			Item *pivotaux = pivot->next->next;
			delete (pivot->next);
			pivot->next = pivotaux;
		
		}
	}

}


//-----------
// Consultors
//-----------

/* Pre: el paràmetre implícit no és buit */
/* Post: el resultat és el primer element 
	     del paràmetre implícit */
template <typename T>
T Queue<T>::front() const {
	if (first == NULL) {
	cerr << "Error: front on empty queue" << endl;
	exit(0);
	}
	return first->value;
}	

/* Pre: cert */
/* Post: el resultat és el nombre d'elements
	     del paràmetre implícit */  
template <typename T>
int Queue<T>::size() const {
	return _size;
}

/* Pre: cert */
/* Post: el resultat indica si el paràmetre
   implícit	és buit o no */
template <typename T>
bool Queue<T>::empty() const {
	return first == NULL;
}

/*Pre: cert*/
/*Post: Retorna un boolea que es cert si el pacient es troba a la cua i fals si no*/
template <typename T>
bool Queue<T>::find(T &p){
	bool trobat = false;
	if (not (this->empty())){
		for (Item *aux = first; aux != NULL and not trobat; aux = aux->next){

			if (aux->value == p){
				trobat = true;
			}

		}
	}
	return trobat;
}

//-----------
// L/E
//-----------
	
/* Pre: cert */
/* Post: s'han escrit al canal estàndard de sortida els elements
   de q */
template<typename U>
ostream &operator<<(ostream &os, Queue<U> &q) {
  os << q._size;
  for (typename Queue<U>::Item *item = q.first; item != NULL; item = item->next)
    os << " " << item->value;
  return os;
}

/* Pre: q està buida; el canal estàndard d'entrada els elements
    d'una cua Q */
/* Post: q = Q */
template<typename U>
istream &operator>>(istream &is, Queue<U> &q) {
  int size;
  is >> size;
  if (size == 0) {
    q = Queue<U> ();
    return is;
  }
  for (int i = 0; i < size; ++i) {
    U x;
    cin >> x;
    q.push(x);
  }
  return is;
}
