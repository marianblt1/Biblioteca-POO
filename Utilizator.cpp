#include "Utilizator.h"
#include <iostream>
#include <algorithm>

using namespace std;

Utilizator::Utilizator(string nume, string prenume, int id,
                       string email, string telefon) {
    this->nume = nume;
    this->prenume = prenume;
    this->id = id;
    this->email = email;
    this->telefon = telefon;
    this->status = "Activ";
    this->cartiActive = 0;
}

string Utilizator::getNume() const { return nume; }
string Utilizator::getPrenume() const { return prenume; }
int Utilizator::getId() const { return id; }
string Utilizator::getEmail() const { return email; }
string Utilizator::getTelefon() const { return telefon; }
string Utilizator::getStatus() const { return status; }
int Utilizator::getCartiActive() const { return cartiActive; }
vector<int> Utilizator::getListaImprumuturi() const { return listaImprumuturi; }

void Utilizator::setStatus(string status) {
    if (status == "Activ" || status == "Penalizat" || status == "Suspendat") {
        this->status = status;
    }
}

void Utilizator::adaugaImprumut(int idCarte) {
    listaImprumuturi.push_back(idCarte);
    cartiActive++;
}

void Utilizator::eliminaImprumut(int idCarte) {
    listaImprumuturi.erase(
        remove(listaImprumuturi.begin(), listaImprumuturi.end(), idCarte),
        listaImprumuturi.end()
    );
    if (cartiActive > 0) cartiActive--;
}

void Utilizator::afisareDetalii() const {
    cout << "Nume: " << nume << " " << prenume << endl;
    cout << "ID: " << id << endl;
    cout << "Email: " << email << endl;
    cout << "Telefon: " << telefon << endl;
    cout << "Status: " << status << endl;
    cout << "Carti active: " << cartiActive << endl;
}