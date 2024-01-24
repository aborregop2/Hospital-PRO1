#include "Hospital.hpp"



bool find_doctor(string d);


//-------------
// Constructors
//-------------

/* Pre: cert */
/* Post: el resultat és un hospital buit */
Hospital::Hospital() {

}

//-------------
// Destructor
//-------------
	
/* esborra automàticament els objectes locals
en sortir d'un àmbit de visibilitat */
Hospital::~Hospital() {

}

//-------------
// Modificadors
//-------------



/* Pre: cert */
/* Post: si el pacient no esta registrat a l'hospital es afegit a la llista d’espera en funci´o de la
gravetat del seu estat de salut i registrat al sistema, altrament es dona un error */
void Hospital::add_pacient(Pacient &p) {
    cout<<"alta_pacient ";
	cout<<p<<endl;
    if ((pacients.find(p)).first or p.getGravetat() < 1 or p.getGravetat() > 3) {
        
        cout << "  error" << endl;
    }
    else {
       llista_espera.push(p);
       pacients.insert(p);
    }
}

/* Pre: cert */
/* Post: si el pacient es troba al sistema, s'elimina del mateix, de la llista d'espera i s'elimina qualsevol 
visita que pugues tenir, altrament es dona un error */
void Hospital::remove_pacient(Pacient &p) {
    cout<<"baixa_pacient "<<p.getNom()<<endl;
    if (not (pacients.find(p)).first) {
       
        cout << "  error" << endl;
    }
    
    else {
         
        if (llista_espera.find(p)){
            
            llista_espera.remove(p);
        }
       
        pacients.remove(p);
        
      

        for (list<Doctor>::iterator it = doctors.begin(); it != doctors.end(); it++) {
           
            (*it).eliminarTotesVisita(p);
            
        }
    }
}

/* Pre: cert */
/* Post: afegeix un doctor al sistema si no hi ha un altre igual en el mateix */
void Hospital::insert_doctor(Doctor &d) {
    cout << "alta_doctor "<< d.getNom() << endl;
    if (not find_doctor(d.getNom())) {
        doctors.push_back(d);

    }
    else {
        cout << "  error" << endl;
    }
}

/* Pre: cert */
/* Post: s'elemina el primer pacient de la llista d'espera, si aquesta esta buida
es produeix un error */
void Hospital::treat_pacient() {
    cout << "tractar_seguent_pacient"<<endl;
    if (llista_espera.empty()) {
        cout << "  error" << endl;
    }
    else {
        llista_espera.pop();
    }
}


/* Pre: p es un pacient no buit i g es un enter no buit que representa la gravetat */
/* Post: s’actualitza el valor de gravetat del pacient en el sistema i es
ressitua el pacient en la llista d’espera en funció del nou nivell de gravetat */
void Hospital::modify_status(Pacient &p, int g) {
    cout<<"modificar_estat_pacient " << p.getNom() << " " << g << endl;
    if (not (pacients.find(p)).first or g<1 or g>3) {
        cout << "  error" << endl;
    }
    else {
       
        Pacient r(p.getNom(), p.getEdat(), p.getMotiu(), g);
        pacients.setValue(p, r);
        
        if (llista_espera.find(p)){
            llista_espera.remove(p);
        }
        llista_espera.push(r);
    }
}

/* Pre: p es un pacient, d es un string (nom del doctor) i date es una data */
/* Post: si el pacient o el doctor es troben al sistema es produeix un error, altrament s’afegeix una nova visita 
al doctor amb el pacient i data indicats. */
void Hospital::new_visit(Pacient &p, string d, Data &date) {
    cout << "programar_visita " << p.getNom() << " " << d << " " << date.getDia() << " " << date.getMes() << " " << date.getAny() << endl;
    if (not pacients.find(p).first or not find_doctor(d)) {
        cout << "  error" << endl;
    }
    else { /*Busquem el doctor en la llista de doctors i li afegim la visita*/
        for (list<Doctor>::iterator it = doctors.begin(); it != doctors.end(); it++) {
            if ((*it).getNom() == d) {
                Visita v(date, p);
                (*it).afegirVisita(v);
            }
        }
    }
}

/* Pre: p es un Pacient, d es un string (nom del doctor) i date es una data */
/* Post: si el pacient o el doctor no es troben al sistema es produeix un error, altrament s’elimina la visita al doctor amb
el pacient i data indicats. */
void Hospital::delete_visit(Pacient &p, string d, Data &date) {
    cout << "cancellar_visita " << p.getNom() << " " << d << " " << date.getDia() << " " << date.getMes() << " " << date.getAny() << endl;
    if (not (pacients.find(p)).first or not find_doctor(d)) {
         cout << "  error" << endl;
        
    }
    else {
        for (list<Doctor>::iterator it = doctors.begin(); it != doctors.end(); it++) {
            if ((*it).getNom() == d) {
                Visita v(date, p);
                (*it).eliminarVisita(v);
            }
        }
    }
}

//-------------
// Consultors
//-------------

/* Pre: cert */
/* Post: escriu la llista d'espera per pantalla */
void Hospital::llista_espera_consultor() const {
    Queue<Pacient> q;
    q = llista_espera;

    while (not q.empty()){
        cout << "  " << q.front() << endl;
        q.pop();
    }
}

/* Pre: cert */
/* Post: escriu el nom de cada doctor i les seves visites ordenades per data, en cas 
de que hi hagi 2 dates coincidents s'escriuen per ordre d'alta */
void Hospital::visit_consultor() const {
    for (list<Doctor>::const_iterator it = doctors.begin(); it != doctors.end(); it++) {
        cout << *it;
    }

}

/*Pre: cert*/
/*Post: retorna el pacient que te el mateix nom que el parametre*/
void Hospital::pacient_consultor(Pacient &pa) const {
    pa = (pacients.find(pa)).second;
}

//-------------------
// Funcions auxiliars
//-------------------

/* Pre: d es un string */
/* Post: retorna si el doctor es troba al sistema */
bool Hospital::find_doctor(string d) const {
    bool find = false;
    for (list<Doctor>::const_iterator it = doctors.begin(); it != doctors.end() and not find; it++) {
        if ((*it).getNom() == d) find = true;
    }

    return find; 
}

