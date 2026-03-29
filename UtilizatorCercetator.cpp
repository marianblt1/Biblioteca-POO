#include "UtilizatorCercetator.h"
#include <iostream>

using namespace std;

UtilizatorCercetator::UtilizatorCercetator(string nume, string prenume, int id,
                                           string email, string telefon,
                                           string domeniuCercetare, string institutie)
    : Utilizator(nume, prenume, id, email, telefon) {
    this->domeniuCercetare = domeniuCercetare;
    this->institutie = institutie;
}

string UtilizatorCercetator::getDomeniuCercetare() const { return domeniuCercetare; }
string UtilizatorCercetator::getInstitutie() const { return institutie; }

void UtilizatorCercetator::afisareDetalii() const {
    Utilizator::afisareDetalii();
    cout << "Tip: Cercetator" << endl;
    cout << "Domeniu cercetare: " << domeniuCercetare << endl;
    cout << "Institutie: " << institutie << endl;
}