#ifndef CAMERA_H
#define CAMERA_H

#include <string>
#include <vector>
#include <iostream>
#include "Carte.h"

enum TipCamera {
    SALA_LECTURA,
    DEPOZIT,
    RECEPTIE,
    SALA_CALCULATOARE,
    SALA_COPII
};

class Camera {
private:
    std::string nume;
    TipCamera tip;
    int capacitate;
    std::string program;        // ex: "08:00 - 20:00"
    std::vector<Carte*> carti;  // cartile din camera

public:
    Camera(std::string nume, TipCamera tip, int capacitate, std::string program);

    // Getteri
    std::string getNume() const;
    TipCamera getTip() const;
    int getCapacitate() const;
    std::string getProgram() const;
    int getNrCarti() const;

    // Metode
    void adaugaCarte(Carte* carte);
    void eliminaCarte(std::string isbn);
    Carte* cautaCarte(std::string isbn) const;
    void afisareCarti() const;
    void afisareDetalii() const;

    std::string tipToString() const;

    ~Camera() {}
};

#endif