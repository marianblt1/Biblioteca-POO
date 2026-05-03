#ifndef MENIU_H
#define MENIU_H

#include "Biblioteca.h"
#include "CarteFictiune.h"
#include "CarteTehnica.h"
#include "CarteDigitala.h"
#include "Revista.h"
#include "UtilizatorStudent.h"
#include "UtilizatorElev.h"
#include "UtilizatorAdult.h"
#include "UtilizatorProfesor.h"
#include "UtilizatorPensionar.h"
#include "UtilizatorCercetator.h"

class Meniu {
private:
    Biblioteca& biblioteca;
    std::string tipUtilizator;

    void meniuCarti();
    void meniuUtilizatori();
    void meniuCautare();
    void meniuImprumuturi();

    void adaugaCarte();
    void adaugaUtilizator();

public:
    Meniu(Biblioteca& biblioteca, std::string tipUtilizator);
    void ruleaza();
};

#endif