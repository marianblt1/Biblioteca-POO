#include "UtilizatorStudent.h"
#include <iostream>

using namespace std;

UtilizatorStudent::UtilizatorStudent(string nume, string prenume, int id,
                                     string email, string telefon,
                                     string facultate, int anStudiu, string nrMatricol)
    : Utilizator(nume, prenume, id, email, telefon) {
    this->facultate = facultate;
    this->anStudiu = anStudiu;
    this->nrMatricol = nrMatricol;
}

string UtilizatorStudent::getFacultate() const { return facultate; }
int UtilizatorStudent::getAnStudiu() const { return anStudiu; }
string UtilizatorStudent::getNrMatricol() const { return nrMatricol; }

void UtilizatorStudent::afisareDetalii() const {
    Utilizator::afisareDetalii();
    cout << "Tip: Student" << endl;
    cout << "Facultate: " << facultate << endl;
    cout << "An studiu: " << anStudiu << endl;
    cout << "Nr. matricol: " << nrMatricol << endl;
}