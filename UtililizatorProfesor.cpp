// UtilizatorProfesor.cpp
#include "UtilizatorProfesor.h"
#include <iostream>

using namespace std;

UtilizatorProfesor::UtilizatorProfesor(string nume, string prenume, int id,
                                       string email, string telefon,
                                       string materie, string institutie)
    : Utilizator(nume, prenume, id, email, telefon) {
    this->materie = materie;
    this->institutie = institutie;
}

string UtilizatorProfesor::getMaterie() const { return materie; }
string UtilizatorProfesor::getInstitutie() const { return institutie; }

void UtilizatorProfesor::afisareDetalii() const {
    Utilizator::afisareDetalii();
    cout << "Tip: Profesor" << endl;
    cout << "Materie: " << materie << endl;
    cout << "Institutie: " << institutie << endl;
}