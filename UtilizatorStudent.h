#ifndef UTILIZATORSTUDENT_H
#define UTILIZATORSTUDENT_H

#include "Utilizator.h"

class UtilizatorStudent : public Utilizator {
private:
    std::string facultate;
    int anStudiu;
    std::string nrMatricol;

public:
    UtilizatorStudent(std::string nume, std::string prenume, int id,
                      std::string email, std::string telefon,
                      std::string facultate, int anStudiu, std::string nrMatricol);

    std::string getFacultate() const;
    int getAnStudiu() const;
    std::string getNrMatricol() const;

    void afisareDetalii() const override;

    virtual ~UtilizatorStudent() {}
};

#endif