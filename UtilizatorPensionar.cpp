#include "UtilizatorPensionar.h"
#include <iostream>

using namespace std;

UtilizatorPensionar::UtilizatorPensionar(string nume, string prenume, int id,
                                         string email, string telefon,
                                         int varstaPensionare)
    : Utilizator(nume, prenume, id, email, telefon) {
    this->varstaPensionare = varstaPensionare;
}

int UtilizatorPensionar::getVarstaPensionare() const { return varstaPensionare; }

void UtilizatorPensionar::afisareDetalii() const {
    Utilizator::afisareDetalii();
    cout << "Tip: Pensionar" << endl;
    cout << "Varsta pensionare: " << varstaPensionare << " ani" << endl;
}