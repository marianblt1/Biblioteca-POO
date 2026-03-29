#include "CarteFizica.h"
#include <iostream>

using namespace std;

CarteFizica::CarteFizica(string titlu, string autor, string ISBN,
                         int anAparitie, string stare, int timpImprumut,
                         int nrExemplare, string localizare)
    : Carte(titlu, autor, ISBN, anAparitie, stare, timpImprumut) {
    this->nrExemplare = nrExemplare;
    this->localizare = localizare;
}

int CarteFizica::getNrExemplare() const { return nrExemplare; }
string CarteFizica::getLocalizare() const { return localizare; }

void CarteFizica::setNrExemplare(int nr) {
    if (nr >= 0) {
        this->nrExemplare = nr;
    }
}

void CarteFizica::afisareDetalii() const {
    Carte::afisareDetalii();  // apelam afisarea din clasa de baza
    cout << "Nr. exemplare: " << nrExemplare << endl;
    cout << "Localizare: " << localizare << endl;
}