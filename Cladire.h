#ifndef CLADIRE_H
#define CLADIRE_H

#include <string>
#include <vector>
#include <iostream>
#include "Camera.h"

class Cladire {
private:
    std::string adresa;
    int nrEtaje;
    std::vector<Camera*> camere;

public:
    Cladire(std::string adresa, int nrEtaje);

    // Getteri
    std::string getAdresa() const;
    int getNrEtaje() const;
    int getNrCamere() const;

    // Metode
    void adaugaCamera(Camera* camera);
    void eliminaCamera(std::string numeCamera);
    Camera* getCamera(std::string numeCamera) const;
    void afisareCamere() const;
    void afisareDetalii() const;

    // Cauta carte in toata cladirea
    std::string localizarecarte(std::string isbn) const;

    ~Cladire();
};

#endif