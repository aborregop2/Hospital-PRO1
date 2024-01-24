#include <iostream>
#include "Hospital.hpp"

using namespace std;


/** Programa principal
 *
 * main() crea l'hospital, fa la lectura d'instruccions i
 * l'escriptura de resultats. Les operacions estan definides i
 * implementades en les classes Hospital, Pacient, Doctor, Visita,
   Data, PriorityQueue i BST
 */
int main() {
	// Crear un hospital
	Hospital h;
	

	
	// Processar instruccions
    string inst;
    while ((cin >> inst) and (inst != "fi")) {
        
		if (inst == "alta_pacient") {
			Pacient p;
			cin>>p;
			h.add_pacient(p);
			
            	

        } else if (inst == "baixa_pacient") {
            
			string p;
			cin>>p;
			Pacient pa(p);
			h.pacient_consultor(pa);
			h.remove_pacient(pa);
			
			

        } else if (inst == "alta_doctor") {
            string doc;
			cin>>doc;
			list<Visita> v;
			Doctor d (doc, v);
			h.insert_doctor(d);
			

        } else if (inst == "llista_espera") {

			cout << "llista_espera"<<endl;
			h.llista_espera_consultor();

        } else if (inst == "tractar_seguent_pacient") {

			h.treat_pacient();

        } else if (inst == "modificar_estat_pacient") {
			string s;
			cin >> s;
			Pacient pa(s);
			h.pacient_consultor(pa);
			int g;
			cin>>g;
			h.modify_status(pa, g);

			

      	} else if (inst == "programar_visita") {

			
			string p;
			cin >> p;
			Pacient pa(p);
			h.pacient_consultor(pa);
			string d;
			cin >> d;
			Data dat;
			cin >> dat;
			h.new_visit(pa, d, dat);


      	} else if (inst == "cancellar_visita") {

			
			string p;
			cin >> p;
			Pacient pa(p);
			h.pacient_consultor(pa);
			string d;
			cin >> d;
			Data dat;
			cin >> dat;
			h.delete_visit(pa, d, dat);


      	} else if (inst == "mostrar_programacio_visites") {

			cout << "mostrar_programacio_visites " << endl;
			h.visit_consultor();


      	} else {
			cout << inst << endl;
      		cout << "  error" << endl;
      	}
      	
    }
    cout << "fi" << endl;
}

	
