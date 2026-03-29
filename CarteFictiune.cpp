#include "CarteFictiune.h"
#include <iostream>

using namespace std;

CarteFictiune::CarteFictiune(string titlu, string autor, string ISBN,
                             int anAparitie, string stare, int timpImprumut,
                             int nrExemplare, string localizare,
                             string gen, int varstaminima)
    : CarteFizica(titlu, autor, ISBN, anAparitie, stare, timpImprumut, nrExemplare, localizare) {
    this->gen = gen;
    this->varstaminima = varstaminima;
}

string CarteFictiune::getGen() const { return gen; }
int CarteFictiune::getVarstaMinima() const { return varstaminima; }

void CarteFictiune::afisareDetalii() const {
    CarteFizica::afisareDetalii();
    cout << "Gen: " << gen << endl;
    cout << "Varsta minima recomandata: " << varstaminima << " ani" << endl;
}