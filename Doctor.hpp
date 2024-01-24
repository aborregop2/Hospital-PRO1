#ifndef DOCTOR_HPP
#define DOCTOR_HPP
#include <iostream>
#include <list>
#include "Visita.hpp"

using namespace std;

/** Representació d'un doctor.
 *
 *  Consta del nom del doctor i la llista de les seves visites programades.
 *  
 */

class Doctor {
	private:
        string nom;
        list<Visita> visites;

	public:
        //-------------
        // Constructors
        //-------------

        /* Pre: cert */
        /* Post: crea un doctor buit */
        Doctor();

        /* Pre: cert */
        /* Post: crea un doctor amb el nom, i visites rebudes per paràmetre */
        Doctor(string nom, list<Visita> visites);

        //------------
        // Destructor
        //------------

        /* esborra automàticament els objectes locals
	   en sortir d'un àmbit de visibilitat */
        ~Doctor();

        //-----------
        // Consultors
        //-----------

        /* Pre: cert */
        /* Post: retorna el nom del doctor */
        string getNom() const;

        

        /* Pre: cert */
	/* Post: retorna un booleà que indica si el doctor paràmetre
	   implícit i doctor 'd' són identics (true)
	   o no ho són (false) */
	bool operator==(const Doctor &d);

        //-------------
        // Modificadors
        //-------------

        /* Pre: v es una visita */
        /* Post: s'afegeix a la llista de visites la nova visita */
        void afegirVisita(const Visita &v);

        /* Pre: v es una visita */
        /* Post: s'esborren totes les visites del pacient p de la llista de visites del paràmetre implícit */
        void eliminarTotesVisita(const Pacient &p);

        
        /* Pre: v es una visita */
        /* Post: elimina la visita de la llista de visites del doctor */
        void eliminarVisita(Visita &v);

        //-----------
        // L/E
        //-----------

        /* Pre: estan preparats al canal estàndard d'entrada un string i una llista */
        /* Post: el doctor 'd' passa a tenir el string i la llista llegits del canal
           estàndard d'entrada com a nom i visites, respectivament */      
        friend istream& operator>>(istream &is, Doctor &d); 
        
        /* Pre: cert */
        /* Post: s'han escrit els atributs nom i visites del doctor 'd'
           al canal estàndard de sortida */
        friend ostream& operator<<(ostream &os, const Doctor &d); 



};
#endif