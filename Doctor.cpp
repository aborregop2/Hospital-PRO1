#include "Doctor.hpp"

//-------------
// Constructors
//-------------

/* Pre: cert */
/* Post: crea un doctor buit */
Doctor::Doctor() {
}

/* Pre: cert */
/* Post: crea un doctor amb el nom, i visites rebudes per paràmetre */
Doctor::Doctor(string nom, list<Visita> visites) {
	this->nom = nom;
	this->visites = visites;
}

//------------
// Destructor
//------------

/* esborra automàticament els objectes locals 
en sortir d'un àmbit de visibilitat */
Doctor::~Doctor() {

}

//-----------
// Consultors
//-----------

/* Pre: cert */
/* Post: retorna el nom del doctor */
string Doctor::getNom() const {
	return nom;
}



/* Pre: cert */
/* Post: retorna un booleà que indica si el doctor paràmetre
implícit i doctor 'd' són identics (true)
o no ho són (false) */
bool Doctor::operator==(const Doctor &d){
	return nom == d.nom;
}

//-------------
// Modificadors
//-------------

/* Pre: v es una visita */
/* Post: s'afegeix a la llista de visites la nova visita */
void Doctor::afegirVisita(const Visita &v) {
	if (visites.empty()) {
		visites.push_back(v);
	}
	else {
		bool insertat = false;
		for (list<Visita>::iterator it = visites.begin(); it != visites.end() and not insertat; it++) {
			if (not ((*it).getData() < v.getData()) and not ((*it).getData() == v.getData())) {
				visites.insert(it, v);
				insertat = true;
			}
			else if ((*it).getData() == v.getData()){
				visites.insert(++it,v);
				insertat = true;
			}

		}
		if (not insertat){
			visites.push_back(v);
		}
	}
}

/* Pre: v es una visita */
/* Post: s'esborren totes les visites del pacient p de la llista de visites del paràmetre implícit */
void Doctor::eliminarTotesVisita(const Pacient &p) {

	
	list<Visita>::iterator it = visites.begin(); 
	while(it != visites.end()){

		if (p.getNom() == (*it).getPacient().getNom()) {
			it = visites.erase(it);
		}
		else ++it;


	}
}

/* Pre: v es una visita */
/* Post: elimina la visita de la llista de visites del doctor */
void Doctor::eliminarVisita(Visita &v) {
	bool stop = false;
	

	list<Visita>::iterator it = visites.begin();
	while (it != visites.end() and not stop){
		if (v.getData() == (*it).getData() and v.getPacient() == (*it).getPacient()) {		
			it = visites.erase(it);
			stop = true;
		}
		else it++;
	}
	

	if (not stop) {
		cout << "  error" << endl;
	}
}


//-----------
// L/E
//-----------

/* Pre: estan preparats al canal estàndard d'entrada un string i una llista */
/* Post: el doctor 'd' passa a tenir el string i la llista llegits del canal
estàndard d'entrada com a nom i visites, respectivament */      
istream& operator>>(istream &is, Doctor &d) 
{
	is >> d.nom;
	return is;
}
        
/* Pre: cert */
/* Post: s'han escrit els atributs nom i visites del doctor 'd'
al canal estàndard de sortida */
ostream& operator<<(ostream &os, const Doctor &d)
{
	os << "  " << d.nom << endl;
	
	for (list<Visita>::const_iterator ini = d.visites.begin(); ini != d.visites.end(); ini++) {
		os << "  " << *ini << endl;
	}
	return os;
}