#include "Visita.hpp"

//-------------
// Constructors
//-------------

/* Pre: cert */
/* Post: crea una visita de data 'd' i pacient 'p' */
Visita::Visita(const Data &data, const Pacient &pacient) {
    this->data = data;
    this->pacient = pacient;
}

//-------------
// Modificadors
//-------------

/* Pre: cert */
/* Post: modifica la data del paremetre implicit en funcio de "d" */
void Visita::change_Data(Data &d) {

    Data a(d.getDia(), d.getMes(), d.getAny());
    this->data = a;
  
}

/*Pre: cert*/
/*Post: El parametre implícit adquereix els valors de v*/
Visita& Visita::operator=(const Visita &v){

    if (this != &v) {

        this->data = v.getData();
        this->pacient = v.getPacient(); 

    }

    return *this;

}

/*Pre: cert*/
/*Post: S'intercanvien els valors del parametre implícit i v*/
void Visita::swap_visita(Visita &v){
    
    Visita aux(this->data, this->pacient);

    *this = v;
    v = aux;

}

//-----------
// Consultors
//-----------

/* Pre: cert */
/* Post: retorna la data de la visita paràmetre implícit */
Data Visita::getData() const {
    return data;
}

/* Pre: cert */
/* Post: retorna el pacient de la visita paràmetre implícit */
Pacient Visita::getPacient() const {
    return pacient;
}

//-----------
// Lectura i escriptura
//-----------

/* Pre: cert*/
/*Post: Es prepara al canal de sortida els parametres de v*/
ostream& operator<<(ostream &os, const Visita &v) {
	os << v.getData() << " " << v.getPacient().getNom();
  	return os;
}
		
