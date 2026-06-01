#include "Camera.h"
#include <iostream>

using namespace std;

Camera::Camera(string nume, TipCamera tip, int capacitate, string program) {
    this->nume = nume;
    this->tip = tip;
    this->capacitate = capacitate;
    this->program = program;
}

string Camera::getNume() const { return nume; }
TipCamera Camera::getTip() const { return tip; }
int Camera::getCapacitate() const { return capacitate; }
string Camera::getProgram() const { return program; }
int Camera::getNrCarti() const { return carti.size(); }

string Camera::tipToString() const {
    switch(tip) {
        case SALA_LECTURA: return "Sala de Lectura";
        case DEPOZIT: return "Depozit";
        case RECEPTIE: return "Receptie";
        case SALA_CALCULATOARE: return "Sala Calculatoare";
        case SALA_COPII: return "Sala Copii";
        default: return "Necunoscut";
    }
}

void Camera::adaugaCarte(Carte* carte) {
    carti.push_back(carte);
    cout << "Cartea '" << carte->getTitlu() << "' adaugata in camera '" << nume << "'." << endl;
}

void Camera::eliminaCarte(string isbn) {
    for (size_t i = 0; i < carti.size(); i++) {
        if (carti[i]->getISBN() == isbn) {
            carti.erase(carti.begin() + i);
            cout << "Cartea a fost eliminata din camera." << endl;
            return;
        }
    }
    cout << "Cartea nu a fost gasita in aceasta camera." << endl;
}

Carte* Camera::cautaCarte(string isbn) const {
    for (size_t i = 0; i < carti.size(); i++) {
        if (carti[i]->getISBN() == isbn) {
            return carti[i];
        }
    }
    return nullptr;
}

void Camera::afisareCarti() const {
    cout << "\n=== Carti in " << nume << " ===" << endl;
    if (carti.empty()) {
        cout << "Nu sunt carti in aceasta camera." << endl;
        return;
    }
    for (size_t i = 0; i < carti.size(); i++) {
        cout << "\n--- Carte " << i+1 << " ---" << endl;
        carti[i]->afisareDetalii();
    }
}

void Camera::afisareDetalii() const {
    cout << "\nCamera: " << nume << endl;
    cout << "Tip: " << tipToString() << endl;
    cout << "Capacitate: " << capacitate << endl;
    cout << "Program: " << program << endl;
    cout << "Nr. carti: " << getNrCarti() << endl;
}