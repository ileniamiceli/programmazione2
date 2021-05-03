/*
    Si implementi un programma che rappresenti una gerarchia di veicoli.
    Ogni veicolo ha un numero di ruote, un tipo di carburante, una motorizzazione,
    una velocità massima, una marca ed un prezzo.
    Tra i veicoli distinguiamo motocicli, automobili, camioni, mezzi speciali (ruspe, ecc.).

    Si simuli una gara tra 10 veicoli di tipo diverso, riportando
    posizioni iniziali, sorpassi e classifica finale.
*/


//verificare che l'header dichiarato su ifndef non sia definito
#ifndef VEICOLO_HPP
#define VEICOLO_HPP //lo definiamo


#include <iostream>

using namespace std;

class Veicolo{ //astratta, dobbiamo dichiarare almeno una funzione pure virtual
    protected:
        int n_ruote;
        int velocita_max;
        int velocita;
        double prezzo;
        string carburante;
        string motorizzazione;     
        string marca;

    public:

        Veicolo(int n_ruote, int velocita_max, double prezzo, string marca, string carburante, string motorizzazione) :
            n_ruote(n_ruote), velocita_max(velocita_max), velocita(0), prezzo(prezzo), marca(marca), carburante(carburante), motorizzazione(motorizzazione){}

        int getNumeroRuote(){
            return n_ruote;
        }

        int getVelocitaMax(){
            return velocita_max;
        }

        int getVelocita(){
            return velocita;
        }

        double getPrezzo(){
            return prezzo;
        }

        string getMarca(){
            return marca;
        }

        string getCarburante(){
            return carburante;
        }

        string getMotorizzazione(){
            return motorizzazione;
        }

        void setNumeroRuote(int n){
            n_ruote = n;
        }

        void setVelocitaMax(int n){
            velocita_max = n;
        }

        void setPrezzo(double d){
            prezzo = d;
        }

        void setMarca(string s){
            marca = s;
        }

        void setCarburante(string s){
            carburante = s;
        }

        void setMotorizzazione(string s){
            motorizzazione = s;
        }

        void accelera(){
            if(velocita < velocita_max)
                velocita++;
        }

        void decelera(){
            if(velocita > 0)
                velocita--;
        }

        virtual string toString() const = 0;
        
        //overload redirezione dell'output
        friend ostream& operator<<(ostream& out, const Veicolo& v){
            out << v.toString();
            return out;
        }

        void operator=(const Veicolo& v){
            this->n_ruote = v.n_ruote;
            this->velocita_max = v.velocita_max;
            this->motorizzazione = v.motorizzazione;
            this->carburante = v.carburante;
            this->marca = v.marca;
            this->prezzo = v.prezzo;
        }
};

#endif //basta