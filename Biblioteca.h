#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <string>
#include <iostream>
#include <fstream>
#include "Carte.h"
#include "Utilizator.h"
#include "Depozit.h"
#include "Exceptii.h" 
class Biblioteca {
private:
    std::string nume;
    Depozit<Carte*> inventarCarti;
    Depozit<Utilizator*> listaUtilizatori;

public:
    Biblioteca(std::string nume);

    // Gestiune carti
    void adaugaCarte(Carte* carte);
    void eliminaCarte(int idCarte);
    void afisareCarti() const;

    // Gestiune utilizatori
    void adaugaUtilizator(Utilizator* utilizator);
    void eliminaUtilizator(int idUtilizator);
    void afisareUtilizatori() const;
    void cautaCarte(int tip, std::string termen) const;

    // Gestiune imprumuturi
    void imprumutaCarte(int idUtilizator, int idCarte);
    void returneazaCarte(int idUtilizator, int idCarte);

    // Logare evenimente
    void logEveniment(std::string eveniment) const;

    // Destructor
    ~Biblioteca();
};
#endif