#ifndef VISITA_HPP
#define VISITA_HPP
#include "Data.hpp"
#include "Pacient.hpp"

using namespace std;

/** Representació d'una visita.
 *
 *  Consta d'una data i d'un pacient.
 */

class Visita {
	
	private:
		Data data;
		Pacient pacient;
	
	public:
		//-------------
		// Constructors
		//-------------
		
		/* Pre: cert */
		/* Post: crea una visita de data 'd' i pacient 'p' */
		Visita(const Data &d, const Pacient &p);

		//-------------
		// Modificadors
		//-------------

		/* Pre: cert */
		/* Post: modifica la data del paremetre implicit en funcio de "d" */
		void change_Data(Data &d);


		/*Pre: cert*/
		/*Post: El parametre implícit adquereix els valors de v*/
		Visita& operator=(const Visita &v);

		/*Pre: cert*/
		/*Post: S'intercanvien els valors del parametre implícit i v*/
		void swap_visita(Visita &v);
		
		//-----------
		// Consultors
		//-----------

		/* Pre: cert */
		/* Post: retorna la data de la visita paràmetre implícit */
		Data getData() const;
		
		/* Pre: cert */
		/* Post: retorna el pacient de la visita paràmetre implícit */
		Pacient getPacient() const;

		//-----------
		// Lectura i escriptura
		//-----------

		/* Pre: cert*/
		/*Post: Es prepara al canal de sortida els parametres de v*/
		friend ostream& operator<<(ostream &os, const Visita &v);


		
};
#endif