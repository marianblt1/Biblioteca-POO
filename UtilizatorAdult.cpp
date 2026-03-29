// UtilizatorAdult.cpp
#include "UtilizatorAdult.h"
#include <iostream>

using namespace std;

UtilizatorAdult::UtilizatorAdult(string nume, string prenume, int id,
                                 string email, string telefon,
                                 string ocupatie)
    : Utilizator(nume, prenume, id, email, telefon) {
    this->ocupatie = ocupatie;
}

string UtilizatorAdult::getOcupatie() const { return ocupatie; }

void UtilizatorAdult::afisareDetalii() const {
    Utilizator::afisareDetalii();
    cout << "Tip: Adult" << endl;
    cout << "Ocupatie: " << ocupatie << endl;
}