#include "Revista.h"
#include <iostream>

using namespace std;

Revista::Revista(string titlu, string autor, string ISBN,
                 int anAparitie, string stare, int timpImprumut,
                 int numar, string periodicitate)
    : Carte(titlu, autor, ISBN, anAparitie, stare, timpImprumut) {
    this->numar = numar;
    this->periodicitate = periodicitate;
}

int Revista::getNumar() const { return numar; }
string Revista::getPeriodicitate() const { return periodicitate; }

void Revista::afisareDetalii() const {
    Carte::afisareDetalii();
    cout << "Numar editie: " << numar << endl;
    cout << "Periodicitate: " << periodicitate << endl;
}