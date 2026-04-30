#include "Biblioteca.h"
#include <iostream>
#include <fstream>
#include "Exceptii.h"

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
    for (size_t i = 0; i < inventarCarti.size(); i++) {
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
    for (size_t i = 0; i < inventarCarti.size(); i++) {
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
    for (size_t i = 0; i < listaUtilizatori.size(); i++) {
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
    for (size_t i = 0; i < listaUtilizatori.size(); i++) {
        cout << "\n--- Utilizator " << i+1 << " ---" << endl;
        listaUtilizatori[i]->afisareDetalii();
    }
}

void Biblioteca::imprumutaCarte(int idUtilizator, int idCarte) {
    Utilizator* utilizator = nullptr;
    Carte* carte = nullptr;

    for (size_t i = 0; i < listaUtilizatori.size(); i++) {
        if (listaUtilizatori[i]->getId() == idUtilizator) {
            utilizator = listaUtilizatori[i];
            break;
        }
    }

    for (size_t i = 0; i < inventarCarti.size(); i++) {
        if (inventarCarti[i]->getISBN() == to_string(idCarte)) {
            carte = inventarCarti[i];
            break;
        }
    }

    if (utilizator == nullptr)
        throw UtilizatorNegasit(idUtilizator);

    if (carte == nullptr)
        throw CarteNegasita(to_string(idCarte));

    if (carte->getStatus() != "Disponibila")
        throw CarteIndisponibila(carte->getTitlu());

    if (utilizator->getStatus() == "Suspendat")
        throw UtilizatorSuspendat(utilizator->getNume());

    carte->setStatus("Imprumutata");
    utilizator->adaugaImprumut(idCarte);
    cout << "Cartea '" << carte->getTitlu() << "' a fost imprumutata lui "
         << utilizator->getNume() << "." << endl;
    logEveniment("Imprumut: " + utilizator->getNume() + " -> " + carte->getTitlu());
}

void Biblioteca::returneazaCarte(int idUtilizator, int idCarte) {
    Utilizator* utilizator = nullptr;
    Carte* carte = nullptr;

    for (size_t i = 0; i < listaUtilizatori.size(); i++) {
        if (listaUtilizatori[i]->getId() == idUtilizator) {
            utilizator = listaUtilizatori[i];
            break;
        }
    }

    for (size_t i = 0; i < inventarCarti.size(); i++) {
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

void Biblioteca::cautaCarte(int tip, string termen) const {
    cout << "\n---> rezultate cautare <---" << endl;
    bool gasit = false;

    for (size_t i = 0; i < inventarCarti.size(); i++) {
        bool match = false;

        if (tip == 1 && inventarCarti[i]->getTitlu().find(termen) != string::npos)
            match = true;
        else if (tip == 2 && inventarCarti[i]->getAutor().find(termen) != string::npos)
            match = true;
        else if (tip == 3 && inventarCarti[i]->getISBN().find(termen) != string::npos)
            match = true;

        if (match) {
            cout << "\n--- Rezultat " << i+1 << " ---" << endl;
            inventarCarti[i]->afisareDetalii();
            gasit = true;
        }
    }

    if (!gasit)
        cout << "Niciun rezultat gasit." << endl;
}

Biblioteca::~Biblioteca() {
    for (size_t i = 0; i < inventarCarti.size(); i++) {
        delete inventarCarti[i];
    }
    for (size_t i = 0; i < listaUtilizatori.size(); i++) {
        delete listaUtilizatori[i];
    }
}