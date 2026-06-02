#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <string>
#include <iostream>
#include <fstream>
#include "Carte.h"
#include "Utilizator.h"
#include "Depozit.h"
#include "Exceptii.h"
#include "CarteFizica.h"
#include "Cladire.h"
#include "CarteRara.h"

class Biblioteca {
private:

    std::string nume;
    Depozit<Carte*> inventarCarti;
    Depozit<Utilizator*> listaUtilizatori;
    Cladire* cladire;

public:
    Biblioteca(std::string nume);

    // Gestiune carti
    void adaugaCarte(Carte* carte);
    void eliminaCarte(int idCarte);
    void eliminaCarteISBN(std::string isbn);
    void afisareCarti() const;

    // Gestiune utilizatori
    void adaugaUtilizator(Utilizator* utilizator);
    void eliminaUtilizator(int idUtilizator);
    void afisareUtilizatori() const;
    void cautaCarte(int tip, std::string termen) const;
    void cautaUtilizator(std::string termen) const;
    void salveazaDate() const;
    void incarcaDate();

    // Gestiune imprumuturi
    void imprumutaCarte(std::string identificatorUtilizator, std::string isbn);
    void returneazaCarte(std::string identificatorUtilizator, std::string isbn);

    // Logare evenimente
    void logEveniment(std::string eveniment) const;

    void setCladire(Cladire* cladire);
    Cladire* getCladire() const;
    void localizazeCarteInCladire(std::string isbn) const;

    // Destructor
    ~Biblioteca();
};
#endif