#include "CarteRara.h"
#include <iostream>

using namespace std;

CarteRara::CarteRara(string titlu, string autor, string ISBN,
                     int anAparitie, string stare, int timpImprumut,
                     int nrExemplare, string localizare,
                     int anEstimat, string origine, bool esteManuscris)
    : CarteFizica(titlu, autor, ISBN, anAparitie, stare, timpImprumut, nrExemplare, localizare) {
    this->anEstimat = anEstimat;
    this->origine = origine;
    this->esteManuscris = esteManuscris;
    // O carte rara e mereu "Doar in sala"
    this->setStatus("Doar in sala");
}

int CarteRara::getAnEstimat() const { return anEstimat; }
string CarteRara::getOrigine() const { return origine; }
bool CarteRara::getEsteManuscris() const { return esteManuscris; }

void CarteRara::afisareDetalii() const {
    CarteFizica::afisareDetalii();
    cout << "*** CARTE RARA - NU POATE FI IMPRUMUTATA ***" << endl;
    cout << "An estimat: " << anEstimat << endl;
    cout << "Origine: " << origine << endl;
    cout << "Tip: " << (esteManuscris ? "Manuscris" : "Carte rara tiparita") << endl;
}