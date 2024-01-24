#include "Data.hpp"


//-------------
// Constructors
//-------------

/* Pre: cert */
/* Post: crea una data buida */
Data::Data() {
}

/* Pre: cert */
/* Post: crea una data amb el dia, mes i any rebuts per paràmetre */
Data::Data(int dia, int mes, int any) {
    this->dia = dia;
    this->mes = mes;
    this->any = any;
}

/*Pre: cert*/
/*Post: asigna al paràmetre implícit les dades de d*/
Data::Data(const Data &d) {
    dia = d.dia;
    mes = d.mes;
    any = d.any;
 }



//-----------
// Consultors
//-----------

/* Pre: cert */
/* Post: retorna el dia de la data paràmetre implicit */
int Data::getDia() const {
    return dia;
}

/* Pre: cert */
/* Post: retorna el mes de la data paràmetre implicit */
int Data::getMes() const {
    return mes;
}

/* Pre: cert */
/* Post: retorna l'any de la data paràmetre implicit */
int Data::getAny() const {
    return any;
}

/* Pre: cert */
/* Post: retorna un booleà que indica si la data paràmetre
	     implícit i la data 'd' rebuda són identiques (true)
		 o no ho són (false) */
bool Data::operator==(const Data &data) {
	return dia == data.dia  and  mes == data.mes  and  any == data.any;
}

/* Pre: cert */
/* Post: retorna un booleà que indica si la data paràmetre
         implícit és anterior a la data 'd' rebuda (true) o
	     no ho és (false) */
bool Data::operator<(const Data &data) {
	return dia < data.dia  or (dia == data.dia and mes < data.mes) or (dia == data.dia and mes == data.mes and any < data.any);
}

/* Pre: cert */
/* Post: asigna els atributs de d al parametre implicit */
Data& Data::operator=(const Data &d) {
    if (this != &d) {
        dia = d.dia;
        mes = d.mes;
        any = d.any;
    }
    return *this;
}


//-----------
// L/E
//-----------
		
/* Pre: estan preparats al canal estàndard d'entrada tres enters */
/* Post: la data 'd' passa a tenir els enters llegits del canal
         estàndard d'entrada com a dia, mes i any, respectivament */	
istream& operator>>(istream &is, Data &data) {
	is >> data.dia >> data.mes >> data.any;
	return is;
}
		
/* Pre: cert */
/* Post: s'han escrit els atributs dia, mes i any de la data 'd'
	     al canal estàndard de sortida */
ostream& operator<<(ostream &os, const Data &data) {
	os << data.dia << "/" << data.mes << "/" << data.any;
  	return os;
}