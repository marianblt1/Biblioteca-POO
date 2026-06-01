#include "Cladire.h"
#include <iostream>

using namespace std;

Cladire::Cladire(string adresa, int nrEtaje) {
    this->adresa = adresa;
    this->nrEtaje = nrEtaje;
}

string Cladire::getAdresa() const { return adresa; }
int Cladire::getNrEtaje() const { return nrEtaje; }
int Cladire::getNrCamere() const { return camere.size(); }

void Cladire::adaugaCamera(Camera* camera) {
    camere.push_back(camera);
    cout << "Camera '" << camera->getNume() << "' adaugata in cladire." << endl;
}

void Cladire::eliminaCamera(string numeCamera) {
    for (size_t i = 0; i < camere.size(); i++) {
        if (camere[i]->getNume() == numeCamera) {
            delete camere[i];
            camere.erase(camere.begin() + i);
            cout << "Camera '" << numeCamera << "' eliminata." << endl;
            return;
        }
    }
    cout << "Camera nu a fost gasita." << endl;
}

Camera* Cladire::getCamera(string numeCamera) const {
    for (size_t i = 0; i < camere.size(); i++) {
        if (camere[i]->getNume() == numeCamera) {
            return camere[i];
        }
    }
    return nullptr;
}

void Cladire::afisareCamere() const {
    cout << "\n=== Camere in cladire ===" << endl;
    if (camere.empty()) {
        cout << "Nu sunt camere in aceasta cladire." << endl;
        return;
    }
    for (size_t i = 0; i < camere.size(); i++) {
        camere[i]->afisareDetalii();
    }
}

void Cladire::afisareDetalii() const {
    cout << "\n=== Detalii Cladire ===" << endl;
    cout << "Adresa: " << adresa << endl;
    cout << "Nr. etaje: " << nrEtaje << endl;
    cout << "Nr. camere: " << getNrCamere() << endl;
    afisareCamere();
}

string Cladire::localizarecarte(string isbn) const {
    for (size_t i = 0; i < camere.size(); i++) {
        Carte* c = camere[i]->cautaCarte(isbn);
        if (c != nullptr) {
    return "Camera: " + camere[i]->getNume() + " (" + camere[i]->tipToString() + ")";
}
    }
    return "Cartea nu a fost gasita in nicio camera.";
}

Cladire::~Cladire() {
    for (size_t i = 0; i < camere.size(); i++) {
        delete camere[i];
    }
}