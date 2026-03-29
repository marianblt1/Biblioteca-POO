#include "CarteTehnica.h"
#include <iostream>

using namespace std;

CarteTehnica::CarteTehnica(string titlu, string autor, string ISBN,
                           int anAparitie, string stare, int timpImprumut,
                           int nrExemplare, string localizare,
                           string domeniu, string nivelDificultate)
    : CarteFizica(titlu, autor, ISBN, anAparitie, stare, timpImprumut, nrExemplare, localizare) {
    this->domeniu = domeniu;
    this->nivelDificultate = nivelDificultate;
}

string CarteTehnica::getDomeniu() const { return domeniu; }
string CarteTehnica::getNivelDificultate() const { return nivelDificultate; }

void CarteTehnica::afisareDetalii() const {
    CarteFizica::afisareDetalii();
    cout << "Domeniu: " << domeniu << endl;
    cout << "Nivel dificultate: " << nivelDificultate << endl;
}