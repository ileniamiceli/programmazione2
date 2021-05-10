#ifndef GARA_HPP
#define GARA_HPP

#include "veicolo.hpp"
#include <cstdlib>

using namespace std;

class Gara{
    
    int durata;
    int n_partecipanti;
    int n_iscritti;
    void controlla(int t);
    Veicolo ** veicoli;

    public:

        Gara(int durata, int partecipanti) : durata(durata), n_partecipanti(partecipanti){
            veicoli = new Veicolo*[n_partecipanti];
            n_iscritti = 0;
        }

        ~Gara(){
            delete [] veicoli;
        }

        void partenza();
        void stampaClassifica();
        void aggiungiPartecipante(Veicolo& v);
        void bubblesort();
        
};

#endif

void Gara::aggiungiPartecipante(Veicolo& v){
    veicoli[n_iscritti++] = &v;
}

void Gara::bubblesort(){  
    bool swap = true;
    
    while(swap){
        swap = false;
        
        for(int i = 0; i < n_iscritti-1; i++){
            if(veicoli[i]->getVelocita() < veicoli[i+1]->getVelocita()){
                Veicolo * temp = veicoli[i];
                veicoli[i] = veicoli[i+1];
                veicoli[i+1] = temp;
                swap = true;
            }
        }
    }
    
    /* PROF
    for(int i=0; i < numeroIscritti; i++) {
		for(int j=i+1; j < numeroIscritti; j++) {
			if(*veicoli[i] < *veicoli[j]) {
				Veicolo *tmp = veicoli[i];
				veicoli[i] = veicoli[j];
				veicoli[j] = tmp;
			}
		}
	}
    */
}

void Gara::controlla(int t){
    int tempmax = veicoli[0]->getVelocita();
    
    int indicemax = 0;
    //int tempmax = -1;

    for(int i = 1; i < n_iscritti; i++){
        //estrarre la velocità di ogni veicolo
        //e verificare chi è più avanti
        //ricerca se vogliamo trovare solo il massimo
        //ordinamento se vogliamo la classifica completa
        /*
        if(veicoli[i]->getVelocita() > tempmax){
            tempmax = veicoli[i]->getVelocita();
            indicemax = i;
        }
        */
        Gara::bubblesort();
    }
    cout <<"Il veicolo piu' veloce e' " << *veicoli[indicemax] << " e ha velocita' " << tempmax << endl;
}

void Gara::partenza(){ //gara
    
    srand(42);  
    for(int i = 0; i < durata; i++){
        
        for(int j = 0; j < n_iscritti; j++){ //per ogni veicolo
            int scelta = rand()%2; //0 e 1
            if(scelta)
                veicoli[j] -> accelera();
            else
                veicoli[j]->decelera();
        }
        this->controlla(i);

    }
    this->stampaClassifica();
 
}

void Gara::stampaClassifica(){ //bubblesort

    cout << "Stampa Classifica..." << endl;
    for(int i = 0; i < n_iscritti; i++){
        cout << i+1 << " posizione: " << *veicoli[i] << " con velocita' " << veicoli[i]->getVelocita() << endl;
    }
}
