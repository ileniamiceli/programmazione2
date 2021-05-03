#include <iostream>
#include <sstream>
#include "veicolo.hpp"

using namespace std;

class Moto : public Veicolo{
    public:

        /*
        int n_ruote;
        int velocita_max;
        int velocita;
        double prezzo;
        string carburante;
        string motorizzazione;     
        string marca;
        */

        Moto(int velocita_max, double prezzo, string marca, string motorizzazione) :
            Veicolo(2, velocita_max, prezzo, marca, "benzina", motorizzazione){}
        
        string toString() const{
            stringstream stream;
            stream << "Sono una moto di marca " << marca << ", " << motorizzazione
            << " " << carburante << ". La mia velocita' e' di " << velocita_max << " km/h";
            return stream.str();
        }

        /*
        friend ostream& operator<<(ostream& out, const Moto& m){
            out << m.toString();
            return out;
        }
        */
};