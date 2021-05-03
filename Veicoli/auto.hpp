#include <sstream>
#include "veicolo.hpp"

using namespace std;

class Auto : public Veicolo{

    public:

        Auto(int velocita_max, double prezzo, string marca, string carburante, string motorizzazione) :
            Veicolo(4, velocita_max, prezzo, marca, carburante, motorizzazione){}

        string toString() const{
            stringstream stream;
            stream << "Sono un'auto di marca " << marca << ", " << motorizzazione
            << " " << carburante << ". La mia velocita' e' di " << velocita_max << " km/h";
            return stream.str();
        }
};