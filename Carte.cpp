#include "Carte.h"
#include <iostream>

using namespace std;

Carte::Carte(string titlu, string autor, string ISBN, 
             int anAparitie, string stare, int timpImprumut) {
    this->titlu = titlu;
    this->autor = autor;
    this->ISBN = ISBN;
    this->anAparitie = anAparitie;
    this->stare = stare;
    this->timpImprumut = timpImprumut;
    this->status = "Disponibila";  // orice carte noua e disponibila
}

string Carte::getTitlu() const { return titlu; }
string Carte::getAutor() const { return autor; }
string Carte::getISBN() const { return ISBN; }
int Carte::getAnAparitie() const { return anAparitie; }
string Carte::getStatus() const { return status; }
string Carte::getStare() const { return stare; }
int Carte::getTimpImprumut() const { return timpImprumut; }

void Carte::setStatus(string status) {
    if (status == "Disponibila" || status == "Imprumutata" || status == "Rezervata") {
        this->status = status;
    }
}

void Carte::setStare(string stare) {
    if (stare == "Noua" || stare == "Buna" || stare == "Uzata" || stare == "Deteriorata") {
        this->stare = stare;
    }
}

void Carte::afisareDetalii() const {
    cout << "Titlu: " << titlu << endl;
    cout << "Autor: " << autor << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "An aparitie: " << anAparitie << endl;
    cout << "Status: " << status << endl;
    cout << "Stare: " << stare << endl;
    cout << "Timp imprumut: " << timpImprumut << " zile" << endl;
}