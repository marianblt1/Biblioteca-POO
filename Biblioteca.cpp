#include "Biblioteca.h"
#include <iostream>
#include <fstream>

using namespace std;

Biblioteca::Biblioteca(string nume) {
    this->nume = nume;
}

void Biblioteca::adaugaCarte(Carte* carte) {
    inventarCarti.push_back(carte);
    cout << "Cartea '" << carte->getTitlu() << "' a fost adaugata." << endl;
    logEveniment("Adaugata cartea: " + carte->getTitlu());
}

void Biblioteca::eliminaCarte(int idCarte) {
    for (int i = 0; i < inventarCarti.size(); i++) {
        if (inventarCarti[i]->getISBN() == to_string(idCarte)) {
            logEveniment("Eliminata cartea: " + inventarCarti[i]->getTitlu());
            delete inventarCarti[i];
            inventarCarti.erase(inventarCarti.begin() + i);
            cout << "Cartea a fost eliminata." << endl;
            return;
        }
    }
    cout << "Cartea nu a fost gasita." << endl;
}

void Biblioteca::afisareCarti() const {
    cout << "\n=== Inventar Carti - " << nume << " ===" << endl;
    for (int i = 0; i < inventarCarti.size(); i++) {
        cout << "\n--- Carte " << i+1 << " ---" << endl;
        inventarCarti[i]->afisareDetalii();
    }
}

void Biblioteca::adaugaUtilizator(Utilizator* utilizator) {
    listaUtilizatori.push_back(utilizator);
    cout << "Utilizatorul '" << utilizator->getNume() << " "
         << utilizator->getPrenume() << "' a fost adaugat." << endl;
    logEveniment("Adaugat utilizatorul: " + utilizator->getNume() + " " + utilizator->getPrenume());
}

void Biblioteca::eliminaUtilizator(int idUtilizator) {
    for (int i = 0; i < listaUtilizatori.size(); i++) {
        if (listaUtilizatori[i]->getId() == idUtilizator) {
            logEveniment("Eliminat utilizatorul: " + listaUtilizatori[i]->getNume());
            delete listaUtilizatori[i];
            listaUtilizatori.erase(listaUtilizatori.begin() + i);
            cout << "Utilizatorul a fost eliminat." << endl;
            return;
        }
    }
    cout << "Utilizatorul nu a fost gasit." << endl;
}

void Biblioteca::afisareUtilizatori() const {
    cout << "\n=== Lista Utilizatori - " << nume << " ===" << endl;
    for (int i = 0; i < listaUtilizatori.size(); i++) {
        cout << "\n--- Utilizator " << i+1 << " ---" << endl;
        listaUtilizatori[i]->afisareDetalii();
    }
}

void Biblioteca::imprumutaCarte(int idUtilizator, int idCarte) {
    Utilizator* utilizator = nullptr;
    Carte* carte = nullptr;

    for (int i = 0; i < listaUtilizatori.size(); i++) {
        if (listaUtilizatori[i]->getId() == idUtilizator) {
            utilizator = listaUtilizatori[i];
            break;
        }
    }

    for (int i = 0; i < inventarCarti.size(); i++) {
        if (inventarCarti[i]->getISBN() == to_string(idCarte)) {
            carte = inventarCarti[i];
            break;
        }
    }

    if (utilizator == nullptr) {
        cout << "Utilizatorul nu a fost gasit." << endl;
        return;
    }
    if (carte == nullptr) {
        cout << "Cartea nu a fost gasita." << endl;
        return;
    }
    if (carte->getStatus() != "Disponibila") {
        cout << "Cartea nu este disponibila." << endl;
        return;
    }

    carte->setStatus("Imprumutata");
    utilizator->adaugaImprumut(idCarte);
    cout << "Cartea '" << carte->getTitlu() << "' a fost imprumutata lui "
         << utilizator->getNume() << "." << endl;
    logEveniment("Imprumut: " + utilizator->getNume() + " -> " + carte->getTitlu());
}

void Biblioteca::returneazaCarte(int idUtilizator, int idCarte) {
    Utilizator* utilizator = nullptr;
    Carte* carte = nullptr;

    for (int i = 0; i < listaUtilizatori.size(); i++) {
        if (listaUtilizatori[i]->getId() == idUtilizator) {
            utilizator = listaUtilizatori[i];
            break;
        }
    }

    for (int i = 0; i < inventarCarti.size(); i++) {
        if (inventarCarti[i]->getISBN() == to_string(idCarte)) {
            carte = inventarCarti[i];
            break;
        }
    }

    if (utilizator == nullptr || carte == nullptr) {
        cout << "Date invalide." << endl;
        return;
    }

    carte->setStatus("Disponibila");
    utilizator->eliminaImprumut(idCarte);
    cout << "Cartea '" << carte->getTitlu() << "' a fost returnata." << endl;
    logEveniment("Returnare: " + utilizator->getNume() + " -> " + carte->getTitlu());
}

void Biblioteca::logEveniment(string eveniment) const {
    ofstream logFile("log.txt", ios::app);
    if (logFile.is_open()) {
        logFile << eveniment << endl;
        logFile.close();
    }
}

Biblioteca::~Biblioteca() {
    for (int i = 0; i < inventarCarti.size(); i++) {
        delete inventarCarti[i];
    }
    for (int i = 0; i < listaUtilizatori.size(); i++) {
        delete listaUtilizatori[i];
    }
}