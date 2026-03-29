// UtilizatorElev.cpp
#include "UtilizatorElev.h"
#include <iostream>

using namespace std;

UtilizatorElev::UtilizatorElev(string nume, string prenume, int id,
                               string email, string telefon,
                               string scoala, string clasa)
    : Utilizator(nume, prenume, id, email, telefon) {
    this->scoala = scoala;
    this->clasa = clasa;
}

string UtilizatorElev::getScoala() const { return scoala; }
string UtilizatorElev::getClasa() const { return clasa; }

void UtilizatorElev::afisareDetalii() const {
    Utilizator::afisareDetalii();
    cout << "Tip: Elev" << endl;
    cout << "Scoala: " << scoala << endl;
    cout << "Clasa: " << clasa << endl;
}