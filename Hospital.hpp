#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP
#include "Doctor.hpp"
#include "PriorityQueue.hpp"
#include "BST.hpp"


using namespace std;

/** Representació d'un hospital.
 *
 *  Consta d'una llista de doctors juntament amb un BST de pacients i una llista d'espera dels pacients
 * 	(PriorityQueue)
 */

class Hospital {
	private:
		list<Doctor> doctors;
		Queue<Pacient> llista_espera;
		BST<Pacient> pacients;
		
	public:
		//-------------
		// Constructors
		//-------------

		/* Pre: cert */
		/* Post: el resultat és un hospital buit */
		Hospital();

		//-------------
		// Destructor
		//-------------
	
		/* esborra automàticament els objectes locals
	   	en sortir d'un àmbit de visibilitat */
		~Hospital();

		//-------------
		// Modificadors
		//-------------

		/* Pre: p es un pacient no buit */
		/* Post: si el pacient no esta registrat a l'hospital es afegit a la llista d’espera en funci´o de la
		gravetat del seu estat de salut i registrat al sistema. */
		void add_pacient(Pacient &p);

		/* Pre: p es un pacient no buit */
		/* Post: si el pacient es troba al sistema, s'elimina del mateix, de la llista d'espera i s'elimina qualsevol 
		visita que pugues tenir, altrament es dona un error */
		void remove_pacient(Pacient &p);

		/* Pre: d es un doctor */
		/* Post: afegeix un doctor al sistema si no hi ha un altre igual en el mateix */
		void insert_doctor(Doctor &d);

		/* Pre: cert */
		/* Post: s'elemina el primer pacient de la llista d'espera, si aquesta esta buida
		es produeix un error */
		void treat_pacient();

		/* Pre: p es un Pacient no buit i g es un enter que representa la nova gravetat del pacient */
		/* Post: s’actualitza el valor de gravetat del pacient en el sistema i es
		ressitua el pacient en la llista d’espera en funci´o del nou nivell de gravetat */
		void modify_status(Pacient &p, int g);

		/* Pre: p es un Pacient, d es un string (nom del doctor) i date es una data */
		/* Post: si el pacient o el doctor es troben al sistema es produeix un error, altrament s’afegeix una nova visita 
		al doctor amb el pacient i data indicats. */
		void new_visit(Pacient &p, string d, Data &date);

		/* Pre: p es un Pacient, d es un string (nom del doctor) i date es una data */
		/* Post: si el pacient o el doctor no es troben al sistema es produeix un error, altrament s’elimina la visita al doctor amb
		el pacient i data indicats. */
		void delete_visit(Pacient &p, string d, Data &date);



		//-------------
		// Consultors
		//-------------

		/* Pre: cert */
		/* Post: escriu la llista d'espera per pantalla */
		void llista_espera_consultor() const;

		/* Pre: cert */
		/* Post: escriu el nom de cada doctor i les seves visites ordenades per data, en cas 
		de que hi hagi 2 dates coincidents s'escriuen per ordre d'alta */
		void visit_consultor() const;	

		/*Pre: cert*/
		/*Post: retorna el pacient que te el mateix nom que el parametre*/
		void pacient_consultor(Pacient &pa) const;

		//-------------------
		// Funcions auxiliars
		//-------------------

		/* Pre: d es un string */
		/* Post: retorna si el doctor es troba al sistema */
		bool find_doctor(string d) const;	


};
#endif