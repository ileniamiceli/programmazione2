#include <iostream>
#include "moto.hpp"
#include "auto.hpp"
#include "gara.hpp"

int main(){
    Moto m(120, 10000, "Ducati", "1000cc");
    Auto a(160, 8000, "Fiat Punto", "Diesel", "1300 MTJ");
    Moto m2(130, 9000, "Vespa", "1000cc");
    
    cout << m << endl;
    cout << a << endl;

    Gara gara(10, 10);
    gara.aggiungiPartecipante(m);
    gara.aggiungiPartecipante(a);
    gara.aggiungiPartecipante(m2);
    gara.partenza();

    //gara.stampaClassifica();
}