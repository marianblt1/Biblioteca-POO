#include "CarteDigitala.h"
#include <iostream>

using namespace std;

CarteDigitala::CarteDigitala(string titlu, string autor, string ISBN,
                             int anAparitie, string stare, int timpImprumut,
                             string format, float marimeFisier)
    : Carte(titlu, autor, ISBN, anAparitie, stare, timpImprumut) {
    this->format = format;
    this->marimeFisier = marimeFisier;
}

string CarteDigitala::getFormat() const { return format; }
float CarteDigitala::getMarimeFisier() const { return marimeFisier; }

void CarteDigitala::afisareDetalii() const {
    Carte::afisareDetalii();
    cout << "Format: " << format << endl;
    cout << "Marime fisier: " << marimeFisier << " MB" << endl;
}